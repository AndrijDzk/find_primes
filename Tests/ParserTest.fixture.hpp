/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParserTest.fixture.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 14:24:15 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/06 14:25:05 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Includes/Parser.class.hpp"

#include "gtest/gtest.h"

class ParserTest : public ::testing::Test
{
protected:
	int	checkForMissingOpeningTag(std::string const &str, std::string &right, t_vs &errors) {foo.checkForMissingOpeningTag(str, right, errors);}
	int	checkForMissingClosingTag(std::string const &str, std::string &right, t_vs &errors) {foo.checkForMissingClosingTag(str, right, errors);}

private:
	Parser		foo;
};
