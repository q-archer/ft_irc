/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 15:41:53 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 11:46:33 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <sys/select.h>

# define BUF_SIZE 1024

typedef struct		s_env
{
	char			buf_read[BUF_SIZE + 1];
	char			buf_write[BUF_SIZE + 1];
	int				socket;
	int				port;
	char			*addr;
	fd_set			read_fd;
	fd_set			write_fd;
}					t_env;

void				create_client(t_env *env);
void				init_env(t_env *env, int port, char *addr);
void				init_fd(t_env *env);
void				main_loop(t_env *env);
void				write_client(t_env *env, int flag);
void				read_client(t_env *env);
void				check_fd(t_env *env);
void				error_client(t_env *env, char *error);

#endif
