/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 22:23:59 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/11/15 00:18:41 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		len;
	int		add;
	va_list	args;

	len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			add = ft_printf_multiverse((char **)&str, args);
			if (add == -1)
				return (-1);
			len += add;
			if (*str)
				str++;
		}
		else
		{
			add = write(1, str++, 1);
			if (add == -1)
				return (-1);
			len += add;
		}
	}
	va_end(args);
	return (len);
}
