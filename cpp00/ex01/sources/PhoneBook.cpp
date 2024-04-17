/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:56:57 by antoda-s          #+#    #+#             */
/*   Updated: 2024/04/17 09:33:54 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_i = 0;
}

PhoneBook::~PhoneBook(void)
{

}

void PhoneBook::add(void)
{
	std::string fname, lname, nname, pnumber, dsecret;

	std::cout << "First Name    :  ";
	std::getline(std::cin, fname, '\n');
	std::cout << "Last Name     :  ";
	std::getline(std::cin, lname, '\n');
	std::cout << "Nickname      :  ";
	std::getline(std::cin, nname, '\n');
	std::cout << "Phone number  :  ";
	std::getline(std::cin, pnumber, '\n');
	std::cout << "Darkest Secret:  ";
	std::getline(std::cin, dsecret, '\n');

	if (fname.length() < 1 || lname.length() < 1 || nname.length() < 1
		|| pnumber.length() < 1 || dsecret.length() < 1)
	{
		std::cout << "\n██████  A CONTACT CANT HAVE EMPTY FIELDS  ███████████\n" << std::endl;
		return ;
	}

	if (!_isStringPrintable(fname) || !_isStringPrintable(lname)
		|| !_isStringPrintable(nname) || !_isStringPrintable(pnumber)
		|| !_isStringPrintable(dsecret))
		{
			std::cout << "\n██████  INVALID CHARACTER INPUT  ██████████████████\n" << std::endl;
			return ;
		}

	this->_contacts[this->_i++ % MAX_CONTACTS] = Contact(fname, lname, nname, pnumber, dsecret);
	//std::cout << CLEAR_SCREEN;
	std::cout << "\n██████  CONTACT SAVED  ██████████████████████████████\n" << std::endl;
}

bool PhoneBook::_isStringPrintable(std::string str)
{
	for (size_t i=0; i < str.size(); i++)
		if (!isprint(str[i]))
			return false;
	return true;
}

void PhoneBook::_displayPhoneBook(void)
{
	std::string field;

	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		std::cout << "|" << std::setw(10) << i << "|";
		field = this->_contacts[i].getFirstName() ;
		std::cout << std::setw(10) << Contact::formatField(field) << "|";
		field = this->_contacts[i].getLastName();
		std::cout << std::setw(10) << Contact::formatField(field) << "|";
		field = this->_contacts[i].getNickName();
		std::cout << std::setw(10) <<Contact::formatField(field) << "|" << std::endl;
	}
}
void PhoneBook::_displayPrompt(void)
{
	std::cout << "Phonebook : Enter your OPTION > ";
}

void PhoneBook::_displayMenu()
{
	std::cout << "██████  Phonebook Options  ██████████████████████████" << std::endl;
	std::cout << std::endl;
	std::cout << "        > ADD" << std::endl;
	std::cout << "        > SEARCH" << std::endl;
	std::cout << "        > EXIT" << std::endl;
	std::cout << std::endl;
	//std::cout << "█████████████████████████████████████████████████████" << std::endl;
	std::cout << "Enter your OPTION > ";
}

void PhoneBook::search(void)
{
	int	id;
	int	maxId;

	//Get the maximum id depending on the number of contacts inserted so far
	maxId = this->_i > 7 ? 7 : this->_i - 1;

	//Display the phonebook table
	this->_displayPhoneBook();
	std::cout << "Select id > ";
	std::cin >> id;
	std::cin.ignore(1000, '\n');

	// Check for input that is not a number
	if (std::cin.fail())
	{
		std::cout << "\n██████  INVALID INPUT  ██████████████████████████████\n" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	}
	else if (id < 0 || id > maxId)
		std::cout << "\n██████  NO CONTACT AT INDEX " << id << "  ██████████████████████\n" << std::endl;
	else
		this->_contacts[id].displayContact();
}