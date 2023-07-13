/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:13:15 by iszitoun          #+#    #+#             */
/*   Updated: 2023/07/13 15:17:06 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*count_redirections*/ int count_redi(char *list)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (list[i] && list[i] == '2')
		i++;
	while (list[i])
	{
		if (list[i] >= 52 && list[i] != '6')
			count++;
		else if (list[i] == '6')
			return (count);
		i++;
	}
	return (count);
}

int	count_pipe(char *list)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	check_pipe(list);
	while (list[i])
	{
		if (list[i] == '6')
			count++;
		i++;
	}
	return (count);
}

int	check_pipe(char *list)
{
	int	i;

	i = ft_strlen(list) - 1;
	if (i >= 0)
	{
		if (list[i] == '6')
			lerreurat(6);
		while (list[i] == '2')
			i--;
		if (list[i] == '6')
			lerreurat(6);
	}
	return (1);
}
