/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primes_into_xml.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 09:29:37 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/09 09:29:44 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include <fstream>

#include "myMap.class.hpp"

void	primes_into_xml(MyMap const &res, std::string const &filename)
{
	std::fstream		file(filename, std::fstream::out | std::fstream::trunc);

	if (file.good())
	{
		file << "<root>" << std::endl;
		file << "<primes> ";
		for (auto const &prime : res)
			file << prime.first << " ";
		file << "</primes>" << std::endl;
		file << "</root>" << std::endl;
	}
	else
		std::cout << "Error: unable to open output file " << filename << std::endl;
}
