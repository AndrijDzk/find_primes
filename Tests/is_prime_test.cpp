/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_prime_test.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 07:59:08 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/03 08:22:35 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_primes.hpp"

#include "gtest/gtest.h"

TEST(isPrimeTest, zeroIsntPrime)
{
	EXPECT_EQ(is_prime(0), 0);
}
