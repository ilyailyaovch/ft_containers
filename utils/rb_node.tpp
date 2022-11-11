/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_node.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 22:23:35 by ilya              #+#    #+#             */
/*   Updated: 2022/11/11 12:12:36 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_NODE_TPP
# define RB_NODE_TPP

namespace	ft
{
	template <typename T>
	rb_node<T>::rb_node() :
		data()
	{
		this->left = NULL;
		this->right = NULL;
		this->p = NULL;
		this->color = ft::RED;
	}

	template <typename T>
	rb_node<T>::rb_node(const T &elem) : data(elem)
	{
		this->left = NULL;
		this->right = NULL;
		this->p = NULL;
		this->color = ft::RED;
	}

	template <typename T>
	rb_node<T>::rb_node(const rb_node &other)
	{
		this->data = other.data;
		this->left = other.left;
		this->right = other.right;
		this->p = other.p;
		this->color = other.color;
	}

	template <typename T>
	rb_node<T>	&rb_node<T>::operator=(const rb_node &other)
	{
		if (this != &other)
		{
			this->data = other.data;
			this->left = other.left;
			this->right = other.right;
			this->p = other.p;
			this->color = other.color;
		}
		return (*this);
	}

	template <typename T>
	rb_node<T>::~rb_node()
	{
	}

}	//end of "namespace	ft"

#endif