//
// Created by Waif Jonathon on 3/24/22.
//

#include "Fixed.hpp"

int	main(){
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;

		std::cout << Fixed::max( a, b ) << std::endl;
	}
	{
		Fixed a;
		Fixed q;

		a.setRawBits(9);
		std::cout << std::endl << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		const Fixed b(Fixed(10.05f) * Fixed(2));
		const Fixed c(Fixed(5.05f) + Fixed(2));
		Fixed const d(Fixed(5.05f) - Fixed(2));
		Fixed const e(Fixed(6.06f) / Fixed(2));

		std::cout << std::endl << b << std::endl;
		std::cout << c << std::endl;
		std::cout << d << std::endl;
		std::cout << e << std::endl;

		std::cout << std::endl << Fixed::min(a, q) << std::endl;
		std::cout << Fixed::min( c, b) << std::endl;
	}
}
