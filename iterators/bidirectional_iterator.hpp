/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:05:43 by ilya              #+#    #+#             */
/*   Updated: 2022/11/07 00:58:46 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

# include "iterator.hpp"

namespace	ft
{
	template < typename T >
	class	bidirectional_iterator : public ft::iterator< ft::bidirectional_iterator_tag, T >
	{
		public:
			/*	Member types defines */
			typedef ft::iterator<ft::bidirectional_iterator_tag, T>	iterator_type;
			typedef typename iterator_type::iterator_category		iterator_category;
			typedef typename iterator_type::pointer					pointer;
			typedef typename iterator_type::reference				reference;
			typedef typename iterator_type::value_type				value_type;
			typedef typename iterator_type::difference_type			difference_type;

		public:
			/*	Member types defines */
			bidirectional_iterator();
			bidirectional_iterator(pointer null_node, pointer ptr);
			bidirectional_iterator(const bidirectional_iterator &other);
			bidirectional_iterator		&operator=(const bidirectional_iterator &other);
			virtual						~bidirectional_iterator();
		
		public:
			bidirectional_iterator<T>	&operator++();
			bidirectional_iterator<T>	operator++(int);
			bidirectional_iterator<T>	&operator--();
			bidirectional_iterator<T>	operator--(int);
			value_type					&operator*()	const; //
			value_type					*operator->()	const; //
			pointer						get_node()	const;
			bool			operator==(const bidirectional_iterator &other) const;
			bool			operator!=(const bidirectional_iterator &other) const;

		private:
			pointer				_null_node;
			pointer				_elem;
	};

}	//end of "namespace	ft"

# include "bidirectional_iterator.tpp"

#endif