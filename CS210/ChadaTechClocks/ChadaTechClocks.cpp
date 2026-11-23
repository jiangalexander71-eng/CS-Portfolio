/*
 * ChadaTechClocks.cpp
 *
 *  Date: 11/14/2026
 *  Author: Alexander Jiang
 */

//Allow for input and output
#include <iostream>

//Allow for formatting of output
#include <iomanip>

//Include string library
#include <string>

//Defaults to standard library namespace
using namespace std;

//Gets user initial time
void GetInitialTime(int& hours, int& minutes, int& seconds) {
	while (true) {
		cout << "Please enter the time in hours, minutes, and seconds (HH MM SS): ";
		cin >> hours >> minutes >> seconds;

		//Check if input is valid
		if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59 || seconds < 0 || seconds > 59) {
			cout << "Invalid time entered. Please try again." << endl;
			cout << endl;
		}

		//Exit loop if input is valid
		else {
			break; 
		}
	}
}

//Displays the time in 12-hour format
void Display12HourClock(int hours, int minutes, int seconds) {

	//Determine if time is AM or PM
	string period = (hours >= 12) ? "P M" : "A M";

    int displayHours = hours;

	//Keeps time if hours is less than 12, otherwise subtracts 12 from hours to display in 12-hour format
	if (displayHours == 0) {
		displayHours = 12; 
	}
	else if (displayHours > 12) {
		displayHours -= 12; 
	}

	//Displays 12-hour time
    cout << setfill('0') << "*     " << setw(2) << displayHours << ":"
         << setw(2) << minutes << ":" 
         << setw(2) << seconds << " " << period << "       *";
}
//Displays the time in 24-hour format
void Display24HourClock(int hours, int minutes, int seconds) {
	//Displays 24-hour time
	cout << setfill('0') << "*       " << setw(2) << hours << ":"
        << setw(2) << minutes << ":"
        << setw(2) << seconds << "         *" << endl;
}

//Displays the time in both 12-hour and 24-hour formats
void DisplayClocks(int hours, int minutes, int seconds) {
    cout << "**************************    **************************" << endl;;
    cout << "*     12-Hour Clock      *    *     24-Hour Clock      *" << endl;;
	Display12HourClock(hours, minutes, seconds);
    cout << "    ";
	Display24HourClock(hours, minutes, seconds);
    cout << "**************************    **************************" << endl;
	cout << endl;
}   

//Displays the menu options
void DisplayMenu() {
	cout << "**************************" << endl;
	cout << "* 1 - Add One Hour       *" << endl;
	cout << "* 2 - Add One Minute     *" << endl;
	cout << "* 3 - Add One Second     *" << endl;
	cout << "* 4 - Exit Program       *" << endl;
	cout << "**************************" << endl;
	cout << "Please select an option from the menu: ";
}

//Adds one hour to time, goes back to 0 after 23
void AddOneHour(int& hours) {
	hours = (hours + 1) % 24;
}
//Adds one minute to time, goes back to 0 after 59, adds one hour if minutes go back to 0
void AddOneMinute(int& hours, int& minutes) {
	minutes = (minutes + 1) % 60;
	if (minutes == 0) {
		hours = (hours + 1) % 24;
	}
}

//Adds one second to time, goes back to 0 after 59, adds one minute if seconds go back to 0, adds one hour if minutes go back to 0
void AddOneSecond(int& hours, int& minutes, int& seconds) {
	seconds = (seconds + 1) % 60;
	if (seconds == 0) {
		minutes = (minutes + 1) % 60;
		if (minutes == 0) {
			hours = (hours + 1) % 24;
		}
	}
}

//Main function
int main() {
    //Initialize time variables
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    int selection = 0;
    
    //Gets user input for initial time
	GetInitialTime(hours, minutes, seconds);

    //Displays initial time in HH:MM:SS format
	DisplayClocks(hours, minutes, seconds); 

	//Loops until user exits
	while (selection != 4) {
		//Displays menu options
		DisplayMenu();

		//Gets user selection
		cin >> selection;

		//Adds one hour, displays time
		if (selection == 1) {
			AddOneHour(hours);
			DisplayClocks(hours, minutes, seconds);
		}

		//Adds one minute, displays time
		else if (selection == 2) {
			AddOneMinute(hours, minutes);
			DisplayClocks(hours, minutes, seconds);
		}

		//Adds one second, displays time
		else if (selection == 3) {
			AddOneSecond(hours, minutes, seconds);
			DisplayClocks(hours, minutes, seconds);
		}

		//Exits program
		else if (selection == 4) {
			cout << "Exiting program." << endl;
		}
	}
}

