/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 11:54:32 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 11:59:25 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		send_message(char *name, char *msg, t_env *env, int client[2])
{
	fill_buf_write("<", env, client[0]);
	fill_buf_write(env->all_fd[client[1]].name, env, client[0]);
	fill_buf_write("> ", env, client[0]);
	fill_buf_write(name, env, client[0]);
	fill_buf_write(": ", env, client[0]);
	fill_buf_write(msg, env, client[0]);
	fill_buf_write("\n", env, client[0]);
}
