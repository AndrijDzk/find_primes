/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LowTagLTN.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 11:28:11 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/07 11:28:11 by adzikovs         ###   ########.fr       */
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
