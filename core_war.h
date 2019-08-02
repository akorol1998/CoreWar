/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_war.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:08:45 by akorol            #+#    #+#             */
/*   Updated: 2019/07/05 15:10:28 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_WAR_H
# define CORE_WAR_H
# include "libft/ft_printf.h"
# include "errno.h"
# include "fcntl.h"
# include "op.h"
# define BUF_SIZE 1
# define LN_SIZE 10
# define HASH(C) (((C) == ('#')) ? 1 : 0)
# define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
# define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

typedef struct		s_cmnd
{
	int				op;
	int				op_code;
	int				*type_code;
	int				type;
	int				type_c;
	int				arg1;
	int				arg2;
	int				arg3;
	int				size;
}					t_cmnd;

typedef struct      s_pack
{
    char			***cmnds;
    char			**labels;
    char			**op;
    char			*name;
    char			*comment;
	char			*buf;
	char			*file_name;
    int				dsc;
    int				pos;
	int				l;
	int				w;
	int				arg_len;
	char			*lbl;
	int				idx;
	int				bytes;
	int				n;
	t_cmnd			**comm;

}					t_pack;

void				allocate_comm(t_pack *data);
t_cmnd				*allocating_for_comm(t_pack *da);
t_pack				*fill_data(void);
int					read_name(t_pack *data, char *line);
int					read_comment(t_pack *data, char *line);
int					check_after(char *line);
int					read_instructions(t_pack *data);
void				print_tokens(t_pack *data);
void				merge_chars(char **buf, char c);
int					label_check(t_pack *data, int line);
int                 check_for_being_op(t_pack *data, int line);
int					compare_func(char *buf, t_pack *data);
int					check_after_token(t_pack *data, int line, int word, int i);
int					check_sti_op(t_pack *data, int line, int w);
int 				char_in_array(char c);
int					len_arr(char **arr);
int					next_argument(t_pack *data, char **line, int w);
int					valid_invalid_comment(char *buf);
int					label_exists(char *buf, t_pack *data);
int					char_in_array(char c);
void				merge_chars(char **buf, char c);
int					valid_invalid_chars(t_pack *data, char *line);
int					read_labels(t_pack *data, char *line);
int					handle_operation(t_pack *data, char *line);
void				handle_arguments(t_pack *data, char *op, char *line);
void				current_cmnds_position(t_pack *data);
int					register_sti(char *line, int i);
int					direct_number(t_pack *data, char **line, int w);
int					register_check(char *line);
int					indirect_arg(t_pack *data, char **line, int w);
int					indirect_validation(t_pack *data, char *line);
int					direct_label(t_pack *data, char *line);
int					handle_live(t_pack *data, char **arr);
void				clean_the_line(t_pack *data);
int					is_operation(t_pack *data, char *line);
int					operation_valid(t_pack *data, char *op, char *line);
int					possible_ops(t_pack *data, char **buf, char *word, int i);
int					handle_load(t_pack *data, char **arr);
int					check_line_tail(t_pack *data, char **arr);
int					handle_sti(t_pack *data, char **arr);
int					handle_add(t_pack *data, char **arr);
int					handle_and(t_pack *data, char **arr);
int					handle_load_index(t_pack *data, char **arr);
int					handle_aff(t_pack *data, char **arr);
int					handle_store(t_pack *data, char **arr);
void				args_to_cmnds(t_pack *data, char **arr);
char				*delete_comments(char *line);
int					check_file_name(t_pack *data, char *name);
int					writing_to_file(t_pack *data);
int					check_commas(char *op, char *str);
void				execution_code(t_pack *data);
void				and_op_size(t_pack *da, int w);
void				ld_op_size(t_pack *da, int w);
void				sti_op_size(t_pack *da, int w);
void				live_op_size(t_pack *da, int w);
void				st_op_size(t_pack *da, int w);
void				add_sub_op_size(t_pack *da, int w);
void				load_index_op_size(t_pack *da, int w);
void				aff_op_size(t_pack *da, int w);
void				go_through_ops(t_pack *data);
void				and_op_type_code(t_cmnd *cmnd);
void				direct_write(t_pack *da, int w, int	i, int *idx);
int					two_to_power(int a);
void				comm_info_to_file(t_pack *da, int *idx);
int					get_direct_number(t_pack *data, char **line, int w);
char				*get_direct_label(t_pack *data, char *line);
int					search_for_label(t_pack *da, int *idx, char *lbl);
void				write_to_file(t_pack *da, int size, int nbr);
void				indirect_case(t_pack *da, int w, int i, int *idx);
void				just_empty_line(t_pack *data, char *line);
int					get_next_line_core_war(const int fd, char **line, t_pack *data);
int					backwards(char *line);
int					read_assm(t_pack *da);
#endif