/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 17:42:47 by yorlov            #+#    #+#             */
/*   Updated: 2017/09/30 17:42:49 by yorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

void	dispatcher(t_flag *f, va_list *ap)
{
	if (f->f_tab[13] == 's')
		handle_s(f, ap);
	// // else if (f->f_tab[13] == 'S')
	// // 	handle_S(f, ap);
	// else if (f->f_tab[13] == 'p')
	// 	handle_p(f, ap);
	else if (f->f_tab[13] == 'd')
		handle_i(f, ap);
	// // else if (f->f_tab[13] == 'D')
	// // 	handle_D(f, ap);
	else if (f->f_tab[13] =='i')
		handle_i(f, ap);
	else if (f->f_tab[13] == 'o')
		handle_o(f, ap);
	// // else if (f->f_tab[13] == 'O')
	// // 	handle_O(f, ap);
	else if (f->f_tab[13] == 'u')
		handle_u(f, ap);
	else if (f->f_tab[13] == 'U')
		handle_u(f, ap);
	else
		dispatcher2(f, ap);

}

void	dispatcher2(t_flag *f, va_list *ap)
{
	if (f->f_tab[13] == 'x' || f->f_tab[13] == 'X')
	{
		f->hex[1] = 'X';
		if (f->f_tab[13] == 'x')
			f->hex[1] = 'x';
		handle_Xx(f, ap);
	}
	/*else */if (f->f_tab[13] == 'c')
		handle_c(f, ap);
// // 	else if (f->f_tab[13] == 'C')
// // 		handle_C(f, ap);
	else if (f->f_tab[13] == '%')
		handle_percentage(f);
	// else if (f->f_tab[13] == 0)
	// 	handle_undef(f, ap);
}
