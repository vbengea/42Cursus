/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbcvali <vbcvali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:03:16 by vbcvali           #+#    #+#             */
/*   Updated: 2024/12/31 11:25:17 by vbcvali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philosophers.h"

static	bool	ft_isalldigit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

static	bool	check_limits(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (i == 1 && (ft_atol(argv[i]) > 200 || ft_atol(argv[i]) < 1))
			return (false);
		if (i < 5 && i > 1)
		{
			if (ft_atol(argv[i]) < 60)
				return (false);
		}
		if (i == 5 && (!ft_isalldigit(argv[i]) || ft_atol(argv[5]) < 1))
			return (false);
		i++;
	}
	return (true);
}

bool	valid_input(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!ft_isalldigit(argv[i]))
			return (false);
		i++;
	}
	if (!check_limits(argv))
		return (false);
	return (true);
}
