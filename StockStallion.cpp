#include <limits>
#include "StockStallion.h"
#include "sqlite3.h"
#include <fstream>
#include <iostream>

StockStallion::StockStallion() {

}

std::string StockStallion::loginRegisterPrompt() {
    std::string choice = " ";
    while (choice != "1" || choice != "2") {
        std::cout << "Welcome to StockStallion" << std::endl;
        std::cout << "Please enter a selection: (1 or 2)" << std::endl;
        std::cout << "[1] Register: \n";
        std::cout << "[2] Log in " << std::endl;
        std::cin >> choice;
        try {
            std::stoi(choice);
        }
        catch (std::invalid_argument w) {
            std::cerr << "error";
            std::exit(1);
        }
    }
    if(std::cin.get() == ' '){
        while(std::cin.get() != '\n'){
            std::cin.clear();
        }
    }
    return choice;
}
/**
bool StockStallion::verifyPassword(std::string pw) {
    try{
        std::ifstream infile;
        infile.open("~/Stockstallion.txt");

    } catch (if){

    }
}
 */

int main(){
    StockStallion a;
    a.loginRegisterPrompt();
}