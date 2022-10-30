/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:05:08 by ilya              #+#    #+#             */
/*   Updated: 2022/10/30 10:56:15 by ilya             ###   ########.fr       */
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
	/* Member functions Capacity */

	template <typename T, typename Allocator>
	bool	vector<T, Allocator>::empty() const
	{
		return (this->_size == 0);
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::size_type
	vector<T, Allocator>::size() const
	{
		return (this->_size);
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::size_type
	vector<T, Allocator>::max_size() const
	{
		return (this->_alloc.max_size());
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::size_type
	vector<T, Allocator>::capacity() const
	{
		return (this->_capacity);
	}

	template <typename T, typename Allocator>
	void	vector<T, Allocator>::reserve(size_type new_cap)
	{
		pointer		tmp;
		size_type 	i;

		if (this->_size ==  this->max_size())
			throw std::length_error("vector::out of max_size");
		else if (new_cap > this->_capacity)
		{
			tmp = _alloc.allocate(new_cap);
			try
			{
				for (i = 0; i < this->_size; ++i)
				{
					_alloc.construct(tmp + i, this->_array[i]);
					_alloc.destroy(_alloc.address(this->_array[i]));
				}
			}
			catch (...)
			{
				for (size_type j = 0; j < i; j++)
                	_alloc.destroy(tmp + j);
				_alloc.deallocate(tmp, new_cap);
				throw ;
			}
			_alloc.deallocate(this->_array, this->_capacity);
			this->_capacity = new_cap;
			this->_array = tmp;
		}
	}

	template <typename T, typename Allocator>
	void	vector<T, Allocator>::resize(size_type n, value_type val)
	{
		if (n > this->max_size())
			throw std::logic_error("vector:resize, max_size error");
		else if (n < this->_size)
			this->erase(this->begin() + n, this->end());
		else if (n > this->_size)
			this->insert(this->end(), n - this->_size, val);
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

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::reference
	vector<T, Allocator>::at(size_type pos)
	{
		if (!(pos < _size))
			throw std::out_of_range("Index out of range");
		return this->_array[pos];
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::const_reference
	vector<T, Allocator>::at(size_type pos) const
	{
		if (!(pos < _size))
			throw std::out_of_range("Index out of range");
		return this->_array[pos];
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::reference
	vector<T, Allocator>::front()
	{
		return (this->_array[0]);
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::const_reference
	vector<T, Allocator>::front() const
	{
		return (this->_array[0]);
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::reference
	vector<T, Allocator>::back()
	{
		return (this->_array[this->_size - 1]);
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::const_reference
	vector<T, Allocator>::back() const
	{
		return (this->_array[this->_size - 1]);
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::pointer
	vector<T, Allocator>::data()
	{
		return (this->_array);
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::const_pointer
	vector<T, Allocator>::data() const
	{
		return (this->_array);
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