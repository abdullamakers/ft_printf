/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdualsh <abdualsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 00:33:19 by abdualsh          #+#    #+#             */
/*   Updated: 2025/12/07 13:01:53 by abdualsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <stdio.h>

void print_numbers(int count, ...)
{
    va_list args;              // create list
    va_start(args, count);     // start reading after "count"

    for (int i = 0; i < count; i++)
    {
        int x = va_arg(args, int);   // get next number
        printf("%d ", x);
    }

    va_end(args);              // finish
}

int main()
{
    print_numbers(3, 10, 20, 30);
    return 0;
}
