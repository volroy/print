/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percentage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 06:58:26 by yorlov            #+#    #+#             */
/*   Updated: 2017/10/07 06:58:27 by yorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int				handle_percentage(t_flag *f)
{
	if (0/*f->f_tab[5] == 0*/)
		to_buf(f, "%");
	else
	{
		if (f->f_tab[0] == 1)
		{
			to_buf(f, "%");
			print_c_times(f, ' ', f->f_tab[5] - 1);
		}
		else
		{
			print_c_times(f, ' ', f->f_tab[5] - 1);
			to_buf(f, "%");
		}
	}
	f->index--;
	return (0);
}

// int				handle_p(t_flag *f)
// {
// 	f->arg = pf_ft_strlwr(pf_ft_itoa_base((uintmax_t)va_arg(*ap, void*), 16));
// 	if (f->fla[6] == -1 && f->arg[0] == '0')
// 	{
// 		pf_ft_buf('0', f);
// 		pf_ft_buf('x', f);
// 	}
// 	else
// 		pf_ft_handler_numb(f);
// 	return (0);
// }