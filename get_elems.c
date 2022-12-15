/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elems.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:00:45 by gsaile            #+#    #+#             */
/*   Updated: 2022/12/15 17:46:33 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_alpha(char *s)
{
	while (*s)
	{
		if (*s != ' ' && *s != '+' && *s != '-' && (*s < '0' || *s > '9'))
			return (1);
		s++;
	}
	return (0);
}

void	get_index(t_number *a)
{
	int			i;
	t_number	*tmp;

	while (a)
	{
		i = a->value;
		tmp = a->next;
		while (tmp)
		{
			if (tmp->value > i)
				tmp->index++;
			else if (tmp->value < i)
				a->index++;
			else
			{
				ft_lstclear(&a);
				ft_putstr_fd("Error\n", 2);
				exit(1);
			}
			tmp = tmp->next;
		}
		a = a->next;
	}
}

t_number	*get_elems(int num, char **av)
{
	t_number	*head;

	if (num == 1)
		exit(0);
	head = NULL;
	get_elems2(num, av, &head);
	get_index(head);
	return (head);
}

void	get_elems2(int num, char **av, t_number **head)
{
	int			i;
	int			j;
	t_number	*current;
	char		**tmp;

	i = 1;
	while (i < num)
	{
		if (has_alpha(av[i]))
			error_exit(head, NULL);
		tmp = ft_split(av[i], ' ');
		j = 0;
		while (tmp[j])
		{
			current = malloc(sizeof(t_number));
			if (current == NULL)
				atoi_error_exit(*head, tmp);
			current->next = NULL;
			current->value = ft_atoi(tmp[j++], *head, tmp);
			current->index = 0;
			ft_lstadd_back(head, current);
		}
		ft_free_split(tmp);
		i++;
	}
}
