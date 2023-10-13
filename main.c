/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: papereir <papereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:46:24 by marvin            #+#    #+#             */
/*   Updated: 2023/10/13 15:36:38 by papereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*cmds[2];
	int		fd[2];

	if (!envp || !*envp)
		error("ERROR of Environment Variables", 1);
	if (argc != 5)
		error("ERROR Invalid Number of Arguments", 1);
	cmds[0] = argv[2];
	cmds[1] = argv[3];
	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC);
	return (pipex(fd, cmds, envp));
}
