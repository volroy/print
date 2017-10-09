/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 06:36:06 by yorlov            #+#    #+#             */
/*   Updated: 2017/10/07 06:36:07 by yorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int				handle_u(t_flag *f, va_list *ap)
{
	// printf("her\n");
	f->arg = cast_o(f, ap);
	// to_buf(f, f->arg);
	if (f->f_tab[5] <= ft_strlen(f->arg) && f->f_tab[6] <= ft_strlen(f->arg))
		u_without(f);
	else if (f->f_tab[5] > ft_strlen(f->arg) && f->f_tab[6] <= ft_strlen(f->arg))
		u_with_width(f);
	else if (f->f_tab[5] <= ft_strlen(f->arg) && f->f_tab[6] > ft_strlen(f->arg))
		u_with_precision(f);
	else if (f->f_tab[5] > ft_strlen(f->arg) && f->f_tab[6] > ft_strlen(f->arg))
		o_width_and_precision(f);
	// f->buf[ft_strlen(f->arg)] = '\0';
	return (0);
}

void	u_without(t_flag *f)
{
	if (f->arg[0] == '0' && f->f_tab[6] < 1)
		;
	else
		to_buf(f, f->arg);
}

void	u_with_width(t_flag *f)
{
	if (f->f_tab[0] == 1)
	{
		to_buf(f, f->arg);
		print_c_times(f, ' ', f->f_tab[5] - ft_strlen(f->arg));
	}
	else if (f->f_tab[4] == 1)
	{
		print_c_times(f, '0', f->f_tab[5] - ft_strlen(f->arg));
		to_buf(f, f->arg);
	}
	else
	{
		print_c_times(f, ' ', f->f_tab[5] - ft_strlen(f->arg));
		to_buf(f, f->arg);
	}
}

void	u_with_precision(t_flag *f)
{
	print_c_times(f, '0', f->f_tab[6] - ft_strlen(f->arg));
	to_buf(f, f->arg);
}

void	u_width_and_precision(t_flag *f)
{
	int		k;

	if (f->f_tab[6] >= f->f_tab[5])
		o_with_precision(f);
	else if (f->f_tab[0] == 1 && (f->f_tab[3] == 1 ? to_buf(f, "0") : 1))
	{
		print_c_times(f, '0', f->f_tab[6] - ft_strlen(f->arg));
		to_buf(f, f->arg);
		print_c_times(f, ' ', f->f_tab[5] - f->f_tab[6] - (f->f_tab[3] == 1 ? 2 : 0));
	}
	else if (print_c_times(f, ' ', f->f_tab[5] - f->f_tab[6] - (f->f_tab[3] == 1 ? 2 : 0)))
	{
		print_c_times(f, '0', f->f_tab[6] - ft_strlen(f->arg));
		k = (f->f_tab[3] == 1 ? to_buf(f, "0") : 1);
		to_buf(f, f->arg);
	}
}