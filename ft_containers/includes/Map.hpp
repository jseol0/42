/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:18:25 by heryu             #+#    #+#             */
/*   Updated: 2022/11/04 20:10:55 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <limits>
# include <functional>
# include "MapIterator.hpp"

# define NOT_FOUND	0
# define LEFT		1
# define RIGHT		2

namespace ft
{
	template <typename Key, typename T,
			  typename Compare = std::less<Key>,
			  typename Alloc = std::allocator<std::pair<const Key, T> > >
	class Map
	{
	public:
		typedef	Key											key_type;
		typedef T											mapped_type;
		typedef std::pair<const key_type, mapped_type>		value_type;

		typedef Compare										key_compare;

		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;

		typedef ft::MapIterator<value_type>					iterator;
		typedef ft::MapIterator<const value_type>			const_iterator;
		typedef ft::ReverseMapIterator<iterator>			reverse_iterator;
		typedef ft::ReverseMapIterator<const_iterator>		const_reverse_iterator;

		typedef ptrdiff_t									diffrence_type;
		typedef size_t										size_type;

		typedef bNode<value_type>							node_type;
		typedef bNode<value_type>*							node_pointer;

		// key,value에서 value가 아님 (pair를 의미함에 주의)
		class value_compare : std::binary_function<value_type, value_type, bool>
		{
		friend class Map;
		protected:
			Compare comp;	// in C++98, it is required to inherit binary_function<value_type,value_type,bool>
			value_compare(Compare c) : comp(c) {}
		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;
			bool operator() (const value_type& x, const value_type& y) const
			{
				return comp(x.first, y.first);
			}
		};

	private:
		node_pointer	mRoot;	// null로 초기화
		node_type		mEnd;	// mEnd와 mrEnd는 일단 서로 부모여야함 (iterator 때문)
		node_type		mrEnd;	// mEnd와 mrEnd는 일단 서로 부모여야함 (iterator 때문)
		size_type		mSize;
		key_compare		mKeyComp;
		allocator_type	mAlloc;

		node_pointer __find(node_pointer cur, const key_type& k)
		{
			if (cur == NULL || cur == &mEnd || cur == &mrEnd)
				return (end().getPtr());
			// Two keys are considered equivalent
			// if the container's comparison object returns false reflexively
			// (i.e., no matter the order in which the elements are passed as arguments).
			if (!mKeyComp(cur->val.first, k) && !mKeyComp(k, cur->val.first)) // 같음
				return (cur);

			if (mKeyComp(cur->val.first, k)) // k가 더 크면 오른쪽으로 (less<int>일 때)
				return (__find(cur->right, k));
			else // 그게 아니면 왼쪽
				return (__find(cur->left, k));
		}

		node_pointer __find(node_pointer cur, const key_type& k) const
		{
			if (cur == NULL || cur == &mEnd || cur == &mrEnd)
				return (reinterpret_cast<node_pointer>(end().getPtr()));
			// Two keys are considered equivalent
			// if the container's comparison object returns false reflexively
			// (i.e., no matter the order in which the elements are passed as arguments).
			if (!mKeyComp(cur->val.first, k) && !mKeyComp(k, cur->val.first)) // 같음
				return (cur);

			if (mKeyComp(cur->val.first, k)) // k가 더 크면 오른쪽으로 (less<int>일 때)
				return (__find(cur->right, k));
			else // 그게 아니면 왼쪽
				return (__find(cur->left, k));
		}

		std::pair<node_pointer, int> __searchInsertNode(node_pointer cur, const key_type& k) const
		{
			if (cur == NULL || cur == &mEnd || cur == &mrEnd ||
				(!mKeyComp(cur->val.first, k) && !mKeyComp(k, cur->val.first)))
				return (std::pair<node_pointer, int>(cur, NOT_FOUND));

			if (mKeyComp(cur->val.first, k)) // k가 더 크면 오른쪽으로 (less<int>일 때)
			{
				if (cur->right == NULL || cur->right == &mEnd)
					return (std::pair<node_pointer, int>(cur, RIGHT));
				else
					return (__searchInsertNode(cur->right, k));
			}
			else // 그게 아니면 왼쪽
			{
				if (cur->left == NULL || cur->left == &mrEnd)
					return (std::pair<node_pointer, int>(cur, LEFT));
				else
					return (__searchInsertNode(cur->left, k));
			}
		}

		std::pair<iterator, bool> __insert(node_pointer root, const value_type& val)
		{
			std::pair<node_pointer, int> found = __searchInsertNode(root, val.first);

			// found.first : fount_node
			// found.second : flag_dir ( 0:notfound, 1:left, 2:right)
			// 0 : notfound -> node is { Dup_key | Null | End }
			if (found.second == NOT_FOUND)
				return (std::pair<iterator, bool>(iterator(found.first), false));

			node_pointer newNode = new node_type(val);
			if (found.second == LEFT)
			{
				if (found.first->left == &mrEnd)
				{
					newNode->left = &mrEnd;
					mrEnd.parent = newNode;
				}
				found.first->left = newNode;
				newNode->parent = found.first;
			}
			else // (found.second == RIGHT)
			{
				if (found.first->right == &mEnd)
				{
					newNode->right = &mEnd;
					mEnd.parent = newNode;
				}
				found.first->right = newNode;
				newNode->parent = found.first;
			}
			mSize++;
			return (std::pair<iterator, bool>(iterator(newNode), true));
		}

		node_pointer	__lower_bound_pointer(const key_type& k) const
		{
			std::pair<node_pointer, int> p = __searchInsertNode(mRoot, k);
			if (p.second == NOT_FOUND && p.first->val.first == k) // 같은 키
				return (p.first);
			node_pointer bound = p.first;
			while (bound != NULL && mKeyComp(bound->val.first, k)) // if (k <= bound), break
				bound = bound->parent;
			return (bound); // null or k <= bound
		}
		node_pointer	__upper_bound_pointer(const key_type& k) const
		{
			std::pair<node_pointer, int> p = __searchInsertNode(mRoot, k);
			if (p.second == NOT_FOUND && p.first->val.first == k) // 같은 키
				return ((++(iterator(p.first))).getPtr());
			node_pointer bound = p.first;
			while (bound != NULL && !mKeyComp(k, bound->val.first)) // if (k < bound), break
			{
				bound = bound->parent;
			}
			return (bound); // null or k < bound
		}

		void		__resetEndNode(void)
		{
			if (mRoot == NULL)
			{
				mrEnd.parent = &mEnd;
				mEnd.parent = &mrEnd;
				return ;
			}

			node_pointer maxNode = mRoot;
			while (maxNode->right)
			{
				maxNode = maxNode->right;
			}
			mEnd.parent = maxNode;
			maxNode->right = &mEnd;

			node_pointer minNode = mRoot;
			while (minNode->left)
			{
				minNode = minNode->left;
			}
			mrEnd.parent = minNode;
			minNode->left = &mrEnd;
		}

	public:
		// copliens form
		explicit Map(const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type())
			: mRoot(0), mEnd(), mrEnd(), mSize(0), mKeyComp(comp), mAlloc(alloc)
		{
			mEnd.parent = &mrEnd;
			mrEnd.parent = &mEnd;
		}

		template <class InputIterator>
		Map(InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type())
			: mRoot(0), mEnd(), mrEnd(), mSize(0), mKeyComp(comp), mAlloc(alloc)
		{
			mEnd.parent = &mrEnd;
			mrEnd.parent = &mEnd;

			insert(first, last);
		}

		Map(const Map& other)
			: mRoot(0), mEnd(), mrEnd(), mSize(0), mKeyComp(other.mKeyComp), mAlloc(other.mAlloc)
		{
			mEnd.parent = &mrEnd;
			mrEnd.parent = &mEnd;
			*this = other;
		}

		virtual ~Map()
		{
			clear();
		}

		Map&	operator=(const Map& rhs)
		{
			if (this != &rhs)
			{
				if (!empty())
					clear();
				mEnd.parent = &mrEnd;
				mrEnd.parent = &mEnd;
				insert(rhs.begin(), rhs.end());
			}
			return (*this);
		}


		// iterator
		iterator				begin()
		{
			return (iterator(mrEnd.parent));
		}
		const_iterator			begin() const
		{
			return (const_iterator(mrEnd.parent));
		}

		iterator				end()
		{
			return (iterator(&mEnd));
		}
		const_iterator			end() const
		{
			return (const_iterator(const_cast<node_pointer>(&mEnd))); // Map.hpp에 설명
		}

		reverse_iterator		rbegin()
		{
			return (reverse_iterator(mEnd.parent));
		}
		const_reverse_iterator	rbegin() const
		{
			return (const_reverse_iterator(mEnd.parent));
		}

		reverse_iterator		rend()
		{
			return (reverse_iterator(&mrEnd));
		}
		const_reverse_iterator	rend() const
		{
			return (const_reverse_iterator(const_cast<node_pointer>(&mrEnd)));
		}


		// capacity
		bool		empty() const
		{
			return (mSize == 0);
		}
		size_type	size() const
		{
			return (mSize);
		}
		size_type	max_size() const
		{
			return (ULONG_MAX / (sizeof(node_type)));
		}


		// element access
		mapped_type&	operator[](const key_type& k)
		{
			iterator found = find(k);
			if (found != end())
				return (found->second);
			return(insert(value_type(k, mapped_type())).first->second);
		}


		// modifiers
		std::pair<iterator, bool> insert(const value_type& val)
		{
			if (mRoot == NULL)
			{
				node_pointer newNode = new node_type(val);
				mRoot = newNode;
				newNode->parent = NULL;
				newNode->left = &mrEnd;
				newNode->right = &mEnd;
				mEnd.parent = newNode;
				mrEnd.parent = newNode;
				++mSize;
				return (std::pair<iterator, bool>(iterator(newNode), true));
			}
			else
			{
				return (__insert(mRoot, val));
			}
		}
		iterator insert(iterator hint, const value_type& val)
		{
			// if an invalid position is specified, it causes undefined behavior.
			// https://stackoverflow.com/questions/32758548/stdmap-insert-hint-location-difference-between-c98-and-c11
			// hint로 인해 BST의 복잡성을 깰 수 있음
			// 혹은 hint가 맞는지 확인하는 것은 그냥 insert하는 것보다 비효율적
			// if (mRoot == NULL)
			// 	return (insert(val).first);
			// return (__insert(hint.getPtr(), val).first);
			(void)hint;
			return (insert(val).first);
		}
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last)
		{
			InputIterator iter = first;
			while (iter != last)
			{
				insert(*iter);
				iter++;
			}
		}

		// If an invalid position or range is specified, it causes undefined behavior.
		void		erase(iterator position)
		{
			node_pointer delNode = position.getPtr();

			// map에 mEnd, mrEnd를 따로 두기때문에 처리해줘야 할게 많음
			mrEnd.parent->left = NULL;
			mEnd.parent->right = NULL;

			// size == 1일 때
			if (delNode == mRoot && mSize == 1)
			{
				mRoot = NULL;
				mSize--;
				delete delNode;
				return __resetEndNode();
			}

			// 양쪽 자식이 없으면 부모 설정 후 삭제
			// (이 노드가 자식이 없는 루트노드일 경우 위에서 거름)
			if (delNode->left == NULL && delNode->right == NULL)
			{
				if (delNode->parent->left == delNode)
					delNode->parent->left = NULL;
				else
					delNode->parent->right = NULL;
				delete delNode;
				mSize--;
				return __resetEndNode();
			}

			// 왼쪽 자식만 없을 때
			if (delNode->left == NULL)
			{
				// 그 중 루트노드 일 경우
				if (delNode->parent == NULL)
				{
					delNode->right->parent = NULL;
					mRoot = delNode->right;
				}
				else
				{
					if (delNode->parent->left == delNode)
						delNode->parent->left = delNode->right;
					else
						delNode->parent->right = delNode->right;
					delNode->right->parent = delNode->parent;
				}
				delete delNode;
				mSize--;
				return __resetEndNode();
			}

			// 오른쪽 자식만 없으면
			if (delNode->right == NULL)
			{
				// 그 중 루트노드 일 경우
				if (delNode->parent == NULL)
				{
					delNode->left->parent = NULL;
					mRoot = delNode->left;
				}
				else
				{
					if (delNode->parent->left == delNode)
						delNode->parent->left = delNode->left;
					else
						delNode->parent->right = delNode->left;
					delNode->left->parent = delNode->parent;
				}
				delete delNode;
				mSize--;
				return __resetEndNode();
			}

			// 둘 다 자식 있으면
			// 나보다 작은 것 중에 최대를 고르던지 <<<
			// 나보다 큰 것 중에 최소를 고르던지
			node_pointer replaceNode = delNode->left;
			while (replaceNode->right) // 작은 것 중에 최대 찾음
				replaceNode = replaceNode->right;
			if (replaceNode->parent != delNode)
			{
				// replaceNode의 부모 + 자식의 연결
				if (replaceNode->left)
					replaceNode->left->parent = replaceNode->parent;
				replaceNode->parent->right = replaceNode->left;

				// delNode의 왼쪽과 replace와 연결
				delNode->left->parent = replaceNode;
				replaceNode->left = delNode->left;
			}

			delNode->right->parent = replaceNode; // delNode->right와 replace연결
			replaceNode->right = delNode->right;

			if (delNode->parent == NULL)	// replaceNode와 delNode->parent와 연결
			{
				replaceNode->parent = NULL;
				mRoot = replaceNode;
			}
			else
			{
				if (delNode->parent->left == delNode)
					delNode->parent->left = replaceNode;
				else
					delNode->parent->right = replaceNode;
				replaceNode->parent = delNode->parent;
			}
			mSize--;
			delete delNode;
			return __resetEndNode();
		}
		size_type	erase(const key_type& k) // 0 or 1
		{
			iterator iter = find(k);
			if (iter != end())
			{
				erase(iter);
				return (1);
			}
			return (0);
		}
		void		erase(iterator first, iterator last)
		{
			iterator iter = first;
			while (iter != last)
			{
				erase(iter++); //삭제 된 iter에 증감을 할 때의 위험성
			}
		}

		void	swap(Map& x)
		{
			node_pointer	tmpRoot = mRoot;
			node_type		tmpEnd = mEnd;
			node_type		tmprEnd = mrEnd;
			size_type		tmpSize = mSize;
			key_compare		tmpKeyComp = mKeyComp;
			allocator_type	tmpAlloc = mAlloc;

			mRoot = x.mRoot;
			mEnd = x.mEnd;
			mrEnd = x.mrEnd;
			mSize = x.mSize;
			mKeyComp = x.mKeyComp;
			mAlloc = x.mAlloc;

			x.mRoot = tmpRoot;
			x.mEnd = tmpEnd;
			x.mrEnd = tmprEnd;
			x.mSize = tmpSize;
			x.mKeyComp = tmpKeyComp;
			x.mAlloc = tmpAlloc;

			if (mSize == 0)
			{
				mrEnd.parent = &mEnd;
				mEnd.parent = &mrEnd;
			}
			else
			{
				mrEnd.parent->left = &mrEnd;
				mEnd.parent->right = &mEnd;
			}
			if (x.mSize == 0)
			{
				x.mrEnd.parent = &x.mEnd;
				x.mEnd.parent = &x.mrEnd;
			}
			else
			{
				x.mrEnd.parent->left = &x.mrEnd;
				x.mEnd.parent->right = &x.mEnd;
			}
		}

		void	clear()
		{
			erase(begin(), end());
		}

		// observers
		key_compare key_comp() const
		{
			return (mKeyComp);
		}
		value_compare value_comp() const
		{
			return (value_compare(mKeyComp));
		}

		// operations
		iterator		find(const key_type& k) // must be O(logN)
		{
			if (mRoot == NULL)
				return (end());
			return (iterator(__find(mRoot, k)));
		}
		const_iterator	find(const key_type& k) const
		{
			if (mRoot == NULL)
				return (end());
			return (const_iterator(__find(mRoot, k)));
		}

		size_type count (const key_type& k) const
		{
			if (find(k) != end())
				return (1);
			return (0);
		}

		// 7 1 2 3 4 5 -> k == 6
		iterator lower_bound (const key_type& k)
		{
			if (mRoot == NULL)
				return (end());

			node_pointer bound = __lower_bound_pointer(k);
			if (bound == NULL)
				return (end());
			else
				return (iterator(bound));
		}
		const_iterator lower_bound (const key_type& k) const
		{
			if (mRoot == NULL)
				return (end());

			node_pointer bound = __lower_bound_pointer(k);
			if (bound == NULL)
				return (end());
			else
				return (const_iterator(bound));
		}

		iterator upper_bound (const key_type& k)
		{
			if (mRoot == NULL)
				return (end());

			node_pointer bound = __upper_bound_pointer(k);
			if (bound == NULL)
				return (end());
			else
				return (iterator(bound));
		}
		const_iterator upper_bound (const key_type& k) const
		{
			if (mRoot == NULL)
				return (end());

			node_pointer bound = __upper_bound_pointer(k);
			if (bound == NULL)
				return (end());
			else
				return (const_iterator(bound));
		}
	};

	// non member
	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename Map<Key,T,Compare,Alloc>::const_iterator lhs_iter = lhs.begin();
		typename Map<Key,T,Compare,Alloc>::const_iterator rhs_iter = rhs.begin();
		size_t size = lhs.size();
		for (size_t i = 0; i < size; ++i)
		{
			if (lhs_iter->first != rhs_iter->first || lhs_iter->second != rhs_iter->second)
				return (false);
			++lhs_iter;
			++rhs_iter;
		}
		return (true);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs)
	{
		typename Map<Key,T,Compare,Alloc>::const_iterator l_first = lhs.begin();
		typename Map<Key,T,Compare,Alloc>::const_iterator l_last = lhs.end();
		typename Map<Key,T,Compare,Alloc>::const_iterator r_first = rhs.begin();
		typename Map<Key,T,Compare,Alloc>::const_iterator r_last = rhs.end();
		// lexicographical compare
		while (l_first != l_last)
		{
			if (r_first == r_last || *l_first > *r_first)
				return (false);
			else if (*l_first < *r_first)
				return (true);
			++l_first;
			++r_first;
		}
		return (r_first != r_last);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	void swap(Map<Key,T,Compare,Alloc>& x, Map<Key,T,Compare,Alloc>& y)
	{
		x.swap(y);
	}
}

#endif
