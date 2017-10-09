/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 17:21:10 by yorlov            #+#    #+#             */
/*   Updated: 2017/09/29 17:21:12 by yorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <unistd.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int		ft_atoi(char *str, int k)
{
	int		s;
	int		r;

	r = 0;
	s = 1;
	while (str[k] >= 0 && str[k] <= 32)
		(k)++;
	if (str[k] == '-')
		s = -1;
	if (str[k] == '+' || str[k] == '-')
		(k)++;
	while (str[k] && str[k] >= '0' && str[k] <= '9')
	{
		r = r * 10 + str[k] - '0';
		(k)++;
	}
	return (s * r);
}

int		ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_putstr(char *str)
{
	int 	i;

	i = -1;
	while (str[++i] != '\0')
		write(1, &str[i], 1);
	return (1);
}

char			*ft_itoa_base(uintmax_t nbr, int base)
{
	static char	convert[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
	'9', 'A', 'B', 'C', 'D', 'E', 'F'};
	intmax_t	i;
	uintmax_t	n;
	int			converted_nbr[64];
	char		*result;

	if (nbr == 0)
		return ("0");
	i = 0;
	n = (intmax_t)nbr;
	while (n > 0)
	{
		converted_nbr[i++] = n % base;
		n /= base;
	}
	result = (char*)malloc(sizeof(char) * --i);
	result[i + 1] = '\0';
	while (i >= 0)
		result[n++] = convert[converted_nbr[i--]];
	return (result);
}

int		print_c_times(t_flag *f, char c, int num)
{
	int 	i;

	i = -1;
	if (num < 1)
		return (0);
	while (++i < num)
		to_buf_c(f, c);
	return (1);
}

void		ft_sign(t_flag *f)
{
	f->sign = '+';
	if (f->data < 0)
		f->sign = '-';
}

uintmax_t		pf_ft_sign(t_flag *f, intmax_t data)
{
	f->sign = '+';
	if (data < 0)
	{
		f->sign = '-';
		data = -data;
	}
	return ((uintmax_t)data);
}

int 			to_buf(t_flag *f, char *str)
{
	// printf("%s\n", str);
	f->buf = ft_strjoin(f->buf, str);
	return (1);
}

int 			to_buf_c(t_flag *f, char c)
{
	f->buf = ft_strjoin_c(f->buf, c);
	return (1);
}

void	init_buf(t_flag *f)
{
	f->buf = ft_strnew(1);
	ft_putstr(f->buf);
}

char	*ft_strnew(size_t size)
{
	char	*text;

	text = (char *)malloc((size + 1) * sizeof(char));
	if (!text)
		return (NULL);
	ft_bzero(text, size);
	text[size] = '\0';
	return (text);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	if (n != 0)
	{
		ptr = s;
		i = 0;
		while (i < n)
		{
			ptr[i] = 0;
			i++;
		}
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;

	if (!s1)
		return (NULL);
	strjoin = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!strjoin)
		return (NULL);
	ft_strcpy(strjoin, s1);
	ft_strcat(strjoin, s2);
	return (strjoin);
}

char	*ft_strjoin_c(char const *s1, char s2)
{
	char	*strjoin;

	if (!s1)
		return (NULL);
	strjoin = ft_strnew(ft_strlen(s1) + 1);
	if (!strjoin)
		return (NULL);
	ft_strcpy(strjoin, s1);
	ft_strcat(strjoin, &s2);
	strjoin[ft_strlen(s1) + 1] = '\0';
	return (strjoin);
}

char	*ft_strcpy(char *dst, const char *src)
{
	size_t		i;
	size_t 		j;

	i = 0;
	j = ft_strlen(src);
	while (i < j)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	size_t	i;
	size_t	k;
	size_t 	j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	k = 0;
	while (k < j)
	{
		s1[i] = s2[k];
		i++;
		k++;
	}
	s1[i] = '\0';
	return (s1);
}

void	to_lower(t_flag *f)
{
	int 	i;

	i = -1;
	while (f->arg[++i] != '\0')
	{
		if (f->arg[i] >= 'A' && f->arg[i] <= 'Z')
			f->arg[i] = f->arg[i] + 32;
	}
}
