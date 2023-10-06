/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:36:17 by adouib            #+#    #+#             */
/*   Updated: 2023/03/13 14:12:08 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <iterator>
#include <algorithm>

#include <iostream>
using namespace std;
template<typename T>
void	print_vector(T &v) // will call the copy ctor and when it goes out of function scope, will destroy the object along with its data, its data already point to what the other object point to
{
	std::cout << "[--->  ";
	for (int i = 0; i < v.size(); i++)
		std::cout << v[i] << ' ';
	std::cout << " <---]" << '\n';

}

template<typename T, typename U>
bool cb(T x, U y)
{
	return x == y;
}

bool cb1(int x, int y)
{
	return x == y;
}

bool comp(int x, int y)
{
	return x < y;
}

// -N2ft22random_access_iteratorINSt3__112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEEE

// template<>
// void print_vector<int *>(int *v) // will call the copy ctor and when it goes out of function scope, will destroy the object along with its data, its data already point to what the other object point to
// {
// 	std::cout << "[--->  ";
// 	for (int i = 0; i < 5; i++)
// 		std::cout << v[i] << ' ';
// 	std::cout << " <---]" << '\n';

// }
template <typename T>
ptrdiff_t distance(T first, T last)
{
	return last - first;
}
int main()
{
	cout << boolalpha;

	// {
	// 	std::vector<int> v;
	// 	cout << v.at(0) << '\n';
	// }
	// // !! range ctor
	// {
	// 	int arr[] = {42, 43, 44, 45, 46};
	// 	ft::vector<int> v(std::begin(arr), std::end(arr));
	// 	print_vector(v);

	// }
	// !! fill ctor
	// {
	// 	int arr[] = {42, 43, 44, 45, 46};
	// 	ft::vector<int> v;
	// 	// print_vector(v);

	// }
	{
		int arr[] = {3, 4, 5, 6, 9};
		// ft::vector<int> v;
		// ft::vector<int> v(3, 103);
		// ft::vector<int> v2(arr, arr + 5);
		ft::vector<int> v2(std::begin(arr), std::end(arr));
		ft::vector<int>::iterator it = v2.begin();
		// ft::vector<int> v(3, 103, std::allocator<int>());
		for (int i = 0; i < v2.size(); i++)
			std::cout << v2[i] << '\n';



		std::cout << "vec size: " << v2.size() << '\n';
		std::cout << "vec capacity: " << v2.capacity() << '\n';
		std::cout << "is empty: " << v2.empty() << '\n';
	}


	{
		// int arr[] = {3, 4, 5, 6, 9};
		// ft::vector<int> v(arr, arr + 5);
		// try
		// {
		// 	v.reserve(-12);
		// }
		// catch(const std::exception& e)
		// {
		// 	std::cerr << e.what() << '\n';
		// }

		// for (int i = 0; i < v.size(); i++)
		// 	std::cout << v[i] << '\n';
		// std::cout << "old size "<< v.size()<< '\n';
		// std::cout << "old capacity "<< v.capacity()<< '\n';

		// v.reserve(10);
		// for (int i = 0; i < v.size(); i++)
		// 	std::cout << v[i] << '\n';
		// std::cout << "new size "<< v.size()<< '\n';
		// std::cout << "new capacity "<< v.capacity()<< '\n';


		// std::cout << "front "<< v.front()<< '\n';
		// std::cout << "back "<< v.back()<< '\n';

	}
	// !!! swap
	// {
	// 	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	// 	int arr2[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 103};
	// 	ft::vector<int> v(std::begin(arr), std::end(arr));
	// 	ft::vector<int> v2(std::begin(arr2), std::end(arr2));


	// 	std::cout << "BEFORE : " << '\n';

	// 	std::cout << "size : "<<  v.size() << '\n';
	// 	std::cout <<  "capacity : "<< v.capacity() << '\n';
	// 	std::cout << "v2 size : "<<  v2.size() << '\n';
	// 	std::cout <<  "v2 capacity : "<< v2.capacity() << '\n';

	// 	print_vector(v);
	// 	print_vector(v2);

    //     v.resize(0);

	// 	v.swap(v2);

	// 	std::cout << "AFTER : " << '\n';

	// 	std::cout << "size : "<<  v.size() << '\n';
	// 	std::cout <<  "capacity : "<< v.capacity() << '\n';
	// 	std::cout << "v2 size : "<<  v2.size() << '\n';
	// 	std::cout <<  "v2 capacity : "<< v2.capacity() << '\n';
	// 	print_vector(v);
	// 	print_vector(v2);

	// }

	// !!!! erase
	{
		// 	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

		// std::vector<int> v(std::begin(arr), std::end(arr));
		// v.reserve(30);
		// // std::vector<int> v(std::begin(arr), std::end(arr));
		// print_vector(v);
		// // std::vector<int>::iterator it = v.begin() + 2;
		// std::vector<int>::iterator first = v.begin();
		// std::vector<int>::iterator last = v.end();
		// // ++it2;
		// // std::cout << "it : "<< *it2 << '\n';
		// std::cout << "size bef : "<< v.size() << '\n';
		// std::vector<int>::iterator it = v.erase(v.begin() + 5); // last is not included in the deleting
		// // std::vector<int>::iterator it = v.erase(v.begin() + 2, v.begin() + 5); // last is not included in the deleting
		// // std::vector<int>::iterator it = v.erase(v.begin(), v.begin() + 3); // 3 elements
		// std::cout << "size afte : "<< v.size() << '\n';
		// // std::cout << "ret : "<< *it << '\n';
		// // std::cout << "last - first : " << last - first << '\n';
		// // ptrdiff_t diff = last - first;
		// // std::cout << "ptrdiff : "<< diff << '\n';

		// print_vector(v);

	}

	// !!!! insert by position
	// {
	// 		int arr[] = {100, 200, 300};

	// 	// ft::vector<int> v(std::begin(arr), std::end(arr));
	// 	ft::vector<int> v;
	// 	// v.reserve(30);

	// 	std::cout << "size : "<<  v.size() << '\n';
	// 	std::cout <<  "capacity : "<< v.capacity() << '\n';

	// 	print_vector(v);

	// 	// std::cout <<  " address : "<< &(*(v.begin()))  << '\n';

	// 	// std::cout <<  " begin : "<< *(v.begin())  << '\n';
	// 	// std::cout << std::boolalpha <<  " empty : "<< v.empty()  << '\n';


	// 	ft::vector<int>::iterator it = v.insert ( v.begin() , 104 ); // 200 100 100 100
	//     it = v.insert(v.end(), 103);
    //     it = v.insert(v.begin(), 102);

	// 	// std::cout <<  " address : "<< &(*(v.begin()))  << '\n';

	// 	std::cout << "inserted element : "<< *it << '\n';

	// 	std::cout << "new size : "<<  v.size() << '\n';
	// 	std::cout <<  "new capacity : "<< v.capacity() << '\n';

	// 	print_vector(v);

	// }


	// // !!!! insert by n and val
	// {
	// 		int arr[] = {100, 200, 300};

	// 	ft::vector<int> v(std::begin(arr), std::end(arr));
	// 	// v.reserve(30);

	// 	std::cout << "size : "<<  v.size() << '\n';
	// 	std::cout <<  "capacity : "<< v.capacity() << '\n';

	// 	print_vector(v);

	// 	// std::cout <<  " address : "<< &(*(v.begin()))  << '\n';


	// 	// v.insert ( v.begin(), 2, 103 ); // 200 100 100 100
	// 	 v.insert(v.begin(), v.max_size(), 104);

	// 	// std::cout <<  " address : "<< &(*(v.begin()))  << '\n';

	// 	std::cout << "new size : "<<  v.size() << '\n';
	// 	std::cout <<  "new capacity : "<< v.capacity() << '\n';

	// 	print_vector(v);

	// }

	// !!!! insert by range of iterators
	// {
	// 		int arr[] = {100, 200, 300, 400};
	// 		int arr2[] = {42, 43, 44, 45, 46, 47};

	// 	ft::vector<int> v(std::begin(arr), std::end(arr));
	// 	// ft::vector<int> v2(6, 8);
	// 	// v.reserve(30	);

	// 	std::cout << "size : "<<  v.size() << '\n';
	// 	std::cout <<  "capacity : "<< v.capacity() << '\n';

	// 	print_vector(v);

	// 	// std::cout <<  " address : "<< &(*(v.begin()))  << '\n';

	// 	// ft::RandomAccessIterator<int> it(arr);
	// 	v.insert ( v.begin() + 1, std::begin(arr2), std::end(arr2)); // 200 100 100 100

	// 	// std::cout <<  " address : "<< &(*(v.begin()))  << '\n';

	// 	std::cout << "new size : "<<  v.size() << '\n';
	// 	std::cout <<  "new capacity : "<< v.capacity() << '\n';

	// 	print_vector(v);

	// }

	// !!! assign by fill

	// {
	// 		int arr[] = {100, 200, 300, 400};
	// 		int arr2[] = {42, 43, 44, 45, 46, 47};

	// 	ft::vector<int> v(std::begin(arr), std::end(arr));
	// 	// ft::vector<int> v2(6, 8);
	// 	// v.reserve(30);

	// 	std::cout << "size : "<<  v.size() << '\n';
	// 	std::cout <<  "capacity : "<< v.capacity() << '\n';

	// 	print_vector(v);

	// 	v.assign ( 2, 104); // 200 100 100 100
	// 	// v.clear(); // 200 100 100 100

	// 	std::cout << "new size : "<<  v.size() << '\n';
	// 	std::cout <<  "new capacity : "<< v.capacity() << '\n';

	// 	print_vector(v);

	// }

		// !!! assign by range

	// {
	// 		int arr[] = {100, 200, 300, 400};
	// 		int arr2[] = {42, 43, 44, 45, 46, 47};

	// 	ft::vector<int> v(std::begin(arr), std::end(arr));
	// 	// ft::vector<int> v2(6, 8);
	// 	// v.reserve(30);

	// 	std::cout << "size : "<<  v.size() << '\n';
	// 	std::cout <<  "capacity : "<< v.capacity() << '\n';

	// 	print_vector(v);

	// 	v.assign ( arr2, arr2 + 6); // 200 100 100 100
	// 	// v.clear(); // 200 100 100 100

	// 	std::cout << "new size : "<<  v.size() << '\n';
	// 	std::cout <<  "new capacity : "<< v.capacity() << '\n';

	// 	print_vector(v);

	// }

	// !!! push_back and pop_back

	// {
	// 	int arr[] = {42, 43, 44, 45, 46, 47};

	// 	ft::vector<int> v(std::begin(arr), std::end(arr));
	// 	// ft::vector<int> v2(6, 8);
	// 	// v.reserve(30);

	// 	std::cout << "size : "<<  v.size() << '\n';
	// 	std::cout <<  "capacity : "<< v.capacity() << '\n';

	// 	print_vector(v);

	// 	// v.pop_back(); // 200 100 100 100
	// 	v.push_back(48);
	// 	v.push_back(49);
	// 	v.push_back(50);
	// 	// v.pop_back();
	// 	// v.push_back(51);
	// 	v.clear();
	// 	v.clear();

	// 	std::cout << "new size : "<<  v.size() << '\n';
	// 	std::cout <<  "new capacity : "<< v.capacity() << '\n';

	// 	print_vector(v);

	// }

	// !!! get_allocator

	// {
	// 	int arr[] = {42, 43, 44, 45, 46, 47};

	// 	std::vector<int> v;
	// 	// ft::vector<int> v2(6, 8);
	// 	// v.reserve(30);

	// 	int *p = v.get_allocator().allocate(5);
	// 	for (int i = 0; i < 5; ++i) v.get_allocator().construct(p + i, i + 1);

	// 	// std::cout << "size : "<<  v.size() << '\n';
	// 	// std::cout <<  "capacity : "<< v.capacity() << '\n';
	// 	print_vector(p);

	// 	for(int i = 0; i < 5; ++i) v.get_allocator().destroy(p + i);
	// 	v.get_allocator().deallocate(p, 5);

	// 	// std::cout << "new size : "<<  v.size() << '\n';
	// 	// std::cout <<  "new capacity : "<< v.capacity() << '\n';
	// 	print_vector(p);


	// }

	// !!! copy ctor and assignement op

	// {
	// 	int arr[] = {42, 43, 44, 45, 46, 47};

	// 	ft::vector<int> v(std::begin(arr), std::end(arr));
	// 	{
	// 		ft::vector<int> v2(v);

	// 		std::cout << " size : "<<  v2.size() << '\n';
	// 		std::cout <<  " capacity : "<< v2.capacity() << '\n';

	// 		print_vector(v2);
	// 	}
	// 	// print_vector(v2);

	// }

	// / construct using  fill constructor
	// equal
	// {
	// 	int arr[] = {102, 103, 104};
	// 	int arr2[] = {102, 103, 104};
	// 	// int arr2[] = {202, 203, 204};
	// 	ft::vector<int> v1(std::begin(arr), std::end(arr));
	// 	ft::vector<int> v2(std::begin(arr2), std::end(arr2));


	// 	std::cout << std::boolalpha ;

	// 	// bool isEqual = std::equal(v1.begin(), v1.end(), v2.begin());
	// 	// std::cout << isEqual << '\n';
	// 	// v2[0] = 202;
	// 	// isEqual = std::equal(v1.begin(), v1.end(), v2.begin());
	// 	// std::cout << isEqual << '\n';
	// 	// v2[0] = 102;
	// 	// isEqual = std::equal(v1.begin(), v1.end(), v2.begin(), cb1);
	// 	// std::cout << isEqual << '\n';


	// 	// print_vector(v1);
	// 	// print_vector(v2);
	// 	std::cout << (v1 != v2) << '\n';

	// }

	// lexicographical_compare
	// {
	// 	int arr[] = {102};
	// 	int arr2[] = {102, 103};
	// 	// int arr2[] = {202, 203, 204};
	// 	ft::vector<int> v1(std::begin(arr), std::end(arr));
	// 	ft::vector<int> v2(std::begin(arr2), std::end(arr2));


	// 	std::cout << std::boolalpha ;

	// 	bool isLess = ft::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());
	// 	bool isLess2 = ft::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), comp);

	// 	std::cout << isLess << '\n';
	// 	std::cout << isLess2 << '\n';

	// 	// std::cout << (v1 < v2) << '\n';
	// 	std::cout << "vals " << ( 5 < 5) << '\n';

	// }

	// reverse iterator
	// {
	// 	int arr[] = {102, 103, 104, 105, 106, 107, 108, 109};
	// // 	int arr2[] = {102, 103, 104};
	// // 	// int arr2[] = {202, 203, 204};
	// 	ft::vector<int> v1(std::begin(arr), std::end(arr));
	// 	std::vector<int> v2(std::begin(arr), std::end(arr));
	// 	std::vector<int> v3;
	// 	const std::vector<int> v3_const(std::begin(arr), std::end(arr));
	// 	// std::vector<int>::reverse_iterator rbit = v1.rbegin();
	// 	// std::vector<int>::reverse_iterator reit = v1.rend();

	// 	ft::vector<int>::reverse_iterator rt1_b = v1.rbegin();
	// 	ft::vector<int>::reverse_iterator rt1 = v1.rend();
	// 	std::vector<int>::reverse_iterator rt2_b = v2.rbegin();
	// 	std::vector<int>::reverse_iterator rt2 = v2.rend();
	// 	std::vector<int>::const_reverse_iterator crt2 = v2.rend();


	// 	// ft::vector<int>::const_reverse_iterator crit = v1.rbegin();

	// 	std::cout << std::boolalpha << '\n';

	// 	// std::cout << "it " << *(v1.begin() ) << '\n';
	// 	// std::cout << "rbit " << *rbit << '\n';
	// 	// std::cout << "reit " << *(reit) << '\n';
	// 	// std::cout << "reit - 1 : " << *(reit - 1) << '\n';
	// 	// std::cout << "base : " << (rt.base()) << '\n';

	// 	// if (rt1 == rt1_b)
	// 	// 	std::cout << "ft rt1 : " << "terue" << '\n';
	// 	std::cout << "std rt2 : " << (rt2 > rt2_b) << '\n';
	// 	std::cout << "*v2.rbegin() : " << *(v2.rbegin() + 25) << '\n';



	// 	// rt1 = rt1 - 1;
	// 	// rt1 = rt1 + 1;
	// 	rt1--;
	// 	--rt1;
	// 	rt1++;
	// 	++rt1;

	// 	std::cout << "rt1 : " << *(rt1) << '\n';
	// 	std::cout << "rt1 - rt1_b : " << (rt1 - rt1_b) << '\n';

	// 	// rt2 = rt2 - 1;
	// 	// rt2 = rt2 + 1;
	// 	rt2--;
	// 	--rt2;
	// 	rt2++;
	// 	++rt2;
	// 	std::cout << "rt2 : " << *(rt2) << '\n';

	// 	std::cout << "v1 rbegin : " << *(v1.rbegin()) << '\n';
	// 	std::cout << "v2 rbegin : " << *(v2.rbegin()) << '\n';

	// 	std::cout << "rt1 != rt1_b : " << (rt1 != rt1_b) << '\n';

	// 	std::cout << "v3_const.rbegin() == v3_const.rend() : " << (v3_const.rbegin() == v3_const.rend()) << '\n';
	// 	std::cout << "v3_const.rbegin() != v3_const.rend() : " << (v3_const.rbegin() != v3_const.rend()) << '\n';



	// }

	// construct using a range of iterators
	// {
	// 	int arr[] = {1, 2, 3, 4};
	// 	std::vector<int> v(std::begin(arr), std::end(arr));
	// 	print_vector(v);
	// 	// ft::vector<int>::iterator it = v.begin();
	// }
	// !! iterator
	// {
	// 	int arr[] = {1, 2, 3, 4, 5};
	// 	ft::vector<int> v(std::begin(arr), std::end(arr));
	// 	ft::vector<int>::iterator bit = v.begin();
	// 	ft::vector<int>::iterator eit = v.end();

	// 	// std::vector<int> v(std::begin(arr), std::end(arr));
	// 	// std::vector<int>::iterator bit = v.begin();
	// 	// std::vector<int>::iterator eit = v.end();
	// 	// bit++;
	// 	// bit++;
	// 	// bit--;
	// 	// !!!!!!! calling the assignement ctor bit = bit + 2;

	// 	std::cout << " ---- " << '\n';
	// 	std::cout << " bit : "<< *bit  << '\n';
	// 	std::cout << " bit : "<< *(bit++) << '\n';
	// 	std::cout << " bit : "<< *(bit) << '\n';
	// 	// std::cout << " eit : "<< *(eit -1) << '\n';
	// 	// std::cout << " bit : "<< (bit < eit) << '\n';
	// 	// std::cout << " bit : "<< (bit > eit) << '\n';
	// 	// std::cout << " bit : "<< (bit >= eit) << '\n';
	// 	// std::cout << " bit : "<< (bit <= eit) << '\n';
	// 	// std::cout << " bit : "<< (bit == eit) << '\n';
	// 	// std::cout << " bit : "<< (bit != eit) << '\n';

	// 	// std::cout << " ---- " << '\n';
	// 	// std::cout << " access using dereferencing : " << '\n';
	// 	// for (; bit != eit; bit++)
	// 	// 	std::cout << " val : "<< *bit << '\n';

	// 	// std::cout << " ---- " << '\n';
	// 	// std::cout << " access using index : " << '\n';
	// 	// for (int i = 0; i < v.size(); i++)
	// 	// 	std::cout << " val : "<< bit[i] << '\n';

	// 	std::cout << " ---- " << '\n';


	// 	std::cout << " ---- " << '\n';


	// 	std::cout << " ---- " << '\n';
	// }

}
