/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TagLTNFactory.class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 06:58:50 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/08 07:53:28 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "TagLTN.hpp"

		TagLTNFactory::TagLTNFactory(void) :
				names({
					TagLTNFactory::eRoot,
					TagLTNFactory::eIntervals,
					TagLTNFactory::eInterval,
					TagLTNFactory::eLow,
					TagLTNFactory::eHigh,
					TagLTNFactory::eText}),
				workers({
					&TagLTNFactory::newRoot,
					&TagLTNFactory::newIntervals,
					&TagLTNFactory::newInterval,
					&TagLTNFactory::newLow,
					&TagLTNFactory::newHigh,
					&TagLTNFactory::newText}) {}

LTN*	TagLTNFactory::newLTN(
			TagLTNFactory::e_LTNType type,
			LTN *parent,
			std::string const &content)
{
	static TagLTNFactory*	factory = nullptr;

	if (factory == nullptr)
		factory = new TagLTNFactory();
	return (factory->_newLTN(type, parent, content));
}

#if E_LTN_TYPES_AM != 6
#error "TagLTNFactory::_newLTN arent prepared for all e_LTNtypes"
#endif

LTN*	TagLTNFactory::_newLTN(
			TagLTNFactory::e_LTNType type,
			LTN *parent,
			std::string const &content)
{
	for (size_t i = 0; (i < this->names.size()) && (i < this->workers.size()); i++)
		if (type == this->names[i])
			return ((this->*(this->workers[i]))(parent, content));
	std::cerr << "Error: TagLTNFactory dosent have worker for " << type << std::endl;
	return (new RootTagLTN(parent));
}

LTN*	TagLTNFactory::newRoot(LTN *parent, std::string const &content)
{
	return (new RootTagLTN(parent));
}

LTN*	TagLTNFactory::newIntervals(LTN *parent, std::string const &content)
{
	return (new IntervalsTagLTN(parent));
}

LTN*	TagLTNFactory::newInterval(LTN *parent, std::string const &content)
{
	return (new IntervalTagLTN(parent));
}

LTN*	TagLTNFactory::newLow(LTN *parent, std::string const &content)
{
	return (new LowTagLTN(parent));
}

LTN*	TagLTNFactory::newHigh(LTN *parent, std::string const &content)
{
	return (new HighTagLTN(parent));
}

LTN*	TagLTNFactory::newText(LTN *parent, std::string const &content)
{
	return (new TextLTN(parent, content));
}
