/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:57:15 by jseol             #+#    #+#             */
/*   Updated: 2022/08/15 23:54:32 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	{
		// subject test
		std::cout << "===== subject test =====" << std::endl;
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl; // 17

		mstack.pop();

		std::cout << mstack.size() << std::endl; // 1

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl; // 5 3 5 737 0
			++it;
		}
		std::stack<int> s(mstack);
	}
		// my test
	std::cout << std::endl;
	{
		//list test
		std::cout << "===== list test =====" << std::endl;
		std::list<int>	list;

		list.push_back(5);
		list.push_back(17);

		std::cout << list.back() << std::endl;

		list.pop_back();

		std::cout << list.size() << std::endl;

		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		list.push_back(0);

		std::list<int>::iterator itlist = list.begin();
		std::list<int>::iterator itliste = list.end();

		++itlist;
		--itlist;

		while(itlist != itliste)
		{
			std::cout << *itlist << std::endl;
			++itlist;
		}
	}
	{
		// normal iterator
		std::cout << "===== normal iterator test =====" << std::endl;
		MutantStack<int> s;
		for (int i = 0; i < 5; ++i)
			s.push(i + 1);

		MutantStack<int>::iterator it = s.begin();
		MutantStack<int>::iterator ite = s.end();
		*it = 777;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << std::endl;
		
		// coppy constructor
		std::cout << "===== coppy constructor test =====" << std::endl;
		std::stack<int> s2(s);
		while (!s2.empty())
		{
			std::cout << s2.top() << std::endl;
			s2.pop();
		}
		std::cout << std::endl;
	}
	{
		// reverse_iterator
		std::cout << "===== reverse_iterator test =====" << std::endl;
		MutantStack<int> s;
		for (int i = 0; i < 5; ++i)
			s.push(i + 1);

		MutantStack<int>::reverse_iterator it = s.rbegin();
		MutantStack<int>::reverse_iterator ite = s.rend();
		*it = 777;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << std::endl;
	}

	// while(1);

	return 0;
}
