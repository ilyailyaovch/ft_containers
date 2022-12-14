/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapTest.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:45:22 by ilya              #+#    #+#             */
/*   Updated: 2022/11/12 13:29:57 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "../containers/map.hpp"
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
	/* Example for pair and make_pair */

	std::pair<int, std::string>	pair1;
	std::cout << MAGENTA << "Example 1" << RESET << std::endl;
	std::cout << YELLOW;
	std::cout << "std::pair -> first: " << pair1.first;
	std::cout << ", second: " << pair1.second;
	pair1 = std::make_pair(1, "Ilya");
	std::cout << ", first: " << pair1.first;
	std::cout << ", second: " << pair1.second;
	std::pair<int, std::string>	pair2(2, "HI");
	std::cout << ", first: " << pair2.first;
	std::cout << ", second: " << pair2.second;
	std::pair<int, std::string>	pair3(pair1);
	std::cout << ", first: " << pair3.first;
	std::cout << ", second: " << pair3.second;
	std::cout << ", first: " << std::make_pair(4, 5).first;
	std::cout << ", second: " << std::make_pair(4, 5).second;
	std::pair<int, int>	pair4(1, 5);
	std::pair<int, int>	pair5(1, 4);
	std::cout << ", ==: " << (pair1 == pair2);
	std::cout << ", ==: " << (pair1 == pair3);
	std::cout << ", ==: " << (pair4 == pair5);
	std::cout << ", !=: " << (pair1 != pair2);
	std::cout << ", !=: " << (pair1 != pair3);
	std::cout << ", !=: " << (pair4 != pair5);
	std::cout << ", <: " << (pair1 < pair2);
	std::cout << ", <: " << (pair1 < pair3);
	std::cout << ", <: " << (pair4 < pair5);
	std::cout << ", <=: " << (pair1 <= pair2);
	std::cout << ", <=: " << (pair1 <= pair3);
	std::cout << ", <=: " << (pair4 <= pair5);
	std::cout << ", >: " << (pair1 > pair2);
	std::cout << ", >: " << (pair1 > pair3);
	std::cout << ", >: " << (pair4 > pair5);
	std::cout << ", >=: " << (pair1 >= pair2);
	std::cout << ", >=: " << (pair1 >= pair3);
	std::cout << ", >=: " << (pair4 >= pair5);
	std::cout << '.' << RESET << std::endl;

	ft::pair<int, std::string>	ft_pair1;
	std::cout << GREEN;
	std::cout << "ft::pair  -> first: " << ft_pair1.first;
	std::cout << ", second: " << ft_pair1.second;
	ft_pair1 = ft::make_pair(1, "Ilya");
	std::cout << ", first: " << ft_pair1.first;
	std::cout << ", second: " << ft_pair1.second;
	ft::pair<int, std::string>	ft_pair2(2, "HI");
	std::cout << ", first: " << ft_pair2.first;
	std::cout << ", second: " << ft_pair2.second;
	ft::pair<int, std::string>	ft_pair3(ft_pair1);
	std::cout << ", first: " << ft_pair3.first;
	std::cout << ", second: " << ft_pair3.second;
	std::cout << ", first: " << ft::make_pair(4, 5).first;
	std::cout << ", second: " << ft::make_pair(4, 5).second;
	ft::pair<int, int>	ft_pair4(1, 5);
	ft::pair<int, int>	ft_pair5(1, 4);
	std::cout << ", ==: " << (ft_pair1 == ft_pair2);
	std::cout << ", ==: " << (ft_pair1 == ft_pair3);
	std::cout << ", ==: " << (ft_pair4 == ft_pair5);
	std::cout << ", !=: " << (ft_pair1 != ft_pair2);
	std::cout << ", !=: " << (ft_pair1 != ft_pair3);
	std::cout << ", !=: " << (ft_pair4 != ft_pair5);
	std::cout << ", <: " << (ft_pair1 < ft_pair2);
	std::cout << ", <: " << (ft_pair1 < ft_pair3);
	std::cout << ", <: " << (ft_pair4 < ft_pair5);
	std::cout << ", <=: " << (ft_pair1 <= ft_pair2);
	std::cout << ", <=: " << (ft_pair1 <= ft_pair3);
	std::cout << ", <=: " << (ft_pair4 <= ft_pair5);
	std::cout << ", >: " << (ft_pair1 > ft_pair2);
	std::cout << ", >: " << (ft_pair1 > ft_pair3);
	std::cout << ", >: " << (ft_pair4 > ft_pair5);
	std::cout << ", >=: " << (ft_pair1 >= ft_pair2);
	std::cout << ", >=: " << (ft_pair1 >= ft_pair3);
	std::cout << ", >=: " << (ft_pair4 >= ft_pair5);
	std::cout << '.' << RESET << std::endl << std::endl;
}

