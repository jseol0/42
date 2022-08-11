/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 20:28:01 by jseol             #+#    #+#             */
/*   Updated: 2022/08/11 22:12:29 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <typename T>
class Array
{
	public:
		Array() : mArray(new T[0]), mSize(0) {};
		Array(unsigned int n) : mArray(new T[n]), mSize(n) {};
		Array(const Array& other)
		{
			*this = other;
		}
		~Array()
		{
			delete [] mArray;
		}

		Array&	operator=(const Array& rhs)
		{
			if (this == &rhs)
				return (*this);
			if (mSize != rhs.mSize)
			{
				if (mArray)
					delete [] mArray;
				mSize = rhs.mSize;
				mArray = new T[mSize];
			}
			for (unsigned int i = 0; i < mSize; i++)
				mArray[i] = rhs.mArray[i];
			return (*this);
		}

		T&	operator[](const unsigned int index)
		{
			if (index < 0 || index >= mSize)
				throw Array::IndexException();
			return (mArray[index]);
		}
		
		const T& operator[](const unsigned int index) const
		{
			if (index < 0 || index >= mSize)
				throw Array::IndexException();
			return (mArray[index]);
		}

		unsigned int	size(void) const
		{
			return (mSize);
		}

		class IndexException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Error: Out of index");
				}
		};

	private:
		T *mArray;
		unsigned int mSize;
};



#endif