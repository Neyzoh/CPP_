/* ************************************************************************** */
/*             https://profile-v3.intra.42.fr/                                                               */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <skn.aga108@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 19:55:31 by adammour          #+#    #+#             */
/*   Updated: 2026/02/06 19:45:00 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include <iostream>

class PhoneBook
{
    private:
        Contact tab[8];
        int idx;
        int nb_contact;

    public:
        PhoneBook(void);
        ~PhoneBook(void);
        void addContact(Contact contact);
        void searchContact(void);
};