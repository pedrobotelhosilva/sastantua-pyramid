/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotelho <pbotelho@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 19:10:11 by pbotelho          #+#    #+#             */
/*   Updated: 2023/07/09 04:44:37 by pbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	put_n_char(char c, int n, char c2, int n2)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(c);
		i++;
	}
	i = 0;
	while (i < n2)
	{
		ft_putchar(c2);
		i++;
	}
}

int	count_space(int size, int floor, int add, int fix)
{
	int	wt;
	int	i;
	int	j;

	i = 0;
	wt = 1;
	while (i < size)
	{
		j = 0;
		while (j < floor)
		{
			wt += 2;
			j++;
		}
		if ((i + 1) % 3 == 0)
		{
			fix--;
			add += 2;
		}
		wt += add;
		floor++;
		i++;
	}
	return ((wt / 2) + fix);
}

void	put_door(int size, int j, int i)
{
	if (size % 2 == 0)
	{
		while (++i, i < size - 1 && j > 2)
		{
			if (size >= 5 && j - 2 == size / 2 && i == size - 3)
				write(1, "$", 1);
			else
				write (1, "|", 1);
		}
		if (j <= 2)
			put_n_char('*', size - 1, 0, 0);
		ft_putchar('*');
	}
	else
	{
		while (++i, i < size)
		{
			if (size >= 5 && j - 2 == size / 2 && i == size - 2)
				write(1, "$", 1);
			else
				write (1, "|", 1);
		}
	}
}

void	put_base(int floor, int count_s, int size, int wt)
{
	int	temp;
	int	j;

	j = -1;
	while (++j, --floor, floor && size > 0)
	{
		put_n_char(' ', count_s--, '/', 1);
		temp = wt;
		if (j >= 2)
			wt -= size;
		while (wt)
		{
			if (wt + (size / 2) == (temp / 2) && j >= 2)
				put_door(size, j, -1);
			ft_putchar('*');
			wt--;
		}
		put_n_char('\\', 1, '\n', 1);
		wt = temp + 2;
	}
}

void	sastantua(int size)
{
	int	counter[4];
	int	count_s;
	int	add;

	add = 4;
	counter[3] = 1;
	counter[2] = 2;
	counter[0] = -1;
	count_s = count_space(size, 3, 4, 1) - 4;
	while (++counter[0], ++counter[2], counter[0] < size - 1)
	{
		counter[1] = -1;
		while (++counter[1], counter[1] < counter[2])
		{
			put_n_char(' ', count_s--, '/', 1);
			put_n_char('*', counter[3], 0, 0);
			put_n_char('\\', 1, '\n', 1);
			counter[3] += 2;
		}
		if ((counter[0] + 1) % 3 == 0)
			add += 2;
		count_s -= add / 2;
		counter[3] += add;
	}
	put_base(counter[2] + 1, count_s, size, counter[3]);
}

int	main(void)
{
	sastantua(0);
	sastantua(1);
	sastantua(2);
	sastantua(3);
	sastantua(4);
	sastantua(5);
	sastantua(6);
	sastantua(7);
	sastantua(8);
	sastantua(9);
}
