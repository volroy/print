/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 21:59:29 by yorlov            #+#    #+#             */
/*   Updated: 2017/10/01 21:59:31 by yorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int		handle_i(t_flag *f, va_list *ap)
{
	f->arg = cast_i(f, ap);

	// printf("%c\n", f->sign);
	// if (f->data == 0 && f->dot == 1)
	// 	f->arg = "";
	if (f->data == 0 && f->f_tab[1] == 0 && f->f_tab[2] == 0 && f->f_tab[12] != 1)
		handle_zero(f);
	else if (f->f_tab[5] <= ft_strlen(f->arg) && f->f_tab[6] <= ft_strlen(f->arg))
		i_without_width_and_precision(f);
	else if (f->f_tab[5] > ft_strlen(f->arg) && f->f_tab[6] <= ft_strlen(f->arg))
		i_with_width(f, f->f_tab[5] - ft_strlen(f->arg));
	else if (f->f_tab[5] <= ft_strlen(f->arg) && f->f_tab[6] > ft_strlen(f->arg))
		i_with_precision(f, f->f_tab[6] - ft_strlen(f->arg));
	else if (f->f_tab[5] > ft_strlen(f->arg) && f->f_tab[6] > ft_strlen(f->arg))
		i_width_and_precision(f, f->f_tab[6] - ft_strlen(f->arg));
	// pf_ft_handler_numb(f);
	// printf("here - %li\n", f->data);
	return (0);
}

void	i_without_width_and_precision(t_flag *f)
{
	if (f->f_tab[1] == 1 && (f->sign == '+' ? print_c_times(f, '+', 1) : print_c_times(f, '-', 1)))
		to_buf(f, f->arg);
	else if (f->f_tab[2] == 1 && (f->sign == '+' ? print_c_times(f, ' ', 1) : print_c_times(f, '-', 1)))
		to_buf(f, f->arg);
	else
	{
		if (f->sign == '-' && print_c_times(f, '-', 1))
			to_buf(f, f->arg);
		else
			to_buf(f, f->arg);
	}
}

void	i_with_width(t_flag *f, int i)
{
	int		k;

	k = 0;
	if (f->f_tab[0] == 1 && (f->f_tab[1] == 1 || f->f_tab[2] == 1))
	{
		f->s_or_p = (f->f_tab[1] == 1 ? '+' : ' ');
		k = (f->sign == '+' ? print_c_times(f, f->s_or_p, 1) : print_c_times(f, '-', 1));
		to_buf(f, f->arg);
		print_c_times(f, ' ', i - 1);
	}
	else if (f->f_tab[0] == 1)
	{
		if (f->sign == '+' && to_buf(f, f->arg))
			print_c_times(f, ' ', i);
		else if (print_c_times(f, '-', 1) && to_buf(f, f->arg))
			print_c_times(f, ' ', i - 1);
	}
	else if (f->f_tab[4] == 1 && (f->f_tab[1] == 1 || f->f_tab[2] == 1))
	{
		f->s_or_p = (f->f_tab[1] == 1 ? '+' : ' ');
		k = (f->sign == '+' ? print_c_times(f, f->s_or_p, 1) : print_c_times(f, '-', 1));
		print_c_times(f, '0', i - 1);
		to_buf(f, f->arg);
	}
	else
		i_with_width_tail(f, k, i);
}

void	i_with_width_tail(t_flag *f, int k, int i)
{
	if (f->f_tab[4] == 1)
	{
		if (f->sign == '+' && print_c_times(f, '0', i))
			to_buf(f, f->arg);
		else if (print_c_times(f, '-', 1) && print_c_times(f, '0', i - 1))
			to_buf(f, f->arg);
	}
	else if (f->f_tab[1] == 1 || f->f_tab[2] == 1)
	{
		print_c_times(f, ' ', i - 1);
		f->s_or_p = (f->f_tab[1] == 1 ? '+' : ' ');
		k = (f->sign == '+' ? print_c_times(f, f->s_or_p, 1) : print_c_times(f, '-', 1));
		to_buf(f, f->arg);
	}
	else
	{
		k = (f->sign == '+' ? print_c_times(f, ' ', i) : (print_c_times(f, ' ', i - 1) && print_c_times(f, '-', 1)));
		to_buf(f, f->arg);
	}
}

void 	i_with_precision(t_flag *f, int i)
{
	int		k;

	k = 0;
	if (f->f_tab[1] == 1 || f->f_tab[2] == 1)
	{
		f->s_or_p = (f->f_tab[1] == 1 ? '+' : ' ');
		k = (f->sign == '+' ? print_c_times(f, f->s_or_p, 1) : print_c_times(f, '-', 1));
		print_c_times(f, '0', i);
		to_buf(f, f->arg);
	}
	else
	{
		k = (f->sign == '+' ? 1 : print_c_times(f, '-', 1));
		print_c_times(f, '0', i);
		to_buf(f, f->arg);
	}
}

void	i_width_and_precision(t_flag *f, int i)
{
	int		k;

	k = 0;
	if (f->f_tab[6] >= f->f_tab[5])
		i_with_precision(f, i);
	else
	{
		if (f->f_tab[0] == 1 && (f->f_tab[1] == 1 || f->f_tab[2] == 1))
		{
			f->s_or_p = (f->f_tab[1] == 1 ? '+' : ' ');
			k = (f->sign == '+' ? print_c_times(f, f->s_or_p, 1) : print_c_times(f, '-', 1));
			print_c_times(f, '0', f->f_tab[6] - ft_strlen(f->arg));
			to_buf(f, f->arg);
			print_c_times(f, ' ', f->f_tab[5] - f->f_tab[6] - 1);
		}
		else if (f->f_tab[0] == 1)
		{
			if (f->sign == '+' && print_c_times(f, '0', f->f_tab[6] - ft_strlen(f->arg)) && to_buf(f, f->arg))
				print_c_times(f, ' ', f->f_tab[5] - f->f_tab[6]);
			else if (print_c_times(f, '-', 1) && print_c_times(f, '0', f->f_tab[6] - ft_strlen(f->arg)) && to_buf(f, f->arg))
				print_c_times(f, ' ', f->f_tab[5] - f->f_tab[6] - 1);
		}
		else if (f->f_tab[4] == 1 && (f->f_tab[1] == 1 || f->f_tab[2] == 1))
		{
			f->s_or_p = (f->f_tab[1] == 1 ? '+' : ' ');
			k = (f->sign == '+' ? print_c_times(f, f->s_or_p, 1) : print_c_times(f, '-', 1));
			print_c_times(f, '0', f->f_tab[6] - 1);
			to_buf(f, f->arg);
		}
		else
			i_width_and_precision_tail(f, k, i);
	}
}

void	i_width_and_precision_tail(t_flag *f, int k, int i)
{
	(void)i;
	if (f->f_tab[4] == 1)
	{
		if (f->sign == '+' && print_c_times(f, ' ', f->f_tab[5] - f->f_tab[6]) && print_c_times(f, '0', f->f_tab[6] - ft_strlen(f->arg)))
			to_buf(f, f->arg);
		else
		{
			print_c_times(f, ' ', f->f_tab[5] - f->f_tab[6] - 1);
			print_c_times(f, '-', 1);
			print_c_times(f, '0', f->f_tab[6] - ft_strlen(f->arg));
			to_buf(f, f->arg);
		}
	}
	else if (f->f_tab[1] == 1 || f->f_tab[2] == 1)
	{
		print_c_times(f, ' ', f->f_tab[5] - f->f_tab[6] - 1);
		f->s_or_p = (f->f_tab[1] == 1 ? '+' : ' ');
		k = (f->sign == '+' ? print_c_times(f, f->s_or_p, 1) : print_c_times(f, '-', 1));
		print_c_times(f, '0', f->f_tab[6] - ft_strlen(f->arg));
		to_buf(f, f->arg);
	}
	else
	{
		print_c_times(f, ' ', f->f_tab[5] - f->f_tab[6] - (f->sign == '-' ? 1 : 0));
		if (f->sign == '-')
			print_c_times(f, '-', 1)/* && print_c_times(f, ' ', f->f_tab[6] - ft_strlen(f->arg) - 1))*/;
		print_c_times(f, '0', f->f_tab[6] - ft_strlen(f->arg));
		to_buf(f, f->arg);
	}
}
