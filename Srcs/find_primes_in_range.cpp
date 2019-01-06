/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_primes_in_range.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 11:07:55 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/05 09:49:00 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myMap.class.hpp"

#include "find_primes.hpp"

static void		findPrimesInRangeBody(t_nb begin, t_nb end, MyMap *res)
{
	for (; begin < end; begin++)
	{
		if (is_prime(begin))
			try
			{
				res->lock.lock();
				res->at(begin)++;
				res->lock.unlock();
			}
			catch (std::out_of_range &e)
			{
				(*res)[begin] = 1;
				res->lock.unlock();
			}
	}
}

std::thread*		findPrimesInRange(t_nb begin, t_nb end, MyMap &res, bool join)
{
	std::thread*	Worker;

	Worker = new std::thread(findPrimesInRangeBody, begin, end, &res);
	if (join)
	{
		Worker->join();
		delete Worker;
		return (nullptr);
	}
	else
		return (Worker);
}
