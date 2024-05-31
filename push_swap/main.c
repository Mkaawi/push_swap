/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:28:06 by abdennac          #+#    #+#             */
/*   Updated: 2024/05/31 12:06:03 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initstack(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;
	int		j;

	j = 1;
	while (j < argc)
	{
		i = 0;
		args = ft_split(argv[j], ' ');
		while (args[i])
		{
			new = ft_lstnew(ft_atoi(args[i]));
			ft_lstadd_back(stack, new);
			i++;
		}
		ffree(args);
		j++;
	}
	check_list(stack);
	index_stack(stack);
}

int	calculate_end(t_list **stack_a)
{
	int	size;
	int	end;

	end = 0;
	size = ft_lstsize(*stack_a) / 100;
	while (size > 0)
	{
		size--;
		end += 4;
	}
	return (end);
}

void	sort(t_list **stack_a, t_list **stack_b, t_list **sorted)
{
	int	size;
	int	end;

	size = ft_lstsize(*stack_a);
	end = calculate_end(stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
	else if (size > 5 && size <= 100)
		range(stack_a, stack_b, sorted, 15);
	else if (size > 100)
		range(stack_a, stack_b, sorted, 15 + end);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	t_list	**sorted;

	if (argc < 2)
		return (0);
	if (check_args(argv) == -1)
		return (0);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	sorted = (t_list **)malloc(sizeof(t_list));
	initstack(stack_a, argc, argv);
	initstack(sorted, argc, argv);
	sort(stack_a, stack_b, sorted);
	free_list(stack_a);
	free_list(stack_b);
	free_list(sorted);
	return (0);
}
