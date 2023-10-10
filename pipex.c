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

int	main(int argc, char *argv[], char *envp)
{
	char	*cmds[2];
	int		fd[2];

	if (!envp || !*envp)
		error("Error: Array of Pointers to Environment Variables", 1);
	if (argc != 5)
		error("Invalid number of arguments", 1);
	cmds
}