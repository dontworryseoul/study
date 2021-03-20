/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 04:55:36 by jso               #+#    #+#             */
/*   Updated: 2021/03/20 09:19:58 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define ZERO 0
# define ASCII_ZERO 48
# define ASCII_SMALL_X 120
typedef struct
{
	int		left;
	int		zero;
	int		width;
	int		dot;
	int		prcs;
	char	type;
}				t_flags;

int			g_ret_value;

int			ft_printf(const char *fmt, ...);

/*
**			Funcs the file of ft_printf_find_format.c below	
*/

void		ft_printf_find_format(va_list ap, const char *fmt, t_flags *flg);
void		ft_printf_check_flag(const char **fmt, t_flags *flg);
void		ft_printf_check_width(va_list ap, const char **fmt, t_flags *flg);
void		ft_printf_check_pres(va_list ap, const char **fmt, t_flags *flg);

/*
**			Funcs the file of ft_printf_print_center.c below	
*/

void		ft_printf_check_type(const char **f, t_flags *flg);
void		ft_printf_printing_types(va_list ap, t_flags *flg);

void		ft_printf_ptr(long long p_hex, t_flags *flg);
void		ft_printf_recur_ptr(long long p_hex, char *base);
int			ft_printf_num_len(long long p_hex, int base);
void		ft_printf_padding(int len);
void		ft_printf_ptr_z_x(long long p_hex, t_flags *flg);

void		ft_printf_putchar(char c);

#endif
