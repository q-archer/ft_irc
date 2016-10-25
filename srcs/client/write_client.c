/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 20:17:25 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 11:43:46 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include "libft.h"
#include "client.h"

void		write_client(t_env *env, int flag)
{
	int		ret;

	if (flag == 1)
	{
		if ((ret = read(0, &env->buf_write, BUF_SIZE)) <= 0)
			error_client(env, "");
		env->buf_write[ret] = '\0';
	}
	else
	{
		if (send(env->socket, env->buf_write, ft_strlen(env->buf_write), 0)
			== -1)
			error_client(env, "sendw");
		ft_bzero(env->buf_write, BUF_SIZE + 1);
	}
}
