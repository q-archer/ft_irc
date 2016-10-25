/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_channel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 18:40:40 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 11:38:54 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "server.h"

void		init_channel(t_env *env)
{
	int		i;

	env->all_channel = NULL;
	if ((env->all_channel = (t_ch*)malloc(sizeof(t_ch) * 1)) == NULL)
		error_server(env, "malloc_ic");
	if ((env->all_channel->name = ft_strdup("#general")) == NULL)
		error_server(env, "dup_ic");
	env->all_channel->list_client = NULL;
	env->all_channel->next = NULL;
	i = 0;
	while (i < env->max_fd_nbr)
	{
		env->all_fd[i].channel = env->all_channel;
		i++;
	}
}
