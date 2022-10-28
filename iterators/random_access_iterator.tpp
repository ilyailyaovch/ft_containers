#ifndef FT_RANDOM_ACCESS_ITERATOR_TPP
# define FT_RANDOM_ACCESS_ITERATOR_TPP

namespace ft
{
	/*=================================*/
	/*	Canonical form */

	template <typename T>
	random_access_iterator<T>::random_access_iterator():
		_elem(NULL){}

	template <typename T>
	random_access_iterator<T>::random_access_iterator(pointer ptr):
		_elem(ptr){}

	template <typename T>	//!!!!!!!!
	random_access_iterator<T>::random_access_iterator(const random_access_iterator &other):
		_elem(other._elem){} 
	
	template <typename T>	//!!!!!!!!
	random_access_iterator<T>&
	random_access_iterator<T>::operator=(const random_access_iterator &other)
	{
		if (this != &other)
			this->_elem = other._elem;
		return (*this);
	}

	template <typename T>
	random_access_iterator<T>::~random_access_iterator()
	{
	}

	/*=================================*/
	/*	Member functions */
	
	template <typename T>
	bool	random_access_iterator<T>::operator==(const random_access_iterator &other) const
	{
		return (this->_elem == other._elem);
	}

	template <typename T>
	bool	random_access_iterator<T>::operator!=(const random_access_iterator &other) const
	{
		return (this->_elem != other._elem);
	}

	// prefix	(++a)
	template <typename T>	
	random_access_iterator<T>	&random_access_iterator<T>::operator++()
	{
		this->_elem += 1;
		return (*this);
	}

	// prefix	(--a)
	template <typename T>	
	random_access_iterator<T>	&random_access_iterator<T>::operator--()
	{
		this->_elem -= 1;
		return (*this);
	}

	// postfix	(a++)
	template <typename T>	
	random_access_iterator<T>	random_access_iterator<T>::operator++(int)
	{
		random_access_iterator<T>	temp;
		temp = *this;
		this->_elem += 1;
		return (temp);
	}

	// postfix	(a--)
	template <typename T>	
	random_access_iterator<T>	random_access_iterator<T>::operator--(int)
	{
		random_access_iterator<T>	temp;
		temp = *this;
		this->_elem -= 1;
		return (temp);
	}

	//	a + n
	template <typename T>
	random_access_iterator<T>
	random_access_iterator<T>::operator+(difference_type num) const
	{
		random_access_iterator<T>	temp(*this);
		temp._elem += num;
		return (temp);
	}

	//	a - n
	template <typename T>		
	random_access_iterator<T>
	random_access_iterator<T>::operator-(difference_type num) const
	{
		random_access_iterator<T>	temp(*this);
		temp._elem -= num;
		return (temp);
	}

	//a - b
	template <typename T>
	typename random_access_iterator<T>::difference_type
	random_access_iterator<T>::operator-(const random_access_iterator<T> &other) const
	{
		return (_elem - other._elem);
	}

	template <typename T>
	random_access_iterator<T>&
	random_access_iterator<T>::operator+=(difference_type num)
	{
		this->_elem += num;
		return (*this);
	}

	template <typename T>
	random_access_iterator<T>&
	random_access_iterator<T>::operator-=(difference_type num)
	{
		this->_elem -= num;
		return (*this);
	}

	template <typename T>
	bool	random_access_iterator<T>::operator>(const random_access_iterator &other) const
	{
		return (this->_elem > other._elem);
	}

	template <typename T>
	bool	random_access_iterator<T>::operator<(const random_access_iterator &other) const
	{
		return (this->_elem < other._elem);
	}

	template <typename T>
	bool	random_access_iterator<T>::operator>=(const random_access_iterator &other) const
	{
		return (this->_elem >= other._elem);
	}

	template <typename T>
	bool	random_access_iterator<T>::operator<=(const random_access_iterator &other) const
	{
		return (this->_elem <= other._elem);
	}

	template <typename T>
	typename random_access_iterator<T>::pointer	random_access_iterator<T>::base() const
	{
		return (this->_elem);
	}

	/*=================================*/
	/* For Non-member functions  */

	template <typename T_L, typename T_R>
	typename random_access_iterator<T_L>::difference_type
	operator-(const random_access_iterator<T_L> &lhs, const random_access_iterator<T_R> &rhs)
	{
		return (lhs.base() - rhs.base());
	}

	template <typename T_L, typename T_R>
	bool operator>(	const random_access_iterator<T_L> &lhs,
					const random_access_iterator<T_R> &rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <typename T_L, typename T_R>
	bool operator<(	const random_access_iterator<T_L> &lhs,
					const random_access_iterator<T_R> &rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <typename T_L, typename T_R>
	bool operator>=(const random_access_iterator<T_L> &lhs,
					const random_access_iterator<T_R> &rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <typename T_L, typename T_R>
	bool operator<=(const random_access_iterator<T_L> &lhs,
					const random_access_iterator<T_R> &rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <typename T_L, typename T_R>
	bool operator==(const random_access_iterator<T_L> &lhs,
					const random_access_iterator<T_R> &rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <typename T_L, typename T_R>
	bool operator!=(const random_access_iterator<T_L> &lhs,
					const random_access_iterator<T_R> &rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <typename T>
	random_access_iterator<T>
	operator+(	typename random_access_iterator<T>::difference_type n,
				random_access_iterator<T> &rhs)
	{
		return (rhs + n);
	}

};	//end of "namespace	ft"

#endif