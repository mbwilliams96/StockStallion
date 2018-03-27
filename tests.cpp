#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "sqlite3.h"
#include "StockStallion.h"

template <typename T>
T requestInputFromUser(const std::string &userPrompt){
    std::cout << userPrompt << "\n> ";
    T out = T();
    while (!(std::cin >> out)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
        std::cout << "Error!" "\n";
        std::cout << userPrompt << "\n> ";
    }
    return out;
}

int main(){
  // ### Simple Authentication Registration Test  ### //
  // std::ofstream exampleAuthFile;
  //
  // std::string exampleUsername = "GregGNV101";
  // std::string examplePassword = "hello";
  //
  //
  // std:: string filename = "./simpleAuth/" + exampleUsername + ".txt";
  // exampleAuthFile.open(filename);
  //
  // if (exampleAuthFile.is_open()){
  //   exampleAuthFile << examplePassword << "\n";
  // }
  // std::cout << filename;
  // ### END OF Simple Authentication Registration Test  ### //

  int choice = requestInputFromUser("\nChoose an option:\n\n" "[1]\tLogin\n" "[2]\tRegister\n" );
  //registration needs to make sure that entry doesn't already exist and that


}
