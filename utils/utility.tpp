/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:40:56 by ilya              #+#    #+#             */
/*   Updated: 2022/11/04 15:09:20 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_TPP
# define UTILITY_TPP

# ifndef UTILITY_HPP
#  error utility.tpp should only be included from utility.hpp.
# endif

namespace ft
{
	/*=================================*/
	/*	Pair */

	template <typename T1, typename T2>
	pair<T1, T2>::pair():
	first(), second()
	{
	}

	template <typename T1, typename T2>
	pair<T1, T2>::pair(const first_type &a, const second_type &b):
	first(a), second(b)
	{
	}

	template <typename T1, typename T2>
	template <typename U1, typename U2>
	pair<T1, T2>::pair(const pair<U1, U2> &other) :
	first(other.first), second(other.second)
	{
	}

	template <typename T1, typename T2>
	pair<T1, T2>	&pair<T1, T2>::operator=(const pair &rhs)
	{
		if (this != &rhs)
		{
			this->first = rhs.first;
			this->second = rhs.second;
		}
		return (*this);
	}

	/*=================================*/
	/*	Pair Non-member functions */

	template <typename T1, typename T2>
	bool	operator==(const pair<T1, T2> &lhs,const pair<T1, T2> &rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <typename T1, typename T2>
	bool	operator!=(const pair<T1, T2> &lhs,const pair<T1, T2> &rhs)
	{
		return (!(lhs == rhs));
	}

	template <typename T1, typename T2>
	bool	operator<(const pair<T1, T2> &lhs,const pair<T1, T2> &rhs)
	{
		if (lhs.first < rhs.first)
			return (true);
		else if (lhs.first == rhs.first)
			return (lhs.second < rhs.second);
		return (false);
	}

	template <typename T1, typename T2>
	bool	operator<=(const pair<T1, T2> &lhs,const pair<T1, T2> &rhs)
	{
		return (!(rhs < lhs));
	}

	template <typename T1, typename T2>
	bool	operator>(const pair<T1, T2> &lhs,const pair<T1, T2> &rhs)
	{
		return (rhs < lhs);
	}

	template <typename T1, typename T2>
	bool	operator>=(const pair<T1, T2> &lhs,const pair<T1, T2> &rhs)
	{
		return (!(lhs < rhs));
	}

	/*=================================*/
	/*	Make_pair */
	
	template <typename T1, typename T2>
	pair<T1, T2>	make_pair(T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	}
	
}	//end of "namespace	ft"

#endif