/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:14:49 by heryu             #+#    #+#             */
/*   Updated: 2022/11/04 20:11:35 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

std::pair<std::string, int> arr[] = {
		std::make_pair("D_Kim", 25),
		std::make_pair("E_Lee", 20),
		std::make_pair("B_Park", 18),
		std::make_pair("C_Choi", 31),
		std::make_pair("A_Jeong", 42)
};
//int arr2[] = { 100, 50, 150, 25, 75, 125, 175, 15, 35, 60, 85, 110, 130, 155, 200 };
std::pair<int, int> arr2[] = {
		std::make_pair(100, 100),
		std::make_pair(50, 50),
		std::make_pair(150, 150),
		std::make_pair(25, 25),
		std::make_pair(75, 75),
		std::make_pair(125, 125),
		std::make_pair(175, 175),
		std::make_pair(15, 15),
		std::make_pair(35, 35),
		std::make_pair(60, 60),
		std::make_pair(85, 85),
		std::make_pair(110, 110),
		std::make_pair(130, 130),
		std::make_pair(155, 155),
		std::make_pair(200, 200),
		std::make_pair(80, 80)
};

template <class K, class T, class C, class A>
bool operator==(const std::map<K,T,C,A>& lhs, const ft::Map<K,T,C,A>& rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	typename std::map<K,T,C,A>::const_iterator lhs_iter = lhs.begin();
	typename ft::Map<K,T,C,A>::const_iterator rhs_iter = rhs.begin();
	size_t size = lhs.size();
	for (size_t i = 0; i < size; ++i)
	{
		if (lhs_iter->first != rhs_iter->first)
			return (false);
		if (lhs_iter->second != rhs_iter->second)
			return (false);
		++lhs_iter;
		++rhs_iter;
	}
	return (true);
}
template <class K, class T, class C, class A>
bool operator!=(const std::map<K,T,C,A>& lhs, const ft::Map<K,T,C,A>& rhs)
{
	return (!(lhs == rhs));
}

template <typename MAP>
static void print_map_elements(const MAP& m)
{
	std::cout << "=== elements (KEY : VALUE) ===" << std::endl;
	for (typename MAP::const_iterator iter = m.begin(); iter != m.end(); ++iter)
	{
		std::cout << "[ " << iter->first << " : " << iter->second << " ]" << std::endl;
	}
}

template <typename MAP>
static void print_map_size(const MAP& m)
{
	std::cout << "-->> size(" << m.size() << ")" << std::endl;
}

template <typename MAP>
static void print_map(const MAP& m)
{
	print_map_elements(m);
	print_map_size(m);
	std::cout << std::endl;
}

static bool construct_test(void)
{
	print_title("map construct test");
	{
	print_interface("explicit Map(const key_compare& comp = key_compare(),\n	const allocator_type& alloc = allocator_type())");
	std::cout << "... made by default construct ...\n";
	std::map<std::string, int> m1;
	ft::Map<std::string, int> m2;
	print_map(m1);
	print_map(m2);
	if (m1 != m2)
		return (FAIL);
	std::cout << std::endl;
	}
	{
	print_interface("template <class InputIterator>\nMap(InputIterator first, InputIterator last,\n	const key_compare& comp = key_compare(),\n	const allocator_type& alloc = allocator_type())\n");
	std::cout << "... range construct by pair array ...\n" << std::endl;
	std::map<std::string, int> m1(arr, arr + 5);
	ft::Map<std::string, int> m2(arr, arr + 5);
	print_map(m1);
	print_map(m2);
	if (m1 != m2)
		return (FAIL);
	std::cout << std::endl;

	print_clear();
	print_title("map construct test");
	print_interface("Map(const Map& other)");
	std::cout << "... map<string, int> copiedMap(originMap) ...\n";
	std::map<std::string, int> m3(m1);
	ft::Map<std::string, int> m4(m2);
	print_map(m3);
	print_map(m4);
	if (m3 != m4)
		return (FAIL);

	print_interface("Map&	operator=(const Map& rhs)");
	std::map<std::string, int> tmp1;
	tmp1["Ryu"] = 25;
	ft::Map<std::string, int> tmp2;
	tmp2["Ryu"] = 25;
	std::cout << "... tmp map: (Ryu, 25) ..." << std::endl;
	print_map(tmp1);

	std::cout << " ... tmpMap = originMap ...\n";
	tmp1 = m1;
	tmp2 = m2;
	print_map(tmp1);
	print_map(tmp2);
	if (tmp1 != tmp2)
		return (FAIL);
	}
	return (SUCCESS);
}

static bool iterator_test(void)
{
	print_title("map iterator test");
	{
	std::map<std::string, int> m1(arr, arr + 5);
	ft::Map<std::string, int> m2(arr, arr + 5);
	print_interface("iterator	begin()");
	print_interface("iterator	end()");
	std::cout << "... print elements by using iterator ..." << std::endl;
	std::cout << "std" << std::endl;
	for (std::map<std::string, int>::iterator iter = m1.begin(); iter != m1.end(); ++iter)
	{
		std::cout << "(" << iter->first << ", " << iter->second << ")" << std::endl;
	}
	std::cout << "\nft" << std::endl;
	for (ft::Map<std::string, int>::iterator iter = m2.begin(); iter != m2.end(); ++iter)
	{
		std::cout << "(" << iter->first << ", " << iter->second << ")" << std::endl;
	}
	std::map<std::string, int>::iterator iter1 = m1.begin();
	ft::Map<std::string, int>::iterator iter2 = m2.begin();
	for (size_t i = 0; i < 5; ++i)
	{
		if (iter1->first != iter2->first)
			return (FAIL);
		if (iter1->second != iter2->second)
			return (FAIL);
		++iter1;
		++iter2;
	}
	std::cout << "\n";
	}
	{
	print_interface("const_iterator	begin() const");
	print_interface("const_iterator	end() const");
	const std::map<std::string, int> m1(arr, arr + 5);
	const ft::Map<std::string, int> m2(arr, arr + 5);
	print_interface("const_iterator	begin()");
	print_interface("const_iterator	end()");
	std::cout << "... print elements by using const_iterator ..." << std::endl;
	std::cout << "std" << std::endl;
	for (std::map<std::string, int>::const_iterator iter = m1.begin(); iter != m1.end(); ++iter)
	{
		std::cout << "(" << iter->first << ", " << iter->second << ")" << std::endl;
	}
	std::cout << "\nft" << std::endl;
	for (ft::Map<std::string, int>::const_iterator iter = m2.begin(); iter != m2.end(); ++iter)
	{
		std::cout << "(" << iter->first << ", " << iter->second << ")" << std::endl;
	}
	std::map<std::string, int>::const_iterator iter1 = m1.begin();
	ft::Map<std::string, int>::const_iterator iter2 = m2.begin();
	for (size_t i = 0; i < 5; ++i)
	{
		if (iter1->first != iter2->first)
			return (FAIL);
		if (iter1->second != iter2->second)
			return (FAIL);
		++iter1;
		++iter2;
		// iter1->second = 1;
		// iter2->second = 1;
	}
	std::cout << "\n";
	}
	print_clear();
	print_title("map iterator test");
	{
	std::map<std::string, int> m1(arr, arr + 5);
	ft::Map<std::string, int> m2(arr, arr + 5);
	print_interface("reverse_iterator	rbegin()");
	print_interface("reverse_iterator	rend()");
	std::cout << "... print elements by using reverse_iterator ..." << std::endl;
	std::cout << "std" << std::endl;
	for (std::map<std::string, int>::reverse_iterator iter = m1.rbegin(); iter != m1.rend(); ++iter)
	{
		std::cout << "(" << iter->first << ", " << iter->second << ")" << std::endl;
	}
	std::cout << "\nft" << std::endl;
	for (ft::Map<std::string, int>::reverse_iterator iter = m2.rbegin(); iter != m2.rend(); ++iter)
	{
		std::cout << "(" << iter->first << ", " << iter->second << ")" << std::endl;
	}
	std::map<std::string, int>::reverse_iterator iter1 = m1.rbegin();
	ft::Map<std::string, int>::reverse_iterator iter2 = m2.rbegin();
	for (size_t i = 0; i < 5; ++i)
	{
		if (iter1->first != iter2->first)
			return (FAIL);
		if (iter1->second != iter2->second)
			return (FAIL);
		++iter1;
		++iter2;
	}
	std::cout << "\n";
	}
	{
	std::map<std::string, int> m1(arr, arr + 5);
	ft::Map<std::string, int> m2(arr, arr + 5);
	print_interface("const_reverse_iterator	rbegin()");
	print_interface("const_reverse_iterator	rend()");
	std::cout << "... print elements by using const_reverse_iterator ..." << std::endl;
	std::cout << "std" << std::endl;
	for (std::map<std::string, int>::const_reverse_iterator iter = m1.rbegin(); iter != m1.rend(); ++iter)
	{
		std::cout << "(" << iter->first << ", " << iter->second << ")" << std::endl;
	}
	std::cout << "\nft" << std::endl;
	for (ft::Map<std::string, int>::const_reverse_iterator iter = m2.rbegin(); iter != m2.rend(); ++iter)
	{
		std::cout << "(" << iter->first << ", " << iter->second << ")" << std::endl;
	}
	std::map<std::string, int>::const_reverse_iterator iter1 = m1.rbegin();
	ft::Map<std::string, int>::const_reverse_iterator iter2 = m2.rbegin();
	for (size_t i = 0; i < 5; ++i)
	{
		if (iter1->first != iter2->first)
			return (FAIL);
		if (iter1->second != iter2->second)
			return (FAIL);
		++iter1;
		++iter2;
		// iter1->second = 1;
		// iter2->second = 1;
	}
	std::cout << "\n";
	}
	return (SUCCESS);
}

static bool capacity_test()
{
	print_title("map capacity test");

	print_interface("bool	empty() const");
	std::cout << std::boolalpha;
	std::cout << " ... current empty ...\n";
	std::map<std::string, int> m1;
	ft::Map<std::string, int> m2;
	std::cout << "std empty: " << m1.empty() << std::endl;
	std::cout << "ft empty: " << m2.empty() << std::endl;
	if (m1.empty() != m2.empty())
		return (FAIL);

	m1["1"] = 1; m1["2"] = 2; m1["3"] = 3; m1["4"] = 4; m1["5"] = 5;
	m2["1"] = 1; m2["2"] = 2; m2["3"] = 3; m2["4"] = 4; m2["5"] = 5;
	std::cout << "\n... After insert value * 5 ...\n";
	std::cout << "std empty: " << m1.empty() << std::endl;
	std::cout << "ft empty: " << m2.empty() << std::endl;
	if (m1.empty() != m2.empty())
		return (FAIL);
	std::cout << "\n";

	print_interface("size_type	size() const");
	std::cout << "std size: " << m1.size() << std::endl;
	std::cout << "ft size: " << m2.size() << std::endl;
	if (m1.size() != m2.size())
		return (FAIL);
	std::cout << "\n";

	std::cout << "... After erase all elements ..." << std::endl;
	m1.erase(m1.begin(), m1.end());
	m2.erase(m2.begin(), m2.end());
	std::cout << "std size: " << m1.size() << std::endl;
	std::cout << "ft size: " << m2.size() << std::endl;
	if (m1.size() != m2.size())
		return (FAIL);
	std::cout << "\n";

	print_interface("size_type	max_size() const");
	std::cout << "... map<bool, bool> ..." << std::endl;
	{
	std::map<bool, bool> tmp1;
	ft::Map<bool, bool> tmp2;
	std::cout << "std max_size: " << tmp1.max_size() << std::endl;
	std::cout << "ft max_size: " << tmp2.max_size() << std::endl;
	if (tmp1.max_size() != tmp2.max_size())
		return (FAIL);
	std::cout << std::endl;
	}
	std::cout << "... map<int, bool> ..." << std::endl;
	{
	std::map<int, bool> tmp1;
	ft::Map<int, bool> tmp2;
	std::cout << "std max_size: " << tmp1.max_size() << std::endl;
	std::cout << "ft max_size: " << tmp2.max_size() << std::endl;
	if (tmp1.max_size() != tmp2.max_size())
		return (FAIL);
	std::cout << std::endl;
	}
	std::cout << "... map<int, double> ..." << std::endl;
	{
	std::map<int, double> tmp1;
	ft::Map<int, double> tmp2;
	std::cout << "std max_size: " << tmp1.max_size() << std::endl;
	std::cout << "ft max_size: " << tmp2.max_size() << std::endl;
	if (tmp1.max_size() != tmp2.max_size())
		return (FAIL);
	std::cout << std::endl;
	}
	std::cout << "... map<string, double> ..." << std::endl;
	{
	std::map<std::string, double> tmp1;
	ft::Map<std::string, double> tmp2;
	std::cout << "std max_size: " << tmp1.max_size() << std::endl;
	std::cout << "ft max_size: " << tmp2.max_size() << std::endl;
	if (tmp1.max_size() != tmp2.max_size())
		return (FAIL);
	std::cout << std::endl;
	}
	std::cout << "... map<long long, long long> ..." << std::endl;
	{
	std::map<long long, long long> tmp1;
	ft::Map<long long, long long> tmp2;
	std::cout << "std max_size: " << tmp1.max_size() << std::endl;
	std::cout << "ft max_size: " << tmp2.max_size() << std::endl;
	if (tmp1.max_size() != tmp2.max_size())
		return (FAIL);
	std::cout << std::endl;
	}
	std::cout << "... map<A, A> ..." << std::endl;
	{
	std::map<A, A> tmp1;
	ft::Map<A, A> tmp2;
	std::cout << "std max_size: " << tmp1.max_size() << std::endl;
	std::cout << "ft max_size: " << tmp2.max_size() << std::endl;
	if (tmp1.max_size() != tmp2.max_size())
		return (FAIL);
	std::cout << std::endl;
	}
	return (SUCCESS);
}

static bool element_access(void)
{
	print_title("map element access test");

	print_interface("mapped_type&	operator[](const key_type& k)");
	std::map<std::string, int> m1;
	ft::Map<std::string, int> m2;
	std::cout << "... just map[\"just_key\"] ..." << std::endl;
	m1["just_key"];
	m2["just_key"];
	print_map(m1);
	print_map(m2);
	if (m1 != m2)
		return (FAIL);

	std::cout << "\n... map[\"just_key\"] = 777 ..." << std::endl;
	m1["just_key"] = 777;
	m2["just_key"] = 777;
	print_map(m1);
	print_map(m2);
	if (m1 != m2)
		return (FAIL);

	std::cout << "\n... map[\"insert_value\"] = 123 ..." << std::endl;
	m1["insert_value"] = 123;
	m2["insert_value"] = 123;
	print_map(m1);
	print_map(m2);
	if (m1 != m2)
		return (FAIL);
	return (SUCCESS);
}

static bool insert_test(void)
{
	print_title("map insert test");

	print_interface("std::pair<iterator, bool> insert(const value_type& val)");
	{
	std::map<std::string, int> m1;
	ft::Map<std::string, int> m2;
	std::cout << "map.insert(std::make_pair(\"duplicated_key\", 777)) * 3 times;" << std::endl;
	m1.insert(std::make_pair("duplicated_key", 777));
	m2.insert(std::make_pair("duplicated_key", 777));
	m1.insert(std::make_pair("duplicated_key", 777));
	m2.insert(std::make_pair("duplicated_key", 777));
	print_map(m1);
	print_map(m2);
	if (m1 != m2)
		return (FAIL);
	std::cout << std::endl;

	std::pair<std::map<std::string, int>::iterator, bool> ret1 = m1.insert(std::make_pair("duplicated_key", 777));
	std::pair<ft::Map<std::string, int>::iterator, bool> ret2 = m2.insert(std::make_pair("duplicated_key", 777));
	std::cout << "... last return value ..." << std::endl;
	std::cout << "std: " << ret1.first->first << ", " << ret1.first->second << ", " << ret1.second << std::endl;
	std::cout << "ft: " << ret2.first->first << ", " << ret2.first->second << ", " << ret2.second << std::endl;
	if (ret1.first->first != ret2.first->first)
		return (FAIL);
	if (ret1.first->second != ret2.first->second)
		return (FAIL);
	if (ret1.second != ret2.second)
		return (FAIL);
	std::cout << std::endl;

	std::cout << "... insert normal values ..." << std::endl;
	m1.insert(std::make_pair("normal1_key", 1));
	m2.insert(std::make_pair("normal1_key", 1));
	m1.insert(std::make_pair("normal2_key", 2));
	m2.insert(std::make_pair("normal2_key", 2));
	m1.insert(std::make_pair("normal3_key", 3));
	m2.insert(std::make_pair("normal3_key", 3));
	print_map(m1);
	print_map(m2);
	if (m1 != m2)
		return (FAIL);
	std::cout << std::endl;

	print_clear();
	print_title("map insert test");
	print_interface("iterator insert(iterator hint, const value_type& val)");
	std::cout << "... insert(map.begin(), pair(hint, 333)) ..." << std::endl;
	std::map<std::string, int>::iterator iter1 = m1.insert(m1.begin(), std::make_pair<std::string, int>("hint", 333));
	ft::Map<std::string, int>::iterator iter2 = m2.insert(m2.begin(), std::make_pair<std::string, int>("hint", 333));
	std::cout << "... return value ..." << std::endl;
	std::cout << "std: " << iter1->first << ":" << iter1->second << std::endl;
	std::cout << "ft: " << iter2->first << ":" << iter2->second << std::endl;
	std::cout << std::endl;
	if (iter1->first != iter2->first)
		return (FAIL);
	if (iter1->second != iter2->second)
		return (FAIL);
	print_map(m1);
	print_map(m2);
	if (m1 != m2)
		return (FAIL);
	std::cout << std::endl;
	}
	{
	print_interface("template <class InputIterator>\nvoid insert (InputIterator first, InputIterator last)");
	std::map<std::string, int> m1;
	ft::Map<std::string, int> m2;
	std::cout << "map.insert(arr, arr + 3)" << std::endl;
	m1.insert(arr, arr + 3);
	m2.insert(arr, arr + 3);
	print_map(m1);
	print_map(m2);
	if (m1 != m2)
		return (FAIL);
	std::cout << std::endl;
	}

	return (SUCCESS);
}

static bool erase_test(void)
{
	print_title("map erase test");

	print_interface("void		erase(iterator position)");
	print_interface("size_type	erase(const key_type& k)");
	std::map<std::string, int> m1; m1["key"] = 1;
	ft::Map<std::string, int> m2; m2["key"] = 1;
	std::cout << "... current map ..." << std::endl;
	print_map(m1);
	std::cout << std::endl;

	std::cout << "... map.erase(begin) ..." << std::endl;
	m1.erase(m1.begin());
	m2.erase(m2.begin());
	print_map(m1);
	print_map(m2);
	if (m1 != m2)
		return (FAIL);
	std::cout << std::endl;

	std::cout << "... map.erase(2) ... (1 > 2 > 3)" << std::endl;
	m1["1"] = 1; m1["2"] = 2; m1["3"] = 3;
	m2["1"] = 1; m2["2"] = 2; m2["3"] = 3;
	m1.erase("2");
	m2.erase("2");
	print_map(m1);
	print_map(m2);
	if (m1 != m2)
		return (FAIL);
	std::cout << std::endl;

	print_clear();
	print_title("map erase test");
	std::cout << "... map.erase(100) ... \n... (100, 50, 150, 25, 75, 125, 175, 15, 35, 60, 85, 110, 130, 155, 200, 80)\n";

	std::map<int, int> m3(arr2, arr2 + 16);
	ft::Map<int, int> m4(arr2, arr2 + 16);
	size_t ret1 = m3.erase(100);
	size_t ret2 = m4.erase(100);
	print_map(m3);
	print_map(m4);
	std::cout << "... erase return value ...\n";
	std::cout << "std:ft = " << ret1 << ":" << ret2 << std::endl;
	if (ret1 != ret2)
		return (FAIL);
	if (m3 != m4)
		return (FAIL);
	std::cout << std::endl;

	print_interface("void	erase(iterator first, iterator last)");
	std::cout << "map.erase(begin, end)" << std::endl;
	m3.erase(m3.begin(), m3.end());
	m4.erase(m4.begin(), m4.end());
	print_map(m3);
	print_map(m4);
	if (m3 != m4)
		return (FAIL);
	return (SUCCESS);
}

static bool swap_clear_test(void)
{
	print_title("map swap clear test");

	print_interface("void	swap(Map& x)");
	std::cout << "... x map ..." << std::endl;
	std::map<std::string, int> m1(arr, arr + 3);
	std::map<std::string, int> m2(arr + 3, arr + 5);
	ft::Map<std::string, int> m3(arr, arr + 3);
	ft::Map<std::string, int> m4(arr + 3, arr + 5);
	print_map(m1);
	std::cout << "... y map ..." << std::endl;
	print_map(m2);
	std::cout << "\n... After swap ...\n" << std::endl;

	m1.swap(m2);
	m3.swap(m4);
	std::cout << "... std x map ..." << std::endl;
	print_map(m1);
	std::cout << "... std y map ..." << std::endl;
	print_map(m2);

	std::cout << "\n... ft  x map ..." << std::endl;
	print_map(m3);
	std::cout << "... ft  y map ..." << std::endl;
	print_map(m4);
	if ((m1 != m3) || (m2 != m4))
		return (FAIL);
	std::cout << std::endl;

	print_clear();
	print_title("map swap clear test");
	print_interface("void	clear()");
	std::cout << "... x map clear ..." << std::endl;
	m1.clear();
	m3.clear();
	std::cout << "... std x map ..." << std::endl;
	print_map(m1);
	std::cout << "\n... ft x map ..." << std::endl;
	print_map(m3);
	if (m1 != m3)
		return (FAIL);
	return (SUCCESS);
}

static bool cmp_func_test(void)
{
	print_title("map compare function test");

	print_interface("key_compare key_comp() const");
	std::map<int, int> m1;
	ft::Map<int, int> m2;
	std::map<int, int>::key_compare kcmp1 = m1.key_comp();
	ft::Map<int, int>::key_compare kcmp2 = m2.key_comp();
	std::cout << "std kcmp(1, 2): " << kcmp1(1, 2) << std::endl;
	std::cout << "std kcmp(1, 1): " << kcmp1(1, 1) << std::endl;
	std::cout << "std kcmp(2, 1): " << kcmp1(2, 1) << std::endl;
	std::cout << "\n";
	std::cout << "ft kcmp(1, 2): " << kcmp2(1, 2) << std::endl;
	std::cout << "ft kcmp(1, 2): " << kcmp2(1, 1) << std::endl;
	std::cout << "ft kcmp(1, 2): " << kcmp2(2, 1) << std::endl;
	std::cout << "\n\n";
	if (kcmp1(1, 2) != kcmp2(1, 2))
		return (FAIL);
	if (kcmp1(1, 1) != kcmp2(1, 1))
		return (FAIL);
	if (kcmp1(2, 1) != kcmp2(2, 1))
		return (FAIL);
	std::cout << std::endl;

	std::cout << "... cplusplus test ... " << std::endl;
	ft::Map<char,int> mymap;
	ft::Map<char,int>::key_compare mycomp = mymap.key_comp();
	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;
	std::cout << "mymap contains:\n";
	char highest = mymap.rbegin()->first;     // key value of last element
	ft::Map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );
	std::cout << "\n\n";

	print_clear();
	print_title("map compare function test");
	print_interface("value_compare value_comp() const");
	std::map<int, int>::value_compare vcmp1 = m1.value_comp();
	ft::Map<int, int>::value_compare vcmp2 = m2.value_comp();
	std::cout << "std vcmp(pair(1, 1), pair(2, 2)): " << vcmp1(std::make_pair(1, 1), std::make_pair(2, 2)) << std::endl;
	std::cout << "std vcmp(pair(1, 1), pair(1, 2)): " << vcmp1(std::make_pair(1, 1), std::make_pair(1, 2)) << std::endl;
	std::cout << "std vcmp(pair(1, 1), pair(2, 0)): " << vcmp1(std::make_pair(1, 1), std::make_pair(2, 0)) << std::endl;
	std::cout << "std vcmp(pair(2, 1), pair(2, 0)): " << vcmp1(std::make_pair(2, 1), std::make_pair(2, 0)) << std::endl;
	std::cout << "\n";
	std::cout << "ft  vcmp(pair(1, 1), pair(2, 2)): " << vcmp2(std::make_pair(1, 1), std::make_pair(2, 2)) << std::endl;
	std::cout << "ft  vcmp(pair(1, 1), pair(1, 2)): " << vcmp2(std::make_pair(1, 1), std::make_pair(1, 2)) << std::endl;
	std::cout << "ft  vcmp(pair(1, 1), pair(2, 0)): " << vcmp2(std::make_pair(1, 1), std::make_pair(2, 0)) << std::endl;
	std::cout << "ft  vcmp(pair(2, 1), pair(2, 0)): " << vcmp2(std::make_pair(2, 1), std::make_pair(2, 0)) << std::endl;
	std::cout << "\n";
	if (vcmp1(std::make_pair(1, 1), std::make_pair(2, 2)) != vcmp2(std::make_pair(1, 1), std::make_pair(2, 2)))
		return (FAIL);
	if (vcmp1(std::make_pair(1, 1), std::make_pair(1, 2)) != vcmp2(std::make_pair(1, 1), std::make_pair(1, 2)))
		return (FAIL);
	if (vcmp1(std::make_pair(1, 1), std::make_pair(2, 0)) != vcmp2(std::make_pair(1, 1), std::make_pair(2, 0)))
		return (FAIL);
	if (vcmp1(std::make_pair(2, 1), std::make_pair(2, 0)) != vcmp2(std::make_pair(2, 1), std::make_pair(2, 0)))
		return (FAIL);
	std::cout << "... cplusplus test ... " << std::endl;
	ft::Map<char,int> mymap2;
	mymap2['x']=1001;
	mymap2['y']=2002;
	mymap2['z']=3003;
	std::cout << "mymap2 contains:\n";
	std::pair<char,int> highest2 = *mymap2.rbegin();          // last element
	ft::Map<char,int>::iterator it2 = mymap2.begin();
	do {
		std::cout << it2->first << " => " << it2->second << '\n';
	} while ( mymap2.value_comp()(*it2++, highest2) );
	return (SUCCESS);
}

static bool find_count_test(void)
{
	print_title("map find count test");
	{
	print_interface("iterator	find(const key_type& k)");
	std::cout << "... current map ..." << std::endl;
	std::map<std::string, int> m1(arr, arr + 5);
	ft::Map<std::string, int> m2(arr, arr + 5);
	print_map(m1);
	std::cout << std::endl;
	std::cout << "... map.find(\"B_Park\") ..." << std::endl;
	std::cout << "std: (" << m1.find("B_Park")->first << ":" << m1.find("B_Park")->second << ")" << std::endl;
	std::cout << "ft : (" << m2.find("B_Park")->first << ":" << m2.find("B_Park")->second << ")" << std::endl;
	if (m1.find("B_Park")->first != m1.find("B_Park")->first)
		return (FAIL);
	if (m2.find("B_Park")->first != m2.find("B_Park")->first)
		return (FAIL);
	if (m1.find("B_Park")->second != m1.find("B_Park")->second)
		return (FAIL);
	if (m2.find("B_Park")->second != m2.find("B_Park")->second)
		return (FAIL);

	std::cout << "\n... not found test ..." << std::endl;
	if (m1.find("invalid") == m1.end())
		std::cout << "not found" << std::endl;
	if (m2.find("invalid") == m2.end())
		std::cout << "not found" << std::endl;
	std::cout << std::endl << std::endl;
	}
	{
	print_interface("const_iterator	find(const key_type& k) const");
	const std::map<std::string, int> m1(arr, arr + 5);
	const ft::Map<std::string, int> m2(arr, arr + 5);
	std::cout << "... map.find(\"B_Park\") ..." << std::endl;
	std::cout << "std: (" << m1.find("B_Park")->first << ":" << m1.find("B_Park")->second << ")" << std::endl;
	std::cout << "ft : (" << m2.find("B_Park")->first << ":" << m2.find("B_Park")->second << ")" << std::endl;
	if (m1.find("B_Park")->first != m1.find("B_Park")->first)
		return (FAIL);
	if (m2.find("B_Park")->first != m2.find("B_Park")->first)
		return (FAIL);
	if (m1.find("B_Park")->second != m1.find("B_Park")->second)
		return (FAIL);
	if (m2.find("B_Park")->second != m2.find("B_Park")->second)
		return (FAIL);
	// m1.find("B_Park")->second = 1;
	// m2.find("B_Park")->second = 1;
	std::cout << std::endl;
	print_interface("size_type count (const key_type& k) const");
	std::cout << "map.count(\"B_Park\")" << std::endl;
	std::cout << "std: " << m1.count("B_Park") << std::endl;
	std::cout << "ft : " << m2.count("B_Park") << std::endl;
	if (m1.count("B_Park") != m2.count("B_Park"))
		return (FAIL);

	std::cout << "\nmap.count(\"invalid key\")" << std::endl;
	std::cout << "std: " << m1.count("invalid key") << std::endl;
	std::cout << "ft : " << m2.count("invalid key") << std::endl;
	if (m1.count("invalid key") != m2.count("invalid key"))
		return (FAIL);
	}
	return (SUCCESS);
}

static bool bound_test(void)
{
	print_title("map bound test");
	{
	print_interface("iterator lower_bound (const key_type& k)");
	print_interface("iterator upper_bound (const key_type& k)");
	std::cout << "map's key { 0, 5, 10, 15, 20}" << std::endl;
	std::map<int, int> m1;
	ft::Map<int, int> m2;
	for (int i = 0; i < 5; ++i)
	{
		m1[i * 5] = i * 5;
		m2[i * 5] = i * 5;
	}
	std::cout << "std lower_bound(5): ("<< m1.lower_bound(5)->first << ", " << m1.lower_bound(5)->second << ")" << std::endl;
	std::cout << "ft lower_bound(5): ("<< m2.lower_bound(5)->first << ", " << m2.lower_bound(5)->second << ")" << std::endl;
	std::cout << std::endl;

	std::cout << "std upper_bound(5): ("<< m1.upper_bound(5)->first << ", " << m1.upper_bound(5)->second << ")" << std::endl;
	std::cout << "ft upper_bound(5): ("<< m2.upper_bound(5)->first << ", " << m2.upper_bound(5)->second << ")" << std::endl;
	std::cout << std::endl;

	if (m1.lower_bound(5)->first != m2.lower_bound(5)->first)
		return (FAIL);
	if (m1.lower_bound(5)->second != m2.lower_bound(5)->second)
		return (FAIL);
	if (m1.upper_bound(5)->first != m2.upper_bound(5)->first)
		return (FAIL);
	if (m1.upper_bound(5)->second != m2.upper_bound(5)->second)
		return (FAIL);

	std::cout << "std lower_bound(20) == end() : " << (m1.lower_bound(20) == m1.end()) << std::endl;
	std::cout << "ft  lower_bound(20) == end() : " << (m2.lower_bound(20) == m2.end()) << std::endl;
	std::cout << std::endl;
	std::cout << "std upper_bound(20) == end() : " << (m1.upper_bound(20) == m1.end()) << std::endl;
	std::cout << "ft  upper_bound(20) == end() : " << (m2.upper_bound(20) == m2.end()) << std::endl;
	std::cout << std::endl;
	if ((m1.lower_bound(20) == m1.end()) != (m2.lower_bound(20) == m2.end()))
		return (FAIL);
	if ((m1.upper_bound(20) == m1.end()) != (m2.upper_bound(20) == m2.end()))
		return (FAIL);
	}
	{
	print_interface("const_iterator lower_bound (const key_type& k) const");
	print_interface("const_iterator upper_bound (const key_type& k) const");
	std::cout << "map's key { 0, 5, 10, 15, 20}" << std::endl;
	std::map<int, int> tmp1;
	ft::Map<int, int> tmp2;
	for (int i = 0; i < 5; ++i)
	{
		tmp1[i * 5] = i * 5;
		tmp2[i * 5] = i * 5;
	}
	const std::map<int, int> m1(tmp1);
	const ft::Map<int, int> m2(tmp2);
	std::cout << "std lower_bound(5): ("<< m1.lower_bound(5)->first << ", " << m1.lower_bound(5)->second << ")" << std::endl;
	std::cout << "ft lower_bound(5): ("<< m2.lower_bound(5)->first << ", " << m2.lower_bound(5)->second << ")" << std::endl;
	std::cout << std::endl;

	std::cout << "std upper_bound(5): ("<< m1.upper_bound(5)->first << ", " << m1.upper_bound(5)->second << ")" << std::endl;
	std::cout << "ft upper_bound(5): ("<< m2.upper_bound(5)->first << ", " << m2.upper_bound(5)->second << ")" << std::endl;
	std::cout << std::endl;

	if (m1.lower_bound(5)->first != m2.lower_bound(5)->first)
		return (FAIL);
	if (m1.lower_bound(5)->second != m2.lower_bound(5)->second)
		return (FAIL);
	if (m1.upper_bound(5)->first != m2.upper_bound(5)->first)
		return (FAIL);
	if (m1.upper_bound(5)->second != m2.upper_bound(5)->second)
		return (FAIL);

	std::cout << "std lower_bound(20) == end() : " << (m1.lower_bound(20) == m1.end()) << std::endl;
	std::cout << "ft  lower_bound(20) == end() : " << (m2.lower_bound(20) == m2.end()) << std::endl;
	std::cout << std::endl;
	std::cout << "std upper_bound(20) == end() : " << (m1.upper_bound(20) == m1.end()) << std::endl;
	std::cout << "ft  upper_bound(20) == end() : " << (m2.upper_bound(20) == m2.end()) << std::endl;
	std::cout << std::endl;
	if ((m1.lower_bound(20) == m1.end()) != (m2.lower_bound(20) == m2.end()))
		return (FAIL);
	if ((m1.upper_bound(20) == m1.end()) != (m2.upper_bound(20) == m2.end()))
		return (FAIL);
	}
	return (SUCCESS);
}

static bool non_member_operator_test(void)
{
	print_title("map non member operator test");
	std::cout << "... current map1, map2 ..." << std::endl;
	std::map<int, int> m1; m1[1] = 1;m1[2] = 2;m1[3] = 3;
	std::map<int, int> m2; m2[1] = 1;m2[2] = 2;m2[3] = 4;
	ft::Map<int, int> m3; m3[1] = 1;m3[2] = 2;m3[3] = 3;
	ft::Map<int, int> m4; m4[1] = 1;m4[2] = 2;m4[3] = 4;
	print_map(m1);
	print_map(m2);
	std::cout << std::endl;

	print_interface("template <class Key, class T, class Compare, class Alloc>\nbool operator==(const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs)");
	std::cout << "std map(m1 == m2): " << (m1 == m2) << std::endl;
	std::cout << "ft  map(m1 == m2): " << (m3 == m4) << std::endl;
	if ((m1 == m2) != (m3 == m4))
		return (FAIL);
	std::cout << std::endl;

	print_interface("template <class Key, class T, class Compare, class Alloc>\nbool operator!=(const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs)");
	std::cout << "std map(m1 != m2): " << (m1 != m2) << std::endl;
	std::cout << "ft  map(m1 != m2): " << (m3 != m4) << std::endl;
	if ((m1 != m2) != (m3 != m4))
		return (FAIL);
	std::cout << std::endl;

	print_clear();
	print_title("map non member operator test");
	print_interface("template <class Key, class T, class Compare, class Alloc>\nbool operator<(const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs)");
	std::cout << "std map(m1 < m2): " << (m1 < m2) << std::endl;
	std::cout << "ft  map(m1 < m2): " << (m3 < m4) << std::endl;
	if ((m1 < m2) != (m3 < m4))
		return (FAIL);
	std::cout << std::endl;

	print_interface("template <class Key, class T, class Compare, class Alloc>\nbool operator>(const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs)");
	std::cout << "std map(m1 > m2): " << (m1 > m2) << std::endl;
	std::cout << "ft  map(m1 > m2): " << (m3 > m4) << std::endl;
	if ((m1 > m2) != (m3 > m4))
		return (FAIL);
	std::cout << std::endl;

	print_interface("template <class Key, class T, class Compare, class Alloc>\nbool operator<=(const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs)");
	std::cout << "std map(m1 <= m2): " << (m1 <= m2) << std::endl;
	std::cout << "ft  map(m1 <= m2): " << (m3 <= m4) << std::endl;
	if ((m1 <= m2) != (m3 <= m4))
		return (FAIL);
	std::cout << std::endl;

	print_interface("template <class Key, class T, class Compare, class Alloc>\nbool operator>=(const Map<Key,T,Compare,Alloc>& lhs, const Map<Key,T,Compare,Alloc>& rhs)");
	std::cout << "std map(m1 >= m2): " << (m1 >= m2) << std::endl;
	std::cout << "ft  map(m1 >= m2): " << (m3 >= m4) << std::endl;
	if ((m1 >= m2) != (m3 >= m4))
		return (FAIL);
	std::cout << std::endl;
	return (SUCCESS);
}

static bool non_member_swap_test(void)
{
	print_title("map non member swap test");

	print_interface("template <class Key, class T, class Compare, class Alloc>\nvoid swap(Map<Key,T,Compare,Alloc>& x, Map<Key,T,Compare,Alloc>& y)");
	std::cout << "... x map ..." << std::endl;
	std::map<std::string, int> m1(arr, arr + 3);
	std::map<std::string, int> m2(arr + 3, arr + 5);
	ft::Map<std::string, int> m3(arr, arr + 3);
	ft::Map<std::string, int> m4(arr + 3, arr + 5);
	print_map(m1);
	std::cout << "... y map ..." << std::endl;
	print_map(m2);
	std::cout << "\n... After swap ...\n" << std::endl;

	swap(m1, m2);
	swap(m3, m4);
	std::cout << "... std x map ..." << std::endl;
	print_map(m1);
	std::cout << "... std y map ..." << std::endl;
	print_map(m2);

	std::cout << "\n... ft  x map ..." << std::endl;
	print_map(m3);
	std::cout << "... ft  y map ..." << std::endl;
	print_map(m4);
	if ((m1 != m3) || (m2 != m4))
		return (FAIL);
	return (SUCCESS);
}

void test_map(void)
{
	print_clear();
	print_container_name("MAP");
	print_clear();
	(construct_test() <= FAIL) ? print_fail() : print_success();
	print_clear();
	(iterator_test() <= FAIL) ? print_fail() : print_success();
	print_clear();
	(capacity_test() <= FAIL) ? print_fail() : print_success();
	print_clear();
	(element_access() <= FAIL) ? print_fail() : print_success();
	print_clear();
	(insert_test() <= FAIL) ? print_fail() : print_success();
	print_clear();
	(erase_test() <= FAIL) ? print_fail() : print_success();
	print_clear();
	(swap_clear_test() <= FAIL) ? print_fail() : print_success();
	print_clear();
	(cmp_func_test() <= FAIL) ? print_fail() : print_success();
	print_clear();
	(find_count_test() <= FAIL) ? print_fail() : print_success();
	print_clear();
	(bound_test() <= FAIL) ? print_fail() : print_success();
	print_clear();
	(non_member_operator_test() <= FAIL) ? print_fail() : print_success();
	print_clear();
	(non_member_swap_test() <= FAIL) ? print_fail() : print_success();
}
