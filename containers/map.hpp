/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:13:07 by ilya              #+#    #+#             */
/*   Updated: 2022/11/04 18:57:39 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>					/*	std::allocator */
# include <stdexcept>				/* 	try...catch */
# include <../utils/utility.hpp>	/*	ft::pair */
# include <../utils/functional.hpp>	/*	ft::less */
# include "../utils/algorithm.hpp"	/*	equal & lex_compare */

/**
 * https://en.cppreference.com/w/cpp/container/map
 */

namespace	ft
{
	/*	generic template */
	template <
		typename Key,
		typename T,
		typename Compare = std::less<Key>,
		typename Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		
		public:
			/*	Member types */
			typedef Key						key_type;
			typedef T						mapped_type;
			typedef ft::pair<const Key, T>	value_type;
			typedef Compare					key_compare;
			typedef size_t					size_type;
			typedef ptrdiff_t				difference_type;
			typedef Allocator				allocator_type;
			typedef value_type				&reference;
			typedef const value_type		&const_reference;
			typedef value_type				*pointer;
			typedef const value_type		*const_pointer;

		public:
			/*	Canonical form */
			//
			
	};	//end of "class map"

}	//end of "namespace	ft"

#endif