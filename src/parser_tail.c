/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tail.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 15:20:01 by yorlov            #+#    #+#             */
/*   Updated: 2017/09/30 15:20:03 by yorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdio.h>

void	check_convercions(t_flag *f)
{
	if (f->format[f->index] == 's')
		f->f_tab[13] = 's';
	else if (f->format[f->index] == 'S')
		f->f_tab[13] = 'S';
	else if (f->format[f->index] == 'p')
		f->f_tab[13] = 'p';
	else if (f->format[f->index] == 'd')
		f->f_tab[13] = 'd';
	else if (f->format[f->index] == 'D')
		f->f_tab[13] = 'D';
	else if (f->format[f->index] == 'i')
		f->f_tab[13] = 'i';
	else if (f->format[f->index] == 'o')
		f->f_tab[13] = 'o';
	else if (f->format[f->index] == 'O')
		f->f_tab[13] = 'O';
	else if (f->format[f->index] == 'u')
		f->f_tab[13] = 'u';
	else if (f->format[f->index] == 'U')
		f->f_tab[13] = 'U';
	else
		check_convercions_2(f);
}

void	check_convercions_2(t_flag *f)
{
	if (f->format[f->index] == 'x')
		f->f_tab[13] = 'x';
	else if (f->format[f->index] == 'X')
		f->f_tab[13] = 'X';
	else if (f->format[f->index] == 'c')
		f->f_tab[13] = 'c';
	else if (f->format[f->index] == 'C')
		f->f_tab[13] = 'C';
	else if (f->format[f->index] == '%')
		f->f_tab[13] = '%';
	else
		f->f_tab[13] = 0;
	f->index++;
}
