/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LowTagLTN.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 11:28:11 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/08 15:35:41 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <regex>

#include "TagLTN.hpp"

		LowTagLTN::LowTagLTN(LexicalTreeNode *parent) :
				LexicalTreeNode(LOW_TAG_NAME, parent) {}

t_vs	LowTagLTN::selfCheck(bool strict) const
{
	t_vs		res;
	std::regex	reg("[[:s:]]*(\\+|\\-)?[[:d:]]+[[:s:]]*");

	if (this->parent == nullptr)
		res.push_back(NO_PARENT_ERR(this->name, INTERVAL_TAG_NAME));
	if (this->subNodes.size() != 1 || this->subNodes[0]->getName() != TEXT_NAME)
		res.push_back(LOW_TAG_WRONG_TEXT);
	else if (!std::regex_match(this->subNodes[0]->getContent(), reg))
		res.push_back(LOW_TAG_WRONG_TEXT);
	return (res);
}

HighTagLTN::HighTagLTN(LexicalTreeNode *parent) :
		LexicalTreeNode(HIGH_TAG_NAME, parent) {}

t_vs	HighTagLTN::selfCheck(bool strict) const
{
	t_vs		res;
	std::regex	reg("[[:s:]]*(\\+|\\-)?[[:d:]]+[[:s:]]*");

	if (this->parent == nullptr)
		res.push_back(NO_PARENT_ERR(this->name, INTERVAL_TAG_NAME));
	if (this->subNodes.size() != 1 || this->subNodes[0]->getName() != TEXT_NAME)
		res.push_back(HIGH_TAG_WRONG_TEXT);
	else if (!std::regex_match(this->subNodes[0]->getContent(), reg))
		res.push_back(HIGH_TAG_WRONG_TEXT);
	return (res);
}

t_vs	IntervalTagLTN::selfCheck(bool strict) const
{
	t_vs	basic_errors;

	basic_errors = LexicalTreeNode::checkSubNodesAndParent(
		strict, IntervalTagLTN::ValidSN, true, INTERVALS_TAG_NAME);
	if (!basic_errors.empty())
		return (basic_errors);
	else if (this->subNodes.size() != 2 ||
				this->subNodes[0]->getName() != LOW_TAG_NAME ||
				this->subNodes[1]->getName() != HIGH_TAG_NAME)
		return (t_vs({WRONG_INTERVAL}));
	return (basic_errors);
}

t_vs	LowTagLTN::getIntervals(void) const
{
	t_vs	res;

	if (!this->lexicalCheck(false).empty())
		return (res);
	res.push_back(this->subNodes[0]->getContent());
	return (res);
}

t_vs	HighTagLTN::getIntervals(void) const
{
	t_vs	res;

	if (!this->lexicalCheck(false).empty())
		return (res);
	res.push_back(this->subNodes[0]->getContent());
	return (res);
}

t_vs	IntervalTagLTN::getIntervals(void) const
{
	t_vs	res;

	if (!this->lexicalCheck(false).empty())
		return (res);
	try
	{
		res.push_back(this->subNodes[0]->getIntervals()[0]);
		res.back().append(" ");
		res.back().append(this->subNodes[1]->getIntervals()[0]);
		return (res);
	}
	catch (std::exception &e) {return (t_vs());}
}
