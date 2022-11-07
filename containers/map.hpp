/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:13:07 by ilya              #+#    #+#             */
/*   Updated: 2022/11/07 01:02:50 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>					/*	std::allocator */
# include <stdexcept>				/* 	try...catch */
# include "../utils/utility.hpp"	/*	ft::pair */
# include "../utils/functional.hpp"	/*	ft::less */
# include "../utils/algorithm.hpp"	/*	equal & lex_compare */
# include "../utils/rb_tree.hpp"	/*	ft::rb_tree */

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
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef ft::pair<const Key, T>						value_type;
			typedef Compare										key_compare;
			typedef Allocator									allocator_type;			
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::size_type			size_type;		//size_t
			typedef typename allocator_type::difference_type	difference_type;//ptrdiff_t

		public:
			/*	Member class */
			class value_compare
			{
				friend class map<key_type, value_type, key_compare, allocator_type>;
				protected:
					Compare comp;
					value_compare(Compare c){this->comp = c;}
				public:
					bool operator()(const value_type & x, const value_type & y) const 
					{
						return comp(x.first, y.first);
					} 
			};
			
		public:
			/*	Member types (Iterators) */
			typedef rb_tree<value_type, value_compare, allocator_type>	rb_tree;
			typedef typename rb_tree::iterator	iterator;
			
			
	};	//end of "class map"

}	//end of "namespace	ft"

#endif