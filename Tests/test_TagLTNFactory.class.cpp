/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_TagLTNFactory.class.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 07:35:00 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/08 07:38:35 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtest/gtest.h"

#include "find_primes.hpp"

#include "TagLTN.hpp"

TEST(TagLTNFactoryTest, newLTNTest)
{
	LexicalTreeNode*	test;

	init_static();

	test = TagLTNFactory::newLTN(TagLTNFactory::eRoot, nullptr, "");
	EXPECT_EQ(test->getName(), ROOT_TAG_NAME);
	delete test;

	test = TagLTNFactory::newLTN(TagLTNFactory::eIntervals, nullptr, "");
	EXPECT_EQ(test->getName(), INTERVALS_TAG_NAME);
	delete test;

	test = TagLTNFactory::newLTN(TagLTNFactory::eInterval, nullptr, "");
	EXPECT_EQ(test->getName(), INTERVAL_TAG_NAME);
	delete test;

	test = TagLTNFactory::newLTN(TagLTNFactory::eLow, nullptr, "");
	EXPECT_EQ(test->getName(), LOW_TAG_NAME);
	delete test;

	test = TagLTNFactory::newLTN(TagLTNFactory::eHigh, nullptr, "");
	EXPECT_EQ(test->getName(), HIGH_TAG_NAME);
	delete test;

	test = TagLTNFactory::newLTN(TagLTNFactory::eText, nullptr, "");
	EXPECT_EQ(test->getName(), TEXT_NAME);
	delete test;
}
