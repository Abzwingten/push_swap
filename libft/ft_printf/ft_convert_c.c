#include "../includes/ft_printf.h"


static wint_t	ft_length(t_bin *bin, va_list args)
{
	wint_t	c;

	if (bin->length & L_LONG)
		c = (wint_t)(va_arg(args, wint_t));
	else
		c = (int)(va_arg(args, int));
	return ((wint_t)c);
}

void	ft_convert_c(t_bin *bin, va_list args)
{
	wint_t	c;

	c = ft_length(bin, args);
	if (!bin->width)
		bin->width += 1;
	bin->replace = malloc(bin->width);
	ft_memset(bin->replace, SPACE, bin->width);
	if (bin->flags & FLAG_MINUS)
		bin->replace[0] = c;
	else
		bin->replace[bin->width - 1] = c;
	bin->len = bin->width;
}
