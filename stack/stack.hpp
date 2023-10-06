/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:36:23 by adouib            #+#    #+#             */
/*   Updated: 2022/12/12 13:47:23 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../vector/vector.hpp"

namespace ft
{

	template <typename T, typename Container = ft::vector<T>>
	struct stack
	{
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		/*
		vector default ctor
		vector copy ctor
		stack ctor
		vector dctor
		stack dctor
		vector dctor
		*/
		explicit stack(const container_type &c = container_type()) : _c(c) { }
		stack(const stack &other) : _c(other._c) { }
		stack &operator=(const stack &other)
		{
			if (this != &other)
				_c = other._c;
			return *this;
		}
		~stack() { } // stack obj will be desructed then _c vector obj lastone will be destructed
		bool empty() const { return _c.empty(); }
		size_type size() const { return _c.size(); }
		reference top() { return _c.back(); }
		const_reference top() const { return _c.back(); }
		void push(const value_type &val) { _c.push_back(val); }
		void pop() { _c.pop_back(); }

		const container_type &base() const { return _c; }

	protected:
		container_type _c;
	};

	template <typename T, typename Container>
	bool operator==(const stack<T, Container> &left, const stack<T, Container> &right) { return left.base() == right.base(); }
	template <typename T, typename Container>
	bool operator!=(const stack<T, Container> &left, const stack<T, Container> &right) { return left.base() != right.base(); }
	template <typename T, typename Container>
	bool operator<(const stack<T, Container> &left, const stack<T, Container> &right) { return left.base() < right.base(); }
	template <typename T, typename Container>
	bool operator<=(const stack<T, Container> &left, const stack<T, Container> &right) { return left.base() <= right.base(); }
	template <typename T, typename Container>
	bool operator>(const stack<T, Container> &left, const stack<T, Container> &right) { return left.base() > right.base(); }
	template <typename T, typename Container>
	bool operator>=(const stack<T, Container> &left, const stack<T, Container> &right) { return left.base() >= right.base(); }

}
