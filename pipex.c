/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:22:09 by psoulie           #+#    #+#             */
/*   Updated: 2024/11/19 11:56:56 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*findpath(char *cmd, char **env)
{
	char	**paths;
	char	*attempt;
	int		i;

	i  = 0;
	while (!ft_strnstr(env[i++], "PATH", 4));
	paths = ft_split(env[i], ':');
	i = 0;
	while (paths[i])
	{
		attempt = ft_strjoin(ft_strjoin(paths[i], "/"), cmd);
		if (access(attempt, F_OK))
			return (attempt);
		free(attempt);
		i++;
	}
	while (i >= 0)
		free(paths[i--]);
	return (NULL);
}

void	execute(char *str, char **env)
{
	char	**cmd;
	char	*path;
	int		i;

	cmd = ft_split(str, ' ');
	path = findpath(cmd[0], env);
	printf("%s\n", path);
	i = 0;
	if (!path)
	{
		while (cmd[i])
			free(cmd[i++]);
		perror("command not found");
		exit(-1);
	}
	if (execve(path, cmd, env) == -1)
	{
		perror("execute");
		exit(-1);
	}
}

void	child(char *cmd1, char *infile, int *end, char **env)
{
	int	fdin;

	close(end[0]);
	fdin = open(infile, O_RDONLY);
	dup2(fdin, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	execute(cmd1, env);
	close(fdin);
}

void	parent(char *cmd2, char *outfile, int *end, char **env)
{
	int	fdout;

	close(end[1]);
	fdout = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(end[0], STDIN_FILENO);
	dup2(fdout, STDOUT_FILENO);
	execute(cmd2, env);
	close(fdout);
}

int	main(int ac, char **av, char **env)
{
	int		end[2];
	pid_t	pid;

	if (ac != 5)
		return (ft_printf("Correct format: ./pipex infile \"cmd1\" \"cmd2\" outfile\n"));
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
