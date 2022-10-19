/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:58:23 by ilya              #+#    #+#             */
/*   Updated: 2022/10/19 12:49:41 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory> 				/*	std::allocator */
# include <algorithm> 			/*	std::swap */
# include <iostream>			/*	std::cout */

namespace	ft
{
	/*	generic template */
	template < class T, class Allocator = std::allocator<T> >

	class vector
	{
		public:
			/*	Member types */
			typedef	T											value_type;
			typedef	Allocator									allocator_type;
			typedef	typename allocator_type::size_type			size_type;			//size_t
			typedef	typename allocator_type::difference_type	difference_type;	//ptrdiff_t
			typedef	typename allocator_type::reference			reference;
			typedef	typename allocator_type::const_reference	const_reference;
			typedef	typename allocator_type::pointer			pointer;
			typedef	typename allocator_type::const_pointer		const_pointer;
			
			/*	Member types iterators */
			// typedef random_access_it<T>						iterator;
			// typedef random_access_it<const T>				const_iterator;
			// typedef v_reverse_iter<iterator>				reverse_iterator;
			// typedef v_reverse_iter<const_iterator>			const_reverse_iterator;

		public:
			/*	Canonical form */
			explicit	vector(const allocator_type &alloc = allocator_type());		//empty
			explicit	vector(	size_type size,										//fill
								const_reference val = value_type(),
								const	allocator_type &alloc = allocator_type());
			// iterator later
			// vector(const vector &other);
			// vector	&operator=(const vector &rhs);
			~vector(void);

		public:
			/*	Member functions */
			void	clear();

		private:
			size_type					_size;
			size_type					_capacity;
			pointer						_array;
			allocator_type				_alloc;
			
	};	//end of "class vector"
	
}		//end of "namespace	ft"

# include "vector.tpp"

#endif