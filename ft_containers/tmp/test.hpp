/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 08:30:27 by heryu             #+#    #+#             */
/*   Updated: 2022/11/05 13:24:56 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP

# include <iostream>
# include <string>
# include <cstdio>

# include <map>
# include "./includes/Map.hpp"

# include <vector>
# include "./includes/Vector.hpp"

# include <stack>
# include "./includes/Stack.hpp"


struct A
{
	int a;
	char b;
	float c;
	double d;
	void * e;
};

const std::string MSG_SUCCESS = "SUCCESS";
const std::string MSG_FAIL = "FAIL";

const bool SUCCESS = true;
const bool FAIL = false;

// main
void	print_container_name(const std::string& name);
void	print_title(const std::string& title);
void	print_interface(const std::string& title);
void	print_success(const std::string& message = MSG_SUCCESS);
void	print_fail(const std::string& message = MSG_FAIL);
void	print_clear(void);

// vector
void	test_vector(void);

// map
void	test_map(void);

// stack
void	test_stack(void);

#endif
