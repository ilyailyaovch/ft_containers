/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:05:43 by ilya              #+#    #+#             */
/*   Updated: 2022/11/08 15:33:50 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

# include "iterator.hpp"

namespace	ft
{
	/*	generic template (node<T>, T) */
	template < typename T, typename pair_type >
	class	bidirectional_iterator : public ft::iterator< ft::bidirectional_iterator_tag, T >
	{
		public:
			/*	Member types defines */
			typedef ft::iterator<ft::bidirectional_iterator_tag, T>	iterator_type;
			typedef typename iterator_type::iterator_category		iterator_category;
			typedef typename iterator_type::pointer					pointer;	// Node_pointer
			typedef typename iterator_type::reference				reference;	// Node_reference
			typedef typename iterator_type::value_type				value_type;
			typedef typename iterator_type::difference_type			difference_type;

		public:
			/*	Member types defines */
			bidirectional_iterator();
			bidirectional_iterator(pointer null_node, pointer ptr);
			bidirectional_iterator(const bidirectional_iterator &other);
			bidirectional_iterator	&operator=(const bidirectional_iterator &other);
			operator				bidirectional_iterator <const T, const pair_type> () const;
			virtual					~bidirectional_iterator();
		
		public:
			/*	Member types operators */
			bidirectional_iterator<T, pair_type>	&operator++();
			bidirectional_iterator<T, pair_type>	operator++(int);
			bidirectional_iterator<T, pair_type>	&operator--();
			bidirectional_iterator<T, pair_type>	operator--(int);
			pair_type								&operator*()	const;
			pair_type								*operator->()	const;
			pointer									get_node()	const;
			
			bool			operator==(const bidirectional_iterator &other) const;
			bool			operator!=(const bidirectional_iterator &other) const;

		private:
			pointer				_null_node;
			pointer				_elem;
	};

}	//end of "namespace	ft"

# include "bidirectional_iterator.tpp"

#endif