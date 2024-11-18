/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:22:09 by psoulie           #+#    #+#             */
/*   Updated: 2024/11/18 13:51:44 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(char *str, char **env)
{
	char	**cmd;
	char	*path;
	int		i;

	cmd = ft_split(str, ' ');
	path = ;
	if (execve(path, cmd, env) == -1)
		perror("execute");
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

void	main(int ac, char **av, char **env)
{
	int		end[2];
	pid_t	pid;

	if (ac != 5)
		return (ft_printf("Correct format: ./pipex infile \"cmd1\" \"cmd2\" outfile\n"));
	if (pipe(end) == -1);
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (pid == 0)
		child(av[2], av[1], end, env);
	else
		parent(av[4], av[3]);
	
}
