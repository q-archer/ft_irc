/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buf_write.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 16:13:27 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 11:38:42 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		fill_buf_write(char *str, t_env *env, int client)
{
	int		i;
	int		j;
	int		flag;

	i = 0;
	flag = 0;
	j = env->all_fd[client].last_w;
	while (str[i] != '\0')
	{
		if (j == env->all_fd[client].first_w
			&& env->all_fd[client].buf_write[j] != '\0')
			flag = 1;
		env->all_fd[client].buf_write[j] = str[i];
		i++;
		j = (j + 1) % (CIRCULAR_BUF_SIZE + 1);
	}
	if (flag == 1)
		env->all_fd[client].first_w = j;
	env->all_fd[client].last_w = j;
	env->all_fd[client].empty_write = 0;
}
