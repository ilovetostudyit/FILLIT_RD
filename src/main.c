/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:53:54 by ehaggon           #+#    #+#             */
/*   Updated: 2019/02/21 19:09:20 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int	main(int argc, char **argv)
{
	int fd;
	char buf[550 + 1];
	if (argc != 2)
	{
		ft_putstr("usage");
		ft_putstr("\n");
		return(0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
			ft_putstr("error");
			ft_putstr("\n");
			return(0);
	}
	buf[read(fd, buf, (550 + 1))] = '\0';
	close (fd);

	if (cut_figure(buf) == 0)
	{
		ft_putstr("error");
		ft_putstr("\n");
		return(0);
	}
	return (0);
}
