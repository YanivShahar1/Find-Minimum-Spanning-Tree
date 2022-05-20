#pragma once
#include <iostream>

using namespace std;
struct Node
{
	int vertex, weight;
	Node* next, *twin;
	bool appear = false;
};

class List
{

private:
	Node* head;
	Node* tail;
	int size;

	Node* allocateData(int, int);

	void addToEmptyList(Node*);		 	  // add node to empty list 
	void addToEndOfList(Node*);			  // add node to the end of list

	Node* findPlaceToDelete(int)const;		  // find the place to delete the node
	void deleteFromInnerPlace(Node*);	  // delete a node from inner place
	void deleteFromEndOfList(Node*);	  // delete a node from the end of the list.
	void deleteFromBeginning();
	void addToBeginningOfList(Node*);
public:
	List()
		:head(nullptr), tail(nullptr), size(0)
	{}
	~List()
	{
		makeEmptyList();
	}

	void makeEmptyList();							// makes empty list
	void deleteFromList(int);						// delete a node from list by index
	Node* insertToList(int, int);							// insert to list 
	Node* findInList(int);							// find the list 
	Node* getHead() const { return head; }	// get list		
	const Node* getTail() const { return tail; }	// get tail
	int getSize() const { return size; }			// get size
	bool isEmpty() const { return size == 0; }		// checks if empty
	int deleteFromEndOfList();						// delete from end of list 

	void printList(int vertex);

	void setPointer(int, Node*);
};