/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 12:37:00 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 11:38:33 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "server.h"

static void	print_all_fd(struct s_fd *all_fd, int size)
{
	int		i;

	i = 0;
	ft_putstr("all_fd      : [");
	while (i < size)
	{
		ft_putstr("(");
		if (all_fd[i].name != NULL)
			ft_putstr(all_fd[i].name);
		else
			ft_putstr("NULL");
		ft_putstr(" | ");
		ft_putnbr(all_fd[i].set);
		ft_putstr(")");
		if (i + 1 < size)
			ft_putstr(", ");
		i++;
	}
	ft_putendl("]");
}

void		debug_print_env(t_env env)
{
	ft_putstr("bin         : [");
	ft_putstr(env.bin);
	ft_putstr("]\n");
	print_all_fd(env.all_fd, env.max_fd_nbr);
	ft_putstr("server_sock : [");
	ft_putnbr(env.server_sock);
	ft_putstr("]\n");
	ft_putstr("max_fd_nbr  : [");
	ft_putnbr(env.max_fd_nbr);
	ft_putstr("]\n");
	ft_putstr("max_fd      : [");
	ft_putnbr(env.max_fd);
	ft_putstr("]\n");
	ft_putstr("port        : [");
	ft_putnbr(env.port);
	ft_putstr("]\n");
}
