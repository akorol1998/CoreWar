#include "core_war.h"

// You must handle the validatoin of all the labels,
// populating array with the label`s names (using cycle of course)
// And only then going again through the tokens array and validating operations and labels
int         label_check(t_pack *data, int line)
{
    int		i;
    int		j;
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
		j = -1;
		while (data->labels[++j])
			;
		data->labels[j] = ft_strdup(buf);
        ft_printf("Realoccing here for [%s]-i-[%d]-arr-[%s]\n", buf, j, data->labels[j]);
		ft_printf("check rest of the element\n");
		check_after_token(data, line, 0, i);
		free(buf);
        return (1);
    }
	if (data->tokens[line][0][i] == '#' && !i)
		return (1);
	free(buf);
	return (0);
}
