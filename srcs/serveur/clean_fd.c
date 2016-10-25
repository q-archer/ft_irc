/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 18:55:23 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 11:37:03 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "server.h"

void		clean_fd(int fd, t_env *env)
{
	ft_strdel(&env->all_fd[fd].name);
	env->all_fd[fd].name = NULL;
	env->all_fd[fd].set = -1;
	ft_bzero(env->all_fd[fd].buf_read, CIRCULAR_BUF_SIZE + 1);
	ft_bzero(env->all_fd[fd].buf_write, CIRCULAR_BUF_SIZE + 1);
	env->all_fd[fd].empty_write = 1;
	env->all_fd[fd].first_r = 0;
	env->all_fd[fd].last_r = 0;
	env->all_fd[fd].first_w = 0;
	env->all_fd[fd].last_w = 0;
	close(fd);
}
