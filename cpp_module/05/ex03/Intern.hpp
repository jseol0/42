/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:32:19 by jseol             #+#    #+#             */
/*   Updated: 2022/08/05 19:34:17 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern& other);
		~Intern();

		Intern& operator=(const Intern& rhs);

		Form* makeForm(const std::string formName, const std::string target) const;

		class InvalidFormNameException : public std::exception
		{
			public:
			virtual const char* what() const throw();
		};
};

#endif