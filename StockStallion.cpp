#include <limits>
#include "StockStallion.h"
#include "sqlite3.h"
#include <fstream>
#include <cstdlib>
#include <iostream>

StockStallion::StockStallion() {

}

std::string StockStallion::loginRegisterPrompt() {
    //However, cin extraction always considers spaces (whitespaces, tabs, new-line...) as terminating the value being
    // extracted, and thus extracting a string means to always extract a single word,
    // not a phrase or an entire sentence.
    std::string choice = " ";
    while (!((choice == "1") || (choice == "2"))) {
        std::cout << "Welcome to StockStallion" << std::endl;
        std::cout << "Please enter a selection: (1 or 2)" << std::endl;
        std::cout << "[1] Register: \n";
        std::cout << "[2] Log in " << std::endl;
        std::cin >> choice;
    }
    return choice;
}

bool StockStallion::authorizeLogin(std::string _Username, std::string _Password) {
    if( StockStallion::verifyUsername(_Username)){
       if(StockStallion::verifyPassword(_Password)){
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

bool StockStallion::verifyPassword(std::string pw) {
    try{
        std::ifstream infile;
        std::string password;
        infile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        infile.open("../SS",std::ios::in);
        while(infile.good()){
            if(infile.eof()){
                break;
            }
            if(password == pw){
                std::cout << "password found" << std::endl;
                return true;
            }
            infile >> password;
        }
        std::cout << "password doesn't exist" << std::endl;
    } catch (std::ifstream::failure e){
        std::cerr << "file doesn't exist " << std::endl;
        std::exit(1);
    }
}

bool StockStallion::verifyUsername(std::string username) {
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

static bool is_name_alphanumeric(std::string &_name_) {
    /**
     * string must be at least 10 characters long and contain only
     * numerals or letters
     */
    for(int i = 0; i < _name_.length(); i++){
        if(isalnum(_name_[i])){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}

static bool does_pass_pass(std::string &_pass_){
    if (_pass_.size() > 7 && _pass_.size() < 21) {
        for (int i = 0; i < _pass_.length(); i++) {
            if (isalnum(_pass_[i])) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    } else{
        return false;
    }
}

static std::string registerNewUser() {
    std::string name;
    std::cout << "Hello and welcome to our game \n";
    std::cout << "if you want to play create a name \n";
    std::cout << "Alphanumeric characters only: ";
    std::cin >> name;
    while(!is_name_alphanumeric(name)){
        std::cout << "sorry that username isn't accepted" << std::endl;
        std::cout << "Please enter an alphanumeric username: ";
        std::cin >> name;
    }
    return name;
}

static std::string registerNewPass(){
    std::string pass;
    std::cout << "now you make the password \n";
    std::cout << "it's quite simple actually \n";
    std::cout << "Alphanumeric and be between 8-20 characters: ";
    std::cin >> pass;
    while(!does_pass_pass(pass)){
        std::cout << "sorry that password isn't accepted" << std::endl;
        std::cout << "Please enter an alphanumeric password 8-20 characters long: ";
        std::cin >> pass;
    }
    return pass;
}

int main() {
    StockStallion a;
    a.verifyPassword("hello");
    return 0;
}