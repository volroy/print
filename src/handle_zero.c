/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 14:25:14 by yorlov            #+#    #+#             */
/*   Updated: 2017/10/08 14:25:16 by yorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		handle_zero(t_flag *f)
{
	if (f->f_tab[5] < 1 && f->f_tab[6] < 1)
		return (0);
	else if (f->f_tab[5] < 1 && f->f_tab[6] >= 1)
		print_c_times(f, '0', f->f_tab[6]);
	else if (f->f_tab[5] >= 1 && f->f_tab[6] < 1)
	{
		
		print_c_times(f, ' ', f->f_tab[5]);
	}
	else if (f->f_tab[5] >= 1 && f->f_tab[6] >= 1)
	{
		if (f->f_tab[0] == 1 && print_c_times(f, '0', f->f_tab[6]))
			print_c_times(f, ' ', f->f_tab[5] - f->f_tab[6]);
		else if (print_c_times(f, ' ', f->f_tab[5] - f->f_tab[6]))
			print_c_times(f, '0', f->f_tab[6]);
	}
	return (0);
}

int		handle_zero_o(t_flag *f)
{
	int		k;

	if (f->f_tab[5] < 1 && f->f_tab[6] == -1)
		to_buf(f, f->arg);
	else if (f->f_tab[5] < 1 && f->f_tab[6] < 1)
		k = (f->f_tab[3] == 1 ? to_buf(f, f->arg) : 1);	
	else if (f->f_tab[5] < 1 && f->f_tab[6] >= 1)
		print_c_times(f, '0', f->f_tab[6]);
	else if (f->f_tab[5] >= 1 && f->f_tab[6] < 1)
		print_c_times(f, ' ', f->f_tab[5]);
	else if (f->f_tab[5] >= 1 && f->f_tab[6] >= 1)
	{
		if (f->f_tab[0] == 1 && print_c_times(f, '0', f->f_tab[6]))
			print_c_times(f, ' ', f->f_tab[5] - f->f_tab[6]);
		else if (print_c_times(f, ' ', f->f_tab[5] - f->f_tab[6]))
			print_c_times(f, '0', f->f_tab[6]);
	}
	return (0);
}

int		handle_zero_x(t_flag *f)
{
	if (f->f_tab[5] < 1 && f->f_tab[6] < 0)
		print_c_times(f, '0', 1);
	else if (f->f_tab[5] < 1 && f->f_tab[6] < 1)
		;
	else if (f->f_tab[5] >= 1 && f->f_tab[6] < 1)
		print_c_times(f, ' ', f->f_tab[5]);
	else if (f->f_tab[5] >= 1 && f->f_tab[6] >= 1)
	{
		if (f->f_tab[0] == 1 && print_c_times(f, '0', f->f_tab[6]))
			print_c_times(f, ' ', f->f_tab[5] - f->f_tab[6]);
		else if (print_c_times(f, ' ', f->f_tab[5] - f->f_tab[6]))
			print_c_times(f, '0', f->f_tab[6]);
	}
	return (0);
}
