/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_client.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 19:25:13 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 11:44:51 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "server.h"

static void	add_channel(t_ch *new_channel, t_env *env)
{
	t_ch	*tmp_channel;

	tmp_channel = env->all_channel;
	if (tmp_channel == NULL)
	{
		env->all_channel = new_channel;
		return ;
	}
	while (tmp_channel)
	{
		if (tmp_channel->next == NULL)
		{
			tmp_channel->next = new_channel;
			return ;
		}
		tmp_channel = tmp_channel->next;
	}
}

static void	create_channel(t_env *env, int client, char *channel)
{
	t_ch	*new_channel;
	t_cl	*new_client;

	new_channel = NULL;
	new_client = NULL;
	if ((new_channel = (t_ch *)malloc(sizeof(t_ch))) == NULL)
		error_server(env, "malloc_ac_cc");
	if ((new_client = (t_cl *)malloc(sizeof(t_cl))) == NULL)
		error_server(env, "malloc_ac_cc_2");
	new_client->socket = client;
	new_client->next = NULL;
	new_channel->list_client = new_client;
	new_channel->next = NULL;
	new_channel->name = NULL;
	if ((new_channel->name = ft_strdup(channel)) == NULL)
		error_server(env, "malloc_ac_cc_3");
	add_channel(new_channel, env);
	env->all_fd[client].channel = new_channel;
}

void		add_client(t_env *env, int client, char *channel)
{
	t_ch	*tmp_channel;
	t_cl	*new_client;

	new_client = NULL;
	tmp_channel = env->all_channel;
	while (tmp_channel)
	{
		if (ft_strcmp(tmp_channel->name, channel) == 0)
		{
			if ((new_client = (t_cl*)malloc(sizeof(t_cl) * 1)) == NULL)
				error_server(env, "malloc_ac");
			new_client->socket = client;
			new_client->next = tmp_channel->list_client;
			tmp_channel->list_client = new_client;
			env->all_fd[client].channel = tmp_channel;
			return ;
		}
		tmp_channel = tmp_channel->next;
	}
	create_channel(env, client, channel);
}
