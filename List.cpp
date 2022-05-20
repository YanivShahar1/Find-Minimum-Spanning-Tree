#include "List.h"

void List::addToEmptyList(Node* cell_to_add)
{
	tail = head = cell_to_add;
	size++;
}
void List::addToEndOfList(Node* cell_to_add)
{
	tail->next = cell_to_add;
	tail = cell_to_add;
	size++;
}

Node* List::allocateData(int ver, int c)
{
	Node* data = new Node;
	if (data == nullptr)
	{
		cout << "Memory allocation error!" << endl;
		exit(-1);
	}
	data->vertex = ver;
	data->weight = c;
	data->next = nullptr;
	return data;
}

Node* List::findPlaceToDelete(int ver)const
{
	Node* curr = head, * prev = nullptr;
	while (curr && (curr->vertex != ver))
	{
		prev = curr;
		curr = curr->next;
	}
	return prev;
}
void List::deleteFromInnerPlace(Node* prev)
{
	Node* cell_to_dell = prev->next;
	prev->next = cell_to_dell->next;
	delete cell_to_dell;
}

void List::deleteFromEndOfList(Node* prev)
{
	delete prev->next;
	tail = prev;
	prev->next = nullptr;
}
void List::makeEmptyList()
{
	while (head)
		deleteFromBeginning();
	size = 0;
}

void List::deleteFromList(int ver)
{
	if (head == nullptr) //Empty list
		return;
	Node* prev = findPlaceToDelete(ver);
	if (prev == tail) //Not found
		return;
	size--;
	if (prev == nullptr) //In the beginning
		deleteFromBeginning();
	else
		if (prev->next == tail) //In the End
			deleteFromEndOfList(prev);
		else
			deleteFromInnerPlace(prev);
}
Node* List::insertToList(int ver, int c)
{
	Node* cell_to_add = allocateData(ver, c);
	if (head == nullptr)
		addToEmptyList(cell_to_add);
	else
		addToBeginningOfList(cell_to_add);

	return cell_to_add;
}

Node* List::findInList(int ver)
{
	Node* curr = head;
	while (curr != nullptr)
	{
		if (curr->vertex == ver)
		{
			return curr;
		}

		curr = curr->next;
	}

	return nullptr;
}
int List::deleteFromEndOfList()
{
	if (size == 0)
	{
		throw "cannot delete";
	}
	Node* curr = head;
	Node* prev = nullptr;
	int deletedNodeValue = -1;
	while (curr->next != NULL)
	{
		prev = curr;
		curr = curr->next;
	}

	tail = prev;
	if (tail != nullptr)
	{
		tail->next = nullptr;
	}
	else
	{
		head = tail;
	}
	deletedNodeValue = curr->vertex;
	delete curr;
	size--;
	return deletedNodeValue;
}
void List::deleteFromBeginning()
{
	Node* cell_to_dell = head;
	head = head->next;

	delete cell_to_dell;

	if (head == nullptr)
		tail = nullptr;
}


void List::addToBeginningOfList(Node* cell_to_add)
{
	cell_to_add->next = head;
	head = cell_to_add;
	size++;
}

void List::printList(int vertex)
{
	Node* curr = head;
	while (curr!=nullptr)
	{
		cout << "\t" << vertex << "\t" << curr->vertex << endl;
		curr = curr->next;
	}
}

void List::setPointer(int v, Node* p)
{
	Node* curr = head;

	while (curr!= nullptr && curr->vertex != v)
	{
		curr = curr->next;
	}
	if (curr->vertex == v)
		curr->twin = p;
	else
		cout << "Can't find v to set a pointer.." << endl;
	

}