/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 02:48:02 by yorlov            #+#    #+#             */
/*   Updated: 2017/10/10 02:48:04 by yorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int			handle_char(t_flag *f)
{
	if (f->f_tab[0] == -1 && (f->spe != 'C' || (f->spe == 'c' &&
		f->f_tab[10] == 1)))
		f->arg = "\0";
	else if (f->f_tab[0] > 0 && (f->spe != 'C' || (f->spe == 'c' &&
		f->f_tab[10] == 1)))
		handle_string_precision(f);
	else if (f->spe == 'S' || (f->spe == 's' && f->f_tab[10] == 1) ||
		f->spe == 'C' || (f->spe == 'c' && f->f_tab[10] == 1))
		f->arg = long_char_to_char(f->warg);
	if (f->f_tab[1] > 0)
		handle_char_width(f);
	if (f->f_tab[1] == 0)
		handle_definitely_char(f, -1);
	return (1);
}

int			handle_num(t_flag *f)
{
	int		i;

	i = -1;
	if (f->arg[0] == '0' && f->f_tab[0] == -1 && !(f->f_tab[2] == 1 &&
		(f->spe == 'o' || f->spe == 'O' || f->spe == 'p')))
		f->arg = "\0";
	if (f->f_tab[1] > 0)
		handle_num_width(f);
	else if (f->f_tab[1] == 0 && f->f_tab[0] > 0)
		handle_num_precision_without_width(f);
	else if (f->f_tab[0] <= 0 && f->f_tab[1] == 0)
		handle_prefics(f);
	while (f->arg[++i] != '\0' && f->f_tab[1] == 0)
		to_buf(f->arg[i], f);
	ft_end(f);
	return (1);
}

void		handle_string_precision(t_flag *f)
{
	if (f->spe == 'S' || (f->spe == 's' && f->f_tab[10] == 1))
		f->arg = ft_wstrsub(f->warg, 0, f->f_tab[0]);
	else if (f->spe == 's')
		f->arg = ft_strsub(f->arg, 0, f->f_tab[0]);
}

void		handle_octothorp(t_flag *f)
{
	int		k;

	if ((f->arg[0] != '0' && f->f_tab[0] != -1) ||
		f->spe == 'p')
	{
		if (f->spe == 'p' || ((f->spe == 'x' || f->spe == 'X')
			&& f->arg[0] != '0'))
		{
			to_buf('0', f);
			k = (f->spe == 'X' ? to_buf('X', f) : to_buf('x', f));
		}
		else if ((f->spe == 'o' || f->spe == 'O') &&
			f->f_tab[0] <= ft_strlen(f->arg))
			to_buf('0', f);
	}
}

void		handle_prefics(t_flag *f)
{
	if (f->sign == '-')
		to_buf('-', f);
	else if ((f->f_tab[5] == 1 || f->f_tab[6] == 1) &&
		(f->spe == 'd' || f->spe == 'D' || f->spe == 'i'))
	{
		if (f->f_tab[6] == 1 && f->f_tab[5] == 0)
			to_buf(' ', f);
		if (f->f_tab[5] == 1)
			to_buf('+', f);
	}
	if (f->f_tab[2] == 1)
		handle_octothorp(f);
}
