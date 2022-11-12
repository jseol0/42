/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 08:31:37 by heryu             #+#    #+#             */
/*   Updated: 2022/11/12 18:39:36 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

template <class T, class Alloc>
bool operator==(const std::vector<T,Alloc>& lhs, const ft::Vector<T,Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	if (lhs.capacity() != rhs.capacity())
		return (false);
	typename std::vector<T, Alloc>::const_iterator lhs_iter = lhs.begin();
	typename ft::Vector<T, Alloc>::const_iterator rhs_iter = rhs.begin();
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
bool operator!=(const std::vector<T,Alloc>& lhs, const ft::Vector<T,Alloc>& rhs)
{
	return (!(lhs == rhs));
}

template <typename VECTOR>
static void print_vector_elements(const VECTOR& v)
{
	size_t size = v.size();
	std::cout << "elements: ";
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

template <typename VECTOR>
static void print_vector_capacity(const VECTOR& v)
{
	std::cout << "size: " << v.size() << ", capacity: " << v.capacity() << std::endl;
}

template <typename VECTOR>
static void print_vector(const VECTOR& v)
{
	print_vector_elements(v);
	print_vector_capacity(v);
}

static bool	construct_test(void)
{
	{
		print_title("vector construct test");
		print_interface("explicit Vector(const allocator_type& alloc = allocator_type())");
		std::vector<int> v1;
		ft::Vector<int> v2;
		print_vector(v1);
		print_vector(v2);
		if (v1 != v2)
			return (FAIL);
	}
	std::cout << std::endl;
	{
		print_interface("explicit Vector(size_type n,const value_type& val = value_type(),\n\
			const allocator_type& alloc = allocator_type())");
		std::vector<int> v1(5, 42);
		ft::Vector<int> v2(5, 42);
		print_vector(v1);
		print_vector(v2);
		if (v1 != v2)
			return (FAIL);
	}
	std::cout << std::endl;
	{
		print_interface("template <typename InputIterator>\nVector(InputIterator first, InputIterator last,\n \
				const allocator_type& alloc = allocator_type())");
		std::vector<int> tmp;
		for (int i = 0; i < 5; ++i)
			tmp.push_back(i + 1);
		std::vector<int> v1(tmp.begin(), tmp.end());
		ft::Vector<int> v2(tmp.begin(), tmp.end());
		print_vector(v1);
		print_vector(v2);
		if (v1 != v2)
			return (FAIL);
	}
	std::cout << std::endl;
	{
		print_interface("Vector(const Vector& other)");
		std::vector<int> tmp1;
		ft::Vector<int> tmp2;
		for (int i = 0; i < 5; ++i)
		{
			tmp1.push_back(i + 1);
			tmp2.push_back(i + 1);
		}
		std::vector<int> v1(tmp1);
		ft::Vector<int> v2(tmp2);
		print_vector(v1);
		print_vector(v2);
		if (v1 != v2)
			return (FAIL);
	}
	std::cout << std::endl;
	{
		print_interface("Vector& operator=(const Vector& rhs)");		// 시간 측정
		std::vector<int> tmp1;
		ft::Vector<int> tmp2;
		for (int i = 0; i < 5; ++i)
		{
			tmp1.push_back((i + 1) * 10);
			tmp2.push_back((i + 1) * 10);
		}
		int arr[] = { 1,2,3,4,5 };
		std::vector<int> v1(arr, arr + 5);
		ft::Vector<int> v2(arr, arr + 5);
		std::cout << "... origin vector ...\n";
		print_vector(v1);
		print_vector(v2);

		std::cout << "\n... After assign = ...\n";
		v1 = tmp1;
		v2 = tmp2;
		print_vector(v1);
		print_vector(v2);
		if (v1 != v2)
			return (FAIL);
	}
	return (SUCCESS);
}

static bool iterator_test(void)
{
	print_title("vector iterator test");

	print_interface("iterator	begin()");
	print_interface("iterator	end()");

	std::vector<int> v1;
	ft::Vector<int> v2;
	for (int i = 0; i < 5; ++i)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 1);
	}
	std::cout << "std::vector: ";
	for (std::vector<int>::iterator iter = v1.begin(); iter != v1.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl;
	std::cout << "ft::Vector: ";
	for (ft::Vector<int>::iterator iter = v2.begin(); iter != v2.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl << std::endl;

	print_interface("const_iterator	begin() const");
	print_interface("const_iterator	end() const");
	std::vector<int>::const_iterator begin1 = v1.begin();
	std::vector<int>::const_iterator end1 = v1.end();
	ft::Vector<int>::const_iterator begin2 = v2.begin();
	ft::Vector<int>::const_iterator end2 = v2.end();
	if (*begin1 != *begin2)
		return (FAIL);
	// *begin1 = 1;
	// *begin2 = 1;
	std::cout << "std::vector: ";
	for (; begin1 != end1; ++begin1)
		std::cout << *begin1 << " ";
	std::cout << std::endl;
	std::cout << "ft::Vector: ";
	for (; begin2 != end2; ++begin2)
		std::cout << *begin2 << " ";
	std::cout << std::endl << std::endl;

	print_interface("iterator	rbegin()");
	print_interface("iterator	rend()");
	std::cout << "std::vector: ";
	for (std::vector<int>::reverse_iterator iter = v1.rbegin(); iter != v1.rend(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl;
	std::cout << "ft::Vector: ";
	for (ft::Vector<int>::reverse_iterator iter = v2.rbegin(); iter != v2.rend(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl << std::endl;

	print_interface("const_iterator	rbegin() const");
	print_interface("const_iterator	rend() const");
	std::vector<int>::const_reverse_iterator rbegin1 = v1.rbegin();
	std::vector<int>::const_reverse_iterator rend1 = v1.rend();
	ft::Vector<int>::const_reverse_iterator rbegin2 = v2.rbegin();
	ft::Vector<int>::const_reverse_iterator rend2 = v2.rend();
	if (*rbegin1 != *rbegin2)
		return (FAIL);
	std::cout << "std::vector: ";
	for (; rbegin1 != rend1; ++rbegin1)
		std::cout << *rbegin1 << " ";
	std::cout << std::endl;
	std::cout << "ft::Vector: ";
	for (; rbegin2 != rend2; ++rbegin2)
		std::cout << *rbegin2 << " ";
	std::cout << std::endl;
	// *rbegin1 = 1;
	// *rbegin2 = 1;
	return (SUCCESS);
}

static bool size_test(void)
{
	print_title("vector size test");

	print_interface("size_type	size() const");
	print_interface("size_type	capacity() const");
	print_interface("bool		empty() const");
	std::vector<int> v1;
	ft::Vector<int> v2;
	std::cout << "std::vector - "; print_vector_capacity(v1);
	std::cout << "ft::vector - "; print_vector_capacity(v2);
	std::cout << std::boolalpha << "empty(): " << v1.empty() << ", " << v2.empty() << std::endl;
	if (v1.empty() != v2.empty())
		return (FAIL);
	if (v1.size() != v2.size())
		return (FAIL);
	if (v1.capacity() != v2.capacity())
		return (FAIL);
	if (v1.max_size() != v2.max_size())
		return (FAIL);

	for (int i = 0; i < 5; ++i)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 1);
	}
	std::cout << std::endl << "... After push 5 elements ..." << std::endl << std::endl;
	std::cout << "std::vector: "; print_vector_capacity(v1);
	std::cout << "ft::vector: "; print_vector_capacity(v2);
	std::cout << std::boolalpha << "empty(): " << v1.empty() << ", " << v2.empty() << std::endl;
	if (v1.empty() != v2.empty())
		return (FAIL);
	if (v1.size() != v2.size())
		return (FAIL);
	if (v1.capacity() != v2.capacity())
		return (FAIL);
	if (v1.max_size() != v2.max_size())
		return (FAIL);

	std::cout << std::endl;
	print_interface("size_type	max_size() const");
	{
	std::vector<int> v1; ft::Vector<int> v2;
	std::cout << "int: " << v1.max_size() << " : " << v2.max_size() << std::endl;
	if (v1.max_size() != v2.max_size())
		return (FAIL);
	}
	{
	std::vector<double> v1; ft::Vector<double> v2;
	std::cout << "double: " << v1.max_size() << " : " << v2.max_size() << std::endl;
	if (v1.max_size() != v2.max_size())
		return (FAIL);
	}
	{
	std::vector<std::string> v1; ft::Vector<std::string> v2;
	std::cout << "string: " << v1.max_size() << " : " << v2.max_size() << std::endl;
	if (v1.max_size() != v2.max_size())
		return (FAIL);
	}
	{
	std::vector<A> v1; ft::Vector<A> v2;
	std::cout << "A: " << v1.max_size() << " : " << v2.max_size() << std::endl;
	if (v1.max_size() != v2.max_size())
		return (FAIL);
	}
	return (SUCCESS);
}

static bool resize_test(void)
{
	print_title("vector resize test");

	print_interface("void	resize(size_type n, value_type val = value_type())");
	std::vector<int> v1(5);
	ft::Vector<int> v2(5);
	print_vector(v1);
	print_vector(v2);
	std::cout << std::endl << " ... After resize(7, 7) ..." << std::endl << std::endl;
	v1.resize(7, 7);
	v2.resize(7, 7);
	print_vector(v1);
	print_vector(v2);
	if (v1 != v2)
		return (FAIL);
	std::cout << std::endl << " ... After resize(21, 21) ..." << std::endl << std::endl;
	v1.resize(21, 21);
	v2.resize(21, 21);
	print_vector(v1);
	print_vector(v2);
	if (v1 != v2)
		return (FAIL);
	std::cout << std::endl << " ... After resize(3, 3) ..." << std::endl << std::endl;
	v1.resize(3, 3);
	v2.resize(3, 3);
	print_vector(v1);
	print_vector(v2);
	if (v1 != v2)
		return (FAIL);
	return (SUCCESS);
}

static bool reserve_test(void)
{
	print_title("vector reserve test");

	print_interface("void		reserve(size_type n)");
	std::vector<int> v1(5);
	ft::Vector<int> v2(5);
	print_vector(v1);
	print_vector(v2);
	if (v1 != v2)
		return (FAIL);
	std::cout << std::endl << " ... After reserve(10) ..." << std::endl << std::endl;
	v1.reserve(10);
	v2.reserve(10);
	print_vector(v1);
	print_vector(v2);
	if (v1 != v2)
		return (FAIL);
	std::cout << std::endl << " ... After reserve(0) ..." << std::endl << std::endl;
	v1.reserve(0);
	v2.reserve(0);
	print_vector(v1);
	print_vector(v2);
	if (v1 != v2)
		return (FAIL);
	return (SUCCESS);
}

static bool element_access_test(void)
{
	print_title("vector element access test");

	print_interface("reference 		operator[](size_type n)");
	print_interface("const_reference 	operator[](size_type n) const");
	std::cout << "TEST vector[i] = i + 1 (0 <= i < 5)" << std::endl;
	std::vector<int> v1(5);
	ft::Vector<int> v2(5);
	for (int i = 0; i < 5; ++i)
	{
		v1[i] = i + 1;
		v2[i] = i + 1;
	}
	std::cout << "std::vector: ";
	for (int i = 0; i < 5; ++i)
		std::cout << v1[i] << " ";
	std::cout << std::endl << "ft::Vector: ";
	for (int i = 0; i < 5; ++i)
		std::cout << v2[i] << " ";
	std::cout << std::endl;

	const std::vector<int> const_v1(v1);
	const ft::Vector<int> const_v2(v2);
	// const_v1[0] = 0;
	// const_v2[0] = 0;
	// v1[100] = 100;
	// v2[100] = 100;
	for (int i = 0; i < 5; ++i)
	{
		if (v1[i] != v2[i])
			return (FAIL);
	}
	std::cout << std::endl;

	print_interface("reference		at(size_type n)");
	print_interface("const_reference		at(size_type n) const");
	std::cout << "TEST vector.at(i) = i + 1 (0 <= i < 5)" << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		v1.at(i) = i + 5;
		v2.at(i) = i + 5;
	}
	std::cout << "std::vector: ";
	for (int i = 0; i < 5; ++i)
		std::cout << v1.at(i) << " ";
	std::cout << std::endl << "ft::Vector: ";
	for (int i = 0; i < 5; ++i)
		std::cout << v2.at(i) << " ";
	std::cout << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		if (v1.at(i) != v2.at(i))
			return (FAIL);
	}
	// const_v1.at(0) = 0;
	// const_v2.at(0) = 0;
	// v1.at(100);
	// v2.at(100);

	std::cout << std::endl;
	print_interface("reference		front();");
	print_interface("const_reference		front() const");
	std::cout << "TEST vector.front() = 100" << std::endl;
	v1.front() = 100;
	v2.front() = 100;
	std::cout << "std::vector::front: " << v1.front() << std::endl;
	std::cout << "ft::Vector::front: " << v2.front() << std::endl;
	if (v1.front() != v2.front())
		return (FAIL);

	std::cout << std::endl;
	print_interface("reference		back();");
	print_interface("const_reference		back() const");
	std::cout << "TEST vector.back() = 200" << std::endl;
	v1.back() = 200;
	v2.back() = 200;
	std::cout << "std::vector::back: " << v1.back() << std::endl;
	std::cout << "ft::Vector::back: " << v2.back() << std::endl;
	if (v1.back() != v2.back())
		return (FAIL);

	std::cout << std::endl << "... vector print ..." << std::endl;
	print_vector(v1);
	print_vector(v2);
	return (SUCCESS);
}

static bool assign_test(void)
{
	print_title("vector assign test");

	print_interface("void	assign(size_type n, const value_type& val)");
	std::vector<int> v1(3);
	ft::Vector<int> v2(3);
	print_vector(v1);
	print_vector(v2);

	std::cout << std::endl << "vector.assign(1, 1)" << std::endl;
	v1.assign(1, 1);
	v2.assign(1, 1);
	print_vector(v1);
	print_vector(v2);
	if (v1 != v2)
		return (FAIL);

	std::cout << std::endl << "vector.assign(10, 777)" << std::endl;
	v1.assign(10, 777);
	v2.assign(10, 777);
	print_vector(v1);
	print_vector(v2);
	if (v1 != v2)
		return (FAIL);
	std::cout << std::endl;
	{
	print_interface("template <class InputIterator>\nvoid	assign(InputIterator first, InputIterator last)");
	std::cout << "tmp vector { 2, 4, 3, 1 }" << std::endl;
	std::cout  << std::endl << "Before vector.assign(tmp.begin(), tmp.end());" << std::endl;
	print_vector(v1);
	print_vector(v2);
	int arr[] = { 2, 4, 3, 1 };
	std::vector<int> tmp1(arr, arr + 4);
	ft::Vector<int> tmp2(arr, arr + 4);
	std::vector<int> v1;
	ft::Vector<int> v2;

	v1.assign(tmp1.begin(), tmp1.end());
	v2.assign(tmp2.begin(), tmp2.end());
	std::cout << std::endl << "After vector.assign(tmp.begin(), tmp.end());" << std::endl;
	print_vector(v1);
	print_vector(v2);
	if (v1 != v2)
		return (FAIL);
	}
	return (SUCCESS);
}

static bool push_pop_test(void)
{
	print_title("vector push & pop test");
	std::vector<int> v1;
	ft::Vector<int> v2;

	print_interface("void	push_back(const value_type& val)");
	std::cout << "Before vector.push_back(i + 1), (0 <= i < 5)" << std::endl;
	print_vector(v1);
	print_vector(v2);
	std::cout << std::endl;

	std::cout << "After vector.push_back(i + 1), (0 <= i < 5)" << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 1);
	}
	print_vector(v1);
	print_vector(v2);
	if (v1 != v2)
		return (FAIL);
	std::cout << std::endl;

	print_interface("void	pop_back()");
	std::cout << "vector.pop_back * 3 times" << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		v1.pop_back();
		v2.pop_back();
	}
	print_vector(v1);
	print_vector(v2);
	if (v1 != v2)
		return (FAIL);
	// for (int i = 0; i < 100; ++i) // undefined
	// {
	// 	v1.pop_back();
	// 	v2.pop_back();
	// }
	return (SUCCESS);
}

static bool insert_test(void)
{
	print_title("vector insert test");
	{
	std::vector<int> v1(5);
	ft::Vector<int> v2(5);
	for (int i = 0; i < 5; ++i)
	{
		v1[i] = i + 1;
		v2[i] = i + 1;
	}
	print_interface("iterator insert(iterator position, const value_type& val)");
	std::cout << "Before insert vector" << std::endl;
	print_vector(v1);
	std::cout << std::endl;
	std::cout << "After vector.insert(vector.begin + 1, 777) and return value" << std::endl;
	int ret_v1 =  *(v1.insert(v1.begin() + 1, 777));
	int ret_v2 = *(v2.insert(v2.begin() + 1, 777));
	std::cout << "ret: " << ret_v1 << ", " << ret_v2 << std::endl;
	if (ret_v1 != ret_v2)
		return (FAIL);
	print_vector(v1);
	print_vector(v2);
	if (v1 != v2)
		return (FAIL);
	}
	{
	std::cout << std::endl;
	std::vector<int> v1(5);
	ft::Vector<int> v2(5);
	for (int i = 0; i < 5; ++i)
	{
		v1[i] = i + 1;
		v2[i] = i + 1;
	}
	print_interface("void insert(iterator position, size_type n, const value_type& val)");
	std::cout << "Before insert vector" << std::endl;
	print_vector(v1);
	std::cout << std::endl;
	std::cout << "After vector.insert(vector.begin + 1, 3, 777)" << std::endl;
	v1.insert(v1.begin() + 1, 3, 777);
	v2.insert(v2.begin() + 1, 3, 777);
	print_vector(v1);
	print_vector(v2);
	if (v1 != v2)
		return (FAIL);
	}

	{
	std::cout << std::endl;
	std::vector<int> v1(5);
	ft::Vector<int> v2(5);
	for (int i = 0; i < 5; ++i)
	{
		v1[i] = i + 1;
		v2[i] = i + 1;
	}
	print_interface("template <class InputIterator>\nvoid insert (iterator position, InputIterator first, InputIterator last)");
	std::cout << "Before insert vector" << std::endl;
	print_vector(v1);
	std::cout << std::endl;
	std::cout << "After vector.insert(vector.end, tmp.begin, tmp.end)" << std::endl;
	std::cout << "tmp = { 333, 333, 333, 333, 333, 333 }" << std::endl;
	std::vector<int> tmp1(6);
	ft::Vector<int> tmp2(6);
	for (int i = 0; i < 6; ++i)
	{
		tmp1[i] = 333;
		tmp2[i] = 333;
	}
	v1.insert(v1.end(), tmp1.begin(), tmp1.end());
	v2.insert(v2.end(), tmp2.begin(), tmp2.end());
	print_vector(v1);
	print_vector(v2);
	if (v1 != v2)
		return (FAIL);
	}
	return (SUCCESS);
}

static bool erase_test(void)
{
	print_title("vector erase test");
	{
	std::vector<int> v1(5);
	ft::Vector<int> v2(5);
	for (int i = 0; i < 5; ++i)
	{
		v1[i] = (i + 1) * 10;
		v2[i] = (i + 1) * 10;
	}
	std::cout << "Before vector.erase()" << std::endl;
	print_vector(v1);
	std::cout << std::endl;

	print_interface("iterator erase(iterator position)");
	std::cout << "After vector.erase(v.begin() + 2) and return value" << std::endl;
	int ret_v1 = *(v1.erase(v1.begin() + 2));
	int ret_v2 = *(v2.erase(v2.begin() + 2));
	std::cout << "ret: " << ret_v1 << ", " << ret_v2 << std::endl;
	if (ret_v1 != ret_v2)
		return (FAIL);
	print_vector(v1);
	print_vector(v2);
	if (v1 != v2)
		return (FAIL);
	}
	{
	std::vector<int> v1(5);
	ft::Vector<int> v2(5);
	for (int i = 0; i < 5; ++i)
	{
		v1[i] = (i + 1) * 10;
		v2[i] = (i + 1) * 10;
	}
	std::cout << "\n\nBefore vector.erase()" << std::endl;
	print_vector(v1);
	std::cout << std::endl;

	print_interface("iterator erase (iterator first, iterator last)");
	std::cout << "After vector.erase(v.begin() + 2, v.end() - 1) and return value" << std::endl;
	int ret_v1 = *(v1.erase(v1.begin() + 2, v1.end() - 1));
	int ret_v2 = *(v2.erase(v2.begin() + 2, v2.end() - 1));
	std::cout << "ret: " << ret_v1 << ", " << ret_v2 << std::endl;
	if (ret_v1 != ret_v2)
		return (FAIL);
	print_vector(v1);
	print_vector(v2);
	if (v1 != v2)
		return (FAIL);
	}
	return (SUCCESS);
}

static bool swap_test(void)
{
	print_title("vector swap test");

	print_interface("void	swap(Vector& x)");
	std::vector<int> vx1(5);
	std::vector<int> vy1(10);
	ft::Vector<int> vx2(5);
	ft::Vector<int> vy2(10);
	for (int i = 0; i < 5; ++i)
	{
		vx1[i] = i + 1;
		vy1[i] = 10 - (i + 1);
		vx2[i] = i + 1;
		vy2[i] = 10 - (i + 1);
	}
	std::cout << "Before x.swap(y)" << std::endl;
	std::cout << "=== x ===" << std::endl;
	print_vector(vx1);
	std::cout << "=== y ===" << std::endl;
	print_vector(vy1);
	std::cout << std::endl;

	std::cout << "After x.swap(y)" << std::endl;
	vx1.swap(vy1);
	vx2.swap(vy2);
	std::cout << "...std::vector..." << std::endl;
	std::cout << "=== x ===" << std::endl;
	print_vector(vx1);
	std::cout << "=== y ===" << std::endl;
	print_vector(vy1);
	std::cout << std::endl;
	std::cout << "...ft::Vector..." << std::endl;
	std::cout << "=== x ===" << std::endl;
	print_vector(vx1);
	std::cout << "=== y ===" << std::endl;
	print_vector(vy1);

	if (vx1 != vx2 || vy1 != vy2)
		return (FAIL);
	return (SUCCESS);
}

static bool clear_test(void)
{
	print_title("vector clear test");

	std::vector<int> v1(5);
	ft::Vector<int> v2(5);
	for (int i = 0; i < 5; ++i)
	{
		v1[i] = i + 1;
		v2[i] = i + 1;
	}

	print_interface("void	clear()");
	std::cout << "Before clear" << std::endl;
	print_vector(v1);

	std::cout << "\nAfter clear" << std::endl;
	v1.clear();
	v2.clear();
	print_vector(v1);
	print_vector(v2);
	if (v1 != v2)
		return (FAIL);
	return (SUCCESS);
}

static bool non_member_operator_test(void)
{
	print_title("vector non member operator test (operator== != < > <= >=)");

	std::vector<int> v1;
	std::vector<int> v2;
	ft::Vector<int> v3;
	ft::Vector<int> v4;
	for (int i = 0; i < 4; i++)
	{
		v1.push_back(i);
		v2.push_back(i);
		v3.push_back(i);
		v4.push_back(i);
	}
	v2[3] = 4; v4[3] = 4;
	std::cout << "v1: { 0, 1, 2, 3 }" << std::endl;
	std::cout << "v2: { 0, 1, 2, 4 }" << std::endl;

	print_interface("template <class T, class Alloc>\nbool operator==(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)");
	std::cout << "std::vector(v1 == v2): " << (v1 == v2) << std::endl;
	std::cout << "ft::Vector(v1 == v2): "  << (v3 == v4) << std::endl;
	if ((v1 == v2) != (v3 == v4))
		return (FAIL);

	std::cout << std::endl;
	print_interface("template <class T, class Alloc>\nbool operator!=(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)");
	std::cout << "std::vector(v1 != v2): " << (v1 != v2) << std::endl;
	std::cout << "ft::Vector(v1 != v2): "  << (v3 != v4) << std::endl;
	if ((v1 != v2) != (v3 != v4))
		return (FAIL);

	std::cout << std::endl;
	print_interface("template <class T, class Alloc>\nbool operator<(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)");
	std::cout << "std::vector(v1 < v2): " << (v1 < v2) << std::endl;
	std::cout << "ft::Vector(v1 < v2): "  << (v3 < v4) << std::endl;
	if ((v1 < v2) != (v3 < v4))
		return (FAIL);

	std::cout << std::endl;
	print_interface("template <class T, class Alloc>\nbool operator>(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)");
	std::cout << "std::vector(v1 > v2): " << (v1 > v2) << std::endl;
	std::cout << "ft::Vector(v1 > v2): "  << (v3 > v4) << std::endl;
	if ((v1 > v2) != (v3 > v4))
		return (FAIL);

	std::cout << std::endl;
	print_interface("template <class T, class Alloc>\nbool operator<=(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)");
	std::cout << "std::vector(v1 <= v2): " << (v1 <= v2) << std::endl;
	std::cout << "ft::Vector(v1 <= v2): "  << (v3 <= v4) << std::endl;
	if ((v1 <= v2) != (v3 <= v4))
		return (FAIL);

	std::cout << std::endl;
	print_interface("template <class T, class Alloc>\nbool operator>=(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)");
	std::cout << "std::vector(v1 >= v2): " << (v1 >= v2) << std::endl;
	std::cout << "ft::Vector(v1 >= v2): "  << (v3 >= v4) << std::endl;
	if ((v1 >= v2) != (v3 >= v4))
		return (FAIL);
	return (SUCCESS);
}

static bool non_member_swap_test(void)
{
	print_title("vector non member swap test");
	print_interface("template <class T, class Alloc>\nvoid swap(Vector<T,Alloc>& x, Vector<T,Alloc>& y)");
	std::vector<int> v1;
	std::vector<int> v2(2);
	ft::Vector<int> v3;
	ft::Vector<int> v4(2);
	for (int i = 0; i < 4; i++)
	{
		v1.push_back(i);
		v3.push_back(i);
	}
	std::cout << "Before swap(x, y)" << std::endl;
	std::cout << "=== x ===" << std::endl;
	print_vector(v1);
	std::cout << "=== y ===" << std::endl;
	print_vector(v2);

	std::cout << std::endl << "... After swap(x, y) ..." << std::endl << std::endl;
	swap(v1, v2);
	ft::swap(v3, v4);

	std::cout << "=== x ===" << std::endl;
	print_vector(v1);
	std::cout << "=== y ===" << std::endl;
	print_vector(v2);
	std::cout << "=====================" << std::endl;
	std::cout << "=== x ===" << std::endl;
	print_vector(v3);
	std::cout << "=== y ===" << std::endl;
	print_vector(v4);
	if (v1 != v3 || v2 != v4)
		return (FAIL);
	return (SUCCESS);
}

void	test_vector(void)
{
	print_clear();
	print_container_name("VECTOR");
	print_clear();
	(construct_test() == FAIL) ? print_fail() : print_success();
	print_clear();
	(iterator_test() == FAIL) ? print_fail() : print_success();
	print_clear();
	(size_test() == FAIL) ? print_fail() : print_success();
	print_clear();
	(resize_test() == FAIL) ? print_fail() : print_success();
	print_clear();
	(reserve_test() == FAIL) ? print_fail() : print_success();
	print_clear();
	(element_access_test() == FAIL) ? print_fail() : print_success();
	print_clear();
	(assign_test() == FAIL) ? print_fail() : print_success();
	print_clear();
	(push_pop_test() == FAIL) ? print_fail() : print_success();
	print_clear();
	(insert_test() == FAIL) ? print_fail() : print_success();
	print_clear();
	(erase_test() == FAIL) ? print_fail() : print_success();
	print_clear();
	(swap_test() == FAIL) ? print_fail() : print_success();
	print_clear();
	(clear_test() == FAIL) ? print_fail() : print_success();
	print_clear();
	(non_member_operator_test() == FAIL) ? print_fail() : print_success();
	print_clear();
	(non_member_swap_test() == FAIL) ? print_fail() : print_success();
}
