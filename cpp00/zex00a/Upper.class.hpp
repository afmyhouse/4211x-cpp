/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Upper.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:22:05 by antoda-s          #+#    #+#             */
/*   Updated: 2024/04/03 16:30:19 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPPER_CLASS_HPP
# define UPPER_CLASS_HPP

class Upper {

public:

	// char string[512];

	Upper(char *argv);
	~Upper(void);

	void MyToUpper(void);

private:
	std::string str;

};

#endif