/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 04:24:54 by yorlov            #+#    #+#             */
/*   Updated: 2017/10/16 04:24:55 by yorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char		*ft_wstrsub(wchar_t *ws, unsigned int start, size_t len)
{
	int		real_len;
	int		i;
	char	*fresh;

	real_len = 0;
	i = 0;
	while (ws[i] != '\0' && (int)len >= longchar_len(ws[i]))
	{
		len -= longchar_len(ws[i]);
		real_len += longchar_len(ws[i]);
		i++;
	}
	fresh = long_char_to_char(ws);
	return (ft_strsub_with_free(fresh, start, real_len));
}

char		*ft_strsub_with_free(char const *s, unsigned int start,
	size_t len)
{
	char	*fresh;
	char	*tmp;
	int		i;

	tmp = NULL;
	if (!s)
		return (NULL);
	tmp = (char*)s;
	fresh = malloc((len + 1) * sizeof(char));
	i = 0;
	if (!fresh)
		return (NULL);
	fresh[len] = '\0';
	while (len > 0)
	{
		fresh[i] = s[start];
		i++;
		start++;
		len--;
	}
	free(tmp);
	return (fresh);
}
