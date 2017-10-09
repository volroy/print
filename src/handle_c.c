/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 19:37:25 by yorlov            #+#    #+#             */
/*   Updated: 2017/10/01 19:37:27 by yorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int		handle_c(t_flag *f, va_list *ap)
{
	char		s;

	if (f->f_tab[10] == 1)
		return (0);
	else
		s = (char)va_arg(*ap, int);
	if (f->f_tab[5] == 0 || f->f_tab[5] == 1)
	{
		if (s == 0)
		{
			print_c_times(f, '^', 1);
			print_c_times(f, '@', 1);
			f->len--;
			f->index--;
		}
		else
			print_c_times(f, s, 1);
	}
	else if (f->f_tab[5] > 0)
		c_with_width(f, s);
	return (0);
}

void	c_with_width(t_flag *f, char s)
{
	int		i;

	i = f->f_tab[5] - 1;
	if (f->f_tab[0] == 0)
	{
		while (i-- > 0)
			to_buf_c(f, ' ');
		if (s == 0)
		{
			print_c_times(f, '^', 1);
			print_c_times(f, '@', 1);
			f->len--;
			f->index--;
		}
		else
			print_c_times(f, s, 1);
	}
	else
	{
		if (s == 0)
		{
			print_c_times(f, '^', 1);
			print_c_times(f, '@', 1);
			f->len--;
			f->index--;
		}
		else
			print_c_times(f, s, 1);
		while (i-- > 0)
			to_buf_c(f, ' ');
	}
}
