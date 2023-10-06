#pragma once

#include <iostream>
#include <stdlib.h> // abs
#include "../iterators/map_iterator.hpp"
#include "../utils/utils.hpp"

using namespace std;

template <typename key_type, typename value_type, typename Pair, typename key_compare>
class Tree
{
public:
	// typedef ft::pair<const key_type, value_type> Pair;

// private:
	struct Node
	{
		Pair content;
		struct Node *parent;
		struct Node *left;
		struct Node *right;
		long height;
	};

public:
	// typedef ft::pair<key_type, value_type> Pair;
	typedef Node*& reference_to_node_pointer;
	typedef Node *node_pointer;
	typedef Node &node_reference;

	typedef ft::TreeIterator<Node, key_type, value_type, Pair> iterator;
	typedef ft::TreeIterator<Node, key_type, value_type, const Pair> const_iterator;

	typedef ft::TreeReverseIterator<iterator> reverse_iterator;
	typedef ft::TreeReverseIterator<const_iterator> const_reverse_iterator;
	typedef std::allocator<Node> nodeAllocator;
	typedef size_t size_type;

private:
	node_pointer _root;
	size_type _size;
	nodeAllocator _allocNode;
	key_compare _comp;

	// utility functions for avl TREE

	void rotateToRightUtil(Node *&root)
	{
		Node *leftChild = root->left;

		leftChild->parent = root->parent;
		root->parent = leftChild;

		root->left = leftChild->right;
		leftChild->right = root;

		updateNodeHeightUtil(root);
		updateNodeHeightUtil(leftChild);

		root = leftChild;
	}

	void rotateToLeftUtil(Node *&root)
	{
		Node *rightChild = root->right;

		rightChild->parent = root->parent;
		root->parent = rightChild;

		root->right = rightChild->left;
		rightChild->left = root;

		updateNodeHeightUtil(root);
		updateNodeHeightUtil(rightChild);

		root = rightChild;
	}

	long getNodeHeightUtil(Node *node)
	{
		if (!node)
			return 0;
		return node->height;
	}

	void updateNodeHeightUtil(Node *&node)
	{
		node->height = ft::max(getNodeHeightUtil(node->left), getNodeHeightUtil(node->right)) + 1;
	}

	long getBalanceFactor(Node *root)
	{
		if (!root)
			return 0;
		return (getNodeHeightUtil(root->left) - getNodeHeightUtil(root->right));
	}

	void balanceTheTreeUtil(Node *&root)
	{
		// update the height of parent node of the child node (inserted one)
		updateNodeHeightUtil(root);

		// // check the balance, between the left subtree and the right subtree
		long balanceFactor = getBalanceFactor(root);
		// // check balance factor and do ratations

		// std::cout << getBalanceFactor(root->left) << '\n';
		if (balanceFactor == -1 || balanceFactor == 0 || balanceFactor == 1)
			return;
		else if (balanceFactor > 1)
		{
			if (getBalanceFactor(root->left) >= 1) // check balance of left subtree and see which subtree is higher either left or right
				rotateToRightUtil(root);
			else
			{
				rotateToLeftUtil(root->left);
				rotateToRightUtil(root);
			}
		}
		else if (balanceFactor < -1)
		{
			if (getBalanceFactor(root->right) <= -1) // check balance of right subtree
				rotateToLeftUtil(root);
			else
			{
				rotateToRightUtil(root->right);
				rotateToLeftUtil(root);
			}
		}
	}

	void create(reference_to_node_pointer node, Pair duo)
	{
		node = _allocNode.allocate(1);

		_allocNode.construct(&node->content.first, duo.first);
		_allocNode.construct(&node->content.second, duo.second);
		node->left = nullptr;
		node->right = nullptr;
		node->parent = nullptr;
		node->height = 1; // parent has only leftchild, balance factor must be 1, not 0, (1 - 0) = 1, not (0 - 0)
	}

