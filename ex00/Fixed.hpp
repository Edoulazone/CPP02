/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:18:56 by eschmitz          #+#    #+#             */
/*   Updated: 2025/03/13 15:43:27 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_fixValue;
		static const int	_fractBits = 8;

	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const &copy);
		Fixed&	operator=(Fixed const &copy);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif