/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:36:20 by adouib            #+#    #+#             */
/*   Updated: 2023/03/13 10:54:52 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Tree.hpp"
#include "../iterators/map_iterator.hpp"
#include "../utils/utils.hpp"

#include <functional>
#include <memory>
#include <utility>

using namespace std;

namespace ft
{

	template <
		typename Key,
		typename T,
		typename Compare = std::less<Key>, // std::less is a functor, struct acts a function
		typename Alloc = std::allocator<ft::pair<const Key, T>>>
	struct map
	{
		typedef Key key_type;
		typedef T value_type;
		typedef ft::pair<const key_type, value_type> Pair;
		typedef Compare key_compare; // functor
		typedef Tree<key_type, value_type, Pair, key_compare> tree_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef typename tree_type::iterator iterator;
		typedef typename tree_type::const_iterator const_iterator;
		typedef typename tree_type::reverse_iterator reverse_iterator;
		typedef typename tree_type::const_reverse_iterator const_reverse_iterator;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;

		// Nested function class to compare elements, a functor, a struct that acts as a function;
		// value_compare a functor that use an object of key_compare (a std::less object) to compare the keys

		struct value_compare
		{
			friend class map;

			typedef bool result_type;
			typedef Pair first_argument_type;
			typedef Pair second_argument_type;

			bool operator()(const first_argument_type &duo1, const second_argument_type &duo2) const
			{
				return _comp(duo1.first, duo2.first); // similiar to (duo1.first < duo2.first)
			}

		private:
			key_compare _comp;
			value_compare(key_compare comp) : _comp(comp) {} // constructed with std::less object
		};

		// typedef Lopez<Key>::me AAA;
		// typedef Lopez<Key> AAA;
		// typedef Lopez<char>::me AAA;

		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _comp(comp), _alloc(alloc) {}

		// template <typename InputIterator>
		// map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
		// 	: _tree(first, last)
		// {
		// }

		map(const map &other) : _tree(other._tree), _comp(other._comp), _alloc(other._alloc)
		{
			// iterator it = other.begin();
			// for (iterator it = other.begin(); it != other.end(); ++it) {
				// insert(*it);
			// }
		}
		map &operator=(const map &other) { _tree = other._tree; return *this; }
		~map() {}

		// iterator begin() { return _tree.tree_begin(); }
		const_iterator begin() const { return _tree.tree_begin(); }

		// iterator end() { return _tree.tree_end(); }
		const_iterator end() const { return _tree.tree_end(); }

		// reverse_iterator rbegin() {}
		// const_reverse_iterator rbegin() const {}
		// reverse_iterator rend() {}
		// const_reverse_iterator rend() const {}

		bool empty() const { return _tree.isEmpty(); }
		size_type size() const { return _tree.getTreeSize(); }
		size_type max_size() const { return _tree.max_size(); }
		value_type &operator[](const key_type &key) { return _tree.operator[](key); }

		ft::pair<iterator, bool>
		insert(const Pair &val)
		{
			return _tree.insertByPair(val);
		}

		iterator insert(iterator position, const Pair &val)
		{
			return _tree.insertByIterPosition(position, val);
		}

		template <typename InputIterator>
		void insert(InputIterator first, InputIterator last)
		{

			for (; first != last; ++first)
			{
				_tree.insertByPair(*first);
			}
		}

		size_type erase(const key_type &key) { return _tree.eraseByKey(key); }

		void erase(iterator position)
		{
			if (position == end()) return; // nullptr
			_tree.eraseByKey(position->first);
		}

		void erase(iterator first, iterator last)
		{
			if (first == end())
				return;

			if (last == end())
				while (first != end())
					first = iterator(_tree.eraseByKeyThenReturnNextNode(first->first));
			else
			{
				key_type key = last->first; // saved the key cuz the last position could be removed in the second else of the else in removeUtil or during balancing
				while (_comp(first->first, key))
					first = iterator(_tree.eraseByKeyThenReturnNextNode(first->first));
			}
		}

		void swap(map &other) {}
		void clear() { _tree.clearTree(); }

		key_compare key_comp() const { return _comp; }
		value_compare value_comp() const { return value_compare(); }

		iterator find(const key_type &key)
		{
			return _tree.find(key);
		}

		const_iterator find(const key_type &key) const
		{
			return _tree.find(key); // this should return const iterator
		}

		size_type count(const key_type &key) const { return _tree.getTreeCount(key); }

		iterator lower_bound(const key_type &key) { return _tree.lowerBound(key);}
		const_iterator lower_bound(const key_type &key) const;
		iterator upper_bound(const key_type &key) { return _tree.upperBound(key); }
		const_iterator upper_bound(const key_type &key) const;

		ft::pair<iterator, iterator> equal_range(const key_type &key)
		{
			return ft::make_pair(lower_bound(key), upper_bound(key));
		}
		ft::pair<const_iterator, const_iterator> equal_range(const key_type &key) const;

		allocator_type get_allocator() const { return _alloc; }

		// remove these
		void viewTree() { _tree.viewTree(); }
		iterator getIterOnRoot() { return _tree.getIterOnRoot(); }

	private:
		tree_type _tree;
		key_compare _comp;
		allocator_type _alloc;
	};

	template <typename Key, typename T, typename Compare, typename Alloc>
	bool operator==(const map<Key, T, Compare, Alloc> &left, const map<Key, T, Compare, Alloc> &right)
	{
		cout << "hello\n";
		// if (left.size() != right.size())
		// 	return false;
		// if (!ft::equal(left.begin(), left.end(), right.begin()))
		// 	return false;
		return true;
	}

	// template <typename Key, typename T, typename Compare, typename Alloc>
	// bool operator!=(const map<Key, T, Compare, Alloc> &left, const map<Key, T, Compare, Alloc> &right) {}

	// template <typename Key, typename T, typename Compare, typename Alloc>
	// bool operator<(const map<Key, T, Compare, Alloc> &left, const map<Key, T, Compare, Alloc> &right) {}

	// template <typename Key, typename T, typename Compare, typename Alloc>
	// bool operator<=(const map<Key, T, Compare, Alloc> &left, const map<Key, T, Compare, Alloc> &right) {}

	// template <typename Key, typename T, typename Compare, typename Alloc>
	// bool operator>(const map<Key, T, Compare, Alloc> &left, const map<Key, T, Compare, Alloc> &right) {}

	// template <typename Key, typename T, typename Compare, typename Alloc>
	// bool operator>=(const map<Key, T, Compare, Alloc> &left, const map<Key, T, Compare, Alloc> &right) {}

	// template <typename Key, typename T, typename Compare, typename Alloc>
	// void swap(map<Key, T, Compare, Alloc> &x, map<Key, T, Compare, Alloc> &y) {}
}
