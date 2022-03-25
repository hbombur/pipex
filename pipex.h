/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:45:05 by hbombur           #+#    #+#             */
/*   Updated: 2022/03/25 12:40:17 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

void	p_error(char *str);
void	ft_putstr_fd(char *str, int fd);
char	**ft_split(char const *argv, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	p_error_pipe(int *pfd);
int		p_error_fork(void);
void	p_error_n(int code, int index, char **argv, char *cmd);
char	**ft_free(char **arr);
char	*find_path(char **envp, char **argv, int index);
char	**get_cmd(char **argv, int i);
char	*get_path(char **tmp, char *cmd);
void	pr_parent(int *fd, int *pfd, char **envp, char **argv);
void	pr_child(int *fd, int *pfd, char **envp, char **argv);

#endif
