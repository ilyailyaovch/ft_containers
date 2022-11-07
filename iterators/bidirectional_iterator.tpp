/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.tpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:09:47 by ilya              #+#    #+#             */
/*   Updated: 2022/11/07 01:01:40 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_TPP
# define BIDIRECTIONAL_ITERATOR_TPP

namespace	ft
{
	/*=================================*/
	/*	Canonical form */

	template <typename T>
	bidirectional_iterator<T>::bidirectional_iterator() :
	_null_node(), _elem()
	{
	}

	template <typename T>
	bidirectional_iterator<T>::bidirectional_iterator(pointer null_node, pointer ptr) :
	_null_node(null_node), _elem(ptr)
	{
	}

	template <typename T>
	bidirectional_iterator<T>::bidirectional_iterator(const bidirectional_iterator &other)
	{
		this->_null_node = other._null_node;
		this->_elem = other._elem;
	}

	template <typename T>
	bidirectional_iterator<T>&
	bidirectional_iterator<T>::operator=(const bidirectional_iterator<T> &other)
	{
		if (this != &other)
		{
			this->_null_node = other._null_node;
			this->_elem = other._elem;
		}
		return (*this);
	}

	template <typename T>
	bidirectional_iterator<T>::~bidirectional_iterator()
	{
	}

	/*=================================*/
	/*	Operators */

	template <typename T>
	bidirectional_iterator<T>&
	bidirectional_iterator<T>::operator++()
	{
		if (this->_elem->right != this->_null_node)
		{
			this->_elem = this->_elem->right;
			while (this->_elem->left != this->_null_node)
				this->_elem = this->_elem->left;
		}
		else
		{
			if (this->_elem == this->_elem->parent->left)
				this->_elem = this->_elem->parent;
			else
			{
				while (this->_elem == this->_elem->parent->right)
					this->_elem = this->_elem->parent;
				this->_elem = this->_elem->parent;
			}
		}
		return (*this);
	}

}	//end of "namespace	ft"

#endif