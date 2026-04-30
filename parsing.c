/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivandri <rivandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 19:21:33 by rivandri          #+#    #+#             */
/*   Updated: 2026/04/30 22:25:22 by yoandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_value(char *arg, t_stack **a)
{
	long	value;

	if (!is_valid_number(arg))
		ft_error(a);
	value = ft_atol(arg);
	if (value > INT_MAX || value < INT_MIN || value == LONG_MAX)
		ft_error(a);
	if (duplicate(*a, (int)value))
		ft_error(a);
	add_back(a, new_node((int)(value)));
}
