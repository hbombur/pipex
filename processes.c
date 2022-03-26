/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:51:32 by hbombur           #+#    #+#             */
/*   Updated: 2022/03/26 11:53:07 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **tmp, char *cmd)
{
	char	*freetmp;
	int		i;
	char	*path;

	i = 0;
	while (tmp[i])
	{
		path = ft_strjoin(tmp[i], "/");
		freetmp = path;
		path = ft_strjoin(path, cmd);
		free(freetmp);
		if (!(access(path, F_OK)))
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

char	**get_cmd(char **argv, int i)
{
	char	**cmd;

	cmd = ft_split(argv[i], ' ');
	return (cmd);
}

char	*find_path(char **envp, char **argv, int index)
{
	char	**tmp;
	char	*path;
	int		i;
	char	**cmd;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			tmp = ft_split(envp[i] + 5, ':');
		i++;
	}
	cmd = get_cmd(argv, index);
	path = get_path(tmp, cmd[0]);
	ft_free(tmp);
	if (path == NULL)
		p_error_n(141, index, argv, cmd[0]);
	return (path);
}

void	pr_parent(int	*fd, int *pfd, char **envp, char **argv)
{
	if (dup2(fd[0], STDIN_FILENO) == -1)
		p_error("dup2 fd[0]");
	close(fd[0]);
	if (dup2(pfd[1], STDOUT_FILENO) == -1)
		p_error("dup2 pfd[1]");
	close(pfd[1]);
	close(pfd[0]);
	if (fd[0] >= 0)
	{
		// execve(find_path(envp, argv, 2), get_cmd(argv, 2), envp);
		if (execve(find_path(envp, argv, 2), get_cmd(argv, 2), envp) == -1)
			p_error("command not found");
	}	
	else
		p_error_n(2, 2, argv, NULL);
}

void	pr_child(int	*fd, int *pfd, char **envp, char **argv)
{
	if (dup2(fd[1], 1) == -1)
		p_error("dup2 fd[1]");
	close(fd[1]);
	if (dup2(pfd[0], 0) == -1)
		p_error("dup2 pfd[0]");
	close(pfd[0]);
	close(pfd[1]);
	waitpid(0, NULL, 0);
	if (execve(find_path(envp, argv, 3), get_cmd(argv, 3), envp) == -1)
		p_error("command not found");
}
