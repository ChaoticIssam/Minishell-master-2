/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:13:12 by iszitoun          #+#    #+#             */
/*   Updated: 2023/07/14 10:16:53 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isredi(char c)
{
	if (c == '9' || c == '8' || c == '4' || c == '5')
		return (1);
	return (0);
}

int	ft_isspecial(char c)
{
	return (c == '6' || c == '4' || c == '3');
}

int	expand_erreur(char *list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		if (ft_isredi(list[i]) == 1 && ft_isredi(list[i + 1]) == 1)
			lerreurat(9);
		i++;
	}
	return (1);
}

int	quote_bfr_pipe(char *str, int i, char q)
{
	int	count;

	count = 0;
	while (str[i] != '|' && str[i])
	{
		if (str[i] == q)
			count++;
		if (count % 2 == 0 && (str[i + 1] == '|' || !str[i + 1]))
		{
			while (str[i] && i > 0 && (str[i] == ' ' || str[i] == '\t'))
				i--;
			return (i);
		}
		i++;
	}
	return (0);
}

/*count_strings_in_commandes*/ int count_ptr(char *list, int bool)
{
	int			count;
	static int	i;
	static int	j;
	int			len;

	if (bool == 1)
		i = 0;
	if (bool == 0)
		i = j;
	count = 0;
	len = ft_strlen(list);
	while (list[i] && list[i] == '2')
		i++;
	while (i >= 0 && i + 1 <= len && list[i])
	{
		if (list[i] == '3')
		{
			i = sec_q_rex(list, sec_q(list)) + 1;
			count++;
		}
		if (list[i] == '0')
		{
			i = sec_q_rex(list, sec_s_q(list)) + 1;
			count++;
		}
		if (list[i] == '1' && (list[i + 1] == '2' || !list[i + 1])
			&& list[i] != '6')
			count++;
		if (list[i] == '1' && list[i + 1] >= 52)
			count++;
		else if (list[i] >= 52)
		{
			i++;
			if (bool == 1)
				j = i;
			return (count);
		}
		i++;
	}
	return (count);
}