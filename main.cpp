#include "function.h"

int main() {
    // The programs begins with the main menu
    MainMenu();
    size_t selection = boundTest(1, 3, getInput());
    while (selection != 3) {
        // Main menu option 1 is the Linked List menu
        if (selection == 1) {
            Linked list;
            LinkedMenu();            
            selection = boundTest(1, 5, getInput());
            while (selection != 5) {
                // Linked List menu option 1 is the build list function
                if (selection == 1) {
                    buildList(list);
                }
                // Linked List menu option 2 is the modify list function
                else if (selection == 2) {
                    ModListMenu();
                    selection = boundTest(1, 3, getInput());
                    while (selection != 3) {
                        // Modify Linked List menu option 1 is the add node menu
                        if (selection == 1) {
                            AddNodeMenu();
                            selection = boundTest(1, 4, getInput());
                            while (selection != 4) {
                                // Add Node Menu option 1 is the add node to the front of the list
                                if (selection == 1) {
                                    cout << "Please enter the data value to add to the front of the list." << endl;
                                    int userIn = getInput();
                                    list.add_front(userIn);
                                }
                                else if (selection == 2) {
                                    // Add Node Menu option 2 is the add node to the back of the list
                                    cout << "Please enter the data value to add to the back of the list." << endl;
                                    int userIn = getInput();
                                    list.add_back(userIn);
                                }
                                else if (selection == 3) {
                                    // Add Node Menu option 3 is the add node to an index in the list
                                    cout << "Please enter the index to add the node to." << endl;
                                    size_t userIndex = boundTest(0, list.num_items - 1, getInput());
                                    cout << "Please enter the data value to add to the list." << endl;
                                    int userVal = getInput();
                                    list.insert(userIndex, userVal);
                                }
                                // This will reprint the Add Node Menu until the user selects option 4
                                cout << endl;
                                AddNodeMenu();
                                selection = boundTest(1, 4, getInput());
                            }
                            // Exit the Add Node Menu
                        }
                        // Mod List menu option 2 is delete node menu
                        else if (selection == 2) {
                            DelNodeMenu();
                            selection = boundTest(1, 4, getInput());
                            while (selection != 4) {
                                // Delete Node Menu option 1 is the delete node from the front of the list
                                if (selection == 1) {
                                    list.del_front();
                                }
                                // Delete Node Menu option 2 is the delete node from the back of the list
                                else if (selection == 2) {
                                    list.del_back();
                                }
                                // Delete Node Menu option 3 is the delete node from an index in the list
                                else if (selection == 3) {
                                    cout << "Please enter the index to delete the node from." << endl;
                                    size_t userIndex = boundTest(0, list.num_items, getInput());
                                    list.remove(userIndex);
                                }
                                // This will reprint the Delete Node Menu until the user selects option 4
                                cout << endl;
                                DelNodeMenu();
                                selection = boundTest(1, 4, getInput());
                            }
                            // Exit the Delete Node Menu
                        }
                        // This will reprint the Modify Linked List Menu until the user selects option 3
                        cout << endl;
                        ModListMenu();
                        selection = boundTest(1, 3, getInput());
                    } // Exit the Modify Linked List Menu
                }
                // Linked List menu option 3 is the View List function
                else if (selection == 3) {
                    // This will check if the list is empty before entering the viewing menu
                    if (list.empty()) {
                        cout << "List View Menu unavailable. Linked List is empty." << endl;
                        break;
                    }
                    Node* viewPtr = nullptr;
                    ViewNodeMenu();
                    selection = boundTest(1, 5, getInput());
                    while (selection != 5) {
                        // View Node Menu option 1 is the view the data value at the front of the list
                        if (selection == 1) {
                            viewPtr = list.Lfront();
                            cout << "The data value at the front of the list is " << viewPtr << "." << endl;
                            cout << endl;
                        }
                        // View Node Menu option 2 is the view the data value at the back of the list
                        else if (selection == 2) {
                            viewPtr = list.Lback();
                            cout << "The data value at the back of the list is " << viewPtr << "." << endl;
                            cout << endl;
                        }
                        // View Node Menu option 3 is the view the data value at an index in the list
                        else if (selection == 3) {
                            cout << "Please enter the index to view the node at." << endl;
                            size_t userIndex = boundTest(0, list.num_items - 1, getInput());
                            list.printNode(userIndex);
                            cout << endl;
                        }
                        // View Node Menu option 4 is the view all option
                        else if (selection == 4) {
                            printList(list);
                            cout << endl;
                        }
                        // This will reprint the View Node Menu until the user selects option 5
                        cout << endl;
                        ViewNodeMenu();
                        selection = boundTest(1, 5, getInput());
                    }
                    // Exit View Node Menu
                }
                // Linked List Menu option 4 is the search function
                else if (selection == 4) {
                    cout << "What value would you like to search for?" << endl;
                    int userIn = getInput();
                    size_t out = list.find(userIn);
                    if (out == list.num_items) {
                        cout << "Item not found in list." << endl << endl;
                    }
                    else {
                        cout << "Item '" << userIn << "' found at index " << out << "." << endl << endl;
                    }
                }
                // Reprint the Linked List Menu until user selects option 4
                cout << endl;
                LinkedMenu();
                selection = boundTest(1, 5, getInput());
            }
            // Exit the Linked List Menu
        }
        // Main menu option 2 is the Stack menu
        else if (selection == 2) {
            vector <int> stack;
            int valTotal = 0;
            StackMenu();
            selection = boundTest(1, 4, getInput());
            while (selection != 4) {
                // Stack menu option 1 is the build stack function
                if (selection == 1) {
                    buildStack(stack);
                    cout << endl;
                }
                // Stack menu option 2 is the modify stack function
                else if (selection == 2) {
                    ModStackMenu();
                    selection = boundTest(1, 3, getInput());
                    while (selection != 3) {
                        // Modify Stack menu option 1 is the push function
                        if (selection == 1) {
                            cout << "Please enter the data value to push to the stack." << endl;
                            int userIn = getInput();
                            stack.push_back(userIn);
                            cout << "Pushed " << userIn << " to the stack." << endl << endl;
                        }
                        // Modify Stack menu option 2 is the pop function
                        else if (selection == 2) {
                            cout << "Popping the value " << stack.at(stack.size() - 1) << " from the stack." << endl;
                            stack.pop_back();
                            cout << "Popping complete." << endl << endl;
                        }
                        // This will reprint the Modify Stack Menu until the user selects option 3
                        cout << endl;
                        ModStackMenu();
                        selection = boundTest(1, 3, getInput());
                    }
                }
                // Stack menu option 3 is to view the Stack details
                else if (selection == 3) {
                    ViewStackMenu();
                    selection = boundTest(1, 4, getInput());
                    while (selection != 4) {
                        // View Stack Menu option 1 is the view the top of the stack
                        if (selection == 1) {
                            cout << "The top of the stack is " << stack.at(stack.size() - 1) << "." << endl << endl;
                        }
                        // View Stack Menu option 2 is the view the size of the stack
                        else if (selection == 2) {
                            cout << "The size of the stack is " << stack.size() << "." << endl;
                        }
                        // View Stack Menu option 3 is the view the average value of the stack entries
                        else if (selection == 3) {
                            for (int i = 0; i < stack.size(); ++i) {
                                valTotal += stack.at(i);
                            }
                            cout << "The average value of the stack is " << valTotal / stack.size() << "." << endl << endl;
                        }
                        // This will reprint the View Stack Menu until the user selects option 4
                        cout << endl;
                        ViewStackMenu();
                        selection = boundTest(1, 4, getInput());
                    }
                    // Exit the View Stack Menu
                }
                // This will reprint the Stack Menu until the user selects option 4
                cout << endl;
                StackMenu();
                selection = boundTest(1, 4, getInput());
            }
        }
        // Reprint the Main Menu and get a new input until the user selects option 3
        cout << endl;
        MainMenu();
        selection = boundTest(1, 3, getInput());
    }

    cout << "Thank you for using the program!" << endl;
    
    return 0;
}