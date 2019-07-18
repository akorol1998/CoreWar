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
# define HASH(C) (((C) == ('#')) ? 1 : 0)
# define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
# define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

typedef struct      s_pack
{
    char			***tokens;
    char			**labels;
    char			**op;
    char			*name;
    char			*comment;
	char			*buf;
    int				dsc;
	int				line;
	int				w;
	int				arg1;
	int				arg2;
	int				arg3;
    // int				min;
    // int				max;
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
int					possible_ops(t_pack *data, char **buf, char *word, int i);
int					label_is_present(char *lbl, t_pack *data);
int					check_if_label(t_pack *data, int line);
int					op_bridge(t_pack *data, char *buf, int line, int w);
void				delete_commented_part_of_the_line(t_pack *data, int	line, int word);
int					register_sti(char **line, int w, int i);
void				clean_line(char **line);
int					check_live_op(char *buf, t_pack *data);
int					direct_label(t_pack *data, char **line, int i, int arg);
int					direct_number(t_pack *data, char **line, int w);
int					indirect_arg(t_pack *data, char **line, int w);
void				delete_comments(t_pack *data);
int					check_ld_op(t_pack *data, char *buf);
int					register_check(char **line, int w);
int					indirect_validation(t_pack *data, char **line, int w);
int					third_argument(t_pack *data, char **line, int w);
int					buf_manager(t_pack *data, char *fst);
int					read_ld_args(t_pack *data, char **line);
#endif