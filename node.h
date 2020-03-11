/*********************************************************************
* Program Filename: Node.h
* Author: Megan Lynn Tucker
* Date: 03/15/2020
***********************************************************************/
#ifndef NODE_H
#define NODE_H


#include<iostream>

//Node is being used akin to a struct (with public member variables)
class Node{
public:
	int val; //the value that this node stores
	Node *next; //a pointer to the next node in the list; can have a pointer to that class, but not class
};

#endif
