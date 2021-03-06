/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qarcher <qarcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 15:18:24 by qarcher           #+#    #+#             */
/*   Updated: 2016/04/13 11:41:05 by qarcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(char *bin, char *e)
{
	ft_putstr_fd("error : ", 2);
	ft_putstr_fd(bin, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(e, 2);
}
