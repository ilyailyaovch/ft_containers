/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:27:26 by ilya              #+#    #+#             */
/*   Updated: 2022/11/04 14:41:00 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
# define UTILITY_HPP

/**
 * https://en.cppreference.com/w/cpp/header/utility
 * https://en.cppreference.com/w/cpp/utility/pair
 */

namespace	ft
{
	/*	Pair */
	
	template <typename T1, typename T2>
	struct	pair
	{
		typedef T1		first_type;
		typedef T2		second_type;

		first_type		first;
		second_type		second;

		pair();
		pair(const first_type &a, const second_type &b);
		template <typename U1, typename U2>
		pair(const pair<U1, U2> &pr);
		pair	&operator=(const pair &rhs);
	};

	/*	Pair Non-member functions */

	template <typename T1, typename T2>
	bool	operator==(const pair<T1, T2> &lhs,const pair<T1, T2> &rhs);

	template <typename T1, typename T2>
	bool	operator!=(const pair<T1, T2> &lhs,const pair<T1, T2> &rhs);

	template <typename T1, typename T2>
	bool	operator<(const pair<T1, T2> &lhs,const pair<T1, T2> &rhs);

	template <typename T1, typename T2>
	bool	operator<=(const pair<T1, T2> &lhs,const pair<T1, T2> &rhs);

	template <typename T1, typename T2>
	bool	operator>(const pair<T1, T2> &lhs,const pair<T1, T2> &rhs);

	template <typename T1, typename T2>
	bool	operator>=(const pair<T1, T2> &lhs,const pair<T1, T2> &rhs);

	/*	Make_pair */

	template <typename T1, typename T2>
	pair<T1, T2>	make_pair(T1 x, T2 y);
	

}	//end of "namespace	ft"

#endif