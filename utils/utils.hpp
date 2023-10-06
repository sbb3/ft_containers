/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 23:24:19 by adouib            #+#    #+#             */
/*   Updated: 2022/12/30 21:07:17 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>
#include <iostream>
#include <cstddef>

namespace ft
{
	long max(long x, long y)
	{
		return (x < y) ? y : x;
	}

	template <typename T>
	size_t distance(T first, T last)
	{
		size_t c = 0;
		for (; first != last; first++, c++)
			;
		return c;
	}

	template <typename T>
	void copy(T first, T last, T dest)
	{
		for (int i = 0; first != last; i++, first++)
			dest[i] = *first;
	}

	template <typename T>
	void swap(T &x, T &y)
	{
		T tmp;

		tmp = x;
		x = y;
		y = tmp;
	}

	template <typename InputIter1, typename InputIter2>
	bool equal(InputIter1 first1, InputIter1 last1, InputIter2 first2)
	{
		for (; first1 != last1; first1++, first2++)
			if (!(*first1 == *first2))
				return false;
		return true;
	}

	// CALLBACK FUNCTION  FOR THE EQUAL TEMPLATE FUNCTION
	// template<typename T>
	// bool pred(int x, int y)
	// {
	// 	return x == y;
	// }

	template <typename InputIter1, typename InputIter2, typename Pred>
	bool equal(InputIter1 first1, InputIter1 last1, InputIter2 first2, Pred callback)
	{
		for (; first1 != last1; first1++, first2++)
			if (!(callback(*first1, *first2)))
				return false;
		return true;
	}

	template <typename InputIter1, typename InputIter2>
	bool lexicographical_compare(InputIter1 first1, InputIter1 last1, InputIter2 first2, InputIter2 last2)
	{
		for (; first1 != last1 && first2 != last2; first1++, first2++)
		{
			if (*first1 < *first2)
				return true;
			else if (*first2 < *first1)
				return false;
		}

		// if they dont equal, see which one get exausted
		// Once one of the ranges is exhausted, the function returns true if the first range is exhausted and the second range is not, and false otherwise.
		// like (first1 - last1	).distance < (first2 - last2).distance
		return (first1 == last1) && (first2 != last2);
	}

	template <typename InputIter1, typename InputIter2, typename Compare>
	bool lexicographical_compare(InputIter1 first1, InputIter1 last1, InputIter2 first2, InputIter2 last2, Compare comp)
	{
		for (; first1 != last1 && first2 != last2; first1++, first2++)
		{
			if (comp(*first1, *first2))
				return true;
			else if (comp(*first2, *first1))
				return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	// class template
	template <typename T1, typename T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		// default ctor
		pair() : first(first_type()), second(second_type()) {}
		// copy ctor
		pair(const pair &pr) : first(pr.first), second(pr.second) {}
		//  copy ctor with different type params than the calling object
		template <typename T3, typename T4>
		pair(const pair<T3, T4> &pr) : first(pr.first), second(pr.second) {}
		// assignment ctor
		pair &operator=(const pair &pr)
		{
			if (this != &pr)
			{
				first = pr.first;
				second = pr.second;
			}
			return *this;
		}
		// init ctor
		pair(const first_type &f, const second_type &s) : first(f), second(s) {}
		// desctor
		~pair() {}

		first_type first;
		second_type second;
	};

	// function template
	template <typename T1, typename T2>
	pair<T1, T2> make_pair(T1 first, T2 second)
	{
		return pair<T1, T2>(first, second);
	}

}
