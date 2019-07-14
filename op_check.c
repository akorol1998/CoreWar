#include "core_war.h"

int			op_bridge(t_pack *data, char *buf, int line, int w)
{

	// 'w' is the index of current string in which the operation is
	// check awether it is possible to 
	ft_printf("%s", buf);
	if (!ft_strcmp(buf, "sti"))
	{
		// for each operation the fucntion and arguments will be different
		return (check_sti_op(data, line, w + 1)); 
	}
	return (1);
}

int			possible_ops(t_pack *data, char **buf, char *word, int i)
{
	int		n;

	n = -1;
	while (!compare_func(*buf, data))
	{
		n = i;
		if (word[++i])
			merge_chars(buf, word[i]);
		else
			break ;
		
	}
	return (n != -1 ? n : 0);
}

int         check_for_being_op(t_pack *data, int line)
{
    int		i;
    char    *buf;

    buf = NULL;
	if(data->tokens[line])
	{
		i = -1;
		while (data->tokens[line][0] && data->tokens[line][0][++i])
		{
			merge_chars(&buf, data->tokens[line][0][i]);
            if (i + 1 >= 2 && i + 1 <= 5)
			{
				i = possible_ops(data, &buf, data->tokens[line][0], i);
				ft_printf("enter [%s]\n", buf);
				if (i)
                {
					check_after_token(data, line, 0, i);
					op_bridge(data, buf, line, 0);
					ft_printf("Checking what is after operation in the element\n");
					free(buf);
                    return (1);
                }
				return (0);
			}
			if (i + 1 > 5)
			{
				free(buf);
				return (0);
			}
		}
	}
	return (0);
}
