/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TagLTN.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 08:02:01 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/07 11:43:19 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "LexicalTreeNode.class.hpp"

#define LOW_TAG_WRONG_TEXT "Wrong text between <low> and </low>"
#define HIGH_TAG_WRONG_TEXT "Wrong text between <high> and </high>"

class RootTagLTN : public LexicalTreeNode
{
public:
					RootTagLTN(LexicalTreeNode *parent) : LexicalTreeNode(ROOT_TAG_NAME, parent) {}
private:
	t_vs			selfCheck(bool strict) const override {return (LexicalTreeNode::checkSubNodesAndParent(strict, RootTagLTN::ValidSN, false, ""));}
	static t_vs		ValidSN;
	friend void		init_static(void);
};

class IntervalsTagLTN : public LexicalTreeNode
{
public:
					IntervalsTagLTN(LexicalTreeNode *parent) : LexicalTreeNode(INTERVALS_TAG_NAME, parent) {}

private:
	t_vs			selfCheck(bool strict) const override {return (LexicalTreeNode::checkSubNodesAndParent(strict, IntervalsTagLTN::ValidSN, true, ROOT_TAG_NAME));}
	static t_vs		ValidSN;
	friend void		init_static(void);
};

class IntervalTagLTN : public LexicalTreeNode
{
public:
					IntervalTagLTN(LexicalTreeNode *parent) : LexicalTreeNode(INTERVAL_TAG_NAME, parent) {}

private:
	t_vs			selfCheck(bool strict) const override {return (LexicalTreeNode::checkSubNodesAndParent(strict, IntervalTagLTN::ValidSN, true, INTERVALS_TAG_NAME));}
	static t_vs 	ValidSN;
	friend void		init_static(void);
};

class LowTagLTN : public LexicalTreeNode
{
public:
					LowTagLTN(LexicalTreeNode *parent);

private:
	t_vs			selfCheck(bool strict) const override;
};

class HighTagLTN : public LexicalTreeNode
{
public:
					HighTagLTN(LexicalTreeNode *parent);

private:
	t_vs			selfCheck(bool strict) const override;
};

class TextLTN : public LexicalTreeNode
{
public:
					TextLTN(LexicalTreeNode *parent, std::string const &content) : LexicalTreeNode(TEXT_NAME, parent, content) {}

private:
	t_vs			selfCheck(bool strict) const override {return (t_vs());}
};
