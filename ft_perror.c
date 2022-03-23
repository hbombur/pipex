/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:44:36 by hbombur           #+#    #+#             */
/*   Updated: 2022/03/23 22:16:51 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	p_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	p_error_n(int	code, int index, char **argv, char *cmd)
{
	
	if (code == 2)
	{
		ft_putstr_fd("No such file or directory: ", 2);
		
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd("\n", 2);
		exit(code);
	}
	if (code == 141)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putstr_fd(argv[index], 2);
		ft_putstr_fd("\n", 2);
		exit(code);
	}
	
	strerror(code);
	exit(EXIT_FAILURE);
}

void	p_error_pipe(int *pfd)
{
	if (pipe(pfd) == -1)
		p_error("pipe");
}

int	p_error_fork(void)
{
	int	i;

	i = fork();
	if (i == -1)
		p_error("fork");
	return (i);
}
