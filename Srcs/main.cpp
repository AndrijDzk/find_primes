/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 11:04:37 by adzikovs          #+#    #+#             */
/*   Updated: 2019/01/09 09:48:42 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


#include "myMap.class.hpp"

#include "Parser.class.hpp"

#include "find_primes.hpp"

int		main(int argc, char **argv)
{
	init_static();

	Parser						_parser;
	Parser::t_intervals			input;
	std::vector<std::thread*>	threads;
	std::thread*				tmp;
	MyMap						res;
	if (argc < 2)
		std::cout << "Usage: " << argv[0] << " input_file [output_file]" << std::endl;
	else
	{
		try
		{
			input = _parser.readIntervals(argv[1], true);
			for (Parser::t_interval const &interval : input)
			{
				tmp = findPrimesInRange(interval.first, interval.second, res, false);
				threads.push_back(tmp);
			}
			for (std::thread* thread : threads)
				if (thread->joinable())
					thread->join();
			if (argc < 3)
				primes_into_xml(res, "primes.xml");
			else
				primes_into_xml(res, argv[2]);
		}
		catch (std::exception &e)
		{
			std::cout << e.what();
		}
	}
	return (0);
}
