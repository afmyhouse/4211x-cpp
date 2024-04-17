/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:49:59 by antoda-s          #+#    #+#             */
/*   Updated: 2024/04/05 16:55:30 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

std::string megaphone(char *quiet)
{
	std::string loud;

	for (int i = 0; quiet[i]; i++)
		loud += toupper(quiet[i]);
	return loud;
}

int main(int argc, char **argv)
{
	std::string loud;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < argc; i++)
	{
		loud += megaphone(argv[i]);
		if (i < argc - 1)
			loud += " ";
	}
	std::cout << loud << std::endl;
}