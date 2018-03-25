
#ifndef STOCKSTALLION_H
#define STOCKSTALLION_H

#include <string>
#include <limits>


class StockStallion{
public:
	StockStallion();

	// Database Functions
	static void initializeDB();
	static void addUserToDB(std::string username, std::string password);

    //templates suck for multi file projects : (
    template <typename T>
    T requestInputFromUser(const std::string &userPrompt);


    static bool verifyChoiceInRange(int choice, int max);

    // prompts user with options to login or register
    std::string loginRegisterPrompt();


	static bool verifyUsername(std::string username);
	static bool verifyPassword(std::string pw);

    //gets user info (username, password), POSTS it to DB.
    //void registerNewUser();

    static void loginRegisterSequence();
	static void commandLineLoginRegisterView();
	static bool authorizeLogin(std::string _Username, std::string _Password);
	static std::string getUsernameFromUser();
	static std:: string getPasswordFromUser();


    static bool registerNewUser();
	// void registrationSuccess();
	// void registrationFailed();

	// Main Menu which allows user to views stocks and perform other actions
	// void commandLineMainMenuView();
	// void displayOptions();
	// int userChoice();
	// void viewStocks();

	// private:
	// This is for a crude authentication system and must be changed.
	// vector <User> userList;
	// or another idea, read usernames and passwords from a file.

};
#endif
