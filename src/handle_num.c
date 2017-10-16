/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_numb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 02:46:12 by yorlov            #+#    #+#             */
/*   Updated: 2017/10/10 02:46:14 by yorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	handle_num_precision_without_width(t_flag *f)
{
	int	i;
	int	prec;

	handle_prefics(f);
	prec = f->f_tab[0] - ft_strlen(f->arg);
	i = -1;
	if (f->f_tab[0] > f->f_tab[1] + ft_strlen(f->arg))
	{
		while (++i < prec)
			to_buf('0', f);
	}
}

void	handle_num_filler(t_flag *f, int num_spaces)
{
	int	precis;

	precis = ft_strlen(f->arg);
	if (f->sign == '-' || f->f_tab[5] == 1 || f->f_tab[6] == 1 ||
		(f->f_tab[2] == 1 &&
		f->f_tab[0] <= precis && (f->spe == 'o' || f->spe == 'O')))
		num_spaces--;
	if (f->f_tab[2] == 1 && (f->spe == 'x' || f->spe == 'X' || f->spe == 'p'))
		num_spaces = num_spaces - 2;
	while (f->f_tab[0] > precis++)
		num_spaces--;
	if (f->f_tab[0] < f->f_tab[1] + ft_strlen(f->arg))
	{
		while (num_spaces-- > 0)
			precis = ((f->f_tab[3] == 1 && f->f_tab[0] == 0)
				? to_buf('0', f) : to_buf(' ', f));
	}
}

void	handle_num_right_side(t_flag *f)
{
	int		i;
	int		len;
	int		num_spaces;

	len = ft_strlen(f->arg);
	num_spaces = f->f_tab[1] - len;
	if (f->f_tab[3] != 1)
	{
		handle_num_filler(f, num_spaces);
		handle_prefics(f);
	}
	else
	{
		handle_prefics(f);
		handle_num_filler(f, num_spaces);
	}
	i = -1;
	while (f->f_tab[0] > len++)
		to_buf('0', f);
	while (f->arg[++i] != '\0')
		to_buf(f->arg[i], f);
}

void	handle_num_left_side(t_flag *f)
{
	int		i;
	int		precis;
	int		num_spaces;

	i = -1;
	f->f_tab[3] = 0;
	handle_prefics(f);
	precis = ft_strlen(f->arg);
	while (f->f_tab[0] > precis++)
		to_buf('0', f);
	while (f->arg[++i] != '\0')
		to_buf(f->arg[i], f);
	num_spaces = f->f_tab[1] - ft_strlen(f->arg);
	handle_num_filler(f, num_spaces);
}

void	handle_num_width(t_flag *f)
{
	int	i;
	int	length;

	i = -1;
	length = ft_strlen(f->arg);
	if (f->f_tab[1] > length && f->f_tab[4] == 1)
		handle_num_left_side(f);
	else if (f->f_tab[1] > length)
		handle_num_right_side(f);
	else
	{
		handle_prefics(f);
		while (f->f_tab[0] > length++)
			to_buf('0', f);
		while (f->arg[++i] != '\0')
			to_buf(f->arg[i], f);
	}
}
