/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:23:45 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/05/01 18:08:39 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_num_len(int n)
{
	size_t	num_len;

	if (n == 0)
		return (1);
	num_len = 0;
	if (n < 0)
		num_len++;
	while (n != 0)
	{
		num_len++;
		n /= 10;
	}
	return (num_len);
}

static void	fill_result(int n, int neg, char *result, size_t num_len)
{
	int	digit;

	while (n != 0)
	{
		if (neg)
			digit = -(n % 10);
		else
			digit = n % 10;
		result[--num_len] = digit + '0';
		n /= 10;
	}
	if (neg)
		result[0] = '-';
}

char	*ft_itoa(int n)
{
	size_t	num_len;
	int		neg;
	char	*result;

	neg = n < 0;
	num_len = get_num_len(n);
	result = malloc(sizeof(char) * (num_len + 1));
	if (!result)
		return (NULL);
	result[num_len] = '\0';
	if (n == 0)
		result[0] = '0';
	else
		fill_result(n, neg, result, num_len);
	return (result);
}
