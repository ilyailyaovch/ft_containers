/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:58:23 by ilya              #+#    #+#             */
/*   Updated: 2022/11/07 19:01:10 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory> 										/*	std::allocator */
# include <stdexcept>									/* 	try...catch */
# include <cstddef>
# include "../iterators/random_access_iterator.hpp"		/*	random_access_iterator */
# include "../iterators/reverse_iterator.hpp"			/*	reverse_iterator */
# include "../utils/algorithm.hpp"						/*	equal & lex_compare */
# include "../utils/type_traits.hpp"					/*	enable_if & is_integral */

/**
 * https://en.cppreference.com/w/cpp/container/vector
 * https://en.cppreference.com/w/cpp/named_req/Allocator
 * https://en.cppreference.com/w/cpp/types/enable_if
 * */

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
			typedef random_access_iterator<const T>		const_iterator;
			typedef random_access_iterator<T>			iterator;
			typedef reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef	reverse_iterator<iterator>			reverse_iterator;

		public:
			/*	Canonical form */
			explicit	vector(const allocator_type &alloc = allocator_type());		//empty
			explicit	vector(	size_type n,										//fill
								const_reference val = value_type(),
								const	allocator_type &alloc = allocator_type());
			template <typename InputIterator>
			vector(	InputIterator first, InputIterator last,
					const allocator_type &alloc = allocator_type(),
					typename enable_if<!is_integral<InputIterator>::value, bool>::type = true);
			vector(const vector &copy);
			vector&	operator=(const vector &rhs);
			~vector( void );

		public:
			/*	Member functions (Iterators) */
			iterator					begin();
			const_iterator				begin() const;
			iterator					end();
			const_iterator				end() const;
			reverse_iterator			rbegin();
			const_reverse_iterator		rbegin() const;
			reverse_iterator			rend();
			const_reverse_iterator		rend() const;

		public:
			/* Member functions (Capacity) */
			bool 						empty() const;
			size_type 					size() const;
			size_type 					max_size() const;
			size_type					capacity() const;
			void 						reserve(size_type new_cap);
			void						resize(size_type n, value_type val = value_type());

		public:
			/* Member functions (Element access) */
			reference					operator[](size_type n);
			const_reference				operator[](size_type n) const;
			reference					at(size_type pos);
			const_reference				at(size_type pos) const;
			reference					front();
			const_reference				front() const;
			reference					back();
			const_reference				back() const;
			pointer						data();
			const_pointer				data() const;

		public:
			/*	Member functions (Modifiers) */
			void						clear();
			void						swap(vector &other);
			iterator					erase(iterator pos);
			iterator					erase(iterator first, iterator last);
			void						push_back(const value_type &val);
			void						pop_back();
			iterator					insert(iterator pos, const T &value);
			void						insert(iterator pos,size_type count, const T &value);
			void						assign(size_type n, const value_type &val);
			template <typename InputIt>
			void	insert(	iterator pos, InputIt first, InputIt last,
							typename enable_if<!is_integral<InputIt>::value, bool>::type = true);
			template <typename InputIt>
			void	assign(	InputIt first, InputIt last,
							typename enable_if<!is_integral<InputIt>::value, bool>::type = true);
		
		public:
			/*	Member functions (Allocator) */
			allocator_type				get_allocator() const;
			
		private:
			/*	Attributes */
			size_type			_size;
			size_type			_capacity;
			pointer				_array;
			allocator_type		_alloc;
			
	};	//end of "class vector"

	/*	Non-member functions */

	template <typename T, typename Allocator>
	void	swap(vector<T, Allocator> &lhs, vector<T, Allocator> &rhs);
	
	template <typename T, typename Allocator>
	bool	operator==(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs);
	
	template <typename T, typename Allocator>
	bool	operator!=(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs);

	template <typename T, typename Allocator>
	bool	operator<(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs);

	template <typename T, typename Allocator>
	bool	operator<=(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs);

	template <typename T, typename Allocator>
	bool	operator>(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs);

	template <typename T, typename Allocator>
	bool	operator>=(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs);
	
}	//end of "namespace	ft"

# include "vector.tpp"

#endif