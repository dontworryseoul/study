/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jso <jso@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:27:32 by jso               #+#    #+#             */
/*   Updated: 2021/03/17 21:37:24 by jso              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_flags
{
	int			left;
	int			zero;
	int			width;
	int			dot;
	int			precision;
	int			type;
}				t_flags;

int				g_ret_value;

int				ft_printf(const char *fmt, ...);

#endif
