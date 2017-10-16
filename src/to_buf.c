/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_buf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 02:45:06 by yorlov            #+#    #+#             */
/*   Updated: 2017/10/10 02:45:07 by yorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void				print_it(t_flag *f)
{
	f->res = f->res + write(1, g_buffer, g_buffer_counter);
	init_buf();
}

void				null_exception(t_flag *f)
{
	static char		str[6];
	int				i;

	i = -1;
	str[0] = '(';
	str[1] = 'n';
	str[2] = 'u';
	str[3] = 'l';
	str[4] = 'l';
	str[5] = ')';
	while (str[++i] != '\0')
		to_buf(str[i], f);
}

int					to_buf(char c, t_flag *f)
{
	g_buffer[g_buffer_counter] = c;
	g_buffer_counter++;
	if (g_buffer_counter == 2048)
		print_it(f);
	return (1);
}

void				costyl(t_flag *f, va_list *ap)
{
	char			c;
	char			s[2];

	c = (char)va_arg(*ap, int);
	if (c == 0 && f->f_tab[0] == -1)
		f->f_tab[0] = 0;
	s[0] = c;
	s[1] = '\0';
	f->arg = s;
	handle_char(f);
}
