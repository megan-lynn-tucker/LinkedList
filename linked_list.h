/*********************************************************************
* Program Filename: Linked_List.h
* Author: Megan Lynn Tucker
* Date: 03/15/2020
***********************************************************************/
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include<iostream>
#include"node.h"

using namespace std;

class Linked_List{
	private:
		unsigned int length; //the number of nodes contained in the list
		Node *head; //a pointer to the first node in the list
	public:
		Linked_List(); //constructor
		Linked_List(const Linked_List&); //copy constructor
		Linked_List& operator=(const Linked_List&); //assignment operator overload
		
		int get_length(); //note: there is no set_length(unsigned int)
		void print(); //output a list of all integers contained within the list
		void clear(); //delete the entire list (remove all nodes and reset length to 0)
		unsigned int push_front(int); //insert new value at front of the list (returns new list len)
		unsigned int push_back(int); //insert new value at back of the list (returns new list len)
		unsigned int insert(int val, unsigned int index); //insert a new value in the list at index
		
		void split(Linked_List&, Linked_List&);
		void sort_ascending(); // sort the nodes in ascending order (recursive Merge sort)
		Node* merge_a(Node*, Node*);
		void sort_descending(); // sort the nodes in descending order
		Node* merge_d(Node*, Node*);
		
		void count_primes();
		
		~Linked_List(); //destructor
};

#endif
