/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:15:21 by heryu             #+#    #+#             */
/*   Updated: 2022/11/04 20:11:01 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITERATOR_HPP
# define MAPITERATOR_HPP

# include <cstddef>
# include "Data.hpp"

namespace ft
{
	template <typename T>
	class MapIterator
	{
	public:
		typedef T								value_type;
		typedef ptrdiff_t						difference_type;
		typedef T&								reference;
		typedef const T&						const_reference;
		typedef T*								pointer;
		typedef const T*						const_pointer;
		typedef bNode<T>						node_type;
		typedef bNode<T>*						node_pointer;
		typedef ft::bidirectional_iterator_tag	iterator_category;

	protected:
		node_pointer	mPtr;

		node_pointer	__next()
		{
			node_pointer next = NULL;
			if (mPtr->right) //나보다 큰 것 중에 최소
			{
				next = mPtr->right;
				while (next->left)
				{
					next = next->left;
				}
			}
			else // 내가 서브트리에서 최대일 때 -> 부모찾아가기
			{
				node_pointer cur = mPtr;
				next = cur->parent;
				while (next != NULL && next->left != cur)
				{
					cur = next;
					next = next->parent;
				}
			}
			return (next);
		}
		node_pointer	__prev()
		{
			node_pointer prev = NULL;
			if (mPtr->left) //나보다 작은 것 중에 최대
			{
				prev = mPtr->left;
				while (prev->right)
				{
					prev = prev->right;
				}
			}
			else // 내가 서브트리에서 최소일 때 -> 부모찾아가기
			{
				node_pointer cur = mPtr;
				prev = cur->parent;
				while (prev != NULL && prev->right != cur)
				{
					cur = prev;
					prev = prev->parent;
				}
			}
			return (prev);
		}

	public:
		node_pointer	getPtr(void) const
		{
			return (mPtr);
		}
		MapIterator()
			: mPtr(0)
		{

		}
		MapIterator(node_pointer ptr)
			: mPtr(ptr)
		{

		}
		template <typename NON_CONST>
		MapIterator(bNode<NON_CONST>* ptr)
			: mPtr(reinterpret_cast<bNode<const T> *>(ptr))
		{

		}
		MapIterator(const MapIterator& other)
			: mPtr(other.mPtr)
		{

		}
		// Map<T>::const_iterator = Map<T>::iterator의 경우 (복사생성자 혹은 복사대입연산자)
		// 1. const_iterator -> iterator<const T> -> mPtr은 node<const T>*
		// 2. iterator -> iterator<T> -> mPtr은 node<T>*
		// as node<const T>* -> node<T>* error -> reinterpret_cast
		template <typename NON_CONST>
		MapIterator(const MapIterator<NON_CONST>& other)
			: mPtr(reinterpret_cast<bNode<const T> *>(other.getPtr()))
		{

		}
		virtual ~MapIterator()
		{

		}
		MapIterator& operator=(const MapIterator& rhs)
		{
			mPtr = rhs.mPtr;
			return (*this);
		}
		template <typename NON_CONST>
		MapIterator& operator=(const MapIterator<NON_CONST>& rhs)
		{
			mPtr = reinterpret_cast<bNode<const T> *>(rhs.getPtr());
			return (*this);
		}

		bool	operator==(const MapIterator& rhs)
		{
			return (mPtr == rhs.mPtr);
		}
		bool	operator!=(const MapIterator& rhs)
		{
			return (mPtr != rhs.mPtr);
		}

		reference		operator*()
		{
			return (mPtr->val);
		}
		const_reference	operator*() const
		{
			return (mPtr->val);
		}
		pointer			operator->()
		{
			return (&mPtr->val);
		}
		const_pointer	operator->() const
		{
			return (&mPtr->val);
		}

		MapIterator&	operator++()
		{
			mPtr = __next();
			return (*this);
		}
		MapIterator		operator++(int)
		{
			MapIterator tmp(*this);
			mPtr = __next();
			return (tmp);
		}

		MapIterator&	operator--()
		{
			mPtr = __prev();
			return (*this);
		}
		MapIterator		operator--(int)
		{
			MapIterator tmp(*this);
			mPtr = __prev();
			return (tmp);
		}
	};


	// reverse iterator (for Map)
	template <typename Iter>
	class ReverseMapIterator : public Iter
	{
	public:
		typedef	Iter										iterator_type;
		typedef typename iterator_type::iterator_category	iterator_category;
		typedef typename iterator_type::value_type			value_type;
		typedef typename iterator_type::difference_type		difference_type;
		typedef typename iterator_type::pointer				pointer;
		typedef typename iterator_type::const_pointer		const_pointer;
		typedef typename iterator_type::reference			reference;
		typedef typename iterator_type::const_reference		const_reference;
		typedef typename iterator_type::node_type			node_type;
		typedef typename iterator_type::node_pointer		node_pointer;

		ReverseMapIterator()
			: Iter()
		{

		}
		ReverseMapIterator(node_pointer ptr)
			: Iter(ptr)
		{

		}
		template <typename NON_CONST>
		ReverseMapIterator(bNode<NON_CONST>* ptr)
			: Iter(ptr)
		{

		}
		ReverseMapIterator(const iterator_type& iter)
			: Iter(iter)
		{

		}
		ReverseMapIterator(const ReverseMapIterator& other)
			: Iter(other)
		{

		}
		template <typename NON_CONST>
		ReverseMapIterator(const ReverseMapIterator<NON_CONST>& other)
			: Iter(other)
		{

		}
		virtual ~ReverseMapIterator()
		{

		}
		ReverseMapIterator&	operator=(const ReverseMapIterator& rhs)
		{
			Iter::operator=(rhs);
			return (*this);
		}
		template <typename NON_CONST>
		ReverseMapIterator&	operator=(const ReverseMapIterator<NON_CONST>& rhs)
		{
			Iter::operator=(rhs);
			return (*this);
		}

		ReverseMapIterator&		operator++()
		{
			Iter::mPtr = Iter::__prev();
			return (*this);
		}
		ReverseMapIterator		operator++(int)
		{
			ReverseMapIterator tmp(*this);
			Iter::mPtr = Iter::__prev();
			return (tmp);
		}
		ReverseMapIterator&		operator--()
		{
			Iter::mPtr = Iter::__next();
			return (*this);
		}
		ReverseMapIterator		operator--(int)
		{
			ReverseMapIterator tmp(*this);
			Iter::mPtr = Iter::__next();
			return (tmp);
		}
	};
}


#endif
