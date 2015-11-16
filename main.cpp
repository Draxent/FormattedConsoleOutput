/**
 *	@file main.cpp
 *  @brief Example of usage of \ref FCO objects.
 *  @author Federico Conte (draxent)
 */

#include <iostream>
#include "fco.hpp"

using namespace fco;

int main( )
{
	FCO f1;
	f1.add( BG_BLUE );
	f1.add( FG_LIGHT_YELLOW );
    std::cout << f1.apply("Text with background in blue and foreground in yellow!") << std::endl;

    FCO f2({ FG_LIGHT_GREEN, BOLD, ITALIC, UNDERLINE });
    std::cout << f2.apply("Now we use a different style!") << std::endl;

    // Reuse of f1 style with a different text
    std::cout << f1.apply("Another text with background in blue and foreground in yellow!") << std::endl;

    // Sum of properties, f1 have more priority than f2
    FCO f3 = f1 + f2;
    std::cout << f1.apply("Again another text with background in ") << f3.apply("blue");
    std::cout << f1.apply(" and foreground in ") << f3.apply("yellow") << f1.apply("!") << std::endl;

    // Other type of constructor
    FCO f4( f2 );
    f4.add({ FG_RED, SELECTED });
    f4.remove( UNDERLINE );
    std::cout << f4.apply("Starting from f2 we made some changes to its style.") << std::endl;

    return 0;
}

