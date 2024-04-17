/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:35:30 by antoda-s          #+#    #+#             */
/*   Updated: 2024/04/16 13:16:34 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
class StringHandler {

public:

	StringHandler(char *argv){
		this->str = argv;
		return ;
	}

	~StringHandler(void){
		return ;
	}

	std::string UpperHandler(void) {
		for (size_t x=0; x<this->str.size(); x++) {
			this->str[x] = toupper(this->str[x]);
			}
		return this->str;
	}

private:
	std::string str;

};

int	main(int argc, char **argv)
{

	if (argc != 1)
	{
		for(int i = 1; argv[i]; i++)
		{
			StringHandler myString(argv[i]);
			std::cout << myString.UpperHandler();
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	return 0;
}
