/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:22:09 by psoulie           #+#    #+#             */
/*   Updated: 2024/11/20 11:45:47 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	child(char *cmd1, char *infile, int *end, char **env)
{
	int	fdin;
	int	stdout;

	stdout = dup(STDOUT_FILENO);
	close(end[0]);
	fdin = open(infile, O_RDONLY);
	if (fdin == -1)
		exit(EXIT_FAILURE);
	dup2(fdin, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(fdin);
	execute(cmd1, env);
	dup2(stdout, STDOUT_FILENO);
	ft_printf("command not found: %s\n", cmd1);
	exit(EXIT_FAILURE);
}

void	parent(char *cmd2, char *outfile, int *end, char **env)
{
	int	fdout;
	int	stdout;

	stdout = dup(STDOUT_FILENO);
	close(end[1]);
	fdout = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fdout == -1)
		exit(EXIT_FAILURE);
	dup2(end[0], STDIN_FILENO);
	dup2(fdout, STDOUT_FILENO);
	close(fdout);
	execute(cmd2, env);
	dup2(stdout, STDOUT_FILENO);
	ft_printf("command not found: %s\n", cmd2);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av, char **env)
{
	int		end[2];
	pid_t	pid;

	if (ac != 5)
		return (ft_printf("Format: ./pipex infile \"cmd1\" \"cmd2\" outfile\n"));
	if (pipe(end) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (pid == 0)
		child(av[2], av[1], end, env);
	else
	{
		wait(NULL);
		parent(av[3], av[4], end, env);
	}
	return (0);
}
