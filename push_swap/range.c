/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:48:03 by abdennac          #+#    #+#             */
/*   Updated: 2024/05/27 15:18:46 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	re_index(t_list **stack, t_list **sorted)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *stack;
	while (tmp)
	{
		tmp2 = *sorted;
		while (tmp2)
		{
			if (tmp->value == tmp2->value)
			{
				tmp->index = tmp2->index;
				break ;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void	quick_sort(t_list **stack)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		swp;

	tmp = *stack;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->value > tmp2->value)
			{
				swp = tmp->value;
				tmp->value = tmp2->value;
				tmp2->value = swp;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

int	get_max(t_list **stack)
{
	t_list	*tmp;
	int		max;
	int		index;
	int		i;

	i = 0;
	index = 0;
	tmp = *stack;
	max = tmp->value;
	while (tmp)
	{
		if (max < tmp->value)
		{
			max = tmp->value;
			i = index;
		}
		index++;
		tmp = tmp->next;
	}
	return (i);
}

void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	int	max;

	while (ft_lstsize(*stack_b) != 0)
	{
		max = get_max(stack_b);
		if (max <= ft_lstsize(*stack_b) / 2)
		{
			while (max != 0)
			{
				rb(stack_b);
				max--;
			}
		}
		else
		{
			while (ft_lstsize(*stack_b) - max != 0)
			{
				rrb(stack_b);
				max++;
			}
		}
		pa(stack_b, stack_a);
	}
}

void	range(t_list **stack_a, t_list **stack_b, t_list **sorted, int end)
{
	int	start;

	start = 0;
	quick_sort(sorted);
	re_index(stack_a, sorted);
	while (*stack_a)
	{
		if ((*stack_a)->index >= start && (*stack_a)->index <= end)
		{
			pb(stack_a, stack_b);
			start++;
			end++;
		}
		else if ((*stack_a)->index < start)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			start++;
			end++;
		}
		else if ((*stack_a)->index > end)
			ra(stack_a);
	}
	index_stack(stack_b);
	push_to_a(stack_a, stack_b);
}
