/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 10:15:55 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/07 07:44:03 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>
#include <utility>
#include <vector>
#include <fstream>

#include "typedefs.hpp"

#define MISSING_OT(X) "Missing </" + X + "> opening tag"
#define MISSING_CT(X) "Missing <" + X + "> closing tag"

class Parser
{
	friend class 			ParserTest;
public:
	typedef std::pair<t_nb, t_nb>			t_interval;
	typedef std::vector<Parser::t_interval>	t_intervals;
	typedef struct							s_tags_pair
	{
		std::string							name;
		std::string							content;
		std::string							post;
	}										t_tag_pair;

public:
	class Error : public std::logic_error {public: Error(std::string const &msg) : logic_error(msg) {}};
		class FatalError : public Parser::Error {public : FatalError(std::string const &msg) : Error(msg) {}};
			class WrongFileError : public Parser::FatalError {public: WrongFileError() : FatalError("Wrong filename") {}};
		class NonFatalError : public Parser::Error {public : NonFatalError(std::string const &msg) : Error(msg) {}};
			class MissingTag : public Parser::NonFatalError {public: MissingTag(std::string const &name) : NonFatalError("Missing " + name + " tag") {}};
			class NoTags : public Parser::NonFatalError {public: NoTags() : NonFatalError("Tags non found") {}};

public:
	Parser::t_intervals		readIntervals(std::string const &filename);

private:
	int						checkForErrors(
								std::string const &str,
								std::string &right,
								t_vs &errors);
	int						checkForMissingOpeningTag(
								std::string const &str,
								std::string &right,
								t_vs &errors);
	int						checkForMissingClosingTag(
								std::string const &str,
								std::string &right,
								t_vs &errors);
	Parser::t_tag_pair		getTagPair(
								std::string const &str,
								t_vs &errors);
	std::ifstream			openFile(std::string const &filename);
};
