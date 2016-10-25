/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 17:10:26 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/14 14:59:13 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "client.h"

static void		usage(void)
{
	ft_putendl("/connect <machine> [port]");
}

static void		connect_cmd(t_env *env, char *line)
{
	char		**split;

	split = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp(line, "/connect ", 9) == 0)
		{
			if ((split = ft_strsplit(line, ' ')) == NULL)
				break ;
			if (ft_strlen_mat(split) != 3)
				usage();
			else
			{
				init_env(env, ft_atoi(split[2]), split[1]);
				ft_strdel(&line);
				return ;
			}
		}
		else
			usage();
		ft_strdel(&line);
	}
	ft_strdel(&line);
	exit(-1);
}

int				main(int ac, char **av)
{
	t_env		env;

	if (ac < 3)
	{
		usage();
		connect_cmd(&env, NULL);
	}
	else
		init_env(&env, ft_atoi(av[2]), av[1]);
	create_client(&env);
	main_loop(&env);
	close(env.socket);
	return (0);
}
