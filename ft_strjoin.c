/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaidi <mousaidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:30:07 by mousaidi          #+#    #+#             */
/*   Updated: 2026/11/03 19:42:24 by mousaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	counting_length(int size, char **strs)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	inserting_sep(int count, char *ptr, char *sep)
{
	int	j;

	j = 0;
	while (sep[j] != '\0')
	{
		ptr[count] = sep[j];
		count++;
		j++;
	}
	return (count);
}

void	joining_strings(int size, char *ptr, char **strs, char *sep)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			ptr[count] = strs[i][j];
			count++;
			j++;
		}
		if (i < size - 1)
			count = inserting_sep(count, ptr, sep);
		i++;
	}
	ptr[count] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		count;
	int		i;
	char	*ptr;

	count = 0;
	if (size <= 0)
	{
		ptr = malloc(sizeof(char) * 1);
		if (ptr == NULL)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	count = counting_length(size, strs);
	i = 0;
	while (sep[i] != '\0')
		i++;
	ptr = malloc(count + (i * (size - 1)) + 1);
	if (ptr == NULL)
		return (NULL);
	joining_strings(size, ptr, strs, sep);
	return (ptr);
}
/*#include <stdio.h>
int main(void)
{
	char *strs[] = {"Hello", "world", "from", "C"};
	char *sep = " - ";
	char *result;


	result = ft_strjoin(4, strs, sep);

	printf("%s\n", result);
	free(result);

	return (0);
}*/
