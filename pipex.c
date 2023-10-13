/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papereir <papereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:23:49 by marvin            #+#    #+#             */
/*   Updated: 2023/10/13 17:26:46 by papereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(int *fd, char **cmds, char *envp[])
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
		ft_sl1(fd[0], cmds[0], pip, envp);
	sl2 = fork();
	if (sl2 < 0)
		error("ERROR Fork of slave 2", 1);
	if (sl2 == 0)
		ft_sl2(fd[1], cmds[1], pip, envp);
	close(pip[0]);
	close(pip[1]);
	while (wait(&status))
		if (WIFEXITED(status))
			res = WIFEXITED(status);
	return (res);
}

void	ft_sl1(int fd, char *cmd1, int pip[2], char *envp[])
{
	char	**cmd;
	char	*path;

	if (fd < 0)
		error("ERROR Can not read the input file\n", 1);
	dup2(pip[1], STDOUT_FILENO);
	close(pip[0]);
	dup2(fd, STDIN_FILENO);
	cmd = ft_split(cmd1, ' ');
	path = get_path(cmd[0], envp);
	if (execve(path, cmd, envp) == -1)
	{
		perror("Bad execve");
		exit(127);
	}
}

void	ft_sl2(int fd, char *cmd2, int pip[2], char *envp[])
{
	char	**cmd;
	char	*path;

	if (fd < 0)
		error ("Error: Can Not Read the Output File\n", 1);
	dup2(pip[0], STDIN_FILENO);
	close(pip[1]);
	dup2(fd, STDOUT_FILENO);
	cmd = ft_split(cmd2, ' ');
	path = get_path(cmd[0], envp);
	if (execve(path, cmd, envp) == -1)
	{	
		perror("Error Bad execve");
		exit(127);
	}
}

char	*get_path(char *cmd, char *envp[])
{
	char	**paths;
	char	*goodpath;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (cmd[0] == '/' && access(cmd, 0) == 0)
		return (cmd);
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	cmd = ft_strjoin("/", cmd);
	while (paths[j])
	{
		goodpath = ft_strjoin(paths[j], cmd);
		if (access(goodpath, 0) == 0)
			return (goodpath);
		j++;
	}
	perror("ERROR: command not found");
	exit(127);
}
