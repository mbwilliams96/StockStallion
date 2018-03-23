#include <limits>
#include "StockStallion.h"
#include "sqlite3.h"
#include <fstream>
#include <iostream>

StockStallion::StockStallion() {

}

std::string StockStallion::loginRegisterPrompt() {
    std::string choice;
    do {
        std::cout << "Welcome to StockStallion" << std::endl;
        std::cout << "Please enter a selection: (1 or 2)" << std::endl;
        std::cout << "[1] Register: \n";
        std::cout << "[2] Log in " << std::endl;
        std::cin >> choice;
    }
    while (choice != "1" || choice != "2");
    return choice;
}

bool StockStallion::verifyPassword(std::string pw) {
    try{
        std::ifstream infile;
        infile.open("~/Stockstallion.txt");

    } catch (if){

    }
}