static void	example2()
{
	/* Example 2 */
	/* Example for map constructors, size, empty, max_size */
	/* Example for iterators */

	std::pair<int, std::string>	pair1;
	pair1.first = 0; 
	pair1.second = "A"; 
	std::map<int, std::string> A;
	std::map<int, std::string>::iterator it1;
	std::cout << MAGENTA << "Example 2" << RESET << std::endl;
	std::cout << YELLOW;
	std::cout << "std::pair -> ";
	std::cout << "size: " << A.size();
	std::cout << ", empty: " << A.empty();
	std::cout << ", max_size: " << A.max_size();
	A.insert(pair1);
	std::cout << ", size: " << A.size();
	A.insert(std::make_pair(-1, "B"));
	std::cout << ", size: " << A.size();
	A.insert(std::make_pair(1, "C"));
	std::cout << ", pair -> first: " << pair1.first;
	std::cout << ", second: " << pair1.second;
	std::cout << ", size: " << A.size();
	std::cout << ", max_size: " << A.max_size();
	std::cout << ", empty: " << A.empty();
	it1 = A.begin();
	std::cout << ", it: " << (*it1).first;
	std::cout << ", " << it1->first;
	std::cout << ", " << it1->second;
	std::cout << ", " << (it1++)->first;
	std::cout << ", " << (++it1)->first;
	std::cout << ", " << (--it1)->second;
	std::cout << ", " << (it1--)->second;
	std::cout << ", " << it1->second;
	std::cout << '.' << RESET << std::endl;

	ft::pair<int, std::string>	ft_pair1;
	ft_pair1.first = 0; 
	ft_pair1.second = "A"; 
	ft::map<int, std::string> ft_A;
	ft::map<int, std::string>::iterator ft_it1;
	std::cout << GREEN;
	std::cout << "ft::pair  -> ";
	std::cout << "size: " << ft_A.size();
	std::cout << ", empty: " << ft_A.empty();
	std::cout << ", max_size: " << ft_A.max_size();
	ft_A.insert(ft_pair1);
	std::cout << ", size: " << ft_A.size();
	ft_A.insert(ft::make_pair(-1, "B"));
	std::cout << ", size: " << ft_A.size();
	ft_A.insert(ft::make_pair(1, "C"));
	std::cout << ", pair -> first: " << ft_pair1.first;
	std::cout << ", second: " << ft_pair1.second;
	std::cout << ", size: " << ft_A.size();
	std::cout << ", max_size: " << ft_A.max_size();
	std::cout << ", empty: " << ft_A.empty();
	ft_it1 = ft_A.begin();
	std::cout << ", it: " << (*ft_it1).first;
	std::cout << ", " << ft_it1->first;
	std::cout << ", " << ft_it1->second;
	std::cout << ", " << (ft_it1++)->first;
	std::cout << ", " << (++ft_it1)->first;
	std::cout << ", " << (--ft_it1)->second;
	std::cout << ", " << (ft_it1--)->second;
	std::cout << ", " << ft_it1->second;
	std::cout << '.' << RESET << std::endl << std::endl;
}

