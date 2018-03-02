#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int main(){
  // ### Simple Authentication Registration Test  ### //
  std::ofstream exampleAuthFile;

  std::string exampleUsername = "GregGNV101";
  std::string examplePassword = "hello";


  std:: string filename = "./simpleAuth/" + exampleUsername + ".txt";
  exampleAuthFile.open(filename);

  if (exampleAuthFile.is_open()){
    exampleAuthFile << examplePassword << "\n";
  }
  // std::cout << filename;

  // ### END OF Simple Authentication Registration Test  ### //

}
