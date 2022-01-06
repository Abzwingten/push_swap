#include "../includes/ft_printf.h"


int	ft_parser_asterix(char option, t_format *f, t_bin *bin)
{
	int	spec;

	spec = va_arg(f->args, int);
	if (spec < 0)
	{
		if (!option)
		{
			spec *= -1;
			bin->flags |= FLAG_MINUS;
		}
		else
			spec = -1;
	}
	return (spec);
}
