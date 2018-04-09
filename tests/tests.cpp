#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <mem.h>
#include "../sqlite/sqlite3.h"
#include "../StockStallion.h"
#include "../Database.h"
// template <typename T>
// T requestInputFromUser(const std::string &userPrompt){
//     std::cout << userPrompt << "\n> ";
//     T out = T();
//     while (!(std::cin >> out)) {
//         std::cin.clear();
//         std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
//         std::cout << "Error!" "\n";
//         std::cout << userPrompt << "\n> ";
//     }
//     return out;
// }




int main(){}
//
//    Database *db;
//    db = new Database("stockstallion.db");
//
//
//        //test
//    std::string _id = std::to_string( rand() % 1000);
//    std::string username = "example";
//    std::string password = "exampled";
//        // end test
//
//    //    char* q0 = "CREATE TABLE IF NOT EXISTS users( id INT PRIMARY KEY NOT NULL, username TEXT NOT NULL, password TEXT NOT NULL);";
////    std::string _q = std::string("INSERT INTO users(id, username,") + "password)" + "VALUES(" + "'" + _id + "'" + "," + "'" + username + "'" + "," + "'" + password + "'" + ");";
////    char *q2 = &_q[0u];
////    char* q2 = strdup(_q.c_str());
//
////    std::cout << q2;
////    db->query(q2);
////    //    db->query(q0);
////    //    db->query("INSERT INTO a VALUES(1, 2);");
////    //    db->query("INSERT INTO a VALUES(5, 4);");
////    //    char* q = "SELECT name FROM sqlite_temp_master WHERE type='table';";
//        char* q = "SELECT * FROM users;";
//        vector<vector<string> > result = db->query(q);
////
//    //    std::cout << "\n";
//        for(vector<vector<string> >::iterator it = result.begin(); it < result.end(); ++it)
//        {
//            vector<string> row = *it;
//            cout << "ID: " << row.at(0) << "\t" << "Username: " << row.at(1) << "\t" << "Password: " << row.at(2) << endl;
//        }
//
//        db->close();
//    //    std::cout << "hello";
//}





// int main(){

  // ### Simple Authentication Registration Test  ### //
  // std::ofstream exampleAuthFile;

  // std::string exampleUsername = "GregGNV101";
  // std::string examplePassword = "hello";


  // std:: string filename = "./simpleAuth/" + exampleUsername + ".txt";
  // exampleAuthFile.open(filename);

  //  if (exampleAuthFile.is_open()){
  // exampleAuthFile << examplePassword << "\n";
//   }
  // std::cout << filename;
  // ### END OF Simple Authentication Registration Test  ### //

  //   int choice = requestInputFromUser("\nChoose an option:\n\n" "[1]\tLogin\n" "[2]\tRegister\n" );
  //registration needs to make sure that entry doesn't already exist and that




// #### GET CWD ########333

//
//#include <stdio.h>  /* defines FILENAME_MAX */
//#ifdef WINDOWS
//#include <direct.h>
//    #define GetCurrentDir _getcwd
//#else
//#include <unistd.h>
//#define GetCurrentDir getcwd
//#endif
//


//char cCurrentPath[FILENAME_MAX];
//
//if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
//{
//return errno;
//}
//
//cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */
//
//printf ("The current working directory is %s", cCurrentPath);
//
