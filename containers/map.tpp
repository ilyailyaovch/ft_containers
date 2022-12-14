/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 20:13:27 by ilya              #+#    #+#             */
/*   Updated: 2022/11/12 13:35:09 by ilya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_TPP
#define MAP_TPP

namespace ft
{
	/*====================================================*/
	/*	Constructors and destructors */
	/*====================================================*/

	template <typename Key, typename T, typename Compare, typename Allocator>
	map<Key, T, Compare, Allocator>::map(const key_compare &comp,
										 const allocator_type &alloc):
	_tree(comp, alloc)
	{
	}

	template <typename Key, typename T, typename Compare, typename Allocator>
	template <typename InputIterator>
	map<Key, T, Compare, Allocator>::map(	InputIterator first,
											InputIterator last,
											const key_compare &comp,
											const allocator_type &alloc):
	_tree(comp, alloc)
	{
		this->insert(first, last);
	}

	template < typename Key, typename T, typename Compare, typename Allocator>
	map<Key, T, Compare, Allocator>::map(const map &other) :
	_tree(other._tree)
	{
	}

	template < typename Key, typename T, typename Compare, typename Allocator>
	map<Key, T, Compare, Allocator>&
	map<Key, T, Compare, Allocator>::operator=(const map &other)
	{
		if (this != &other)
			this->_tree = other._tree;
		return (*this);
	}

	template < typename Key, typename T, typename Compare, typename Allocator>
	map<Key, T, Compare, Allocator>::~map()
	{
	}

	/*====================================================*/
	/*	Iterators */
	/*====================================================*/

	template < typename Key, typename T, typename Compare, typename Allocator>
 	typename map<Key, T, Compare, Allocator>::iterator
	map<Key, T, Compare, Allocator>::begin()
	{
		return (this->_tree.begin());
	}
	
	template < typename Key, typename T, typename Compare, typename Allocator>
	typename map<Key, T, Compare, Allocator>::const_iterator
	map<Key, T, Compare, Allocator>::begin() const
	{
		return (this->_tree.begin());
	}

	template < typename Key, typename T, typename Compare, typename Allocator>
	typename map<Key, T, Compare, Allocator>::iterator
	map<Key, T, Compare, Allocator>::end()
	{
		return (this->_tree.end());
	}

	template < typename Key, typename T, typename Compare, typename Allocator>
	typename map<Key, T, Compare, Allocator>::const_iterator
	map<Key, T, Compare, Allocator>::end() const
	{
		return (this->_tree.end());
	}

	template < typename Key, typename T, typename Compare, typename Allocator>
	typename map<Key, T, Compare, Allocator>::reverse_iterator
	map<Key, T, Compare, Allocator>::rbegin()
	{
		return (this->_tree.rbegin());
	}

	template < typename Key, typename T, typename Compare, typename Allocator>
	typename map<Key, T, Compare, Allocator>::const_reverse_iterator
	map<Key, T, Compare, Allocator>::rbegin() const
	{
		return (this->_tree.rbegin());
	}

	template < typename Key, typename T, typename Compare, typename Allocator>
	typename map<Key, T, Compare, Allocator>::reverse_iterator
	map<Key, T, Compare, Allocator>::rend()
	{
		return (this->_tree.rend());
	}

	template < typename Key, typename T, typename Compare, typename Allocator>
	typename map<Key, T, Compare, Allocator>::const_reverse_iterator 
	map<Key, T, Compare, Allocator>::rend() const
	{
		return (this->_tree.rend());
	}

	/*====================================================*/
	/*	Capacity */
	/*====================================================*/

	template < typename Key, typename T, typename Compare, typename Allocator>
	bool	map<Key, T, Compare, Allocator>::empty() const
	{
		return (this->_tree.empty());
	}

	template < typename Key, typename T, typename Compare, typename Allocator>
	typename map<Key, T, Compare, Allocator>::size_type
	map<Key, T, Compare, Allocator>::size() const
	{
		return (this->_tree.size());
	}

	template < typename Key, typename T, typename Compare, typename Allocator>
	typename map<Key, T, Compare, Allocator>::size_type
	map<Key, T, Compare, Allocator>::max_size() const
	{
		return (this->_tree.max_size());
	}

	/*====================================================*/
	/*	Element access */
	/*====================================================*/

	template < typename Key, typename T, typename Compare, typename Allocator>
	typename map<Key, T, Compare, Allocator>::mapped_type &
	map<Key, T, Compare, Allocator>::operator[](const key_type &key)
	{
		return (this->_tree.insert(ft::make_pair(key, mapped_type())).first->second);
	}

	template < typename Key, typename T, typename Compare, typename Allocator>
	typename map<Key, T, Compare, Allocator>::mapped_type &
	map<Key, T, Compare, Allocator>::at(const key_type &key)
	{
		iterator	it;

		it = this->find(key);
		if (it == this->end())
			throw std::out_of_range("map::at:  key not found");
		return (it->second);
	}

	template < typename Key, typename T, typename Compare, typename Allocator>
	const typename map<Key, T, Compare, Allocator>::mapped_type &
	map<Key, T, Compare, Allocator>::at(const key_type &key) const
	{
		iterator	it;

		it = this->find(key);
		if (it == this->end())
			throw std::out_of_range("map::at:  key not found");
		return (it->second);
	}

	/*====================================================*/
	/*	Modifires */
	/*====================================================*/
	
	template < typename Key, typename T, typename Compare, typename Allocator>
	ft::pair <typename map<Key, T, Compare, Allocator>::iterator, bool>
	map<Key, T, Compare, Allocator>::insert(const value_type &val)
	{
		return (this->_tree.insert(val));
	}

	template < typename Key, typename T, typename Compare, typename Allocator>
	typename map<Key, T, Compare, Allocator>::iterator
	map<Key, T, Compare, Allocator>::insert(iterator it, const value_type &val)
	{
		return(this->_tree.insert(it, val));
	}

	template < typename Key, typename T, typename Compare, typename Allocator>
	template <class InputIt>
	void	map<Key, T, Compare, Allocator>::insert(InputIt first, InputIt last)
	{
		while (first != last)
		{
			this->_tree.insert(*first);
			++first;
		}
	}

	template < typename Key, typename T, typename Compare, typename Allocator>
	void	map<Key, T, Compare, Allocator>::erase(iterator pos)
	{
		this->_tree.erase(pos);
	}

	template < typename Key, typename T, typename Compare, typename Allocator>
	void	map<Key, T, Compare, Allocator>::erase(iterator first, iterator last)
	{
		while (first != last)
			this->_tree.erase(first++);
	}

	template < typename Key, typename T, typename Compare, typename Allocator>
	typename map<Key, T, Compare, Allocator>::size_type
	map<Key, T, Compare, Allocator>::erase(const key_type &key)
	{
		value_type	tmp(key, T());

		return (this->_tree.erase(tmp));
	}

	template < typename Key, typename T, typename Compare, typename Allocator>
	void	map<Key, T, Compare, Allocator>::swap(map<Key, T, Compare, Allocator> &other)
	{
		this->_tree.swap(other._tree);
	}

	template < typename Key, typename T, typename Compare, typename Allocator>
	void	map<Key, T, Compare, Allocator>::clear()
	{
		this->_tree.clear();
	}

	/*====================================================*/
	/*	Observers */
	/*====================================================*/

	template < typename Key, typename T, typename Compare, typename Allocator>
	typename map<Key, T, Compare, Allocator>::key_compare
	map<Key, T, Compare, Allocator>::key_comp() const
	{
		return (key_compare());
	}

	template < typename Key, typename T, typename Compare, typename Allocator>
	typename map<Key, T, Compare, Allocator>::value_compare
	map<Key, T, Compare, Allocator>::value_comp() const
	{
		return (value_compare(key_compare()));
	}

	/*====================================================*/
	/*	Operations */
	/*====================================================*/

	template < typename Key, typename T, typename Compare, typename Allocator>
	typename map<Key, T, Compare, Allocator>::iterator
	map<Key, T, Compare, Allocator>::find(const key_type &key)
	{
		value_type	tmp(key, T());
		iterator	it(_tree.get_null(), _tree.search(tmp));
		
		return (it);
	}

	template < typename Key, typename T, typename Compare, typename Allocator>
	typename map<Key, T, Compare, Allocator>::const_iterator
	map<Key, T, Compare, Allocator>::find(const key_type &key) const
	{
		value_type		tmp(key, T());
		const_iterator	it(_tree.get_null(), _tree.search(tmp));
		
		return (it);
	}

	template < typename Key, typename T, typename Compare, typename Allocator>
	typename map<Key, T, Compare, Allocator>::size_type
	map<Key, T, Compare, Allocator>::count(const key_type &key) const
	{
		value_type		tmp(key, T());

		return (_tree.count(tmp));
	}

	template < typename Key, typename T, typename Compare, typename Allocator>
	typename map<Key, T, Compare, Allocator>::iterator
	map<Key, T, Compare, Allocator>::lower_bound(const key_type &key) 
	{
		value_type		tmp(key, T());

		return (_tree.lower_bound(tmp));
	}

	template < typename Key, typename T, typename Compare, typename Allocator>
	typename map<Key, T, Compare, Allocator>::const_iterator
	map<Key, T, Compare, Allocator>::lower_bound(const key_type &key) const
	{
		value_type		tmp(key, T());

		return (_tree.lower_bound(tmp));
	}

	template < typename Key, typename T, typename Compare, typename Allocator>
	typename map<Key, T, Compare, Allocator>::iterator
	map<Key, T, Compare, Allocator>::upper_bound(const key_type &key) 
	{
		value_type		tmp(key, T());

		return (_tree.upper_bound(tmp));
	}

	template < typename Key, typename T, typename Compare, typename Allocator>
	typename map<Key, T, Compare, Allocator>::const_iterator
	map<Key, T, Compare, Allocator>::upper_bound(const key_type &key) const
	{
		value_type		tmp(key, T());

		return (_tree.upper_bound(tmp));
	}

	template < typename Key, typename T, typename Compare, typename Allocator>
	ft::pair<	typename map<Key, T, Compare, Allocator>::iterator,
				typename map<Key, T, Compare, Allocator>::iterator>			
	map<Key, T, Compare, Allocator>::equal_range(const key_type &key)
	{
		value_type		tmp(key, T());

		return (_tree.equal_range(tmp));
	}

	template < typename Key, typename T, typename Compare, typename Allocator>
	ft::pair<	typename map<Key, T, Compare, Allocator>::const_iterator,
				typename map<Key, T, Compare, Allocator>::const_iterator>			
	map<Key, T, Compare, Allocator>::equal_range(const key_type &key) const
	{
		value_type		tmp(key, T());

		return (_tree.equal_range(tmp));
	}

	/*====================================================*/
	/*	Allocator */
	/*====================================================*/

	template < typename Key, typename T, typename Compare, typename Allocator>
	typename map<Key, T, Compare, Allocator>::allocator_type
		map<Key, T, Compare, Allocator>::get_allocator() const
	{
		return (this->_tree.get_allocator());
	}

	/*====================================================*/
	/*	Non-member functions */
	/*====================================================*/

	template < typename Key, typename T, typename Compare, typename Alloc>
	void	swap(	ft::map<Key, T, Compare, Alloc> &lhs,
					ft::map<Key, T, Compare, Alloc> &rhs)
	{
		lhs.swap(rhs);
 	}

	template < typename Key, typename T, typename Compare, typename Alloc>
	bool	operator==(	const ft::map<Key, T, Compare, Alloc> &lhs,
						const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
 	}

	template < typename Key, typename T, typename Compare, typename Alloc>
	bool	operator!=(	const ft::map<Key, T, Compare, Alloc> &lhs,
						const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs == rhs));
 	}

	template < typename Key, typename T, typename Compare, typename Alloc>
	bool	operator<(	const ft::map<Key, T, Compare, Alloc> &lhs,
						const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(),
											rhs.begin(), rhs.end()));
 	}

	template < typename Key, typename T, typename Compare, typename Alloc>
	bool	operator<=(	const ft::map<Key, T, Compare, Alloc> &lhs,
						const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(rhs < lhs));
 	}

	template < typename Key, typename T, typename Compare, typename Alloc>
	bool	operator>(	const ft::map<Key, T, Compare, Alloc> &lhs,
						const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return (rhs < lhs);
 	}

	template < typename Key, typename T, typename Compare, typename Alloc>
	bool	operator>=(	const ft::map<Key, T, Compare, Alloc> &lhs,
						const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs < rhs));
 	}

} // end of "namespace	ft"

#endif