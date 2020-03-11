/*********************************************************************
 * * Name: linked_list.cpp
 * * Author: Megan Lynn Tucker
 * * Date: 03/15/2020
 * * Description: Manages functions for linked lists including merge sort and find primes
 * * Input: N/A
 * * Output: Prints the values of the linked list
 * * *********************************************************************/
#include<iostream>
#include<cstdlib>
#include"linked_list.h"

/********************************************************************* 
 * * Function: Linked_List
 * * Description: Constructor
 * * Parameters: N/A
 * * Pre-Conditions: A linked list object is constructed
 * * Post-Conditions: It is initialized to default linked list
 * *********************************************************************/ 
Linked_List::Linked_List(){
	length = 0;
	head = NULL;
}

/********************************************************************* 
 * * Function: Linked_List
 * * Description: Copy Constructor
 * * Parameters: Linked_List object
 * * Pre-Conditions: A linked list object is to be copied; Linked_List a, Linked_List b = a
 * * Post-Conditions: The linked list is copied
 * *********************************************************************/ 
Linked_List::Linked_List(const Linked_List &old_list){
	length = old_list.length;
	head = old_list.head;
}

/********************************************************************* 
 * * Function: operator=
 * * Description: Assignment Operator Overload
 * * Parameters: Linked_List object
 * * Pre-Conditions: A linked list object is to be copied; Linked_List a, Linked_List b, b = a
 * * Post-Conditions: The linked list is copied
 * *********************************************************************/ 
Linked_List& Linked_List::operator=(const Linked_List &old_list){
	length = old_list.length;
	head = old_list.head;
	return *this;
}

/********************************************************************* 
 * * Function: get_length
 * * Description: Accessor (getter)
 * * Parameters: N/A
 * * Pre-Conditions: A linked list object exists
 * * Post-Conditions: The list length is returned
 * *********************************************************************/ 
int Linked_List::get_length(){
	return length;
}

/********************************************************************* 
 * * Function: print()
 * * Description: Prints the linked list
 * * Parameters: N/A
 * * Pre-Conditions: The linked list is not empty
 * * Post-Conditions: Each value of the linked list is printed
 * *********************************************************************/ 
void Linked_List::print(){
	Node *current = head; //the current value begins at head and is pushed through to the end
	cout << "Linked List: ";
	for(int i = 0; i < length; i++){ 
		cout << current->val << " "; //note this is the same as saying (*current).val
		current = current->next; //note this method of looping thorugh the linked list is used through the program
	}
	cout << endl;
}

/********************************************************************* 
 * * Function: clear()
 * * Description: Deletes every value of the linked list
 * * Parameters: N/A
 * * Pre-Conditions: The linked list is not already empty
 * * Post-Conditions: The linked list is deleted
 * *********************************************************************/ 
void Linked_List::clear(){ //note that this handles the clean up that destructors would normally deal with;
	Node *current = head;
	while(current != NULL){
		Node *temp = current->next; //create a temp node for the next node
		delete current;
		current = temp; //move the current node to temp
	}
	head = NULL; //set head to null because at the end of the loop, head is pointing to a node that doesn't exist
}

/********************************************************************* 
 * * Function: push_front
 * * Description: Adds a new value to the front of the linked list
 * * Parameters: User input of int
 * * Pre-Conditions: The user input a valid integer input
 * * Post-Conditions: A new node is added to the front of the linked list with value equal to user input
 * *********************************************************************/ 
unsigned int Linked_List::push_front(int input){
	Node *new_start = new Node; //create the new node
	new_start->val = input; 
	new_start->next = head; //make it point to the current first value in the list
	head = new_start; //make the head point to the new node
	++length;
}

/********************************************************************* 
 * * Function: push_back
 * * Description: Adds a new value to the back of the linked list
 * * Parameters: User input of int
 * * Pre-Conditions: The user input a valid integer input
 * * Post-Conditions: A new node is added to the back of the linked list with value equal to user input
 * *********************************************************************/ 
unsigned int Linked_List::push_back(int input){
	Node *new_end = new Node;
	new_end->val = input;
	new_end->next = NULL; //as this is the new end it will point to null
	if(head == NULL){
		head = new_end;	//in the case that the list is empty, make the head point to the new node
	}
	else{
		Node *current = head;
		for(int i = 0; i < length - 1; i++){ //want to be at the last node; iterate one less
			current = current->next;
		}
		current->next = new_end; //make previous end point to the new node instead of null
	}
	length++;
}

/********************************************************************* 
 * * Function: insert
 * * Description: Adds a new value to a user specified location in the linked list
 * * Parameters: User input of int
 * * Pre-Conditions: The user input a valid integer input
 * * Post-Conditions: A new node is added to the linked list with value equal to user input
 * *********************************************************************/ 
unsigned int Linked_List::insert(int input, unsigned int index){
	Node *current = head;
	for(int i = 0; i < index - 1; i++){
		current = current->next; //find the node that the new node will be placed behind
	}
	Node *temp = current->next; //temp holds the value of the node the new node will be placed in front of
	Node *new_node = new Node; 
	new_node->val = input;
	new_node->next = temp;
	current->next = new_node;
}

