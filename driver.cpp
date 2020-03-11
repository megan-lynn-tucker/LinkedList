/*********************************************************************
 * * Name: driver.cpp
 * * Author: Megan Lynn Tucker
 * * Date: 03/15/2020
 * * Description: Takes user input for linked list
 * * Input: User input
 * * Output: Requests for user input
 * * *********************************************************************/
#include<iostream>
#include<cstdlib>
#include"linked_list.h"
#include"node.h"
#include"input.h"

using namespace std;


int main(){
	Input user_in;
	string again, location, direction;
	int input, index;
	do{ //loop until user wishes to stop
		Linked_List list;
 		do{ //loop until user does not want to add any more numbers to the list
			cout << "Enter a number: ";
			cin >> input;
			cin.ignore(); //flush the buffer to prepare for getline input

			cout << "Insert at the front (f), back (b), or another location (i)? ";
			user_in.check_location(location);
			if(location == "f"){
				list.push_front(input);
			}
			else if(location == "b"){
				list.push_back(input);
			}
			else if(location == "i"){
				cout << "Where would you like to insert the number? ";
				cout << "Enter a number between 1 and " << list.get_length() << ": ";
				user_in.check_length(index, list.get_length());
				list.insert(input, index);
			}

			cout << "Do you want to enter another number? ";
			user_in.check_yn(again);
		}while(again == "y");
		
		cout << "Do you want to ascending or descending (a or d)? ";
		user_in.check_direction(direction);
		if(direction == "a"){
			list.sort_ascending();
		}
		else if(direction == "d"){
			list.sort_descending();
		}

		list.print();
		list.count_primes();

		cout << "Do you want to do this again (y or n)? ";
		user_in.check_yn(again);
	}while(again == "y");

	return 0;
}
