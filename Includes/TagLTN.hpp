/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TagLTN.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 08:02:01 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/08 15:35:41 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "LexicalTreeNode.class.hpp"

#define LOW_TAG_WRONG_TEXT "Wrong text between <low> and </low>"
#define HIGH_TAG_WRONG_TEXT "Wrong text between <high> and </high>"
#define WRONG_INTERVAL "Wrong interval"

typedef LexicalTreeNode		LTN;

class RootTagLTN : public LexicalTreeNode
{
public:
					RootTagLTN(LexicalTreeNode *parent) : LexicalTreeNode(ROOT_TAG_NAME, parent) {}
	t_vs			getIntervals(void) const override {return (LexicalTreeNode::getIntervals());}

private:
	t_vs			selfCheck(bool strict) const override {return (LexicalTreeNode::checkSubNodesAndParent(strict, RootTagLTN::ValidSN, false, ""));}
	static t_vs		ValidSN;
	friend void		init_static(void);
};

class IntervalsTagLTN : public LexicalTreeNode
{
public:
					IntervalsTagLTN(LexicalTreeNode *parent) : LexicalTreeNode(INTERVALS_TAG_NAME, parent) {}
	t_vs			getIntervals(void) const override {return (LexicalTreeNode::getIntervals());}

private:
	t_vs			selfCheck(bool strict) const override {return (LexicalTreeNode::checkSubNodesAndParent(strict, IntervalsTagLTN::ValidSN, true, ROOT_TAG_NAME));}
	static t_vs		ValidSN;
	friend void		init_static(void);
};

class IntervalTagLTN : public LexicalTreeNode
{
public:
					IntervalTagLTN(LexicalTreeNode *parent) : LexicalTreeNode(INTERVAL_TAG_NAME, parent) {}
	t_vs			getIntervals(void) const override;

private:
	t_vs			selfCheck(bool strict) const override;
	static t_vs 	ValidSN;
	friend void		init_static(void);
};

class LowTagLTN : public LexicalTreeNode
{
public:
					LowTagLTN(LexicalTreeNode *parent);
	t_vs			getIntervals(void) const override;


private:
	t_vs			selfCheck(bool strict) const override;
};

class HighTagLTN : public LexicalTreeNode
{
public:
					HighTagLTN(LexicalTreeNode *parent);
	t_vs			getIntervals(void) const override;

private:
	t_vs			selfCheck(bool strict) const override;
};

class TextLTN : public LexicalTreeNode
{
public:
					TextLTN(LexicalTreeNode *parent, std::string const &content) : LexicalTreeNode(TEXT_NAME, parent, content) {}
	t_vs			getIntervals(void) const override {return (LexicalTreeNode::getIntervals());}

private:
	t_vs			selfCheck(bool strict) const override {return (t_vs());}
};

#define E_LTN_TYPES_AM 6

class TagLTNFactory
{
public:
	enum			e_LTNType {eRoot, eIntervals, eInterval, eLow,
								eHigh, eText};
	static LTN*		newLTN(TagLTNFactory::e_LTNType type, LTN* parent, std::string const &content);
	virtual			~TagLTNFactory(void) = default;

protected:
	virtual LTN*	_newLTN(TagLTNFactory::e_LTNType type, LTN* parent, std::string const &content);
					TagLTNFactory(void);

private:
	virtual LTN*	newRoot(LTN *parent, std::string const &content);
	virtual LTN*	newIntervals(LTN *parent, std::string const &content);
	virtual LTN*	newInterval(LTN *parent, std::string const &content);
	virtual LTN*	newLow(LTN *parent, std::string const &content);
	virtual LTN*	newHigh(LTN *parent, std::string const &content);
	virtual LTN*	newText(LTN *parent, std::string const &content);

private:
	std::vector<TagLTNFactory::e_LTNType >							names;
	std::vector<LTN* (TagLTNFactory::*)(LTN*, std::string const&)>	workers;
};
