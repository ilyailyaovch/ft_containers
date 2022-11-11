/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorTest.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:17:08 by ilya              #+#    #+#             */
/*   Updated: 2022/11/12 02:33:14 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <memory>
#include <iostream>
#include "../containers/vector.hpp"
#include "../utils/colorHeader.hpp"

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <utility>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <functional>

static void	example1()
{
	/* Example 1 */
	/* Example for constructor without parametrs */
	/* Example for size and capacity with int */
	/* Example for push_back */

	std::vector<int>	vec;
	std::cout << MAGENTA << "Example 1" << RESET << std::endl;
	std::cout << YELLOW;
	std::cout << "std::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	vec.push_back(42);
	std::cout << ", push_back[42] value[0]: " << vec[0];
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	vec.push_back(84);
	std::cout << ", push_back[84] value[1]: " << vec[1];
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	vec.push_back(168);
	std::cout << ", push_back[168] value[2]: " << vec.at(2);
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	vec.push_back(336);
	vec.push_back(672);
	std::cout << ", push_back[336],[672] value[3]: " << vec.at(3);
	std::cout << ", capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size() << '.';
	std::cout << RESET << std::endl;

	ft::vector<int>		ft_vec;
	std::cout << GREEN;
	std::cout << "ft::vector  -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	ft_vec.push_back(42);
	std::cout << ", push_back[42] value[0]: " << ft_vec[0];
	std::cout << ", capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	ft_vec.push_back(84);
	std::cout << ", push_back[84] value[1]: " << ft_vec[1];
	std::cout << ", capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	ft_vec.push_back(168);
	std::cout << ", push_back[168] value[2]: " << ft_vec.at(2);
	std::cout << ", capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	ft_vec.push_back(336);
	ft_vec.push_back(672);
	std::cout << ", push_back[336],[672] value[3]: " << ft_vec.at(3);
	std::cout << ", capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size() << '.' << std::endl;
	std::cout << RESET << std::endl;
}

static void	example2()
{
	/* Example 2 */
	/* Example for constructor with 2 parametrs with double */
	/* Example for operator[] */

	std::vector<double> vec(3, double(58));
	std::cout << MAGENTA << "Example 2" << RESET << std::endl;
	std::cout << std::fixed << std::setprecision(2) << YELLOW;
	std::cout << "std::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", value[2]: " << vec[2] << '.';
	std::cout << RESET << std::endl;

	ft::vector<double> ft_vec(3, double(58));
	std::cout << GREEN;
	std::cout << "ft::vector  -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << ", value[2]: " << ft_vec[2] << '.' << std::endl;
	std::cout << RESET << std::endl;
}

static void	example3()
{
	/* Example 3 */
	/* Example for const operator[] and for function at() with float */

	const std::vector<float> vec(10, float(-60));
	std::cout << MAGENTA << "Example 3" << RESET << std::endl;
	std::cout << YELLOW;
	std::cout << "std::vector -> at(3): " << vec.at(3);
	try
	{
		std::cout << ", at(13): " << vec.at(13) << '.';
	}
	catch (const std::out_of_range &e)
	{
		std::cout << e.what() << '.';
	}
	std::cout << RESET << std::endl;

	const ft::vector<float> ft_vec(10, float(-60));
	std::cout << GREEN;
	std::cout << "ft::vector  -> at(3): " << ft_vec.at(3);
	try
	{
		std::cout << ", at(13): " << ft_vec.at(13) << '.';
	}
	catch (const std::out_of_range &e)
	{
		std::cout << e.what() << '.';
	}
	std::cout << RESET << std::endl << std::endl;
}

static void	example4()
{
	/* Example 4 */
	/* Example for front() and back() functions */

	const std::vector<int> vec(3, int(58));
	std::cout << MAGENTA << "Example 4" << RESET << std::endl;
	std::cout << YELLOW;
	std::cout << "std::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", value[0]: " << vec[0];
	std::cout << ", front(): " << vec.front();
	std::cout << ", value[2]: " << vec[0];
	std::cout << ", back(): " << vec.back() << '.';
	std::cout << RESET << std::endl;

	const ft::vector<int> ft_vec(3, int(58));
	std::cout << GREEN;
	std::cout << "ft::vector  -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << ", value[0]: " << ft_vec[0];
	std::cout << ", front(): " << ft_vec.front();
	std::cout << ", value[2]: " << ft_vec[0];
	std::cout << ", back(): " << ft_vec.back() << '.';
	std::cout << RESET << std::endl << std::endl;
}

static void	example5()
{
	/* Example 5 */
	/* Example for data() */

	int	*p;

	std::vector<int> vec(5, int(41));
	std::cout << MAGENTA << "Example 5" << RESET << std::endl;
	std::cout << YELLOW;
	std::cout << "std::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	p = vec.data();
	std::cout << ", p[0]: " << p[0] << '.';
	std::cout << RESET << std::endl;

	ft::vector<int> ft_vec(5, int(41));
	std::cout << GREEN;
	std::cout << "ft::vector  -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	p = ft_vec.data();
	std::cout << ", p[0]: " << p[0] << '.';
	std::cout << RESET << std::endl << std::endl;
}

