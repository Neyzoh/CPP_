/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <skn.aga108@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 20:27:47 by adammour          #+#    #+#             */
/*   Updated: 2026/02/06 21:23:41 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <stdlib.h>
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook(void): idx(0),nb_contact(0) 
{
}

PhoneBook::~PhoneBook(void)
{
}

void PhoneBook::addContact(Contact contact)
{
    if (nb_contact < 8)
    {
        this->nb_contact++;
        this->idx = nb_contact;
        this->tab[this->idx - 1] = contact;
    }
    else
    {
        for (int i = 0; i < nb_contact - 1; i++)
        {
            this->tab[i] = this->tab[i + 1];
            this->idx = i - 1;
        }
        this->idx = 8;
        this->tab[this->idx - 1] = contact;
    }
}

std::string truncate10(const std::string& input) 
{
    if (input.size() <= 10) 
        return input;                // rien à couper
    return input.substr(0, 9) + ".";      // on garde les 10 premiers chars
    
}

void PhoneBook::searchContact(void)
{
    std::string input;

    if (nb_contact == 0) {
        std::cout << "Le repertoire est vide" << std::endl;
        return;
    }

    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|" << "     index"
              << "|" << "first name"
              << "|" << " last name"
              << "|" << " nickname"
              << "|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    for (int i = 0; i < nb_contact; i++)
    {
        std::cout << "|"
                  << std::setw(10) << i + 1
                  << "|" << std::setw(10) << truncate10(this->tab[i].getfirstname())
                  << "|" << std::setw(10) << truncate10(this->tab[i].getlastname())
                  << "|" << std::setw(10) << truncate10(this->tab[i].getnickname())
                  << "|" << std::endl;
    }
    std::cout << "---------------------------------------------" << std::endl;

    std::cout << "Indiquer l'index du contact :";
    if (!getline(std::cin, input))
        return ;
    int index = atoi(input.c_str());
    if (index > 8 || index < 1)
    {
        std::cout << "Indice du contact incorrect" << std::endl;
        return;
    }
    this->tab[index - 1].displayContact();
}