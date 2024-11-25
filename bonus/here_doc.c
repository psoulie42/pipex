/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:43:13 by psoulie           #+#    #+#             */
/*   Updated: 2024/11/25 15:06:29 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	exec_heredoc(char *limiter, int *end)
{
	char	*line;

	close(end[0]);
	while (1)
	{
		line = get_next_line(0);
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		write(end[1], line, ft_strlen(line));
		free(line);
	}
}

void	here_doc(char *limiter, int ac)
{
	int		end[2];
	pid_t	pid;

	if (ac < 6)
	{
		ft_printf("Format: ./pipex here_doc LIMITER \"cmd\" \"cmd1\" outfile\n");
		exit(EXIT_FAILURE);
	}
	if (pipe(end) == -1)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid == 0)
		exec_heredoc(limiter, end);
	else
	{
		wait(NULL);
		close(end[1]);
		dup2(end[0], STDIN_FILENO);
	}
}
