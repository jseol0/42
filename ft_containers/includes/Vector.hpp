/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:59:18 by jseol             #+#    #+#             */
/*   Updated: 2022/11/04 11:10:43 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <limits>
# include "VectorIterator.hpp"
# include "Data.hpp"

namespace ft
{
	template <typename T>
	T	max(const T& a, const T& b)
	{
		if (a < b)
			return (b);
		else
			return (a);
	}

	template <typename T, typename Alloc = std::allocator<T> >
	class Vector
	{
	public:
		typedef	T											value_type;
		typedef	Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;

		typedef ft::VectorIterator<T>						iterator;
		typedef ft::VectorIterator<const T>					const_iterator;
		typedef ft::ReverseVectorIterator<iterator>			reverse_iterator;
		typedef ft::ReverseVectorIterator<const_iterator>	const_reverse_iterator;

		typedef ptrdiff_t									diffrence_type;
		typedef size_t										size_type;

	private:
		pointer			mContainer;
		size_type		mSize;
		size_type		mCapacity;
		allocator_type	mAlloc;

		void	__init(size_type n, const value_type& val, __false)
		{
			mSize = n;
			mCapacity = mSize;
			mContainer = mAlloc.allocate(mCapacity);
			for (size_type i = 0; i < mSize; ++i)
			{
				mAlloc.construct(mContainer + i, val);
			}
		}
		template <typename InputIterator>
		void	__init(InputIterator first, InputIterator last, __true)
		{
			if (last - first < 0)
				throw std::length_error("vector construct length error");
			mSize = last - first;
			mCapacity = mSize;
			mContainer = mAlloc.allocate(mCapacity);
			for (size_type i = 0; i < mSize; ++i)
			{
				mAlloc.construct(mContainer + i, *first++);
			}
		}

		void __assign(size_type n, const value_type& val, __false)
		{
			if (mSize == n)
				return ;
			reserve(n); // ignored if mCapacity >= n
			for (size_type i = n; i < mSize; ++i)
				mAlloc.destroy(mContainer + i);
			mSize = n;
			for (size_type i = 0; i < mSize; ++i)
				mAlloc.construct(mContainer + i, val);
		}
		template <typename InputIterator>
		void __assign(InputIterator first, InputIterator last, __true)
		{
			if (last - first < 0)
				throw std::length_error("assign length error");
			size_type n = last - first;
			if (mSize == n)
				return ;
			reserve(n);
			for (size_type i = n; i < mSize; ++i)
				mAlloc.destroy(mContainer + i);
			mSize = n;
			for (size_type i = 0; i < mSize; ++i)
				mAlloc.construct(mContainer + i, *first++);
		}

		void __insert(iterator position, size_type n, const value_type& val, __false)
		{
			if (mSize + n > mCapacity)
			{
				size_type originCapacity = mCapacity;
				mCapacity = ft::max(mCapacity * 2, mSize + n);
				pointer tmp = mAlloc.allocate(mCapacity);
				iterator iter_begin = begin();
				size_type i = 0;
				for (; i < static_cast<size_type>(position - iter_begin); ++i)
					mAlloc.construct(tmp + i, mContainer[i]);
				for (size_type j = 0; j < n; ++j)
					mAlloc.construct(tmp + i + j, val);
				for (; i < mSize; ++i)
					mAlloc.construct(tmp + i + n, mContainer[i]);

				for (i = 0; i < mSize; ++i)
					mAlloc.destroy(mContainer + i);
				mAlloc.deallocate(mContainer, originCapacity);
				mContainer = tmp;
			}
			else
			{
				for (iterator iter = end() - 1 + n; iter != position + n - 1; --iter)
					*iter = *(iter - n);
				for (size_type i = 0; i < n; ++i)
					mAlloc.construct(&(*(position + i)), val);
			}
			mSize += n;
		}
		template <class InputIterator>
		void __insert(iterator position, InputIterator first, InputIterator last, __true)
		{
			size_type n = static_cast<size_type>(last - first);
			if (mSize + n > mCapacity)
			{
				size_type originCapacity = mCapacity;
				mCapacity = ft::max(mCapacity * 2, mSize + n);
				pointer tmp = mAlloc.allocate(mCapacity);
				iterator iter_begin = begin();
				size_type i = 0;
				for (; i < static_cast<size_type>(position - iter_begin); ++i)
					mAlloc.construct(tmp + i, mContainer[i]);
				for (size_type j = 0; j < n; ++j)
					mAlloc.construct(tmp + i + j, *(first + j));
				for (; i < mSize; ++i)
					mAlloc.construct(tmp + i + n, mContainer[i]);

				for (i = 0; i < mSize; ++i)
					mAlloc.destroy(mContainer + i);
				mAlloc.deallocate(mContainer, originCapacity);
				mContainer = tmp;
			}
			else
			{
				for (iterator iter = end() - 1 + n; iter != position + n - 1; --iter)
					*iter = *(iter - n);
				for (size_type i = 0; i < n; ++i)
					mAlloc.construct(&(*(position + i)), *(first + i));
			}
			mSize += n;
		}


	public:
		// copliens form
		explicit	Vector(const allocator_type& alloc = allocator_type())
			: mContainer(0), mSize(0), mCapacity(0), mAlloc(alloc)
		{

		}
		explicit	Vector(size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type())
			: mAlloc(alloc)
		{
			__init(n, val, __false());
		}

		template <typename InputIterator>
		Vector(InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type())
			: mAlloc(alloc)
		{
			__init(first, last, typename is_iterator<InputIterator>::val());
		}

		Vector(const Vector& other)
			: mContainer(0)
		{
			*this = other;
		}

		~Vector()
		{
			for (size_type i = 0; i < mSize; ++i)
			{
				mAlloc.destroy(mContainer + i);
			}
			mAlloc.deallocate(mContainer, mCapacity);
		}

		Vector&	operator=(const Vector& rhs)
		{
			if (this != &rhs)
			{
				if (mContainer != 0)
				{
					for (size_type i = 0; i < mSize; ++i)
					{
						mAlloc.destroy(mContainer + i);
					}
					mAlloc.deallocate(mContainer, mCapacity);
				}
				mAlloc = rhs.mAlloc;
				mSize = rhs.mSize;
				mCapacity = rhs.mSize;
				mContainer = mAlloc.allocate(mCapacity);
				for (size_type i = 0; i < mSize; ++i)
				{
					mContainer[i] = rhs.mContainer[i];
				}
			}
			return (*this);
		}

		// iterator
		iterator				begin()
		{
			return (iterator(mContainer));
		}
		const_iterator			begin() const
		{
			return (const_iterator(mContainer));
		}

		iterator				end()
		{
			return (iterator(mContainer + mSize));
		}
		const_iterator			end() const
		{
			return (const_iterator(mContainer + mSize));
		}

		reverse_iterator		rbegin()
		{
			return (reverse_iterator(mContainer + mSize - 1));
		}
		const_reverse_iterator	rbegin() const
		{
			return (const_reverse_iterator(mContainer + mSize - 1));
		}

		reverse_iterator		rend()
		{
			return (reverse_iterator(mContainer - 1)); // 생성자 호출
		}
		const_reverse_iterator	rend() const
		{
			return (const_reverse_iterator(mContainer - 1));
		}

		// capacity
		size_type	size() const
		{
			return (mSize);
		}

		size_type	max_size() const
		{
			return (ULONG_MAX / sizeof(T));
		}

		void		resize(size_type n, value_type val = value_type())
		{
			if (mSize > n)
			{
				for (size_type i = n; i < mSize; ++i)
					mAlloc.destroy(mContainer + i);
			}
			else if (mSize < n)
			{
				if (n <= mCapacity)
				{
					for (size_type i = mSize; i < n; ++i)
						mAlloc.construct(mContainer + i, val);
				}
				// mCapacity : 5
				// n : 6 -> doubling
				// n : 11 -> doubling X 11
				else // N or capacity doubling
				{
					size_type newCapacity = ft::max(n, mCapacity * 2);
					reserve(newCapacity);
					for (size_type i = mSize; i < n; ++i)
						mAlloc.construct(mContainer + i, val);
				}
			}
			mSize = n;
		}

		size_type	capacity() const
		{
			return (mCapacity);
		}

		bool		empty() const
		{
			return (mSize == 0);
		}

		void		reserve(size_type n)
		{
			if (mCapacity >= n)
				return ;
			pointer	tmp = mAlloc.allocate(n);
			for (size_type i = 0; i < mSize; ++i)
			{
				mAlloc.construct(tmp + i, mContainer[i]);
				mAlloc.destroy(mContainer + i);
				// tmp[i] = mContainer[i]; // more effective...
			}
			mAlloc.deallocate(mContainer, mCapacity);
			mContainer = tmp;
			mCapacity = n;
		}

		// element access
		reference 		operator[](size_type n)
		{
			return (mContainer[n]);
		};
		const_reference operator[](size_type n) const
		{
			return (mContainer[n]);
		};

		reference		at(size_type n)
		{	// A similar member function operator[], but at has exception
			if (n < 0 || mSize <= n)
				throw std::out_of_range("Vector::at(n), out of range...");
			return (mContainer[n]);
		}
		const_reference	at(size_type n) const
		{
			if (n < 0 || mSize <= n)
				throw std::out_of_range("Vector::at(n), out of range...");
			return (mContainer[n]);
		}

		reference		front()
		{
			return (mContainer[0]);
		}
		const_reference	front() const
		{
			return (mContainer[0]);
		}

		reference		back()
		{
			return (mContainer[mSize - 1]);
		}
		const_reference back() const
		{
			return (mContainer[mSize - 1]);
		}

		// modifier
		template <class InputIterator>
		void	assign(InputIterator first, InputIterator last)
		{
			__assign(first, last, typename is_iterator<InputIterator>::val());
		}
		void	assign(size_type n, const value_type& val)
		{
			__assign(n, val, __false());
		}

		void	push_back(const value_type& val)
		{
			if (mSize == mCapacity)
				reserve(ft::max(mCapacity * 2, static_cast<size_type>(1)));
			mAlloc.construct(mContainer + mSize, val);
			mSize++;
		}

		void	pop_back()
		{
			if (!empty())
			{
				mAlloc.destroy(mContainer + mSize - 1);
				mSize--;
			}
		}

		iterator insert(iterator position, const value_type& val)
		{
			diffrence_type distance = &(*position) - mContainer;
			if (mSize == mCapacity) // doubling
			{
				size_type originCapacity = mCapacity;
				mCapacity = ft::max(mCapacity * 2, static_cast<size_type>(1));
				pointer tmp = mAlloc.allocate(mCapacity);
				iterator iter_begin = begin();
				size_type i = 0;
				for (; i < static_cast<size_type>(position - iter_begin); ++i)
					mAlloc.construct(tmp + i, mContainer[i]);
				mAlloc.construct(tmp + i, val);
				for (; i < mSize; ++i)
					mAlloc.construct(tmp + 1 + i, mContainer[i]);

				for (i = 0; i < mSize; ++i)
					mAlloc.destroy(mContainer + i);
				mAlloc.deallocate(mContainer, originCapacity);
				mContainer = tmp;
			}
			else
			{
				for (iterator iter = end(); iter != position; --iter)
					*iter = *(iter - 1);
				mAlloc.construct(&(*position), val);
			}
			mSize++;
			return (iterator(mContainer + distance));
		}
		void insert(iterator position, size_type n, const value_type& val)
		{
			__insert(position, n, val, __false());
		}
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last)
		{
			__insert(position, first, last, typename ft::is_iterator<InputIterator>::val());
		}

		iterator erase(iterator position)
		{
			iterator endPos = end();

			mAlloc.destroy(&(*position));
			mSize--;
			for (iterator it = position; it != endPos - 1; ++it)
				*it = *(it + 1);
			return (position);
		}
		iterator erase (iterator first, iterator last)
		{
			iterator originEndPos = end();
			for (iterator del = first; del != last; del++) // first > last 인 경우 undefined
			{
				mAlloc.destroy(&(*del));
				mSize--;
			}
			size_type deleteCount = last - first;
			for (iterator it = first; it != originEndPos - deleteCount; ++it)
				*it = *(it + deleteCount);
			return (first);
		}

		void	swap(Vector& x)
		{
			if (this == &x)
				return ;
			// there is no need to reallocate by operator= and copy()
			pointer			tmp_container = x.mContainer;
			size_type		tmp_size = x.mSize;
			size_type		tmp_capacity = x.mCapacity;
			allocator_type	tmp_alloc = x.mAlloc;

			x.mContainer = mContainer;
			x.mSize = mSize;
			x.mCapacity = mCapacity;
			x.mAlloc = mAlloc;

			mContainer = tmp_container;
			mSize = tmp_size;
			mCapacity = tmp_capacity;
			mAlloc = tmp_alloc;
		}
		void	clear()
		{
			while (!empty())
				pop_back();
		}
	};

	// non-member functions
	template <class T, class Alloc>
	bool operator==(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename Vector<T, Alloc>::const_iterator lhs_iter = lhs.begin();
		typename Vector<T, Alloc>::const_iterator rhs_iter = rhs.begin();
		size_t size = lhs.size();
		for (size_t i = 0; i < size; ++i)
		{
			if (*lhs_iter != *rhs_iter)
				return (false);
			++lhs_iter;
			++rhs_iter;
		}
		return (true);
	}

	template <class T, class Alloc>
	bool operator!=(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator<(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
	{
		typename Vector<T, Alloc>::const_iterator l_first = lhs.begin();
		typename Vector<T, Alloc>::const_iterator l_last = lhs.end();
		typename Vector<T, Alloc>::const_iterator r_first = rhs.begin();
		typename Vector<T, Alloc>::const_iterator r_last = rhs.end();
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

	template <class T, class Alloc>
	bool operator>(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator<=(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T, class Alloc>
	bool operator>=(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
	void swap(Vector<T,Alloc>& x, Vector<T,Alloc>& y)
	{
		x.swap(y);
	}
}

#endif
