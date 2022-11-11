/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:05:08 by ilya              #+#    #+#             */
/*   Updated: 2022/11/12 01:32:30 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TPP
# define VECTOR_TPP

namespace ft
{
	/*====================================================*/
	/*	Canonical form */
	/*====================================================*/

	template <typename T, typename Allocator>
	vector<T, Allocator>::vector(const allocator_type &alloc):
	_size(0), _capacity(0), _array(NULL), _alloc(alloc){}

	template <typename T, typename Allocator>
	vector<T, Allocator>::vector(	size_type size,
									const_reference val,
									const allocator_type &alloc)
	{
		size_type	i;

		_alloc = alloc;
		_array = size ? _alloc.allocate(size) : NULL;
		_capacity = size;
		_size = 0;
		try
		{
			for (i = 0; i < size; ++i)
			{
				_alloc.construct(_array + i, val);
				_size += 1;
			}
		}
		catch (...)
		{
			this->clear();
			this->_alloc.deallocate(this->_array, size);
			throw ;
		}
	}

	template <typename T, typename Allocator>
	template <typename InputIterator>
	vector<T, Allocator>::vector(	InputIterator first, InputIterator last,
		const allocator_type &alloc,
		typename enable_if<!is_integral<InputIterator>::value, bool>::type)
	{
		difference_type	diff;

		diff = ft::distance(first, last);
		this->_alloc = alloc;
		this->_array = _alloc.allocate(diff);
		this->_capacity = diff;
		this->_size = 0;
		try
		{
			while (first != last)
			{
				this->push_back(*first);
				++first;
			}
		}
		catch (...)
		{
			this->clear();
			this->_alloc.deallocate(this->_array, diff);
			throw ;
		}
	}

	template <typename T, typename Allocator>
	vector<T, Allocator>::vector(const vector &copy)
	{
		this->_alloc = copy._alloc;
		this->_array = this->_alloc.allocate(copy._capacity);
		this->_capacity = copy._capacity;
		this->_size = 0;
		while (this->_size != copy._size)
			this->push_back(copy[this->_size]);
	}

	template <typename T, typename Allocator>
	vector<T, Allocator>&	vector<T, Allocator>::operator=(const vector &rhs)
	{
		if (this != &rhs)
		{
			this->clear();
			if (this->_array != 0)
				_alloc.deallocate(this->_array, this->_capacity);
			this->_alloc = rhs._alloc;
			this->_array = _alloc.allocate(rhs._capacity);
			this->_capacity = rhs._capacity;
			this->_size = 0;
			while (this->_size != rhs._size)
				this->push_back(rhs[this->_size]);
		}
		return (*this);
	}

	template <typename T, typename Allocator>
	vector<T, Allocator>::~vector()
	{
		this->clear();
		if (_array != 0)
			_alloc.deallocate(_array, _capacity);
	}

	/*====================================================*/
	/*	Member functions Iterators */
	/*====================================================*/

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
	
	/*====================================================*/
	/* Member functions Capacity */
	/*====================================================*/

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
		size_type i;
		
		if (this->_size ==  this->max_size())
			throw std::length_error("vector::out of max_size");
		else if (new_cap > this->_capacity)
		{
			pointer tmp = this->_alloc.allocate(new_cap);
			try
			{
				for (i = 0; i < this->_size; ++i)
				{
					this->_alloc.construct(tmp + i, this->_array[i]);
					this->_alloc.destroy(this->_alloc.address(this->_array[i]));
				}
			}
			catch (...)
			{
				for (size_type j = 0; j < i; j++)
                	this->_alloc.destroy(tmp + j);
				this->_alloc.deallocate(tmp, new_cap);
				throw ;
			}
			this->_alloc.deallocate(this->_array, this->_capacity);
			this->_capacity = new_cap;
			this->_array = tmp;
		}
	}

	template <typename T, typename Allocator>
	void	vector<T, Allocator>::resize(size_type n, value_type val)
	{
		if (n < _size)
		{
			for (size_type i = n; i < _size; i++)
				_alloc.destroy(_array + i);
		}
		else
		{
			if (n > _capacity)
			{
				size_type tmpCap = (_capacity * 2 > n) ? (_capacity * 2) : (n);
				reserve(tmpCap);
			}
			for (size_type i = _size; i < n; i++) 
				_alloc.construct(_array + i, val);
		}
		_size = n;
	}
	
	/*====================================================*/
	/* Member functions Element access */
	/*====================================================*/

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

	/*====================================================*/
	/*	Member functions Modifiers */
	/*====================================================*/
	
	template <typename T, typename Allocator>
	void	vector<T, Allocator>::clear()
	{
		for (size_type i = 0; i < _size; ++i)
			_alloc.destroy(_array + i);
		_size = 0;
	}

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
	typename vector<T, Allocator>::iterator
	vector<T, Allocator>::erase(iterator pos)
	{
		return (this->erase(pos, pos + 1));
	}

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::iterator
	vector<T, Allocator>::erase(iterator first, iterator last)
	{
		size_type	count;
		size_type	start;
		size_type	tmp_start;

		count = last - first;
		start = first - this->begin();
		tmp_start = start;
		while (first != last)
		{
			_alloc.destroy(_alloc.address(*first));
			++first;
		}
		while (count != 0 && last < this->end())
		{
			_alloc.construct(_alloc.address(this->_array[tmp_start++]), *last);
			_alloc.destroy(_alloc.address(*last));
			++last;
		}
		this->_size -= count;
		return (this->begin() + start);
	}

	template <typename T, typename Allocator>
	void	vector<T, Allocator>::push_back(const value_type &val)
	{
		if (this->_size == this->_capacity)
		{
			if (this->_capacity == 0)
				this->reserve(1);
			else if (this->max_size() >= this->_capacity * 2)
				this->reserve(this->_capacity * 2);
			else
				this->reserve(this->max_size());
		}
		_alloc.construct(this->_array + this->_size, val);
		this->_size += 1;
	}

	template <typename T, typename Allocator>
	void	vector<T, Allocator>::pop_back(void)
	{
		_alloc.destroy(&this->back());
		this->_size -= 1;
	}

	// insert(value)
	template <typename T, typename Allocator>
	typename vector<T, Allocator>::iterator
	vector<T, Allocator>::insert(iterator pos, const T &value)
	{
		size_type	insertStart;

		insertStart = static_cast<size_type>(pos - this->begin());
		this->insert(pos, 1, value);
		return (this->begin() + insertStart);
	}

	// insert(fill)
	template <typename T, typename Allocator>
	void    vector<T, Allocator>::insert(iterator pos, size_type count, const value_type& value)
	{
		// difference_type	dist = position - this->begin();
		// if (this->_size == 0)
		// 	reserve(n);
		// else if (this->_size + n > this->_capacity)
		// {
		// 	if (this->_size < n)
		// 		reserve(this->_size + n);
		// 	else
		// 		reserve(this->_capacity * 2);
		// }
		
		// for (difference_type i = this->_size - 1; i >= dist; i--) 
		// 	_alloc.construct(&_array[i + n], _array[i]);
		// for (size_type i = 0; i < n; i++)
		// {
		// 	_alloc.construct(&_array[dist], val);
		// 	dist++;
		// }
		// this->_size += n;
		pointer		tmp;
		size_type	start;
		size_type	i;
		size_type	j;

		start = static_cast<size_type>(pos - this->begin());
		i = 0;
		j = 0;
		if (count == 0)
			return ;
		else if (pos < this->begin() && pos > this->end())
			throw std::logic_error("vector:insert error");
		else if (this->max_size() < this->_size + count)
			throw std::length_error("vector:insert error");
		if (this->_size + count > this->_capacity)
		{
			size_type	tmp_cap = (_capacity * 2 >= this->_size + count) ? \
								 (this->_capacity * 2) : (this->_size + count);
			tmp = this->_alloc.allocate(tmp_cap);
			try
			{
				for (; i < start; ++i)
					this->_alloc.construct(tmp + i, this->_array[i]);
				for (; j < count; ++j)
					this->_alloc.construct(tmp + i + j, value);
				for (; i + j < (this->_size + count); ++i)
					this->_alloc.construct(tmp + i + j, this->_array[i]);
				for (int t = 0; i < this->_size; ++t)
					this->_alloc.destroy(this->_alloc.address(this->_array[t]));
			}
			catch (...)
			{
				for (size_type t = 0; t < i + j; t++)
                	this->_alloc.destroy(tmp + t);
				this->_alloc.deallocate(tmp, this->_size + count);
				throw ;
			}
			this->_alloc.deallocate(this->_array, this->_capacity);
			this->_capacity = tmp_cap;
			this->_array = tmp;
		}
		else
		{
			for (size_type t = this->_size + count - 1; t >= start; --t)
			{
				if (t >= start && t < start + count)
					this->_alloc.construct(this->_array + t, value);
				else if (t >= this->_size)
					this->_alloc.construct(this->_array + t, this->_array[t - count]);
				else if (t <= this->_size && t >= start + count)
				{
					this->_alloc.destroy(this->_array + t);
					this->_alloc.construct(this->_array + t, this->_array[t - count]);
				}
				if (t == 0)
					break ;
			}
		}
		this->_size = this->_size + count;
	}
	
	// insert(range || iterators)
	template <typename T, typename Allocator>
	template <typename InputIt>
	void    vector<T, Allocator>::insert(iterator pos, InputIt first, InputIt last,
		typename enable_if<!is_integral<InputIt>::value, bool>::type)
	{
		pointer		tmp;
		size_type	i, j;

		size_type count = static_cast<size_type>(last - first);
		size_type start = static_cast<size_type>(pos - this->begin());
		i = 0;
		j = 0;
		if (count == 0)
			return ;
		else if (pos < this->begin() && pos > this->end())
			throw std::logic_error("vector:insert error");
		else if (this->max_size() < this->_size + count)
			throw std::length_error("vector:insert error");
		if (this->_size + count > this->_capacity)
		{
			size_type	tmp_cap = (_capacity * 2 >= this->_size + count) ? \
								 (this->_capacity * 2) : (this->_size + count);
			tmp = this->_alloc.allocate(tmp_cap);
			try
			{
				for (; i < start; ++i)
					this->_alloc.construct(tmp + i, this->_array[i]);
				for (; j < count; ++j)
					this->_alloc.construct(tmp + i + j, *(first++));
				for (; i + j < (this->_size + count); ++i)
					this->_alloc.construct(tmp + i + j, this->_array[i]);
				for (int t = 0; i < this->_size; ++t)
					this->_alloc.destroy(this->_alloc.address(this->_array[t]));
			}
			catch (...)
			{
				for (size_type t = 0; t < i + j; t++)
                	this->_alloc.destroy(tmp + t);
				this->_alloc.deallocate(tmp, this->_size + count);
				throw ;
			}
			this->_alloc.deallocate(this->_array, this->_capacity);
			this->_capacity = tmp_cap;
			this->_array = tmp;
		}
		else
		{
			for (size_type t = this->_size + count - 1; t >= start; --t)
			{
				if (t >= start && t < start + count)
					this->_alloc.construct(this->_array + t, *(--last));
				else if (t >= this->_size)
					this->_alloc.construct(this->_array + t, this->_array[t - count]);
				else if (t <= this->_size && t >= start + count)
				{
					this->_alloc.destroy(this->_array + t);
					this->_alloc.construct(this->_array + t, this->_array[t - count]);
				}
				if (t == 0)
					break ;
			}
		}
		this->_size = this->_size + count;
	}

	template <typename T, typename Allocator>
	void	vector<T, Allocator>::assign(size_type n, const value_type &val)
	{
		this->erase(this->begin(), this->end());
		this->reserve(n);
		this->insert(this->begin(), n, val);
	}

	template <typename T, typename Allocator>
	template <typename InputIt>
	void	vector<T, Allocator>::assign(InputIt first, InputIt last,
		typename enable_if<!is_integral<InputIt>::value, bool>::type)
	{
		this->erase(this->begin(), this->end());
		this->reserve(ft::distance(first, last));
		this->insert(this->begin(), first, last);
	}

	/*====================================================*/
	/*	Member functions (Allocator) */
	/*====================================================*/

	template <typename T, typename Allocator>
	typename vector<T, Allocator>::allocator_type
	vector<T, Allocator>::get_allocator() const
	{
		return (this->_alloc);
	}

	/*====================================================*/
	/*	Non-member functions (operators) */
	/*====================================================*/

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
		if (lhs.size() != rhs.size())
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