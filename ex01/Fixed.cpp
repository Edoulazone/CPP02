/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:58:01 by eschmitz          #+#    #+#             */
/*   Updated: 2025/03/13 16:24:01 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _fixValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(int const n) {
	std::cout << "Int constructor called" << std::endl;
	_fixValue = n << _fractBits;
}

Fixed::Fixed(float const n) {
	std::cout << "Float constructor called" << std::endl;
	_fixValue = (int)(n * (1 << _fractBits));
}

Fixed&	Fixed::operator=(Fixed const &copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		_fixValue = copy.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const {
	return (_fixValue);
}

void	Fixed::setRawBits(int const raw) {
	_fixValue = raw;
}

float	Fixed::toFloat(void) const {
	return ((float)_fixValue / (float)(1 << _fractBits));
}

int	Fixed::toInt(void) const {
	return ((int)(_fixValue >> _fractBits));
}

std::ostream&	operator<<(std::ostream &o, Fixed const &fixed) {
	o << fixed.toFloat();
	return (o);
}