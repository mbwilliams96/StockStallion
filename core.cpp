#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "sqlite3.h"
#include "StockStallion.h"
#include "StockStallion.cpp"




int main(){
  system { "title Stock Stallion: Stocks Made Simple" };
  system { "cls" };
  system { "color 9f" };



  StockStallion app = StockStallion();

  app.commandLineLoginRegisterView();

  // StockStallion::User user = app.commandLineLoginRegisterView();

  // app.commandLineMainMenuView( user )

  return 0;
}
