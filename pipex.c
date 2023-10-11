/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:23:49 by marvin            #+#    #+#             */
/*   Updated: 2023/10/10 16:23:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		pipex(int *fd, char **cmds, char *envp[])
{
	int		pip[2];
	pid_t	sl1;
	pid_t	sl2;
	int		status;
	int		res;

	res = 0;
	pipe(pip);
	sl1 = fork();
	if (sl1 < 0)
		error("ERROR Fork of slave 1", 1);
	if (sl1 == 0)
		
}

void	ft_sl1(int fd, char *cmd1, int pip[2], char *envp[])
{
	char	**cmd;
	char	*path;
	if (fd < 0)
		error("ERROR Can not read the input file\n", 1);
	dup2(pip[1], STDOUT_FILENO);
	
}