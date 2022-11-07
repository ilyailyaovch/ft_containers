/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:05:50 by ilya              #+#    #+#             */
/*   Updated: 2022/11/07 10:09:43 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_HPP
# define  RB_TREE_HPP

# include "../utils/rb_node.hpp"

# include <memory>
# include "../iterators/bidirectional_iterator.hpp"
# include "../iterators/reverse_iterator.hpp"
# include "../utils/functional.hpp"	/*	NOT implemented */
# include "../utils/rb_node.hpp"	/*	ft::rb_node */

namespace	ft
{
	template < typename T, typename Compare = std::less<T>, typename Alloc = std::allocator<T> >
	class	rb_tree
	{
		/* Member types */
		public:
			typedef T												value_type;
			typedef Compare											key_compare;
			typedef Alloc											allocator_type;
			typedef rb_node<value_type>								*node_ptr;
			typedef size_t											size_type;
			typedef bidirectional_iterator<node_ptr>				iterator;	//ptr!!!
			typedef bidirectional_iterator<const node_ptr>			const_iterator;
			typedef reverse_iterator<const_iterator>				const_reverse_iterator;
			typedef reverse_iterator<iterator>						reverse_iterator;
			typedef typename allocator_type::template rebind<rb_node<value_type> >::other \
																	allocator_node_type;

			
	};	//end of "class	rb_tree"

}	//end of "namespace	ft"

# include "rb_tree.tpp"

#endif