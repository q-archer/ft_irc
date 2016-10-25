/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nick_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 12:33:18 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 11:39:34 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "server.h"

static void	success_change(t_env *env, int client, char *nickname)
{
	char	*saved_name;
	char	*tmp;
	char	*msg;

	saved_name = NULL;
	tmp = NULL;
	msg = NULL;
	if ((saved_name = ft_strdup(env->all_fd[client].name)) == NULL)
		error_server(env, "dup_nc");
	ft_strdel(&env->all_fd[client].name);
	if ((env->all_fd[client].name = ft_strdup(nickname)) == NULL)
		error_server(env, "dup_nc2");
	if ((tmp = ft_strjoin(saved_name, " new nickname is ")) == NULL)
		error_server(env, "join_nc");
	if ((msg = ft_strjoin(tmp, env->all_fd[client].name)) == NULL)
		error_server(env, "join_nc2");
	send_channel(env, client, msg, 0);
	ft_strdel(&saved_name);
	ft_strdel(&tmp);
	ft_strdel(&msg);
}

void		nick_cmd(char **split, t_env *env, int client)
{
	if (split[1] == NULL)
		fill_buf_write("- ! - Error command : /nick <nickname>. \
			(max 9 char)\n", env, client);
	else
	{
		if (ft_strlen(split[1]) > 9)
			fill_buf_write("- ! -Error command : nickname : maximum 9 \
				characters.\n", env, client);
		else
			success_change(env, client, split[1]);
	}
}
