/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_static.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 11:09:20 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/08 09:54:32 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TagLTN.hpp"

#include "Parser.class.hpp"

t_vs		RootTagLTN::ValidSN;
t_vs		IntervalsTagLTN::ValidSN;
t_vs		IntervalTagLTN::ValidSN;
LTN*		(*Parser::factory)(
				TagLTNFactory::e_LTNType,
				LTN*,
				std::string const &);

void		init_static(void)
{
	RootTagLTN::ValidSN = {INTERVALS_TAG_NAME};
	IntervalsTagLTN::ValidSN = {INTERVAL_TAG_NAME};
	IntervalTagLTN::ValidSN = {LOW_TAG_NAME, HIGH_TAG_NAME};
	Parser::factory = &TagLTNFactory::newLTN;
}
