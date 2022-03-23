/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:51:32 by hbombur           #+#    #+#             */
/*   Updated: 2022/03/23 22:18:16 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pr_parent(int	*fd, int *pfd, char **envp, char **argv)
{
	dup2(fd[0], 0);
	close(fd[0]);
	dup2(pfd[1], 1);
	close(pfd[1]);
	close(pfd[0]);
	if (fd[0] >= 0)
		execve(find_path(envp, argv, 2), get_cmd(argv, 2), envp);
	else
		p_error_n(2, 2, argv, NULL);
}

void	pr_child(int	*fd, int *pfd, char **envp, char **argv)
{
	dup2(fd[1], 1);
	close(fd[1]);
	dup2(pfd[0], 0);
	close(pfd[0]);
	close(pfd[1]);
	waitpid(0, NULL, 0);
	execve(find_path(envp, argv, 3), get_cmd(argv, 3), envp);
}
