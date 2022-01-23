//TODO:
//w konkretnym polu sprawdzenie czy podajesz pole (0,36)
//dodac nowa funkcje find
//poprawic clear dla windowsa
#include <iostream>
#include "ruletka.h"
#include <stdlib.h>
#include <random>
int PLAYER_MONEY = 40;
int pool[36] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36};
int biale[18] = {1,3,5,7,9,11,13,15,17,19,21,23,27,25,29,33,31,35};
int czerwone[18] = {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36};
std::string BetTypeStr[11] = {"pola 1-12","pola 13-24", "pola 25-36","pola 1-18","pola 19-36","parzyste","nieparzyste","biale","czerwone","konkretne pole","pole 0"};
int mnoznik[11] = {3,3,3,2,2,2,2,2,2,36,100};
bool CanPlay;
int mlp;
int wybor;
bool PlayAgain;
std::string jeszcze_raz;
int wybrane_pole;
int bet = 0;
// rysowanie planszy
auto DrawBoard() -> void{
    for(int x = 3;x<=36;x+=3){
        std::cout << x<<" ";
        x+=3;
        std::cout << "\033[1;31m"<< x << " \033[0m";
    }
    std::cout<<"\n";
    for(int x= 2; x<=35;x+=3){
        std::cout << "\033[1;31m"<< x << " \033[0m";
        x+=3;
        std::cout << x<<" ";
    }
    std::cout<<"\n";
    for(int x= 1; x<=35;x+=3){
        std::cout << x<<" ";
        x+=3;
        std::cout << "\033[1;31m"<< x << " \033[0m";
    }
    std::cout <<"\n";

}
//konfiguracja zakladu
auto BetSetup() -> void{
    mlp = mnoznik[wybor-1];
    std::cout <<"Masz: "<< PLAYER_MONEY <<"PLN\n";
    std::cout << "ile chcesz postawic (min 10, max 50): ";
    std::cin >> bet;
    while(bet <10 || bet > 50){
        std::cout << "Podaj poprawna wartosc! \n";
        std::cout << "ile chcesz postawic (min 10, max 50): ";
        std::cin >> bet;
    }
    if(bet>PLAYER_MONEY){
        std::cout <<"nie masz tyle pieniedy! \n";
        CanPlay = false;
        return;
    }else{
        PLAYER_MONEY = PLAYER_MONEY - bet;
        CanPlay = true;
        return;
    }
    return;
}

auto win(int zaklad, int Wmnoznik) -> void{
    std::cout << "postawiles: " << zaklad <<"\n";
    std::cout << "mnoznik wygranej: " << Wmnoznik <<"\n";
    int wygrana;
    wygrana = (zaklad * Wmnoznik);
    std::cout <<"Gratulacje! wygrales: "<<wygrana<<"\n";
    PLAYER_MONEY=PLAYER_MONEY + wygrana;
    return;
}
auto lose() -> void{
    return;
}

