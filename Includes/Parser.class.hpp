/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 10:15:55 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/08 15:01:16 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>
#include <utility>
#include <vector>
#include <fstream>

#include "TagLTN.hpp"

#include "typedefs.hpp"

#define MISSING_OT(X) "Missing </" + X + "> opening tag"
#define MISSING_CT(X) "Missing <" + X + "> closing tag"

typedef std::vector<LexicalTreeNode*>	t_vLTN;

class Parser
{
	friend class 			ParserTest;
	friend class			MockTagLTNFactory;
public:
	typedef std::pair<t_nb, t_nb>			t_interval;
	typedef std::vector<Parser::t_interval>	t_intervals;

public:
	class Error : public std::logic_error {public: Error(std::string const &msg) : logic_error(msg) {}};
		class FatalError : public Parser::Error {public : FatalError(std::string const &msg) : Error(msg) {}};
			class WrongFileError : public Parser::FatalError {public: WrongFileError() : FatalError("Wrong filename") {}};
			class MissingTag : public Parser::FatalError {public: MissingTag(std::string const &name) : FatalError("Missing " + name + " tag") {}};
		class NonFatalError : public Parser::Error {public : NonFatalError(std::string const &msg) : Error(msg) {}};
			class UnknownTag : public Parser::NonFatalError {public: UnknownTag(std::string const &name) : NonFatalError("Unknown tag " + name) {}};

public:
	Parser::t_intervals			readIntervals(std::string const &filename, bool strict);
	TagLTNFactory::e_LTNType	strIntoLTNType(std::string const &name);
								Parser(void);
								~Parser(void);

private:
	t_vLTN						trees;
	LexicalTreeNode*			curr;
	static LTN*					(*factory)(
									TagLTNFactory::e_LTNType,
									LTN*,
									std::string const &);

private:
	std::ifstream				openFile(std::string const &filename);
	Parser::t_intervals			stringsIntoIntervals(t_vs const &intervals) const;
	void						clear(void);

protected:
	void						proceedLine(std::string const &line);
	virtual void				proceedText(std::string const &text);
	virtual void				proceedTag(std::string const &name, bool open);
	friend void					init_static(void);
};