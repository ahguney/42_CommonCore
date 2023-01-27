#ifndef INSERT_DELETE_HPP
#define INSERT_DELETE_HPP

#include "../utils.hpp"
#include "tree_utils.hpp"
namespace ft
{
	template <typename _Base_ptr, typename _Value, typename _Alloc>
	void create_node(_Base_ptr *_node, _Value _value, _Alloc _allocator)
	{
		*_node = _allocator.allocate(1);
		_allocator.construct(*_node, _value);
	}

	template <typename _Base_ptr, typename _Value, typename _Comp, typename _Alloc>
	_Base_ptr _add_with_balance(_Base_ptr _node, const _Value &_value, _Base_ptr parent, _Comp comp, _Alloc _allocator)
	{
		if (!_node)
		{
			create_node(&_node, _value, _allocator);
			_node->parent_node = parent;
			return _node;
		}
		else if (comp(_value, _node->data))
			_node->left_node = _add_with_balance(_node->left_node, _value, _node, comp, _allocator);
		else if (comp(_node->data, _value))
			_node->right_node = _add_with_balance(_node->right_node, _value, _node, comp, _allocator);
		else
			return _node;
		_node->height = 1 + std::max(height(_node->left_node), height(_node->right_node));
		_node = balance(_node);
		return _node;
	}

	template <typename _Base_ptr, typename _Val, typename _Comp, typename _Alloc>
	_Base_ptr _delete_node(_Base_ptr _node, const _Val &_value, _Comp comp, _Alloc _alloc)
	{
		_Base_ptr temp;
		if (!_node)
			return _node;
		if (comp(_value, _node->data))
			_node->left_node = _delete_node(_node->left_node, _value, comp, _alloc);
		else if (comp(_node->data, _value))
			_node->right_node = _delete_node(_node->right_node, _value, comp, _alloc);
		else
		{
			if (!(_node->left_node) || !(_node->right_node))
			{
				temp = _node->left_node ? _node->left_node : _node->right_node;
				if (!temp)
				{
					temp = _node;
					_node = NULL;
				}
				else
				{
					_Base_ptr parent = _node->parent_node;
					std::swap(_node, temp);
					_node->parent_node = parent;
				}
				_alloc.destroy(temp);
				_alloc.deallocate(temp, 1);
				temp = NULL;
				return _node;
			}
			else
			{
				temp = _node->_maximum(_node->left_node);
				_Val _value = temp->data;
				_Base_ptr parent = _node->parent_node;
				_node->left_node = _delete_node(_node->left_node, _value, comp, _alloc);
				_Base_ptr left = _node->left_node;
				_Base_ptr right = _node->right_node;
				_alloc.destroy(_node);
				_alloc.construct(_node, _value);
				_node->parent_node = parent;
				_node->left_node = left;
				_node->right_node = right;
			}
		}
		_node->height = 1 + std::max(height(_node->left_node), height(_node->right_node));
		_node = balance(_node);
		return _node;
	}

	template <typename _Base_ptr, typename _Alloc>
	_Base_ptr _copy(_Base_ptr tree, _Base_ptr first, _Base_ptr parent, _Alloc _alloc)
	{
		if (!first)
			return tree;
		create_node(&tree, first->data, _alloc);
		tree->parent_node = parent;
		tree->left_node = _copy(tree->left_node, first->left_node, tree, _alloc);
		tree->right_node = _copy(tree->right_node, first->right_node, tree, _alloc);
		return tree;
	}

};

#endif