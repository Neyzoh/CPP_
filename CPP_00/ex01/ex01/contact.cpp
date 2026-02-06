/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <skn.aga108@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 20:11:50 by adammour          #+#    #+#             */
/*   Updated: 2026/02/06 19:43:59 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact(void):first_name(""),last_name(""),nickname(""),phone_number(""),darkest_secret("")
{
}

Contact::~Contact(void)
{
}
void Contact::setfirstname(std::string first_name)
{
    this->first_name = first_name;
}

void Contact::setlastname(std::string last_name)
{
    this->last_name = last_name;
}
void Contact::setnickname(std::string nickname)
{
    this->nickname = nickname;
}
void Contact::setphonenumber(std::string phone_number)
{
 this->phone_number = phone_number;
}
void Contact::setdarkestsecret(std::string darkest_secret)
{
    this->darkest_secret = darkest_secret;
}
std::string Contact::getfirstname(void) const
{
    return this->first_name;
}

std::string Contact::getlastname(void) const
{
    return this->last_name;
}

std::string Contact::getnickname(void) const
{
    return this->nickname;
}
std::string Contact::getphonenumber(void) const
{
    return this->phone_number;
}

void Contact::displayContact(void) const
{
    std::cout << this->first_name << std::endl;
    std::cout << this->last_name << std::endl;
    std::cout << this->nickname << std::endl;
    std::cout << this->phone_number << std::endl;
}
