/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 02:48:12 by yorlov            #+#    #+#             */
/*   Updated: 2017/10/10 02:48:41 by yorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int					ft_printf(const char *format, ...)
{
	int				i;
	va_list			ap;
	t_flag			f;

	i = -1;
	f.res = 0;
	va_start(ap, format);
	init_buf();
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			f.format = (char*)&format[++i];
			if (parser(&f) == -1)
				break ;
			dispatcher(&f, &ap);
			i = i + f.index;
		}
		else if (format[i] != '\0' && format[i] != '%')
			to_buf(format[i], &f);
	}
	if (g_buffer_counter > 0)
		print_it(&f);
	va_end(ap);
	return (f.res);
}

int					dispatcher(t_flag *f, va_list *ap)
{
	t_specificator	s[16];
	int				i;

	init_specificator(s);
	init_specificator_tail(s);
	f->spe = f->format[f->index];
	i = -1;
	while (s[++i].specificator != f->spe && s[i].specificator != 0)
		;
	if (s[i].specificator == 0)
		return (handle_undef(f));
	return (s[i].ptr(f, ap));
}

void				ft_end(t_flag *f)
{
	if (f->f_tab[0] >= 0 && f->arg != NULL && f->arg[0] != '\0' &&
		f->arg[0] != '0')
	{
		if (f->spe == 'x' || f->spe == 'X' || f->spe == 'o' || f->spe == 'O'
			|| f->spe == 'u' || f->spe == 'U' || f->spe == 'd' || f->spe == 'D'
			|| f->spe == 'p' || f->spe == 'S' || f->spe == 'i' || (f->spe == 's'
			&& f->f_tab[0] < ft_strlen(f->arg) && f->f_tab[0] > 0) ||
			f->spe == 'C' || (f->spe == 'c' && f->f_tab[10] == 1))
			free(f->arg);
	}
}
