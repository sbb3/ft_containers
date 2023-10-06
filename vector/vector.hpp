/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:36:27 by adouib            #+#    #+#             */
/*   Updated: 2023/03/13 21:12:02 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
// #include <algorithm>
// #include <vector>
#include "../iterators/random_access_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "custom_exception.hpp"
#include "../utils/utils.hpp"
#include "../utils/type_traits.hpp"
#include <cstddef>
#include <stdexcept>

using namespace std;

// typedef = alias = another name
namespace ft
{
	// The argument in the template brackets is the type (the class) of the allocator. The argument to the constructor is an instance of that type.
	template <typename T, typename Alloc = std::allocator<T> > // std::allocator is a class template in the C++ Standard Library that provides a uniform interface for allocating and deallocating memory. It is typically used as a template argument for container classes such as std::vector and std::list, which use it to manage the memory for the elements stored in the container.
	struct vector											  // std::vector class template in the C++ Standard Library, which is a dynamic array that stores elements in contiguous memory and provides member functions to access and manipulate the elements of the container.
	{
		// Member types
		typedef T value_type;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef ft::random_access_iterator<value_type> iterator;
		typedef ft::random_access_iterator<const value_type> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		// Member functions
		// constructors, copy constructors, assignment operator and destructor
		// = allocator_type() just tells the compiler that it is an optional argument. If the user don't provide any other allocator_type object to the constructor of the vector, the default constructor of the Allocator/allocator_type will be used to create an object to be passed there instead.
		// The prototype explicit vector(const allocator_type &alloc = allocator_type()) specifies that the default constructor takes an optional argument alloc of type allocator_type, which is the allocator type used to manage the memory for the elements of the container. If no argument is provided, the default allocator is used. The explicit keyword specifies that the constructor can only be called with an explicit constructor call and cannot be used for implicit type conversions.
		// !!! (1) default constructor
		explicit vector(const allocator_type &alloc = allocator_type()) : _data(NULL), _size(0), _capacity(0), _alloc(alloc) {}
		// !!! (2) fill size constructor
		explicit vector(size_type size, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _size(size), _capacity(size), _alloc(alloc)
		{
			if (_size >= max_size())
				throw std::length_error("Error : size requested is greater than the maximum size of the container");
			_data = _alloc.allocate(size); // reserve slots in memory
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(_data + i, val); // initialize the slots
		}
		// !!!!!!!!! (3) range constructor - !!! std::enable_if and std::is_integral
		template <typename InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type _ = InputIterator()) : _alloc(alloc)
		{
			(void)_;
			_size = _capacity = ft::distance(first, last); // return the size of the range of elements, from first element to last element
			_data = _alloc.allocate(_size);
			for (size_type i = 0; i < _size; ++i, ++first)
				_alloc.construct(_data + i, *first); // initialize the slots
		}
		// !! (4) copy constructor - get called when the object and elements are not initilizaed
		vector(const vector &x) : _size(x._size), _capacity(x._capacity), _alloc(x._alloc)
		{
			_data = _alloc.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(_data + i, *(x._data + i));
		}

		// !! assignment operator - get called when the obj and elements are initialiazed
		vector &operator=(const vector &x)
		{
			if (this == &x)
				return *this;
			if (_size != 0)
				clear(); // destroy the previous elements
			if (_data)
				_alloc.deallocate(_data, _capacity);
			_alloc = x._alloc;
			_capacity = x._capacity;
			_size = x._size;
			_data = _alloc.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(_data + i, *(x._data + i));

			return *this;
		}

		// !!  destructor
		~vector()
		{
			if (_size != 0)
				clear();
			if (_data)
				_alloc.deallocate(_data, _capacity); // free the reserved slots in memory
			_capacity = 0;
		}

		// Iterators
		// when you return an iterator from the begin function, it returns an instance of the iterator class. it call the class constructor and initliaze the ptr variable by the _data
		// The returned iterator is stored in the variable it, which is an instance of the iterator class.
		iterator begin() { return iterator(_data); }				   // calls the RandomAccessIterator = iterator constructor as return value and init the ptr | An iterator to the beginning of the sequence container.
		const_iterator begin() const { return const_iterator(_data); } // If the vector object is const-qualified, the function returns a const_iterator. Otherwise, it returns an iterator.
		iterator end() { return iterator(_data + _size); }			   // returns an iterator referring to the past-the-end element in the vector container.
		const_iterator end() const { return const_iterator(_data + _size); }

		reverse_iterator rbegin() { return reverse_iterator(end()); }
		const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
		reverse_iterator rend() { return reverse_iterator(begin()); }
		const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }
		// Capacity

		// Returns the number of elements in the vector.
		size_type size() const { return _size; }
		// returns the maximum number of elements that the std::vector container can hold, not the maximum size of the underlying dynamic array.
		size_type max_size() const { return _alloc.max_size(); } // or SIZE_MAX / sizeof(T); !! MAX_SIZE is the max value of the type size_t same as INT_MAX of size_type,

		// !!! Resizes the container so that it contains n elements.
		void resize(size_type new_size, value_type val = value_type())
		{
			if (new_size >= max_size())
				throw std::length_error("Error: new size requested exceeded maximum vector size");
			if (new_size < _size)
			{ // remove and destroy the elements beyond the n
				for (size_type i = new_size; i < _size; i++)
					_alloc.destroy(_data + i);
			}
			else if (new_size > _size)
			{
				if (new_size > _capacity)
				{
					size_type _new_capacity = (new_size < 2 * _capacity) ? (2 * _capacity) : new_size;
					reserve(_new_capacity);
					_capacity = _new_capacity;
				}
				size_type n = new_size - _size;
				insert(_data + _size, n, val); // insert after _siz
			}
			_size = new_size;
		}

		// // Return size of allocated storage capacity
		size_type capacity() const { return _capacity; }

		bool empty() const { return (_size == 0); } // Test whether vector is empty

		void reserve(size_type new_capacity)
		{
			if (new_capacity >= max_size()) // If the size requested is greater than the maximum size (vector::max_size), a length_error exception is thrown.
				throw std::length_error("Error : size requested is greater than the maximum size of the container");
			if (new_capacity < _capacity)
				return;

			pointer _new_data = _alloc.allocate(new_capacity);

			for (size_type i = 0; i < _size; i++)
				_alloc.construct(_new_data + i, *(_data + i));

			if (_data)
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_data + i);

			if (_data)
				_alloc.deallocate(_data, _capacity);
			// The delete operator deallocates memory and calls the destructor for a single object created with new.
			// The delete [] operator deallocates memory and calls destructors for an array of objects created with new [].
			_data = _new_data;
			_capacity = new_capacity;
		} // Requests that the vector capacity be at least enough to contain n elements.

		// !!!!!! Element access

		reference operator[](size_type index)
		{
			if (index > size())
				throw ft::exceeded_container_limits_custom_exception();
			return _data[index];
		}

		const_reference operator[](size_type index) const
		{
			if (index > size())
				throw ft::exceeded_container_limits_custom_exception();
			return _data[index];
		}

		reference at(size_type index)
		{
			if (index >= size())
				throw std::out_of_range("Error : index requested larger than the container(elements) size (occupied slots)");
			return _data[index];
		}

		const_reference at(size_type index) const
		{
			if (index >= size())
				throw std::out_of_range("Error : index requested larger than the container(elements) size (occupied slots)");
			return _data[index];
		}

		reference front() { return (*begin()); } // Access first element

		const_reference front() const { return *(begin()); }

		reference back() { return *(end() - 1); }

		const_reference back() const { return *(end() - 1); }

		// !!! Modifiers
		// range of iterators
		template <typename InputIterator>
		void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
		{
			// if (std::is_same<Iterator1, Iterator2>::value == std::input_iterator_tag)
			// 	cout << "True\n";

			// if (std::is_same<typename std::iterator_traits<InputIterator>::iterator_category, std::input_iterator_tag>::value)
			// {
			// 	cout << "True\n";
			// }
			size_t distance = ft::distance(first, last);
			clear();
			if (distance > _capacity)
			{
				if (_data)
					_alloc.deallocate(_data, _capacity);
				_capacity = distance;
				_data = _alloc.allocate(_capacity);
			}
			_size = distance;
			for (size_type i = 0; i < _size; i++, ++first)
				_alloc.construct(_data + i, *first);
		}
		// fill
		void assign(size_type n, const value_type &val)
		{
			clear();
			if (_data)
				_alloc.deallocate(_data, _capacity);

			if (n > _capacity)
				_capacity = n;

			_size = n;
			_data = _alloc.allocate(_capacity);
			if (_data)
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(_data + i, val);
		}

		void push_back(const value_type &val)
		{
			if (_size == _capacity)
				reserve(2 * _capacity);
			insert(end(), val);
		}

		void pop_back() { erase(end() - 1); }

		iterator insert(iterator position, const value_type &val)
		{
			size_type _new_capacity = _capacity;
			if (_size == _capacity)
				_new_capacity = (_capacity == 0) ? 1 : (2 * _capacity);

			pointer _new_data = _alloc.allocate(_new_capacity);

			// copy from begin to position
			size_type i = 0;
			for (iterator it = begin(); it != position; ++it, i++)
				_alloc.construct(_new_data + i, *(_data + i));

			// insert the single element
			_alloc.construct(_new_data + i, val);
			i++;

			// le rest
			for (iterator it = position; it != end(); ++it, i++)
				_alloc.construct(_new_data + i, *(_data + i - 1));

			size_t dist_from_begin_to_position = ft::distance(begin(), position);

			// destroy the old _data
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(_data + i);
			if (_data)
				_alloc.deallocate(_data, _capacity);

			_data = _new_data;
			_capacity = _new_capacity;
			_size++;

			return iterator(_data + dist_from_begin_to_position); // the inserted element
		}

		void insert(iterator position, size_type n, const value_type &val)
		{
			if (n == 0)
				return;
			if (n >= max_size())
				throw std::length_error("Error : size requested is greater than the maximum size of the container");

			size_type _new_capacity = _capacity;
			if (n + _size > _capacity)
				_new_capacity = (n + _size < 2 * _capacity) ? (2 * _capacity) : (n + _size);

			pointer _new_data = _alloc.allocate(_new_capacity);

			// copy from begin to position
			size_type i = 0;
			for (iterator it = begin(); it != position; ++it, i++)
				_alloc.construct(_new_data + i, *(_data + i));

			// insert the n  elements
			for (size_type m = n; m > 0; i++, m--)
				_alloc.construct(_new_data + i, val);

			// le rest
			for (iterator it = position; it != end(); ++it, i++)
				_alloc.construct(_new_data + i, *(_data + i - n));

			// destroy the old _data
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(_data + i);
			if (_data)
				_alloc.deallocate(_data, _capacity);

			_data = _new_data;
			_capacity = _new_capacity;
			_size += n;
		}

		template <typename InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
		{
			size_t n = ft::distance(first, last);
			if (n == 0)
				return;
			size_type _new_capacity = _capacity;
			if (n + _size > _capacity)
				_new_capacity = (n + _size < 2 * _capacity) ? (2 * _capacity) : (n + _size);

			pointer _new_data = _alloc.allocate(_new_capacity);

			// copy from begin to position
			size_type i = 0;
			for (iterator it = begin(); it != position; ++it, i++)
				_alloc.construct(_new_data + i, *(_data + i));

			// insert the range itrs elements
			for (; first != last; ++i, ++first)
				_alloc.construct(_new_data + i, *first);

			// le rest
			for (iterator it = position; it != end(); ++it, i++)
				_alloc.construct(_new_data + i, *(_data + i - n));

			// destroy the old _data
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(_data + i);
			if (_data)
				_alloc.deallocate(_data, _capacity);

			_data = _new_data;
			_capacity = _new_capacity;
			_size += n;
		}

		iterator erase(iterator position) { return erase(position, position + 1); } // last is not included in erasing

		iterator erase(iterator first, iterator last)
		{
			if (first == last)
				return last;

			for (iterator tmp_first = first; tmp_first != last; ++tmp_first)
				_alloc.destroy(&(*tmp_first));

			size_type first_index = ft::distance(begin(), first);

			for (iterator tmp_last = last; tmp_last != end(); ++tmp_last, ++first_index)
			{
				_alloc.construct(_data + first_index, *tmp_last); // construct works only on uninitialized area
				_alloc.destroy(&(*tmp_last));					  // destroy works only on initialized area
			}

			_size -= ft::distance(first, last); // distance between last and first
			return first;
		}

		void swap(vector &x)
		{
			ft::swap(x._data, _data);
			ft::swap(x._size, _size);
			ft::swap(x._capacity, _capacity);
		}

		void clear()
		{
			if (_size == 0)
				return;
			erase(begin(), end());
			_size = 0;
		}

		allocator_type get_allocator() const { return _alloc; } // Returns a copy of the allocator object associated with the vector.

	private:
		pointer _data;	 //  pointer to the start of the array
		size_type _size; // occupied slots |  number of elements in the storage or container (collection) // size() return _size
		// returns the number of elements currently stored
		size_type _capacity;   // free slots |  number of  (free + occupied) slots in the storage, allocated storage
		allocator_type _alloc; // allocator used to manage the memory for the elements
	};

	// Non-member function overloads - Relational Operators

	template <typename T, typename Alloc>
	bool operator==(const vector<T, Alloc> &left, const vector<T, Alloc> &right)
	{
		if (left.size() != right.size())
			return false;
		if (!ft::equal(left.begin(), left.end(), right.begin()))
			return false;
		return true;
	}

	template <typename T, typename Alloc>
	bool operator!=(const vector<T, Alloc> &left, const vector<T, Alloc> &right)
	{
		return !(left == right);
	}

	template <typename T, typename Alloc>
	bool operator<(const vector<T, Alloc> &left, const vector<T, Alloc> &right)
	{
		return ft::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
	}

	template <typename T, typename Alloc>
	bool operator<=(const vector<T, Alloc> &left, const vector<T, Alloc> &right)
	{
		return !(right < left);
	}

	template <typename T, typename Alloc>
	bool operator>(const vector<T, Alloc> &left, const vector<T, Alloc> &right)
	{
		return right < left;
	}

	template <typename T, typename Alloc>
	bool operator>=(const vector<T, Alloc> &left, const vector<T, Alloc> &right)
	{
		return !(left < right);
	}

	template <class T, class Alloc>
	void swap(vector<T, Alloc> &x, vector<T, Alloc> &y) { x.swap(y); }

}
