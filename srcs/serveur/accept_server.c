/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accept_server.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 17:58:12 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 11:36:53 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include "libft.h"
#include "server.h"

static void				base_name(t_env *env, int client)
{
	char				*nbr;

	nbr = NULL;
	if ((nbr = ft_itoa(client)) == NULL)
		error_server(env, "itoa_as");
	env->all_fd[client].name = ft_strjoin("Client_", nbr);
	if (env->all_fd[client].name == NULL)
		error_server(env, "join_as2");
	ft_strdel(&nbr);
}

void					accept_server(t_env *env)
{
	int					cs;
	struct sockaddr_in	csin;
	unsigned int		cslen;
	char				*msg;

	msg = NULL;
	if ((cs = accept(env->server_sock, (struct sockaddr *)&csin, &cslen)) == -1)
		error_server(env, "accept");
	ft_strdel(&(env->all_fd[cs].name));
	base_name(env, cs);
	env->all_fd[cs].set = 1;
	if (cs > env->max_fd)
		env->max_fd = cs;
	add_client(env, cs, "#general");
	ft_putstr("Connection: ");
	ft_putendl(env->all_fd[cs].name);
	if ((msg = ft_strjoin(env->all_fd[cs].name, " has joined #general. ( \
/help : to see all commands )")) == NULL)
		error_server(env, "join_as");
	send_channel(env, cs, msg, 0);
	ft_strdel(&msg);
}
