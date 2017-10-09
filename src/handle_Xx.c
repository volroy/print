/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_Xx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 01:44:54 by yorlov            #+#    #+#             */
/*   Updated: 2017/10/04 01:44:57 by yorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int				handle_Xx(t_flag *f, va_list *ap)
{
	int 	i;
	int 	k;

	f->arg = cast_x(f, ap);
	if (f->f_tab[13] == 'x')
		to_lower(f);
	k = 0;
	i = (f->f_tab[3] == 1 ? (ft_strlen(f->arg) + 2) : ft_strlen(f->arg));
	if (f->data == 0)
		handle_zero_x(f);
	else if (f->f_tab[5] <= i && f->f_tab[6] < i)
		x_without(f);
	else if (f->f_tab[5] > i && f->f_tab[6] <= i)
		x_with_width(f, f->f_tab[5] - i, k);
	else if (f->f_tab[5] <= i && f->f_tab[6] >= i)
		x_with_precision(f, f->f_tab[6] - i, k);
	else if (f->f_tab[5] > i && f->f_tab[6] >= i)
		x_width_and_precision(f, f->f_tab[6] - i, k);
	f->index--;
	return (0);
}

void	x_without(t_flag *f)
{
	int		i;

	i = (f->f_tab[3] == 1 ? ft_strlen(f->arg) + 2 : f->f_tab[3] == 1);
	if (f->f_tab[3] == 1)
		to_buf(f, f->hex);
	// f->arg[i] = '\0';
	to_buf(f, f->arg);
	if (f->f_tab[9] == 1)
		f->buf[i] = '\0';
}

void	x_with_width(t_flag *f, int i, int k)
{
	if (f->f_tab[0] == 1 && (f->f_tab[3] == 1 ? to_buf(f, f->hex) : 1))
	{
		to_buf(f, f->arg);
		print_c_times(f, ' ', i);
	}
	else if (f->f_tab[4] == 1 && (f->f_tab[3] == 1 ? to_buf(f, f->hex) : 1))
	{
		print_c_times(f, '0', i);
		to_buf(f, f->arg);
	}
	else
	{
		print_c_times(f, ' ', f->f_tab[5] - ft_strlen(f->arg) - (f->f_tab[3] == 1 ? 2 : 0));
		k = (f->f_tab[3] == 1 ? to_buf(f, f->hex) : 1);
		// print_c_times(f, '0', f->f_tab[6] - ft_strlen(f->arg));
		to_buf(f, f->arg);
	}
}

void	x_with_precision(t_flag *f, int i, int k)
{
	k = (f->f_tab[3] == 1 ? to_buf(f, f->hex) : 1);
	k = (f->f_tab[3] == 1 ? (i = i + 2) : 1);
	print_c_times(f, '0', i);
	if (f->data != 0)
		to_buf(f, f->arg);
}

void	x_width_and_precision(t_flag *f, int i, int k)
{
	if (f->f_tab[6] >= f->f_tab[5])
		x_with_precision(f, i, k);
	else if (f->f_tab[0] == 1 && (f->f_tab[3] == 1 ? to_buf(f, f->hex) : 1))
	{
		print_c_times(f, '0', f->f_tab[6] - ft_strlen(f->arg));
		to_buf(f, f->arg);
		print_c_times(f, ' ', f->f_tab[5] - f->f_tab[6] - (f->f_tab[3] == 1 ? 2 : 0));
	}
	else if (print_c_times(f, ' ', f->f_tab[5] - f->f_tab[6] - (f->f_tab[3] == 1 ? 2 : 0)))
	{
		print_c_times(f, '0', f->f_tab[6] - ft_strlen(f->arg));
		k = (f->f_tab[3] == 1 ? to_buf(f, f->hex) : 1);
		to_buf(f, f->arg);
	}
}
