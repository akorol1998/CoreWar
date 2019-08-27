#include "core_war.h"

void		choose_operation_1(t_pack *data, char *op, char **arr, int *res)
{
	if (!ft_strcmp(op, "live"))
	{
		data->arg_len = 1;
		if (((*res) = handle_live(data, arr)))
			(*res) = check_line_tail(data, (arr));
		if (!(*res))
			invalid_argumnet_exit(data, arr, op);
	}
	if (!ft_strcmp(op, "ld"))
	{
		data->arg_len = 2;
		if (((*res) = handle_load(data, arr)))
			(*res) = check_line_tail(data, (arr));
		if (!(*res))
			invalid_argumnet_exit(data, arr, op);
	}
}

void		choose_operation_2(t_pack *data, char *op, char **arr, int *res)
{
	if (!ft_strcmp(op, "zjmp"))
	{
		data->arg_len = 1;
		if (((*res) = handle_live(data, arr)))
			(*res) = check_line_tail(data, (arr));
		if (!(*res))
			invalid_argumnet_exit(data, arr, op);
	}
	if (!ft_strcmp(op, "sti"))
	{
		data->arg_len = 3;
		if (((*res) = handle_sti(data, arr)))
			(*res) = check_line_tail(data, (arr));
		if (!(*res))
			invalid_argumnet_exit(data, arr, op);
	}
}

void		choose_operation_3(t_pack *data, char *op, char **arr, int *res)
{
	if (!ft_strcmp(op, "add"))
	{
		data->arg_len = 3;
		if (((*res) = handle_add(data, arr)))
			(*res) = check_line_tail(data, (arr));
		if (!(*res))
			invalid_argumnet_exit(data, arr, op);
	}
	if (!ft_strcmp(op, "sub"))
	{
		data->arg_len = 3;
		if (((*res) = handle_add(data, arr)))
			(*res) = check_line_tail(data, (arr));
		if (!(*res))
			invalid_argumnet_exit(data, arr, op);
	}
}

void		choose_operation_4(t_pack *data, char *op, char **arr, int *res)
{
	if (!ft_strcmp(op, "and"))
	{
		data->arg_len = 3;
		if (((*res) = handle_and(data, arr)))
			(*res) = check_line_tail(data, (arr));
		if (!(*res))
			invalid_argumnet_exit(data, arr, op);
	}
	if (!ft_strcmp(op, "or"))
	{
		data->arg_len = 3;
		if (((*res) = handle_and(data, arr)))
			(*res) = check_line_tail(data, (arr));
		if (!(*res))
			invalid_argumnet_exit(data, arr, op);
	}
}