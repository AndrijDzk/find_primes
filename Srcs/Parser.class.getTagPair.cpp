/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.class.getTagPair.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 11:12:39 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/06 08:54:58 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <regex>

#include "Parser.class.hpp"

Parser::t_tag_pair		Parser::getTagPair(
							std::string const &str,
							t_vs &errors)
{
	std::regex			reg;
	std::string			expr;
	std::smatch			match;
	Parser::t_tag_pair	res;

	expr = "<([.]+)>";
	expr += "([.[:s:]]*)";
	expr += "</()\\0>";
	expr += "([.[:s:]]*)";
	if (!std::regex_match(str, match, reg))
	{
		if (this->checkForErrors(str, res.post, errors))
			return (res);
		else
		{
			errors.push_back("Tags not found");
			res.post = str;
			return (res);
		}
	}
	res.name = match.str(0);
	res.content = match.str(1);
	res.post = match.str(3);
	return (res);
}
