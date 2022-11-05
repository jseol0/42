/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 22:42:56 by heryu             #+#    #+#             */
/*   Updated: 2022/11/05 13:20:13 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "Vector.hpp"
# include <csignal>

namespace ft
{
	template <typename T, typename Container = ft::Vector<T> >
	class Stack
	{
	public:
		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;

	protected:
		container_type		c;

	public:
		explicit Stack(const container_type& ctnr = container_type())
			: c(ctnr)
		{

		}

		bool empty() const
		{
			return (c.empty());
		}

		size_type size() const
		{
			return (c.size());
		}

		value_type&			top()
		{
			if (empty())
				raise(SIGSEGV);
			return (c.back());
		}
		const value_type&	top() const
		{
			if (empty())
				raise(SIGSEGV);
			return (c.back());
		}

		void	push(const value_type& val)
		{
			c.push_back(val);
		}

		void	pop(void)
		{
			c.pop_back();
		}

		template <class type, class container>
		friend bool operator==(const Stack<type,container>& lhs, const Stack<type,container>& rhs);
		template <class type, class container>
		friend bool operator!=(const Stack<type,container>& lhs, const Stack<type,container>& rhs);
		template <class type, class container>
		friend bool operator<(const Stack<type,container>& lhs, const Stack<type,container>& rhs);
		template <class type, class container>
		friend bool operator>(const Stack<type,container>& lhs, const Stack<type,container>& rhs);
		template <class type, class container>
		friend bool operator<=(const Stack<type,container>& lhs, const Stack<type,container>& rhs);
		template <class type, class container>
		friend bool operator>=(const Stack<type,container>& lhs, const Stack<type,container>& rhs);

	};

	template <class T, class Container>
	bool operator==(const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)
	{
		return (ft::operator==(lhs.c, rhs.c));
	}

	template <class T, class Container>
	bool operator!=(const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)
	{
		return (ft::operator!=(lhs.c, rhs.c));
	}

	template <class T, class Container>
	bool operator<(const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)
	{
		return (ft::operator<(lhs.c, rhs.c));
	}

	template <class T, class Container>
	bool operator>(const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)
	{
		return (ft::operator>(lhs.c, rhs.c));
	}

	template <class T, class Container>
	bool operator<=(const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)
	{
		return (ft::operator<=(lhs.c, rhs.c));
	}

	template <class T, class Container>
	bool operator>=(const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)
	{
		return (ft::operator>=(lhs.c, rhs.c));
	}
}

#endif
