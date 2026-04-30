/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivandri <rivandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 07:16:55 by airandri          #+#    #+#             */
/*   Updated: 2026/04/30 21:42:19 by yoandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	small(t_stack **a, t_stack **b, t_bench *bench, int size)
{
	if (size <= 3)
	{
		bench->strategy = "adaptive";
		bench->complexity = "O(1)";
		sort_three(a, bench);
	}
	else
	{
		bench->strategy = "adaptive";
		bench->complexity = "O(n²)";
		handle_min(a, b, bench);
	}
}

static void	large(t_stack **a, t_stack **b, t_bench *bench)
{
	if (bench->disorder < 0.2)
	{
		bench->strategy = "simple";
		bench->complexity = "O(n²)";
		selection_sort(a, b, bench);
	}
	else if (bench->disorder < 0.5)
	{
		bench->strategy = "medium";
		bench->complexity = "O(n√n)";
		chunk_sort(a, b, bench);
	}
	else
	{
		bench->strategy = "complex";
		bench->complexity = "O(n log n)";
		radix_sort(a, b, bench);
	}
}

static void	adaptive(t_stack **a, t_stack **b, t_bench *bench)
{
	int		size;

	size = ft_lst_size(*a);
	if (size <= 5)
		small(a, b, bench, size);
	else
		large(a, b, bench);
}

void	decision(t_stack **a, t_stack **b, char *selector, t_bench *bench)
{
	bench->disorder = disorder(*a);
	if (selector && ft_streq(selector, "--simple"))
	{
		selection_sort(a, b, bench);
		bench->strategy = "simple";
		bench->complexity = "O(n²)";
	}
	else if (selector && ft_streq(selector, "--medium"))
	{
		chunk_sort(a, b, bench);
		bench->strategy = "medium";
		bench->complexity = "O(n√n)";
	}
	else if (selector && ft_streq(selector, "--complex"))
	{
		radix_sort(a, b, bench);
		bench->strategy = "complex";
		bench->complexity = "O(n log n)";
	}
	else if (!selector || ft_streq(selector, "--adaptive"))
		adaptive(a, b, bench);
}
