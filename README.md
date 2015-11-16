# FCO (Formatted Console Output)

###Description
Print formatted output on your Linux console through the use of a simple interface.

The implementation is inspired by : <br/>
[cout_col v1.0.2](https://github.com/tomveltmeijer/cout_col) <br/>
The MIT License (MIT) <br/>
Copyright (c) 2015 [Tom Veltmeijer](https://github.com/tomveltmeijer) <br/>
http://opensource.org/licenses/MIT <br/>

###Demonstration
```C++
#include <iostream>
#include "fco.hpp"

using namespace fco;

int main( int argc, char* argv[] )
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
```
<img src="https://github.com/Draxent/FormattedConsoleOutput/blob/master/demo.png">

###License
The MIT License (MIT)

Copyright (c) 2015 Federico Conte

http://opensource.org/licenses/MIT
