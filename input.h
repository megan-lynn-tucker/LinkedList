/*********************************************************************
 * * Program Filename: input.h
 * * Author: Megan Lynn Tucker
 * * Date: 03/15/2020
 * ***********************************************************************/
#ifndef INPUT_H
#define INPUT_H

#include<iostream>

using namespace std;

class Input{
	public:
		void check_yn(string&);
		void check_location(string&);
		void check_direction(string&);
		void check_length(int&, const int);
};

#endif
