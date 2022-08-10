/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 23:32:33 by jseol             #+#    #+#             */
/*   Updated: 2022/08/10 14:06:26 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>
# include <cstdint>

class Data
{
	public:
		Data();
		Data(std::string name, double num, int age);
		Data(const Data& other);
		~Data();

		Data& operator=(const Data& rhs);

		const std::string& getName() const;
		const double& getNum() const;
		const int& getAge() const;

	private:
		std::string mName;
		double	mNum;
		int mAge;
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

std::ostream& operator<<(std::ostream& os, const Data& ptr);
void print(uintptr_t raw);

#endif