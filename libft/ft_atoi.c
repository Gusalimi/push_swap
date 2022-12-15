/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:51:59 by gsaile            #+#    #+#             */
/*   Updated: 2022/12/15 18:09:18 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return ((c == '\t')
		|| (c == '\n')
		|| (c == '\v')
		|| (c == '\f')
		|| (c == '\r')
		|| (c == ' '));
}

int	ft_atoi(const char *str, t_number *a, char **tab)
{
	unsigned int		result;
	int					sign;
	char				*tmp;

	result = 0;
	sign = 1;
	tmp = (char *)str;
	while (ft_isspace(*tmp))
		tmp++;
	if (*tmp == '+' || *tmp == '-')
		if (*(tmp++) == '-')
			sign = -1;
	while (ft_isdigit(*tmp))
	{
		result *= 10;
		result += *tmp - '0';
		tmp++;
		if ((sign == 1 && result > 2147483647)
			|| (sign == -1 && result > 2147483648))
			atoi_error_exit(a, tab);
	}
	if (*tmp != 0)
		atoi_error_exit(a, tab);
	return (result * sign);
}
