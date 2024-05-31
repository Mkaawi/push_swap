/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:43:31 by abdennac          #+#    #+#             */
/*   Updated: 2024/05/27 16:49:51 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_sa(t_list **stack_a)
{
	ra(stack_a);
	sa(stack_a);
}

void	sort_3(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	if (tmp->value > tmp->next->value
		&& tmp->next->value > tmp->next->next->value)
		ra_sa(stack_a);
	else if (tmp->value > tmp->next->value
		&& tmp->next->value < tmp->next->next->value)
	{
		if (tmp->value > tmp->next->next->value)
			ra(stack_a);
		else if (tmp->value < tmp->next->next->value)
			sa(stack_a);
	}
	else if (tmp->value < tmp->next->value
		&& tmp->next->value > tmp->next->next->value)
	{
		if (tmp->value > tmp->next->next->value)
			rra(stack_a);
		else if (tmp->value < tmp->next->next->value)
		{
			rra(stack_a);
			sa(stack_a);
		}
	}
}

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		min;

	tmp = *stack_a;
	min = get_min(stack_a);
	while ((*stack_a)->index != min)
	{
		if (min > ft_lstsize(*stack_a) / 2)
			rra(stack_a);
		else
			ra(stack_a);
	}
	pb(stack_a, stack_b);
	if (ft_lstsize(*stack_a) == 3)
		sort_3(stack_a);
	pa(stack_b, stack_a);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		min;

	tmp = *stack_a;
	min = get_min(stack_a);
	while ((*stack_a)->index != min)
	{
		if (min > ft_lstsize(*stack_a) / 2)
			rra(stack_a);
		else
			ra(stack_a);
	}
	pb(stack_a, stack_b);
	min = get_min(stack_a);
	while ((*stack_a)->index != min)
		ra(stack_a);
	pb(stack_a, stack_b);
	if (ft_lstsize(*stack_a) == 3)
		sort_3(stack_a);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}
