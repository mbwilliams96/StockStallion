#include <limits>
#include "StockStallion.h"
#include "sqlite3.h"
#include <fstream>
#include <cstdlib>
#include <iostream>

StockStallion::StockStallion() {

}

static std::string StockStallion::loginRegisterPrompt() {
    //However, cin extraction always considers spaces (whitespaces, tabs, new-line...) as terminating the value being
    // extracted, and thus extracting a string means to always extract a single word,
    // not a phrase or an entire sentence.
    std::string choice = " ";
    while (!(choice == "1") || (choice == "2")) {
        std::cout << "Welcome to StockStallion" << std::endl;
        std::cout << "Please enter a selection: (1 or 2)" << std::endl;
        std::cout << "[1] Register: \n";
        std::cout << "[2] Log in " << std::endl;
        std::cin >> choice;
    }
    return choice;
}

static bool StockStallion::authorizeLogin(std::string _Username, std::string _Password) {
    if( this ->verifyUsername(_Username)){
       if(this -> verifyPassword(_Password)){
           return true;
       }
        else{
           return false;
       }
    }
    else{
        return false;
    }

}

static bool StockStallion::verifyPassword(std::string pw) {
    try{
        std::ifstream infile;
        std::string password;
        infile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        infile.open("/home/botnet/SS",std::ios::in);
        while(!infile.eof()){
            infile >> password;
            std::cout << password << std::endl;
            if(password == pw){
                std::cout << "password found" << std::endl;
                return true;
            }
        }
        std::cout << "password not found" << std::endl;
        infile.close();
        return false;


    } catch (std::ifstream::failure e){
        std::cerr << "file doesn't exist " << std::endl;
        std::exit(1);
    }
}

static bool StockStallion::verifyUsername(std::string username) {
    try{
        std::ifstream infile;
        std::string username_;
        infile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        infile.open("/home/botnet/SS",std::ios::in);
        while(!infile.eof()){
            infile >> username_;
            std::cout << username_ << std::endl;
            if(username_ == username){
                std::cout << "username found" << std::endl;
                return true;
            }
        }
        std::cout << "username not found" << std::endl;
        infile.close();
        return false;


    } catch (std::ifstream::failure e){
        std::cerr << "file doesn't exist " << std::endl;
        std::exit(1);
    }
}

static bool StockStallion::registerNewUser() {}

int main() {
    
    return 0;
}