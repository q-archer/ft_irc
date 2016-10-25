/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_server.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:47:29 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 11:44:04 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "server.h"

void					create_server(t_env *env)
{
	struct protoent		*proto;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (!proto)
		error_server(env, "proto");
	if ((env->server_sock = socket(PF_INET, SOCK_STREAM, proto->p_proto)) == -1)
		error_server(env, "socket");
	sin.sin_family = AF_INET;
	sin.sin_port = htons(env->port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(env->server_sock, (const struct sockaddr *)&sin, sizeof(sin))
		== -1)
		error_server(env, "socket");
	listen(env->server_sock, 42);
}
