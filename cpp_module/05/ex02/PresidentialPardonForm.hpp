/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:59:13 by jseol             #+#    #+#             */
/*   Updated: 2022/08/05 19:03:56 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "Form.hpp"

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm(const std::string target);
		~PresidentialPardonForm();

		PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);

		virtual void action(void) const;
	private:
		std::string mTarget;
		PresidentialPardonForm(void);
};

#endif