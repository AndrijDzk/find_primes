/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.class.readIntervals.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 10:22:14 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/08 15:01:38 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include <stack>

#include <regex>

#include "Parser.class.hpp"

void					Parser::proceedLine(std::string const &line)
{
	std::regex					reg;
	std::smatch					match;
	std::stack<std::string>		search_stack;
	std::string					top;

	reg.assign("<(/)?([^/<>]+)>");
	search_stack.push(line);
	while (!search_stack.empty())
	{
		top = search_stack.top();
		search_stack.pop();
		try
		{
			if (std::regex_match(top, match, reg))
				this->proceedTag(match.str(2), match.str(1).empty());
			else if (!std::regex_search(top, match, reg))
				this->proceedText(top);
			else
			{
				search_stack.push(match.suffix());
				search_stack.push(match.str(0));
				search_stack.push(match.prefix());
			}
		}
		catch (Parser::NonFatalError &e) {std::cout << "Warning: " << e.what();}
	}
}

void					Parser::proceedText(std::string const &text)
{
	LTN*						newTag;

	newTag = (*Parser::factory)(TagLTNFactory::eText, this->curr, text);
	if (this->curr)
		this->curr->addSubNode(newTag);
	else
		this->trees.push_back(newTag);
	this->curr = newTag;
}

void					Parser::proceedTag(std::string const &name, bool open)
{
	LTN*						newTag;
	TagLTNFactory::e_LTNType	type;

	type = this->strIntoLTNType(name);
	if (open)
	{
		newTag = (*Parser::factory)(type, this->curr, std::string());
		if (this->curr)
			this->curr->addSubNode(newTag);
		else
			this->trees.push_back(newTag);
		this->curr = newTag;
	}
	else
	{
		if (this->curr && this->curr->getName() == name)
			this->curr = this->curr->getParent();
		else
			throw Parser::MissingTag(name + " opening");
	}
}

Parser::t_intervals		Parser::readIntervals(std::string const &filename, bool strict)
{
	std::ifstream		file;
	std::string			buff;
	bool				good = true;
	t_vs				tmp;

	try
	{
		file = this->openFile(filename);
		while (std::getline(file, buff).good())
			this->proceedLine(buff);
		for (auto const &tree : this->trees)
			for (auto const &error : tree->lexicalCheck(strict))
			{
				good = false;
				tmp.push_back("Error: " + error);
			}
		if (good)
		{
			tmp.clear();
			for (auto const &tree : this->trees)
				for (auto const &interval : tree->getIntervals())
					tmp.push_back(interval);
			this->clear();
			return (this->stringsIntoIntervals(tmp));
		}
		else
		{
			std::string		error_msg;

			for (std::string const &error : tmp)
				error_msg.append("Error: " + error + "\n");
			this->clear();
			throw Parser::FatalError(error_msg);
		}
	}
	catch (std::exception &e)
	{
		this->clear();
		throw e;
	}
	this->clear();
	throw Parser::FatalError("Error: Wrong file!");
}

Parser::t_intervals		Parser::stringsIntoIntervals(t_vs const &intervals) const
{
	Parser::t_intervals	res;
	std::regex			reg;
	std::smatch			match;
	std::string			expr;
	Parser::t_interval	tmp;
	long				tmp2;

	expr = "[[:s:]]*";
	expr += "([+-]?[[:d:]]+)";
	expr += "[[:s:]]*";
	expr += "([+-]?[[:d:]]+)";
	expr += "[[:s:]]*";
	reg.assign(expr);
	for (std::string const &interval : intervals)
		if (std::regex_match(interval, match, reg))
		{
			try
			{
				tmp2 = std::stol(match.str(1));
				if (tmp2 >= 0)
					tmp.first = static_cast<t_nb>(tmp2);
				else
					tmp.first = 0;
				tmp2 = std::stol(match.str(2));
				if (tmp2 >= 0)
					tmp.second = static_cast<t_nb>(tmp2);
				else
					tmp.second = 0;
				res.push_back(tmp);
			}
			catch (std::exception &e) {}
		}
	return (res);
}

void					Parser::clear(void)
{
	for (LexicalTreeNode *tree : this->trees)
		delete tree;
	this->trees.clear();
	this->curr = nullptr;
}
