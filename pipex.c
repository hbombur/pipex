/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:43:59 by hbombur           #+#    #+#             */
/*   Updated: 2022/03/22 16:43:48 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	p_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
 
static void	pipe_parent(int *fd, char **argv, char **envp)
{
	int		file;
	char	*cmd;

	file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1)
		p_error("Err: Open file2");
	if ((dup2(fd[0], STDIN_FILENO)) == -1)
		p_error("Err: Dup2 fd[0]");
	if ((dup2(file, STDOUT_FILENO)) == -1)
		p_error("Err:Dup2 file2");
	close(fd[1]);
	cmd = ft_split_cmd(argv[3], ' ');
}

static void	pipe_child(int *fd, char **argv, char **envp)
{
	int		file;
	char	**cmd;

	file = open(argv[1], O_RDONLY);
	if (file == -1)
		p_error("Err: Open file1");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		p_error("Err: Dup2 fd[1]");
	if (dup2(file, STDIN_FILENO) == -1)
		p_error("Err: Dup2 file1");
	close(fd[0]);
	cmd = ft_split_cmd(argv[2], ' ');
	if (execve(check_path(cmd[0], envp), cmd, envp) == -1) //check_path rework
		error("Err: Cmd2 not found");
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid;

	if (argc != 5)
		(ft_putstr_fd("Error!: Use format ./pipex file1 cmd1 cmd2 file2", 2));
	else
	{
		if (pipe(fd) == -1)
			p_error("Err: Pipe");
		pid = fork();
		if (pid == -1)
			p_error("Err: Fork");
		if (pid == 0)
			pipe_child(fd, argv, envp);
		wait(NULL);
		pipe_parent(fd, argv, envp);
	}
	return (0);
}
