/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_wchar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 02:48:19 by yorlov            #+#    #+#             */
/*   Updated: 2017/10/10 02:49:30 by yorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		put_long_char_in_char(wchar_t wchar, char *tmp, int i)
{
	int		size;

	size = longchar_len(wchar);
	if (size == 1)
		tmp[i++] = wchar;
	else if (size == 2)
	{
		tmp[i++] = (wchar >> 6) + 192;
		tmp[i++] = (wchar & 63) + 128;
	}
	else if (size == 3)
	{
		tmp[i++] = (wchar >> 12) + 224;
		tmp[i++] = ((wchar >> 6) & 63) + 128;
		tmp[i++] = (wchar & 63) + 128;
	}
	else
	{
		tmp[i++] = (wchar >> 18) + 240;
		tmp[i++] = ((wchar >> 12) & 63) + 128;
		tmp[i++] = ((wchar >> 6) & 63) + 128;
		tmp[i++] = (wchar & 63) + 128;
	}
	return (i);
}

char	*long_char_to_char(wchar_t *ws)
{
	char	*tmp;
	int		i;
	int		k;
	int		len;

	if (!ws)
		return (0);
	i = 0;
	k = 0;
	len = byte_len(ws);
	tmp = (char*)malloc(sizeof(char) * len);
	tmp[len] = '\0';
	while (ws[k])
		i = put_long_char_in_char(ws[k++], tmp, i);
	return (tmp);
}
