/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:57:12 by jseol             #+#    #+#             */
/*   Updated: 2022/08/15 19:27:23 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iterator>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void) {}
		MutantStack(const MutantStack<T>& other)
		{
			*this = other;
		}
		~MutantStack() {}

		MutantStack<T>& operator=(const MutantStack<T> & rhs)
		{
			if (this == rhs)
				return (*this);
			std::stack<T>::operator=(rhs);
			return (*this);
		}

		typedef typename std::stack<T>::container_type::iterator			iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator	reverse_iterator;

		iterator begin() {return (std::stack<T>::c.begin());}
		iterator end() {return (std::stack<T>::c.end());}

		reverse_iterator rbegin() {return (std::stack<T>::c.rbegin());}
		reverse_iterator rend() {return (std::stack<T>::c.rend());}
};

#endif