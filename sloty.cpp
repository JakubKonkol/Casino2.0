#include <iostream>
#include <stdlib.h>
#include <random>
#include <string>
#include "sloty.h"
std::string twojwybor;
int ws1,ws2,ws3;
bool S_CanPlay = true;
bool S_PlayAgain = true;
int S_PLAYER_MONEY = 1000;
int S_zaklad;
int S_jeszczeraz;
auto S_BetSetup() -> void{
    std::cout <<"Masz: "<< S_PLAYER_MONEY <<"PLN\n";
    std::cout <<"Ile chcesz postawic?(min 10, max 100pln)\n";
    std::cin >> S_zaklad;
    while(S_zaklad <10 || S_zaklad > 100){
        std::cout << "Podaj poprawna wartosc! \n";
        std::cout << "ile chcesz postawic (min 10, max 50): ";
        std::cin >> S_zaklad;
    }
    if(S_zaklad>S_PLAYER_MONEY){
        std::cout <<"nie masz tyle pieniedy! \n";
        S_CanPlay = false;
        return;
    }else{
        S_PLAYER_MONEY = S_PLAYER_MONEY - S_zaklad;
        S_CanPlay = true;
        return;
    }
    return;
}
auto S_losuj() -> int{
    std::random_device rd ;
    std::uniform_int_distribution < int > random (1 , 7);
    int wylosowany_slot1= random(rd);
    int wylosowany_slot2= random(rd);
    int wylosowany_slot3= random(rd);
    ws1 = wylosowany_slot1;
    ws2 = wylosowany_slot2;
    ws3 = wylosowany_slot3;
    return 0;
}
auto S_win(int beciak, int S_mnoznik) -> void{
    int winek = beciak*S_mnoznik;
    S_PLAYER_MONEY = S_PLAYER_MONEY + winek;
    std::cout << "Gratulacje wygrałeś: "<< winek<<" PLN \n";
    return;
}
auto S_lose() -> void{
    std::cout <<"niestety nie udalo sie! \n";
    std::cout <<"chcesz zagrac jeszcze raz? 1.tak 2.nie 3.zmien zaklad";
    std::cin >> S_jeszczeraz;
    switch (S_jeszczeraz){
        case 1:
            S_PlayAgain = true;
            gra();
            break;
        case 2:
            S_PlayAgain = false;
            SLOTY_MAIN();
            break;
        case 3:
            S_BetSetup();
            gra();
            break;
    }
    return;
}
auto gra() -> void{
    if(S_CanPlay){
        S_PLAYER_MONEY = S_PLAYER_MONEY-S_zaklad;
        std::cout << "\n---------------------------------------\n";
        S_losuj();
        std::cout << "WYLOSOWANE LICZBY TO...: \n";
        std::cout << "\n---------------------------------------\n";
        std::cout <<  ws1 << "  "<< ws2 << "  " << ws3 << "";
        std::cout << "\n---------------------------------------\n";
        if(ws1 != 7 && ws2 != 7 && ws3 != 7){
            if(ws1 == ws2 && ws2 == ws3){
                S_win(S_zaklad, 50);
            }
            else{
                S_lose();
            }
        }if(ws1==7 && ws2==7 && ws3==7){
            S_win(S_zaklad, 500);
        }
        else{
            S_lose();
        }

    }



}
auto SLOTY_MAIN()-> int{
    if(S_PlayAgain){
        std::cout << "\n---------------------------------------\n";
        S_BetSetup();
        while(S_PlayAgain){
            gra();
        }

    }
    if(S_PlayAgain==false){
        std::cout << "gra zakonczy sie\n";
    }
    return 0;
}
/*
auto main() -> int {
    SLOTY_MAIN();
    return 0;
}
 */
//