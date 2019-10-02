/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 08:02:11 by viforget          #+#    #+#             */
/*   Updated: 2019/09/24 12:22:14 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"

int main(int ac, char **arv, char **env)
{
	char	*str;
	char	**av;
	int 	i;

	str = ft_memalloc(4097);
	i = read(1, str, 4097);
	//str = ft_strjoindele("man ", str);
	str[i - 1] = 0;
	av = ft_strsplit(str, ' ');
	//execve(ft_strjoindele("/usr/bin", str), NULL, NULL);
	ft_putstr(str);
	ft_putchar('|');
	execve("/usr/bin/man", av, env);
}
