/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_channel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 17:41:39 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 11:39:44 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		send_channel(t_env *env, int client, char *message, int src)
{
	t_cl	*tmp_client;

	tmp_client = env->all_fd[client].channel->list_client;
	while (tmp_client)
	{
		if (src == 0)
			fill_buf_write("- ! - ", env, tmp_client->socket);
		fill_buf_write(message, env, tmp_client->socket);
		fill_buf_write("\n", env, tmp_client->socket);
		tmp_client = tmp_client->next;
	}
}
