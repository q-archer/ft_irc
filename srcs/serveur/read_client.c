/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 17:50:09 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 11:39:37 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <stdlib.h>
#include "libft.h"
#include "server.h"

static void	get_line_read(t_env *env, int client)
{
	char	*line;
	int		i;
	int		j;

	line = NULL;
	i = env->all_fd[client].first_r;
	while (env->all_fd[client].buf_read[i] != '\n')
		i++;
	if ((line = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		error_server(env, "malloc_glr");
	i = env->all_fd[client].first_r;
	j = 0;
	while (env->all_fd[client].buf_read[i] != '\n')
	{
		line[j] = env->all_fd[client].buf_read[i];
		env->all_fd[client].buf_read[i] = '\0';
		j++;
		i = (i + 1) % (CIRCULAR_BUF_SIZE + 1);
	}
	line[j] = '\0';
	env->all_fd[client].buf_read[i] = '\0';
	env->all_fd[client].first_r = (i + 1) % (CIRCULAR_BUF_SIZE + 1);
	if (j != 0)
		manage_line(line, env, client);
	ft_strdel(&line);
}

static int	check_new_line(t_env *env, int client)
{
	int		i;

	i = env->all_fd[client].first_r;
	while (1)
	{
		if (env->all_fd[client].buf_read[i] == '\n')
			return (1);
		else if (env->all_fd[client].buf_read[i] == '\0')
			return (-1);
		i = (i + 1) % (CIRCULAR_BUF_SIZE + 1);
		if (i == env->all_fd[client].first_r)
			return (-1);
	}
	return (-1);
}

static void	fill_circular_buf(char buf[BUF_SIZE + 1], t_env *env, int client)
{
	int		i;
	int		j;
	int		flag;

	i = 0;
	flag = 0;
	j = env->all_fd[client].last_r;
	while (buf[i] != '\0')
	{
		if (j == env->all_fd[client].first_r
			&& env->all_fd[client].buf_read[j] != '\0')
			flag = 1;
		env->all_fd[client].buf_read[j] = buf[i];
		i++;
		j = (j + 1) % (CIRCULAR_BUF_SIZE + 1);
	}
	if (flag == 1)
		env->all_fd[client].first_r = j;
	env->all_fd[client].last_r = j;
}

void		read_client(int client, t_env *env)
{
	char	buf[BUF_SIZE + 1];
	int		ret;

	ret = 0;
	ft_bzero(buf, BUF_SIZE + 1);
	if ((ret = recv(client, buf, BUF_SIZE, 0)) <= 0)
	{
		delete_client(env, client);
		return ;
	}
	buf[ret] = '\0';
	fill_circular_buf(buf, env, client);
	ft_bzero(buf, BUF_SIZE + 1);
	if (check_new_line(env, client) == -1)
		return ;
	get_line_read(env, client);
}
