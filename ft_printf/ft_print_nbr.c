/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoandria <yoandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 10:13:08 by yoandria          #+#    #+#             */
/*   Updated: 2026/04/16 10:16:27 by yoandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	int		len;
	int		tmp;
	long	num;

	len = 0;
	num = n;
	if (num < 0)
	{
		if (ft_print_char('-') == -1)
			return (-1);
		len++;
		num = -num;
	}
	if (num >= 10)
	{
		tmp = ft_print_nbr(num / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	tmp = ft_print_char((num % 10) + '0');
	if (tmp == -1)
		return (-1);
	len += tmp;
	return (len);
}
