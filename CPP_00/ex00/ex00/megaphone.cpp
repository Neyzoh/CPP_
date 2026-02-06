/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <adammour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 19:33:11 by adammour          #+#    #+#             */
/*   Updated: 2026/01/31 19:50:48 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    if (ac > 1)
    {
        for (int i = 1; i < ac; i++)
        {
            for (int j = 0; av[i][j]; j++)
                av[i][j] = (char)toupper(av[i][j]);
            std::cout << av[i];
            if(i != ac - 1)
                std::cout << " ";
        }
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return(0);
}