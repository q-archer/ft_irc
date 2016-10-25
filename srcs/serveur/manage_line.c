/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 17:19:51 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 11:39:20 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		manage_line(char *line, t_env *env, int client)
{
	t_cl	*tmp_client;

	if (line[0] == '/')
		manage_cmd(client, env, line);
	else
	{
		tmp_client = env->all_fd[client].channel->list_client;
		while (tmp_client)
		{
			fill_buf_write("<", env, tmp_client->socket);
			fill_buf_write(env->all_fd[client].name, env, tmp_client->socket);
			fill_buf_write("> ", env, tmp_client->socket);
			fill_buf_write(line, env, tmp_client->socket);
			fill_buf_write("\n", env, tmp_client->socket);
			tmp_client = tmp_client->next;
		}
	}
}
