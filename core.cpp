#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "sqlite3.h"
#include "StockStallion.h"
#include "StockStallion.cpp"




int main(){

  StockStallion app = StockStallion();

  app.commandLineLoginRegisterView();

  // StockStallion::User user = app.commandLineLoginRegisterView();

  // app.commandLineMainMenuView( user )

  return 0;
}
