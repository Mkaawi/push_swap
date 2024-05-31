/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:15:14 by abdennac          #+#    #+#             */
/*   Updated: 2024/05/27 16:48:56 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_list **stack)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}

void	*ft_memset(void *ptr, int x, size_t n)
{
	char	*p;
	int		i;

	p = ptr;
	i = 0;
	while (n > (size_t)i)
	{
		p[i] = (unsigned char)x;
		i++;
	}
	return (ptr);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if ((num[i] >= '0' && num[i] <= '9'))
			return (1);
		i++;
	}
	return (-1);
}

int	get_min(t_list **stack)
{
	t_list	*tmp;
	int		min;
	int		index;

	tmp = *stack;
	min = tmp->value;
	index = tmp->index;
	while (tmp)
	{
		if (min > tmp->value)
		{
			min = tmp->value;
			index = tmp->index;
		}
		tmp = tmp->next;
	}
	return (index);
}
