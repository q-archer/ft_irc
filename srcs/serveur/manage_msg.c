/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 14:21:14 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 11:39:23 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <stdlib.h>
#include "libft.h"
#include "server.h"

static int	check_new_line(t_env *env, int client)
{
	int		i;

	i = env->all_fd[client].first_w;
	while (1)
	{
		if (env->all_fd[client].buf_write[i] == '\n')
			return (1);
		else if (env->all_fd[client].buf_write[i] == '\0')
			return (-1);
		i = (i + 1) % (CIRCULAR_BUF_SIZE + 1);
		if (i == env->all_fd[client].first_w)
			return (-1);
	}
	return (-1);
}

static char	*get_buf_line(t_env *env, int client)
{
	char	*line;
	int		i;
	int		j;

	line = NULL;
	i = env->all_fd[client].first_w;
	while (env->all_fd[client].buf_write[i] != '\n')
		i++;
	if ((line = (char *)malloc(sizeof(char) * (i + 2))) == NULL)
		error_server(env, "malloc_glr");
	i = env->all_fd[client].first_w;
	j = 0;
	while (env->all_fd[client].buf_write[i] != '\n')
	{
		line[j] = env->all_fd[client].buf_write[i];
		env->all_fd[client].buf_write[i] = '\0';
		j++;
		i = (i + 1) % (CIRCULAR_BUF_SIZE + 1);
	}
	line[j] = '\n';
	line[j + 1] = '\0';
	env->all_fd[client].buf_write[i] = '\0';
	env->all_fd[client].first_w = (i + 1) % (CIRCULAR_BUF_SIZE + 1);
	return (line);
}

void		manage_msg(int client, t_env *env)
{
	char	*line;

	line = NULL;
	if ((line = get_buf_line(env, client)) == NULL)
		error_server(env, "get_buf_line");
	send(client, line, ft_strlen(line), 0);
	ft_strdel(&line);
	if (check_new_line(env, client) == -1)
		env->all_fd[client].empty_write = 1;
	else
		env->all_fd[client].empty_write = 0;
}
