/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackTest.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:58:11 by ilya              #+#    #+#             */
/*   Updated: 2022/11/12 02:32:44 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "../containers/stack.hpp"
#include "../utils/colorHeader.hpp"

static int	example1()
{
	
	std::cout << MAGENTA << "Example 1" << RESET << std::endl;
	std::cout << GREEN << "Constructor & member func" << RESET << std::endl;
	
	ft::stack<int, ft::vector<int> >	st;
	
	std::cout << GREEN;
	std::cout << "ft::stack -> size(): " << st.size();
	st.push(42);
	std::cout << ", push[42], top(): " << st.top();
	std::cout << ", size(): " << st.size();
	st.push(336);
	st.push(672);
	std::cout << ", push[336], push[672], top(): " << st.top();
	st.pop();
	std::cout << ", pop(), top: " << st.top();
	std::cout << ", empty(): " << st.empty();
	std::cout << ", size(): " << st.size() << std::endl;
	std::cout << RESET;
	
	return (EXIT_SUCCESS);
}

static int	example2()
{
	std::cout << MAGENTA << "Example 2" << RESET << std::endl;
	std::cout << GREEN << "operator= & non-member func" << RESET << std::endl;
	
	ft::stack<int, ft::vector<int> >	st;

	std::cout << GREEN;
	std::cout << "ft::stack st -> size: " << st.size();
	st.push(42);
	st.push(336);
	st.push(672);
	std::cout << ", push[42], push[336], push[672] ";
	std::cout << "st.top(): " << st.top() << std::endl;

	ft::stack<int, ft::vector<int> >	st2 = st;
	std::cout << "ft::stack st2 = st -> size: " << st.size();
	std::cout << ", st2.top(): " << st2.top() << std::endl;

	std::cout << "non-mem: ==: " << (st == st2);
	std::cout << ", !=: " << (st != st2);
	std::cout << ", >: " << (st > st2);
	std::cout << ", >=: " << (st >= st2);
	std::cout << ", <: " << (st < st2);
	std::cout << ", <=: " << (st <= st2) << std::endl;
	std::cout << RESET;
	
	return (EXIT_SUCCESS);
}

void	stackTest(void)
{	
	std::cout << BOLDBLUE << "=================================" << RESET << std::endl;
	std::cout << BOLDBLUE << "============StackTest============" << RESET << std::endl;
	std::cout << BOLDBLUE << "=================================" << RESET << std::endl;

	example1();
	example2();
}