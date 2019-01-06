/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_Parser.class.checkForMissingClosingTag.cpp    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 14:34:04 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/06 14:39:28 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParserTest.fixture.hpp"

TEST_F(ParserTest, checkForMissingClosingTagTest1)
{
	std::string		str;
	std::string		right;
	t_vs			errors;

	str = "jfhfdg idfgydug ertyuf d<name>dfgdf f df";
	ASSERT_EQ(checkForMissingClosingTag(str, right, errors), 1);
	ASSERT_EQ(errors.size(), 1);
	EXPECT_EQ(errors[0], "Missing <name> closing tag");
	EXPECT_EQ(right, "dfgdf f df");
}

TEST_F(ParserTest, checkForMissingClosingTagTest2)
{
	std::string		str;
	std::string		right;
	t_vs			errors;

	str = "<name>dfgdf f df";
	ASSERT_EQ(checkForMissingClosingTag(str, right, errors), 1);
	ASSERT_EQ(errors.size(), 1);
	EXPECT_EQ(errors[0], "Missing <name> closing tag");
	EXPECT_EQ(right, "dfgdf f df");
}

TEST_F(ParserTest, checkForMissingClosingTagTest3)
{
	std::string		str;
	std::string		right;
	t_vs			errors;

	str = "jfhfdg idfgydug ertyuf d<name>";
	ASSERT_EQ(checkForMissingClosingTag(str, right, errors), 1);
	ASSERT_EQ(errors.size(), 1);
	EXPECT_EQ(errors[0], "Missing <name> closing tag");
	EXPECT_EQ(right, "");
}

TEST_F(ParserTest, checkForMissingClosingTagTest4)
{
	std::string		str;
	std::string		right;
	t_vs			errors;

	str = "jfhfdg idfgydug ertyuf d<namedfgdf f df";
	ASSERT_EQ(checkForMissingClosingTag(str, right, errors), 0);
	ASSERT_EQ(errors.size(), 0);
	EXPECT_EQ(right, "");
}

