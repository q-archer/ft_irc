/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:26:57 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 11:38:57 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "server.h"

static void			init_var(t_env *env, int client)
{
	env->all_fd[client].name = NULL;
	env->all_fd[client].set = -1;
	ft_bzero(env->all_fd[client].buf_read, CIRCULAR_BUF_SIZE + 1);
	ft_bzero(env->all_fd[client].buf_write, CIRCULAR_BUF_SIZE + 1);
	env->all_fd[client].empty_write = 1;
	env->all_fd[client].first_r = 0;
	env->all_fd[client].last_r = 0;
	env->all_fd[client].first_w = 0;
	env->all_fd[client].last_w = 0;
}

void				init_env(t_env *env, int port, char *bin)
{
	struct rlimit	limits;
	int				i;

	env->bin = bin;
	env->all_fd = NULL;
	if (getrlimit(RLIMIT_NOFILE, &limits) == -1)
		error_server(env, "getrlimit");
	if ((env->all_fd = (struct s_fd *)malloc(sizeof(struct s_fd)
		* limits.rlim_cur)) == NULL)
		error_server(env, "malloc ie");
	i = -1;
	env->max_fd_nbr = limits.rlim_cur;
	while (++i < env->max_fd_nbr)
	{
		init_var(env, i);
	}
	env->end = 0;
	env->server_sock = -1;
	env->max_fd = -1;
	env->port = port;
}
