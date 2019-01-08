/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_static.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 11:09:20 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/07 11:12:47 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TagLTN.hpp"

t_vs		RootTagLTN::ValidSN;
t_vs		IntervalsTagLTN::ValidSN;
t_vs		IntervalTagLTN::ValidSN;

void		init_static(void)
{
	RootTagLTN::ValidSN = {INTERVALS_TAG_NAME};
	IntervalsTagLTN::ValidSN = {INTERVAL_TAG_NAME};
	IntervalTagLTN::ValidSN = {LOW_TAG_NAME, HIGH_TAG_NAME};
}
