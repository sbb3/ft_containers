#pragma once

#include "../utils/utils.hpp"

#include <iostream>
using namespace std;

namespace ft
{
	template <typename Node, typename key_type, typename value_type, typename Pair>
	struct TreeIterator
	{
		typedef Pair& pair_reference;
		typedef Pair* pair_pointer;
		typedef Node* pointer;
		typedef Node& reference;

		TreeIterator() : _node(nullptr) {}
		TreeIterator(const pointer node) : _node(node) {}
		TreeIterator(const TreeIterator &other) : _node(other.base()) { }
		TreeIterator &operator=(const TreeIterator &other) { _node = other.base(); return *this; }
		~TreeIterator() { }

		pointer base() const { return _node; }

		// Dereference operator - Returns a reference to the element pointed to by the iterator.
		pair_reference operator*() const { return _node->content; }

		// Arrow operator (returns a pointer to the element type)
		pair_pointer operator->() const { return &_node->content; }

		// Prefix increment operator - advances the iterator to the next element and returns a reference to the
		TreeIterator &operator++()
		{
			_node = advanceToNextNode(_node);
			return *this;
		}

		// Postfix increment operator - Advances the iterator to the next element and returns a copy of the iterator before it was advanced.
		TreeIterator operator++(int)
		{
			TreeIterator copy(*this);
			++(*this);
			return copy;
		}

		// Prefix decrement operator - Moves the iterator to the previous element and returns a reference to the moved iterator.
		TreeIterator &operator--()
		{
			_node = backwardToNextNode(_node);
			return *this;
		}

		// Postfix decrement operator - Moves the iterator to the previous element and returns a copy of the iterator before it was moved.
		TreeIterator operator--(int)
		{
			TreeIterator copy(*this);
			--(*this);
			return copy;
		}

		Node *getPredecessor(Node *root)
		{
			if (!root)
				return nullptr;

			while (root->right)
				root = root->right;
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

		Node *advanceToNextNode(Node *node)
		{
			if (node->right)
				return getSuccessor(node->right);
			else
				return getAncestor(node);
		}

		Node *backwardToNextNode(Node *node)
		{
			if (node->left)
				return getPredecessor(node->left);
			else
				return getAncestor(node);
		}

		bool operator==(const TreeIterator &right) { return base() == right.base(); }

		bool operator!=(const TreeIterator &right) { return base() != right.base(); }

	private:
		pointer _node;

	};


	template <typename TreeIterator>
	struct TreeReverseIterator
	{

	};


} // namespace ft
