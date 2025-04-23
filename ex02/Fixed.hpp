/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:25:06 by eschmitz          #+#    #+#             */
/*   Updated: 2025/04/23 12:45:58 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

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

		bool	operator>(Fixed const &copy) const;
		bool	operator<(Fixed const &copy) const;
		bool	operator>=(Fixed const &copy) const;
		bool	operator<=(Fixed const &copy) const;
		bool	operator==(Fixed const &copy) const;
		bool	operator!=(Fixed const &copy) const;

		Fixed	operator+(Fixed const &copy) const;
		Fixed	operator-(Fixed const &copy) const;
		Fixed	operator*(Fixed const &copy) const;
		Fixed	operator/(Fixed const &copy) const;

		Fixed&	operator++();
		Fixed&	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);

		static Fixed	&min(Fixed &a, Fixed &b);
		const static Fixed	&min(Fixed const &a, Fixed const &b);
		static Fixed	&max(Fixed &a, Fixed &b);
		const static Fixed	&max(Fixed const &a, Fixed const &b);
};

std::ostream&	operator<<(std::ostream &o, Fixed const &fixed);

#endif