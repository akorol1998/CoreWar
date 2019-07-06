/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 11:29:40 by akorol            #+#    #+#             */
/*   Updated: 2019/01/12 20:07:33 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

char	*ft_cley(char const *s1, char const *s2)
{
	size_t		i;
	char		*new;
	size_t		j;
	size_t		a;
	size_t		b;

	if (s1 == NULL || s2 == NULL)
		return (0);
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	if (!(new = ft_strnew(a + b)))
		return (NULL);
	i = -1;
	j = -1;
	while (++i < a)
		new[i] = s1[i];
	while (++j < b)
		new[j + i] = s2[j];
	return (new);
}

t_node	*ft_update_vol2(t_node *temp, t_node **head, char *buf, const int desc)
{
	t_node *p;

	temp = (t_node*)malloc(sizeof(t_node));
	temp->ds = desc;
	temp->data = ft_strdup(buf);
	temp->next = NULL;
	if (*head == NULL)
		*head = temp;
	else
	{
		p = *head;
		while (p->next)
			p = p->next;
		p->next = temp;
	}
	return (temp);
}

t_node	*ft_update_list(t_node **head, char *buf, const int desc)
{
	t_node	*temp;
	char	*trash;

	temp = *head;
	while (temp != NULL)
	{
		if (temp->ds == desc)
		{
			trash = temp->data;
			temp->data = ft_cley(trash, buf);
			free(trash);
			return (temp);
		}
		temp = temp->next;
	}
	return (ft_update_vol2(temp, head, buf, desc));
}

int		ft_part_2(t_node *head, char **line, const int desc)
{
	char	*pointer;

	if (BUFF_SIZE <= 0 || line == NULL)
		return (-1);
	while (head && head->ds != desc)
		head = head->next;
	if (head && head->data && ft_strchr(head->data, '\n'))
	{
		*line = ft_strsub(head->data, 0, ft_strchr(head->data,
				'\n') - head->data);
		pointer = ft_strdup(ft_strchr(head->data, '\n') + 1);
		free(head->data);
		head->data = pointer;
		return (1);
	}
	if (head && head->data && ft_strlen(head->data))
	{
		*line = ft_strdup(head->data);
		free(head->data);
		head->data = NULL;
		return (1);
	}
	else
		return (0);
}

int		get_next_line(const int d, char **line)
{
	static	t_node	*head;
	int				r;
	char			buf[BUFF_SIZE + 1];
	char			*pointer;
	t_node			*arr;

	while (line && (r = read(d, buf, BUFF_SIZE)) && BUFF_SIZE > 0)
	{
		if (r < 0 || d < 0)
			return (-1);
		buf[r] = '\0';
		arr = ft_update_list(&head, buf, d);
		if (ft_strchr(arr->data, '\n'))
		{
			*line = ft_strsub(arr->data, 0, ft_strchr(arr->data,
					'\n') - arr->data);
			pointer = ft_strdup(ft_strchr(arr->data, '\n') + 1);
			free(arr->data);
			arr->data = pointer != NULL ? pointer : NULL;
			return (1);
		}
	}
	return (ft_part_2(head, line, d));
}
