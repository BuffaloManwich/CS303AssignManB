#include "menus.h"

void MainMenu() {
	cout << "WELCOME!!!" << endl;
	cout << "Please make a selection from the following options:" << endl << endl;
	cout << "1) Enter the linked list menu" << endl << endl;
	cout << "2) Enter the stack menu" << endl << endl;
	cout << "3) Exit the program" << endl << endl;
	cout << "What is your selection?" << endl;
	return;
}

void LinkedMenu() {
	cout << endl;
	cout << "LINKED LIST MENU" << endl;
	cout << "Please make a selection from the following options:" << endl << endl;
	cout << "1) Build a Linked List of integers" << endl << endl;
	cout << "2) Modify current Linked List" << endl << endl;
	cout << "3) View current Linked List" << endl << endl;
	cout << "4) Search list for a integer value (search(data))" << endl << endl;
	cout << "5) Return to the Main Menu" << endl << endl;
	cout << "What is your selection?" << endl;
	return;
}

void StackMenu() {
	cout << endl;
	cout << "STACK MENU" << endl;
	cout << "Please make a selection from the following options:" << endl << endl;
	cout << "1) Build a Stack of integers" << endl << endl;
	cout << "2) Modify current Stack" << endl << endl;
	cout << "3) View Stack details" << endl << endl;
	cout << "4) Return to Main Menu" << endl << endl;
	cout << "What is your selection?" << endl;
	return;
}

void ModListMenu() {
	cout << endl;
	cout << "MODIFY LINKED LIST MENU" << endl;
	cout << "Please make a selection from the following options:" << endl << endl;
	cout << "1) Add a node to the list" << endl << endl;
	cout << "2) Delete a node from the list" << endl << endl;
	cout << "3) Return to the Linked List Menu" << endl << endl;
	cout << "What is your selection?" << endl;
	return;
}

void AddNodeMenu() {
	cout << endl;
	cout << "ADD NODE MENU" << endl;
	cout << "Please make a selection from the following options:" << endl << endl;
	cout << "1) Add a node to the front of the list (add_front(data))" << endl << endl;
	cout << "2) Add a node to the back of the list (add_back(data))" << endl << endl;
	cout << "3) Add a node to the nth position of the list (add_node(index))" << endl << endl;
	cout << "4) Return to the Modify Linked List Menu" << endl << endl;
	cout << "What is your selection?" << endl;
	return;
}

void DelNodeMenu() {
	cout << endl;
	cout << "DELETE NODE MENU" << endl;
	cout << "Please make a selction from the following options:" << endl << endl;
	cout << "1) Remove a node from the front of the list (del_front())" << endl << endl;
	cout << "2) Remove a node from the back of the list (del_back())" << endl << endl;
	cout << "3) Remove a node from the nth position of the list (del_node(index))" << endl << endl;
	cout << "4) Return to the Modify Linked List Menu" << endl << endl;
	cout << "What is your selection?" << endl;
	return;
}

void ViewNodeMenu() {
	cout << endl;
	cout << "VIEW NODE MENU" << endl;
	cout << "Please make a selection from the following options:" << endl << endl;
	cout << "1) View the data value at the front of the list (front())" << endl << endl;
	cout << "2) View the data value at the back of the list (back())" << endl << endl;
	cout << "3) View the data value at the nth position of the list (show(index))" << endl << endl;
	cout << "4) View the entire Linked List (printList())" << endl << endl;
	cout << "5) Return to the Linked List Menu" << endl << endl;
	cout << "What is your selection?" << endl;
	return;
}

void ModStackMenu() {
	cout << endl;
	cout << "MODIFY STACK MENU" << endl;
	cout << "Please make a selection from the following options:" << endl << endl;
	cout << "1) Add a number to the top of the stack (push(data))" << endl << endl;
	cout << "2) Remove a number from the top of the stack (pop())" << endl << endl;
	cout << "3) Return to the Stack Menu" << endl << endl;
	cout << "What is your selection?" << endl;
	return;
}

void ViewStackMenu() {
	cout << endl;
	cout << "VIEW STACK MENU" << endl;
	cout << "Please make a selection from the following options:" << endl << endl;
	cout << "1) View the top of the stack (top())" << endl << endl;
	cout << "2) View the size of the stack (sSize())" << endl << endl;
	cout << "3) View the average of the Stack's values (sMean())" << endl << endl;
	cout << "4) Return to the Stack Menu" << endl << endl;
	cout << "What is your selection?" << endl;
	return;
}