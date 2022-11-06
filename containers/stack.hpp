/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:58:21 by ilya              #+#    #+#             */
/*   Updated: 2022/11/04 21:48:30 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

/**
 * https://en.cppreference.com/w/cpp/container/stack
 */

namespace ft
{
	/*	generic template */
	template < class T, class Container = ft::vector<T> > 
	class stack
	{
		public:
			/*	Member types */
			typedef Container							container_type;
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;
			typedef typename Container::reference		reference;
			typedef typename Container::const_reference	const_reference;

		public:
			/*	Canonical form */
			explicit		stack(const container_type &cont = container_type());
			stack&			operator=(const stack &other);
			~stack();

		public:
			/*	Member functions */
			reference			top();
			const_reference		top() 	const;
			bool				empty() const;
			size_type			size() 	const;
			void				push(const_reference value);
			void				pop();

		protected:
			container_type	_cont;

		public:
		
			/*	Non-member functions */

			template <typename _T, typename _Cont>
			friend bool	operator==(	const stack<_T, _Cont> &lhs,
									const stack<_T, _Cont> &rhs);

			template <typename _T, typename _Cont>
			friend bool	operator!=(	const stack<_T, _Cont> &lhs,
									const stack<_T, _Cont> &rhs);

			template <typename _T, typename _Cont>
			friend bool	operator>(	const stack<_T, _Cont> &lhs,
									const stack<_T, _Cont> &rhs);

			template <typename _T, typename _Cont>
			friend bool	operator>=(	const stack<_T, _Cont> &lhs,
									const stack<_T, _Cont> &rhs);

			template <typename _T, typename _Cont>
			friend bool	operator<(	const stack<_T, _Cont> &lhs,
									const stack<_T, _Cont> &rhs);

			template <typename _T, typename _Cont>
			friend bool	operator<=(	const stack<_T, _Cont> &lhs,
									const stack<_T, _Cont> &rhs);

	};	//end of "class stack"

}	//end of "namespace	ft"

#include "stack.tpp"

#endif