	void insertUtil(Node *&root, Pair duo, Node *&newNode, bool &isInserted)
	{
		if (!root)
		{
			create(root, duo);
			++_size;
			newNode = root;
			isInserted = true;
			return;
		}
		else if (duo.first == getKey(root))
		{
			newNode = root;
			isInserted = false;
			return;
		}
		else if (_comp(duo.first, getKey(root)))
		{
			insertUtil(root->left, duo, newNode, isInserted);
			root->left->parent = root;
		}
		else if (_comp(getKey(root), duo.first))
		{
			insertUtil(root->right, duo, newNode, isInserted);
			root->right->parent = root;
		}
		balanceTheTreeUtil(root);
	}

	void eraseNodeUtil(Node *&root, key_type key, Node *&nextNode, bool &isErased)
	{
		if (!root)
		{
			isErased = false;
			return;
		}

		else if (_comp(key, getKey(root)))
		{
			eraseNodeUtil(root->left, key, nextNode, isErased);
		}
		else if (_comp(getKey(root), key))
		{
			eraseNodeUtil(root->right, key, nextNode, isErased);
		}
		else if (key == getKey(root))
		{
			isErased = true;
			// no children
			if (!root->left && !root->right)
			{
				nextNode = getAncestor(root);
				destroyNodeUtil(root);
				return;
			}
			else
			{
				// no left or no right, but there is one of them
				if (!root->left || !root->right)
				{
					Node *toBeDeletedChild = (root->left) ? root->left : root->right;
					Node *toBeDeletedParent = root->parent;

					if (root->right)
						nextNode = root->right;
					else if (root->parent)
						nextNode = getAncestor(root);

					destroyNodeUtil(root);

					root = toBeDeletedChild;
					root->parent = toBeDeletedParent;

				}
				// both exist
				else
				{
					Node *node = getSuccessor(root->right);
					key_type savedKey = getKey(node);
					value_type savedValue = getValue(node);
					eraseNodeUtil(root->right, savedKey, nextNode, isErased);
					root->content.first = savedKey;
					root->content.second = savedValue;
					nextNode = root;
				}
			}
		}
		balanceTheTreeUtil(root);
	}

	Node * searchUtil(Node *root, key_type key) const
	{
		if (!root)
			return nullptr;

		if (key == root->content.first)
			return root;

		else if (key < root->content.first)
			root = searchUtil(root->left, key);

		else if (key > root->content.first)
			root = searchUtil(root->right, key);

		return root;
	}

	Node * searchUtil(Node *root, key_type key, Node *&parent)
	{
		if (!root)
			return nullptr;

		if (key == root->content.first)
			return root;

		else if (key < root->content.first)
		{
			if (!root->left) {
				parent = root;
				return nullptr;
			}
			root = searchUtil(root->left, key, parent);
		}

		else if (key > root->content.first)
		{

			if (!root->right) {
				parent = root;
				return nullptr;
			}
			root = searchUtil(root->right, key, parent);
		}

		return root;
	}

	Node *getSuccessor(Node *root)
	{
		if (!root)
			return nullptr;

		while (root->left)
			root = root->left;
		return root;
	}

	Node *getAncestor(Node *root)
	{
		Node *parent = root->parent;
		while (parent && root == parent->right)
		{
			root = parent;
			parent = parent->parent;
		}
		return parent;
	}

	void destroyNodeUtil(Node *&node)
	{
		_allocNode.destroy(&node->content.first);
		_allocNode.destroy(&node->content.second);
		_allocNode.deallocate(node, 1);
		node = nullptr;
		--_size;
	}

	void inorderUtil(Node *node)
	{
		if (!node)
			return;

		inorderUtil(node->left);
		std::cout << "k: " << node->content.first << " , v: " << node->content.second << " , h: " << node->height << '\n';
		inorderUtil(node->right);
	}

	void ClearByPostorderUtil(Node *&node)
	{
		if (!node)
			return;

		ClearByPostorderUtil(node->left);
		ClearByPostorderUtil(node->right);
		destroyNodeUtil(node);
	}

