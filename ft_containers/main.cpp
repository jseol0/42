/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:57:42 by jseol             #+#    #+#             */
/*   Updated: 2022/11/12 19:45:19 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "includes/Map.hpp"
#include "includes/Stack.hpp"
#include "includes/Vector.hpp"


template <typename MapType>
void	printMap(MapType const &mp)
{
	std::cout << std::endl;
	std::cout << "---print start-----" << std::endl;
	std::cout << "size: " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
	std::cout << "empty: " << mp.empty() << std::endl;

	typename MapType::const_iterator it = mp.begin(), ite = mp.end();
	std::cout << std::endl << "Content:" << std::endl;
	for (; it != ite; ++it)
		std::cout << "-> key: " << (*it).first << "value: " << (*it).second << std::endl;
	std::cout << "---print end-----" << std::endl;
	std::cout << std::endl;
}

template <typename VECTYPE>
void	printVec(VECTYPE const &s)
{
	std::cout << std::endl;
	std::cout << "---print start-----" << std::endl;
	std::cout << "size: " << s.size() << std::endl;
	std::cout << "max_size: " << s.max_size() << std::endl;
	std::cout << "empty: " << s.empty() << std::endl;
	std::cout << "capacity: " << s.capacity() << std::endl;

	typename VECTYPE::const_iterator it = s.begin(), ite = s.end();
	std::cout << std::endl << "Content:" << std::endl;
	for (; it != ite; ++it)
		std::cout << "-> value: " << *it << std::endl;
	std::cout << "---print end-----" << std::endl;
	std::cout << std::endl;
}

int main()
{
	std::cout << "====================== Vec/Stack ==========================="<< std::endl;
	
	ft::vector<float> vec;
	printVec(vec);
	vec.resize(9, 2.9);
	printVec(vec);
	vec.reserve(30);
	printVec(vec);
	std::cout << vec.back() << std::endl;
	std::cout << vec.front() << std::endl;
	vec.pop_back();

	ft::vector<float> vec2(vec);
	printVec(vec2);
	vec.insert(vec.begin() + 3, vec2.begin(), vec2.end());
	printVec(vec);
	vec.erase(vec.begin() + 5, vec.end());
	printVec(vec);

	ft::vector<ft::pair<int, char> > vec3;
	vec3.insert(vec3.begin(), 6, ft::make_pair(9, 'u'));
	ft::vector<ft::pair<int, char> >::const_iterator it = vec3.begin(), ite = vec3.end();
	std::cout << std::endl << "Content:" << std::endl;
	for (; it != ite; ++it)
		std::cout << "-> key: " << (*it).first << "value: " << (*it).second << std::endl;
	std::cout << std::endl;

	ft::stack<unsigned long> stack;
	std::cout << stack.empty() << std::endl;
	stack.push(1);
	stack.push(4);
	stack.push(9);
	stack.push(7);
	stack.push(3);
	std::cout << stack.top() << std::endl;
	stack.pop();
	std::cout << stack.top() << std::endl;
	stack.pop();
	std::cout << stack.top() << std::endl;
	std::cout << stack.size() << std::endl;
	std::cout << stack.empty() << std::endl;

	std::cout << "======================== Map ================================"<< std::endl;

	ft::map<int, int> myMap0;
	std::cout << "ft::map<int, int> myMap0;" << std::endl;
	std::cout << std::endl;
	std::cout << "myMap0.empty() = " << myMap0.empty() << std::endl;
	std::cout << "myMap0.size() =  " << myMap0.size() << std::endl;
	std::cout << "myMap0.max_size() =  " << myMap0.max_size() << std::endl;
	std::cout << "myMap0.clear()" << std::endl;  myMap0.clear();
	std::cout << "myMap0[0] =  " << myMap0[0] << std::endl;
	std::cout << "myMap0.insert(ft::make_pair(3, 9))" << std::endl; myMap0.insert(ft::make_pair(3, 9));
	std::cout << "myMap0.size() = " << myMap0.size() << std::endl;
	std::cout << "myMap0.clear() " << std::endl;  myMap0.clear();
	std::cout << "myMap0.size() = " << myMap0.size() << std::endl;

	myMap0.insert(ft::make_pair(3, 30));
	myMap0.insert(ft::make_pair(2, 20));
	myMap0.insert(ft::make_pair(9, 90));
	myMap0.insert(ft::make_pair(7, 70));
	myMap0.insert(ft::make_pair(-1, -10));
	printMap(myMap0);

	std::cout << "myMap0.find(7)->second: " << myMap0.find(7)->second << std::endl;	
	std::cout << "(myMap0.find(4) == myMap0.end()): " << (myMap0.find(4) == myMap0.end()) << std::endl;

	myMap0[5] = 50;
	printMap(myMap0);

	std::cout << "myMap0.lower_bound(5)->first: " << myMap0.lower_bound(5)->first << std::endl;
	std::cout << "myMap0.upper_bound(5)->first: " << myMap0.upper_bound(5)->first << std::endl;


	//erase non-existed value
	myMap0.erase(4);
	printMap(myMap0);

	myMap0.erase(5);
	printMap(myMap0);

	myMap0.erase(myMap0.begin(), myMap0.begin()++);
	printMap(myMap0);

	myMap0.clear();
	printMap(myMap0);

	std::cout << std::endl;
	std::cout << "TEST END" << std::endl;
}
