/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_failure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:57:58 by asyani            #+#    #+#             */
/*   Updated: 2025/03/05 10:58:09 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

/**
 * exit_failure _ function to exit error
 * @str: the string error
 */
void	exit_failure(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(2, "Error: ", 7);
	write(2, str, 1);
	exit(1);
}
