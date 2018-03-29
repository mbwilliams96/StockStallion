#include <limits>
#include "StockStallion.h"
#include "sqlite3.h"

StockStallion::StockStallion(){
  // initialize db on startup
  StockStallion::initializeDB();
}

// ### DATABASE INTERFACE FUNCTIONS ####
static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}
// Create database when the app runs if it doesn't already exist.
// Test the connection to the db if it does exist.
void StockStallion::initializeDB(){
  sqlite3 *db;
  char *zErrMsg = 0;
  const char *sql;
  int rc;

  rc = sqlite3_open("stockstallion.db", &db);

  if( rc ){
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db) );
    return;
  } else {
    fprintf(stdout, "Opened database successfully\n");
  }

  sql = "CREATE TABLE IF NOT EXITS users(" \
        "id       INT PRIMARY KEY   NOT NULL," \
        "username TEXT              NOT NULL" \
        "password TEXT              NOT NULL);";

  rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
  if( rc != SQLITE_OK ){
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
       sqlite3_free(zErrMsg);
    } else {
       fprintf(stdout, "Table created successfully\n");
    }
  sqlite3_close(db);
  return;
}
void StockStallion::addUserToDB(std::string username, std::string password){
  sqlite3 *db;
  char *zErrMsg = 0;
  const char *sql;
  int rc;

  rc = sqlite3_open("stockstallion.db", &db);

  if( rc ){
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db) );
    return;
  } else {
    fprintf(stdout, "Opened database successfully\n");
  }

  std::string insertUser = std::string("VALUES (") + "'" + username + "'"  + "," + "'" + password + "');";

  sql = ("INSERT INTO users(username,password) " + insertUser).c_str();

  rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
  if( rc != SQLITE_OK ){
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
       sqlite3_free(zErrMsg);
    } else {
       fprintf(stdout, "Table created successfully\n");
    }
  sqlite3_close(db);
  return;
}
// END OF DATABASE INTERFACE FUNCTIONS


// template doesn't work
template <typename T>
T StockStallion::requestInputFromUser(const std::string &userPrompt){
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

void StockStallion::loginRegisterPrompt(){
  std::cout << "\nChoose an option:\n\n";
  std::cout << "[1]\tLogin\n";
  std::cout << "[2]\tRegister\n";
  return;
}

// verify strings
// It would be alot better if we could use a template for accepting and
// verifying user input. Couldn't get the templates to work though.
// Usernames should be aplhanumeric

// couldn't seal down the logic for this one
// bool verifyInput(std::string stringInput, int stringType){
//   swtich (stringType){
//     case 0: // string is an intended usernames
//       validChoice = StockStallion::verifyUsername(stringInput);
//     case 1;
//       validChoice = StockStallion::verifyPassword(stringInput);
//   }
//
//   while( (std::cin.fail()) or !validChoice) {
//     std::cout << "Enter a valid string";
//     std::cin.clear();
//     std::cin.ignore(256,'\n');
//     std::cout << ": ";
//     std::cin >> string;
//     validChoice = verifyChoiceInRange(choice, 2);
//   }
// }

bool StockStallion::verifyUsername(std::string username){
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
// passwords shouldn't contain spaces.
bool StockStallion::verifyPassword(std::string pw){
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
bool StockStallion::verifyChoiceInRange(int choice, int max){
  if ( choice < 0){
    return false;
  }
  return (choice <= max);
}
void StockStallion::registerNewUser(){
  std::cout << "\n\n\nWelcome to the Stock Stallion Registration Prompt.";
  // other fields can be added { name, temperament, etc}
  std::string username, password;

  std::cout << "\n\nEnter a username: ";
  std::cin >> username;
  this -> verifyUsername(username);

  std::cout << "\n\nEnter a password: ";
  std::cin >> password;
  this -> verifyPassword(password);
  StockStallion::addUserToDB(username, password);

  std::cout << "Congratulations! You may have been registered as " << "''" << username << "''.";
  return;
}

void StockStallion::loginRegisterSequence(){
    // templates are constrained such that the implementation
    // and instantiation must happen in the same place (otherwise there will be errors)
    // (still doesn't work )
  int choice = requestInputFromUser("\nChoose an option:\n\n" "[1]\tLogin\n" "[2]\tRegister\n" );
  // StockStallion::loginRegisterPrompt();
  // int choice;
  // bool validChoice;
  // std::cout << "Choice: ";
  // std::cin >> choice;
  //
  // //valdiate input
  // validChoice = verifyChoiceInRange(choice, 2);
  // std::cout << validChoice;
  // while( (std::cin.fail()) or !validChoice ) {
  //   std::cout << "Enter an integer in range 1-2.\n";
  //   std::cin.clear();
  //   std::cin.ignore(256,'\n');
  //   std::cout << "Choice: ";
  //   std::cin >> choice;
  //   validChoice = verifyChoiceInRange(choice, 2);
  // }

  // switch(choice){
  //   case 1:
  //     // authorizeLoginSequence();
  //   case 2:
  //     StockStallion::registerNewUser();
  // }
  return;
}


void StockStallion::commandLineLoginRegisterView(){
    std::cout << "Welcome to Stock Stallion!\n\n";
    std::cout << "StockStallion in a system designed for the viewing, analysis and prediction of performance of stocks.\nIt simplifies investment strategy.\n\n";
    StockStallion::loginRegisterSequence();
    // bool validChoice = false;




    return;
  }
