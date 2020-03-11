/*********************************************************************
 * * Name: input.cpp
 * * Author: Megan Lynn Tucker
 * * Date: 03/15/2020
 * * Description: Checks if user input is valid
 * * Input: Strings for command values
 * * Output: "Invalid input" if the input is invalid
 * * *********************************************************************/
#include<cstdlib>
#include"input.h"

/********************************************************************* 
 * * Function: check_yn
 * * Description: Checks if the input is "y" or "n"
 * * Parameters: Reference to input string
 * * Pre-Conditions: N/A
 * * Post-Conditions: The user has input either "y" or "n"
 * *********************************************************************/ 
void Input::check_yn(string &s){
	bool valid;
	do{ //check that input is either y or n; reprompt if not true
		valid = true;
		getline(cin, s);
		if(s != "y" && s != "n"){
			cout << "Invalid input. ";
			valid = false;
		}
	}while(valid == false);
}

/********************************************************************* 
 * * Function: check_location
 * * Description: Checks if the input is "f", "b", or "i"
 * * Parameters: Reference to input string
 * * Pre-Conditions: N/A
 * * Post-Conditions: The user has input either "f", "b", or "i"
 * *********************************************************************/ 
void Input::check_location(string &s){
	bool valid;
	do{ //check that input is either y or n; reprompt if not true
		valid = true;
		getline(cin, s);
		if(!(s == "f" || s == "b" || s == "i")){
			cout << "Invalid input. ";
			valid = false;
		}
	}while(valid == false);
}

/********************************************************************* 
 * * Function: check_direction
 * * Description: Checks if the input is "a" or "d"
 * * Parameters: Reference to input string
 * * Pre-Conditions: N/A
 * * Post-Conditions: The user has input either "a" or "d"
 * *********************************************************************/ 
void Input::check_direction(string &s){
	bool valid;
	do{ //check that input is either y or n; reprompt if not true
		valid = true;
		getline(cin, s);
		if(s != "a" && s != "d"){
			cout << "Invalid input. ";
			valid = false;
		}
	}while(valid == false);
}

/********************************************************************* 
 * * Function: check_length
 * * Description: Checks if the input is between 1 and the length of the linked list
 * * Parameters: Reference to input string
 * * Pre-Conditions: N/A
 * * Post-Conditions: The user has input an integer between 1 and length of list
 * *********************************************************************/ 
void Input::check_length(int &index, const int length){
	bool valid;
	string s;
	do{
		valid = true;
		getline(cin, s);
		index = atoi(s.c_str());
		if(index < 1 || index > length){
			cout << "Invalid input. ";
			valid = false;
		}
	}while(valid == false);
}
