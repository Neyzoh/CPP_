/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adammour <skn.aga108@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 20:11:57 by adammour          #+#    #+#             */
/*   Updated: 2026/02/02 14:08:01 by adammour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Contact 
{
    private : 
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

    public :
        Contact(void);
        ~Contact(void);
        void setfirstname(std::string first_name);
        void setlastname(std::string last_name);
        void setnickname(std::string nickname);
        void setphonenumber(std::string phone_number);
        void setdarkestsecret(std::string darkest_secret);

        std::string getfirstname(void) const;
        std::string getlastname(void) const;
        std::string getnickname(void) const;
        std::string getphonenumber(void) const;

        void displayContact(void) const;
};


