/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 02:46:00 by yorlov            #+#    #+#             */
/*   Updated: 2017/10/10 02:46:02 by yorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		handle_definitely_char(t_flag *f, int i)
{
	size_t	len;

	if ((i = -1) && ((f->spe == 's' && f->f_tab[10] == 1) || f->spe == 'S' ||
		(f->spe == 'c' && f->f_tab[10] == 1) || f->spe == 'C'))
	{
		if (f->arg != NULL)
		{
			if (f->arg[0] == '\0' && (f->spe == 'C' ||
				(f->spe == 'c' && f->f_tab[10] == 1)))
				to_buf('\0', f);
			len = ft_strlen(f->arg);
			while (len-- > 0)
				to_buf(f->arg[++i], f);
		}
		else if (f->f_tab[0] != -1)
			null_exception(f);
	}
	else
	{
		while (f->arg[++i] != '\0')
			to_buf(f->arg[i], f);
	}
	ft_end(f);
}

void		handle_char_right_side(t_flag *f)
{
	int		nb_space;

	nb_space = f->f_tab[1] - ft_strlen(f->arg);
	if ((f->spe == 'c' && f->arg[0] == 0) || (f->spe == 'C' && f->arg[0] == 0))
		nb_space--;
	while (nb_space-- > 0)
	{
		if (f->f_tab[3] == 1 && f->f_tab[0] <= 0)
			to_buf('0', f);
		else
			to_buf(' ', f);
	}
	handle_definitely_char(f, -1);
}

void		handle_char_left_side(t_flag *f)
{
	int		nb_space;

	nb_space = f->f_tab[1] - ft_strlen(f->arg);
	if ((f->spe == 'c' && f->arg[0] == 0) || (f->spe == 'C' && f->arg[0] == 0))
		nb_space--;
	handle_definitely_char(f, -1);
	while (nb_space-- > 0)
		to_buf(' ', f);
}

void		handle_char_width(t_flag *f)
{
	int		i;

	i = 0;
	if (f->arg)
		i = ft_strlen(f->arg);
	if (i < f->f_tab[1])
	{
		if (f->f_tab[4] == 1)
			handle_char_left_side(f);
		else
			handle_char_right_side(f);
	}
	else
		handle_definitely_char(f, -1);
}
