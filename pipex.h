/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:43:17 by psoulie           #+#    #+#             */
/*   Updated: 2024/12/06 10:48:36 by psoulie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
//# include <sys/types.h>
# include <sys/wait.h>
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
int		ft_strcmp(const char *s1, const char *s2);
int		openfile(char *file, int mode);
int		ft_splitonsteroids(char *str, int start, char c);
int		quote(char c, int *in_quote);
int		checkquote(char *str);
size_t	ft_strlen(const char *str);
char	**ft_split(char *str, char c);
char	*ft_strnstr(const char *hst, const char *ndl, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
void	here_doc(char *limit, int ac);
void	exec_heredoc(char *limit, int *end);
void	toggle_quote(int *in_quote);

#endif
