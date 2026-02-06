/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <skn.aga108@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 20:48:43 by adammour          #+#    #+#             */
/*   Updated: 2026/02/06 19:54:26 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include "phonebook.hpp"

int main(int ac, char **av)
{
    std::string input;
    PhoneBook phonebook;
    (void)ac;
    (void)av;

    while (true)
    {
        std::cout << "Veuillez selectionner une des options suivantes : 'ADD', 'SEARCH', 'EXIT')" << std::endl;
        getline(std::cin, input);
        if (input == "ADD" )
        {
            std::string firstname;
            std::cout << "First name :";
            if(!getline(std::cin, firstname))
                break;
            std::string lastname;
            std::cout << "Last name :";
            if(!getline(std::cin, lastname))
                break;
            std::string nickname;
            std::cout << "Nickname :";
            if(!getline(std::cin, nickname))
                break;
            std::string phonenumber;
            std::cout << "Phone number :";
            if(!getline(std::cin, phonenumber))
                break;
            std::string darkestsecret;
            std::cout << "Darkest secret :";
            if(!getline(std::cin, darkestsecret))
                break;
            if (!firstname.empty()
            && !lastname.empty()
            && !phonenumber.empty()
            && !nickname.empty()
            && !darkestsecret.empty())
            {
            Contact contact;
            contact.setfirstname(firstname);
            contact.setlastname(lastname);
            contact.setnickname(nickname);
            contact.setphonenumber(phonenumber);
            contact.setdarkestsecret(darkestsecret);
            phonebook.addContact(contact);
            }
            else
                std::cout << "Vous devez remplir tout les champs" << std::endl;
        }
        else if (input == "SEARCH")
            phonebook.searchContact();
        else if (input == "EXIT")
            exit(EXIT_SUCCESS);
    }
}