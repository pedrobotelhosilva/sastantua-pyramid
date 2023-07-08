/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotelho <pbotelho@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 19:10:11 by pbotelho          #+#    #+#             */
/*   Updated: 2023/07/08 18:50:12 by pbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int    count_space(int    size)
{
    int	i = 0;
    int	degral = 3;
    int	wt = 1;
    int	temp;
    int	j;
    int	add = 4;
    int	flag = 1;

    while (i < size)
    {
        j = 0;
        while (j < degral)
        {
            temp = wt;
            while (wt)
                wt--;
            wt = temp + 2;
            j++;
        }
        if ((i + 1) % 3 == 0)
	{
		flag--;
		add += 2;
	}
        wt += add;
        degral++;
        i++;
    }
    return ((wt / 2) + flag);
}

void    sasta(int size)
{
    int    i = 0;
    int    degral = 3;
    int    count_s = count_space(size) - 4;
    int    space;
    int    wt = 1;
    int    temp;
    int    add = 4;
    int    j;

    while (i < size - 1)
    {
        j = 0;
        while (j < degral)
        {
            space = 0;
            while (space < count_s)
            {
                write(1, " ", 1);
                space++;
            }
            count_s--;
            write(1, "/", 1);
            temp = wt;
            while (wt)
            {
                write(1, "*", 1);
                wt--;
            }
            wt = temp + 2;
            write(1, "\\\n", 2);
            j++;
        }
        if ((i + 1) % 3 == 0)
           add += 2;
        wt += add;
        count_s -= add / 2;
        degral++;
        i++;
   }
    j = 0;
    while (j < degral)
    {
	    space = 0;
	    while (space < count_s)
	    {
		write(1, " ", 1);
                space++;
            }
            count_s--;
            write(1, "/", 1);
            temp = wt;
	    if (j >= 2)
		wt -= size;
            while (wt)
            {
		if (wt + (size / 2) == (temp / 2) && j >= 2)
		{
			i = 0;
			if (size % 2 == 0)
			{
				if (j > 2)
				{
					while (i < size - 1)
					{
						if (size >= 5 && j - 2 == size / 2 && i == size - 3)
							write(1, "$", 1);
						else
							write (1, "|", 1);
						i++;
					}
				}
				else
				{
					while (i < size - 1)
					{
						write(1, "*", 1);
						i++;
					}
				}
			}
			else
			{
				while (i < size)
				{
					if (size >= 5 && j - 2 == size / 2 && i == size - 2)
						write(1, "$", 1);
					else
						write (1, "|", 1);
					i++;
				}
			}
	    		if (size % 2 == 0)
                		write(1, "*", 1);
		}
                write(1, "*", 1);
		wt--;
            }
            wt = temp + 2;
            write(1, "\\\n", 2);
            j++;
    }

}

int    main(void)
{
	sasta(1);
	sasta(2);
}
