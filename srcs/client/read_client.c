/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 20:16:23 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/14 12:29:07 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include "libft.h"
#include "client.h"

void		read_client(t_env *env)
{
	int		ret;

	if ((ret = recv(env->socket, env->buf_read, BUF_SIZE, 0)) <= 0)
		error_client(env, "Server disconnected");
	env->buf_read[ret] = '\0';
	if (env->buf_read[0] != '\0')
		ft_putstr(env->buf_read);
	ft_bzero(env->buf_read, BUF_SIZE + 1);
}
