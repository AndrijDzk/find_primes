/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_prime_test.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 07:59:08 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/05 09:06:46 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>

#include "gtest/gtest.h"

#include "find_primes.hpp"

typedef std::vector<int>::iterator		t_vii;

TEST(isPrimeTest, CompositeNubersTest)
{
	std::vector<int>	arr = {
							0, 1, 4, 6, 8, 9, 10, 12,
							14, 15, 16};
	for (t_vii i = arr.begin(); i != arr.end(); i++)
		ASSERT_EQ(is_prime(*i), false);
};

TEST(isPrimeTest, PrimeNubersTest)
{
	std::vector<int>	arr = {
							2, 3, 5, 7, 11, 13,
							17, 19, 23};
	for (t_vii i = arr.begin(); i != arr.end(); i++)
		ASSERT_EQ(is_prime(*i), true);
};
