/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.class.openFile.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 10:33:56 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/05 10:33:56 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.class.hpp"

std::ifstream		Parser::openFile(std::string const &filename)
{
	std::ifstream	res(filename, std::ifstream::in);

	if (res.good())
		return (res);
	else
		throw Parser::WrongFileError();
}
