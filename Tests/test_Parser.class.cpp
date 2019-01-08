/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_Parser.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 09:54:36 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/08 14:10:00 by adzikovs         ###   ########.fr       */
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
