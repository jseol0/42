/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:12:14 by jseol             #+#    #+#             */
/*   Updated: 2022/11/12 21:09:22 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>

namespace ft
{
	template <class Category, class T, class Distance = ptrdiff_t,
				class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};

	struct input_iterator_tag { };
	struct output_iterator_tag { };
	struct forward_iterator_tag : public input_iterator_tag { };
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };


	//	iterator_traits

	template <class Iterator>
	class iterator_traits
	{
	public:
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template <class T>
	class iterator_traits<T*>
	{
	public:
		typedef ptrdiff_t					difference_type;
		typedef T							value_type;
		typedef T*							pointer;
		typedef T&							reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	template <class T>
	class iterator_traits<const T*>
	{
	public:
		typedef ptrdiff_t					difference_type;
		typedef T							value_type;
		typedef const T*					pointer;
		typedef const T&					reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	template<typename InputIterator>
	typename iterator_traits<InputIterator>::difference_type
		distance(InputIterator first, InputIterator last)
	{
		typename iterator_traits<InputIterator>::difference_type n = 0;

		while (first++ != last)
			n++;
		return (n);
	}


	//	Vector_iterator

	template <typename T>
	class Vector_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
	{

	public:
		typedef ft::iterator<ft::random_access_iterator_tag, T>			Iterator;
		typedef typename iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename iterator_traits<Iterator>::value_type			value_type;
		typedef typename iterator_traits<Iterator>::pointer				pointer;
		typedef typename iterator_traits<Iterator>::reference			reference;
		typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;

	//canonical
		Vector_iterator(void) : _base() {}

		Vector_iterator(pointer it) : _base(it) {}

		Vector_iterator(const Vector_iterator& rhs) : _base(rhs._base) {}

		Vector_iterator &operator=(const Vector_iterator& rhs)
		{
			if (this == &rhs)
				return (*this);
			this->_base = rhs._base;
			return (*this);
		}

		~Vector_iterator() {}

	//member funcs
		pointer base() const 
		{
			return (this->_base);
		}

		reference operator*(void) const
		{
			return (*_base);
		}

		pointer operator->(void)
		{
			return &(this->operator*());
		}

		Vector_iterator& operator++(void)
		{
			_base++;
			return (*this);
		}

		Vector_iterator operator++(int)
		{
			Vector_iterator it(*this);
			_base++;
			return (it);
		}

		Vector_iterator& operator--(void)
		{
			_base--;
			return (*this);
		}

		Vector_iterator operator--(int)
		{
			Vector_iterator it(*this);
			_base--;
			return (it);
		}

		Vector_iterator operator+(difference_type n) const
		{
			return (_base + n);
		}

		Vector_iterator operator-(difference_type n) const
		{
			return (_base - n);
		}

		Vector_iterator& operator+=(difference_type n)
		{
			_base += n;
			return (*this);
		}

		Vector_iterator& operator-=(difference_type n)
		{
			_base -= n;
			return (*this);
		}

		reference operator[](difference_type n)
		{
			return (*(operator+(n)));
		}

		operator Vector_iterator<const T> () const
		{
			return (Vector_iterator<const T>(this->_base));
		}

		private:
			pointer _base;
	};

	template<typename Iterator1, typename Iterator2>
	bool	operator==(const Vector_iterator<Iterator1> lhs,
				const Vector_iterator<Iterator2> rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template<typename Iterator1, typename Iterator2>
	bool	operator!=(const Vector_iterator<Iterator1> lhs,
				const Vector_iterator<Iterator2> rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template<typename Iterator1, typename Iterator2>
	bool	operator<(const Vector_iterator<Iterator1> lhs,
				const Vector_iterator<Iterator2> rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template<typename Iterator1, typename Iterator2>
	bool	operator>(const Vector_iterator<Iterator1> lhs,
				const Vector_iterator<Iterator2> rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template<typename Iterator1, typename Iterator2>
	bool	operator<=(const Vector_iterator<Iterator1> lhs,
				const Vector_iterator<Iterator2> rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template<typename Iterator1, typename Iterator2>
	bool	operator>=(const Vector_iterator<Iterator1> lhs,
					const Vector_iterator<Iterator2> rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template<typename T>
	Vector_iterator<T>
		operator+(
				typename Vector_iterator<T>::difference_type n,
				Vector_iterator<T>& it)
		{
			return (&(*it) + n);
		}

	template<typename Iterator1, typename Iterator2>
	typename Vector_iterator<Iterator1>::difference_type
		operator-(const Vector_iterator<Iterator1> lhs,
				const Vector_iterator<Iterator2> rhs)
	{
		return (lhs.base() - rhs.base());
	}



	//	reverse_iterator

	template <class Iterator>
	class reverse_iterator
	{
	public:
	//typedef
		typedef Iterator												iterator_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
		typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename ft::iterator_traits<Iterator>::reference			reference;
		typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;

	//constructors & destructor & copy assign
		reverse_iterator() : _base() {}

		explicit reverse_iterator(iterator_type it) : _base(it) {}

		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter>& rev_base) : _base(rev_base.base()) {}
		
		~reverse_iterator() {}

		template <class Iter>
		reverse_iterator & operator=(const reverse_iterator<Iter>& rev_base) 
		{
			this->_base = rev_base.base();
			return (*this);
		}
	
	//other member funcs
		iterator_type base() const 
		{
			return (this->_base);
		}

		reference operator*() const
		{
			iterator_type	it(this->_base);

			return (*--it);
		}

		reverse_iterator operator+(difference_type n) const
		{
			return (reverse_iterator(this->_base - n));
		}

		reverse_iterator& operator++()
		{
			--this->_base;
			return(*this);
		}

		reverse_iterator  operator++(int)
		{
			reverse_iterator	tmp(*this);

			--this->_base;
			return (tmp);
		}

		reverse_iterator& operator+=(difference_type n)
		{
			this->_base -= n;
			return (*this);
		}

		reverse_iterator operator-(difference_type n) const
		{
			return (reverse_iterator(this->_base + n));
		}

		reverse_iterator& operator--()
		{
			++this->_base;
			return(*this);
		}

		reverse_iterator  operator--(int)
		{
			reverse_iterator	tmp(*this);

			++this->_base;
			return (tmp);
		}

		reverse_iterator& operator-=(difference_type n)
		{
			this->_base += n;
			return (*this);
		}

		pointer operator->()
		{
			return (&(operator*()));
		}

		const pointer operator->() const
		{
			return (&(operator*()));
		}

		reference operator[] (difference_type n)
		{
			return *(this->_base - n - 1);
		}

	private:
		iterator_type	_base;
	};

	//reverse_iterator non member funcs
	template <class Iterator1, class Iterator2>
	bool operator==(const reverse_iterator<Iterator1>& lhs,
					const reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator!=(const reverse_iterator<Iterator1>& lhs,
					const reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator<(const reverse_iterator<Iterator1>& lhs,
					const reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator<=(const reverse_iterator<Iterator1>& lhs,
					const reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator>(const reverse_iterator<Iterator1>& lhs,
					const reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator>=(const reverse_iterator<Iterator1>& lhs,
					const reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <class Iterator>
	reverse_iterator<Iterator>
		operator+(
			typename reverse_iterator<Iterator>::difference_type n,
			const reverse_iterator<Iterator>& rev_base)
	{
		return (rev_base + n); 
	}

	template <class Iterator1, class Iterator2>
	typename reverse_iterator<Iterator1>::difference_type
		operator-(
			const reverse_iterator<Iterator1>& lhs,
			const reverse_iterator<Iterator2>& rhs)
	{
		return (rhs.base() - lhs.base());
	}

}

#endif