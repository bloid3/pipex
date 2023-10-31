/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papereir <papereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:22:50 by marvin            #+#    #+#             */
/*   Updated: 2023/10/13 15:49:36 by papereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

void	error(char *message);
void	ft_putendl_fd(char *s, int fd);
void	child(char **argv, char **envp, int *fd);
void	parent(char **argv, char **envp, int *fd);
char	*find_path(char *cmd, char **envp);
void	execute(char *argv, char **envp);
char	*ft_strnstr(const char	*big, const char *little, size_t len);
char	**ft_malloc_error(char **tab);
size_t	ft_nb_words(char const *s, char c);
void	ft_get_next_word(char **next_word, size_t *next_word_len, char c);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	ft_free_array(char **array);

#endif