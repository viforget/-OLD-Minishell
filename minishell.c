/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 11:51:54 by viforget          #+#    #+#             */
/*   Updated: 2019/10/08 08:19:34 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**envcpy(char **env)
{
	int	i;
	char **tab;


	i = 0;
	if (env[0] == NULL) //TO CHANGE
		exit(1);
	while (env[i])
		i++;
	tab = ft_memalloc(sizeof(char *) * i + 1);
	tab[i] = NULL;
	i= 0;
	while (env[i])
	{
		tab[i] = ft_strdup(env[i]);
		i++;
	}
	return (tab);
}

char	**read_split(char c)
{
	int 	 nb;
	char 	**av;
	char	*str;

	str = ft_memalloc(4097);
	nb = read(1, str, 4097);
	str[nb - 1] = 0;
	av = ft_strsplit(str, c);
	ft_strdel(&str);
	return (av);
}

int		built_in(char **av, char ***env)
{
	if (ft_strcmp(av[0], "cd") == 0)
		gocd(av[1], *env);
	else if (ft_strcmp(av[0], "env") == 0)
		goenv(*env);
	else if (ft_strcmp(av[0], "setenv") == 0)
		*env = ft_setenv(*env, av[1], av[2]);
	else if (ft_strcmp(av[0], "unsetenv") == 0)
		ft_unsetenv(env, av + 1);
	/*else if (ft_strcmp(av[0], "echo") == 0)
		goecho(env);*/
	else
		return (0);
	return (1);
}

int		main(int ac, char **av, char **env)
{
	int		i;

	env = envcpy(env);
	i = 0;
	av = NULL;
	while (av == NULL || ft_strcmp(av[0], "exit") != 0)
	{
		putprompt(env);
		av = read_split(' ');
		if (built_in(av, &env) == 0)
		{
			i = fork();
			if (i == 0 && ac)
				binex(av, env[loc_env(env, "PATH=")] + 5);
			wait(&i);
		}
	}
}
