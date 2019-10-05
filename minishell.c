/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 11:51:54 by viforget          #+#    #+#             */
/*   Updated: 2019/10/05 14:38:29 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	envcpy(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		env[i] = ft_strdup(env[i]);
		i++;
	}
}

int		main(int ac, char **av, char **env)
{
	char	*str;
	int		i;

	envcpy(env);
	i = 0;
	str = ft_memalloc(4097);
	av = NULL;
	while (av == NULL || ft_strcmp(av[0], "exit") != 0)
	{
		putprompt(env);
		i = read(1, str, 4097);
		str[i - 1] = 0;
		av = ft_strsplit(str, ' ');
		if (ft_strcmp(av[0], "cd") == 0)
			gocd(av[1], env);
		else if (ft_strcmp(str, "env") == 0)
			goenv(env);
		else
		{
			i = fork();
			if (i == 0 && ac)
				binex(av, env[loc_env(env, "PATH=")] + 5);
			wait(&i);
		}
	}
	ft_strdel(&str);
}
