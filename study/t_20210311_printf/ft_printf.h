#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_flags
{
	int			left;
	int			zero;
	int			precision;
	int			dot;
	int			width;
	int			ret_value;
	int			padding_byte;
	char		type;
}				t_flags;

int			ft_printf(const char *format, ...);
void		ft_printf_rst(va_list ap, const char *fmt, t_flags *flags);
void		ft_printf_all(va_list ap, t_flags *flags);
void		ft_init_struct(t_flags *flags);
void		ft_printf_char(va_list ap, t_flags *flags);
void		ft_printf_padding(int byte, t_flags *flags);

void		ft_check_format(va_list ap, const char **fmt, t_flags *flags);
void		ft_check_type(const char **f, t_flags *flags);
void		ft_check_precs(va_list ap, const char **fmt, t_flags *flags);
void		ft_check_width(va_list ap, const char **fmt, t_flags *flags);
void		ft_check_flag(const char **fmt, t_flags *flags);

#endif
