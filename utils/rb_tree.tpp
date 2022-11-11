/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 22:54:49 by ilya              #+#    #+#             */
/*   Updated: 2022/11/11 15:44:39 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_TPP
#define RB_TREE_TPP

namespace ft
{
	/*==========================================*/
	/*	Constructors and destructors */

	template < typename T, typename Compare, typename Alloc>
	rb_tree<T, Compare, Alloc>::rb_tree(const key_compare &comp, const allocator_type &alloc):
		_alloc(alloc), _alloc_node(allocator_node_type()), _comp(comp)
	{
		_null_node = this->_alloc_node.allocate(1);
		try
		{
			this->_alloc_node.construct(_null_node);
		}
		catch (...)
		{
			this->_alloc_node.deallocate(_null_node, 1);
			throw ;
		}
		this->_head = this->_null_node;
		_null_node->p= this->_head;
		_null_node->color = ft::BLACK;
		this->_size = 0;
	}

	template < typename T, typename Compare, typename Alloc>
	rb_tree<T, Compare, Alloc>::rb_tree
	(const node_ptr head, const key_compare &comp, const allocator_type &alloc):
		_alloc(alloc), _alloc_node(allocator_node_type()), _comp(comp)
	{
		this->_null_node = this->_alloc_node.allocate(1);
		try
		{
			this->_alloc_node.construct(this->_null_node);
		}
		catch (...)
		{
			this->_alloc_node.deallocate(this->_null_node, 1);
			throw ;
		}
		this->_head = head;
		this->_null_node->p= this->_head;
		_null_node->color = ft::BLACK;
		this->_size = 1;
	}

	template < typename T, typename Compare, typename Alloc>
	rb_tree<T, Compare, Alloc>::rb_tree(const rb_tree<T, Compare, Alloc> &other) :
		_alloc(other._alloc), _alloc_node(other._alloc_node),_comp(other._comp)
	{
		this->_null_node = this->_alloc_node.allocate(1);
		try
		{
			this->_alloc_node.construct(this->_null_node);
		}
		catch (...)
		{
			this->_alloc_node.deallocate(this->_null_node, 1);
			throw ;
		}
		this->_head = this->_null_node;
		this->_null_node->p= this->_head;
		_null_node->color = ft::BLACK;
		this->deep_copy(other.get_head(), other._null_node);
		this->_size = other._size;
	}

	template < typename T, typename Compare, typename Alloc> 
	rb_tree<T, Compare, Alloc>&
	rb_tree<T, Compare, Alloc>::operator=(const rb_tree<T, Compare, Alloc> &other)
	{
		if (this != &other)
		{
			if (_head != _null_node)
				this->clear(this->_head);
			this->_alloc = other._alloc;
			this->_alloc_node = other._alloc_node;
			this->_head = this->_null_node;
			this->_comp = other._comp;
			this->deep_copy(other.get_head(), other._null_node);
			this->_size = other._size;
		}
		return (*this);
	}

	template < typename T, typename Compare, typename Alloc>
	rb_tree<T, Compare, Alloc>::~rb_tree()
	{
		if (_head != _null_node)
			this->clear(this->_head);
		if (_null_node != 0)
		{
			this->_alloc_node.destroy(_null_node);
			this->_alloc_node.deallocate(_null_node, 1);
			_null_node = 0;
		}
	}

	/*======================================*/
	/*	Tree functional */

	template < typename T, typename Compare, typename Alloc>
	typename rb_tree<T, Compare, Alloc>::node_ptr
	rb_tree<T, Compare, Alloc>::create_node(value_type data)
	{
		node_ptr	new_node;

		new_node = this->_alloc_node.allocate(1);
		try
		{
			this->_alloc_node.construct(new_node, data);
		}
		catch (...)
		{
			this->_alloc_node.deallocate(new_node, 1);
			throw ;
		}
		new_node->left = _null_node;
		new_node->right = _null_node;
		new_node->p = _null_node;
		return (new_node);
	}

	template < typename T, typename Compare, typename Alloc>
	typename rb_tree<T, Compare, Alloc>::node_ptr
	rb_tree<T, Compare, Alloc>::get_head() const
	{
		return (this->_head);
	}

	template < typename T, typename Compare, typename Alloc>
	typename rb_tree<T, Compare, Alloc>::node_ptr
	rb_tree<T, Compare, Alloc>::get_null() const
	{
		return (this->_null_node);
	}

	template < typename T, typename Compare, typename Alloc>
	int	rb_tree<T, Compare, Alloc>::height(node_ptr head) const
	{
		if (head == this->_null_node)
			return (0);
		else
		{
			int lheight = height(head->left);
			int rheight = height(head->right);
			if (lheight > rheight)
				return (lheight + 1);
			else
				return (rheight + 1);
		}
	}

	template < typename T, typename Compare, typename Alloc>
	int	rb_tree<T, Compare, Alloc>::height() const
	{
		return (this->height(this->_head));
	}

	template < typename T, typename Compare, typename Alloc>
	typename rb_tree<T, Compare, Alloc>::node_ptr
	rb_tree<T, Compare, Alloc>::min(node_ptr head)	const
	{
		if (head == this->_null_node)
			return (this->_null_node);
		while (head->left != this->_null_node)
			head = head->left;
		return (head);
	}

	template < typename T, typename Compare, typename Alloc>
	typename rb_tree<T, Compare, Alloc>::node_ptr
	rb_tree<T, Compare, Alloc>::min()	const
	{
		return (this->min(this->_head));
	}

	template < typename T, typename Compare, typename Alloc>
	typename rb_tree<T, Compare, Alloc>::node_ptr
	rb_tree<T, Compare, Alloc>::max(node_ptr head) const
	{
		if (head == this->_null_node)
			return (this->_null_node);
		while (head->right != this->_null_node)
			head = head->right;
		return (head);
	}

	template < typename T, typename Compare, typename Alloc>
	typename rb_tree<T, Compare, Alloc>::node_ptr
	rb_tree<T, Compare, Alloc>::max()	const
	{
		return (this->max(this->_head));
	}

	template < typename T, typename Compare, typename Alloc>
	typename rb_tree<T, Compare, Alloc>::node_ptr
	rb_tree<T, Compare, Alloc>::successor(node_ptr head)	const
	{
		node_ptr	parent;

		if (head == this->_null_node)
			return (this->_null_node);
		if (head->right != this->_null_node)
			return (this->min(head->right));
		else
		{
			parent = head->p;
			while (parent != this->_null_node && head == parent->right)
			{
				head = parent;
				parent = head->p;
			}
			return (parent);
		}
	}

	template < typename T, typename Compare, typename Alloc>
	typename rb_tree<T, Compare, Alloc>::node_ptr
	rb_tree<T, Compare, Alloc>::successor() const
	{
		return (this->successor(this->_head));
	}

	template < typename T, typename Compare, typename Alloc>
	typename rb_tree<T, Compare, Alloc>::node_ptr
	rb_tree<T, Compare, Alloc>::predecessor(node_ptr head) const
	{
		node_ptr	parent;

		if (head == this->_null_node)
			return (this->_null_node);
		if (head->left != this->_null_node)
			return (this->max(head->left));
		else
		{
			parent = head->p;
			while (parent != this->_null_node && head == parent->left)
			{
				head = parent;
				parent = head->p;
			}
			return (parent);
		}
	}

	template < typename T, typename Compare, typename Alloc>
	typename rb_tree<T, Compare, Alloc>::node_ptr
	rb_tree<T, Compare, Alloc>::predecessor() const
	{
		return (this->predecessor(this->_head));
	}

	/*=============================*/
    /*	Capacity */

	template < typename T, typename Compare, typename Alloc>
	bool	rb_tree<T, Compare, Alloc>::empty() const
	{
		if (this->_size == 0)
			return (true);
		return (false);
	}

	template < typename T, typename Compare, typename Alloc>
	typename rb_tree<T, Compare, Alloc>::size_type
	rb_tree<T, Compare, Alloc>::size() const
	{
		return (this->_size);
	}

	template < typename T, typename Compare, typename Alloc>
	typename rb_tree<T, Compare, Alloc>::size_type
	rb_tree<T, Compare, Alloc>::max_size() const
	{
		return (this->_alloc_node.max_size());
		// return ();
	}
	
	/*=============================*/
    /*	Operations */

	template < typename T, typename Compare, typename Alloc>
	typename rb_tree<T, Compare, Alloc>::node_ptr
	rb_tree<T, Compare, Alloc>::search(node_ptr head, const value_type &data) const
	{
		if (head == this->_null_node || \
				(!this->comp_data(head->data, data) && \
				 !this->comp_data(data, head->data)))
			return (head);
		if (this->comp_data(data, head->data))
			return (this->search(head->left, data));
		else
			return (this->search(head->right, data));
	}

	template < typename T, typename Compare, typename Alloc>
	typename rb_tree<T, Compare, Alloc>::node_ptr
	rb_tree<T, Compare, Alloc>::search(const value_type &data) const
	{
		return (this->search(this->_head, data));
	}

	/*=============================*/
	/*	Count */

	template < typename T, typename Compare, typename Alloc>
	void
	rb_tree<T, Compare, Alloc>::count_in_level
	(node_ptr head, const value_type &data, int level, size_type &count) const
	{
		if (head != this->_null_node)
		{
			if (level == 1)
			{
				if (!this->comp_data(head->data, data) && \
					!this->comp_data(data, head->data))
					++count;
			}
			else if (level > 1)
			{
				count_in_level(head->left, data, level - 1, count);
				count_in_level(head->right, data, level - 1, count);
			}
		}
	}

	template < typename T, typename Compare, typename Alloc>
	typename rb_tree<T, Compare, Alloc>::size_type
	rb_tree<T, Compare, Alloc>::count(node_ptr head, const value_type &data) const
	{
		size_type	count;

		count = 0;
		node_ptr	res = search(head, data);
		if (res != this->_null_node)
			++count;
		return (count);
	}

	template < typename T, typename Compare, typename Alloc>
	typename rb_tree<T, Compare, Alloc>::size_type
	rb_tree<T, Compare, Alloc>::count(const value_type &data) const
	{
		return(this->count(this->_head, data));
	}

	/*=============================*/
	/*	Bounds */

	template < typename T, typename Compare, typename Alloc>
	typename rb_tree<T, Compare, Alloc>::iterator
	rb_tree<T, Compare, Alloc>::lower_bound(const value_type &data)
	{
		iterator	it1;
		iterator	it2;

		it1 = this->begin();
		it2 = this->end();
		while (it1 != it2)
		{
			if (!this->comp_data(*it1, data))
				break ;
			++it1;
		}
		return (it1);
	}

	template < typename T, typename Compare, typename Alloc>
	typename rb_tree<T, Compare, Alloc>::const_iterator
	rb_tree<T, Compare, Alloc>::lower_bound(const value_type &data) const
	{
		const_iterator	it1;
		const_iterator	it2;

		it1 = this->begin();
		it2 = this->end();
		while (it1 != it2)
		{
			if (!this->comp_data(*it1, data))
				break ;
			++it1;
		}

		return (it1);
	}

	template < typename T, typename Compare, typename Alloc>
	typename rb_tree<T, Compare, Alloc>::iterator
	rb_tree<T, Compare, Alloc>::upper_bound(const value_type &data)
	{
		iterator	it1;
		iterator	it2;

		it1 = this->begin();
		it2 = this->end();
		while (it1 != it2)
		{
			if (this->comp_data(data, *it1))
				break ;
			++it1;
		}

		return (it1);
	}

	template < typename T, typename Compare, typename Alloc>
	typename rb_tree<T, Compare, Alloc>::const_iterator
	rb_tree<T, Compare, Alloc>::upper_bound (const value_type &data) const
	{
		const_iterator	it1;
		const_iterator	it2;

		it1 = this->begin();
		it2 = this->end();
		while (it1 != it2)
		{
			if (this->comp_data(data, *it1))
				break ;
			++it1;
		}

		return (it1);
	}

	template < typename T, typename Compare, typename Alloc>
	ft::pair<	typename rb_tree<T, Compare, Alloc>::iterator,
				typename rb_tree<T, Compare, Alloc>::iterator>
	rb_tree<T, Compare, Alloc>::equal_range(const value_type &data)
	{
		return (ft::pair<iterator, iterator>(	this->lower_bound(data),
												this->upper_bound(data)));
	}

	template < typename T, typename Compare, typename Alloc>
	ft::pair <	typename rb_tree<T, Compare, Alloc>::const_iterator,
				typename rb_tree<T, Compare, Alloc>::const_iterator>
	rb_tree<T, Compare, Alloc>::equal_range
	(const value_type &data) const
	{
		return (	ft::pair<const_iterator, const_iterator>
					(this->lower_bound(data), this->upper_bound(data)));
	}

	/*=============================*/
	/*	Tree walk */

	template < typename T, typename Compare, typename Alloc>
	void	rb_tree<T, Compare, Alloc>::preorder_tree_walk(node_ptr head) const
	{
		if (head != this->_null_node)
		{
			std::cout << Key()(head->data) << ' ';
			preorder_tree_walk(head->left);
			preorder_tree_walk(head->right);
		}
	}

	template < typename T, typename Compare, typename Alloc>
	void	rb_tree<T, Compare, Alloc>::preorder_tree_walk() const
	{
		this->preorder_tree_walk(this->_head);
	}

	template < typename T, typename Compare, typename Alloc>
	void	rb_tree<T, Compare, Alloc>::inorder_tree_walk(node_ptr head) const
	{
		if (head != this->_null_node)
		{
			inorder_tree_walk(head->left);
			std::cout << Key()(head->data) << ' ';
			inorder_tree_walk(head->right);
		}
	}

	template < typename T, typename Compare, typename Alloc>
	void	rb_tree<T, Compare, Alloc>::inorder_tree_walk() const
	{
		this->inorder_tree_walk(this->_head);
	}

	template < typename T, typename Compare, typename Alloc>
	void	rb_tree<T, Compare, Alloc>::postorder_tree_walk(node_ptr head) const
	{
		if (head != this->_null_node)
		{
			postorder_tree_walk(head->left);
			postorder_tree_walk(head->right);
			std::cout << Key()(head->data) << ' ';
		}
	}

	template < typename T, typename Compare, typename Alloc>
	void	rb_tree<T, Compare, Alloc>::postorder_tree_walk() const
	{
		this->postorder_tree_walk(this->_head);
	}

	template < typename T, typename Compare, typename Alloc>
	void	rb_tree<T, Compare, Alloc>::print_level(node_ptr head, int level) const
	{
		if (head != this->_null_node)
		{
			if (level == 1)
				std::cout << Key()(head->data) << " ";
			else if (level > 1)
			{
				print_level(head->left, level - 1);
				print_level(head->right, level - 1);
			}
		}
	}

	template < typename T, typename Compare, typename Alloc>
	void	rb_tree<T, Compare, Alloc>::print_level(int level) const
	{
		this->print_level(this->_head, level);
	}

	template < typename T, typename Compare, typename Alloc>
	void	rb_tree<T, Compare, Alloc>::print_tree(node_ptr head) const
	{
		int	tree_height;
		int level;

		tree_height = this->height(head);
		level = 1;
		while (level <= tree_height)
		{
			std::cout << "Level " << level - 1 << " - | ";
			print_level(head, level);
			std::cout << "|" << std::endl;
			++level;
		}
	}

	template < typename T, typename Compare, typename Alloc>
	void	rb_tree<T, Compare, Alloc>::print_tree() const
	{
		this->print_tree(this->_head);
	}

	/*========================================*/
    /*	Insert, erase, swap */


	template < typename T, typename Compare, typename Alloc>
	ft::pair<	typename rb_tree<T, Compare, Alloc>::iterator,
				bool>
	rb_tree<T, Compare, Alloc>::insert(node_ptr head, node_ptr new_node)
	{
		node_ptr	tmp;
		node_ptr	parent;

		tmp = head;
		parent = this->_null_node;
		while (tmp != this->_null_node)
		{
			parent = tmp;
			if (!this->comp_data(new_node->data, tmp->data) && \
				!this->comp_data(tmp->data, new_node->data))
					return (ft::pair<iterator, bool>(iterator(_null_node, tmp), false));
			else if (this->comp_data(new_node->data, tmp->data))
				tmp = tmp->left;
			else
				tmp = tmp->right;
		}
		new_node->p = parent;
		if (parent == this->_null_node)
			this->_head = new_node;
		else if (this->comp_data(new_node->data, parent->data))
			parent->left = new_node;
		else
			parent->right = new_node;
		++(this->_size);
		this->insert_fixup(new_node);
		this->_null_node->p = this->_head;
		return (ft::pair<iterator, bool>(iterator(_null_node, new_node), true));
	}

	template < typename T, typename Compare, typename Alloc>
	ft::pair <	typename rb_tree<T, Compare, Alloc>::iterator,
				bool>
	rb_tree<T, Compare, Alloc>::insert(node_ptr new_node)
	{
		return (insert(_head, new_node));
	}

	template < typename T, typename Compare, typename Alloc>
	typename rb_tree<T, Compare, Alloc>::iterator
	rb_tree<T, Compare, Alloc>::insert(iterator hint, const value_type &value)
	{
		node_ptr					new_node;
		node_ptr					head_node;
		ft::pair<iterator, bool>	res;

		new_node = this->create_node(value);
		head_node = hint.get_node();
		while (head_node != _null_node)
		{
			if (head_node->p != _null_node && \
				head_node->p->left == head_node && \
				comp_data(value, head_node->p->data))
				break ;
			if (head_node->p != _null_node && \
				head_node->p->right == head_node && \
				comp_data(head_node->p->data, value))
				break ;
			head_node = head_node->p;
		}
		if (head_node == _null_node)
			head_node = this->_head;
		res = this->insert(head_node, new_node);
		if (res.second == false)
		{
			this->_alloc_node.destroy(new_node);
			this->_alloc_node.deallocate(new_node, 1);
		}
		return (res.first);
	}

	template < typename T, typename Compare, typename Alloc>
	ft::pair<	typename rb_tree<T, Compare, Alloc>::iterator,
				bool >
	rb_tree<T, Compare, Alloc>::insert(const value_type &value)
	{
		node_ptr					new_node;
		ft::pair<iterator, bool>	res;

		new_node = this->create_node(value);
		res = this->insert(new_node);
		if (res.second == false)
		{
			this->_alloc_node.destroy(new_node);
			this->_alloc_node.deallocate(new_node, 1);
		}
		return (res);
	}

	template < typename T, typename Compare, typename Alloc>
	void	rb_tree<T, Compare, Alloc>::insert_fixup(node_ptr new_node)
	{
		node_ptr	y;

		while (new_node->p->color == ft::RED)
		{
			if (new_node->p == new_node->p->p->left)
			{
				y = new_node->p->p->right;
				if (y->color == ft::RED)
				{
					y->color = ft::BLACK;
					new_node->p->color = ft::BLACK;
					new_node->p->p->color = ft::RED;
					new_node = new_node->p->p;
				}
				else
				{
					if (new_node == new_node->p->right)
					{
						new_node = new_node->p;
						rotate_left(new_node);
					}
					new_node->p->color = ft::BLACK;
					new_node->p->p->color = ft::RED;
					rotate_right(new_node->p->p);
				}
			}
			else
			{
				y = new_node->p->p->left;
				if (y->color == ft::RED)
				{
					y->color = ft::BLACK;
					new_node->p->color = ft::BLACK;
					new_node->p->p->color = ft::RED;
					new_node = new_node->p->p;
				}
				else
				{
					if (new_node == new_node->p->left)
					{
						new_node = new_node->p;
						rotate_right(new_node);
					}
					new_node->p->color = ft::BLACK;
					new_node->p->p->color = ft::RED;
					rotate_left(new_node->p->p);
				}
			}
		}
		_head->color = ft::BLACK;
	}

	template < typename T, typename Compare, typename Alloc>
	void	rb_tree<T, Compare, Alloc>::erase(node_ptr old_node)
	{
		node_ptr	u;
		node_ptr	x;
		t_rb_color	u_original_color;

		u = old_node;
		u_original_color = u->color;
		if (old_node == _null_node)
			return ;
		if (old_node->left == this->_null_node)
		{
			x = old_node->right;
			this->transplant(old_node, old_node->right);
		}
		else if (old_node->right == this->_null_node)
		{
			x = old_node->left;
			this->transplant(old_node, old_node->left);
		}
		else
		{
			u = this->min(old_node->right);
			u_original_color = u->color;
			x = u->right;
			if (u != old_node->right)
			{
				this->transplant(u, u->right);
				u->right = old_node->right;
				u->right->p = u;
			}
			else
				x->p = u;
			this->transplant(old_node, u);
			u->left = old_node->left;
			u->left->p = u;
			u->color = old_node->color;
		}
		this->_alloc_node.destroy(old_node);
		this->_alloc_node.deallocate(old_node, 1);
		--(this->_size);
		if (u_original_color == ft::BLACK)
			erase_fixup(x);
		this->_null_node->p = this->_head;
	}

	template < typename T, typename Compare, typename Alloc>
	typename rb_tree<T, Compare, Alloc>::size_type
	rb_tree<T, Compare, Alloc>::erase(value_type value)
	{
		size_type	count;
		node_ptr	found;

		count = 0;
		found = this->search(value);
		if (found != _null_node)
		{
			this->erase(found);
			++count;
		}
		return (count);
	}

	template < typename T, typename Compare, typename Alloc>
	void	rb_tree<T, Compare, Alloc>::erase(iterator pos)
	{
		this->erase(pos.get_node());
	}

	template < typename T, typename Compare, typename Alloc>
	void	rb_tree<T, Compare, Alloc>::erase_fixup(node_ptr x)
	{
		node_ptr	w;

		while (x != _head && x->color == ft::BLACK)
		{
			if (x == x->p->left)
			{
				w = x->p->right;
				if (w->color == ft::RED)
				{
					w->color = ft::BLACK;
					x->p->color = ft::RED;
					rotate_left(x->p);
					w = x->p->right;
				}
				if (w->left->color == ft::BLACK && w->right->color == ft::BLACK)
				{
					w->color = ft::RED;
					x = x->p;
				}
				else
				{
					if (w->right->color == ft::BLACK)
					{
						w->left->color = ft::BLACK;
						w->color = ft::RED;
						rotate_right(w);
						w = x->p->right;
					}
					w->color = x->p->color;
					x->p->color = ft::BLACK;
					w->right->color = ft::BLACK;
					rotate_left(x->p);
					x = _head;
				}
			}
			else
			{
				w = x->p->left;
				if (w->color == ft::RED)
				{
					w->color = ft::BLACK;
					x->p->color = ft::RED;
					rotate_right(x->p);
					w = x->p->left;
				}
				if (w->right->color == ft::BLACK && w->left->color == ft::BLACK)
				{
					w->color = ft::RED;
					x = x->p;
				}
				else
				{
					if (w->left->color == ft::BLACK)
					{
						w->right->color = ft::BLACK;
						w->color = ft::RED;
						rotate_left(w);
						w = x->p->left;
					}
					w->color = x->p->color;
					x->p->color = ft::BLACK;
					w->left->color = ft::BLACK;
					rotate_right(x->p);
					x = _head;
				}
			}
		}
		x->color = ft::BLACK;
	}

	template < typename T, typename Compare, typename Alloc>
	void	rb_tree<T, Compare, Alloc>::clear(node_ptr head)
	{
		if (head != this->_null_node)
		{
			this->clear(head->left);
			this->clear(head->right);
			this->_alloc_node.destroy(head);
			this->_alloc_node.deallocate(head, 1);
			--(this->_size);
		}
	}

	template < typename T, typename Compare, typename Alloc>
	void	rb_tree<T, Compare, Alloc>::clear()
	{
		this->clear(_head);
		_head = _null_node;
	}

	template < typename T, typename Compare, typename Alloc>
	void	rb_tree<T, Compare, Alloc>::swap(rb_tree<T, Compare, Alloc> &other)
	{
		node_ptr	tmp_head = this->_head;
		this->_head = other._head;
		other._head = tmp_head;

		node_ptr	tmp_null = this->_null_node;
		this->_null_node = other._null_node;
		other._null_node = tmp_null;

		size_type	tmp_size = this->_size;
		this->_size = other._size;
		other._size = tmp_size;

		key_compare	tmp_comp = this->_comp;
		this->_comp = other._comp;
		other._comp = tmp_comp;
	}

	/*=====================================*/
    /*	Iterators */

	template < typename T, typename Compare, typename Alloc>
	typename rb_tree<T, Compare, Alloc>::iterator
	rb_tree<T, Compare, Alloc>::begin()
	{
		return (iterator(this->_null_node, this->min()));
	}

	template < typename T, typename Compare, typename Alloc>
	typename rb_tree<T, Compare, Alloc>::const_iterator
	rb_tree<T, Compare, Alloc>::begin() const
	{
		return (const_iterator(this->_null_node, this->min()));
	}

	template < typename T, typename Compare, typename Alloc>
	typename rb_tree<T, Compare, Alloc>::iterator
	rb_tree<T, Compare, Alloc>::end()
	{
		return (iterator(this->_null_node, this->_null_node));
	}

	template < typename T, typename Compare, typename Alloc>
	typename rb_tree<T, Compare, Alloc>::const_iterator
	rb_tree<T, Compare, Alloc>::end() const
	{
		return (const_iterator(this->_null_node, this->_null_node));
	}

	template < typename T, typename Compare, typename Alloc>
	typename rb_tree<T, Compare, Alloc>::reverse_iterator
	rb_tree<T, Compare, Alloc>::rbegin()
	{
		return (reverse_iterator(this->end()));
	}

	template < typename T, typename Compare, typename Alloc>
	typename rb_tree<T, Compare, Alloc>::const_reverse_iterator
	rb_tree<T, Compare, Alloc>::rbegin() const
	{
		return (const_reverse_iterator(this->end()));
	}

	template < typename T, typename Compare, typename Alloc>
	typename rb_tree<T, Compare, Alloc>::reverse_iterator
	rb_tree<T, Compare, Alloc>::rend()
	{
		return (reverse_iterator(this->begin()));
	}

	template < typename T, typename Compare, typename Alloc>
	typename rb_tree<T, Compare, Alloc>::const_reverse_iterator
	rb_tree<T, Compare, Alloc>::rend() const
	{
		return (const_reverse_iterator(this->begin()));
	}

	/*=====================================*/
    /*	Allocator */
    

	template < typename T, typename Compare, typename Alloc>
	typename rb_tree<T, Compare, Alloc>::allocator_type
	rb_tree<T, Compare, Alloc>::get_allocator() const
	{
		return (this->_alloc);
	}

	/*=====================================*/
    /*	Helper methods */

	template < typename T, typename Compare, typename Alloc>
	void	rb_tree<T, Compare, Alloc>::transplant(node_ptr u, node_ptr v)
	{
		if (u->p == _null_node)
			this->_head = v;
		else if (u == u->p->left)
			u->p->left = v;
		else
			u->p->right = v;
		v->p = u->p;
	}

	template < typename T, typename Compare, typename Alloc>
	void	rb_tree<T, Compare, Alloc>::deep_copy(node_ptr other_node, node_ptr other_null)
	{
		if (other_node != other_null)
		{
			this->insert(create_node(other_node->data));
			this->deep_copy(other_node->left, other_null);
			this->deep_copy(other_node->right, other_null);
		}
	}
	
	template <typename T, typename Compare, typename Alloc>
	bool rb_tree<T, Compare, Alloc>::
	comp_data(value_type v1, value_type v2) const
	{
		return (_comp(Key()(v1), Key()(v2)));
	}

	template < typename T, typename Compare, typename Alloc>
	void	rb_tree<T, Compare, Alloc>::rotate_left(node_ptr node)
	{
		node_ptr	y;

		y = node->right;
		node->right = y->left;
		if (y->left != _null_node)
			y->left->p = node;
		y->p = node->p;
		if (node->p == _null_node)
			_head = y;
		else if (node == node->p->left)
			node->p->left = y;
		else
			node->p->right = y;
		y->left = node;
		node->p = y;
	}

	template < typename T, typename Compare, typename Alloc>
	void	rb_tree<T, Compare, Alloc>::rotate_right(node_ptr node)
	{
		node_ptr	y;

		y = node->left;
		node->left = y->right;
		if (y->right != _null_node)
			y->right->p = node;
		y->p = node->p;
		if (node->p == _null_node)
			_head = y;
		else if (node == node->p->left)
			node->p->left = y;
		else
			node->p->right = y;
		y->right = node;
		node->p = y;
	}

} // end of "namespace	ft"

#endif