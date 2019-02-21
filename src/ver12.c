/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver12.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:48:34 by ehaggon           #+#    #+#             */
/*   Updated: 2019/02/21 19:28:01 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int        cut_figure(char *str)
{
    int i;
    int start;
    int end;
	int number_of_figure;
	char *map;
	char *order;

    end = 0;
	if (validTetriminos1(str) != 1 || validTetriminos2(str) != 1 || validTetriminos4(str) != 1 || validTetriminos5(str) != 1)
		return(0);
	i = sqrt_hash(number_of_hash(str));
	number_of_figure = number_of_hash(str) / 4;
	order = createorder(number_of_figure);
	str = coloring(str);
	map = createmapp(i);
	start = 0;
	while (find_answer(str, map, order, i, -1) != 1)
	{
		free(map);
		i = i + 1;
		map = createmapp(i);
	}
	return(1);
}
