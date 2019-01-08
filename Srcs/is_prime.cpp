/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_prime.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 11:33:15 by adzikovs          #+#    #+#             */
/*   Updated: 2018/12/28 11:33:15 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>

#include <stdexcept>

#include "typedefs.hpp"

static bool		simple_tests(t_nb nbr)
{
	if (nbr < 2)
		return (false);
	else if (nbr < 4)
		return (true);
	throw std::exception();
}

bool			is_prime(t_nb nbr)
{
	t_nb		lim;

	try { return (simple_tests(nbr));}
	catch (...) {}
	lim = static_cast<t_nb>(std::ceil(std::sqrt(nbr)));
	for (t_nb i = 2; i <= lim; i++)
		if ((nbr % i) == 0)
			return (false);
	return (true);
}
