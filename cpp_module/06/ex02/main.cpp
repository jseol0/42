/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:37:27 by jseol             #+#    #+#             */
/*   Updated: 2022/08/12 13:40:14 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
	for (int i = 0; i < 10; i++)
	{
		Base* p = generate();
		identify(p);
		identify(*p);
		std::cout << std::endl;
		delete p;
	}
	return (0);
}