static void	example3()
{
	/* Example 3 */
	/* Example for iterators */

	std::map<int, std::string> A;
	std::map<int, std::string>::iterator it1;
	std::map<int, std::string>::iterator it2;
	it1 = A.begin();
	it2 = A.end();
	std::cout << MAGENTA << "Example 3" << RESET << std::endl;
	std::cout << YELLOW;
	std::cout << "std::map -> ";
	std::cout << (it1 == it2);
	A.insert(std::make_pair(0, "0A"));
	A.insert(std::make_pair(-2, "-2B"));
	std::cout << ", size: " << A.size();
	A.insert(std::make_pair(2, "2C"));
	A.insert(std::make_pair(-1, "-1D"));
	A.insert(std::make_pair(-3, "-3E"));
	A.insert(std::make_pair(1, "1F"));
	A.insert(std::make_pair(3, "3J"));
	std::cout << ", size: " << A.size();
	it1 = A.begin();
	it2 = A.end();
	std::cout << ", it: " << (it1 == it2);
	std::cout << ", " << it1->first;
	std::cout << ", " << (--it2)->second;
	std::cout << ", " << (it2--)->second;
	std::cout << ", " << it2->second;
	it2->second = "hello";
	it2 = A.end();
	std::cout << ", loop:";
	while (it1 != it2)
		std::cout << " " << (it1++)->second;
	std::cout << '.' << RESET << std::endl;

	ft::map<int, std::string> ft_A;
	ft::map<int, std::string>::iterator ft_it1;
	ft::map<int, std::string>::iterator ft_it2;
	ft_it1 = ft_A.begin();
	ft_it2 = ft_A.end();
	std::cout << GREEN;
	std::cout << "ft::map  -> ";
	std::cout << (ft_it1 == ft_it2);
	ft_A.insert(ft::make_pair(0, "0A"));
	ft_A.insert(ft::make_pair(-2, "-2B"));
	std::cout << ", size: " << ft_A.size();
	ft_A.insert(ft::make_pair(2, "2C"));
	ft_A.insert(ft::make_pair(-1, "-1D"));
	ft_A.insert(ft::make_pair(-3, "-3E"));
	ft_A.insert(ft::make_pair(1, "1F"));
	ft_A.insert(ft::make_pair(3, "3J"));
	std::cout << ", size: " << ft_A.size();
	ft_it1 = ft_A.begin();
	ft_it2 = ft_A.end();
	std::cout << ", it: " << (ft_it1 == ft_it2);
	std::cout << ", " << ft_it1->first;
	std::cout << ", " << (--ft_it2)->second;
	std::cout << ", " << (ft_it2--)->second;
	std::cout << ", " << ft_it2->second;
	ft_it2->second = "hello";
	ft_it2 = ft_A.end();
	std::cout << ", loop:";
	while (ft_it1 != ft_it2)
		std::cout << " " << (ft_it1++)->second;
	std::cout << '.' << RESET << std::endl << std::endl;
}

static void	example4()
{
	/* Example 4 */
	/* Example for const iterators */

	std::map<int, std::string> A;
	std::map<int, std::string>::const_iterator it1;
	std::map<int, std::string>::const_iterator it2;
	it1 = A.begin();
	it2 = A.end();
	std::cout << MAGENTA << "Example 4" << RESET << std::endl;
	std::cout << YELLOW;
	std::cout << "std::map -> ";
	std::cout << (it1 == it2);
	A.insert(std::make_pair(0, "0A"));
	A.insert(std::make_pair(-2, "-2B"));
	std::cout << ", size: " << A.size();
	A.insert(std::make_pair(2, "2C"));
	A.insert(std::make_pair(-1, "-1D"));
	A.insert(std::make_pair(-3, "-3E"));
	A.insert(std::make_pair(1, "1F"));
	A.insert(std::make_pair(3, "3J"));
	std::cout << ", size: " << A.size();
	it1 = A.begin();
	it2 = A.end();
	std::cout << ", it: " << (it1 == it2);
	std::cout << ", " << it1->first;
	std::cout << ", " << (--it2)->second;
	std::cout << ", " << (it2--)->second;
	std::cout << ", " << it2->second;
	it2 = A.end();
	std::cout << ", loop:";
	while (it1 != it2)
		std::cout << " " << (it1++)->second;
	it1 = A.begin();
	std::cout << ", loop:";
	while (it1 != it2)
		std::cout << " " << (--it2)->second;
	std::cout << '.' << RESET << std::endl;

	ft::map<int, std::string> ft_A;
	ft::map<int, std::string>::const_iterator ft_it1;
	ft::map<int, std::string>::const_iterator ft_it2;
	ft_it1 = ft_A.begin();
	ft_it2 = ft_A.end();
	std::cout << GREEN;
	std::cout << "ft::map  -> ";
	std::cout << (ft_it1 == ft_it2);
	ft_A.insert(ft::make_pair(0, "0A"));
	ft_A.insert(ft::make_pair(-2, "-2B"));
	std::cout << ", size: " << ft_A.size();
	ft_A.insert(ft::make_pair(2, "2C"));
	ft_A.insert(ft::make_pair(-1, "-1D"));
	ft_A.insert(ft::make_pair(-3, "-3E"));
	ft_A.insert(ft::make_pair(1, "1F"));
	ft_A.insert(ft::make_pair(3, "3J"));
	std::cout << ", size: " << ft_A.size();
	ft_it1 = ft_A.begin();
	ft_it2 = ft_A.end();
	std::cout << ", it: " << (ft_it1 == ft_it2);
	std::cout << ", " << ft_it1->first;
	std::cout << ", " << (--ft_it2)->second;
	std::cout << ", " << (ft_it2--)->second;
	std::cout << ", " << ft_it2->second;
	ft_it2 = ft_A.end();
	std::cout << ", loop:";
	while (ft_it1 != ft_it2)
		std::cout << " " << (ft_it1++)->second;
	ft_it1 = ft_A.begin();
	std::cout << ", loop:";
	while (ft_it1 != ft_it2)
		std::cout << " " << (--ft_it2)->second;
	std::cout << '.' << RESET << std::endl << std::endl;
}

