/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 22:13:18 by yorlov            #+#    #+#             */
/*   Updated: 2017/09/27 22:13:19 by yorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int	i;

	i = 0;
	// printf("heres\n");
	ft_printf("{%0-3d}", 0);
	printf("\n");
	// printf("{%0-3d}", 0);
	printf("\n");
	return (0);
}	