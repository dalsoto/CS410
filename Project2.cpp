#include <iostream>
using namespace std;

/*** Created DisplayMenu function for easier readability ***/
void DisplayMenu(){
  	cout << "What would you like to do?" << endl;
		cout << "DISPLAY the client list (enter 1)" << endl;
		cout << "CHANGE a client's choice (enter 2)" << endl; 
		cout << "Exit the program.. (enter 3)" << endl;
    
    return;
}

void ChangeCustomerChoice(string arr[5][2]) {
  // Switched variables to strings for easier invalid input handling
  string clientNum = "";
	string servChoice = "";

   // Changes the client's service "selected option"	to user input
  cout << "Enter the number of the client that you wish to change" << endl;
 	cin >> clientNum; // Which client to change - 1, 2, 3, 4, or 5

  // Input validation - user can only input 1/2/3/4/5 which avoids undefined behavior, malicious characters, and crashes
  while(clientNum != "1" && clientNum != "2" && clientNum != "3" && clientNum != "4" && clientNum != "5"){
    cin.clear();
    cout << "Invalid Input - Only Input 1, 2, 3, 4, or 5" << endl;
    cin >> clientNum;
    if (clientNum == "1" || clientNum == "2" || clientNum == "3" || clientNum == "4" || clientNum == "5"){
      break;
    }
    else{
      continue;
    }
  }

 	cout << "Please enter the client's new service choice (1 = Brokerage, 2 = Retirement)" << endl;
 	cin >> servChoice; // 1 or 2

  // Input validation - user can only input 1 or 2 which avoids undefined behavior, malicious characters, and crashes
  while(servChoice != "1" && servChoice != "2"){
    cin.clear();
    cout << "Invalid Input - Only Input 1(Brokerage) or 2(Retirement)" << endl;
    cin >> servChoice;
    if (servChoice == "1" || servChoice == "2"){
      break;
    }
    else{
      continue;
    }
  }

 	if (clientNum == "1") {
 		arr[0][1] = servChoice;
 	}
 	else if (clientNum == "2") {
 		arr[1][1] = servChoice;
 	}
 	else if (clientNum == "3") {
	  arr[2][1]= servChoice;
 	}
 	else if (clientNum == "4") {
 	  arr[3][1] = servChoice;
 	}
 	else if (clientNum == "5") {
 	  arr[4][1] = servChoice;
 	}
  else{ // Handling if user doesn't input correct number - unlikely to get used since there is input validation
    cout << "Client number " << clientNum << " does not exist - Returning to main menu" << endl;
  }
  
 	return; // returns to main loop

}

void DisplayInfo(string arr[5][2]) {
	int num = 1; // List starts with client number 1

  // Displays all of the client's info
	cout << "  Client's Name    Service Selected (1 = Brokerage, 2 = Retirement)" << endl;
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			cout << num << ". " << arr[i][j] << " selected option " << arr[i][j+1] << endl;

			num++;
			break;
		}
	}

  return; // returns to main loop

}


int CheckUserPermissionAccess() {
  // Intialize variables to avoid being easier to manipulate
  string userPass = "";
  string userName = "";
  int correct = 0;

  /*** This can't be changed for this assignment, but usernames and passwords should get inputted into a secure database that uses encryption.
  Then, the user input should get verified by comparing it to the stored data in the database. Passwords should NOT be hardcoded ever ***/
  cout << "Enter your username:" << endl;
  cin >> userName; // Doesn't matter what is inputted here

  cout << "Enter your password:" << endl;
  cin >> userPass;

  if (userPass == "123"){ // Program presently has password hardcoded as "123"
    correct = 1;
  }
  else{
    correct = 2;
  }
  return correct;
}



int main() {
  // Localized the array so that it is more difficult for attackers to access and manipulate
  // Also switched client information to a multidimentional array for client scalability
  string clients[5][2] = {{"Bob Jones","1"}, {"Sarah Davis","2"}, {"Amy Friendly","1"}, {"Johnny Smith","1"}, {"Carol Spears" ,"2"}};

  // Intialize variables to avoid being easier to manipulate
  string userChoice = ""; // Switched userChoise to string for easier validation
  int verified = 0;

	cout << "Created by Dalton Soto" << endl;

	cout << "Hello! Welcome to our Investment Company" << endl;
  /*** Very unsecure user verification process ***/
  while(verified != 1){
    verified = CheckUserPermissionAccess();
    
    if(verified == 1){
      break;
    }
    else{
      cout << "Invalid Password. Please try again" << endl;
    }
  }

  while(1){
    DisplayMenu(); // Display menu options
    cin >> userChoice;

    // Input validation for the menu choices - avoids attackers being able to input malicious characters to cause undefined behavior and crashes
    while(userChoice != "1" && userChoice != "2" && userChoice != "3"){
      cin.clear();
      cout << "Invalid Choice" << endl;
      DisplayMenu(); // Display menu options
      cin >> userChoice;
      if(userChoice == "1" || userChoice == "2" || userChoice == "3"){
        break;
      }
      else{
        continue;
      }
    }

    if (userChoice == "1") {
      cout << "You chose 1" << endl;
			DisplayInfo(clients);
		}
		else if (userChoice == "2") {
			cout << "You chose 2" << endl;
      ChangeCustomerChoice(clients);
		}
		else if (userChoice == "3") {
			cout << "You chose 3" << endl;
			break; // exit loop when 3 is chosen
		}
    else{ // Exception handling - likely will not get used since there is input validation
      cout << "Invalid Choice" << endl;
    }
  }

  return 0;
}