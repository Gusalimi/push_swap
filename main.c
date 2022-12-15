/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:55:12 by gsaile            #+#    #+#             */
/*   Updated: 2022/12/15 17:55:03 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_stack(t_number *stack, const char stack_name)
{
	ft_printf("%c :\n", stack_name);
	if (stack_name == 'a')
		ft_printf("\033[0;32m");
	else
		ft_printf("\033[0;34m");
	if (!stack)
		return (ft_printf("(empty)\033[0m\n"));
	while (stack)
	{
		ft_printf("%d\n", stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
	ft_printf("\033[0m");
	return (0);
}

int	main(int ac, char **av)
{
	t_number	*a;
	t_number	*b;

	a = get_elems(ac, av);
	b = 0;
	if (is_sorted(a))
	{
		ft_lstclear(&a);
		return (0);
	}
	if (ft_lstsize(a) < 6)
		bruteforce(&a, &b);
	else
		sort(&a, &b);
	ft_lstclear(&a);
	ft_lstclear(&b);
}
