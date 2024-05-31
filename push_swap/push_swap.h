/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:28:03 by abdennac          #+#    #+#             */
/*   Updated: 2024/05/27 16:49:03 by abdennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;

void				pa(t_list **stack_b, t_list **stack_a);
void				pb(t_list **stack_a, t_list **stack_b);
void				sa(t_list **stack_a);
void				sb(t_list **stack_b);
void				ss(t_list **stack_a, t_list **stack_b);
void				ra(t_list **stack_a);
void				rb(t_list **stack_b);
void				rr(t_list **stack_a, t_list **stack_b);
void				rra(t_list **stack_a);
void				rrb(t_list **stack_b);
void				rrr(t_list **stack_a, t_list **stack_b);

void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *list);
t_list				*ft_lstnew(int value);

int					get_min(t_list **stack);
int					ft_isnum(char *num);
void				*ft_memset(void *ptr, int x, size_t n);
void				free_list(t_list **head);
void				ffree(char **str);
void				initStack(t_list **stack, int argc, char **argv);
void				check_list(t_list **stack);
int					check_args(char **args);
void				quick_sort(t_list **stack);
void				sort_3(t_list **stack_a);
void				sort_4(t_list **stack_a, t_list **stack_b);
void				sort_5(t_list **stack_a, t_list **stack_b);
void				range(t_list **stack_a, t_list **stack_b, t_list **sorted,
						int end);
void				index_stack(t_list **stack);
int					count(char *str, char c);
void				fre(char **str, int count);
long				ft_atoi(const char *str);
char				**ft_split(char *s, char c);
void				ft_putstr(char const *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_strlen(const char *str);
char				*ft_strdup(char *src);

#endif