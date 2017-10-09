/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 17:20:23 by yorlov            #+#    #+#             */
/*   Updated: 2017/09/29 17:20:25 by yorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdio.h>

int	check_format(t_flag *f)
{
	f->index = 0;
	// printf("%s\n", f->format);
	while (f->format[f->index] == '-' || f->format[f->index] == '+' ||
		f->format[f->index] == ' ' || f->format[f->index] == '#' ||
		f->format[f->index] == '.' ||
		(f->format[f->index] >= '0' && f->format[f->index] <= '9') ||
		(f->format[f->index] == 'h' || f->format[f->index] == 'l' ||
		f->format[f->index] == 'j' || f->format[f->index] == 'z'))
	{
		check_flag(f);
		check_width(f);
		check_precision(f);
		check_modif(f);
		// printf("[%c]\n", f->format[f->index]);
	}
	check_convercions(f);
	// if ()
	// printf("[%c]\n", f->format[f->index]);
	if (some_1(f))
	{
		ft_bzero(f->buf, ft_strlen(f->buf));
		return (1);
	}
	return (0);
}

int		check_flag(t_flag *f)
{
	if (f->format[f->index] == '-')
		f->f_tab[0] = 1;
	else if (f->format[f->index] == '+')
		f->f_tab[1] = 1;
	else if (f->format[f->index] == ' ')
		f->f_tab[2] = 1;
	else if (f->format[f->index] == '#')
		f->f_tab[3] = 1;
	else if (f->format[f->index] == '0')
		f->f_tab[4] = 1;
	if (f->format[f->index] == '-' || f->format[f->index] == '+' 
		|| f->format[f->index] == ' ' || f->format[f->index] == '#'
		|| f->format[f->index] == '0')
		f->index++;
	return (0);
}

void	check_width(t_flag *f)
{
	int		i;

	i = f->index;
	if (f->format[f->index] >= '1' && f->format[f->index] <= '9')
	{
		while (f->format[f->index] >= '0' && f->format[f->index] <= '9')
			f->index++;
		if (f->index > i)
			f->f_tab[5] = ft_atoi(f->format, i);
	}
}

void	check_precision(t_flag *f)
{
	int		i;

	if (f->format[f->index] != '.')
	{
		f->dot = 1;
		f->f_tab[6] = -1;
		return ;
	}
	i = f->index + 1;
	f->index++;
	while (f->format[f->index] >= '0' && f->format[f->index] <= '9')
		f->index++;
	if (f->index > i)
		f->f_tab[6] = ft_atoi(f->format, i);
	else
		f->f_tab[6] = 0;
}

void		check_modif(t_flag *f)
{
	while (f->format[f->index] == 'h' || f->format[f->index] == 'l' ||
		f->format[f->index] == 'j' || f->format[f->index] == 'z')
	{
		if (f->format[f->index] == 'h' && f->format[f->index + 1] == 'h')
		{
			f->index++;
			f->f_tab[7] = 1;
		}
		else if (f->format[f->index] == 'h')
			f->f_tab[8] = 1;
		if (f->format[f->index] == 'l' && f->format[f->index + 1] == 'l' && f->index++)
			f->f_tab[9] = 1;
		else if (f->format[f->index] == 'l')
			f->f_tab[10] = 1;
		if (f->format[f->index] == 'j')
			f->f_tab[11] = 1;
		if (f->format[f->index] == 'z')
			f->f_tab[12] = 1;
		f->index++;
	}
}
