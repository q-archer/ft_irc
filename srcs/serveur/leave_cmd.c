/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 16:23:50 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 11:39:05 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "server.h"

static void	success_leave(t_env *env, int client)
{
	char			*msg;

	msg = NULL;
	if (ft_strcmp(env->all_fd[client].channel->name, "#general") != 0)
	{
		remove_from_channel(env, client);
		add_client(env, client, "#general");
		if ((msg = ft_strjoin(env->all_fd[client].name, " has joined #general"))
			== NULL)
			error_server(env, "join_jc_sj");
		send_channel(env, client, msg, 0);
		ft_strdel(&msg);
	}
}

static int	find_in_channel(t_env *env, int client, char *channel)
{
	t_ch	*tmp_channel;
	t_cl	*tmp_client;

	tmp_channel = NULL;
	tmp_client = NULL;
	tmp_channel = env->all_channel;
	while (tmp_channel)
	{
		if (ft_strcmp(tmp_channel->name, channel) == 0)
		{
			tmp_client = tmp_channel->list_client;
			while (tmp_client)
			{
				if (tmp_client->socket == client)
					return (1);
				tmp_client = tmp_client->next;
			}
			return (-1);
		}
		tmp_channel = tmp_channel->next;
	}
	return (-2);
}

void		leave_cmd(char **split_cmd, t_env *env, int client)
{
	int		ret;

	if (split_cmd[1] == NULL)
	{
		success_leave(env, client);
		return ;
	}
	else if (split_cmd[1][0] != '#')
	{
		fill_buf_write("- ! - Error command : /leave ['#'chan]\n",
			env, client);
		return ;
	}
	ret = find_in_channel(env, client, split_cmd[1]);
	if (ret == -2)
		fill_buf_write("- ! - Channel not found.\n", env, client);
	else if (ret == -1)
		fill_buf_write("- ! - Not found in this channel.\n", env, client);
	else
		success_leave(env, client);
}
