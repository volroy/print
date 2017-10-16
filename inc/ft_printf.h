/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 08:09:33 by yorlov            #+#    #+#             */
/*   Updated: 2017/10/16 08:09:36 by yorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <wchar.h>

char			g_buffer[2048];
int				g_buffer_counter;

typedef struct	s_flag
{
	int			res;
	char		*format;
	int			index;
	char		spe;
	char		*arg;
	wchar_t		*warg;
	char		sign;
	va_list		ap;
	intmax_t	data;
	uintmax_t	data_max;
	int			f_tab[13];
}				t_flag;

typedef struct	s_specificator
{
	char		specificator;
	int			(*ptr)();
}				t_specificator;

int				ft_printf(const char *format, ...);
void			ft_end(t_flag *f);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_itoa_base(uintmax_t nbr, int base);
uintmax_t		ft_sign(t_flag *f, intmax_t nbr);
int				ft_strlen(const char *str);
int				ft_atoi_mod(char *str, int *k);
char			*ft_strlwr(char *s1);
int				longchar_len(wchar_t wchar);
size_t			byte_len(wchar_t *ws);
size_t			longstr_len(wchar_t *ws);
char			*ft_wstrsub(wchar_t *ws, unsigned int start, size_t len);
char			*ft_strsub_with_free(char const *s, unsigned int start,
				size_t len);
char			*long_char_to_char(wchar_t *ws);
int				put_long_char_in_char(wchar_t wchar, char *fresh, int i);
int				dispatcher(t_flag *f, va_list *ap);
void			init_specificator(t_specificator *s);
void			init_specificator_tail(t_specificator *s);
void			init_f_tab(t_flag *f);
void			init_buf(void);
int				parser(t_flag *f);
void			parse_flag(t_flag *f);
void			parse_width(t_flag *f);
void			parse_precision(t_flag *f);
void			parse_mod(t_flag *f);
char			*cast_d(t_flag *f, va_list *ap);
char			*cast_x(t_flag *f, va_list *ap);
char			*cast_u_o(t_flag *f, va_list *ap);
char			*cast_lu_lo(t_flag *f, va_list *ap);
int				cast_lc(t_flag *f, va_list *ap);
int				handle_c(t_flag *f, va_list *ap);
int				handle_lc(t_flag *f, va_list *ap);
int				handle_s(t_flag *f, va_list *ap);
int				handle_ls(t_flag *f, va_list *ap);
int				handle_d(t_flag *f, va_list *ap);
int				handle_ld(t_flag *f, va_list *ap);
int				handle_o(t_flag *f, va_list *ap);
int				handle_u(t_flag *f, va_list *ap);
int				handle_lo(t_flag *f, va_list *ap);
int				handle_lu(t_flag *f, va_list *ap);
int				handle_x(t_flag *f, va_list *ap);
int				handle_lx(t_flag *f, va_list *ap);
int				handle_p(t_flag *f, va_list *ap);
int				handle_undef(t_flag *f);
void			not_elon_but_musk(t_flag *f, int *mask);
int				handle_char(t_flag *f);
int				handle_num(t_flag *f);
void			handle_prefics(t_flag *f);
void			handle_octothorp(t_flag *f);
void			handle_string_precision(t_flag *f);
void			handle_num_precision_without_width(t_flag *f);
void			handle_num_filler(t_flag *f, int len);
void			handle_num_right_side(t_flag *f);
void			handle_num_left_side(t_flag *f);
void			handle_num_width(t_flag *f);
void			handle_definitely_char(t_flag *f, int i);
void			handle_char_width(t_flag *f);
void			handle_char_left_side(t_flag *f);
void			handle_char_right_side(t_flag *f);
int				to_buf(char c, t_flag *f);
void			null_exception(t_flag *f);
void			print_it(t_flag *f);
void			costyl(t_flag *f, va_list *ap);

#endif
