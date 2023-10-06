/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otherTests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:36:17 by adouib            #+#    #+#             */
/*   Updated: 2022/12/02 23:36:18 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"
#include <stack>

template<typename T>
void show_then_delete_elements(T &st)
{
	std::cout << "size before : " << st.size() <<'\n';

	while (!st.empty())
	{
		std::cout <<  st.top() <<'\n';
		st.pop();
	}
	std::cout << "size after : " << st.size() <<'\n';
}

int main(int argc, char const *argv[])
{
	ft::stack<int> st;

	st.push(1);
	st.push(2);
	st.push(3);

    const ft::stack<int> st1(st);

	std::cout << st1.top() << '\n';

	show_then_delete_elements(st);

	st = st1;

	show_then_delete_elements(st);

	return 0;
}

