/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 22:32:01 by yorlov            #+#    #+#             */
/*   Updated: 2017/09/27 22:32:03 by yorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <inttypes.h>
#include <stdio.h>

typedef struct	s_flag
{
	char		*format;
	int			f_tab[14];
	int			index;
	char 		*arg;
	int 		width;
	intmax_t	data;
	uintmax_t	data_max;
	char 		sign;
	char 		s_or_p;
	char 		*buf;
	int 		dot;
	int 		len;
	char 		*hex;
}				t_flag;

typedef struct	t_conv
{
	int			(*ptr)();
}				t_conv;

/*ft_printf*/
int				ft_printf(const char *format, ...);

/*parcer*/
int			check_format(t_flag *f);
int				check_flag(t_flag *f);
void			check_width(t_flag *f);
void			check_precision(t_flag *f);
void			check_modif(t_flag *f);

/*parcer_tail*/
void			check_convercions(t_flag *f);
void			check_convercions_2(t_flag *f);

/*init_all*/
void			init_all(t_flag *f);
void			init_f_tab(t_flag *f);
void			init_conversions_table(t_flag *f);

/*dispatcher*/
void			dispatcher(t_flag *f, va_list *ap);
void			dispatcher2(t_flag *f, va_list *ap);

/*additional_func*/
int				ft_atoi(char *str, int k);
int				ft_strlen(const char *str);
int				ft_putstr(char *str);
char			*pf_ft_itoa_base(uintmax_t nbr, int base);
void			cast_var(t_flag *f, va_list *ap);
int				print_c_times(t_flag *f, char c, int num);
void			ft_sign(t_flag *f);
char			*ft_itoa_base(uintmax_t nbr, int base);
uintmax_t		pf_ft_sign(t_flag *f, intmax_t data);
char			*ft_strnew(size_t size);
void			ft_bzero(void *s, size_t n);
void			init_buf(t_flag *f);
int 			to_buf(t_flag *f, char *c);
int 			to_buf_c(t_flag *f, char c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strcat(char *restrict s1, const char *restrict s2);
char			*ft_strjoin_c(char const *s1, char s2);
void			to_lower(t_flag *f);
// void 	ft_putchar(char *str);

/*handle_s*/
int				handle_s(t_flag *f, va_list *ap);
void			s_without_shift(t_flag *f);
void			s_with_precision(t_flag *f);
void			s_with_width(t_flag *f);
void			s_with_width_and_precision(t_flag *f);

/*handle_c*/
int				handle_c(t_flag *f, va_list *ap);
void			c_with_width(t_flag *f, char s);

/*handle_i*/
int				handle_i(t_flag *f, va_list *ap);
void			i_without_width_and_precision(t_flag *f);
void			i_with_width(t_flag *f, int i);
void			i_with_width_tail(t_flag *f, int k, int i);
void 			i_with_precision(t_flag *f, int i);
void			i_width_and_precision(t_flag *f, int i);
void			i_width_and_precision_tail(t_flag *f, int k, int i);

/*handle_Xx*/
int				handle_Xx(t_flag *f, va_list *ap);
char			*cast_x(t_flag *f, va_list *ap);
void			x_without(t_flag *f);
void			x_with_width(t_flag *f, int i, int k);
void			x_with_precision(t_flag *f, int i, int k);
void			x_width_and_precision(t_flag *f, int i, int k);

/*handle_o*/
int				handle_o(t_flag *f, va_list *ap);
void			o_without(t_flag *f);
void			o_with_width(t_flag *f);
void			o_with_precision(t_flag *f);
void			o_width_and_precision(t_flag *f);

/*handle_u*/
int				handle_u(t_flag *f, va_list *ap);
void			u_without(t_flag *f);
void			u_with_width(t_flag *f);
void			u_with_precision(t_flag *f);
void			u_width_and_precision(t_flag *f);

/*handle_percentage*/
int				handle_percentage(t_flag *f);
int				handle_p(t_flag *f);

/*handle_zero.c*/
int		handle_zero(t_flag *f);
int		handle_zero_o(t_flag *f);
int		handle_zero_x(t_flag *f);

/*cast*/
char			*cast_i(t_flag *f, va_list *ap);
char			*cast_x(t_flag *f, va_list *ap);
char			*cast_o(t_flag *f, va_list *ap);


int 	some_1(t_flag *f);

#endif