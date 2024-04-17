/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Upper.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:30:58 by antoda-s          #+#    #+#             */
/*   Updated: 2024/04/03 17:40:08 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include "Upper.class.hpp"

Upper::Upper(char *argv) {
	this->str = argv;
	return ;
}

Upper:: ~Upper(void) {
	return ;
}

void Upper::MyToUpper() {
	for (size_t x=0; x<this->str.size(); x++){
		this->str[x] = toupper(this->str[x]);
	}
	std::cout << this->str;
	return ;
}