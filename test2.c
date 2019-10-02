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

#include <unistd.h>
#include "libft/libft.h"

int main()
{
	char	*str;
	char	**av;
	int i;

	i = 0;
	str = ft_memalloc(4097);
	av = NULL;
	//execve(ft_strjoindele("/usr/bin", str), NULL, NULL);
	while (av == NULL || ft_strcmp(av[1], "exit") != 0)
	{
		ft_putstr("$>");
		i = read(1, str, 4097);
		str[i - 1] = 0;
		av = ft_strsplit(str, ' ');
		if (/*check_bin(av) != NULL*/ 1)
		{
			i = fork();
			if (i == 0)
			{
				execve(ft_strjoin("/bin/", av[0]), av, NULL);
			}
			wait(&i);
		}
	}
}
