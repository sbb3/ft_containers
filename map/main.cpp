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


#include "map.hpp"
#include <iostream>

#include <map>
#include <functional>
#include <memory>
#include <utility>

using namespace std;

int main()
{

	// typedef ft::map<int, int> Map;
	// typedef std::map<int, int> Other;
	// // typedef ft::map<int, int, std::greater<int>> Map;
	// // typedef std::map<int, int, std::greater<int>> Other;
	// typedef std::pair<int, int> Pair;
	// {
	// 	std::map<int, int> m;

	// 	m.insert(std::pair<int, int>(1, 103));
	// 	m.insert(std::pair<int, int>(2, 104));
	// 	m.insert(std::pair<int, int>(3, 105));

	// 	std::pair<std::map<int, int>::iterator, bool> pair = m.insert(std::pair<int, int>(4, 106));

	// 	std::map<int, int>::iterator it = m.begin();

	// 	(*it).
	// 	for (; it != m.end(); it++)
	// 		std::cout << "k: " << it->first << " , v: " << it->second << '\n';

	// 	std::cout << "k: " << pair.first->first << " , v: " << pair.first->second << '\n';
	// }

	// {
	// 	Map m;
	// 	Map m2;
	// 	m.insert(Pair(2, 104));
	// 	m.insert(Pair(6, 103));
	// 	m.insert(Pair(12, 105));

	// 	// std::pair<Map::iterator, bool> pr = m.insert(Pair(4, 106));


	// 	Map::iterator it = m.begin();
	// 	Map::iterator ite = m.end();

	// 	m2.insert(it, ite);
	// 	Map::iterator itm2 = m2.begin();
	// 	Map::iterator item2 = m2.end();

	// 	// std::cout << "k: " << pr.first->first << " , v: " << pr.second << '\n';

	// 	// Map::iterator position = m.insert(it, Pair(15, 100));
	// 	// cout << position->first << ' ' << position->second << '\n';
 	// 	// it = m.begin();


	// 	for (; itm2 != item2; ++itm2)
	// 		std::cout << "k: " << itm2->first << " , v: " << itm2->second << '\n';

	// 	std::cout << "map size: " << m2.size() << '\n';
	// }

	// {
	// 	ft::pair<int, int> duo(98, 98);
	// 	cout << duo.first << ' ' << duo.second << '\n';

	// 	ft::pair<int, int> duo_copy(duo);
	// 	cout << duo_copy.first << ' ' << duo_copy.second << '\n';

	// 	ft::pair<char, char> duo_copy2(duo);
	// 	cout << duo_copy2.first << ' ' << duo_copy2.second << '\n';

	// 	ft::pair<int, int> duo_assignment(1, 1);
	// 	duo_assignment = duo;
	// 	cout << duo_assignment.first << ' ' << duo_assignment.second << '\n';

	// 	std::pair<int, int> duo2(3, 165);
	// 	cout << duo2.first << ' ' << duo2.second << '\n';

	// 	ft::pair<int, int> m_duo = ft::make_pair(21, 21);
	// 	cout << m_duo.first << ' ' << m_duo.second << '\n';

	// 	ft::pair<int, int> m_duo2 = ft::make_pair(21.37, 'A');
	// 	cout << m_duo2.first << ' ' << m_duo2.second << '\n';

	// }

	{
		// cout << boolalpha;

		// // typedef std::map<int, int> Map;
		// Map m;
		// m.insert(Pair(200, 103));

		// m.insert(Pair(100, 103));
		// m.insert(Pair(300, 103));

		// m.insert(Pair(50, 103));
		// m.insert(Pair(150, 103));
		// m.insert(Pair(250, 103));
		// m.insert(Pair(350, 103));

		// m.insert(Pair(25, 103));
		// m.insert(Pair(75, 103));
		// m.insert(Pair(125, 103));
		// m.insert(Pair(175, 103));
		// m.insert(Pair(225, 103));
		// m.insert(Pair(275, 103));
		// m.insert(Pair(325, 103));
		// m.insert(Pair(375, 103));

		// m.insert(Pair(12, 103));
		// m.insert(Pair(38, 103));
		// m.insert(Pair(65, 103));
		// m.insert(Pair(85, 103));
		// m.insert(Pair(112, 103));
		// m.insert(Pair(138, 103));
		// m.insert(Pair(165, 103));
		// m.insert(Pair(185, 103));
		// m.insert(Pair(212, 103));
		// m.insert(Pair(238, 103));
		// m.insert(Pair(265, 103));
		// m.insert(Pair(285, 103));
		// m.insert(Pair(312, 103));
		// m.insert(Pair(338, 103));
		// m.insert(Pair(365, 103));
		// m.insert(Pair(385, 103));

		// m.insert(Pair(4, 103));
		// m.insert(Pair(16, 103));
		// m.insert(Pair(30, 103));
		// m.insert(Pair(40, 103));
		// m.insert(Pair(70, 103));
		// m.insert(Pair(60, 103));
		// m.insert(Pair(80, 103));
		// m.insert(Pair(90, 103));
		// m.insert(Pair(230, 103));
		// m.insert(Pair(290, 103));
		// m.insert(Pair(330, 103));
		// m.insert(Pair(360, 103));
		// m.insert(Pair(370, 103));


		// Map::iterator ub = m.lower_bound(81);
		// // Map::iterator ub = m.lower_bound(292);
		// if (ub != m.end())
		// 		cout << ub->first << ", " << ub->second << "\n";
		// else
		// 	cout << "null\n";







		// m[3] = 105;
		// m[4] = 106;
		// std::cout << "value: " << m[4] << '\n';

		// m.clear();

		// Map::iterator pos = m.find(8);
		// Map::iterator pos = m.find(1);
		// Map::iterator pos = m.find(5);
		// Map::iterator pos = m.find(10);
		// Map::iterator pos = m.find(15);
		// Map::iterator pos = m.find(20);
		// Map::iterator pos = m.find(30);
		// Map::iterator ite = m.end();
		// m.erase(pos, ite);

		// // Map::iterator pos = m.find(1);
		// // Map::iterator ite = m.end();
		// // // m[2] = 121;
		// // if (pos != m.end())
		// // 	std::cout << "kpos: " << pos->first << " , vpos: " << pos->second << '\n';
		// // else
		// // 	cout << "element not found\n";

		// // cout << m.erase(5) << '\n';
		// // m.erase(pos);

		// // cout << "--------------\n";
		// Map::iterator  copy;
		// 	cout << "/\n";

		// // cout << "copy addr: " << &copy << ", pos addr: " <<  &pos << "\n";

		// while (pos != m.end())
		// {
		// 	Map::iterator  copy(pos);
		// 	cout << "/\n";
		// 	// cout << pos->first << "\n";
		// 	++pos;
			// m.erase(copy);
		// }
		// cout << "--------------\n";

		// 	cout << pos->first << "\n";
		// ++pos;
		// 	cout << pos->first << "\n";

		// // ++pos;
		// if ((pos) == (m.end()))
		// 	cout << "true\n";

		// for (Map::iterator it = m.begin(); it != m.end(); ++it)
		// 	std::cout << "k: " << it->first << " , v: " << it->second << '\n';

		// Map::iterator it = m.begin();
		// cout << "k: " << (*it).first << '\n';
		// ++it;
		// cout << "k: " << (*it).first << '\n';
		// ++it;
		// cout << "k: " << (*it).first << '\n';
		// ++it;
		// cout << "k: " << (*it).first << '\n';

		// for (Map::iterator itroot = m.getIterOnRoot(); itroot != m.end(); ++itroot)
		// 	cout << "k: " << (*itroot).first << '\n';


		// Map::iterator it = m.begin();
		// cout << "k: " << (*it).first << '\n';
		// ++it;
		// cout << "k: " << (*it).first << '\n';

		// m.viewTree();





	}

	{
		typedef ft::map<int, int> Map;
		typedef std::map<int, int> Other;
	typedef ft::pair<const int, int> Pair;

	// // typedef ft::map<int, int, std::greater<int>> Map;
	// // typedef std::map<int, int, std::greater<int>> Other;
		Map m;
		m.insert(Pair(200, 103));

		m.insert(Pair(100, 103));
		m.insert(Pair(300, 103));

		m.insert(Pair(50, 103));
		m.insert(Pair(150, 103));
		m.insert(Pair(250, 103));
		m.insert(Pair(350, 103));

		Map m2(m);

	// 	// m.insert(Pair(25, 103));
	// 	// m.insert(Pair(75, 103));
		// m.insert(Pair(125, 103));
		// m.insert(Pair(175, 103));
		// m.insert(Pair(225, 103));
		// m.insert(Pair(275, 103));
		// m.insert(Pair(325, 103));
		// m.insert(Pair(375, 103));

		// Other o;
		// o.insert(Pair(200, 103));

		// o.insert(Pair(100, 103));
		// o.insert(Pair(300, 103));

		// o.insert(Pair(50, 103));
		// o.insert(Pair(150, 103));
		// o.insert(Pair(250, 103));
		// o.insert(Pair(350, 103));

		// o.insert(Pair(25, 103));
		// o.insert(Pair(75, 103));
		// o.insert(Pair(125, 103));
		// o.insert(Pair(175, 103));
		// o.insert(Pair(225, 103));
		// o.insert(Pair(275, 103));
		// o.insert(Pair(325, 103));
		// o.insert(Pair(375, 103));


		// std::pair<Map::iterator, Map::iterator> duo = m.equal_range(-2);
		// std::pair<Other::iterator, Other::iterator> duo_other = o.equal_range(-2);
		// cout << duo.first->first << ", " << duo.first->second << " | ";
		// cout << duo.second->first << ", " << duo.second->second << "\n";
		// cout << duo_other.first->first << ", " << duo_other.first->second << " | ";
		// cout << duo_other.second->first << ", " << duo_other.second->second << "\n";

		// Map::iterator it = m.find(50);

		// cout << it->first << ", " << it->second << "\n";
		// ++it;
		// cout << it->first << ", " << it->second << "\n";


		// Map::iterator it = m.find(151);
		// // Map::iterator ite = m.find(250);

		// Map::const_iterator it = m.begin();
		// // Other::iterator ito = o.begin();

		// cout << (*it).first << "\n";
		// // cout << ite->first << "\n";

		// // --ito;
		// // cout << ito->first << "\n";
		// 	// cout << m.size() << "\n";

		// // m.erase(it, ite);
		// m.erase(it);


			// cout << m.size() << "\n";

		m.erase(50);
		m.viewTree();
		Map::const_iterator it = m2.begin();
		for (; it != m2.end(); ++it)
			cout << "other k: "<< it->first << "\n";

		// m == m2;

	}




	return (0);
}
