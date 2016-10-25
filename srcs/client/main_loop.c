/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 20:07:26 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 11:41:48 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "client.h"

void		main_loop(t_env *env)
{
	while (1)
	{
		init_fd(env);
		if (select(env->socket + 1, &env->read_fd, &env->write_fd, NULL, 0) > 0)
			check_fd(env);
	}
}
