/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorTest.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:17:08 by ilya              #+#    #+#             */
/*   Updated: 2022/10/28 17:33:48 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <memory>
#include <iostream>
#include "../containers/vector.hpp"
#include "../utils/colorHeader.hpp"

int example1(void)
{
	std::cout << BOLDGREEN << "Example 1" << RESET << std::endl;
	ft::vector<int>		firstEmpty;
	ft::vector<int> 	second (3, 50);                       // four ints with value 100
	ft::vector<int> 	third (second);                       // four ints with value 100
	third[1] = 101;
	third[2] = 666;

	// std::cout  << "Constructors: "  << std::endl;
	// for (int i = 0; i < 3; i++)
	// {
	// 	std::cout << second[i] << std::endl;
	// }

	// std::cout  << "operaror[]: "  << std::endl;
	
	// for (int i = 0; i < 3; i++)
	// {
	// 	std::cout << third[i] << std::endl;
	// }
	
	std::cout  << "randon_access_operator: "  << std::endl;
	ft::vector<int>::iterator	ft_it;
	for (ft_it = third.begin(); ft_it != third.end(); ft_it ++)
	{
		std::cout << *ft_it << std::endl;
	}

	std::cout  << "reverse_iterator: "  << std::endl;
	ft::vector<int>::reverse_iterator	r_ft_it;
	for (r_ft_it = third.rbegin(); r_ft_it != third.rend(); r_ft_it ++)
	{
		std::cout << *r_ft_it << std::endl;
	}
	
	return (EXIT_SUCCESS);
}

void	vectorTest(void)
{
	example1();
}