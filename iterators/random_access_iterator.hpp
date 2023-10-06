/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:21:48 by adouib            #+#    #+#             */
/*   Updated: 2023/03/13 19:29:07 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterator_traits.hpp"

#include <iostream>

namespace ft
{
	template <typename T>
	struct random_access_iterator
	{
		// Member types

		// typedef T value_type;
		// typedef ptrdiff_t difference_type;
		// typedef value_type* pointer;
		// typedef value_type& reference;
		// typedef std::random_access_iterator_tag iterator_category;

		typedef typename iterator_traits<T *>::value_type value_type;
		typedef typename iterator_traits<T *>::difference_type difference_type;
		typedef typename iterator_traits<T *>::pointer pointer;
		typedef typename iterator_traits<T *>::reference reference;
		typedef std::random_access_iterator_tag iterator_category;

		random_access_iterator() : _ptr(NULL) {} // Default constructor
		// Constructor that takes a pointer to the element type
		// Creates an iterator that points to the element at the specified pointer.
		random_access_iterator(pointer vector_data) : _ptr(vector_data) {}
		// copy constructor

		template<typename Iter> // Iter could be const T (value_type) or non-const, this serves the case when trying to assign a non-const iterator to a const iterator
		random_access_iterator(const random_access_iterator<Iter> &other) : _ptr(other.base()) { }

		random_access_iterator(const random_access_iterator &other) : _ptr(other._ptr) { }
		// assignement operator
		random_access_iterator &operator=(const random_access_iterator &other)
		{
			if (*this != other)
				_ptr = other._ptr;
			return *this;
		}
		// destructor
		~random_access_iterator() {}

		pointer base() const { return _ptr; }

		// Dereference operator - Returns a reference to the element pointed to by the iterator.
		reference operator*() const { return *_ptr; }

		// Arrow operator (returns a pointer to the element type)
		pointer operator->() const { return _ptr; }

		// Prefix increment operator - advances the iterator to the next element and returns a reference to the
		random_access_iterator &operator++()
		{
			++_ptr;
			return *this;
		}

		// Postfix increment operator - Advances the iterator to the next element and returns a copy of the iterator before it was advanced.
		random_access_iterator operator++(int)
		{
			pointer copy = _ptr;
			++_ptr;
			return random_access_iterator(copy);
		}

		// Prefix decrement operator - Moves the iterator to the previous element and returns a reference to the moved iterator.
		random_access_iterator &operator--()
		{
			--_ptr;
			return *this;
		}

		// Postfix decrement operator - Moves the iterator to the previous element and returns a copy of the iterator before it was moved.
		random_access_iterator operator--(int)
		{
			pointer copy = _ptr;
			--_ptr;
			return random_access_iterator(copy);
		}

		// // Addition operator - returns an iterator that points to the element `n` elements ahead of the current element.
		// // it = it + 2
		// // arithmetic oper on the addresses - distance between them in memory
		random_access_iterator operator+(difference_type n) const { return random_access_iterator(_ptr + n); }

		// // Subtraction operator Returns an iterator that points to the element `n` elements behind the current element.
		// // arithmetic oper on the addresses - distance between them in memory
		random_access_iterator operator-(difference_type n) const { return random_access_iterator(_ptr - n); }

		// Addition-assignment operator  Advances the iterator by `n` elements and returns a reference to the advanced iterator.
		// it += 2
		random_access_iterator &operator+=(difference_type n)
		{
			_ptr += n;
			return *this;
		}

		// Subtraction-assignment operator  Moves the iterator back by `n` elements and returns a reference to the moved iterator.
		random_access_iterator &operator-=(difference_type n)
		{
			_ptr -= n;
			return *this;
		}

		// offset | Element access operator Returns a reference to the element `n` elements ahead of the current element.
		reference operator[](difference_type n) const { return *(_ptr + n); }

	private:
		pointer _ptr;
	};

	// Relational Operators
	// In C++98, it is generally recommended to overload the relational operators (<, >, <=, >=, ==, and !=) as member functions of the class they operate on. This allows the operators to have access to the private and protected members of the class, which is necessary in order to compare the objects correctly.

	template <typename Iterator1, typename Iterator2>
	bool operator==(const random_access_iterator<Iterator1> &left, const random_access_iterator<Iterator2> &right) { return left.base() == right.base(); }
	template <typename Iterator1, typename Iterator2>
	bool operator!=(const random_access_iterator<Iterator1> &left, const random_access_iterator<Iterator2> &right) { return left.base() != right.base(); }
	template <typename Iterator1, typename Iterator2>
	bool operator<(const random_access_iterator<Iterator1> &left, const random_access_iterator<Iterator2> &right) { return left.base() < right.base(); }
	template <typename Iterator1, typename Iterator2>
	bool operator<=(const random_access_iterator<Iterator1> &left, const random_access_iterator<Iterator2> &right) { return left.base() <= right.base(); }
	template <typename Iterator1, typename Iterator2>
	bool operator>(const random_access_iterator<Iterator1> &left, const random_access_iterator<Iterator2> &right) { return left.base() > right.base(); }
	template <typename Iterator1, typename Iterator2>
	bool operator>=(const random_access_iterator<Iterator1> &left, const random_access_iterator<Iterator2> &right) { return left.base() >= right.base(); }

	template <typename T>
	typename random_access_iterator<T>::difference_type operator-(const random_access_iterator<T> &left, const random_access_iterator<T> &right) { return left.base() - right.base(); }
  // get_the_value_address(value_that_object_points_to)

	template <typename T>
	typename random_access_iterator<T>::difference_type operator+(const random_access_iterator<T> &left, const random_access_iterator<T> &right) { return left.base() + right.base(); }

	template <class T>
	random_access_iterator<T> operator+(typename random_access_iterator<T>::difference_type n, const random_access_iterator<T> &it) { return random_access_iterator<T>(it.base() + n); }

	template <class T>
	random_access_iterator<T> operator-(typename random_access_iterator<T>::difference_type n, const random_access_iterator<T> &it) { return random_access_iterator<T>(it.base() - n); }

}
