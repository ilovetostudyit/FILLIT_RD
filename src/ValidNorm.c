/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ValidNorm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:41:03 by ehaggon           #+#    #+#             */
/*   Updated: 2019/02/22 15:29:24 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int validTetriminos2(char *str)
{
	int		i;
	int		j;
	int		k;
	int		endline;

	i = 0;
	j = 0;
	k = 0;
	endline = 0;
	while (*str != '\0')
	{
		while (k < 20  && *str != '\0')
		{
			if (*str == '#')
				i++;
			if (*str == '.')
				j++;
			if (*str == '\n')
				endline++;
			if (*str != '#' && *str != '.' && *str != '\n' && *str != '\0')
				return (0);
			k++;
			str++;
		}
		k = 0;
		if (i == 4 && j == 12 && endline == 4)
		{
			i = 0;
			j = 0;
			endline = 0;
		}
		else
			return (-1);
		str++;
	}
	return (1);
}

int checklinks(char *str, int cnt)
{
	int links;

	links = 0;
	if ((cnt % 21) > 3)
		if ((str[cnt-5]) &&  ((str[cnt-5]) == '#'))
			links++;
	if ((str[cnt-1]) &&  ((str[cnt-1]) == '#'))
		links++;

	if ((str[cnt+1]) &&  ((str[cnt+1]) == '#'))
		links++;

	if ((cnt % 21) < 15)
		if ((str[cnt+5]) && ((str[cnt+5]) == '#'))
			links++;
	return(links);
}


int	validTetriminos4(char *str)
{
	int links;
	int cnt;
	int bricks;

	bricks = 0;
	links = 0;
	cnt = 0;
	while (str[cnt] != '\0')
	{
		while (bricks != 20)
		{
			if (str[cnt] == '#')
				links =  links + checklinks(str, cnt);
			cnt++;
			bricks++;
		}
		if (links != 6 && links != 8)
			return(-1);
		links = 0;
		bricks = 0;
		cnt++;
	}
	return(1);
}

int validTetriminos5(char *str)
{
	int i;
	int n;
	int hash;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		n++;
		i++;
	}
	hash = number_of_hash(str);
	hash = hash * 5 + ((hash / 4) - 1);
	if (n != hash)
		return(0);
	else
		return(1);
}
