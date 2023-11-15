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

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

void	child(char **argv, char **envp, int *fd)
{
	int		input;

	input = open(argv[1], O_RDONLY, 0777);
	if (input == -1)
		error("No such file or directory");
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
		error("Error opening output file");
	dup2(fd[0], STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], envp);
}

int	pipex(int *fd, char **argv, char **enpv)
{
	pid_t	pid1;
	int		status;
	int		res;

	if (pipe(fd) == -1)
		error("Error creating pipe");
	pid1 = fork();
	if (pid1 == -1)
		error("file not found");
	if (pid1 == 0)
		child(argv, enpv, fd);
	parent(argv, enpv, fd);
	close(fd[0]);
	close(fd[1]);
	while (wait(&status) > 0)
		if (WIFEXITED(status))
			res = WEXITSTATUS(status);
	return (res);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];

	if (!envp || !*envp)
		error("Environment variables not found");
	if (argc != 5)
		error("Invalid number of arguments");
	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fd[0] == -1 || fd[1] == -1)
		error("Error opening file descriptors");
	return (pipex(fd, argv, envp));
}
