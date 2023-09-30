#include <iostream>
#include <vector>
using namespace std;

// GLOBAL VARIABLES - These can be easily accessed and manipulated by an attacker
vector<int> servChoice{ 1, 2, 1, 1, 2 };
int serv1 = servChoice[0], serv2 = servChoice[1], serv3 = servChoice[2], serv4 = servChoice[3], serv5 = servChoice[4];
string userName;

void ChangeCustomerChoice() {
  int clientNum, servChoice;

	/*** These inputs are not verified at all, so the user can input anything to cause the program to act up - also can input malicious characters ***/
  // Changes the client's service "selected option"	to user input
  cout << "Enter the number of the client that you wish to change" << endl;
	cin >> clientNum; // Which client to change - 1, 2, 3, 4, or 5
	cout << "Please enter the client's new service choice (1 = Brokerage, 2 = Retirement)" << endl;
	cin >> servChoice; // 1 or 2

	if (clientNum == 1) {
		serv1 = servChoice;
	}
	else if (clientNum == 2) {
		serv2 = servChoice;
	}
	else if (clientNum == 3) {
		serv3 = servChoice;
	}
	else if (clientNum == 4) {
	 serv4 = servChoice;
	}
	else if (clientNum == 5) {
	 serv5 = servChoice;
	}

	return; // returns to main loop

}

void DisplayInfo() {

  // Displays all of the client's info
	cout << "  Client's Name    Service Selected (1 = Brokerage, 2 = Retirement)" << endl;
	cout << "1. " << "Bob Jones" << " selected option " << serv1  << endl;
	cout << "2. " << "Sarah Davis" << " selected option " << serv2 << endl;
	cout << "3. " << "Amy Friendly" << " selected option " << serv3 << endl;
	cout << "4. " << "Johnny Smith" << " selected option " << serv4 << endl;
	cout << "5. " << "Carol Spears" << " selected option " << serv5 << endl;

  return; // returns to main loop

}


int CheckUserPermissionAccess() {
  string userPass = "";
  int correct = 0;

	/*** This security issue can not be fixed within this code, but usernames and passwords should be stored in a secured database ***/
  cin >> userName; // Doesn't matter what is inputted here

  cout << "Enter your password:" << endl;
  cin >> userPass;

  if (userPass == "123"){
    correct = 1;
  }
  else{
    correct = 2;
  }
  return correct;
}



int main() {
  int userChoice, verified, i;

	cout << "Created by Dalton Soto" << endl;

	cout << "Hello! Welcome to our Investment Company" << endl;
  while(verified != 1){
    cout << "Enter your username:" << endl;
    verified = CheckUserPermissionAccess();
     /*** This is not a secure way to verify a user, the user input should be encrypted and then compared to the stored data in the database ***/
    if(verified == 1){
      break;
    }
    else{
      cout << "Invalid Password. Please try again" << endl;
    }
  }

  while(i != 1){
		/*** No input validation for menu choices, allowing attackers to input malicious character to manipulate the program ***/
		cout << "What would you like to do?" << endl;
		cout << "DISPLAY the client list (enter 1)" << endl;
		cout << "CHANGE a client's choice (enter 2)" << endl; 
		cout << "Exit the program.. (enter 3)" << endl;
    cin >> userChoice;

    if (userChoice == 1) {
      cout << "You chose 1" << endl;
			DisplayInfo();
		}
		else if (userChoice == 2) {
			cout << "You chose 2" << endl;
      ChangeCustomerChoice();
		}
		else if (userChoice == 3) {
			cout << "You chose 3" << endl;
			i = 1; // exit loop when 3 is chosen
		}
  }

  return 0;
}