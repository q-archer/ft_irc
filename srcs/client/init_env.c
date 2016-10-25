/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 20:04:04 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 11:42:55 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "client.h"

void		init_env(t_env *env, int port, char *addr)
{
	env->socket = -1;
	env->port = port;
	env->addr = addr;
	ft_bzero(env->buf_read, BUF_SIZE + 1);
	ft_bzero(env->buf_write, BUF_SIZE + 1);
}