static void	example6()
{
	/* Example 6 */
	/* Example for max_size() and get_allocator() */

	long double	*p;

	std::vector<long double> vec(5, (long double)(41));
	std::cout << MAGENTA << "Example 6" << RESET << std::endl;
	std::cout << YELLOW;
	std::cout << "std::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", max_size: " << vec.max_size();

	p = vec.get_allocator().allocate(3);
	for (int i = 0; i < 3; ++i)
		vec.get_allocator().construct(&p[i], i);
	std::cout << ", allocated array:";
	for (int i = 0; i < 3; ++i)
	{
		std::cout << ' ' << p[i];
		vec.get_allocator().destroy(&p[i]);
	}
	vec.get_allocator().deallocate(p, 3);

	std::cout << '.' << RESET << std::endl;

	ft::vector<long double> ft_vec(5, (long double)(41));
	std::cout << GREEN;
	std::cout << "ft::vector  -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << ", max_size: " << ft_vec.max_size();

	p = ft_vec.get_allocator().allocate(3);
	for (int i = 0; i < 3; ++i)
		ft_vec.get_allocator().construct(&p[i], i);
	std::cout << ", allocated array:";
	for (int i = 0; i < 3; ++i)
	{
		std::cout << ' ' << p[i];
		ft_vec.get_allocator().destroy(&p[i]);
	}
	ft_vec.get_allocator().deallocate(p, 3);

	std::cout << '.' << RESET << std::endl << std::endl;
}

static void	example7()
{
	/* Example 7 */
	/* Example for push_back() and pop_back() */
	/* Example for clear() function */
	/* Example for empty() function */

	std::vector<int> vec(5, (int)(42));
	std::cout << MAGENTA << "Example 7" << RESET << std::endl;
	std::cout << YELLOW;
	std::cout << "std::vector -> capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();

	for (size_t i = 50; i < 55; ++i)
		vec.push_back(i);
	vec.pop_back();
	vec.pop_back();
	std::cout << ", is_empty: " << vec.empty();
	std::cout << ", values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	vec.clear();
	std::cout << ", after clear capacity: " << vec.capacity();
	std::cout << ", size: " << vec.size();
	std::cout << ", is_empty: " << vec.empty();
	std::cout << '.' << RESET << std::endl;

	ft::vector<int> ft_vec(5, (int)(42));
	std::cout << GREEN;
	std::cout << "ft::vector  -> capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();

	for (size_t i = 50; i < 55; ++i)
		ft_vec.push_back(i);
	ft_vec.pop_back();
	ft_vec.pop_back();
	std::cout << ", is_empty: " << ft_vec.empty();
	std::cout << ", values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	ft_vec.clear();
	std::cout << ", after clear capacity: " << ft_vec.capacity();
	std::cout << ", size: " << ft_vec.size();
	std::cout << ", is_empty: " << ft_vec.empty();
	std::cout << '.' << RESET << std::endl << std::endl;
}

static void	example8()
{
	/* Example 8 */
	/* Example for iterators */

	std::vector<int> vec;
	std::vector<int>::iterator	it;
	std::cout << MAGENTA << "Example 8" << RESET << std::endl;
	std::cout << YELLOW;
	std::cout << "std::vector -> ";

	for (size_t i = 50; i < 55; ++i)
		vec.push_back(i);
	std::cout << "values:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << ' ' << vec[i];
	it = vec.begin();
	std::cout << ", it_begin: " << *it;
	it = vec.begin() + 1;
	std::cout << ", it_begin + 1: " << *it;
	it += 1;
	std::cout << ", it += 1: " << *it;
	std::cout << ", it++: " << *(it++);
	std::cout << ", ++it: " << *(++it);
	it = vec.end() - 1;
	std::cout << ", it_end - 1: " << *it;
	it -= 2;
	std::cout << ", it -= 2: " << *it;
	it += 1;
	std::cout << ", it += 1: " << *it;
	std::cout << ", it[-1]: " << it[-1];
	std::cout << '.' << RESET << std::endl;

	ft::vector<int> ft_vec;
	ft::vector<int>::iterator	ft_it;
	std::cout << GREEN;
	std::cout << "ft::vector  -> ";

	for (size_t i = 50; i < 55; ++i)
		ft_vec.push_back(i);
	std::cout << "values:";
	for (size_t i = 0; i < ft_vec.size(); ++i)
		std::cout << ' ' << ft_vec[i];
	ft_it = ft_vec.begin();
	std::cout << ", it_begin: " << *ft_it;
	ft_it = ft_vec.begin() + 1;
	std::cout << ", it_begin + 1: " << *ft_it;
	ft_it += 1;
	std::cout << ", it += 1: " << *ft_it;
	std::cout << ", it++: " << *(ft_it++);
	std::cout << ", ++it: " << *(++ft_it);
	ft_it = ft_vec.end() - 1;
	std::cout << ", it_end - 1: " << *ft_it;
	ft_it -= 2;
	std::cout << ", it -= 2: " << *ft_it;
	ft_it += 1;
	std::cout << ", it += 1: " << *ft_it;
	std::cout << ", it[-1]: " << ft_it[-1];
	std::cout << '.' << RESET << std::endl << std::endl;
}

void	vectorTest(void)
{
	std::cout << BOLDBLUE << "=================================" << RESET << std::endl;
	std::cout << BOLDBLUE << "===========VectorTest============" << RESET << std::endl;
	std::cout << BOLDBLUE << "=================================" << RESET << std::endl;
	
	example1();
	example2();
	example3();
	example4();
	example5();
	example6();
	example7();
	example8();
}
