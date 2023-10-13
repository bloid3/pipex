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

int		pipex(int *fd, char **cmds, char *envp[]);
void	ft_sl1(int fd, char *cmd1, int pip[2], char *envp[]);
void	ft_sl2(int fd, char *cmd2, int pip[2], char *envp[]);
char	*get_path(char *cmd, char *envp[]);
void	error(char *err, int e);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
#endif