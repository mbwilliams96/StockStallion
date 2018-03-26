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

bool StockStallion::authorizeLogin() {
    std::cout << "Thank you for signing into StockStallion" << std::endl;
    std::cout << "Please enter your Username: ";
    std::string name;
    std::cin >> name;
    if (this ->verifyUsername(name)){
        std::cout << " " << std::endl;
        std::cout << "Please enter your password: ";
        std::string password;
        std::cin >> password;
        if(this -> verifyPassword(password)){
            std::cout << " " << std::endl;
            std::cout << "Congratulations for logging in !" << std::endl;
            std::cout << "I have no idea what to do!" << std::endl;
        }
    }
    return true;

}

bool StockStallion::verifyPassword(std::string &pw) {
    std::ifstream infile;
    std::string password;
    infile.open("../SS",std::ios::in);
    if(infile.eof()){
        std::cerr << "file doesn't exist " << std::endl;
        std::exit(1);
    }
    while(infile.good()){
        infile >> password;
        if(password == pw){
            std::cout << "password found" << std::endl;
            return true;
        }
    }
    std::cout << "password doesn't exist" << std::endl;
    return false;

}

bool StockStallion::verifyUsername(std::string &username) {
    std::ifstream infile;
    std::string user;
    infile.open("../SS",std::ios::in);
    if(infile.eof()){
        std::cerr << "file doesn't exist " << std::endl;
        std::exit(1);
    }
    while(infile.good()){
        infile >> user;
        if(user == username){
            std::cout << "username found" << std::endl;
            return true;
        }
    }
    std::cout << "username doesn't exist" << std::endl;
    return false;
}

bool StockStallion::is_name_alphanumeric(std::string &_name_) {
    /**
     * string must be at least 10 characters long and contain only
     * numerals or letters
     */
    int integer = 0;
    int chara = 0;
    for(int i = 0; i < _name_.length(); i++){
        if(isdigit(_name_[i])){
            integer++;
        }
        else if(isalpha(_name_[i])){
            chara++;
        }
        else{
            return false;
        }
    }
    if (chara > 1 && integer > 1){
        if(_name_.length() > 9){
            return true;
        }
    }
    return false;
}

static bool does_pass_pass(std::string &_pass_){
    int integer = 0;
    int chara = 0;
    for(int i = 0; i < _pass_.length(); i++){
        if(isdigit(_pass_[i])){
            integer++;
        }
        else if(isalpha(_pass_[i])){
            chara++;
        }
        else{
            return false;
        }
    }
    if (chara > 1 && integer > 1){
        if(_pass_.length() > 7 && _pass_.length() < 21){
            return true;
        }
    }
    return false;
}

std::string StockStallion::registerNewUser() {
    std::string name;
    std::cout << "Hello and welcome to our game \n";
    std::cout << "if you want to play create a name \n";
    std::cout << "Alphanumeric characters only and at least 10 characters: ";
    std::cin >> name;
    while(!is_name_alphanumeric(name)){
        std::cout << "sorry that username isn't accepted" << std::endl;
        std::cout << "Please enter an alphanumeric username: ";
        std::cin >> name;
    }
    return name;
}

std::string registerNewPass(){
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

void StockStallion::registrationSuccess(std::string &username, std::string &password) {
    std::ofstream outputfile;
    std::ifstream inputfile;
    inputfile.open("../SS",std::ios::in);
    if(inputfile.eof()){
        inputfile.close();
    }
    else{
        std::string read;
        while(inputfile.good()){
            inputfile >> read;
            if(read == username){
                std::cout << "there is a matching username" << std::endl;
                std::cout << "close the program and try again" << std::endl;
                exit(0);
            }
        }
    }
    inputfile.close();
    outputfile.open("../SS",std::ios::app);
    if(outputfile.eof()){
        std::cerr << "something went wrong " << std::endl;
        exit(1);
    }
    outputfile << username << "\n";
    outputfile << password << "\n";
    outputfile.close();
}

int main() {
    std::string choice;
    choice = StockStallion::loginRegisterPrompt();
    if (choice == "1"){
        std::string name;
        std::string pass;
        name = StockStallion::registerNewUser();
        pass = registerNewPass();
        StockStallion::registrationSuccess(name,pass);
    }
    StockStallion stallion;
    stallion.authorizeLogin();
    return 0;
}
