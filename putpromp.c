/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpromp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 14:33:31 by viforget          #+#    #+#             */
/*   Updated: 2019/10/06 11:53:49 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*g_smiley[] =
{
	"(^_^)",
	"(◕‿◕✿)",
	"(⊙_☉ )",
	"¯\\_(ツ)_/¯",
	"( ˘ ³˘)♥",
	"ಠᴗಠ",
	"｡^‿^｡",
	"(⁎˃ᆺ˂)",
	"(ᴗ˳ᴗ)",
	"( ͡° ͜ʖ ͡°)",
	"(ᗒᗣᗕ)՞",
	"◔_◔",
	"(ﾉﾟοﾟ)ﾉ",
	"(●_●)",
	"(ဖ෴ ဖ)⚔ (စ__စ )",
	"(ﾉ◕ヮ◕)ﾉ",
	"♨ _♨ ",
	"[¬º-°]¬",
	"(~‾▿‾)~",
	"V●ᴥ●V",
	"(ノಠ益ಠ)ノ",
	"ヽ(。_°)ノ",
	"꒰⑅•ᴗ•⑅ ꒱",
	"(ʘ ᗝ ʘ)",
	"👻 ",
	"♥‿♥",
	"ʕᵔᴥᵔʔ",
};

int		findsl(char *str)
{
	int i;

	i = ft_strlen(str);
	while (str[i] != '/' && i > 0)
		i--;
	return (i);
}

void	putprompt(char **env)
{
	static int n = 0;

	ft_putstr("\033[31m\033[1m");
	ft_putstr(g_smiley[n]);
	ft_putstr(" \033[0m\033[32m\033[1m");
	ft_putstr(env[loc_env(env, "PWD=")] + findsl(env[loc_env(env, "PWD=")]) + 1);
	ft_putstr("\033[0m\033[1m\033[34m ➔ \033[0m");
	n++;
	if (n > 26)
		n = 0;
}
