/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:22:09 by psoulie           #+#    #+#             */
/*   Updated: 2024/11/25 15:08:47 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*findpath(char *cmd, char **env)
{
	char	**paths;
	char	*attempt;
	int		i;

	i = -1;
	while (ft_strnstr(env[++i], "PATH", 4)
		== 0);
	paths = ft_split(env[i] + 5, ':');
	if (!paths)
		exit(-1);
	i = 0;
	while (paths[i])
	{
		attempt = ft_strjoin(ft_strjoin(paths[i], "/"), cmd);
		if (access(attempt, F_OK) == 0)
			return (attempt);
		free(attempt);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (NULL);
}

void	execute(char *str, char **env)
{
	char	**cmd;
	char	*path;
	int		i;

	cmd = ft_split(str, ' ');
	if (!cmd)
		exit(-1);
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
		return (ft_printf("Format: ./pipex infile \"cmd1\" \"cmd2\" [..] \"cmdn\" outfile\n"));
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		i = 3;
		fdout = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		here_doc(av[2], ac);
	}
	else
	{
		i = 2;
		fdin = open(av[1], O_RDONLY);
		fdout = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(fdin, STDIN_FILENO);
	}
	while (i < ac - 2)
		child(av[i++], env);
	dup2(fdout, STDOUT_FILENO);
	execute(av[ac - 2], env);
	return (0);
}
