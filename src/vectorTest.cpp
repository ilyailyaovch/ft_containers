/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorTest.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:17:08 by ilya              #+#    #+#             */
/*   Updated: 2022/11/01 14:33:57 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <memory>
#include <iostream>
#include "../containers/vector.hpp"
#include "../utils/colorHeader.hpp"

int example1(void) //Iterators
{
	std::cout << BOLDGREEN << "Example 1" << RESET << std::endl;
	std::cout << GREEN << "Iterators" << RESET << std::endl;
	ft::vector<int>		firstEmpty;
	ft::vector<int> 	second (3, 50);                       // four ints with value 100
	ft::vector<int> 	third (second);                       // four ints with value 100
	third[1] = 101;
	third[2] = 666;
	
	std::cout  << "random_access_operator: "  << std::endl;
	ft::vector<int>::iterator	ft_it;
	for (ft_it = third.begin(); ft_it != third.end(); ft_it ++)
	{
		std::cout << *ft_it << std::endl;
	}

	std::cout  << "reverse_iterator: "  << std::endl;
	ft::vector<int>::reverse_iterator	r_ft_it;
	for (r_ft_it = third.rbegin(); r_ft_it != third.rend(); r_ft_it++)
	{
		std::cout << *r_ft_it << std::endl;
	}
	
	return (EXIT_SUCCESS);
}

int example2(void) //Elem access
{
	std::cout << BOLDGREEN << "Example 2" << RESET << std::endl;
	std::cout << GREEN << "Elem access" << RESET << std::endl;
	ft::vector<int> 	second (3, 50);                       // four ints with value 100
	ft::vector<int> 	third (second);                       // four ints with value 100
	third[1] = 101;
	third[2] = 666;

	std::cout  << "operaror[]: "  << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << second[i] << std::endl;
	}

	std::cout  << "operaror[]: "  << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << third[i] << std::endl;
	}

	std::cout << ".at(): " << third.at(1) << std::endl;
	std::cout << ".front(): "<< third.front() << std::endl;
	std::cout << ".back(): "<< third.back() << std::endl;
	std::cout << ".data(): "<< *third.data() << std::endl;

	return (EXIT_SUCCESS);
}

int example3(void)	//Capacity
{
	std::cout << BOLDGREEN << "Example 3" << RESET << std::endl;
	std::cout << GREEN << "Capacity" << RESET << std::endl;
	ft::vector<int> 	second (3, 50);                       // four ints with value 100
	ft::vector<int> 	third (second);                       // four ints with value 100
	third[1] = 101;
	third[2] = 666;
	third.push_back(667);
	
	std::cout << ".empty(): " << third.empty() << std::endl;
	std::cout << ".size(): " << third.size() << std::endl;
	std::cout << ".max_size(): " << third.max_size() << std::endl;
	std::cout << ".capacity(): " << third.capacity() << std::endl;
	//reserve
	//resize
	
	return (EXIT_SUCCESS);
}

void	vectorTest(void)
{
	example1();	//Iterators
	example2();	//Elem access
	example3();	//Capacity
}