/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 16:08:19 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 11:39:12 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "server.h"
#include "libft.h"

void		main_loop(t_env *env)
{
	env->max_fd = env->server_sock;
	while (1)
	{
		if (env->end == 1)
			break ;
		init_fd(env);
		check_fd(env, select(env->max_fd + 1, &env->read_fd, &env->write_fd,
			NULL, 0));
	}
}
