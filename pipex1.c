/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:32:24 by hbombur           #+#    #+#             */
/*   Updated: 2022/03/22 16:24:35 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char **argv, char **envp)
{
	int fd[2];
	int pid;
	
	if (argc != 5)
		ft_putstr("Err: use format ./pipex file1 cmd1 cmd2 file2");
	pid = pipe(fd);
	fd[0] = open(argv[1], O_RDONLY);
	pid = fork();
	if (pid == -1)
		p_error("fork");
	if (pid == 0)
	{
		f_child();
	}
	if (pid > 0)
	{
		f_parent();
	}
	return (0);
}