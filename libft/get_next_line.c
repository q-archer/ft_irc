/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 12:32:26 by qarcher           #+#    #+#             */
/*   Updated: 2015/03/03 18:31:33 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

char		*ft_realloc(char *str, int size)
{
	char	*new_s;
	int		size_str;
	int		i;

	size_str = ft_strlen(str);
	new_s = (char *)malloc(sizeof(char) * (size + size_str + 1));
	ft_bzero(new_s, size + size_str + 1);
	i = 0;
	if (new_s)
	{
		while (i < size_str)
		{
			new_s[i] = str[i];
			i++;
		}
		new_s[i] = '\0';
	}
	ft_strdel(&str);
	return (new_s);
}

int			check_endl(char buf[BUFFSIZE + 1])
{
	int		i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int			get_next_line2(char *s, char **line, int end)
{
	char	*tmp;
	int		i;

	tmp = ft_strsub(s, 0, end);
	if (tmp == NULL)
		return (-1);
	if ((*line = ft_realloc(*line, ft_strlen(tmp))) == NULL)
		return (-1);
	ft_strcat(*line, tmp);
	ft_strdel(&tmp);
	tmp = ft_strdup(s);
	if (tmp == NULL)
		return (-1);
	ft_bzero(s, ft_strlen(tmp));
	i = 0;
	while (tmp[++end] != '\0')
		s[i++] = tmp[end];
	ft_strdel(&tmp);
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	static char		save[BUFFSIZE + 1];
	char			buf[BUFFSIZE + 1];
	int				ret;

	*line = ft_strdup("");
	if ((ret = check_endl(save)) != -1)
		return (get_next_line2(save, line, ret));
	ft_strdel(line);
	*line = ft_strdup(save);
	ft_strclr(save);
	while ((ret = read(fd, buf, BUFFSIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((ret = check_endl(buf)) != -1)
		{
			ft_strcpy(save, buf);
			return (get_next_line2(save, line, ret));
		}
		if ((*line = ft_realloc(*line, BUFFSIZE)) == NULL)
			return (-1);
		*line = ft_strcat(*line, buf);
	}
	if (ft_strlen(*line))
		ret = 1;
	return (ret);
}