//glowna funkcja ruletki
auto ruletka_main() ->int{
    system("CLEAR");
    DrawBoard();
    std::cout << "\n Rodzaje zakladów \n";
    for(int i = 0; i<11;i++){
        std::cout<<i+1 <<". "<<BetTypeStr[i] <<" (" << mnoznik[i]<<"x)\n";
    }
    std::cout << "\n0. wyjscie.\n";
    std::cout<<"podaj numer zakladu: ";
    std::cin >> wybor;
    while (wybor<0 || wybor>11){
        std::cout << "nie ma takiego zakladu, podaj poprawny numer: ";
        std::cin >> wybor;
    }
    switch(wybor){
        case 1: //pola 1-12
            std::cout << "\nrodzaj zakładu: "<< BetTypeStr[wybor-1]<<"\n";
            BetSetup();
            if(CanPlay){
                //GRA
                std::random_device rd ;
                std::uniform_int_distribution < int > random (0 , 36);
                int wylosowane_pole = random(rd);
                if(wylosowane_pole>=1 && wylosowane_pole<=12){
                    std::cout << "\nwylosowane pole: "<< wylosowane_pole<<"\n";
                    std::cout << "Gratulacje wygrales! \n";
                    win(bet, mnoznik[wybor-1]);
                }else{
                    std::cout << "\nwylosowane pole: "<< wylosowane_pole<<"\n";
                    std::cout <<"Niestety nie udalo sie. \n";
                    lose();
                }
            }
            else{
                std::cout << "niestety nie mozesz zagrac \n";
            }
            break;
        case 2: //pola 13-24
            std::cout << "rodzaj zakładu: "<< BetTypeStr[wybor-1]<<"\n";
            BetSetup();
            if(CanPlay){
                //GRA
                std::random_device rd ;
                std::uniform_int_distribution < int > random (0 , 36);
                int wylosowane_pole = random(rd);
                if(wylosowane_pole>=13 && wylosowane_pole<=24){
                    std::cout << "\nwylosowane pole: "<< wylosowane_pole<<"\n";
                    std::cout << "Gratulacje wygrales! \n";
                    win(bet, mnoznik[wybor-1]);
                }else{
                    std::cout << "\nwylosowane pole: "<< wylosowane_pole<<"\n";
                    std::cout <<"Niestety nie udalo sie. \n";
                    lose();
                }
            }
            else{
                std::cout << "niestety nie mozesz zagrac \n";
            }
            break;
        case 3: //pola 25-36
            std::cout << "rodzaj zakładu: "<< BetTypeStr[wybor-1]<<"\n";
            BetSetup();
            if(CanPlay){
                //GRA
                std::random_device rd ;
                std::uniform_int_distribution < int > random (0 , 36);
                int wylosowane_pole = random(rd);
                if(wylosowane_pole>=25 && wylosowane_pole<=36){
                    std::cout << "\nwylosowane pole: "<< wylosowane_pole<<"\n";
                    std::cout << "Gratulacje wygrales! \n";
                    win(bet, mnoznik[wybor-1]);
                }else{
                    std::cout << "\nwylosowane pole: "<< wylosowane_pole<<"\n";
                    std::cout <<"Niestety nie udalo sie. \n";
                    lose();
                }
            }
            else{
                std::cout << "niestety nie mozesz zagrac \n";
            }
            break;
        case 4: //pola 1-18
            std::cout << "rodzaj zakładu: "<< BetTypeStr[wybor-1]<<"\n";
            BetSetup();
            if(CanPlay){
                //GRA
                std::random_device rd ;
                std::uniform_int_distribution < int > random (0 , 36);
                int wylosowane_pole = random(rd);
                if(wylosowane_pole>=1 && wylosowane_pole<=18){
                    std::cout << "\nwylosowane pole: "<< wylosowane_pole<<"\n";
                    std::cout << "Gratulacje wygrales! \n";
                    win(bet, mnoznik[wybor-1]);
                }else{
                    std::cout << "\nwylosowane pole: "<< wylosowane_pole<<"\n";
                    std::cout <<"Niestety nie udalo sie. \n";
                    lose();
                }
            }
            else{
                std::cout << "niestety nie mozesz zagrac \n";
            }
            break;
        case 5: //pola 19-36
            std::cout << "rodzaj zakładu: "<< BetTypeStr[wybor-1]<<"\n";
            BetSetup();
            if(CanPlay){
                //GRA
                std::random_device rd ;
                std::uniform_int_distribution < int > random (0 , 36);
                int wylosowane_pole = random(rd);
                if(wylosowane_pole>=19 && wylosowane_pole<=36){
                    std::cout << "\nwylosowane pole: "<< wylosowane_pole<<"\n";
                    std::cout << "Gratulacje wygrales! \n";
                    win(bet, mnoznik[wybor-1]);
                }else{
                    std::cout << "\nwylosowane pole: "<< wylosowane_pole<<"\n";
                    std::cout <<"Niestety nie udalo sie. \n";
                    lose();
                }
            }
            else{
                std::cout << "niestety nie mozesz zagrac \n";
            }
            break;
        case 6: //parzyste
            std::cout << "rodzaj zakładu: "<< BetTypeStr[wybor-1]<<"\n";
            BetSetup();
            if(CanPlay){
                //GRA
                std::random_device rd ;
                std::uniform_int_distribution < int > random (0 , 36);
                int wylosowane_pole = random(rd);
                if(wylosowane_pole%2==0){
                    std::cout << "\nwylosowane pole: "<< wylosowane_pole<<"\n";
                    std::cout << "Gratulacje wygrales! \n";
                    win(bet, mnoznik[wybor-1]);
                }else{
                    std::cout << "\nwylosowane pole: "<< wylosowane_pole<<"\n";
                    std::cout <<"Niestety nie udalo sie. \n";
                    lose();
                }
            }
            else{
                std::cout << "niestety nie mozesz zagrac \n";
            }
            break;
        case 7: //nieparzyste
            std::cout << "rodzaj zakładu: "<< BetTypeStr[wybor-1]<<"\n";
            BetSetup();
            if(CanPlay){
                //GRA
                std::random_device rd ;
                std::uniform_int_distribution < int > random (0 , 36);
                int wylosowane_pole = random(rd);
                if(wylosowane_pole%2!=0){
                    std::cout << "\nwylosowane pole: "<< wylosowane_pole<<"\n";
                    std::cout << "Gratulacje wygrales! \n";
                    win(bet, mnoznik[wybor-1]);
                }else{
                    std::cout << "\nwylosowane pole: "<< wylosowane_pole<<"\n";
                    std::cout <<"Niestety nie udalo sie. \n";
                    lose();
                }
            }
            else{
                std::cout << "niestety nie mozesz zagrac \n";
            }
            break;
        case 8: //biale
            std::cout << "rodzaj zakładu: "<< BetTypeStr[wybor-1]<<"\n";
            BetSetup();
            if(CanPlay){
                //GRA
                std::random_device rd ;
                std::uniform_int_distribution < int > random (0 , 36);
                int wylosowane_pole = random(rd);
                // if(std::find(std::begin(biale), std::end(biale), wylosowane_pole) != std::end(biale)){
                if (1==1){
                    std::cout << "\nwylosowane pole: "<< wylosowane_pole<<"\n";
                    std::cout << "Gratulacje wygrales! \n";
                    win(bet, mnoznik[wybor-1]);
                }else{
                    std::cout << "\nwylosowane pole: "<< wylosowane_pole<<"\n";
                    std::cout <<"Niestety nie udalo sie. \n";
                    lose();
                }
            }
            else{
                std::cout << "niestety nie mozesz zagrac \n";
            }
            break;
        case 9: //czerwone
            std::cout << "rodzaj zakładu: "<< BetTypeStr[wybor-1]<<"\n";
            BetSetup();
            if(CanPlay==true){
                //GRA
                std::random_device rd ;
                std::uniform_int_distribution < int > random (0 , 36);
                int wylosowane_pole = random(rd);
                //if((std::find(std::begin(czerwone), std::end(czerwone), wylosowane_pole) != std::end(czerwone))){
                if (1==1){
                    std::cout << "\nwylosowane pole: "<< wylosowane_pole<<"\n";
                    std::cout << "Gratulacje wygrales! \n";
                    win(bet, mnoznik[wybor-1]);
                }else{
                    std::cout << "\nwylosowane pole: "<< wylosowane_pole<<"\n";
                    std::cout <<"Niestety nie udalo sie. \n";
                    lose();
                }
            }
            else{
                std::cout << "niestety nie mozesz zagrac \n";
            }
            break;
        case 10: //konkretne pole
            std::cout << "rodzaj zakładu: "<< BetTypeStr[wybor-1]<<"\n";
            BetSetup();
            if(CanPlay){
                //GRA
                std::random_device rd ;
                std::uniform_int_distribution < int > random (0 , 36);
                int wylosowane_pole = random(rd);
                std::cout <<"\nktore chcesz obstawic: ";
                std::cin >> wybrane_pole;
                if(wylosowane_pole==wybrane_pole){
                    std::cout << "\nwylosowane pole: "<< wylosowane_pole<<"\n";
                    std::cout << "Gratulacje wygrales! \n";
                    win(bet, mnoznik[wybor-1]);
                }else{
                    std::cout << "\nwylosowane pole: "<< wylosowane_pole<<"\n";
                    std::cout <<"Niestety nie udalo sie. \n";
                    lose();
                }
            }
            else{
                std::cout << "niestety nie mozesz zagrac \n";
            }
            break;
        case 11: //pole 0
            std::cout << "rodzaj zakładu: "<< BetTypeStr[wybor-1]<<"\n";
            BetSetup();
            if(CanPlay){
                //GRA
                std::random_device rd ;
                std::uniform_int_distribution < int > random (0 , 36);
                int wylosowane_pole = random(rd);
                if(wylosowane_pole==0){
                    std::cout << "\nwylosowane pole: "<< wylosowane_pole<<"\n";
                    std::cout << "Gratulacje wygrales! \n";
                    win(bet, mnoznik[wybor-1]);
                }else{
                    std::cout << "\nwylosowane pole: "<< wylosowane_pole<<"\n";
                    std::cout <<"Niestety nie udalo sie. \n";
                    lose();
                }
            }
            else{
                std::cout << "niestety nie mozesz zagrac \n";
            }
            break;
        case 0:
            std::cout << "\ngra w ruletke zakonczy sie \n";
            break;
        default:
            std::cout << "cos nie tak";
            break;
    }
    return 0;
}
auto RULETKAMAIN() -> int{
    do{
        ruletka_main();
        std::cout << "Czy chcesz zagrac jeszcze raz? (tak/nie): ";
        std::cin >> jeszcze_raz;
        if (jeszcze_raz=="tak"){
            PlayAgain = true;
        }
        if (jeszcze_raz=="nie"){
            PlayAgain = false;
        }
        if (jeszcze_raz !="tak"&&jeszcze_raz!="nie"){
            std::cout << "nie ma takiej opcji! program zakonczy sie!";
            PlayAgain = false;
        }

    }while(PlayAgain);

    return 0;
}
/*auto main() -> int{
    RULETKAMAIN();
} */
