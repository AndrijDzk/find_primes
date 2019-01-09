/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LexicalTreeNode.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 07:37:10 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/08 12:28:05 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "typedefs.hpp"

#define WRONG_PARRENT_ERR(NODE, PAR) NODE +  " inside " + PAR
#define UNKNOWN_TEXT_ERR(TEXT) "Unknown text: " + TEXT
#define NO_PARENT_ERR(NODE, PAR) NODE + " outside of " + PAR

#define ROOT_TAG_NAME "root"
#define INTERVALS_TAG_NAME "intervals"
#define INTERVAL_TAG_NAME "interval"
#define LOW_TAG_NAME "low"
#define HIGH_TAG_NAME "high"
#define TEXT_NAME "text"

class LexicalTreeNode;

typedef std::vector<LexicalTreeNode*>		t_vSubNodes;

class LexicalTreeNode
{
	friend class		ParserTest;
public:
	void				addSubNode(LexicalTreeNode *subNode);
	std::string const	&getName(void) const;
	LexicalTreeNode		*getParent(void) const;
	std::string const	&getContent(void) const;
	t_vs				lexicalCheck(bool strict) const;
	virtual t_vs		getIntervals(void) const = 0;
	virtual				~LexicalTreeNode(void);

protected:
	std::string			name;
	LexicalTreeNode		*parent;
	std::string			content;
	t_vSubNodes			subNodes;
	t_vs				checkSubNodesAndParent(
							bool strict,
							t_vs const &ValidSN,
							bool parent,
							std::string const &ValidParent) const;
	virtual t_vs		selfCheck(bool strict) const = 0;
						LexicalTreeNode(
								std::string const &name,
								LexicalTreeNode *parent);
						LexicalTreeNode(
								std::string const &name,
								LexicalTreeNode *parent,
								std::string const &content);

private:
						LexicalTreeNode(void) = delete;
};
