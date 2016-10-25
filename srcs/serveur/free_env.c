/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 17:32:14 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 12:13:39 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "server.h"

static void	free_client(t_cl *channel)
{
	t_cl	*tmp_client;

	while (channel)
	{
		tmp_client = channel;
		channel = channel->next;
		free(tmp_client);
		tmp_client = NULL;
	}
}

static void	free_channel(t_env *env)
{
	t_ch	*tmp_channel;

	while (env->all_channel)
	{
		tmp_channel = env->all_channel;
		env->all_channel = env->all_channel->next;
		if (tmp_channel->name != NULL)
			ft_strdel(&tmp_channel->name);
		free_client(tmp_channel->list_client);
	}
}

void		free_env(t_env *env)
{
	int		i;

	i = 0;
	if (env)
	{
		if (env->all_fd != NULL)
		{
			while (i < env->max_fd_nbr)
			{
				if (env->all_fd[i].name != NULL)
					ft_strdel(&env->all_fd[i].name);
				i++;
			}
			free(env->all_fd);
			env->all_fd = NULL;
		}
		free_channel(env);
		close(env->server_sock);
	}
}
