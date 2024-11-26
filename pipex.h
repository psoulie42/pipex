/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:43:17 by psoulie           #+#    #+#             */
/*   Updated: 2024/11/25 15:06:38 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdarg.h>
# include <errno.h>

int		ft_printf(const char *str, ...);
int		ft_countargs(const char *str, char c);
int		ft_isprint(int a);
int		ft_railswitch(va_list arg, char a);
int		ft_putcharn(int a);
int		ft_putstrn(char *str);
int		ft_putnbrn(int nb);
int		ft_putunbrn(unsigned int n);
int		ft_putnbrhexn(unsigned long n, char a);
int		ft_putptrn(void *ptr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
char	**ft_split(const char *str, char c);
char	*ft_strnstr(const char *hst, const char *ndl, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
void	here_doc(char *limit, int ac);
void	exec_heredoc(char *limit, int *end);

#endif
