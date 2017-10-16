/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 20:25:51 by yorlov            #+#    #+#             */
/*   Updated: 2017/10/13 20:25:52 by yorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int			parser(t_flag *f)
{
	int		k;

	k = 0;
	init_f_tab(f);
	while (f->format[f->index] == '-' || f->format[f->index] == '+'
		|| f->format[f->index] == ' ' || f->format[f->index] == '#'
		|| f->format[f->index] == '0' || f->format[f->index] == 'h'
		|| f->format[f->index] == 'l' || f->format[f->index] == 'j'
		|| f->format[f->index] == 'z' || f->format[f->index] == '.'
		|| (f->format[f->index] >= '0' && f->format[f->index] <= '9'))
	{
		parse_flag(f);
		parse_width(f);
		parse_precision(f);
		parse_mod(f);
	}
	if (f->index == ft_strlen(f->format))
		return (-1);
	return (0);
}

void		parse_flag(t_flag *f)
{
	if (f->format[f->index] == '-' || f->format[f->index] == '+'
		|| f->format[f->index] == ' ' || f->format[f->index] == '#'
		|| f->format[f->index] == '0')
	{
		if (f->format[f->index] == '#')
			f->f_tab[2] = 1;
		else if (f->format[f->index] == '0')
			f->f_tab[3] = 1;
		else if (f->format[f->index] == '-')
			f->f_tab[4] = 1;
		else if (f->format[f->index] == '+')
			f->f_tab[5] = 1;
		else if (f->format[f->index] == ' ')
			f->f_tab[6] = 1;
		f->index++;
	}
}

void		parse_precision(t_flag *f)
{
	int		original_index;

	if (f->format[f->index] == '.')
	{
		f->f_tab[0] = 0;
		f->index++;
		original_index = f->index;
		while (f->format[f->index] >= '0' && f->format[f->index] <= '9')
			f->index++;
		if (f->index > original_index)
			f->f_tab[0] = ft_atoi_mod(f->format, &original_index);
		if (f->f_tab[0] == 0)
			f->f_tab[0] = -1;
	}
}

void		parse_width(t_flag *f)
{
	int		original_index;

	original_index = f->index;
	if ((f->format[f->index] >= '0' && f->format[f->index] <= '9')
		&& f->format[f->index] != '0')
	{
		while ((f->format[f->index] >= '0' && f->format[f->index] <= '9'))
			f->index++;
		if (f->index > original_index)
			f->f_tab[1] = ft_atoi_mod(f->format, &original_index);
	}
}

void		parse_mod(t_flag *f)
{
	while (f->format[f->index] == 'h' || f->format[f->index] == 'l' ||
		f->format[f->index] == 'j' || f->format[f->index] == 'z')
	{
		if (f->format[f->index] == 'h' && f->format[f->index + 1] == 'h')
		{
			f->f_tab[7] = 1;
			f->index++;
		}
		else if (f->format[f->index] == 'h')
			f->f_tab[8] = 1;
		else if (f->format[f->index] == 'l' && f->format[f->index + 1] == 'l')
		{
			f->f_tab[9] = 1;
			f->index++;
		}
		else if (f->format[f->index] == 'l')
			f->f_tab[10] = 1;
		else if (f->format[f->index] == 'j')
			f->f_tab[11] = 1;
		else if (f->format[f->index] == 'z')
			f->f_tab[12] = 1;
		f->index++;
	}
}
