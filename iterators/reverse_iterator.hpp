/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:27:59 by ilya              #+#    #+#             */
/*   Updated: 2022/11/04 14:28:00 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REVERSE_ITERATOR_HPP
# define FT_REVERSE_ITERATOR_HPP

# include "iterator.hpp"

/**
 * https://en.cppreference.com/w/cpp/iterator/reverse_iterator
 */

namespace	ft
{
	template <typename It>
	class reverse_iterator : public ft::iterator<	typename ft::iterator_traits<It>::iterator_category,
													typename ft::iterator_traits<It>::value_type>
	{
		public:
			/*	Member types defines */
			typedef It													iterator_type;
			typedef typename iterator_type::iterator_category			iterator_category;
			typedef typename iterator_type::value_type					value_type;
			typedef typename iterator_type::difference_type				difference_type;
			typedef typename iterator_type::pointer						pointer;
			typedef typename iterator_type::reference					reference;
		public:
			/*	Canonical form */
			reverse_iterator();
			explicit			reverse_iterator(iterator_type it);
			reverse_iterator	&operator=(const reverse_iterator &other);
			template <typename Iter>
			reverse_iterator (const reverse_iterator<Iter> &other);
			virtual			~reverse_iterator();
		public:
			/*	Member functions */
			reference				operator*() const;
			pointer					operator->() const;
			reverse_iterator<It>	operator-(difference_type n) const;
			reverse_iterator<It>	operator+(difference_type n) const;
			reverse_iterator<It>	&operator-=(difference_type n);
			reverse_iterator<It>	&operator+=(difference_type n);
			reverse_iterator<It>	&operator--();
			reverse_iterator<It>	operator--(int);
			reverse_iterator<It>	&operator++();
			reverse_iterator<It>	operator++(int);
			reference				operator[](difference_type n) const;
			iterator_type			base() const;
		protected:
			iterator_type	_elem;
	};

	/*	Non-member functions */

	template <typename It1, typename It2>
	bool	operator==(	const reverse_iterator<It1> &lhs,
						const reverse_iterator<It2> &rhs);

	template <typename It1, typename It2>
	bool	operator!=(	const reverse_iterator<It1> &lhs,
						const reverse_iterator<It2> &rhs);

	template <typename It1, typename It2>
	bool	operator<(	const reverse_iterator<It1> &lhs,
						const reverse_iterator<It2> &rhs);

	template <typename It1, typename It2>
	bool	operator<=(	const reverse_iterator<It1> &lhs,
						const reverse_iterator<It2> &rhs);

	template <typename It1, typename It2>
	bool	operator>(	const reverse_iterator<It1> &lhs,
						const reverse_iterator<It2> &rhs);

	template <typename It1, typename It2>
	bool	operator>=(	const reverse_iterator<It1> &lhs,
						const reverse_iterator<It2> &rhs);
	
	template <typename It>
	reverse_iterator<It> 
	operator+(	typename reverse_iterator<It>::difference_type n,
				const reverse_iterator<It> &it);

	template <typename It>
	typename reverse_iterator<It>::difference_type
	operator-(	const reverse_iterator<It> &lhs,
				const reverse_iterator<It> &rhs);

}	//end of "namespace	ft"

# include "reverse_iterator.tpp"

#endif