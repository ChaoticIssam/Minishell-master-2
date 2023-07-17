/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_parss_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:15:43 by iszitoun          #+#    #+#             */
/*   Updated: 2023/07/14 10:23:21 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_quotes_pair(char *str, char c)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == c)
			return (i);
		i--;
	}
	return (0);
}

int	sec_q(char *tknz)
{
	int	i;

	i = ft_strlen(tknz) - 1;
	while (i >= 0)
	{
		if (tknz[i] == '3')
			return (i);
		i--;
	}
	return (0);
}

int	sec_s_q(char *tknz)
{
	int	i;

	i = ft_strlen(tknz) - 1;
	while (i >= 0)
	{
		if (tknz[i] == '0')
			return (i);
		i--;
	}
	printf("1\n");
	return (lerreurat(3));
}

int	sec_q_rex(char *tknz, int end)
{
	if (tknz[end + 1] == '1')
	{
		while (tknz[end])
		{
			if (tknz[end + 1] == '2' || tknz[end + 1] == '6')
				return (end);
			end++;
		}
	}
	return (end);
}

int	frst_q(char *tknz)
{
	int	i;

	i = 0;
	while (tknz[i])
	{
		if (tknz[i] == '3')
			return (i);
		i++;
	}
	return (0);
}
