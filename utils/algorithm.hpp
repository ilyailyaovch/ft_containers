/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:18:08 by vismaily          #+#    #+#             */
/*   Updated: 2022/11/11 14:20:32 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALGORITHM_HPP
# define FT_ALGORITHM_HPP

/**
 * https://en.cppreference.com/w/cpp/header/algorithm
 * https://en.cppreference.com/w/cpp/algorithm/equal
 * https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare
 */

namespace	ft
{
	/*	Equal */

	template <typename InputIt1, typename InputIt2>
	bool	equal(InputIt1 first1, InputIt1 last1, InputIt2 first2);

	/*	Lexicographical_compare */

	template <typename InputIt1, typename InputIt2>
	bool	lexicographical_compare(InputIt1 first1, InputIt1 last1,
									InputIt2 first2, InputIt2 last2);

}	//end of "namespace	ft"

# include "algorithm.tpp"

#endif
