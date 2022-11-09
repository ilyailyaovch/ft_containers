/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:05:50 by ilya              #+#    #+#             */
/*   Updated: 2022/11/09 11:34:28 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_HPP
# define  RB_TREE_HPP

# include "../utils/rb_node.hpp"

# include <memory>
# include <iostream>
# include "../iterators/bidirectional_iterator.hpp"
# include "../iterators/reverse_iterator.hpp"
# include "../utils/functional.hpp"	/*	NOT implemented */
# include "../utils/rb_node.hpp"	/*	ft::rb_node */

namespace	ft
{
	template < typename T, typename Compare = std::less<T>, typename Alloc = std::allocator<T> >
	class	rb_tree
	{
		public:
			/* Member types */
			typedef T												value_type;
			typedef Compare											key_compare;
			typedef Alloc											allocator_type;
			typedef rb_node<value_type>								*node_ptr;
			typedef size_t											size_type;
			typedef bidirectional_iterator<node_ptr, T>				iterator;
			typedef bidirectional_iterator<const node_ptr, const T>	const_iterator;
			typedef reverse_iterator<const_iterator>				const_reverse_iterator;
			typedef reverse_iterator<iterator>						reverse_iterator;
			typedef typename allocator_type::template rebind<rb_node<value_type> >::other
																	allocator_node_type;

		public:
			/* Constructors and destructors */
			rb_tree(const key_compare &comp = key_compare(),
					const allocator_type &alloc = allocator_type());
			rb_tree(const node_ptr head,
					const key_compare &comp = key_compare(),
					const allocator_type &alloc = allocator_type());
			rb_tree(const rb_tree &other);
			rb_tree	&operator=(const rb_tree &other);
			~rb_tree();

		public:
			/* Tree functional */
			node_ptr			create_node(value_type data);
			node_ptr			get_head() const;
			node_ptr			get_null() const;
			int					height(node_ptr head) const;
			int					height() const;
			node_ptr			min(node_ptr head) const;
			node_ptr			min() const;
			node_ptr			max(node_ptr head) const;
			node_ptr			max() const;
			node_ptr			successor(node_ptr head) const;
			node_ptr			successor() const;
			node_ptr			predecessor(node_ptr head) const;
			node_ptr			predecessor() const;

		public:
			/* Capacity */
			bool				empty() const;
			size_type			size() const;
			size_type			max_size() const;

		public:
			/* Operations */
			node_ptr			search(node_ptr head, const value_type &data) const;
			node_ptr			search(const value_type &data) const;

			/* Count */
			void				count_in_level(node_ptr head,
								const value_type &data, int level,
								size_type &count) const;
			size_type			count(node_ptr head, const value_type &data) const;
			size_type			count(const value_type &data) const;

			/* Bounds */
			iterator			lower_bound(const value_type &data);
			const_iterator		lower_bound(const value_type &data) const;
			iterator			upper_bound(const value_type &data);
			const_iterator		upper_bound(const value_type &data) const;

			ft::pair<iterator, iterator> 				equal_range(const value_type &data);
			ft::pair<const_iterator, const_iterator>	equal_range(const value_type &data) const;

		public:
			/* Tree walk */
			void				preorder_tree_walk(node_ptr head) const;
			void				preorder_tree_walk() const;
			void				inorder_tree_walk(node_ptr head) const;
			void				inorder_tree_walk() const;
			void				postorder_tree_walk(node_ptr head) const;
			void				postorder_tree_walk() const;

			void				print_level(node_ptr head, int level) const;
			void				print_level(int level) const;

			void				print_tree(node_ptr head) const;
			void				print_tree() const;

		public:
			/* Modifiers (Insert, erase, swap) */
			ft::pair<iterator, bool>	insert(node_ptr head, node_ptr new_node);
			ft::pair<iterator, bool>	insert(node_ptr new_node);
			iterator					insert(iterator hint, const value_type &value);
			ft::pair<iterator, bool>	insert(const value_type &value);
			void						insert_fixup(node_ptr new_node);
			void						erase(node_ptr old_node);
			size_type					erase(value_type value);
			void						erase(iterator pos);
			void						erase_fixup(node_ptr x);
			void						clear(node_ptr head);
			void						clear();
			void						swap(rb_tree &other);

		public:
			/* Iterators */
			iterator				begin();
			const_iterator			begin() const;
			iterator				end();
			const_iterator			end() const;
			reverse_iterator		rbegin();
			const_reverse_iterator	rbegin() const;
			reverse_iterator		rend();
			const_reverse_iterator	rend() const;

		public:
			/* Allocator */
			allocator_type			get_allocator() const;

		private:
			/* Helper methods */
			void				transplant(node_ptr u, node_ptr v);
			void				deep_copy(node_ptr other_node, node_ptr other_null);
			bool				comp_data(value_type v1, value_type v2) const;
			void				rotate_left(node_ptr node);
			void				rotate_right(node_ptr node);

		private:
			/* Member data */
			node_ptr			_head;
			node_ptr			_null_node;
			allocator_type		_alloc;
			allocator_node_type	_alloc_node;
			key_compare			_comp;
			size_type			_size;

	};	//end of "class	rb_tree"

}	//end of "namespace	ft"

# include "rb_tree.tpp"

#endif