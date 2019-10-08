/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 07:24:33 by viforget          #+#    #+#             */
/*   Updated: 2019/10/08 09:05:20 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**delete_env(char **env, int loc)
{
	int 	i;
	char	**env2;

	i = 0;
	while (env[i])
		i++;
	env2 = ft_memalloc(i);
	ft_putnbr(loc); //HEY
	env2[i - 1] = NULL;
	while(i != loc)
	{
		env2[i - 1] = env[i];
		i--;
	}
	i--;
	while(i >= 0)
	{
		env2[i] = env[i];
		i--;
	}
	ft_strdel(&env[loc]);
	free(env);
	return (env2);
}

void	ft_unsetenv(char ***env, char **av)
{
	int i;
	int loc;

	i = 0;
	while (av[i])
	{
		loc = loc_env(*env, av[i]);
		if (loc != -1)
			*env = delete_env(*env, loc);
		i++;
	}
}
