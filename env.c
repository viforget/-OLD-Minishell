/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 12:19:34 by viforget          #+#    #+#             */
/*   Updated: 2019/10/08 06:49:36 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int 	checkenvname(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (!(str[i] == '_' || ft_isalpha(str[i]) == 1))
			return (0);
		i++;
	}
	return (1);
}

char	**addlineenv(char **env, char *str)
{
	char **env2;
	int i;
	int j;

	i = 0;
	while(env[i])
		i++;
	j = i;
	env2 = ft_memalloc(sizeof(char *) * i + 2);
	env2[i + 1] = NULL;
	env2[i] = str;
	while(i > 0)
	{
		i--;
		env2[i] = env[i];
	}
	free(env);
	return(env2);
}

char	**ft_setenv(char **env, char *name, char *content)
{
	char *str;

	if (checkenvname(name) == 1)
	{
		/*if (loc_env(env, name) != -1)
			unsetenv(env, name);*/
		str = ft_strjoindel(ft_strjoin(name, "="), content);
		env = addlineenv(env, str);
	}
	else 
		ft_putendl(ERROR_SETENV);
	return (env);
}

int		loc_env(char **env, char *str)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], str, ft_strlen(str)) == 0)
			return (i);
		i++;
	}
	return (-1);
}
