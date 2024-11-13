/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:22:09 by psoulie           #+#    #+#             */
/*   Updated: 2024/11/13 14:37:55 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(char *fd1, char *cmd1)
{

}

void	main(int ac, char **av)
{
	int		end[2];
	int		fd1;
	int		fd2;
	pid_t	pid;

	if (ac != 5)
		return (ft_printf("Correct format: ./pipex infile cmd1 cmd2 outfile\n"));
	fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[4], insh);
	pipe(end);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (pid > 0)
		child(av[1], av[2]);
	else
		parent(av[4], av[3]);
	
}