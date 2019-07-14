#include "core_war.h"

int			comment_check(t_pack *data, int line)
{
	int		i;
    char    *buf;

    buf = NULL;
	i = -1;
	if(data->tokens[line])
	{
		while (data->tokens[line][0] && data->tokens[line][0][++i] && 
        char_in_array(data->tokens[line][0][i]) &&
        data->tokens[line][0][i] != LABEL_CHAR)
			merge_chars(&buf, data->tokens[line][0][i]);
	}
    if (data->tokens[line][0][i] == LABEL_CHAR)
    {
		i = -1;
		while (data->labels[++i])
			;
		data->labels[i] = ft_strdup(buf);
        ft_printf("Realoccing here for [%s]-i-[%d]-arr-[%s]\n", buf, i, data->labels[i]);
		ft_printf("check rest of the element\n");
		free(buf);
        return (1);
    }
	free(buf);
	return (0);
}