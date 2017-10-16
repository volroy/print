/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_c_C_s_S.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 02:45:50 by yorlov            #+#    #+#             */
/*   Updated: 2017/10/12 02:45:52 by yorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int			handle_c(t_flag *f, va_list *ap)
{
	int		mask[13];
	int		i;

	i = -1;
	while (++i < 13)
		mask[i] = 2;
	mask[0] = 1;
	mask[1] = 1;
	mask[3] = 1;
	mask[4] = 1;
	mask[10] = 1;
	not_elon_but_musk(f, mask);
	if (f->f_tab[10] == 1 || f->spe == 'C')
		return (cast_lc(f, ap));
	else
		costyl(f, ap);
	if (f->arg[0] == 0)
		to_buf('\0', f);
	return (0);
}

// int			handle_lc(t_flag *f, va_list *ap)
// {
// 	// int		mask[13];
// 	// int		i;

// 	// i = -1;
// 	// while (++i < 13)
// 	// 	mask[i] = 2;
// 	// mask[0] = 1;
// 	// mask[1] = 1;
// 	// mask[3] = 1;
// 	// mask[4] = 1;
// 	// not_elon_but_musk(f, mask);
// 	// return (cast_lc(f, ap));
// }

int			handle_s(t_flag *f, va_list *ap)
{
	int		mask[13];
	int		i;

	i = -1;
	while (++i < 13)
		mask[i] = 2;
	mask[0] = 1;
	mask[1] = 1;
	mask[3] = 1;
	mask[4] = 1;
	mask[10] = 1;
	not_elon_but_musk(f, mask);
	if (f->f_tab[10] == 1)
	{
		f->warg = va_arg(*ap, wchar_t*);
		handle_char(f);
		return (0);
	}
	else
		f->arg = va_arg(*ap, char*);
	if (f->arg == 0)
		f->arg = "(null)";
	handle_char(f);
	return (0);
}

int			handle_ls(t_flag *f, va_list *ap)
{
	int		mask[13];
	int		i;

	i = -1;
	while (++i < 13)
		mask[i] = 2;
	mask[0] = 1;
	mask[1] = 1;
	mask[3] = 1;
	mask[4] = 1;
	not_elon_but_musk(f, mask);
	f->warg = va_arg(*ap, wchar_t*);
	handle_char(f);
	return (0);
}
