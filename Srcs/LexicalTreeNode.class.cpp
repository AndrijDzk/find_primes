/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LexicalTreeNode.class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 07:44:12 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/08 08:26:00 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>

#include "LexicalTreeNode.class.hpp"

					LexicalTreeNode::LexicalTreeNode(
						std::string const &name, LexicalTreeNode *parent
						) : name(name), parent(parent) {}

					LexicalTreeNode::LexicalTreeNode(
						std::string const &name,
						LexicalTreeNode *parent,
						std::string const &content
						) :
							name(name),
							parent(parent),
							content(content) {}

					LexicalTreeNode::~LexicalTreeNode(void)
{
	for (LexicalTreeNode *subNode : this->subNodes)
		delete subNode;
}

void				LexicalTreeNode::addSubNode(LexicalTreeNode *subNode)
{
	this->subNodes.push_back(subNode);
}

std::string const	&LexicalTreeNode::getName(void) const
{
	return (this->name);
}

LexicalTreeNode*	LexicalTreeNode::getParent(void) const
{
	return (this->parent);
}

std::string const	&LexicalTreeNode::getContent(void) const
{
	return (this->content);
}

t_vs				LexicalTreeNode::lexicalCheck(bool strict) const
{
	t_vs		res;

	for (auto const &error : this->selfCheck(strict))
		res.push_back(error);

	for (auto const &subNode : this->subNodes)
		for (auto const &error : subNode->lexicalCheck(strict))
			res.push_back(error);
	return (res);
}

t_vs				LexicalTreeNode::checkSubNodesAndParent(
							bool strict,
							t_vs const &ValidSN,
							bool parent,
							std::string const &ValidParent) const
{
	t_vs	res;

	if (parent && (this->parent == nullptr))
		res.push_back(NO_PARENT_ERR(this->name, ValidParent));
	for (auto const &subNode : this->subNodes)
		if (std::find(ValidSN.begin(),
					  ValidSN.end(),
					  subNode->getName()) == ValidSN.end())
		{
			if (strict || subNode->getName() != TEXT_NAME)
				res.push_back(WRONG_PARRENT_ERR(subNode->getName(), this->name));
		}
	return (res);
}

t_vs				LexicalTreeNode::getIntervals(void) const
{
	t_vs			res;

	for (auto const &subnode : this->subNodes)
		for (auto const &interval : subnode->getIntervals())
			res.push_back(interval);
	return (res);
}
