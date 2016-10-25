/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_from_channel.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 15:43:13 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 11:39:41 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "server.h"

void		remove_from_channel_2(t_cl **begin_list, int client,
			t_cl *tmp_client2)
{
	t_cl	*tmp_client;

	tmp_client = *begin_list;
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
	return ;
}

static void	remove_success(t_env *env, int client, char *channel)
{
	char			*tmp;
	char			*msg;

	tmp = NULL;
	msg = NULL;
	if ((tmp = ft_strjoin(env->all_fd[client].name, " has left ")) == NULL)
		error_server(env, "join_jc_sj");
	if ((msg = ft_strjoin(tmp, channel)) == NULL)
		error_server(env, "join_jc_sj2");
	send_channel(env, client, msg, 0);
	ft_strdel(&tmp);
	ft_strdel(&msg);
}

static int	check_client(t_cl *list_client, int client)
{
	t_cl	*tmp_client;

	tmp_client = list_client;
	while (tmp_client)
	{
		if (tmp_client->socket == client)
			return (1);
		tmp_client = tmp_client->next;
	}
	return (-1);
}

void		remove_from_channel(t_env *env, int client)
{
	t_ch	*tmp_channel;

	tmp_channel = env->all_channel;
	while (tmp_channel)
	{
		if (ft_strcmp(tmp_channel->name, env->all_fd[client].channel->name)
			== 0)
		{
			if (check_client(tmp_channel->list_client, client) == 1)
			{
				remove_success(env, client, tmp_channel->name);
				remove_from_channel_2(&tmp_channel->list_client, client, NULL);
			}
		}
		tmp_channel = tmp_channel->next;
	}
}
