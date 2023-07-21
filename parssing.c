/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deimos <deimos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:58:57 by iszitoun          #+#    #+#             */
/*   Updated: 2023/07/20 00:22:46 by deimos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	int_commande_var(t_commande *s, char *list, int bool)
{
	s->x = 0;
	s->start = 0;
	s->j = 0;
	s->end = 0;
	s->ptr_num = count_ptr(list, bool);
	s->commande = calloc(sizeof(char *), s->ptr_num + 2);
	s->lock = 0;
	s->lock1 = 1;
	s->tmp = 0;
}

char	**return_commande(char *list, char *str, int bool)
{
	t_commande	*s;
	static int	i;

	s = malloc(sizeof(t_commande));
	int_commande_var(s, list, bool);
	if (bool == 1)
		i = 0;
	expand_erreur(list);
	if (list[i] == '6')
		i++;
	while (list[i] == '2')
		i++;
	while (i + 1 <= ft_strlen(list) && list[i] && s->x <= count_ptr(list, bool))
	{
		if (ft_isredi(list[i]))
		{
			return_file(list, str, bool);
			
		}
		if (list[i] == '3' || list[i] == '0')
		{
			s->j = i;
			s->commande[s->x] = quotes_quotes(str, list, i);
			if (quote_bfr_pipe(str, i, list[i]))
				i = quote_bfr_pipe(str, i, list[i]);
			else if (!quote_bfr_pipe(str, i, list[i]))
				i = s->j;
			if (list[i] == '3')
				i = sec_q_rex(list, i);
			else if (list[i] == '0')
			{
				i = sec_q_rex(list, i);
			}
			s->start = i + 1;
			s->x++;
		}
		if (((list[i] != s->tmp) || list[i + 1] == '6' || !list[i + 1]))
			get_end(s, i, list);
		if ((list[i] == '1') && list[i] != '3' && s->lock && list[i + 1])
			get_start(s, i, list);
		if (i != 0 && i + 1 <= ft_strlen(list) && list[i] == '1' && list[i
			- 1] == '2' && !list[i + 1])
			s->start = i;
		if (!s->lock1 && list[i] != '3' && str[s->start] != '"'
			&& str[s->start] != '\'' && s->end >= s->start)
			get_commande(s, str);
		if (list[i] == '2' && list[i + 1] == '2')
			skip_sp(s, list, i);
		i++;
	}
	return (s->commande);
}

char	**return_file(char *list, char *str, int bool)
{
	char		**files;
	static int	i;
	int			x;
	int			start;
	int			end;

	files = malloc(sizeof(char *) * 100);
	x = 0;
	start = 0;
	end = 0;
	if (bool == 1)
		i = 0;
	if (list[i] == '6')
		i++;
	while (list[i] == '2')
		i++;
	while (list[i] && list[i] != '6' && ft_isredi(list[i]))
	{
		while (ft_isredi(list[i]) || list[i] == '2')
			i++;
		if (list[i] == '1')
		{
			start = i;
			while (list[i] != '2' && list[i] && !ft_isredi(list[i]))
				i++;
			if (i > start)
				end = i - 1;
			files[x] = ft_substr(str, start, end - start + 1);
			x++;
		}
		i++;
	}
	return (files);
}

char	*quotes_quotes(char *str, char *tknz, int start)
{
	int		i;
	int		j;
	int		last;
	char	*ptr;
	int		numoq;

	i = 0;
	last = 0;
	numoq = 0;
	ptr = malloc(sizeof(char) * 100);
	if (tknz[start] == '3')
	{
		i = frst_q_rex(tknz, start);
		last = sec_q_rex(tknz, sec_q(tknz)) + 1;
		numoq = num_of_q(tknz, start);
	}
	else if (tknz[start] == '0')
	{
		i = frst_q_rex(tknz, start);
		last = sec_q_rex(tknz, sec_s_q(tknz)) + 1;
		numoq = num_of_s_q(tknz, start);
	}
	j = 0;
	while (i < last && numoq % 2 == 0)
	{
		if (tknz[i] == '0' || tknz[i] == '3')
			i++;
		if (tknz[i] == '1')
		{
			ptr[j] = str[i];
			i++;
			j++;
		}
		if (!tknz[i] || tknz[i] == '2' || tknz[i] == '6')
		{
			ptr[j] = '\0';
			return (ptr);
		}
	}
	if ((tknz[i] == '6' && i > sec_q_rex(tknz, sec_q(tknz))))
	{
		ptr[j] = '\0';
		return (ptr);
	}
	if (i == sec_q_rex(tknz, sec_q(tknz) + 2) && sec_q_rex(tknz, sec_q(tknz))
		+ 1 > 0)
	{
		ptr[j] = '\0';
		return (ptr);
	}
	return (0);
}

char	*fill_var(t_env *s, t_commandes *m, int i, int j)
{
	char	*var;
	int		x;

	var = malloc(sizeof(char) * s->env_len + 1);
	x = 0;
	j++;
	while (m->commande[i][j] && m->commande[i][j] != ' ')
	{
		var[x] = m->commande[i][j];
		j++;
		x++;
	}
	var[x] = '\0';
	return (var);
}
