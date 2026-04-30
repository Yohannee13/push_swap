/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivandri <rivandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 19:22:03 by rivandri          #+#    #+#             */
/*   Updated: 2026/04/30 22:24:35 by yoandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_flag(char *arg, t_options *opts, t_stack **a)
{
	if (ft_streq(arg, "--simple"))
		opts->selector = "--simple";
	else if (ft_streq(arg, "--medium"))
		opts->selector = "--medium";
	else if (ft_streq(arg, "--complex"))
		opts->selector = "--complex";
	else if (ft_streq(arg, "--adaptive"))
		opts->selector = "--adaptive";
	else if (ft_streq(arg, "--bench"))
		opts->bench = 1;
	else
		ft_error(a);
}

static void	process_arg(char *arg, t_stack **a)
{
	char	**split;
	int		j;

	if (!ft_strchr(arg, ' '))
	{
		if (!is_valid_number(arg))
			ft_error(a);
		process_value(arg, a);
		return ;
	}
	split = ft_split(arg, ' ');
	j = 0;
	while (split[j])
	{
		if (!ft_str_is_space(split[j]))
		{
			if (!is_valid_number(split[j]))
				ft_error(a);
			process_value(split[j], a);
		}
		j++;
	}
	if (j == 0)
		ft_error(a);
	free_arg(split);
}

static void	fill_stack_and_opts(int argc, char **argv,
	t_options *opts, t_stack **a)
{
	int	i;

	opts->selector = NULL;
	opts->bench = 0;
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
			handle_flag(argv[i], opts, a);
		else
			process_arg(argv[i], a);
		i++;
	}
}

static t_stack	*parse_input(int argc, char **argv, t_options *opts)
{
	t_stack	*a;

	a = NULL;
	fill_stack_and_opts(argc, argv, opts, &a);
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_options	opts;
	t_bench		bench;

	b = NULL;
	if (argc < 2)
		return (0);
	a = parse_input(argc, argv, &opts);
	index_stack(a);
	if (!a || ft_lst_size(a) <= 1 || is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	ft_memset(&bench, 0, sizeof(t_bench));
	decision(&a, &b, opts.selector, &bench);
	if (opts.bench)
		benchmark(&bench);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
