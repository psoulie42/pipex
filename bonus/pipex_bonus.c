/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:22:09 by psoulie           #+#    #+#             */
/*   Updated: 2024/12/03 11:14:01 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	cnf(char *cmd)
{
	dup2(STDERR_FILENO, STDOUT_FILENO);
	ft_printf("command not found: %s\n", cmd);
	exit(EXIT_FAILURE);
}

char	*findpath(char *cmd, char **env)
{
	char	**paths;
	char	*attempt;
	char	*attemptdir;
	int		i;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(env[i] + 5, ':');
	if (!paths)
		exit(-1);
	i = -1;
	while (paths[++i])
	{
		attemptdir = ft_strjoin(paths[i], "/");
		attempt = ft_strjoin(attemptdir, cmd);
		free(attemptdir);
		if (access(attempt, F_OK) == 0)
			return (attempt);
		free(attempt);
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	return (free(paths), NULL);
}

void	execute(char *str, char **env)
{
	char	**cmd;
	char	*path;
	int		i;

	cmd = ft_split(str, ' ');
	if (!cmd || !*cmd)
	{
		dup2(STDERR_FILENO, STDOUT_FILENO);
		ft_printf("missing command\n");
		exit(-1);
	}
	path = findpath(cmd[0], env);
	i = -1;
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		return ;
	}
	if (execve(path, cmd, env) == -1)
	{
		perror("execute");
		exit(EXIT_FAILURE);
	}
}

void	child(char *av, char **env)
{
	int		end[2];
	pid_t	pid;

	if (pipe(end) == -1)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid == 0)
	{
		close(end[0]);
		dup2(end[1], STDOUT_FILENO);
		execute(av, env);
		cnf(av);
	}
	else
	{
		wait(NULL);
		close(end[1]);
		dup2(end[0], STDIN_FILENO);
	}
}

int	main(int ac, char **av, char **env)
{
	int		i;
	int		fdin;
	int		fdout;

	if (ac < 5)
		return (ft_printf("Format: ./pipex infile \"cmd1\" \"cmdn\" out\n"));
	if (ft_strcmp(av[1], "here_doc") == 0)
	{
		i = 3;
		here_doc(av[2], ac);
		fdout = openfile(av[ac - 1], 2);
	}
	else
	{
		i = 2;
		fdin = openfile(av[1], 0);
		fdout = openfile(av[ac - 1], 1);
		dup2(fdin, STDIN_FILENO);
	}
	while (i < ac - 2)
		child(av[i++], env);
	dup2(fdout, STDOUT_FILENO);
	execute(av[ac - 2], env);
	cnf(av[ac - 2]);
	return (0);
}
