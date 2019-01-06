/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_Parser.class.checkForMissingOpeningTag.cpp    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 09:39:49 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/06 14:31:34 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParserTest.fixture.hpp"

TEST_F(ParserTest, checkForMissingOpeningTagTest1)
{
	std::string		str;
	std::string		right;
	t_vs			errors;

	str = "jfhfdg idfgydug ertyuf d</name>dfgdf f df";
	ASSERT_EQ(checkForMissingOpeningTag(str, right, errors), 1);
	ASSERT_EQ(errors.size(), 1);
	EXPECT_EQ(errors[0], MISSING_OT(std::string("name")));
	EXPECT_EQ(right, "dfgdf f df");
}

TEST_F(ParserTest, checkForMissingOpeningTagTest2)
{
	std::string		str;
	std::string		right;
	t_vs			errors;

	str = "</name>dfgdf f df";
	ASSERT_EQ(checkForMissingOpeningTag(str, right, errors), 1);
	ASSERT_EQ(errors.size(), 1);
	EXPECT_EQ(errors[0], MISSING_OT(std::string("name")));
	EXPECT_EQ(right, "dfgdf f df");
}

TEST_F(ParserTest, checkForMissingOpeningTagTest3)
{
	std::string		str;
	std::string		right;
	t_vs			errors;

	str = "jfhfdg idfgydug ertyuf d</name>";
	ASSERT_EQ(checkForMissingOpeningTag(str, right, errors), 1);
	ASSERT_EQ(errors.size(), 1);
	EXPECT_EQ(errors[0], MISSING_OT(std::string("name")));
	EXPECT_EQ(right, "");
}

TEST_F(ParserTest, checkForMissingOpeningTagTest4)
{
	std::string		str;
	std::string		right;
	t_vs			errors;

	str = "jfhfdg idfgydug ertyuf d</namedfgdf f df";
	ASSERT_EQ(checkForMissingOpeningTag(str, right, errors), 0);
	ASSERT_EQ(errors.size(), 0);
	EXPECT_EQ(right, "");
}
