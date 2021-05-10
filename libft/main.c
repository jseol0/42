/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 22:30:47 by jseol             #+#    #+#             */
/*   Updated: 2021/05/11 00:23:38 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
char		*strrchr(const char *s, int c)
{
    size_t i;

    i = ft_strlen(s);

    while (i >= 0)
    {
        if (s[i] == c)
            return ((char *)&s[i]);
        --i;
    }

    return (0);
}


int main() {
  char str[] = "This is a sample string";
  char* pch;
  pch = ft_strrchr(str, 's');
  printf("Last occurence of 's' found at %d \n", pch - str + 1);
  return 0;
}
