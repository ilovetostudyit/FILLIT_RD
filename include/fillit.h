/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:41:42 by ehaggon           #+#    #+#             */
/*   Updated: 2019/02/21 18:58:16 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "../src/libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

//validation of norm
int		validTetriminos1(char *str);
int validTetriminos2(char *str);
int checklinks(char *str, int cnt);
int	validTetriminos4(char *str);
int validTetriminos5(char *str);

//map construction
int        cut_figure(char *str);

//new map construction
char *createmapp(int a);
int number_of_hash(char *str);
int sqrt_hash(int hash);
char *coloring(char *str);
char *createorder(int a);

//placing
int find_answer(char *str, char *map, char *order, int size, int index);
int placing_figure(char *str, char *map, char a, int start, int size);
int cleaning_figure(char *str, char a);
int firstelement(char *str, char a);
int countbefore(char *str, int cntr);
int order_size(char *order);
int placed(char *str, char *map, int start, int size, char a);

#endif
