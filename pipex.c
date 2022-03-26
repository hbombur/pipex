/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:32:24 by hbombur           #+#    #+#             */
/*   Updated: 2022/03/26 11:27:52 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid;
	int	pfd[2];

	if (argc == 5)
	{
		p_error_pipe(pfd);
		fd[0] = open(argv[1], O_RDONLY);
		if (fd[0] == -1)
			p_error("open file1");
		fd[1] = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (fd[1] == -1)
			p_error("open file2");
		pid = p_error_fork();
		if (pid)
			pr_parent(fd, pfd, envp, argv);
		else
			pr_child(fd, pfd, envp, argv);
	}
	else
		write(1, "Err: use format ./pipex file1 cmd1 cmd2 file2", 45);
	return (0);
}
