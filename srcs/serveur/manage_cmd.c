/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 12:19:46 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 12:06:50 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "server.h"

static void	manage_cmd2(int client, t_env *env, char **split_cmd)
{
	if (ft_strcmp(split_cmd[0], "/nick") == 0)
		nick_cmd(split_cmd, env, client);
	else if (ft_strcmp(split_cmd[0], "/join") == 0)
		join_cmd(split_cmd, env, client);
	else if (ft_strcmp(split_cmd[0], "/leave") == 0)
		leave_cmd(split_cmd, env, client);
	else if (ft_strcmp(split_cmd[0], "/who") == 0)
		who_cmd(env, client);
	else if (ft_strcmp(split_cmd[0], "/help") == 0)
		help_cmd(env, client);
	else if (ft_strcmp(split_cmd[0], "/list") == 0)
		list_cmd(env, client);
	else if (ft_strcmp(split_cmd[0], "/quit") == 0)
		delete_client(env, client);
	else
		fill_buf_write("- ! - Error command. ( /help )\n", env, client);
}

void		manage_cmd(int client, t_env *env, char *cmd)
{
	char	**split;

	if (ft_strncmp(cmd, "/msg", 4) == 0)
	{
		msg_cmd(env, client, cmd);
		return ;
	}
	split = NULL;
	if ((split = ft_strsplit(cmd, ' ')) == NULL)
	{
		ft_strdel(&cmd);
		error_server(env, "split_mc");
	}
	else
		manage_cmd2(client, env, split);
	ft_free_mat(&split);
}