static void	example5()
{
	/* Example 5 */
	/* Example for iterators comparison */

	std::map<int, std::string>				tree;
	std::map<int, std::string>::iterator	it1;
	std::map<int, std::string>::iterator	it2;
	std::cout << MAGENTA << "Example 5" << RESET << std::endl;
	std::cout << YELLOW;
	std::cout << "std::map ->";
	tree.insert(std::make_pair(0, "0A"));
	tree.insert(std::make_pair(-2, "-2B"));
	tree.insert(std::make_pair(2, "2C"));
	tree.insert(std::make_pair(-1, "-1D"));
	tree.insert(std::make_pair(-3, "-3E"));
	tree.insert(std::make_pair(1, "1F"));
	tree.insert(std::make_pair(3, "3J"));
	it1 = tree.begin();
	it2 = tree.begin();
	++it2;
	++it2;
	std::cout << " ==: " << (it2 == it1);
	std::cout << ", !=: " << (it2 != it1);
	it1 = it2;
	std::cout << ", ==: " << (it2 == it1);
	std::cout << ", !=: " << (it2 != it1);
	++it1;
	std::cout << ", ==: " << (it2 == it1);
	std::cout << ", !=: " << (it2 != it1);
	std::cout << '.' << RESET << std::endl;

	ft::map<int, std::string>			ft_tree;
	ft::map<int, std::string>::iterator	ft_it1;
	ft::map<int, std::string>::iterator	ft_it2;
	std::cout << GREEN;
	std::cout << "ft::map  ->";
	ft_tree.insert(ft::make_pair(0, "0A"));
	ft_tree.insert(ft::make_pair(-2, "-2B"));
	ft_tree.insert(ft::make_pair(2, "2C"));
	ft_tree.insert(ft::make_pair(-1, "-1D"));
	ft_tree.insert(ft::make_pair(-3, "-3E"));
	ft_tree.insert(ft::make_pair(1, "1F"));
	ft_tree.insert(ft::make_pair(3, "3J"));
	ft_it1 = ft_tree.begin();
	ft_it2 = ft_tree.begin();
	++ft_it2;
	++ft_it2;
	std::cout << " ==: " << (ft_it2 == ft_it1);
	std::cout << ", !=: " << (ft_it2 != ft_it1);
	ft_it1 = ft_it2;
	std::cout << ", ==: " << (ft_it2 == ft_it1);
	std::cout << ", !=: " << (ft_it2 != ft_it1);
	++ft_it1;
	std::cout << ", ==: " << (ft_it2 == ft_it1);
	std::cout << ", !=: " << (ft_it2 != ft_it1);
	std::cout << '.' << RESET << std::endl << std::endl;
}

