/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:13:07 by ilya              #+#    #+#             */
/*   Updated: 2022/11/12 14:12:32 by ilya             ###   ########.fr       */
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
		typename Compare = ft::less<Key>,
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
				public:
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
			typedef rb_tree<value_type, key_compare, allocator_type> 	rb_tree;
			typedef typename rb_tree::iterator							iterator;
			typedef typename rb_tree::const_iterator					const_iterator;
			typedef typename rb_tree::reverse_iterator					reverse_iterator;
			typedef typename rb_tree::const_reverse_iterator			const_reverse_iterator;
		
		public:
			/*	Constructors and destructors */
			explicit	map(const key_compare &comp = key_compare(),
							const allocator_type &alloc = allocator_type());
			template <typename InputIterator>
			map(InputIterator first, InputIterator last,
					const key_compare &comp = key_compare(),
					const allocator_type &alloc = allocator_type());
			map(const map &other);
			map	&operator=(const map &other);
			~map();

		public:
			/*	Iterators */
			iterator						begin();
			const_iterator					begin() const;
			iterator						end();
			const_iterator					end() const;
			reverse_iterator				rbegin();
			const_reverse_iterator			rbegin() const;
			reverse_iterator				rend();
			const_reverse_iterator			rend() const;

		public:
			/* Capacity */
			bool							empty() const;
			size_type						size() const;
			size_type						max_size() const;

		public:
			/* Element access */
			mapped_type						&operator[](const key_type &key);
			mapped_type						&at(const key_type &key);
			const mapped_type				&at(const key_type &key) const;

		public:
			/* Modifires */
			ft::pair<iterator, bool>		insert(const value_type &val);
			iterator						insert(iterator it, const value_type &val);
			template <class InputIt> void	insert(InputIt first, InputIt last);
			void							erase(iterator pos);
			void							erase(iterator first, iterator last);
			size_type						erase(const key_type &key);
			void							swap(map &other);
			void							clear();

		public:
			/* Observers */
			key_compare						key_comp() const;
			value_compare					value_comp() const;

		public:
			/* Operations */
			iterator						find(const key_type &key);
			const_iterator					find(const key_type &key) const;
			size_type						count(const key_type &key) const;
			iterator						lower_bound(const key_type &key);
			const_iterator					lower_bound(const key_type &key) const;
			iterator						upper_bound(const key_type &key);
			const_iterator					upper_bound(const key_type &key) const;
			ft::pair<iterator, iterator>	equal_range(const Key &key);
			ft::pair<	const_iterator, 
						const_iterator>		equal_range(const Key &key) const;

		public:
			/* Allocator */
			allocator_type	get_allocator() const;

		private:
			/* Member data */
			rb_tree			_tree;

	};	//end of "class map"

	/*	Non-member functions */

	template <typename Key, typename T, typename Compare, typename Alloc>
	void	swap(	ft::map<Key, T, Compare, Alloc> &lhs,
					ft::map<Key, T, Compare, Alloc> &rhs);

	template <typename Key, typename T, typename Compare, typename Alloc>
	bool	operator==(	const ft::map<Key, T, Compare, Alloc> &lhs,
						const ft::map<Key, T, Compare, Alloc> &rhs);

	template <typename Key, typename T, typename Compare, typename Alloc>
	bool	operator!=(	const ft::map<Key, T, Compare, Alloc> &lhs,
						const ft::map<Key, T, Compare, Alloc> &rhs);

	template <typename Key, typename T, typename Compare, typename Alloc>
	bool	operator<(	const ft::map<Key, T, Compare, Alloc> &lhs,
						const ft::map<Key, T, Compare, Alloc> &rhs);

	template <typename Key, typename T, typename Compare, typename Alloc>
	bool	operator<=(	const ft::map<Key, T, Compare, Alloc> &lhs,
						const ft::map<Key, T, Compare, Alloc> &rhs);

	template <typename Key, typename T, typename Compare, typename Alloc>
	bool	operator>(	const ft::map<Key, T, Compare, Alloc> &lhs,
						const ft::map<Key, T, Compare, Alloc> &rhs);

	template <typename Key, typename T, typename Compare, typename Alloc>
	bool	operator>=(	const ft::map<Key, T, Compare, Alloc> &lhs,
						const ft::map<Key, T, Compare, Alloc> &rhs);

}	//end of "namespace	ft"

# include "map.tpp"

#endif