#include "../includes/ft_printf.h"


t_format	*ft_format_initializer(const char *format, va_list args)
{
	t_format	*frmt;

	frmt = malloc(sizeof(*frmt));
	if (!frmt)
		return (NULL);
	frmt->input = format;
	frmt->pos = 0;
	frmt->len = 0;
	va_copy(frmt->args, args);
	return (frmt);
}

t_bin	*ft_bin_initializer(void)
{
	t_bin	*bin;

	bin = malloc(sizeof(t_bin));
	if (!bin)
		return (NULL);
	bin->flags = 0;
	bin->width = 0;
	bin->precision = -1;
	bin->length = 0;
	bin->prefix = '\0';
	bin->conversion = '\0';
	bin->replace = NULL;
	bin->len = 0;
	return (bin);
}
