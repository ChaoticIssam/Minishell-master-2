/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toke_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:40:52 by iszitoun          #+#    #+#             */
/*   Updated: 2023/07/13 15:11:12 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fill_the_rest(t_tokenz *m, char *str)
{
	if (str[m->i] == '|')
		m->array[m->j] = '6';
	else if (str[m->i] == '>')
		m->array[m->j] = '5';
	else if (str[m->i] == '<')
		m->array[m->j] = '4';
	else if (str[m->i] == '"')
		dquotes_tokenz(m, str);
	else if (str[m->i] == '\'')
		squotes_tokenz(m, str);
	else if (str[m->i] == ' ' || str[m->i] == '\t' || str[m->i] == '\v')
		m->array[m->j] = '2';
	else
		m->array[m->j] = '1';
}

void	var_def(t_tokenz *m, char *str)
{
	m->array = NULL;
	m->i = 0;
	m->j = 0;
	m->count = 0;
	m->array = calloc(sizeof(char), ft_strlen(str) + 1);
}

char	*toknz_list(char *str)
{
	t_tokenz	*m;

	m = malloc(sizeof(t_tokenz));
	var_def(m, str);
	while (str[m->i])
	{
		if (str[m->i] == '>' && str[m->i + 1] == '>')
		{
			m->array[m->j] = '9';
			m->i++;
		}
		else if (str[m->i] == '<' && str[m->i + 1] == '<')
		{
			m->array[m->j] = '8';
			m->i++;
		}
		fill_the_rest(m, str);
		m->i++;
		m->j++;
	}
	m->array[m->i] = '\0';
	return (m->array);
}
