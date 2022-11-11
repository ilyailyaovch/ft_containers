/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_node.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:05:47 by ilya              #+#    #+#             */
/*   Updated: 2022/11/11 15:21:39 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_NODE_HPP
# define RB_NODE_HPP

namespace	ft
{
	typedef enum e_rb_color
	{
		BLACK,
		RED
	}	t_rb_color;

	template <typename T>
	struct	rb_node
	{
		typedef	T			value_type;
		typedef	rb_node*	node_ptr;

		rb_node();
		rb_node(const T &elem);
		rb_node(const rb_node &other);
		rb_node		&operator=(const rb_node &other);
		~rb_node();

		value_type		data;
		node_ptr		left;
		node_ptr		right;
		node_ptr		p;
		t_rb_color		color;
	};

}	//end of "namespace	ft"

# include "rb_node.tpp"

#endif