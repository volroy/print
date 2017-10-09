/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 23:29:51 by yorlov            #+#    #+#             */
/*   Updated: 2017/10/04 23:29:53 by yorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

// void	cast_var(t_flag *f, va_list *ap)
// {
// 	f->data = 0;
// 	if (f->f_tab[12] == 1)
// 		f->data = (intmax_t)(va_arg(*ap, ssize_t));
// 	else if (f->f_tab[11] == 1)
// 		f->data = (va_arg(*ap, intmax_t));
// 	else if (f->f_tab[9] == 1)
// 		f->data = (intmax_t)(va_arg(*ap, long long));
// 	else if (f->f_tab[10] == 1)
// 		f->data = (intmax_t)(va_arg(*ap, long));
// 	else if (f->f_tab[8] == 1)
// 		f->data = (intmax_t)((short)va_arg(*ap, int));
// 	else if (f->f_tab[7] == 1)
// 		f->data = (intmax_t)((char)va_arg(*ap, int));
// 	else if (f->f_tab[13] == 'D')
// 		f->data = (intmax_t)(va_arg(*ap, long));
// 	else if (f->f_tab[13] == 'd' || f->f_tab[13] == 'i')
// 		f->data = (intmax_t)(va_arg(*ap, int));
// 	ft_sign(f);
// 	// return (f->data);
// }

char	*cast_i(t_flag *f, va_list *ap)
{
	if (f->f_tab[12] == 1)
		f->data = (intmax_t)(va_arg(*ap, ssize_t));
	else if (f->f_tab[11] == 1)
		f->data = (va_arg(*ap, intmax_t));
	else if (f->f_tab[9] == 1)
		f->data = (intmax_t)(va_arg(*ap, long long));
	else if (f->f_tab[10] == 1)
		f->data = (intmax_t)(va_arg(*ap, long));
	else if (f->f_tab[8] == 1)
	{
		// printf("here\n");
		f->data = (intmax_t)((short)va_arg(*ap, int));
		// printf("%jd\n", f->data);
	}
	else if (f->f_tab[7] == 1)
		f->data = (intmax_t)((char)va_arg(*ap, int));
	// else if (f->spe == 'D')
	// 	data = (intmax_t)(va_arg(*ap, long));
	else if (f->f_tab[13] == 'd' || f->f_tab[13] == 'i')
		f->data = (intmax_t)(va_arg(*ap, int));
	f->data_max = pf_ft_sign(f, f->data);
	return (ft_itoa_base(f->data_max, 10));
}

char			*cast_x(t_flag *f, va_list *ap)
{
	if (f->f_tab[12] == 1)
		f->data = (uintmax_t)va_arg(*ap, size_t);
	else if (f->f_tab[11] == 1)
		f->data = va_arg(*ap, uintmax_t);
	else if (f->f_tab[9] == 1)
		f->data = (uintmax_t)va_arg(*ap, unsigned long long);
	else if (f->f_tab[10] == 1)
		f->data = (uintmax_t)va_arg(*ap, unsigned long);
	else if (f->f_tab[8] == 1)
		f->data = (uintmax_t)(unsigned short)va_arg(*ap, unsigned int);
	else if (f->f_tab[7] == 1)
		f->data = (uintmax_t)(unsigned char)va_arg(*ap, unsigned int);
	else
		f->data = (uintmax_t)va_arg(*ap, unsigned int);
	return (ft_itoa_base(f->data, 16));
	// return (NULL);
}

char		*cast_o(t_flag *f, va_list *ap)
{
	if (f->f_tab[12] == 1)
		f->data = (uintmax_t)va_arg(*ap, size_t);
	else if (f->f_tab[11] == 1)
		f->data = va_arg(*ap, uintmax_t);
	else if (f->f_tab[9] == 1)
		f->data = (uintmax_t)va_arg(*ap, unsigned long long);
	else if (f->f_tab[10] == 1)
		f->data = (uintmax_t)va_arg(*ap, unsigned long);
	else if (f->f_tab[8] == 1)
		f->data = (uintmax_t)(unsigned short)va_arg(*ap, unsigned int);
	else if (f->f_tab[7] == 1)
		f->data = (uintmax_t)(unsigned char)va_arg(*ap, unsigned int);
	else
		f->data = (uintmax_t)va_arg(*ap, unsigned int);
	if (f->f_tab[13] == 'u')
		return (ft_itoa_base(f->data, 10));
	if (f->f_tab[13] == 'o')
		return (ft_itoa_base(f->data, 8));
	return (NULL);
}

// uintmax_t	ft_u_cast(t_printlist *buffer, va_list arguments)
// {
// 	uintmax_t	num;

// 	num = va_arg(arguments, intmax_t);
// 	if (buffer->specificator == 1)
// 		num = (size_t)num;
// 	else if (buffer->specificator == 2)
// 		num = (uintmax_t)num;
// 	else if (buffer->specificator == 3)
// 		num = (unsigned long long int)num;
// 	else if (buffer->specificator == 4 || buffer->convertion_type == 'U'
// 										  || buffer->convertion_type == 'O')
// 		num = (unsigned long int)num;
// 	else if (buffer->specificator == 5)
// 		num = (unsigned short int)num;
// 	else if (buffer->specificator == 6)
// 		num = (unsigned char)num;
// 	else
// 		num = (unsigned int)num;
// 	return (num);
// }
