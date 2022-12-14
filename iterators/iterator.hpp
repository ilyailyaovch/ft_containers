/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:27:51 by ilya              #+#    #+#             */
/*   Updated: 2022/11/12 21:42:04 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITERATOR_HPP
# define FT_ITERATOR_HPP

# include <iterator>

/**
 * https://en.cppreference.com/w/cpp/iterator/iterator_traits
 */

namespace ft
{
	/*=================================*/
	/*	Iterators tags
 	*	category to which the iterator belongs to. */

	struct	input_iterator_tag	{};
	struct	output_iterator_tag	{};
	struct	forward_iterator_tag 		: public ft::input_iterator_tag {};
	struct	bidirectional_iterator_tag	: public ft::forward_iterator_tag {};
	struct	random_access_iterator_tag	: public bidirectional_iterator_tag {};

	/*=================================*/
	/*	Iterator template class */

	template <	typename Category,
				typename T,
				typename Distance = std::ptrdiff_t,
				typename Pointer = T*,
				typename Reference = T& >
	struct	iterator
	{
		typedef Category	iterator_category;	//one of the iterator's tags
		typedef T			value_type;			//the type pointed to by iterator
		typedef Distance	difference_type;	//distance between iterators
		typedef Pointer		pointer;			//represents a pointer-to-value_type
		typedef Reference	reference;			//represents a reference-to-value_type
	};

	/*=================================*/
	/*	Iterator traits	
	 * The iterator_traits class template comes with a default definition 
	 * that obtains these types from the iterator type itself (see below).
	 * It is also specialized for pointers (T*) and pointers to const (const T*).
	 */

	template <typename Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::iterator_category	iterator_category;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
	};

	template <typename T>
	struct iterator_traits< T* >
	{
		typedef random_access_iterator_tag				iterator_category;
		typedef	T										value_type;
		typedef	ptrdiff_t								difference_type;
		typedef	T*										pointer;
		typedef	T&										reference;
	};

	template <typename T>
	struct iterator_traits< const T* >
	{
		typedef random_access_iterator_tag				iterator_category;
		typedef	T										value_type;
		typedef	ptrdiff_t								difference_type;
		typedef	const T*								pointer;
		typedef	const T&								reference;
	};

	/*=================================*/
	/*	Distance
	*	type to represent the difference between two iterators. */

	template <typename InputIt>
	typename ft::iterator_traits<InputIt>::difference_type
	distance(InputIt first, InputIt last)
	{
		typename ft::iterator_traits<InputIt>::difference_type	dist = 0;

		while (first != last)
		{
			++dist;
			++first;
		}
		return (dist);
	}

}	//end of "namespace	ft"

#endif