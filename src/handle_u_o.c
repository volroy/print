/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u_U_o_O.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 02:46:23 by yorlov            #+#    #+#             */
/*   Updated: 2017/10/12 02:46:25 by yorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int			handle_u(t_flag *f, va_list *ap)
{
	int		mask[13];
	int		i;

	i = -1;
	while (++i < 13)
		mask[i] = 1;
	mask[2] = 2;
	not_elon_but_musk(f, mask);
	f->arg = cast_u_o(f, ap);
	handle_num(f);
	return (0);
}

int			handle_o(t_flag *f, va_list *ap)
{
	int		mask[13];
	int		i;

	i = -1;
	while (++i < 13)
		mask[i] = 1;
	not_elon_but_musk(f, mask);
	f->arg = cast_u_o(f, ap);
	if (f->f_tab[0] == -1 && f->arg[0] != '0' && f->f_tab[2] == 1)
		f->f_tab[0] = 0;
	handle_num(f);
	return (0);
}

int			handle_lu(t_flag *f, va_list *ap)
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
	f->arg = cast_lu_lo(f, ap);
	handle_num(f);
	return (0);
}

int			handle_lo(t_flag *f, va_list *ap)
{
	int		mask[13];
	int		i;

	i = -1;
	while (++i < 13)
		mask[i] = 1;
	not_elon_but_musk(f, mask);
	f->arg = cast_lu_lo(f, ap);
	if (f->f_tab[0] == -1 && f->arg[0] != '0' && f->f_tab[2] == 1)
		f->f_tab[0] = 0;
	handle_num(f);
	return (0);
}
