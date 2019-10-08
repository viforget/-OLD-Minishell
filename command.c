/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 14:02:55 by viforget          #+#    #+#             */
/*   Updated: 2019/10/08 09:44:00 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	binex(char **av, char *pat)
{
	char	**path;
	int		i;

	i = 0;
	path = ft_strsplit(pat, ':');
	while (path[i])
	{
		path[i] = ft_strjoindel(path[i], "/");
		execve(ft_strjoin(path[i], av[0]), av, NULL);
		ft_strdel(&path[i]);
		i++;
	}
	free(path);
	if (av[0][0])
		ft_putstr("minishell: command not found: ");
	ft_putendl(av[0]);
	exit(0);
}

void	gocd(char *st, char **env)
{
	chdir(st);
	if (loc_env(env, "OLDPWD") != -1)
		env[loc_env(env, "OLDPWD=")] = ft_strjoin("OLD", env[loc_env(env, "PWD=")]);
	else if (loc_env(env, "PWD") != -1)
		ft_setenv(env, "OLDPWD", env[loc_env(env, "PWD=")] + 4);
	if (loc_env(env, "PWD") != -1)
		env[loc_env(env, "PWD=")] = ft_strjoindele("PWD=", getcwd(NULL, 4096));
	else
		ft_setenv(env, "PWD", ft_strjoindele("PWD=", getcwd(NULL, 4096)));	
}

void	goenv(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
}