/********************************************************************* 
 * * Function: split
 * * Description: Splits the linked list in half
 * * Parameters: References to right and left linked lists
 * * Pre-Conditions: The linked list to be split is at least of size 2
 * * Post-Conditions: The linked list is split; the right list is the larger of the lists
 * *********************************************************************/ 
void Linked_List::split(Linked_List &L, Linked_List &R){
	int middle = length/2; //note that this rounds down
	Node *current = head;
	for(int i = 0; i < middle; i++){
		L.push_back(current->val); //copy the values of the old linked list up to middle into L
		current = current->next;
	}
	for(int j = middle; j < length; j++){
		R.push_back(current->val); //copy the values of the old linked list from the middle to the end into R
		current = current->next;	
	}
}

/********************************************************************* 
 * * Function: sort_ascending
 * * Description: Recursive function to perform merge sort
 * * Parameters: N/A
 * * Pre-Conditions: The linked list is at least size 2
 * * Post-Conditions: The linked lists are sorted and merged in ascending order
 * *********************************************************************/ 
void Linked_List::sort_ascending(){
	Linked_List L, R;
	if(head == NULL || head->next == NULL){ //if the list is empty or it is size 1 (it does not need to be split)
		return;
	}

	split(L, R); //split it into two seprate linked lists

	//recursively call the sort ascending function
	R.sort_ascending();
	L.sort_ascending();

	clear(); //delete the linked list; required because we set the head to the merged L and R
	head = merge_a(L.head, R.head);
	//set R and L to null so when the destructor and clear() are called, no double free occurs
	R.head = NULL;
	L.head = NULL;
}

/********************************************************************* 
 * * Function: merge_a
 * * Description: Recursive function to perform merge sort
 * * Parameters: N/A
 * * Pre-Conditions: The linked list is at least size 1
 * * Post-Conditions: The linked lists are sorted and merged in ascending order
 * *********************************************************************/ 
Node* Linked_List::merge_a(Node *L, Node *R){ //here L and R are the head pointers
	Node *merge;
	
	//if we hit the end of one linked list, return the other
	if(L == NULL){
		return R;
	}
	else if(R == NULL){
		return L;
	}
	
	//recursively call merge ascending function
	//check which value is smaller; move the pointer over one and call again with the two lists
	if(L->val <= R->val){
		merge = L;
		merge->next = merge_a(L->next, R);
	}
	else{
		merge = R;
		merge->next = merge_a(L, R->next);
	}
	return merge;
}

/********************************************************************* 
 * * Function: sort_descending
 * * Description: Recursive function to perform merge sort
 * * Parameters: N/A
 * * Pre-Conditions: The linked list is at least size 2
 * * Post-Conditions: The linked lists are sorted and merged in descending order
 * *********************************************************************/ 
void Linked_List::sort_descending(){
	Linked_List L, R;
	if(head == NULL || head->next == NULL){ //if the list is empty or it is size 1 (it does not need to be split)
		return;
	}

	split(L, R); //split it into two seprate linked lists

	//recursively call the sort descending function
	R.sort_descending();
	L.sort_descending();

	clear(); //delete the linked list; required because we set the head to the merged L and R
	head = merge_d(L.head, R.head);
	//set R and L to null so when the destructor and clear() are called, no double free occurs
	R.head = NULL;
	L.head = NULL;
}

/********************************************************************* 
 * * Function: merge_d
 * * Description: Recursive function to perform merge sort
 * * Parameters: N/A
 * * Pre-Conditions: The linked list is at least size 1
 * * Post-Conditions: The linked lists are sorted and merged in descending order
 * *********************************************************************/ 
Node* Linked_List::merge_d(Node *L, Node *R){ //here L and R are the head pointers
	Node *merge;
	
	//if we hit the end of one linked list, return the other
	if(L == NULL){
		return R;
	}
	else if(R == NULL){
		return L;
	}

	//recursively call merge descending function
	//check which value is larger; move the pointer over one and call again with the two lists
	if(L->val >= R->val){
		merge = L;
		merge->next = merge_d(L->next, R);
	}
	else{
		merge = R;
		merge->next = merge_d(L, R->next);
	}
	return merge;
}

/********************************************************************* 
 * * Function: count_primes
 * * Description: Returns the number of prime numbers in the linked list
 * * Parameters: N/A
 * * Pre-Conditions: The linked list is nonempty
 * * Post-Conditions: The number of prime numbers (negatives count as prime) are printed
 * *********************************************************************/ 
void Linked_List::count_primes(){
	bool is_prime;
	Node *current = head;
	int counter = 0;
	for(int i = 0; i < length; i++){
		is_prime = true;
		for(int j = 2; j < current->val; j++){
			if(current->val < 0){ //negative numbers are all considered to be prime
				break;
			}
			else if(current->val % j == 0){
				is_prime = false;
				break; //the value is not prime or it is negative (considered not prime)
			}
		}
		if(is_prime == true){
			++counter;
		}
		current = current->next;
	}
	cout << "This list contains " << counter << " primes. " << endl;
}

/********************************************************************* 
 * * Function: ~Linked_List
 * * Description: Destructor
 * * Parameters: N/A
 * * Pre-Conditions: A linked list object falls out of scope
 * * Post-Conditions: All memory is freed
 * *********************************************************************/ 
Linked_List::~Linked_List(){
	clear();
}
