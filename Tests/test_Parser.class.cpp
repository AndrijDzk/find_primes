/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_Parser.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 09:54:36 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/09 09:25:38 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParserTest.fixture.hpp"

#include "find_primes.hpp"

using ::testing::Return;

MockTagLTNFactory*	MockTagLTNFactory::factory = nullptr;

void	MockTagLTNFactory::init(void)
{
	if (MockTagLTNFactory::factory == nullptr)
		MockTagLTNFactory::factory = new testing::StrictMock<MockTagLTNFactory>;
}

void	MockTagLTNFactory::deinit(void)
{
	if (MockTagLTNFactory::factory)
	{
		delete MockTagLTNFactory::factory;
		MockTagLTNFactory::factory = nullptr;
	}
	Parser::factory = &TagLTNFactory::newLTN;
}

LTN*	MockTagLTNFactory::newLTN(TagLTNFactory::e_LTNType type, LTN *parent, std::string const &content)
{
	MockTagLTNFactory::init();
	return (MockTagLTNFactory::factory->_newLTN(type, parent, content));
}

TEST_F(ParserTest, proceedTagTest1)
{
	::testing::Sequence		s;

	MockTagLTNFactory::init();
	this->substitute_mock_factory();
	this->setExpectationsFor_proceedTagTest1(s);
	this->proceedTag(ROOT_TAG_NAME, true);
	this->proceedTag(INTERVALS_TAG_NAME, true);
	this->proceedTag(INTERVAL_TAG_NAME, true);
	this->proceedTag(INTERVAL_TAG_NAME, false);
	this->proceedTag(INTERVALS_TAG_NAME, false);
	this->proceedTag(ROOT_TAG_NAME, false);
	MockTagLTNFactory::deinit();
};

TEST_F(ParserTest, proceedLineTest1)
{
	MockParser				test_obj;
	::testing::Sequence		s;
	std::string				text1;
	std::string				tag1;
	std::string				text2;
	std::string				tag2;
	std::string				text3;
	std::string				line;

	text1 = "abc dg xyz ";
	tag1 = "nanme";
	text2 = "opqr  dkrg df";
	tag2 = "nanme";
	text3 = "cd";
	line = text1 + "<" + tag1 + ">" + text2 + "</" + tag2 + ">" + text3;
	EXPECT_CALL(test_obj, proceedText(text1))
		.InSequence(s);
	EXPECT_CALL(test_obj, proceedTag(tag1, true))
			.InSequence(s);
	EXPECT_CALL(test_obj, proceedText(text2))
			.InSequence(s);
	EXPECT_CALL(test_obj, proceedTag(tag2, false))
			.InSequence(s);
	EXPECT_CALL(test_obj, proceedText(text3))
			.InSequence(s);
	test_obj.proceedLine(line);
}

TEST_F(ParserTest, readIntervalsTestOk1)
{
	Parser					test_obj;
	Parser::t_intervals		res;

	try
	{
		res = test_obj.readIntervals("Tests/ParserTestOk1.xml", true);
		EXPECT_EQ(res.size(), 3);
		EXPECT_EQ(res[0].first, 0);
		EXPECT_EQ(res[0].second, 123);
		EXPECT_EQ(res[1].first, 11);
		EXPECT_EQ(res[1].second, 19);
		EXPECT_EQ(res[2].first, 76);
		EXPECT_EQ(res[2].second, 149);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		EXPECT_EQ(true, false);
	}
}

TEST_F(ParserTest, readIntervalsTestOk2)
{
	Parser					test_obj;
	Parser::t_intervals		res;

	try
	{
		res = test_obj.readIntervals("Tests/ParserTestOk2.xml", true);
		EXPECT_EQ(res.size(), 3);
		EXPECT_EQ(res[0].first, 0);
		EXPECT_EQ(res[0].second, 123);
		EXPECT_EQ(res[1].first, 11);
		EXPECT_EQ(res[1].second, 19);
		EXPECT_EQ(res[2].first, 76);
		EXPECT_EQ(res[2].second, 149);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		EXPECT_EQ(true, false);
	}
}

TEST_F(ParserTest, readIntervalsTestOk3)
{
	Parser					test_obj;
	Parser::t_intervals		res;

	try
	{
		res = test_obj.readIntervals("Tests/ParserTestFail1.xml", false);
		EXPECT_EQ(res.size(), 3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		EXPECT_EQ(true, false);
	}
}

TEST_F(ParserTest, readIntervalsTestFail1)
{
	Parser					test_obj;
	Parser::t_intervals		res;

	try
	{
		res = test_obj.readIntervals("Tests/ParserTestFail1.xml", true);
		EXPECT_EQ(true, false);
	}
	catch (std::exception &e)
	{
		EXPECT_EQ(e.what(), "Error: " + WRONG_PARRENT_ERR(std::string(TEXT_NAME), std::string(INTERVALS_TAG_NAME)) + "\n");
	}
}

TEST_F(ParserTest, readIntervalsTestFail2)
{
	Parser					test_obj;
	Parser::t_intervals		res;

	try
	{
		res = test_obj.readIntervals("Tests/ParserTestFail2.xml", true);
		EXPECT_EQ(true, false);
	}
	catch (std::exception &e)
	{
		EXPECT_EQ(e.what(), "Error: " + WRONG_PARRENT_ERR(std::string(LOW_TAG_NAME), std::string(INTERVALS_TAG_NAME)) + "\n");
	}
}
