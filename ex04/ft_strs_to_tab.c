/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:44:24 by sqiu              #+#    #+#             */
/*   Updated: 2022/09/21 14:49:26 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"
#include <stdio.h>

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dupl;
	char	*backup;
	int		k;

	k = 0;
	dupl = (char *) malloc ((str_len(src) + 1) * sizeof(char));
	backup = dupl;
	if (backup == NULL)
		return ('\0');
	while (src[k])
	{
		dupl[k] = src[k];
		k++;
	}
	dupl[k] = '\0';
	return (dupl);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*arr;
	struct s_stock_str	*backup;
	int					i;

	i = 0;
	arr = (struct s_stock_str *) malloc((ac + 1) * sizeof(struct s_stock_str));
	backup = arr;
	if (backup == NULL)
		return ('\0');
	while (i < ac)
	{
		arr[i].size = str_len(av[i]);
		arr[i].str = av[i];
		arr[i].copy = ft_strdup(av[i]);
		i++;
	}
	arr[i].str = 0;
	return (arr);
}

// int     main(int argc, char **argv)
// {
//     struct s_stock_str *output;
//     int j;

//     output = (struct s_stock_str *)malloc(argc * sizeof(struct s_stock_str));
//     if (output == NULL)
//         return (0);
//     output = ft_strs_to_tab(argc, argv);
//     j = 0;
//     while (j <= argc)
//     {
//         printf("Struktur Nummer: %d\n", j);
//         printf("String size: %d\n", output[j].size);
//         printf("String: %s\n", output[j].str);
//         printf("Kopie: %s\n", output[j].copy);
//         j++;
//     }
//     free(output);
//     return (0);
// }
