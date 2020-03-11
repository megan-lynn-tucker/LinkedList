# LinkedList
Implement a linked list class from scratch using pointers and object oriented programming.

## Motivation
The purpose of this assignment was to understand the difference between a linked list and an array.

This program constructs a linked list out of the Node class, which is treated like a struct (all variables are public).
The linked list contains functions to add nodes to the front, back, and arbitrary location in the list.
Additionally, it has functions to print the linked list, delete all elements in the linked list, and count the number of primes.
For our purposes, all negative integers are considered primes.
The sort functions use a recursive merge sort algorithm to arrange the linked list in either ascending or descending order.

All user inputs are error checked using getline except input for node values.
This input was not error checked because the input can be negative integers. 
In this case, cin was used. 
Therefore, if noninteger input is provided, the program may crash or enter an infinite loop.

## Class
CS 162: Introduction to Computer Science
