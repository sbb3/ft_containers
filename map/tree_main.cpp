#include "Tree.hpp"
#include <iostream>

using namespace std;

int main()
{
	std::cout << std::boolalpha;

	typedef ft::pair<const int, int> Duo;
	typedef Tree<int, int, Duo, std::less<int>, Duo*> type;

	type m1;
	type *ptr = &m1;

	m1.insertByPair(Duo(6, 103));
	m1.insertByPair(Duo(2, 104));
	m1.insertByPair(Duo(12, 105));
	m1.insertByPair(Duo(1, 106));
	m1.insertByPair(Duo(3, 109));
	m1.insertByPair(Duo(10, 107));
	m1.insertByPair(Duo(15, 108));
	// // m1.insertByPair(Duo(0, 109));
	// m1.insertByPair(Duo(9, 109));
	// m1.insertByPair(Duo(5, 109));
	// m1.eraseByKey(1);
	// m1.eraseByKey(10);
	// m1[16];
	// m1[16] = 70;
	// type::iterator it = m1.tree_begin();
	// type::iterator position = m1.insertByIterPosition(it, Duo(15, 107));

	// type::iterator ite = m1.tree_end();

	// type m2(it, ite);

	// type::iterator it2 = m1.getIterator(2);
	// cout << (*it++).content.first << "\n";
	// it++;
	// cout << (*it).content.first << "\n";

	// // std::cout << m1.getMin()->key << "\n";
	// // std::cout << m1.getMax()->key << "\n";
	// m1.at(6) = 1000;
	// m1[100];
	// m1.at(6) = 1337;
	// m1[21] = 101;
	// m1.at(600) = 1337;
	// it2->content.second = 42;
	// std::cout << "Single element: " << m1.at(6) << '\n';
	// std::cout << "position: " << position->first << ' ' << position->second << '\n';

	// m1.eraseByKey(2);
	// type::iterator it = m1.upperBound(90);
	// if (it != m1.tree_end())
	// 	cout << it->first << ", " << it->second << "\n";
	// else
		// cout << "null\n";
	// m1.viewTree();
	// m1.clearTree();

	// std::cout << "\nm2 elements: \n";
	// m2.viewTree();
	// // m2.clearTree();
	// std::cout << "\nm2 empty: " << m2.isEmpty() << "\n";
	// std::cout << "m2 size: " << m2.getTreeSize() << "\n";
	// std::cout << "m2 balanced: " << m2.isBalancedOptimized(m1.getRootNode()) << "\n";

	type::Node * first = m1.getFirstNodeInTheTree();
	// type::Node *last = m1.getLastNodeInTheTree();

	// for (; first != last; m1.advanceToNextNode(first))
		cout << first->content.first << '\n';
	return (0);
}