static void	example6()
{
	/* Example 6 */
	/* Example for const iterators comparison */

	std::map<int, std::string>					tree;
	std::map<int, std::string>::const_iterator	it1;
	std::map<int, std::string>::const_iterator	it2;
	std::cout << MAGENTA << "Example 6" << RESET << std::endl;
	std::cout << YELLOW;
	std::cout << "std::map ->";
	tree.insert(std::make_pair(0, "0A"));
	tree.insert(std::make_pair(-2, "-2B"));
	tree.insert(std::make_pair(2, "2C"));
	tree.insert(std::make_pair(-1, "-1D"));
	tree.insert(std::make_pair(-3, "-3E"));
	tree.insert(std::make_pair(1, "1F"));
	tree.insert(std::make_pair(3, "3J"));
	it1 = tree.begin();
	it2 = tree.begin();
	++it2;
	++it2;
	std::cout << " ==: " << (it2 == it1);
	std::cout << ", !=: " << (it2 != it1);
	it1 = it2;
	std::cout << ", ==: " << (it2 == it1);
	std::cout << ", !=: " << (it2 != it1);
	++it1;
	std::cout << ", ==: " << (it2 == it1);
	std::cout << ", !=: " << (it2 != it1);
	std::cout << '.' << RESET << std::endl;

	ft::map<int, std::string>					ft_tree;
	ft::map<int, std::string>::const_iterator	ft_it1;
	ft::map<int, std::string>::const_iterator	ft_it2;
	std::cout << GREEN;
	std::cout << "ft::map  ->";
	ft_tree.insert(ft::make_pair(0, "0A"));
	ft_tree.insert(ft::make_pair(-2, "-2B"));
	ft_tree.insert(ft::make_pair(2, "2C"));
	ft_tree.insert(ft::make_pair(-1, "-1D"));
	ft_tree.insert(ft::make_pair(-3, "-3E"));
	ft_tree.insert(ft::make_pair(1, "1F"));
	ft_tree.insert(ft::make_pair(3, "3J"));
	ft_it1 = ft_tree.begin();
	ft_it2 = ft_tree.begin();
	++ft_it2;
	++ft_it2;
	std::cout << " ==: " << (ft_it2 == ft_it1);
	std::cout << ", !=: " << (ft_it2 != ft_it1);
	ft_it1 = ft_it2;
	std::cout << ", ==: " << (ft_it2 == ft_it1);
	std::cout << ", !=: " << (ft_it2 != ft_it1);
	++ft_it1;
	std::cout << ", ==: " << (ft_it2 == ft_it1);
	std::cout << ", !=: " << (ft_it2 != ft_it1);
	std::cout << '.' << RESET << std::endl << std::endl;
}

static void	example7()
{
	/* Example 7 */
	/* Example for const and non-const iterators comparison */

	std::map<int, std::string>					tree;
	std::map<int, std::string>::iterator		it1;
	std::map<int, std::string>::const_iterator	it2;
	std::cout << MAGENTA << "Example 7" << RESET << std::endl;
	std::cout << YELLOW;
	std::cout << "std::map ->";
	tree.insert(std::make_pair(0, "0A"));
	tree.insert(std::make_pair(-2, "-2B"));
	tree.insert(std::make_pair(2, "2C"));
	tree.insert(std::make_pair(-1, "-1D"));
	tree.insert(std::make_pair(-3, "-3E"));
	tree.insert(std::make_pair(1, "1F"));
	tree.insert(std::make_pair(3, "3J"));
	it1 = tree.begin();
	it2 = tree.begin();
	++it2;
	++it2;
	std::cout << " ==: " << (it2 == it1);
	std::cout << ", !=: " << (it2 != it1);
	++it1;
	++it1;
	std::cout << ", ==: " << (it2 == it1);
	std::cout << ", !=: " << (it2 != it1);
	++it1;
	std::cout << ", ==: " << (it2 == it1);
	std::cout << ", !=: " << (it2 != it1);
	std::cout << '.' << RESET << std::endl;

	ft::map<int, std::string>					ft_tree;
	ft::map<int, std::string>::iterator			ft_it1;
	ft::map<int, std::string>::const_iterator	ft_it2;
	std::cout << GREEN;
	std::cout << "ft::map  ->";
	ft_tree.insert(ft::make_pair(0, "0A"));
	ft_tree.insert(ft::make_pair(-2, "-2B"));
	ft_tree.insert(ft::make_pair(2, "2C"));
	ft_tree.insert(ft::make_pair(-1, "-1D"));
	ft_tree.insert(ft::make_pair(-3, "-3E"));
	ft_tree.insert(ft::make_pair(1, "1F"));
	ft_tree.insert(ft::make_pair(3, "3J"));
	ft_it1 = ft_tree.begin();
	ft_it2 = ft_tree.begin();
	++ft_it2;
	++ft_it2;
	std::cout << " ==: " << (ft_it2 == ft_it1);
	std::cout << ", !=: " << (ft_it2 != ft_it1);
	++ft_it1;
	++ft_it1;
	std::cout << ", ==: " << (ft_it2 == ft_it1);
	std::cout << ", !=: " << (ft_it2 != ft_it1);
	++ft_it1;
	std::cout << ", ==: " << (ft_it2 == ft_it1);
	std::cout << ", !=: " << (ft_it2 != ft_it1);
	std::cout << '.' << RESET << std::endl << std::endl;
}

