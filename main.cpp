#include "ruletka.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <random>
#include "sloty.h"
int TestowyInt;
auto main()-> int{
    std::cin >> TestowyInt;
    switch(TestowyInt) {
        case 1:
            RULETKAMAIN();

        case 2:
            SLOTY_MAIN();
    }
    return 0;
}