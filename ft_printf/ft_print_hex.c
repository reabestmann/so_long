/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:54:07 by rbestman          #+#    #+#             */
/*   Updated: 2025/04/02 12:39:14 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static	int	ft_hex_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num)
	{
		len++;
		num /= 16;
	}
	return (len);
}

static void	ft_convert_hex(unsigned int num, char specifier)
{
	if (num >= 16)
	{
		ft_convert_hex(num / 16, specifier);
		ft_convert_hex(num % 16, specifier);
	}
	else if (num <= 9)
		ft_print_char(num + '0');
	else
	{
		if (specifier == 'x')
			ft_print_char((num - 10 + 'a'));
		if (specifier == 'X')
			ft_print_char((num - 10 + 'A'));
	}
}

int	ft_print_hex(unsigned int num, char specifier)
{
	if (num == 0)
		return (ft_print_char('0'));
	else
		ft_convert_hex(num, specifier);
	return (ft_hex_len(num));
}
