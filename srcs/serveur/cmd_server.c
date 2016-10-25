/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_server.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 20:38:50 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 11:37:06 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "server.h"

void		cmd_server(t_env *env)
{
	int		ret;
	char	buf[BUF_SIZE + 1];

	ft_bzero(buf, BUF_SIZE + 1);
	ret = read(0, &buf, BUF_SIZE);
	buf[ret] = '\0';
	if (ft_strcmp(buf, "/quit\n") == 0)
		env->end = 1;
}
