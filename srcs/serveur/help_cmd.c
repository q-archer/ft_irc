/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 12:43:40 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 11:38:50 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "server.h"

void		help_cmd(t_env *env, int client)
{
	fill_buf_write("-\n", env, client);
	fill_buf_write("/nick <nickname> : to change you nickname\n\
/join <#chan> : to join a channel\n\
/leave [#channel] : to leave a channel\n\
/who : to see who is log on the channel\n\
/msg <nick> <message> : to send a private message\n\
/list : to list all channels\n\
/quit : to end connection\n", env, client);
	fill_buf_write("-\n", env, client);
}
