/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 17:18:42 by akorol            #+#    #+#             */
/*   Updated: 2019/01/15 15:16:37 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef	struct		s_nigga
{
	char			*out;
	char const		*conv;
	char			width;
	char			sign;
	char			minus;
	char			plus;
	char			blank;
	int				arg;
	int				invalid;
	int				m_s;
	int				p_s;
	int				percent;
	int				hash;
	int				zero;
	int				dot;
	int				slashz;
	struct s_nigga	*next;
}					t_nigga;

int					round_f(long long buf, long long buf2, double *onum);
int					replace_function(long long *buf, long long buf2,
	double *onum);
void				tuning_f_small_part(char **part_1, char **part_2,
	double num, t_nigga **nig);
char				*tuning_f_2(double num, double *onum, t_nigga **nig);
char				*tuning_f_1(double num, t_nigga **nig);
void				zero_case_pure_function(t_nigga **nig);
void				zero_case_function(t_nigga **nig);
char				*conversion_percent(char *buf, t_nigga **nig);
void				nan_inf_string(char *str, t_nigga **nig);
void				buf_tuning_f_part_1(char *buf, t_nigga **nig);
void				nan_inf_function(double num, t_nigga **nig);
long double			casting_f(t_nigga **nig, va_list args);
void				tuning_f(t_nigga **nig, va_list args);
void				check_weather_o(char *digits, char **temp, t_nigga **nig);
char				*open_u_conversion(t_nigga **nig, va_list args);
char				*condition_b(char *digits, t_nigga **nig);
char				*condition_a(int g, int len, char *digits, t_nigga **nig);
char				*zero_tunage(char *tmp, t_nigga **nig);
char				*cond_a(int g, int len, char *digits, t_nigga **nig);
char				*cond_b(char *digits, t_nigga **nig);
char				*cond_part_2(t_nigga **nig);
char				*cond_part_1(t_nigga **nig);
void				concatenate(char *fin, t_nigga **nig);
int					concatenating(t_nigga *nig, va_list args);
void				hex_capital(char *buf);
void				piece_hex_shit(char const *str, t_nigga **nig,
	va_list args);
char				*hex_converter(t_nigga **nig, va_list args);
void				useful_function(char **tmp, t_nigga **nig);
char				*remainder_zeros(double *num, long long *i, t_nigga **nig);
char				*string_tuning_f(char *buf, char *str, t_nigga **nig);
void				add_sign_f(char *str, t_nigga **nig);
void				buf_tuning_f(char *str, t_nigga **nig);
void				fill_wz_zero(char *str);
char				*join_sign_f(char *str, t_nigga **nig);
void				piece_f_shit(char const *str, t_nigga **nig, va_list args);
char				*open_u_conv(t_nigga **nig, va_list args);
void				conv_u(t_nigga **nig, va_list args);
void				sign_func_o(char **buf, char *digits, t_nigga **nig);
void				merging_o(char *dest, char *digits, t_nigga **nig);
char				*open_o_conv(t_nigga **nig, va_list args);
void				conv_o(t_nigga **nig, va_list args);
void				process_piece_p(char const *fmt, t_nigga **nig,
	va_list args);
void				pick_width(char *fmt, t_nigga **nig);
void				pick_precision(char *fmt, t_nigga **nig);
void				custom_strcpy(char *str1, char *str2);
void				length_comparator(t_nigga **nig, va_list args);
void				last_piece(char	*fin, t_nigga **nig);
void				process_piece_s(char const *fmt, t_nigga **nig,
	va_list args);
void				fill2(char *str, int len);
void				pre_tuner(char const **str, t_nigga **nig);
void				align_c(char *buf, t_nigga **nig);
char				*conversion_c(char *buf, t_nigga **nig, va_list args);
int					separation_vol3(char const *str, t_nigga **nig);
void				separation_vol2(char const *str, int *min, int len);
int					separation(char const *str, int len);
char				*process_piece_c(char const *str, t_nigga **nig);
char				*mod_itoa(long long value, t_nigga **nig);
void				exp_digits(char *buf, t_nigga **nig);
void				flag_tuning(t_nigga **nig);
char const			*next(char const *fmt);
void				push(char *dest, char *src);
void				sign_func_1(char **buf, char *digits, t_nigga **nig);
void				sign_func(char **buf, char *digits, t_nigga **nig);
void				sign_func_2(char **buf, char *digits, int len,
	t_nigga **nig);
void				sign_digits_func(char *dest, char **digits, t_nigga **nig);
void				merging(char **dest, char **digits, t_nigga **nig);
void				minus_flag(char *str, t_nigga **nig);
void				conversion_d(t_nigga **nig, va_list args);
char				*open_d_conversion(t_nigga **nig, va_list args);
void				tuner(char const **point, t_nigga **nig, va_list args);
char				*ft_itoa_base(uintmax_t value, int base);
void				customize_flags(char const *s, t_nigga **nig);
void				customize_flags_2(char const *s, int i, t_nigga **lopata);
char const			*customize_string(char const *str, t_nigga **nig);
void				fill_my_nigga(t_nigga **nig);
char const			*double_percent_sign(char const *fmt, t_nigga **nig);
char const			*find_width_digits(char const *str, t_nigga **nig);
char const			*find_precision_digits(int	*f, char const *str,
	t_nigga **nig);
int					find_greater(int a, int b);
void				fill_zero(char *buf, int size, int fill);
char				*take_piece(char *point);
char				*create_buffer(int	size);
void				check_min_width(char const *str, t_nigga **nig);
void				check_precision(char const *str, t_nigga **nig);
void				check_for_size(char const *str, char *p, t_nigga **nig);
int					ft_printf(const char *restrict fmt, ...);
void				process_piece(char const *str, t_nigga **nig);
int					pick_up_args(va_list args,
		char const *fmt, t_nigga **nig);

#endif
