#include "ruletka.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <random>
#include "sloty.h"
int WyborGry;
auto main() -> int{
    std::cout << "-------------------------------------------------------\n";
    std::cout << "Witaj w Kasynie\n";
    std::cout << "dostepne gry to 1. ruletka 2.sloty \n";
    std::cout << "Wybierz gre wpisujac odpowiedni numer gry\n";
    std::cin >> WyborGry;

    switch(WyborGry){
        case 1:
            RULETKAMAIN();
            break;
        case 2:
            SLOTY_MAIN();
            break;
    }
}
//