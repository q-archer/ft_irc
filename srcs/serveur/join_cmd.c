/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 12:33:27 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 11:45:38 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "server.h"

static void			success_join(t_env *env, int client, char *channel)
{
	char			*tmp;
	char			*msg;

	tmp = NULL;
	msg = NULL;
	remove_from_channel(env, client);
	add_client(env, client, channel);
	if ((tmp = ft_strjoin(env->all_fd[client].name, " has joined ")) == NULL)
		error_server(env, "join_jc_sj");
	if ((msg = ft_strjoin(tmp, channel)) == NULL)
		error_server(env, "join_jc_sj2");
	send_channel(env, client, msg, 0);
	ft_strdel(&tmp);
	ft_strdel(&msg);
}

void				join_cmd(char **split, t_env *env, int client)
{
	int				i;

	if (split[1] == NULL)
		fill_buf_write("- ! - Error command : /join <#chan>. \
(#chan: alph-num)\n", env, client);
	else if (split[1][0] != '#')
		fill_buf_write("- ! - Error command : /join <#chan>. <'#'chan>\n",
			env, client);
	else
	{
		i = -1;
		while (split[1][++i] != '\0')
		{
			if (ft_isalnum(split[1][i]) == 0 && i != 0)
				fill_buf_write("- ! - Error command - #chan: \
only alph-num chars.\n", env, client);
		}
		if (i == 1)
		{
			fill_buf_write("- ! - Error command - not good channel name\n",
				env, client);
			return ;
		}
		success_join(env, client, split[1]);
	}
}
