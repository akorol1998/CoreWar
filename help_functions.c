#include "core_war.h"

int			len_arr(char **arr)
{
	int		i;

	i = -1;
	while (arr[++i])
		;
	return (i);
}

int			compare_func(char *buf, t_pack *data)
{
	int		i;

	i = -1;
	while (data->op[++i])
		if (!ft_strcmp(data->op[i], buf))
			return (0);
	return (1);
}

void         merge_chars(char **buf, char c)
{
    char    *del;
    char    *buf2;

    if (!(*buf))
    {
        (*buf) = ft_strnew(1);
        (*buf)[0] = c;
    }
    else
    {
        buf2 = ft_strnew(1);
        buf2[0] = c;
        del = (*buf);
        (*buf) = ft_strjoin((*buf), buf2);
        free(del);
        free(buf2);
    }
}

int         char_in_array(char c)
{
    int     i;

    i = -1;
    while (LABEL_CHARS[++i])
        if (LABEL_CHARS[i] == c)
            return (1);
    return (0);
}

void		check_after_token(t_pack *data, int line, int word, int i)
{
	int		j;
	char	*buf;

	j = i;
	buf = NULL;
	while (data->tokens[line][word][++j])
		merge_chars(&buf, data->tokens[line][word][i]);
	if (buf)
	{
		if (!data->buf)
			data->buf = buf;
		else
		{
			free(data->buf);
			data->buf = buf;
		}
	}
}
