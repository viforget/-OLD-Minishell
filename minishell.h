/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 14:20:29 by viforget          #+#    #+#             */
/*   Updated: 2019/10/08 08:13:52 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "libft/libft.h"

void	putprompt(char **env);
int		loc_env(char **env, char *str);
void	goenv(char **env);
void	gocd(char *st, char **env);
void	binex(char **av, char *pat);
char	**ft_setenv(char **env, char *name, char *content);
void	ft_unsetenv(char ***env, char **av);

# define ERROR_SETENV  "setenv: Variable name must contain alphanumeric characters."

#endif
