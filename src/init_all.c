/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 04:39:31 by yorlov            #+#    #+#             */
/*   Updated: 2017/10/16 04:39:34 by yorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		init_f_tab(t_flag *f)
{
	int		i;

	i = -1;
	while (++i < 14)
		f->f_tab[i] = 0;
	f->index = 0;
	f->arg = 0;
	f->warg = 0;
}

void		init_specificator(t_specificator *s)
{
	s[0].specificator = 's';
	s[1].specificator = 'S';
	s[2].specificator = 'c';
	s[3].specificator = 'C';
	s[4].specificator = 'd';
	s[5].specificator = 'D';
	s[6].specificator = 'i';
	s[7].specificator = 'o';
	s[8].specificator = 'O';
	s[9].specificator = 'u';
	s[10].specificator = 'U';
	s[11].specificator = 'x';
	s[12].specificator = 'X';
	s[13].specificator = 'p';
	s[14].specificator = 0;
}

void		init_specificator_tail(t_specificator *s)
{
	s[0].ptr = handle_s;
	s[1].ptr = handle_ls;
	s[2].ptr = handle_c;
	s[3].ptr = handle_c;
	s[4].ptr = handle_d;
	s[5].ptr = handle_ld;
	s[6].ptr = handle_d;
	s[7].ptr = handle_o;
	s[8].ptr = handle_lo;
	s[9].ptr = handle_u;
	s[10].ptr = handle_lu;
	s[11].ptr = handle_x;
	s[12].ptr = handle_lx;
	s[13].ptr = handle_p;
	s[14].ptr = NULL;
}

void		init_buf(void)
{
	int		n;

	n = -1;
	while (++n < 2048)
		g_buffer[n] = '\0';
	g_buffer_counter = 0;
}

void		not_elon_but_musk(t_flag *f, int *mask)
{
	int		i;

	i = 1;
	while (++i < 14)
		f->f_tab[i] = f->f_tab[i] * mask[i];
}
