/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:51:49 by yorlov            #+#    #+#             */
/*   Updated: 2017/09/30 21:51:50 by yorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdarg.h>
// #include <stdio.h>
#include <unistd.h>

int		handle_s(t_flag *f, va_list *ap)
{
	if (f->f_tab[10] == 1)
		return (0);
	else
		f->arg = va_arg(*ap, char*);
	if (f->arg == 0)
		f->arg = "(null)";
	if (f->f_tab[5] == 0 && f->f_tab[6] == -1)
		s_without_shift(f);
	if (f->f_tab[5] == 0 && f->f_tab[6] >= 0)
		s_with_precision(f);
	if (f->f_tab[5] > 0 && f->f_tab[6] == -1)
		s_with_width(f);
	if (f->f_tab[5] > 0 && f->f_tab[6] >= 0)
			s_with_width_and_precision(f);
	return (0);
}

void	s_without_shift(t_flag *f)
{
	to_buf(f, f->arg);
}

void	s_with_precision(t_flag *f)
{
	if (f->f_tab[6] >= ft_strlen(f->arg))
		to_buf(f, f->arg);
	else
	{
		f->arg[f->f_tab[6]] = '\0';
		to_buf(f, f->arg);
	}
}

void	s_with_width(t_flag *f)
{
	int		i;

	i = f->f_tab[5] - ft_strlen(f->arg);
	if (f->f_tab[5] <= ft_strlen(f->arg))
		to_buf(f, f->arg);
	else
	{
		if (f->f_tab[0] == 0)
		{
			while (i-- > 0)
				to_buf_c(f, ' ');
			to_buf(f, f->arg);
		}
		else
		{
			to_buf(f, f->arg);
			while (i-- > 0)
				to_buf_c(f, ' ');
		}
	}
}

void	s_with_width_and_precision(t_flag *f)
{
	int		i;
	int		j;

	j = (f->f_tab[6] >= ft_strlen(f->arg) ? ft_strlen(f->arg) : f->f_tab[6]);
	i = f->f_tab[5] - j;
	if (j != ft_strlen(f->arg))
		f->arg[f->f_tab[6]] = '\0';
	if (f->f_tab[0] == 0)
	{
		while (i-- > 0)
			to_buf_c(f, ' ');
		to_buf(f, f->arg);
	}
	else
	{
		to_buf(f, f->arg);
		while (i-- > 0)
			to_buf_c(f, ' ');
	}
}
