/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 00:08:55 by yorlov            #+#    #+#             */
/*   Updated: 2017/10/12 00:08:56 by yorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char			*cast_d(t_flag *f, va_list *ap)
{
	intmax_t	data;
	uintmax_t	data_max;

	data = 0;
	if (f->f_tab[12] == 1)
		data = (intmax_t)(va_arg(*ap, ssize_t));
	else if (f->f_tab[11] == 1)
		data = (va_arg(*ap, intmax_t));
	else if (f->f_tab[9] == 1)
		data = (intmax_t)(va_arg(*ap, long long));
	else if (f->f_tab[10] == 1)
		data = (intmax_t)(va_arg(*ap, long));
	else if (f->f_tab[8] == 1)
		data = (intmax_t)((short)va_arg(*ap, int));
	else if (f->f_tab[7] == 1)
		data = (intmax_t)((char)va_arg(*ap, int));
	else if (f->spe == 'D')
		data = (intmax_t)(va_arg(*ap, long));
	else if (f->spe == 'd' || f->spe == 'i')
		data = (intmax_t)(va_arg(*ap, int));
	data_max = ft_sign(f, data);
	return (ft_itoa_base(data_max, 10));
}

char			*cast_x(t_flag *f, va_list *ap)
{
	intmax_t	data;

	if (f->f_tab[12] == 1)
		data = (uintmax_t)va_arg(*ap, size_t);
	else if (f->f_tab[11] == 1)
		data = va_arg(*ap, uintmax_t);
	else if (f->f_tab[9] == 1)
		data = (uintmax_t)va_arg(*ap, unsigned long long);
	else if (f->f_tab[10] == 1)
		data = (uintmax_t)va_arg(*ap, unsigned long);
	else if (f->f_tab[8] == 1)
		data = (uintmax_t)(unsigned short)va_arg(*ap, unsigned int);
	else if (f->f_tab[7] == 1)
		data = (uintmax_t)(unsigned char)va_arg(*ap, unsigned int);
	else
		data = (uintmax_t)va_arg(*ap, unsigned int);
	if (f->spe == 'X')
		return (ft_itoa_base(data, 16));
	if (f->spe == 'x')
		return (ft_strlwr(ft_itoa_base(data, 16)));
	return (NULL);
}

char			*cast_u_o(t_flag *f, va_list *ap)
{
	intmax_t	data;

	if (f->f_tab[12] == 1)
		data = (uintmax_t)va_arg(*ap, size_t);
	else if (f->f_tab[11] == 1)
		data = va_arg(*ap, uintmax_t);
	else if (f->f_tab[9] == 1)
		data = (uintmax_t)va_arg(*ap, unsigned long long);
	else if (f->f_tab[10] == 1)
		data = (uintmax_t)va_arg(*ap, unsigned long);
	else if (f->f_tab[8] == 1)
		data = (uintmax_t)(unsigned short)va_arg(*ap, unsigned int);
	else if (f->f_tab[7] == 1)
		data = (uintmax_t)(unsigned char)va_arg(*ap, unsigned int);
	else
		data = (uintmax_t)va_arg(*ap, unsigned int);
	if (f->spe == 'u')
		return (ft_itoa_base(data, 10));
	if (f->spe == 'o')
		return (ft_itoa_base(data, 8));
	return (NULL);
}

char			*cast_lu_lo(t_flag *f, va_list *ap)
{
	intmax_t	data;

	if (f->f_tab[12] == 1)
		data = (uintmax_t)va_arg(*ap, size_t);
	else if (f->f_tab[11] == 1)
		data = va_arg(*ap, uintmax_t);
	else if (f->f_tab[9] == 1)
		data = (uintmax_t)va_arg(*ap, unsigned long long);
	else if (f->f_tab[10] == 1)
		data = (uintmax_t)va_arg(*ap, unsigned long);
	else if (f->f_tab[8] == 1)
		data = (uintmax_t)va_arg(*ap, unsigned int);
	else if (f->f_tab[7] == 1)
		data = (uintmax_t)va_arg(*ap, unsigned int);
	else
		data = (uintmax_t)va_arg(*ap, unsigned long);
	if (f->spe == 'U')
		return (ft_itoa_base(data, 10));
	if (f->spe == 'O')
		return (ft_itoa_base(data, 8));
	return (NULL);
}

int				cast_lc(t_flag *f, va_list *ap)
{
	wchar_t		wc;
	wchar_t		ws[2];

	wc = va_arg(*ap, wchar_t);
	ws[0] = wc;
	ws[1] = '\0';
	f->warg = ws;
	handle_char(f);
	return (0);
}
