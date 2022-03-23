/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:32:24 by hbombur           #+#    #+#             */
/*   Updated: 2022/03/23 22:17:31 by hbombur          ###   ########.fr       */
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

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid;
	int	pfd[2];

	p_error_pipe(pfd);
	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	pid = p_error_fork();
	if (pid)
		pr_parent(fd, pfd, envp, argv);
	else
		pr_child(fd, pfd, envp, argv);
	return (0);
}
