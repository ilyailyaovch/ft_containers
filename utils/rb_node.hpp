/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_node.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:05:47 by ilya              #+#    #+#             */
/*   Updated: 2022/11/06 22:34:57 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_NODE_HPP
# define RB_NODE_HPP

namespace	ft
{
	typedef enum e_colors
	{
		BLACK,
		RED
	}	t_colors;

	template <typename T>
	struct	rb_node
	{
		typedef T 			value_type;
		typedef rb_node* 	node_pointer;
		
		rb_node();
		rb_node(const T &elem);
		rb_node(const rb_node &other);
		rb_node		&operator=(const rb_node &other);
		~rb_node();
		
		value_type			data;
		node_pointer		left;
		node_pointer		right;
		node_pointer		parent;
		t_colors			color;
	};
}	//end of "namespace	ft"

# include "rb_node.tpp"

#endif