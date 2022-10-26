/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:55:05 by sqiu              #+#    #+#             */
/*   Updated: 2022/09/21 18:57:55 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_stock_str.h"

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);
char				*ft_strdup(char *src);
int					str_len(char *str);

void	ft_putstr(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	write(1, str, length);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			write(1, "-2147483648", 11);
			return ;
		}
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		ft_putchar('\n');
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		i++;
	}
}

// int     main(int argc, char **argv)
// {
//     ft_show_tab(ft_strs_to_tab(argc, argv));
//     return (0);
// }

// struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
// {
// 	struct s_stock_str	*arr;
// 	struct s_stock_str	*backup;
// 	int					i;

// 	i = 0;
// 	arr = (struct s_stock_str *) malloc((ac + 1) * sizeof(struct s_stock_str));
// 	backup = arr;
// 	if (backup == NULL)
// 		return ('\0');
// 	while (i < ac)
// 	{
// 		arr[i].size = str_len(av[i]);
// 		arr[i].str = av[i];
// 		arr[i].copy = ft_strdup(av[i]);
// 		i++;
// 	}
// 	arr[i].str = 0;
// 	return (arr);
// }

// char	*ft_strdup(char *src)
// {
// 	char	*dupl;
// 	char	*backup;
// 	int		k;

// 	k = 0;
// 	dupl = (char *) malloc ((str_len(src) + 1) * sizeof(char));
// 	backup = dupl;
// 	if (backup == NULL)
// 		return ('\0');
// 	while (src[k])
// 	{
// 		dupl[k] = src[k];
// 		k++;
// 	}
// 	dupl[k] = '\0';
// 	return (dupl);
// }

// int	str_len(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }
