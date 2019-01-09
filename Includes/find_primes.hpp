/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_primes.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 07:57:55 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/05 08:43:42 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <thread>

#include "myMap.class.hpp"

void			init_static(void);

bool			is_prime(t_nb nbr);

std::thread*	findPrimesInRange(t_nb begin, t_nb end, MyMap &res, bool join);

void			primes_into_xml(MyMap const &res, std::string const &filename);
