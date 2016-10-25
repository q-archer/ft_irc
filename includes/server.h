/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 15:40:09 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 12:11:04 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <sys/select.h>
# define BUF_SIZE 1024
# define CIRCULAR_BUF_SIZE 2048

typedef struct		s_cl
{
	int				socket;
	struct s_cl		*next;
}					t_cl;

typedef struct		s_ch
{
	char			*name;
	struct s_cl		*list_client;
	struct s_ch		*next;
}					t_ch;

typedef struct		s_fd
{
	struct s_ch		*channel;
	char			*name;
	int				set;
	char			buf_read[CIRCULAR_BUF_SIZE + 1];
	char			buf_write[CIRCULAR_BUF_SIZE + 1];
	int				first_r;
	int				last_r;
	int				first_w;
	int				last_w;
	char			empty_write;
}					t_fd;

typedef struct		s_env
{
	int				end;
	char			*bin;
	struct s_fd		*all_fd;
	struct s_ch		*all_channel;
	int				server_sock;
	int				max_fd_nbr;
	int				max_fd;
	int				port;
	fd_set			read_fd;
	fd_set			write_fd;
}					t_env;

void				init_env(t_env *env, int port, char *bin);
void				create_server(t_env *env);
void				accept_server(t_env *env);
void				error_server(t_env *env, char *e);
void				debug_print_env(t_env env);
void				main_loop(t_env *env);
void				init_fd(t_env *env);
void				init_channel(t_env *env);
void				check_fd(t_env *env, int ret);
void				read_client(int client, t_env *env);
void				clean_fd(int fd, t_env *env);
void				manage_msg(int client, t_env *env);
void				add_client(t_env *env, int client, char *channel);
void				delete_client(t_env *env, int client);
void				manage_cmd(int client, t_env *env, char *cmd);
void				nick_cmd(char **split, t_env *env, int client);
void				join_cmd(char **split, t_env *env, int client);
void				leave_cmd(char **split, t_env *env, int client);
void				who_cmd(t_env *env, int client);
void				msg_cmd(t_env *env, int client, char *cmd);
void				list_cmd(t_env *env, int client);
void				help_cmd(t_env *env, int client);
void				fill_buf_write(char *str, t_env *env, int client);
void				send_channel(t_env *env, int client, char *message,
					int src);
void				manage_line(char *line, t_env *env, int client);
void				cmd_server(t_env *env);
void				remove_from_channel(t_env *env, int client);
void				send_message(char *name, char *msg, t_env *env,
					int client[2]);
void				free_env(t_env *env);

#endif
