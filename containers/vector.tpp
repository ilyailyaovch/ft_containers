/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:05:08 by ilya              #+#    #+#             */
/*   Updated: 2022/10/19 13:07:56 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TPP
# define VECTOR_TPP

namespace ft
{
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
		_alloc(alloc){
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
	vector<T, Allocator>::~vector()
	{
		this->clear();
		if (_array != 0)
			_alloc.deallocate(_array, _capacity);
	}


	/*	Member functions */

	template <typename T, typename Allocator>
	void	vector<T, Allocator>::clear()
	{
		for (size_type i = 0; i < _size; ++i)
			_alloc.destroy(_array + i);
		_size = 0;
	}
	
}	//end of "namespace	ft"


#endif