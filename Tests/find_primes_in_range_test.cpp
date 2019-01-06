/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_primes_in_range_test.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 08:36:00 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/05 09:49:00 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtest/gtest.h"

#include "find_primes.hpp"

TEST(findPrimesInRange, Range1)
{
	MyMap	Res;
	MyMap	CorrectRes;

	CorrectRes[2] = 1;
	CorrectRes[3] = 1;
	CorrectRes[5] = 1;
	CorrectRes[7] = 1;
	CorrectRes[11] = 1;
	CorrectRes[13] = 1;
	findPrimesInRange(2, 14, Res, true);
	ASSERT_EQ(Res, CorrectRes);
}
