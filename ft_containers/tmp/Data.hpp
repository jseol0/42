/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:35:19 by jseol             #+#    #+#             */
/*   Updated: 2022/11/06 19:46:42 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <cstddef>

namespace ft
{
	// base iterator
	template	<class Category,
				class T,
				class Distance = ptrdiff_t,
				class Pointer = T*,
				class Reference = T&>
	struct iterator {
	public:
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	};



	// iterator_category
	struct input_iterator_tag{};
	struct output_iterator_tag{};
	struct forward_iterator_tag : public input_iterator_tag{};
	struct bidirectional_iterator_tag : public forward_iterator_tag{};
	struct random_access_iterator_tag : public bidirectional_iterator_tag{};



	// iterator_traits
	template <class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
	};
	template <class T>
	struct iterator_traits<T*>
	{
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;
		typedef random_access_iterator_tag iterator_category;
	};
	template <class T>
	struct iterator_traits<const T*>
	{
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef random_access_iterator_tag iterator_category;
	};

	// data for duplicated type
	struct __true {};
	struct __false {};

	template <class T>
	struct is_iterator { typedef __true val; };
	template <>
	struct is_iterator<int> { typedef __false val; };



	// node for map
	template <typename T>
	struct bNode
	{
		int			dump_size; // max_size때문에 덤프넣음 (구조체 메모리정렬과 관련, 어떤 변수가 들어있는지는 관심없음)
		T			val; 		// std::pair<const key_type, mapped_type>
		bNode		*left;
		bNode		*right;
		bNode		*parent;

		bNode() : dump_size(0), val(), left(0), right(0), parent(0) {}
		bNode(const T& t) : dump_size(0), val(t), left(0), right(0), parent(0) {}
		bNode(const bNode& other) : dump_size(0), val(other.val), left(other.left), right(other.right), parent(other.parent) {}
		bNode&	operator=(const bNode& rhs)
		{
			dump_size = 0;
			val.second = rhs.val.second;
			left = rhs.left;
			right = rhs.right;
			parent = rhs.parent;
			return (*this);
		}
		~bNode() {}
	};
}
#endif