static void	example8()
{
	/* Example 8 */
	/* Example for other compare function */

	std::map<int, std::string, std::greater<int> > A;
	std::map<int, std::string, std::greater<int> >::iterator it1;
	std::map<int, std::string, std::greater<int> >::iterator it2;
	it1 = A.begin();
	it2 = A.end();
	std::cout << MAGENTA << "Example 8" << RESET << std::endl;
	std::cout << YELLOW;
	std::cout << "std::map -> ";
	std::cout << (it1 == it2);
	A.insert(std::make_pair(0, "0A"));
	A.insert(std::make_pair(-2, "-2B"));
	std::cout << " size: " << A.size();
	A.insert(std::make_pair(2, "2C"));
	A.insert(std::make_pair(-1, "-1D"));
	A.insert(std::make_pair(-3, "-3E"));
	A.insert(std::make_pair(1, "1F"));
	A.insert(std::make_pair(3, "3J"));
	std::cout << ", size: " << A.size();
	it1 = A.begin();
	it2 = A.end();
	std::cout << ", it: " << (it1 == it2);
	std::cout << ", " << it1->first;
	std::cout << ", " << (--it2)->second;
	std::cout << ", " << (it2--)->second;
	std::cout << ", " << it2->second;
	it2->second = "hello";
	it2 = A.end();
	std::cout << ", loop:";
	while (it1 != it2)
		std::cout << " " << (it1++)->second;
	std::cout << '.' << RESET << std::endl;

	ft::map<int, std::string, std::greater<int> > ft_A;
	ft::map<int, std::string, std::greater<int> >::iterator ft_it1;
	ft::map<int, std::string, std::greater<int> >::iterator ft_it2;
	ft_it1 = ft_A.begin();
	ft_it2 = ft_A.end();
	std::cout << GREEN;
	std::cout << "ft::map  -> ";
	std::cout << (ft_it1 == ft_it2);
	ft_A.insert(ft::make_pair(0, "0A"));
	ft_A.insert(ft::make_pair(-2, "-2B"));
	std::cout << " size: " << ft_A.size();
	ft_A.insert(ft::make_pair(2, "2C"));
	ft_A.insert(ft::make_pair(-1, "-1D"));
	ft_A.insert(ft::make_pair(-3, "-3E"));
	ft_A.insert(ft::make_pair(1, "1F"));
	ft_A.insert(ft::make_pair(3, "3J"));
	std::cout << ", size: " << ft_A.size();
	ft_it1 = ft_A.begin();
	ft_it2 = ft_A.end();
	std::cout << ", it: " << (ft_it1 == ft_it2);
	std::cout << ", " << ft_it1->first;
	std::cout << ", " << (--ft_it2)->second;
	std::cout << ", " << (ft_it2--)->second;
	std::cout << ", " << ft_it2->second;
	ft_it2->second = "hello";
	ft_it2 = ft_A.end();
	std::cout << ", loop:";
	while (ft_it1 != ft_it2)
		std::cout << " " << (ft_it1++)->second;
	std::cout << '.' << RESET << std::endl << std::endl;
}

