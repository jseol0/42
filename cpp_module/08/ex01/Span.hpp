/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:24:00 by jseol             #+#    #+#             */
/*   Updated: 2022/08/15 17:24:57 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <vector>
# include <climits>

class Span
{
	private:
		unsigned int n;
		std::vector<int> vec;
		Span();
	
	public:
		Span(unsigned int n);
		Span(const Span& other);
		~Span();

		Span&	operator=(const Span& rhs);

		void	addNumber(int num);
		void	addNumber(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;
};

#endif