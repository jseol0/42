/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:32:41 by jseol             #+#    #+#             */
/*   Updated: 2022/11/12 18:50:34 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

# include "Data.hpp"
# include <cstddef>

namespace ft
{
	// ===========================================================================
	// VectorIterator
	template <typename T>
	class VectorIterator
	{
	public:
		typedef T								value_type;
		typedef ptrdiff_t						difference_type;
		typedef T&								reference;
		typedef const T&						const_reference;
		typedef T*								pointer;
		typedef const T*						const_pointer;
		typedef ft::random_access_iterator_tag	iterator_category;

	protected:
		pointer	mPtr;

	public:
		VectorIterator()
			: mPtr(0)
		{

		}
		VectorIterator(pointer ptr)
			: mPtr(ptr)
		{

		}
		VectorIterator(const VectorIterator& other)
			: mPtr(other.mPtr)
		{

		}
		template <typename NON_CONST>
		VectorIterator(const VectorIterator<NON_CONST>& other)
			: mPtr(&(other.operator*()))
		{

		}
		virtual ~VectorIterator()
		{

		}
		VectorIterator& operator=(const VectorIterator& rhs)
		{
			mPtr = rhs.mPtr;
			return (*this);
		}
		template <typename NON_CONST>
		VectorIterator& operator=(const VectorIterator<NON_CONST>& rhs)
		{
			mPtr = &(rhs.operator*());
			return (*this);
		}

		bool				operator==(const VectorIterator& rhs) const
		{
			return (mPtr == rhs.mPtr);
		}
		bool				operator!=(const VectorIterator& rhs) const
		{
			return (mPtr != rhs.mPtr);
		}

		reference			operator*()	// *iter
		{
			return (*mPtr);
		}
		const_reference			operator*() const	//const iterator | const_iterator
		{
			return (*mPtr);
		}
		pointer				operator->()	// VectorIterator<A>::iter->mPrint();
		{
			return (mPtr);
		}
		const_pointer		operator->() const	// VectorIterator<A>::iter->mPrint();
		{
			return (mPtr);
		}

		VectorIterator&		operator++()	// prefix ++iter
		{
			++mPtr;
			return (*this);
		}
		VectorIterator		operator++(int)	// postfix iter++
		{
			VectorIterator	tmp(*this);
			mPtr++;
			return (tmp);
		}
		VectorIterator&		operator--()	// prefix --iter
		{
			--mPtr;
			return (*this);
		}
		VectorIterator		operator--(int)	// postfix iter--
		{
			VectorIterator	tmp(*this);
			mPtr--;
			return (tmp);
		}
		VectorIterator		operator+(difference_type n) const	// iter + n
		{
			VectorIterator	tmp(mPtr + n);
			return (tmp);
		}
		VectorIterator		operator-(difference_type n) const	// iter - n
		{
			VectorIterator tmp(mPtr - n);
			return (tmp);
		}
		difference_type		operator-(const VectorIterator& rhs) const // iter1 - iter2
		{
			return (mPtr - rhs.mPtr);
		}
		bool				operator<(const VectorIterator& rhs) const
		{
			return (mPtr < rhs.mPtr);
		}
		bool				operator>(const VectorIterator& rhs) const
		{
			return (mPtr > rhs.mPtr);
		}
		bool				operator<=(const VectorIterator& rhs) const
		{
			return (mPtr <= rhs.mPtr);
		}
		bool				operator>=(const VectorIterator& rhs) const
		{
			return (mPtr >= rhs.mPtr);
		}
		VectorIterator&		operator+=(difference_type n)
		{
			mPtr += n;
			return (*this);
		}
		VectorIterator&		operator-=(difference_type n)
		{
			mPtr -= n;
			return (*this);
		}
		reference			operator[](difference_type n)
		{
			return (mPtr[n]);
		}
		const_reference		operator[](difference_type n) const //const iterator | const_iterator
		{
			return (mPtr[n]);
		}
	};
	// n + iter, but n - iter is not exist
	template <typename T>
	VectorIterator<T>
	operator+(typename VectorIterator<T>::difference_type lhs, const VectorIterator<T>& rhs)
	{
		return (rhs.operator+(lhs));
	}



	// reverse iterator (for vector)
	template <typename Iter>
	class ReverseVectorIterator : public Iter
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

		ReverseVectorIterator()
			: Iter()
		{

		}
		ReverseVectorIterator(pointer ptr)
			: Iter(ptr)
		{

		}
		ReverseVectorIterator(const iterator_type& iter)
			: Iter(iter)
		{

		}
		ReverseVectorIterator(const ReverseVectorIterator& other)
			: Iter(other)
		{

		}
		template <typename NON_CONST>
		ReverseVectorIterator(const ReverseVectorIterator<NON_CONST>& other)
			: Iter(other)
		{

		}
		virtual ~ReverseVectorIterator()
		{

		}
		ReverseVectorIterator&	operator=(const ReverseVectorIterator& rhs)
		{
			Iter::operator=(rhs);
			return (*this);
		}
		template <typename NON_CONST>
		ReverseVectorIterator&	operator=(const ReverseVectorIterator<NON_CONST>& rhs)
		{
			Iter::operator=(rhs);
			return (*this);
		}

		ReverseVectorIterator&	operator++()	// prefix ++iter
		{
			--Iter::mPtr;
			return (*this);
		}
		ReverseVectorIterator		operator++(int)	// postfix iter++
		{
			ReverseVectorIterator tmp(*this);
			Iter::mPtr--;
			return (tmp);
		}
		ReverseVectorIterator&	operator--()	// prefix --iter
		{
			++Iter::mPtr;
			return (*this);
		}
		ReverseVectorIterator		operator--(int)	// postfix iter--
		{
			ReverseVectorIterator	tmp(*this);
			Iter::mPtr++;
			return (tmp);
		}
		ReverseVectorIterator		operator+(difference_type n) const	// iter + n
		{
			ReverseVectorIterator	tmp(Iter::mPtr - n);
			return (tmp);
		}
		ReverseVectorIterator		operator-(difference_type n) const	// iter - n
		{
			ReverseVectorIterator tmp(Iter::mPtr + n);
			return (tmp);
		}
		difference_type		operator-(const ReverseVectorIterator& rhs) const // iter1 - iter2
		{
			return (rhs.Iter::mPtr - Iter::mPtr);
		}
		bool				operator<(const ReverseVectorIterator& rhs) const
		{
			return (Iter::mPtr > rhs.Iter::mPtr);
		}
		bool				operator>(const ReverseVectorIterator& rhs) const
		{
			return (Iter::mPtr < rhs.Iter::mPtr);
		}
		bool				operator<=(const ReverseVectorIterator& rhs) const
		{
			return (Iter::mPtr >= rhs.Iter::mPtr);
		}
		bool				operator>=(const ReverseVectorIterator& rhs) const
		{
			return (Iter::mPtr <= rhs.Iter::mPtr);
		}
		ReverseVectorIterator&	operator+=(difference_type n)
		{
			Iter::mPtr -= n;
			return (*this);
		}
		ReverseVectorIterator&	operator-=(difference_type n)
		{
			Iter::mPtr += n;
			return (*this);
		}
	};
}

#endif