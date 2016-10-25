/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 11:57:29 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 11:41:39 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "client.h"

void	error_client(t_env *env, char *error)
{
	if (env->socket != -1)
		close(env->socket);
	ft_putendl_fd(error, 2);
	exit(-1);
}
