/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 17:09:38 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/14 13:26:53 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "server.h"
#include "libft.h"

#include <sys/socket.h>

static void				usage(char *bin)
{
	ft_putstr_fd("usage : ", 2);
	ft_putstr_fd(bin, 2);
	ft_putendl_fd(" <port>", 2);
}

int						main(int ac, char **av)
{
	t_env				env;

	if (ac != 2)
	{
		usage(av[0]);
		return (-1);
	}
	init_env(&env, ft_atoi(av[1]), av[0]);
	init_channel(&env);
	create_server(&env);
	main_loop(&env);
	free_env(&env);
	return (0);
}
