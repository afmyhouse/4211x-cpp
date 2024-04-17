/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:48:40 by antoda-s          #+#    #+#             */
/*   Updated: 2024/04/16 17:17:34 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void add(void);
		void search(void);
		void _displayMenu(void);
		void _displayPrompt(void);
		void _displayPhoneBook(void);
		bool _isStringPrintable(std::string str);

	private:
		int _i;
		static const int MAX_CONTACTS = 8;
		Contact _contacts[MAX_CONTACTS];

	// private:
};

#endif