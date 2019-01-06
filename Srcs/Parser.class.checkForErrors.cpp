/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.class.checkForErrors.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 08:55:32 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/06 14:39:28 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include <regex>

#include "Parser.class.hpp"

int		Parser::checkForMissingOpeningTag(
			std::string const &str, std::string &right, t_vs &errors)
{
	std::regex			reg;
	std::string			expr;
	std::smatch			res;

	expr += "([^]*)";
	expr += "</([^</]+)>";
	expr += "([^]*)";
	reg.assign(expr);
	if (std::regex_match(str, res, reg))
	{
		reg.assign("<[^</]*>");
		if (!std::regex_search(res.str(1), reg))
		{
			errors.push_back(MISSING_OT(res.str(2)));
			right = res.str(3);
			return (1);
		}
	}
	return (0);
}

int		Parser::checkForMissingClosingTag(
			std::string const &str, std::string &right, t_vs &errors)
{
	std::regex			reg;
	std::string			expr;
	std::smatch			res;

	expr = "([^]*)";
	expr += "<([^</]+)>";
	expr += "([^]*)";
	reg.assign(expr);
	if (std::regex_match(str, res, reg))
	{
		reg.assign("</" + res.str(2) + ">");
		if (!std::regex_search(res.str(3), reg))
		{
			right = res.str(3);
			errors.push_back(MISSING_CT(res.str(2)));
		}
		return (1);
	}
	return (0);
}

int		Parser::checkForErrors(
			std::string const &str, std::string &right, t_vs &errors)
{
	if (this->checkForMissingOpeningTag(str, right, errors))
		return (1);
	else if (this->checkForMissingClosingTag(str, right, errors))
		return (1);
	else
		return (0);
}
