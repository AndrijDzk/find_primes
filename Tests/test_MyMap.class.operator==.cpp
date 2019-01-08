/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestMyMap.class.operator==.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 09:02:36 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/07 09:33:10 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtest/gtest.h"

#include "myMap.class.hpp"

TEST(MyMapClass, OperatorEqTestTrue)
{
	MyMap	Map1;
	MyMap	Map2;

	Map1[2] = 1;
	Map1[3] = 4;
	Map1[5] = 7;

	Map2[2] = 1;
	Map2[3] = 4;
	Map2[5] = 7;
	ASSERT_EQ(Map1, Map2);
}

TEST(MyMapClass, OperatorEqTestFalse1)
{
	MyMap	Map1;
	MyMap	Map2;

	Map1[2] = 1;
	Map1[3] = 4;
	Map1[5] = 7;

	Map2[2] = 1;
	Map2[3] = 4;
	Map2[5] = 6;
	ASSERT_NE(Map1, Map2);
}

TEST(MyMapClass, OperatorEqTestFalse2)
{
	MyMap	Map1;
	MyMap	Map2;

	Map1[2] = 1;
	Map1[3] = 4;
	Map1[5] = 7;

	Map2[2] = 1;
	Map2[3] = 4;
	Map2[6] = 7;
	ASSERT_NE(Map1, Map2);
}

TEST(MyMapClass, OperatorEqTestFalse3)
{
	MyMap	Map1;
	MyMap	Map2;

	Map1[2] = 1;
	Map1[3] = 4;
	Map1[5] = 7;

	Map2[2] = 1;
	Map2[3] = 4;
	ASSERT_NE(Map1, Map2);
}

TEST(MyMapClass, OperatorEqTestFalse4)
{
	MyMap	Map1;
	MyMap	Map2;

	Map1[2] = 1;
	Map1[3] = 4;

	Map2[2] = 1;
	Map2[3] = 4;
	Map2[5] = 6;
	ASSERT_NE(Map1, Map2);
}