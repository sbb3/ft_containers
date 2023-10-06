/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 22:12:37 by adouib            #+#    #+#             */
/*   Updated: 2022/12/21 23:33:30 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>

namespace ft
{
	//  primary template Iterator_traits class
	// default definition hat obtains these types from the iterator type itself
	template <typename Iter>
	struct iterator_traits
	{
		typedef typename Iter::value_type value_type;
		typedef typename Iter::difference_type difference_type;
		typedef typename Iter::pointer pointer;
		typedef typename Iter::reference reference;
		typedef typename Iter::iterator_category iterator_category;
	};

	// explicit specialization for pointers
	template <typename T>
	struct iterator_traits<T *>
	{
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef value_type *pointer;
		typedef value_type &reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	// explicit specialization for pointers to const (const T*)
	template <typename T>
	struct iterator_traits<const T *>
	{
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef const value_type *pointer;
		typedef const value_type &reference;
		typedef std::random_access_iterator_tag iterator_category;
	};
}
