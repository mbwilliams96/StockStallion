#include <limits>
#include "StockStallion.h"
#include "sqlite3.h"
#include <fstream>
#include <iostream>

StockStallion::StockStallion() {

}

std::string StockStallion::loginRegisterPrompt() {
    std::cout << "Welcome to StockStallion" << std::endl;
    std::cout << "Please enter a selection: (1 or 2)" << std::endl;
    std::cout << "[1] Register: \n";
    std::cout << "[2] Log in " << std::endl;
    std::string choice;
    std::cin >> choice;
    return choice;
}

bool StockStallion::verifyPassword(std::string pw) {
    try{
        std::ifstream infile;
        infile.open("~/")
    } catch (){

    }
}