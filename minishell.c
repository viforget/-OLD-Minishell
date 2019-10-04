/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 08:02:11 by viforget          #+#    #+#             */
/*   Updated: 2019/09/24 14:36:24 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	binex(char **av, char *pat)
{
	char	 **path;
	int 	i;

	i = 0;
	path = ft_strsplit(pat , ':');
	while(path[i])
	{
		path[i] = ft_strjoindel(path[i], "/");
		execve(ft_strjoin(path[i], av[0]), av, NULL);
		ft_strdel(&path[i]);
		i++;
	}
	free(path);
	exit(0);
}

void	gocd(char *st, char **env)
{
	chdir(st);
	env[7] = ft_strjoindele("PWD=", getcwd(NULL, 4096));
}

void	goenv(char **env)
{
	int i;

	i = 0;
	while(i < 32)
	{
		ft_putendl(env[i]);
		i++;
	}
}

int 	main(int argc, char **argv, char **env)
{
	char	*str;
	char	**av;
	int i;

	env[7] = ft_strdup(env[7]);
	env[13] = ft_strdup(env[13]);
	i = 0;
	str = ft_memalloc(4097);
	av = NULL;
	//execve(ft_strjoindele("/usr/bin", str), NULL, NULL);
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
		else if (/*check_bin(av) != NULL*/ 1)
		{
			i = fork();
			if (i == 0)
			{
				binex(av, env[13] + 5);
			}
			wait(&i);
		}
	}
	ft_strdel(&str);
}