	bool isBalancedOptimizedUtil(Node *root, long &heightDiff)
	{
		if (!root)
		{
			heightDiff = 0;
			return true;
		}

		long leftHeightDiff = 0;
		long rightHeightDiff = 0;
		if (isBalancedOptimizedUtil(root->left, leftHeightDiff) &&
			isBalancedOptimizedUtil(root->right, rightHeightDiff))
		{
			heightDiff = abs(leftHeightDiff - rightHeightDiff);
			if (heightDiff <= 1)
			{
				heightDiff = ft::max(leftHeightDiff, rightHeightDiff) + 1;
				return true;
			}
		}

		return false;
	}

public:
	Tree() : _root(nullptr), _size(0) { }

	Tree(const Tree &other) : _root(nullptr), _allocNode(other._allocNode), _comp(other._comp), _size(other._size)
	{
		// const_iterator it = other.tree_begin();
		// other.
		// ft::pair<int, int> duo = ft::make_pair(1, 1);
		for (const_iterator it = other.tree_begin(); it != other.tree_end(); ++it)
			insertByPair(*it);

	}

	template <typename InputIterator>
	Tree(InputIterator first, InputIterator last, const key_compare &comp = key_compare()) : _root(NULL), _size(0), _comp(comp)
	{
		for (; first != last; ++first)
		{
			insertByIter(first);
		}
	}

	~Tree() { clearTree(); }

	Node *search(const key_type &key) const { return searchUtil(_root, key); }

	Node *search(const key_type &key, Node *&parent)  { return searchUtil(_root, key, parent); }


	ft::pair<iterator, bool> insertByPair(Pair duo)
	{
		Node *newNode = nullptr;
		bool isInserted = false;
		insertUtil(_root, duo, newNode, isInserted);

		return ft::make_pair(getIterOnSpecifecNode(newNode), isInserted);
	}

	template <typename InputIterator>
	void insertByIter(InputIterator it)
	{
		insertByPair(*it);
	}

	iterator insertByIterPosition(iterator &position, const Pair &duo)
	{
		(void)position;

		Node *isDuoFirstAlreadyExists = search(duo.first);
		if (isDuoFirstAlreadyExists)
			return iterator(isDuoFirstAlreadyExists);

		// Node *found = search(position->first);
		// Node *newNode = nullptr;
		// bool isInserted = false;
		// insertUtil(found, duo, newNode, isInserted);
		// if (isInserted)
		// 	cout << "true insrted\n";
		// else
		// 	cout << "false insrted\n";
		// return iterator(newNode);

		return insertByPair(duo).first;
	}

	size_type eraseByKey(key_type key)
	{
		Node *remplacedNode = nullptr;
		bool isErased = false;
		eraseNodeUtil(_root, key, remplacedNode, isErased);

		return isErased ? 1 : 0;
	}

	Node *eraseByKeyThenReturnNextNode(key_type key)
	{
		Node *nextNode = nullptr;
		bool isErased = false;
		eraseNodeUtil(_root, key, nextNode, isErased);

		return nextNode;
	}

	void clearTree()
	{
		if (!isEmpty())
		{
			ClearByPostorderUtil(_root);
			_size = 0;
		}
	}

	reference_to_node_pointer findThenReturnRefToNode(const key_type key)
	{
		Node **node = &_root;

		// cout << (_root) << '\n';
		// cout << &(_root) << '\n';
		// cout << &(*node) << '\n';
		// cout << (node) << '\n';
		while (*node)
		{
			if (key == (*node)->content.first)
			{
				break;
			}
			else if (key < (*node)->content.first)
			{
				node = &((*node)->left);
			}
			else if (key > (*node)->content.first)
			{
				node = &((*node)->right);
			}
		}
		// cout << (*node) << '\n';
		// cout << &(*node) << '\n';
		// cout << (node) << '\n';

		return *node;
	}

	reference_to_node_pointer getNodeByRef(const key_type &key) { return findThenReturnRefToNode(key); }

	Pair &getPairByRef(const key_type &key) { return getNodeByRef(key)->content; }

	value_type &getPairSecond(const key_type &key) { return getPairByRef(key).second; }

	// iterator getIterator(const key_type &key) { return iterator(getNodeByRef(key)); }

	value_type &operator[](const key_type &key)
	{
		insertByPair(ft::make_pair(key, value_type()));
		return getPairSecond(key);
	}

	// value_type &at(const key_type &key)
	// {
	// 	// if there is elem return it, else throw an exception

