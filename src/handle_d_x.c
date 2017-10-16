/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d_D_x_X.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 02:45:58 by yorlov            #+#    #+#             */
/*   Updated: 2017/10/12 02:46:01 by yorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int			handle_d(t_flag *f, va_list *ap)
{
	int		mask[13];
	int		i;

	i = -1;
	while (++i < 13)
		mask[i] = 1;
	mask[2] = 2;
	not_elon_but_musk(f, mask);
	f->arg = cast_d(f, ap);
	handle_num(f);
	return (0);
}

int			handle_ld(t_flag *f, va_list *ap)
{
	int		mask[13];
	int		i;

	i = -1;
	while (++i < 13)
		mask[i] = 1;
	mask[2] = 2;
	mask[7] = 2;
	mask[8] = 2;
	mask[10] = 2;
	not_elon_but_musk(f, mask);
	f->arg = cast_d(f, ap);
	handle_num(f);
	return (0);
}

int			handle_lx(t_flag *f, va_list *ap)
{
	int		mask[13];
	int		i;

	i = -1;
	while (++i < 13)
		mask[i] = 1;
	not_elon_but_musk(f, mask);
	f->arg = cast_x(f, ap);
	if (f->f_tab[0] == -1 && f->arg[0] != '0' && f->f_tab[2] == 1)
		f->f_tab[0] = 0;
	handle_num(f);
	return (0);
}

int			handle_x(t_flag *f, va_list *ap)
{
	int		mask[13];
	int		i;

	i = -1;
	while (++i < 13)
		mask[i] = 1;
	not_elon_but_musk(f, mask);
	f->arg = cast_x(f, ap);
	if (f->f_tab[0] == -1 && f->arg[0] != '0' && f->f_tab[2] == 1)
		f->f_tab[0] = 0;
	handle_num(f);
	return (0);
}
