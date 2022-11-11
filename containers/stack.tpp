/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:38:43 by ilya              #+#    #+#             */
/*   Updated: 2022/11/11 14:12:13 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_TPP
# define STACK_TPP

namespace ft
{
	/*====================================================*/
	/*	Canonical form */
	/*====================================================*/

	template <typename T, typename Container>
	stack<T, Container>::stack(const container_type &cont)
	{
		this->_cont = cont;
	}

	template <typename T, typename Container>
	stack<T, Container>&	stack<T, Container>::operator=(const stack &other)
	{
		if (this != &other)
			this->_cont = other._cont;
		return (*this);
	}

	template <typename T, typename Container>
	stack<T, Container>::~stack()
	{
		this->_cont.clear();
	}

	/*====================================================*/
	/*	Member functions */
	/*====================================================*/

	template <typename T, typename Container>
	typename stack<T, Container>::reference
	stack<T, Container>::top()
	{
		return (this->_cont.back());
	}

	template <typename T, typename Container>
	typename stack<T, Container>::const_reference
	stack<T, Container>::top() const
	{
		return (this->_cont.back());
	}

	template <typename T, typename Container>
	bool	stack<T, Container>::empty() const
	{
		return (this->_cont.empty());
	}

	template <typename T, typename Container>
	typename stack<T, Container>::size_type
	stack<T, Container>::size() const
	{
		return (this->_cont.size());
	}

	template <typename T, typename Container>
	void	stack<T, Container>::push(const_reference value)
	{
		this->_cont.push_back(value);
	}

	template <typename T, typename Container>
	void	stack<T, Container>::pop()
	{
		this->_cont.pop_back();
	}

	/*====================================================*/
	/*	Non-member functions */
	/*====================================================*/

	template <typename _T, typename _Cont>
	bool	operator==(const stack<_T, _Cont> &lhs, const stack<_T, _Cont> &rhs)
	{
		return (lhs._cont == rhs._cont);
	}

	template <typename _T, typename _Cont>
	bool	operator!=(const stack<_T, _Cont> &lhs, const stack<_T, _Cont> &rhs)
	{
		return (lhs._cont != rhs._cont);
	}

	template <typename _T, typename _Cont>
	bool	operator>(const stack<_T, _Cont> &lhs, const stack<_T, _Cont> &rhs)
	{
		return (lhs._cont > rhs._cont);
	}

	template <typename _T, typename _Cont>
	bool	operator>=(const stack<_T, _Cont> &lhs, const stack<_T, _Cont> &rhs)
	{
		return (lhs._cont >= rhs._cont);
	}

	template <typename _T, typename _Cont>
	bool	operator<(const stack<_T, _Cont> &lhs, const stack<_T, _Cont> &rhs)
	{
		return (lhs._cont < rhs._cont);
	}

	template <typename _T, typename _Cont>
	bool	operator<=(const stack<_T, _Cont> &lhs, const stack<_T, _Cont> &rhs)
	{
		return (lhs._cont <= rhs._cont);
	}
	
}	//end of "namespace	ft"

#endif