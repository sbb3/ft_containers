/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:21:48 by adouib            #+#    #+#             */
/*   Updated: 2023/03/13 19:30:47 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

namespace ft
{
	template <typename Iterator>
	struct reverse_iterator
	{
		typedef Iterator iterator_type;
		typedef typename iterator_traits<Iterator>::value_type value_type;
		typedef typename iterator_traits<Iterator>::difference_type difference_type;
		typedef typename iterator_traits<Iterator>::pointer pointer;
		typedef typename iterator_traits<Iterator>::reference reference;
		typedef typename iterator_traits<Iterator>::iterator_category iterator_category;

		reverse_iterator() : _current() {}
		// "explicit" keyword is used to prevent unwanted implicit conversion like copy initialization, but still allow direct initialization.
		reverse_iterator(iterator_type it) : _current(it) {} // only direct init, not copy init or assignment init

		template <typename Iter>
		reverse_iterator(const reverse_iterator<Iter> &other) : _current(other.base()) { }

		reverse_iterator(const reverse_iterator &other) : _current(other.base()) { }

		reverse_iterator &operator=(const reverse_iterator &other)
		{
			if (*this != other)
				_current = other.base();
			return *this;
		}
		~reverse_iterator() {}

		iterator_type base() const { return _current; }
		reference operator*() const { return *(_current - 1); }
		reverse_iterator operator+(difference_type n) const { return reverse_iterator(_current - n); }
		// pre-increment
		reverse_iterator &operator++()
		{
			--_current;
			return *this;
		}
		// post-increment
		reverse_iterator operator++(int)
		{
			reverse_iterator copy = *this;
			--_current;
			return copy;
		}
		reverse_iterator &operator+=(difference_type n)
		{
			_current -= n;
			return *this;
		}
		reverse_iterator operator-(difference_type n) const { return reverse_iterator(_current + n); }
		reverse_iterator &operator--()
		{
			++_current;
			return *this;
		}
		reverse_iterator operator--(int)
		{
			reverse_iterator copy(*this);
			++_current;
			return copy;
		}
		reverse_iterator &operator-=(difference_type n)
		{
			_current += n;
			return *this;
		}

		pointer operator->() const { return &(operator*()); }

		reference operator[](difference_type n) const { return *(_current - n - 1); }

	private:
		iterator_type _current;
	};

	template <typename Iterator1, typename Iterator2> // Iterator1 const vs Iterator2 non-const
	bool operator==(const reverse_iterator<Iterator1> &left, const reverse_iterator<Iterator2> &right) { return left.base() == right.base(); }

	template <typename Iterator1, typename Iterator2>
	bool operator!=(const reverse_iterator<Iterator1> &left, const reverse_iterator<Iterator2> &right) { return left.base() != right.base(); }

	template <typename Iterator1, typename Iterator2>
	bool operator<(const reverse_iterator<Iterator1> &left, const reverse_iterator<Iterator2> &right) { return left.base() > right.base(); }

	template <typename Iterator1, typename Iterator2>
	bool operator<=(const reverse_iterator<Iterator1> &left, const reverse_iterator<Iterator2> &right) { return left.base() >= right.base(); }

	template <typename Iterator1, typename Iterator2>
	bool operator>(const reverse_iterator<Iterator1> &left, const reverse_iterator<Iterator2> &right) { return left.base() < right.base(); }

	template <typename Iterator1, typename Iterator2>
	bool operator>=(const reverse_iterator<Iterator1> &left, const reverse_iterator<Iterator2> &right) { return left.base() <= right.base(); }

	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it) { return ft::reverse_iterator<Iterator>(rev_it.base() - n); }

	template <typename Iterator>
	reverse_iterator<Iterator> operator-(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it) { return ft::reverse_iterator<Iterator>(rev_it.base() + n); }

	template <typename Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator> &left, const reverse_iterator<Iterator> &right) { return right.base() - left.base(); }  // get_the_value_address(value_that_object_points_to)

} // namespace ft
