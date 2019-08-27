#include "core_war.h"

void		choose_operation_5(t_pack *data, char *op, char **arr, int *res)
{
	if (!ft_strcmp(op, "xor"))
	{
		data->arg_len = 3;
		if (((*res) = handle_and(data, arr)))
			(*res) = check_line_tail(data, (arr));
		if (!(*res))
			invalid_argumnet_exit(data, arr, op);
	}
	if (!ft_strcmp(op, "ldi"))
	{
		data->arg_len = 3;
		if (((*res) = handle_load_index(data, arr)))
			(*res) = check_line_tail(data, (arr));
		if (!(*res))
			invalid_argumnet_exit(data, arr, op);
	}
}

void		choose_operation_6(t_pack *data, char *op, char **arr, int *res)
{
	if (!ft_strcmp(op, "fork"))
	{
		data->arg_len = 1;
		if (((*res) = handle_live(data, arr)))
			(*res) = check_line_tail(data, (arr));
		if (!(*res))
			invalid_argumnet_exit(data, arr, op);
	}
	if (!ft_strcmp(op, "lld"))
	{
		data->arg_len = 2;
		if (((*res) = handle_load(data, arr)))
			(*res) = check_line_tail(data, (arr));
		if (!(*res))
			invalid_argumnet_exit(data, arr, op);
	}
}

void		choose_operation_7(t_pack *data, char *op, char **arr, int *res)
{
	if (!ft_strcmp(op, "lldi"))
	{
		data->arg_len = 3;
		if (((*res) = handle_load_index(data, arr)))
			(*res) = check_line_tail(data, (arr));
		if (!(*res))
			invalid_argumnet_exit(data, arr, op);
	}
	if (!ft_strcmp(op, "lfork"))
	{
		data->arg_len = 1;
		if (((*res) = handle_live(data, arr)))
			(*res) = check_line_tail(data, (arr));
		if (!(*res))
			invalid_argumnet_exit(data, arr, op);
	}
}

void		choose_operation_8(t_pack *data, char *op, char **arr, int *res)
{
	if (!ft_strcmp(op, "aff"))
	{
		data->arg_len = 1;
		if (((*res) = handle_aff(data, arr)))
			(*res) = check_line_tail(data, (arr));
		if (!(*res))
			invalid_argumnet_exit(data, arr, op);
	}
	if (!ft_strcmp(op, "st"))
	{
		data->arg_len = 2;
		if (((*res) = handle_store(data, arr)))
			(*res) = check_line_tail(data, (arr));
		if (!(*res))
			invalid_argumnet_exit(data, arr, op);
	}
}
