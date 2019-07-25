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

typedef struct      s_pack
{
    char			***cmnds;
    char			**labels;
    char			**op;
    char			*name;
    char			*comment;
	char			*buf;
    int				dsc;
	int				l;
	int				w;
	int				arg_len;
	char			*lbl;
	int				idx;
	int				bytes;
}					t_pack;

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
void				args_to_cmnds(t_pack *data, char **arr);

// int					possible_ops(t_pack *data, char **buf, char *word, int i);
// int					label_is_present(char *lbl, t_pack *data);
// int					check_if_label(t_pack *data, int line);
// int					op_bridge(t_pack *data, char *buf, int line, int w);
// void				delete_commented_part_of_the_line(t_pack *data, int	line, int word);
// int					register_sti(char **line, int w, int i);
// void				clean_line(char **line);
// int					check_live_op(char *buf, t_pack *data);
// int					direct_label(t_pack *data, char **line, int i, int arg);
// int					direct_number(t_pack *data, char **line, int w);
// int					indirect_arg(t_pack *data, char **line, int w);
// void				delete_comments(t_pack *data);
// int					check_ld_op(t_pack *data, char *buf);
// int					register_check(char **line, int w);
// int					indirect_validation(t_pack *data, char **line, int w);
// int					third_argument(t_pack *data, char **line, int w);
// int					buf_manager(t_pack *data, char *fst);
// int					read_ld_args(t_pack *data, char **line);
// int					concatenate_buf(t_pack *data);
// int					new_line_func(t_pack *data, char *buf, int line);
// void				replace_elements_in_line(t_pack *data, char **arr, char **arr2);
// int					extract_op(t_pack *data);
// void				pick_word(t_pack *data, char *buf, int line);
// int					coma_count(char **arr, int a);
// void				structurize(t_pack *data);
// int					check_op_live(t_pack *data, char *buf);
// void				final_cut(t_pack *data, char **tab);
// void				clean_unique_data(t_pack *data);
#endif