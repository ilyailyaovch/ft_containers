/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:05:08 by ilya              #+#    #+#             */
/*   Updated: 2022/10/28 17:30:52 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TPP
# define VECTOR_TPP

namespace ft
{
	/*=================================*/
	/*	Canonical form */

	template <class T, class Allocator>
	vector<T, Allocator>::vector(const allocator_type &alloc):
		_size(0),
		_capacity(0),
		_array(NULL),
		_alloc(alloc){}

	template <class T, class Allocator>
	vector<T, Allocator>::vector(size_type size,
		const_reference val,
		const allocator_type &alloc):
		_size(size),
		_capacity(size),
		_alloc(alloc)
	{
		_array = _alloc.allocate(_capacity);
		try
		{
			for (size_type i = 0; i < _size; ++i)
				_alloc.construct(&_array[i], val);
		}
		catch(...)
		{
			this->clear();
			_alloc.deallocate(_array, _capacity);
			throw  ;
		}
	}

	//

	template <typename T, typename Allocator>
	vector<T, Allocator>::vector(const vector &copy):
		_size(copy._size),
		_capacity(copy._size),
		_alloc(copy._alloc)
	{
		if (_capacity)
			_array = _alloc.allocate(_capacity);
		try
		{
			for (size_type i = 0; i < _size; ++i)
				_alloc.construct(&_array[i], copy._array[i]);	
		}
		catch(...)
		{
			this->clear();
			_alloc.deallocate(_array, _capacity);
			throw ;
		}
	}

	// template <typename T, typename Allocator>
	// vector<T, Allocator>&	vector<T, Allocator>::operator=(const vector &rhs)
	// {
	// 	if (this != &other)
	// 	{
	// 		this->clear();
	// 		_alloc.deallocate(_array, _capacity);

	// 	}
	// 	return (*this);
	// }

	template <typename T, typename Allocator>
	vector<T, Allocator>::~vector()
	{
		this->clear();
		if (_array != 0)
			_alloc.deallocate(_array, _capacity);
	}

	/*=================================*/
	/*	Member functions Iterators */

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::iterator
	vector<T, Allocator>::begin()
	{
		return (iterator(this->_array));
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::const_iterator
	vector<T, Allocator>::begin() const
	{
		return (const_iterator(this->_array));
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::iterator
	vector<T, Allocator>::end()
	{
		return (iterator(this->_array + this->_size));
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::const_iterator
	vector<T, Allocator>::end() const
	{
		return (const_iterator(this->_array + this->_size));
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::reverse_iterator
	vector<T, Allocator>::rbegin()
	{
		return (reverse_iterator(this->end()));
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::const_reverse_iterator
	vector<T, Allocator>::rbegin() const
	{
		return (const_reverse_iterator(this->end()));
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::reverse_iterator
	vector<T, Allocator>::rend()
	{
		return (reverse_iterator(this->begin()));
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::const_reverse_iterator
	vector<T, Allocator>::rend() const
	{
		return (const_reverse_iterator(this->begin()));
	}
	
	/*=================================*/
	/* Member functions Element access */

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::reference
	vector<T, Allocator>::operator[](size_type n)
	{
		return (this->_array[n]);
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::const_reference
	vector<T, Allocator>::operator[](size_type n) const
	{
		return (this->_array[n]);
	}

	/*=================================*/
	/*	Member functions Modifiers */
	
	template <typename T, typename Allocator>
	void	vector<T, Allocator>::swap(vector	&other)
	{
		pointer			tmp_array = _array;
		_array 			= other._array;
		other._array 	= tmp_array;

		size_type		tmp_size = _size;
		_size 			= other._size;
		other._size 	= tmp_size;

		size_type		tmp_capacity = _capacity;
		_capacity 		= other._capacity;
		other._capacity = tmp_capacity;

		allocator_type	tmp_allocator = _alloc;
		_alloc 			= other._alloc;
		other._alloc 	= tmp_allocator;
	}
	
	template <typename T, typename Allocator>
	void	vector<T, Allocator>::clear()
	{
		for (size_type i = 0; i < _size; ++i)
			_alloc.destroy(_array + i);
		_size = 0;
	}

	/*=================================*/
	/*	Non-member functions (operators) */

	template <typename T, typename Allocator>
	void	swap(	vector<T, Allocator> &lhs,
					vector<T,Allocator> &rhs)
	{
		lhs.swap(rhs);
	}
	
	template <typename T, typename Allocator>
	bool	operator==(	const vector<T, Allocator> &lhs,
						const vector<T, Allocator> &rhs)
	{
		if (lhs._size != rhs._size)
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <typename T, typename Allocator>
	bool	operator!=(	const vector<T, Allocator> &lhs,
						const vector<T, Allocator> &rhs)
	{
		return (!(lhs == rhs));
	}
	
	template <typename T, typename Allocator>
	bool	operator<(	const vector<T, Allocator> &lhs,
						const vector<T, Allocator> &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <typename T, typename Allocator>
	bool	operator<=(	const vector<T, Allocator> &lhs,
						const vector<T, Allocator> &rhs)
	{
		return (!(rhs < lhs));
	}

	template <typename T, typename Allocator>
	bool	operator>(	const vector<T, Allocator> &lhs,
						const vector<T, Allocator> &rhs)
	{
		return (rhs < lhs);
	}

	template <typename T, typename Allocator>
	bool	operator>=(	const vector<T, Allocator> &lhs,
						const vector<T, Allocator> &rhs)
	{
		return (!(lhs < rhs));
	}
	
}	//end of "namespace	ft"


#endif