/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_TagLTN.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 09:43:40 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/07 12:07:55 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtest/gtest.h"

#include "find_primes.hpp"

#include "TagLTN.hpp"

TEST(lexicalCheckTest, Fail)
{
	RootTagLTN		obj(nullptr);
	t_vs			res;

	init_static();
	obj.addSubNode(new RootTagLTN(&obj));
	res = obj.lexicalCheck(false);
	ASSERT_EQ(res.size(), 1);
	EXPECT_EQ(res[0],
		WRONG_PARRENT_ERR(std::string("root"), std::string("root")));
};

TEST(lexicalCheckTest, Ok)
{
	RootTagLTN		root(nullptr);
	IntervalsTagLTN	*intervals;
	IntervalTagLTN	*interval;
	LowTagLTN		*low;
	HighTagLTN		*high;
	TextLTN			*text_low;
	TextLTN			*text_high;
	t_vs			res;

	init_static();

	intervals = new IntervalsTagLTN(&root);
	root.addSubNode(intervals);

	interval = new IntervalTagLTN(intervals);
	intervals->addSubNode(interval);

	low = new LowTagLTN(interval);
	interval->addSubNode(low);

	text_low = new TextLTN(low, "  	-123		");
	low->addSubNode(text_low);

	high = new HighTagLTN(interval);
	interval->addSubNode(high);

	text_high = new TextLTN(high, " 		8908	");
	high->addSubNode(text_high);

	res = root.lexicalCheck(true);
	EXPECT_EQ(res.size(), 0);

	res = root.lexicalCheck(false);
	EXPECT_EQ(res.size(), 0);
};
