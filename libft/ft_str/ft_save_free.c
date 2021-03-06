/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 21:35:52 by rantario          #+#    #+#             */
/*   Updated: 2021/12/30 21:35:55 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	save_free(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}
