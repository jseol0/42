/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 10:23:02 by heryu             #+#    #+#             */
/*   Updated: 2022/11/05 13:24:06 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

template <typename STACK>
class IterStack : public STACK
{
public:
	typedef typename STACK::container_type::iterator		iterator;
	typedef typename STACK::container_type::const_iterator	const_iterator;

	IterStack() : STACK() {}
	IterStack(const IterStack& other) : STACK(other) {}
	IterStack(const STACK& other) : STACK(other) {}
	~IterStack() {}
	IterStack& operator=(const IterStack& rhs) { this->c::operator=(rhs); }

	iterator	begin()
	{
		return (STACK::c.begin());
	}
	const_iterator begin() const
	{
		return (STACK::c.begin());
	}
	iterator	end()
	{
		return (STACK::c.end());
	}
	const_iterator end() const
	{
		return (STACK::c.end());
	}
};

template <typename T>
bool operator==(const std::stack<T>& lhs, const ft::Stack<T>& rhs)
{
	if (lhs.size() != rhs.size())
		return (false);

	IterStack<std::stack<T> > lhs_iterStack(lhs);
	IterStack<ft::Stack<T> > rhs_iterStacK(rhs);
	typename IterStack<std::stack<T> >::const_iterator lhs_iter = lhs_iterStack.begin();
	typename IterStack<ft::Stack<T> >::const_iterator rhs_iter = rhs_iterStacK.begin();
	size_t size = lhs_iterStack.size();
	for (size_t i = 0; i < size; ++i)
	{
		if (*lhs_iter != *rhs_iter)
			return (false);
		++lhs_iter;
		++rhs_iter;
	}
	return (true);
}

template <class T>
bool operator!=(const std::stack<T>& lhs, const ft::Stack<T>& rhs)
{
	return (!(lhs == rhs));
}

template <typename STACK>
static void print_stack_elements(const STACK& s)
{
	IterStack<STACK> iterStack(s);
	typename IterStack<STACK>::const_iterator iter = iterStack.begin();
	size_t size = iterStack.size();
	std::cout << "elements: ";
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << *iter++ << " ";
	}
	std::cout << "<- top" << std::endl;
}

template <typename STACK>
static void print_stack_size(const STACK& s)
{
	std::cout << "size: " << s.size() << std::endl;
}

template <typename STACK>
static void print_stack(const STACK& s)
{
	print_stack_elements(s);
	print_stack_size(s);
}

static bool construct_test(void)
{
	print_title("stack construct test");

	print_interface("explicit Stack(const container_type& ctnr = container_type())");
	std::cout << "... default construct stack() ...\n";
	std::stack<int> s1;
	ft::Stack<int> s2;
	print_stack(s1);
	print_stack(s2);
	if (s1 != s2)
		return (FAIL);
	std::cout << std::endl;

	std::cout << "... stack(container) container = { 1,2,3,4,5 } ...\n";
	int arr[] = { 1,2,3,4,5 };
	std::deque<int> tmp1(arr, arr + 5);
	ft::Vector<int> tmp2(arr, arr + 5);
	std::stack<int> s3(tmp1);
	ft::Stack<int> s4(tmp2);
	print_stack(s3);
	print_stack(s4);
	if (s3 != s4)
		return (FAIL);
	return (SUCCESS);
}

static bool empty_size_test(void)
{
	print_title("stack empty size test");

	print_interface("bool empty() const");
	std::stack<int> s1;
	ft::Stack<int> s2;
	std::cout << std::boolalpha;
	std::cout << "... empty stack ...\n";
	std::cout << "std::stack.empty : " << s1.empty() << std::endl;
	std::cout << "ft::stack.empty : " << s2.empty() << std::endl;
	if (s1 != s2)
		return (FAIL);

	std::cout << std::endl;
	s1.push(1);
	s2.push(1);
	std::cout << "... empty() After push(1) on stack ...\n";
	std::cout << "std::stack.empty : " << s1.empty() << std::endl;
	std::cout << "ft::Stack.empty : " << s2.empty() << std::endl;
	std::cout << std::endl;

	print_interface("size_type size() const");
	std::cout << "current size: " << s1.size() << std::endl;
	std::cout << "... push(2), push(3) on stack ...\n";
	s1.push(2); s1.push(3);
	s2.push(2); s2.push(3);
	std::cout << "std::stack.size: " << s1.size() << std::endl;
	print_stack_elements(s1);
	std::cout << std::endl;
	std::cout << "ft::Stack.size: " << s1.size() << std::endl;
	print_stack_elements(s2);
	if (s1 != s2)
		return (FAIL);
	return (SUCCESS);
}

static bool top_test(void)
{
	print_title("stack top test");

	print_interface("value_type&	top()");
	print_interface("const value_type&	top() const");
	std::stack<int> s1;
	ft::Stack<int> s2;
	for (int i = 0; i < 5; ++i)
	{
		s1.push(i + 1);
		s2.push(i + 1);
	}
	std::cout << "... current stack ..." << std::endl;
	print_stack(s1);
	print_stack(s2);
	std::cout << "std::stack.top(): " << s1.top() << std::endl;
	std::cout << "ft::Stack.top(): " << s2.top() << std::endl;

	std::cout << "\n... After stack.top() = 777 ..." << std::endl;
	s1.top() = 777;
	s2.top() = 777;
	std::cout << "std::stack.top(): " << s1.top() << std::endl;
	std::cout << "ft::Stack.top(): " << s2.top() << std::endl;

	std::cout << std::endl;
	print_stack(s1);
	print_stack(s2);
	if (s1 != s2)
		return (FAIL);

	// std::cout << std::endl;
	// const std::stack<int> s3(s1);
	// const ft::Stack<int> s4(s2);
	// print_stack(s3);
	// print_stack(s4);
	// s3.top() = 123; // error
	// s4.top() = 123; // error
	// if (s3 != s4)
		// return (FAIL);
	return (SUCCESS);
}

static bool push_pop_test(void)
{
	print_title("stack push pop test");

	print_interface("void	push(const value_type& val)");
	print_interface("void	pop(void)");

	int arr[] = { 1,2,3,4,5 };
	std::deque<int> l1(arr, arr+5);
	std::stack<int> s1(l1);
	ft::Vector<int> l2(arr, arr+5);
	ft::Stack<int> s2(l2);
	std::cout << "... current stack ...\n";
	print_stack(s1);

	std::cout << "\n... After pop 3 times ...\n";
	s1.pop(); s2.pop();
	s1.pop(); s2.pop();
	s1.pop(); s2.pop();
	print_stack(s1);
	print_stack(s2);
	if (s1 != s2)
		return (FAIL);

	std::cout << "\n... After push(100, 200, 300)\n";
	s1.push(100); s2.push(100);
	s1.push(200); s2.push(200);
	s1.push(300); s2.push(300);
	print_stack(s1);
	print_stack(s2);
	if (s1 != s2)
		return (FAIL);
	return (SUCCESS);
}

static bool non_member_operator_test(void)
{
	print_title("stack non member operator test");

	std::cout << "stack1 == { 1,2,3,4 <- top }\n";
	std::cout << "stack2 == { 1,2,3,5 <- top }\n\n";
	std::stack<int> s1;
	s1.push(1); s1.push(2); s1.push(3); s1.push(4);
	std::stack<int> tmp1;
	tmp1.push(1); tmp1.push(2); tmp1.push(3); tmp1.push(5);
	ft::Stack<int> s2;
	s2.push(1); s2.push(2); s2.push(3); s2.push(4);
	ft::Stack<int> tmp2;
	tmp2.push(1); tmp2.push(2); tmp2.push(3); tmp2.push(5);

	print_interface("template <class T, class Container>\nbool operator==(const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)");
	std::cout << "std::stack(s1 == s2): " << (s1 == tmp1) << std::endl;
	std::cout << "ft::Stack(s1 == s2): " << (s2 == tmp2) << std::endl;
	if ((s1 == tmp1) != (s2 == tmp2))
		return (FAIL);
	std::cout << std::endl;

	print_interface("template <class T, class Container>\nbool operator!=(const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)");
	std::cout << "std::stack(s1 != s2): " << (s1 != tmp1) << std::endl;
	std::cout << "ft::Stack(s1 != s2): " << (s2 != tmp2) << std::endl;
	if ((s1 != tmp1) != (s2 != tmp2))
		return (FAIL);
	std::cout << std::endl;

	print_interface("template <class T, class Container>\nbool operator<(const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)");
	std::cout << "std::stack(s1 < s2): " << (s1 < tmp1) << std::endl;
	std::cout << "ft::Stack(s1 < s2): " << (s2 < tmp2) << std::endl;
	if ((s1 < tmp1) != (s2 < tmp2))
		return (FAIL);
	std::cout << std::endl;

	print_interface("template <class T, class Container>\nbool operator>(const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)");
	std::cout << "std::stack(s1 > s2): " << (s1 > tmp1) << std::endl;
	std::cout << "ft::Stack(s1 > s2): " << (s2 > tmp2) << std::endl;
	if ((s1 > tmp1) != (s2 > tmp2))
		return (FAIL);
	std::cout << std::endl;

	print_interface("template <class T, class Container>\nbool operator<=(const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)");
	std::cout << "std::stack(s1 <= s2): " << (s1 <= tmp1) << std::endl;
	std::cout << "ft::Stack(s1 <= s2): " << (s2 <= tmp2) << std::endl;
	if ((s1 <= tmp1) != (s2 <= tmp2))
		return (FAIL);
	std::cout << std::endl;

	print_interface("template <class T, class Container>\nbool operator>=(const Stack<T,Container>& lhs, const Stack<T,Container>& rhs)");
	std::cout << "std::stack(s1 >= s2): " << (s1 >= tmp1) << std::endl;
	std::cout << "ft::Stack(s1 >= s2): " << (s2 >= tmp2) << std::endl;
	if ((s1 >= tmp1) != (s2 >= tmp2))
		return (FAIL);
	return (SUCCESS);
}

void test_stack(void)
{
	print_clear();
	print_container_name("STACK");
	print_clear();
	(construct_test() <= FAIL) ? print_fail() : print_success();
	print_clear();
	(empty_size_test() <= FAIL) ? print_fail() : print_success();
	print_clear();
	(top_test() <= FAIL) ? print_fail() : print_success();
	print_clear();
	(push_pop_test() <= FAIL) ? print_fail() : print_success();
	print_clear();
	(non_member_operator_test() <= FAIL) ? print_fail() : print_success();
}
