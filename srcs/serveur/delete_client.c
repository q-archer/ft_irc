/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_client.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 13:03:25 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 11:38:37 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "server.h"

static void	disconnect_client(t_env *env, int client)
{
	clean_fd(client, env);
	ft_putstr("Disconnection: client #");
	ft_putnbr(client);
	ft_putchar('\n');
}

static void	delete_client2(t_cl **begin_list, int client)
{
	t_cl	*tmp_client;
	t_cl	*tmp_client2;

	tmp_client = *begin_list;
	tmp_client2 = NULL;
	while (tmp_client)
	{
		if (tmp_client->socket == client && tmp_client2 == NULL)
		{
			tmp_client = tmp_client->next;
			free(*begin_list);
			*begin_list = NULL;
			*begin_list = tmp_client;
			return ;
		}
		else if (tmp_client->socket == client)
		{
			tmp_client2->next = tmp_client->next;
			free(tmp_client);
			tmp_client = NULL;
			return ;
		}
		tmp_client2 = tmp_client;
		tmp_client = tmp_client->next;
	}
}

void		delete_client(t_env *env, int client)
{
	t_ch	*tmp_channel;
	char	*msg;

	msg = NULL;
	if ((msg = ft_strjoin(env->all_fd[client].name, " has quit.")) == NULL)
		error_server(env, "join_dc");
	send_channel(env, client, msg, 0);
	ft_strdel(&msg);
	tmp_channel = env->all_channel;
	while (tmp_channel)
	{
		if (ft_strcmp(tmp_channel->name, env->all_fd[client].channel->name)
			== 0)
		{
			delete_client2(&tmp_channel->list_client, client);
			break ;
		}
		tmp_channel = tmp_channel->next;
	}
	disconnect_client(env, client);
}