static void	example9()
{
	/* Example 9 */
	/* Example for reverse iterator */

	std::map<int, std::string>						A;
	std::map<int, std::string>::reverse_iterator	it1;
	std::map<int, std::string>::reverse_iterator	it2;
	it1 = A.rbegin();
	it2 = A.rend();
	std::cout << MAGENTA << "Example 9" << RESET << std::endl;
	std::cout << YELLOW;
	std::cout << "std::map -> ";
	std::cout << (it1 == it2);
	A.insert(std::make_pair(0, "0A"));
	A.insert(std::make_pair(-2, "-2B"));
	A.insert(std::make_pair(2, "2C"));
	A.insert(std::make_pair(-1, "-1D"));
	A.insert(std::make_pair(-3, "-3E"));
	A.insert(std::make_pair(1, "1F"));
	A.insert(std::make_pair(3, "3J"));
	it1 = A.rbegin();
	it2 = A.rend();
	std::cout << " it: " << (it1 == it2);
	std::cout << ", " << it1->first;
	std::cout << ", " << (--it2)->second;
	std::cout << ", " << (it2--)->second;
	std::cout << ", " << it2->second;
	it2->second = "hello";
	it2 = A.rend();
	std::cout << ", loop:";
	while (it1 != it2)
		std::cout << " " << (it1++)->second;
	std::cout << '.' << RESET << std::endl;

	ft::map<int, std::string>					ft_A;
	ft::map<int, std::string>::reverse_iterator ft_it1;
	ft::map<int, std::string>::reverse_iterator ft_it2;
	ft_it1 = ft_A.rbegin();
	ft_it2 = ft_A.rend();
	std::cout << GREEN;
	std::cout << "ft::map  -> ";
	std::cout << (ft_it1 == ft_it2);
	ft_A.insert(ft::make_pair(0, "0A"));
	ft_A.insert(ft::make_pair(-2, "-2B"));
	ft_A.insert(ft::make_pair(2, "2C"));
	ft_A.insert(ft::make_pair(-1, "-1D"));
	ft_A.insert(ft::make_pair(-3, "-3E"));
	ft_A.insert(ft::make_pair(1, "1F"));
	ft_A.insert(ft::make_pair(3, "3J"));
	ft_it1 = ft_A.rbegin();
	ft_it2 = ft_A.rend();
	std::cout << " it: " << (ft_it1 == ft_it2);
	std::cout << ", " << ft_it1->first;
	std::cout << ", " << (--ft_it2)->second;
	std::cout << ", " << (ft_it2--)->second;
	std::cout << ", " << ft_it2->second;
	ft_it2->second = "hello";
	ft_it2 = ft_A.rend();
	std::cout << ", loop:";
	while (ft_it1 != ft_it2)
		std::cout << " " << (ft_it1++)->second;
	std::cout << '.' << RESET << std::endl << std::endl;
}

static int example10()
{
	// initialize container
    std::map<int, int> mp1, mp2;
    mp1.insert(std::make_pair(0, .2));
    std::cout << MAGENTA << "Example 10" << RESET << std::endl;
	std::cout << YELLOW;
    std::cout << "The max size of mp1 is " << mp1.max_size();
    std::cout << "\nThe max size of mp2 is " << mp2.max_size();
	std::cout << RESET << std::endl;

	std::cout << GREEN;
	ft::map<int, int> 		ft_mp1, ft_mp2;
	ft_mp1.insert(ft::make_pair(0, .2));
	std::cout << GREEN;
    std::cout << "The max size of mp1 is " << mp1.max_size();
    std::cout << "\nThe max size of mp2 is " << mp2.max_size();
	std::cout << RESET << std::endl;

    return 0;
}

void	mapTest()
{
	std::cout << BOLDBLUE << "=================================" << RESET << std::endl;
	std::cout << BOLDBLUE << "=============MapTest=============" << RESET << std::endl;
	std::cout << BOLDBLUE << "=================================" << RESET << std::endl;

	example1();
	example2();
	example3();
	example4();
	example5();
	example6();
	example7();
	example8();
	example9();
	example10();
}
