/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:56:57 by antoda-s          #+#    #+#             */
/*   Updated: 2024/04/08 20:00:31 by antoda-s         ###   ########.fr       */
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

	std::cout << "First Name: ";
	std::getline(std::cin, fname, '\n');
	std::cout << "Last Name: ";
	std::getline(std::cin, lname, '\n');
	std::cout << "Nickname: ";
	std::getline(std::cin, nname, '\n');
	std::cout << "Phone number: ";
	std::getline(std::cin, pnumber, '\n');
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, dsecret, '\n');

	if (fname.length() < 1 || lname.length() < 1 || nname.length() < 1
		|| pnumber.length() < 1 || dsecret.length() < 1)
	{
		std::cout << "\n\t-- A CONTACT CANT HAVE EMPTY FIELDS --\n" << std::endl;
		return ;
	}
	this->_contacts[this->_i++ % MAX_CONTACTS] = Contact(fname, lname, nname, pnumber, dsecret);
	std::cout << CLEAR_SCREEN;
	std::cout << "\n\t---- CONTACT SAVED ----\n" << std::endl;
}

void PhoneBook::_display(void)
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

void PhoneBook::search(void)
{
	int	id;
	int	maxId;

	//Get the maximum id depending on the number of contacts inserted so far
	maxId = this->_i > 7 ? 7 : this->_i - 1;

	//Display the phonebook table
	this->_display();
	std::cout << "Entry id > ";
	std::cin >> id;
	std::cin.ignore(1000, '\n');

	// Check for input that is not a number
	if (std::cin.fail())
	{
		std::cout << "\n\t--- INVALID INPUT ---\n" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	}
	else if (id < 0 || id > maxId)
		std::cout << "\n\t--- NO CONTACT AT " << id << " ---\n" << std::endl;
	else
		this->_contacts[id].display();
}