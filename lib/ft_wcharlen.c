/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 04:24:01 by yorlov            #+#    #+#             */
/*   Updated: 2017/10/16 04:24:03 by yorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int			longchar_len(wchar_t wchar)
{
	if (wchar <= 127)
		return (1);
	else if (wchar <= 2047)
		return (2);
	else if (wchar <= 65535)
		return (3);
	else
		return (4);
}
