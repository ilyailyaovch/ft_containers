/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functional.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:27:07 by ilya              #+#    #+#             */
/*   Updated: 2022/11/08 15:29:33 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONAL_HPP
# define FUNCTIONAL_HPP

/**
 * https://en.cppreference.com/w/cpp/utility/functional
 * https://en.cppreference.com/w/cpp/utility/functional/less
 */

namespace	ft
{
	/*	unary_function is a base class for creating function objects with one argument. */
	template <typename Arg, typename Result>
	struct	unary_function
	{
		typedef Arg		argument_type;
		typedef Result	result_type;
	};

	/*	binary_function is a base class for creating function objects with two arguments. */
	template <typename Arg1, typename Arg2, typename Result>
	struct	binary_function
	{
		typedef Arg1 	first_argument_type;
		typedef Arg2 	second_argument_type;
		typedef Result	result_type;
	};

	/**	Function object for performing comparisons.
	 * Unless specialized, invokes operator< on type T.
	 * */
	template <typename T>
	struct	less : binary_function<T, T, bool>
	{
		bool	operator()(const T &x, const T &y) const
		{
			return (x < y);
		}
	};

	template <typename Pair>
	struct	select_first : unary_function<Pair, typename Pair::first_type>
	{
		typename Pair::first_type	&operator()(Pair &x)
		{
			return (x.first);
		}

		const typename Pair::first_type	&operator()(const Pair &x)
		{
			return (x.first);
		}
	};

	template <typename T>
	struct	select_self : unary_function<T, T>
	{
		T	&operator()(T &x)
		{
			return (x);
		}

		const T	&operator()(const T &x)
		{
			return (x);
		}
	};

}	//end of "namespace	ft"

#endif