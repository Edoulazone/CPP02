/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:58:03 by eschmitz          #+#    #+#             */
/*   Updated: 2025/03/13 16:19:30 by eschmitz         ###   ########.fr       */
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
		Fixed(int const n);
		Fixed(float const n);

		Fixed&	operator=(Fixed const &copy);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream&	operator<<(std::ostream &o, Fixed const &fixed);

#endif