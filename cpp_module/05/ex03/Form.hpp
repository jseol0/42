/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:40:43 by jseol             #+#    #+#             */
/*   Updated: 2022/08/05 17:07:12 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(void);
		Form(const Form& other);
		Form(std::string name, int signGrade, int executeGrade);
		virtual ~Form();

		Form& operator=(const Form& rhs);

		std::string getName(void) const;
		bool		getIsSigned(void) const;
		int			getSignGrade(void) const;
		int			getExecuteGrade(void) const;
		void		beSigned(const Bureaucrat& bureaucrat);

		virtual void execute(Bureaucrat const &executor) const;
		virtual void action(void) const = 0;
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class NotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		const std::string	mName;
		bool				isSigned;
		const int			mSignGrade;
		const int			mExecuteGrade;
};

std::ostream& operator<<(std::ostream& os , const Form& form);

#endif