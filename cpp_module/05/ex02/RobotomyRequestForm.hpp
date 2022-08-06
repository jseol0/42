/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:53:53 by jseol             #+#    #+#             */
/*   Updated: 2022/08/05 18:07:17 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include <iostream>
# include "Form.hpp"

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm(const std::string target);
		~RobotomyRequestForm();

		RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);

		virtual void action(void) const;
	private:
		std::string mTarget;
		RobotomyRequestForm(void);
};

#endif