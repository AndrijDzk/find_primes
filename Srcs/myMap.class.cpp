/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myMap.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 08:44:16 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/05 09:18:08 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myMap.class.hpp"

bool	operator==(MyMap const &lhs, MyMap const &rhs)
{
	for (auto const &it : lhs)
		try
		{
			if (rhs.at(it.first) != it.second)
				return (false);
		}
		catch (std::out_of_range &e) {return (false);}

	for (auto const &it : rhs)
		try
		{
			if (lhs.at(it.first) != it.second)
				return (false);
		}
		catch (std::out_of_range &e) {return (false);}
	return (true);
}
