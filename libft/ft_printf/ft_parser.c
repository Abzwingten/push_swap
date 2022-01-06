#include "../includes/ft_printf.h"


t_bin	*ft_parser(t_format *frmt)
{
	t_bin	*bin;

	bin = ft_bin_initializer();
	frmt->pos++;
	ft_parser_flags(frmt, bin);
	ft_parser_width(frmt, bin);
	ft_parser_precision(frmt, bin);
	ft_parser_length(frmt, bin);
	ft_parser_conversion(frmt, bin);
	return (bin);
}
