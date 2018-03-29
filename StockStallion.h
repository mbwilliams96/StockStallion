
#ifndef STOCKSTALLION_H
#define STOCKSTALLION_H
#include <limits>


class StockStallion{
	public:
		StockStallion();

		// Database Functions
		void initializeDB();
		void addUserToDB(std::string username, std::string password);

    //templates suck for multi file projects : (
    template <typename T>
    T requestInputFromUser(const std::string &userPrompt);


    bool verifyChoiceInRange(int choice, int max);

    // prompts user with options to login or register
    void loginRegisterPrompt();


		bool verifyUsername(std::string &username);
		bool verifyPassword(std::string &password);

    //gets user info (username, password), POSTS it to DB.
    void registerNewUser();

    void loginRegisterSequence();
		void commandLineLoginRegisterView();
		// bool authorizeLogin();
		// std:: string getUsernameFromUser();
		// std:: string getPasswordFromUser();


		// bool registerNewUser();
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
