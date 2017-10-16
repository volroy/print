/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p_undef.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 02:46:12 by yorlov            #+#    #+#             */
/*   Updated: 2017/10/12 02:46:14 by yorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int				handle_p(t_flag *f, va_list *ap)
{
	int			mask[13];
	int			i;

	i = -1;
	while (++i < 7)
		mask[i] = 1;
	while (++i < 13)
		mask[i] = 2;
	f->f_tab[2] = 1;
	not_elon_but_musk(f, mask);
	f->arg = ft_strlwr(ft_itoa_base((uintmax_t)va_arg(*ap, void*), 16));
	if (f->f_tab[0] == -1 && f->arg[0] == '0')
	{
		to_buf('0', f);
		to_buf('x', f);
	}
	else
		handle_num(f);
	return (0);
}

int				handle_undef(t_flag *f)
{
	int			mask[13];
	char		c[2];
	int			i;

	i = -1;
	while (++i < 13)
		mask[i] = 2;
	mask[0] = 1;
	mask[1] = 1;
	mask[3] = 1;
	mask[4] = 1;
	mask[10] = 1;
	f->f_tab[0] = 0;
	if (f->spe == 0)
	{
		f->res = 0;
		return (f->res);
	}
	c[0] = f->spe;
	c[1] = '\0';
	f->arg = c;
	not_elon_but_musk(f, mask);
	return (handle_char(f));
}
