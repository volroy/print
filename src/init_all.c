/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 22:27:54 by yorlov            #+#    #+#             */
/*   Updated: 2017/09/29 22:27:56 by yorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdlib.h>

void	init_all(t_flag *f)
{
	init_f_tab(f);
	init_conversions_table(f);
	f->hex = (char*)malloc(sizeof(char) * 3);
	ft_bzero(f->hex, 3);
	f->hex[0] = '0';
	f->len = 0;
}

void	init_f_tab(t_flag *f)
{
	int 	i;

	i = -1;
	while (++i < 14)
		f->f_tab[i] = 0;
	f->f_tab[6] = -1;
}

void	init_conversions_table(t_flag *f)
{
	t_conv	s[2];

	(void)f;
	s[0].ptr = &handle_s;
	// s[1].ptr = &handle_S;
	// s[2].ptr = &handle_p;
	// s[3].ptr = &handle_d;
	// s[4].ptr = &handle_D;
	// s[5].ptr = &handle_i;
	// s[6].ptr = &handle_o;
	// s[7].ptr = &handle_O;
	// s[8].ptr = &handle_u;
	// s[9].ptr = &handle_U;
	// s[10].ptr = &handle_x;
	// s[11].ptr = &handle_X;
	// s[12].ptr = &handle_c;
	// s[13].ptr = &handle_C;
	// s[14].ptr = &handle_undefined;
}
