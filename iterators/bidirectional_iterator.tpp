/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.tpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:09:47 by ilya              #+#    #+#             */
/*   Updated: 2022/11/11 14:14:08 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_TPP
# define BIDIRECTIONAL_ITERATOR_TPP

namespace	ft
{
	/*====================================================*/
	/*	Canonical form */
	/*====================================================*/

	template <typename T, typename pair_type>
	bidirectional_iterator<T, pair_type>::bidirectional_iterator() :
	_null_node(), _elem()
	{
	}

	template <typename T, typename pair_type>
	bidirectional_iterator<T, pair_type>::bidirectional_iterator(node_pointer null_node, node_pointer ptr) :
	_null_node(null_node), _elem(ptr)
	{
	}

	template <typename T, typename pair_type>
	bidirectional_iterator<T, pair_type>::bidirectional_iterator(const bidirectional_iterator &other)
	{
		this->_null_node = other._null_node;
		this->_elem = other._elem;
	}

	template <typename T, typename pair_type>
	bidirectional_iterator<T, pair_type>::operator
	bidirectional_iterator<const T, const pair_type> () const
	{
		return (bidirectional_iterator<const T, const pair_type>(this->_null_node, this->_elem));
	}

	template <typename T, typename pair_type>
	bidirectional_iterator<T, pair_type>&
	bidirectional_iterator<T, pair_type>::operator=(const bidirectional_iterator<T, pair_type> &other)
	{
		if (this != &other)
		{
			this->_null_node = other._null_node;
			this->_elem = other._elem;
		}
		return (*this);
	}

	template <typename T, typename pair_type>
	bidirectional_iterator<T, pair_type>::~bidirectional_iterator()
	{
	}

	/*====================================================*/
	/*	Operators */
	/*====================================================*/

	template <typename T, typename pair_type>
	bidirectional_iterator<T, pair_type>&
	bidirectional_iterator<T, pair_type>::operator++()
	{
		if (this->_elem->right != this->_null_node)
		{
			this->_elem = this->_elem->right;
			while (this->_elem->left != this->_null_node)
				this->_elem = this->_elem->left;
		}
		else
		{
			if (this->_elem == this->_elem->p->left)
				this->_elem = this->_elem->p;
			else
			{
				while (this->_elem == this->_elem->p->right)
					this->_elem = this->_elem->p;
				this->_elem = this->_elem->p;
			}
		}
		return (*this);
	}

	template <typename T, typename pair_type>
	bidirectional_iterator<T, pair_type>
	bidirectional_iterator<T, pair_type>::operator++(int)
	{
		bidirectional_iterator<T, pair_type>	tmp;

		tmp = *this;

		this->operator++();
		return (tmp);
	}

	template <typename T, typename pair_type>
	bidirectional_iterator<T, pair_type>&
	bidirectional_iterator<T, pair_type>::operator--()
	{
		if (this->_elem == this->_null_node)
		{
			this->_elem = this->_null_node->p;
			while (this->_elem->right != this->_null_node)
				this->_elem = this->_elem->right;
		}
		else if (this->_elem->left != this->_null_node)
		{
			this->_elem = this->_elem->left;
			while (this->_elem->right != this->_null_node)
				this->_elem = this->_elem->right;
		}
		else
		{
			if (this->_elem == this->_elem->p->right)
				this->_elem = this->_elem->p;
			else
			{
				while (this->_elem == this->_elem->p->left)
					this->_elem = this->_elem->p;
				this->_elem = this->_elem->p;
			}
		}
		return (*this);
	}

	template <typename T, typename pair_type>
	bidirectional_iterator<T, pair_type>
	bidirectional_iterator<T, pair_type>::operator--(int)
	{
		bidirectional_iterator<T, pair_type>	tmp;

		tmp = *this;
		this->operator--();
		return (tmp);
	}

	template <typename T, typename pair_type>
	pair_type	&bidirectional_iterator<T, pair_type>::operator*() const
	{
		return (this->_elem->data);
	}

	template <typename T, typename pair_type>
	pair_type	*bidirectional_iterator<T, pair_type>::operator->() const
	{
		return (&(this->_elem->data));
	}

	template <typename T, typename pair_type>
	typename bidirectional_iterator<T, pair_type>::node_pointer
	bidirectional_iterator<T, pair_type>::get_node() const
	{
		return (this->_elem);
	}

	template <typename T, typename pair_type>
	bool	bidirectional_iterator<T, pair_type>::operator==
	(const bidirectional_iterator &other) const
	{
		return (this->_elem == other._elem);
	}

	template <typename T, typename pair_type>
	bool	bidirectional_iterator<T, pair_type>::operator!=
	(const bidirectional_iterator &other) const
	{
		return (this->_elem != other._elem);
	}

}	//end of "namespace	ft"

#endif