/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   localiseenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:14:00 by viforget          #+#    #+#             */
/*   Updated: 2019/10/05 14:33:21 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	return (0);
}
