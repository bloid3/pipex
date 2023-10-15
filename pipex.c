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

void	child(char **argv, char **envp, int *fd)
{
	int		input;

	input = open(argv[1], O_RDONLY, 0777);
	if (input == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(input, STDIN_FILENO);
	close(fd[0]);
	execute(argv[2], envp);
}

void	parent(char **argv, char **envp, int *fd)
{
	int		out;
	out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (out == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid1 = fork();
		if (pid1 == -1)
			error();
		if (pid1 == 0)
			child(argv, envp, fd);
		waitpid(pid1, NULL, 0);
		parent(argv, envp, fd);
	}
	else
	{
		ft_putstr_fd("Error: Bad arguments", 2);
	}
	return (0);
}