	// }

	bool isEmpty() const { return (_root == nullptr); }

	Node *getMin(Node *root)
		{
			if (!root)
				return nullptr;
			while (root->left)
				root = root->left;
			return root;
		}

		Node *getMax(Node *root)
		{
			if (!root)
				return nullptr;

			while (root->right)
				root = root->right;
			return root;
		}

	Node *getMinNode(Node *root)
	{
		if (!root)
			return nullptr;

		while (root->left)
			root = root->left;
		return root;
	}

	Node *getMinNode(Node *root) const
	{
		if (!root)
			return nullptr;

		while (root->left)
			root = root->left;
		return root;
	}

	Node *getMaxNode(Node *root)
	{
		if (!root)
			return nullptr;

		while (root->right)
			root = root->right;
		return root;
	}

	// change this
	Node *getMaxNodePlus(Node *root)
	{
		if (!root)
			return nullptr;

		while (root->right)
			root = root->right;
		return root->right;
	}
	Node *getMaxNodePlus(Node *root) const
	{
		if (!root)
			return nullptr;

		while (root->right)
			root = root->right;
		return root->right;
	}

	Node *getFirstNodeInTheTree() { return getMinNode(_root); }

	Node *getLastNodeInTheTree() { return getMaxNodePlus(_root); }


	Node *getRootNode() const { return _root; }

	size_type getTreeSize() const { return _size; }

	size_type max_size() const { return _allocNode.max_size(); }

	size_type getTreeCount(const key_type &key) const { return (search(key) != nullptr) ? 1 : 0; }

	iterator getIterOnMinElement() { return iterator(getMinNode(_root)); }

	const_iterator getConstIterOnMinElement() const { return const_iterator(getMinNode(_root)); }

	iterator getIterOnMaxElement() { return iterator(getMaxNodePlus(_root)); }

	const_iterator getConstIterOnMaxElement() const { return const_iterator(getMaxNodePlus(_root)); }

	iterator getIterOnRoot() { return iterator(getRootNode()); }

	iterator getIterOnSpecifecNode(Node *node) { return iterator(node); }

	iterator tree_begin() { return getIterOnMinElement(); }

	const_iterator tree_begin() const { return getConstIterOnMinElement(); }

	iterator tree_end() { return getIterOnMaxElement(); }

	const_iterator tree_end() const { return getConstIterOnMaxElement(); }

	// to be removed when finished
	bool isBalancedOptimized(Node *root)
	{
		long heightDiff = 0;
		return isBalancedOptimizedUtil(root, heightDiff);
	}

	iterator find(const key_type &key)
	{
		Node *found = search(key);
		if (found)
			return iterator(found);
		return iterator(tree_end());
	}

	const_iterator find(const key_type &key) const
	{
		Node *found = search(key);
		if (found)
			return const_iterator(found);
		return const_iterator(tree_end());
	}



	iterator lowerBound(const key_type &key)
	{
		Node *first = getFirstNodeInTheTree();
		for (; first && _comp(getKey(first), key); first = advanceToNextNode(first));

		return iterator(first);
	}

	iterator upperBound(const key_type &key)
	{
		Node *first = getFirstNodeInTheTree();
		for (; first && !_comp(key, getKey(first)); first = advanceToNextNode(first));

		return iterator(first);
	}

	key_type getKey(Node *&node) { return node->content.first; }

	value_type getValue(Node *&node) { return node->content.second; }

	Node *advanceToNextNode(Node *&node)
	{
		// to advance to the right side of the three, two cases: if node is on left side of _root, then if there is no node->right, you could set node to parent, second case, if you are on right side, you couldnot set node to parent, you should always advance to right
		if (node->right)
			return getSuccessor(node->right);
		else
			return getAncestor(node);
	}

	void viewTree()
	{
		cout << "Tree elements: \n";
		inorderUtil(_root);
		cout << "empty: " << isEmpty() << ", size: " << getTreeSize() << ", balanced: " << isBalancedOptimized(getRootNode()) << "\n";
	}
};

// template<typename rrr>
// struct Lopez
// {
// 	typedef int me;
// 	typedef rrr Integer;
// };
