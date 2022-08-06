/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:30:33 by jseol             #+#    #+#             */
/*   Updated: 2022/08/05 13:19:02 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& rhs);

		const std::string getName(void) const;
		int getGrade(void) const;

		void increaseGrade(void);
		void decreaseGrade(void);

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

	private:
		const std::string	mName;
		int					mGrade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif