/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParserTest.fixture.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 14:24:15 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/08 14:08:37 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "gtest/gtest.h"

#include "gmock/gmock.h"

#include "Parser.class.hpp"

#include "find_primes.hpp"

using ::testing::Invoke;
using ::testing::_;

class MockTagLTNFactory : public TagLTNFactory
{
	friend class				ParserTest;
public:
	static LTN* 				newLTN(
									TagLTNFactory::e_LTNType,
									LTN*,
									std::string const &);
	static void					init(void);
	static void 				deinit(void);

protected:
	static MockTagLTNFactory*	factory;
	MOCK_METHOD3(_newLTN,LTN*(TagLTNFactory::e_LTNType type, LTN* parent, std::string const &content));
	LTN*						ParentNewLTN(TagLTNFactory::e_LTNType type, LTN* parent, std::string const &content) {return (TagLTNFactory::_newLTN(type, parent, content));};
};

class MockParser : public Parser
{
public:
	void		proceedLine(std::string const &line) {Parser::proceedLine(line);}
	MOCK_METHOD2(proceedTag, void(std::string const&, bool));
	MOCK_METHOD1(proceedText, void(std::string const&));
};

class ParserTest : public ::testing::Test
{
protected:
	void						SetUp(void) override
	{
		init_static();
	}

protected:
	void						substitute_mock_factory(void) {Parser::factory = &MockTagLTNFactory::newLTN;}
	void						proceedTag(std::string const &name, bool open) {return (this->foo.proceedTag(name, open));}
	void						proceedLine(std::string const &line) {return (this->foo.proceedLine(line));}
	void						setExpectationsFor_proceedTagTest1(::testing::Sequence const &s)
	{
		ON_CALL((*(MockTagLTNFactory::factory)), _newLTN(_, _, _))
				.WillByDefault(Invoke(&(*(MockTagLTNFactory::factory)), &MockTagLTNFactory::ParentNewLTN));
		EXPECT_CALL((*(MockTagLTNFactory::factory)), _newLTN(TagLTNFactory::eRoot, _, _))
				.InSequence(s);
		EXPECT_CALL((*(MockTagLTNFactory::factory)), _newLTN(TagLTNFactory::eIntervals, _, _))
				.InSequence(s);
		EXPECT_CALL((*(MockTagLTNFactory::factory)), _newLTN(TagLTNFactory::eInterval, _, _))
				.InSequence(s);
	}

private:
	Parser						foo;
};
