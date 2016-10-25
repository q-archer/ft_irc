/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 12:33:44 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 11:59:08 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "server.h"

static char			*get_name(char *cmd, int *index, t_env *env)
{
	int				i;
	int				first;
	char			*ret;

	i = *index;
	first = -1;
	ret = NULL;
	while (cmd[i] != '\0')
	{
		if (cmd[i] != ' ' && first == -1)
			first = i;
		else if (cmd[i] == ' ' && first != -1)
		{
			if ((ret = ft_strsub(cmd, first, i - first)) == NULL)
				error_server(env, "sub_gn");
			break ;
		}
		i++;
	}
	*index = i;
	return (ret);
}

static char			*get_msg(char *cmd, int index, t_env *env)
{
	int				first;
	char			*ret;

	ret = NULL;
	index++;
	first = index;
	while (cmd[index] != '\0')
		index++;
	if ((ret = ft_strsub(cmd, first, index - first)) == NULL)
		error_server(env, "sub_gm");
	return (ret);
}

static void			send_error(int client, t_env *env, int code, char *dest)
{
	if (code == 0)
	{
		fill_buf_write("- ! - Error command. /msg <nick> <message>\n",
			env, client);
	}
	else if (code == 1)
	{
		fill_buf_write("- ! - ", env, client);
		fill_buf_write(dest, env, client);
		fill_buf_write(" not found.\n", env, client);
	}
}

static void			check_msg(char *name, char *msg, t_env *env, int client)
{
	int				i;
	int				norme[2];

	i = -1;
	if (ft_strlen(name) == 0 || ft_strlen(msg) == 0)
	{
		send_error(client, env, 0, NULL);
		return ;
	}
	while (++i < env->max_fd_nbr)
	{
		if (env->all_fd[i].set != -1)
		{
			if (ft_strcmp(name, env->all_fd[i].name) == 0)
			{
				norme[0] = i;
				norme[1] = client;
				send_message(name, msg, env, norme);
				return ;
			}
		}
	}
	send_error(client, env, 1, name);
}

void				msg_cmd(t_env *env, int client, char *cmd)
{
	int				i;
	char			*name;
	char			*msg;

	name = NULL;
	msg = NULL;
	i = 4;
	while (cmd[i] != '\0')
	{
		if (cmd[i] == ' ' && name == NULL)
			name = get_name(cmd, &i, env);
		else if (cmd[i] == ' ' && name != NULL)
		{
			msg = get_msg(cmd, i, env);
			break ;
		}
		else
			i++;
	}
	if (name == NULL || msg == NULL)
		send_error(client, env, 0, NULL);
	else
		check_msg(name, msg, env, client);
	ft_strdel(&name);
	ft_strdel(&msg);
}
