/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 04:24:42 by yorlov            #+#    #+#             */
/*   Updated: 2017/10/16 04:24:45 by yorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

size_t		byte_len(wchar_t *ws)
{
	size_t	len;
	size_t	bytelen;

	len = longstr_len(ws);
	bytelen = 0;
	while (len-- > 0)
		bytelen = bytelen + longchar_len(*(ws++));
	return (bytelen);
}

size_t		longstr_len(wchar_t *ws)
{
	size_t	len;

	len = 0;
	if (!ws)
		return (0);
	while (*(ws++))
		len++;
	return (len);
}
