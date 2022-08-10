/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 23:32:35 by jseol             #+#    #+#             */
/*   Updated: 2022/08/10 14:06:27 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data()
	: mName("No name"), mNum(0), mAge(1)
{

}

Data::Data(std::string name, double num, int age)
	: mName(name), mNum(num), mAge(age)
{

}

Data::Data(const Data& other)
{
	*this = other;
}

Data::~Data()
{
	
}

Data& Data::operator=(const Data& rhs)
{
	if (this != &rhs)
	{
		mName = rhs.mName;
		mNum = rhs.mNum;
		mAge = rhs.mAge;
	}
	return (*this);
}

const std::string& Data::getName() const
{
	return (mName);
}

const double& Data::getNum() const
{
	return (mNum);
}

const int& Data::getAge() const
{
	return (mAge);
}

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

std::ostream& operator<<(std::ostream& os, const Data& ptr)
{
	os << "Adress : " << &ptr << std::endl
		<< "Number : " << ptr.getNum() << std::endl
		<< "Name : " << ptr.getName() << std::endl
		<< "Age : " << ptr.getAge() << std::endl;
	return (os);
}

void print(uintptr_t raw)
{
	Data *d = deserialize(raw);

	std::cout << "Address : " << d << std::endl
		<< "Number : " << d->getNum() << std::endl
		<< "Name : " << d->getName() << std::endl
		<< "Age : " << d->getAge() << std::endl;
}