#include "../includes/ft_printf.h"


void	ft_place_bin(int fd, t_format *frmt)
{
	t_bin	*bin;

	bin = ft_parser(frmt);
	if (bin->conversion)
	{
		ft_choose_conversion(bin, frmt->args);
		frmt->len += write(fd, bin->replace, bin->len);
		free(bin->replace);
	}
	free(bin);
}
