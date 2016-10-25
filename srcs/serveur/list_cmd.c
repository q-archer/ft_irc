/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 17:29:07 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 11:39:08 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		list_cmd(t_env *env, int client)
{
	t_ch	*tmp_channel;

	tmp_channel = env->all_channel;
	while (tmp_channel)
	{
		fill_buf_write("- ", env, client);
		fill_buf_write(tmp_channel->name, env, client);
		fill_buf_write("\n", env, client);
		tmp_channel = tmp_channel->next;
	}
}
