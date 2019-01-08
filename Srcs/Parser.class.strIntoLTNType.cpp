/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.class.strIntoLTNType.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 07:58:01 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/08 07:58:01 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.class.hpp"

#if E_LTN_TYPES_AM != 6
#error "Parser::strIntoLTNType arent prepared for all e_LTNtypes"
#endif

TagLTNFactory::e_LTNType	Parser::strIntoLTNType(std::string const &name)
{
	static t_vs										names = {
															ROOT_TAG_NAME,
															INTERVALS_TAG_NAME,
															INTERVAL_TAG_NAME,
															LOW_TAG_NAME,
															HIGH_TAG_NAME,
															TEXT_NAME};
	static std::vector<TagLTNFactory::e_LTNType>	types = {
															TagLTNFactory::eRoot,
															TagLTNFactory::eIntervals,
															TagLTNFactory::eInterval,
															TagLTNFactory::eLow,
															TagLTNFactory::eHigh,
															TagLTNFactory::eText
															};

	for (size_t i = 0; (i < names.size()) && i < (types.size()); i++)
		if (name == names[i])
			return (types[i]);
	throw Parser::UnknownTag(name);
};
