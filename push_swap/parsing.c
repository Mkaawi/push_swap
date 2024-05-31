/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:22:06 by abdennac          #+#    #+#             */
/*   Updated: 2024/05/27 16:49:46 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_valid(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if ((num[i] == '+' || num[i] == '-') && (num[i + 1] < '0' || num[i
					+ 1] > '9'))
			return (-1);
		i++;
	}
	i = 0;
	while (num[i])
	{
		if ((num[i] >= '0' && num[i] <= '9') || num[i] == ' ' || num[i] == '+'
			|| num[i] == '-')
			i++;
		else
			return (-1);
	}
	return (0);
}

int	check_args(char **args)
{
	int		i;
	long	tmp;

	i = 1;
	while (args[i])
	{
		if (ft_isnum(args[i]) == -1)
			return (ft_putstr("invalid arguments\n"), -1);
		else if (ft_isnum(args[i]) != -1)
		{
			if (ft_valid(args[i]) == -1)
				return (ft_putstr("invalid arguments\n"), -1);
		}
		tmp = ft_atoi(args[i]);
		if (tmp < -2147483648 || tmp > 2147483647)
			return (ft_putstr("number too big\n"), -1);
		i++;
	}
	return (0);
}

void	check_duplicate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *stack;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->value == tmp2->value)
			{
				ft_putstr("duplicate arguments\n");
				free_list(stack);
				exit(0);
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void	if_sorted(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return ;
		tmp = tmp->next;
	}
	ft_putstr("already sorted\n");
	free_list(stack);
	exit(0);
}

void	check_list(t_list **stack)
{
	if (ft_lstsize(*stack) < 2)
	{
		ft_putstr("list too small\n");
		free_list(stack);
		exit(0);
	}
	check_duplicate(stack);
	if_sorted(stack);
}
