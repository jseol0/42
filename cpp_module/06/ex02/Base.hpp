/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:17:26 by jseol             #+#    #+#             */
/*   Updated: 2022/08/10 18:58:41 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>

class Base
{
	public:
		virtual ~Base(void) {};
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
