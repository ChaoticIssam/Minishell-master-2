/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_parss.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:18:51 by iszitoun          #+#    #+#             */
/*   Updated: 2023/07/13 15:19:45 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_len(t_commandes *m)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (m->commande[i] && m->commande[i][j])
	{
		if (m->commande[i][j] == '$')
		{
			j++;
			while (m->commande[i][j] && m->commande[i][j] != ' ')
			{
				count++;
				j++;
			}
			if (m->commande[i][j] == ' ' || !m->commande[i][j])
				return (count);
		}
		i++;
	}
	return (0);
}

char	*var_gett(char **env, int i)
{
	int		j;
	char	*envv;

	envv = malloc(sizeof(char) * 100);
	j = 0;
	while (env[i][j])
	{
		if (env[i][j] == '=')
			return (envv);
		envv[j] = env[i][j];
		j++;
	}
	return (0);
}

char	*get_path(char **env, int i)
{
	int		j;
	int		x;
	char	*envr;

	envr = malloc(sizeof(char) * 100);
	j = 0;
	x = 0;
	while (env[i][j])
	{
		if (env[i][j] == '=')
		{
			j++;
			while (env[i][j])
			{
				envr[x] = env[i][j];
				x++;
				j++;
			}
			if (!env[i][j])
				return (envr);
		}
		j++;
	}
	return (0);
}

char	*fill_path(char **env, t_env *s)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	j = 0;
	path = malloc(sizeof(char) * 100);
	while (env[i][j] && env[i][j] != '=')
		j++;
	j++;
	while (env[i])
	{
		if (!ft_strncmp(s->var, var_gett(env, i)))
		{
			path = get_path(env, i);
			return (path);
		}
		i++;
	}
	return (NULL);
}
