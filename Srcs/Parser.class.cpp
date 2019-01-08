/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 06:23:48 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/08 06:23:48 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.class.hpp"

		Parser::Parser(void) : curr(nullptr) {}

		Parser::~Parser(void)
{
	for (LexicalTreeNode *tree : this->trees)
		delete tree;
}
