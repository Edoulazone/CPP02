/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:25:03 by eschmitz          #+#    #+#             */
/*   Updated: 2025/04/23 12:45:51 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _fixValue(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(int const n) {
	// std::cout << "Int constructor called" << std::endl;
	_fixValue = n << _fractBits;
}

Fixed::Fixed(float const n) {
	// std::cout << "Float constructor called" << std::endl;
	_fixValue = roundf(n * (1 << _fractBits));
}

Fixed&	Fixed::operator=(Fixed const &copy) {
	// std::cout << "Copy assignment operator called" << std::endl;
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

bool	Fixed::operator>(Fixed const &copy) const {
	return (getRawBits() > copy.getRawBits());
}

bool	Fixed::operator<(Fixed const &copy) const {
	return (getRawBits() < copy.getRawBits());
}

bool	Fixed::operator>=(Fixed const &copy) const {
	return (getRawBits() >= copy.getRawBits());
}

bool	Fixed::operator<=(Fixed const &copy) const {
	return (getRawBits() <= copy.getRawBits());
}

bool	Fixed::operator==(Fixed const &copy) const {
	return (getRawBits() == copy.getRawBits());
}

bool	Fixed::operator!=(Fixed const &copy) const {
	return (getRawBits() != copy.getRawBits());
}

Fixed	Fixed::operator+(Fixed const &copy) const {
	Fixed	res;
	res.setRawBits(getRawBits() + copy.getRawBits());
	return (res);
}

Fixed	Fixed::operator-(Fixed const &copy) const {
	Fixed	res;
	res.setRawBits(getRawBits() - copy.getRawBits());
	return (res);
}

Fixed	Fixed::operator*(Fixed const &copy) const {
	Fixed	res;
	res.setRawBits(getRawBits() * copy.getRawBits() >> _fractBits);
	return (res);
}

Fixed	Fixed::operator/(Fixed const &copy) const {
	Fixed	res;
	res.setRawBits(getRawBits() / copy.getRawBits() << _fractBits);
	return (res);
}

Fixed&	Fixed::operator++() {
	_fixValue++;
	return (*this);
}

Fixed&	Fixed::operator--() {
	_fixValue--;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	temp(*this);
	operator++();
	return (temp);
}

Fixed	Fixed::operator--(int) {
	Fixed	temp(*this);
	operator--();
	return (temp);
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b) {
	if (a._fixValue > b._fixValue)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b) {
	if (a._fixValue > b._fixValue)
		return (a);
	return (b);
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b) {
	if (a._fixValue < b._fixValue)
		return (a);
	return (b);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b) {
	if (a._fixValue < b._fixValue)
		return (a);
	return (b);
}

std::ostream&	operator<<(std::ostream &o, Fixed const &fixed) {
	o << fixed.toFloat();
	return (o);
}