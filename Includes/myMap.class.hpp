/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myMap.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 10:59:43 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/05 08:43:42 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <mutex>
#include <map>

#include "typedefs.hpp"

class MyMap : public std::map<t_nb, unsigned>
{
public:
	std::mutex		lock;
};

bool	operator==(MyMap const &lhs, MyMap const &rhs);
