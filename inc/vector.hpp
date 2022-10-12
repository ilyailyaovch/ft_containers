/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:58:23 by ilya              #+#    #+#             */
/*   Updated: 2022/10/12 14:03:57 by ilya             ###   ########.fr       */
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
	template < class T, class Alloc = std::allocator<T> >
	
	class vector{
		
		public:
		
			/*	member types */
			typedef	T								value_type;
			typedef	Alloc							allocator_type;
			// typedef	allocator_type::size_type		size_type;
			// typedef	allocator_type::difference_type	difference_type;
			// typedef	allocator_type::reference		reference;


		private:
			
		
	};	//end of "class vector"
	
}		//end of "namespace	ft"

#endif