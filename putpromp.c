#include "minishell.h"

char	*smiley[] = 
{
	"(^_^)",
	"(◕‿◕✿)",
	"(⊙_☉)",
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
	"👻",
	"♥‿♥",
	"ʕᵔᴥᵔʔ",
};

int		findlastslash(char *str)
{
	int i;

	i = ft_strlen(str);
	while(str[i] != '/' && i > 0)
		i--;
	return (i);
}

void	putprompt(char **env)
{
	static int n = 0;

	ft_putstr("\033[31m\033[1m");
	ft_putstr(smiley[n]);
	ft_putstr(" \033[0m\033[32m\033[1m");
	ft_putstr(env[7] + findlastslash(env[7] - 1));
	ft_putstr("\033[0m\033[1m\033[34m ➔ \033[0m");
	n++;
	if (n > 26)
		n = 0;
}
