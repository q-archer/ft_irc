/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   who_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 12:33:35 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 11:39:46 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "server.h"

void				who_cmd(t_env *env, int client)
{
	t_cl			*tmp_client;

	tmp_client = env->all_fd[client].channel->list_client;
	fill_buf_write(env->all_fd[client].channel->name, env, client);
	fill_buf_write(" :\n", env, client);
	while (tmp_client)
	{
		fill_buf_write("- ", env, client);
		if (env->all_fd[tmp_client->socket].name != NULL)
			fill_buf_write(env->all_fd[tmp_client->socket].name, env, client);
		fill_buf_write("\n", env, client);
		tmp_client = tmp_client->next;
	}
}
