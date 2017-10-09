/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 02:15:59 by yorlov            #+#    #+#             */
/*   Updated: 2017/09/27 02:16:02 by yorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "../inc/ft_printf.h"
#include "unistd.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_flag		f;
	int			i;

	va_start(ap, format);
	i = -1;
	init_buf(&f);
	init_all(&f);
	// printf("here\n");
	while (++i < ft_strlen(format))
	{
		if (format[i] == '%')
		{
			f.format = (char*)&format[++i];
			if (check_format(&f))
				break ;
			dispatcher(&f, &ap);
			i = i + f.index;
		}
		else if (format[i] != '\0' && format[i] != '%')
		{
			// printf("%c\n", format[i]);
			to_buf_c(&f, format[i]);
		}
		// printf("[%s] - [%s]\n", f.format, f.buf);
	}
	i = -1;
	printf("%s", f.buf);
	// while (++i < 14)
	// 	printf("[%i]", f.f_tab[i]);
	va_end(ap);
	return (ft_strlen(f.buf) + f.len);
}