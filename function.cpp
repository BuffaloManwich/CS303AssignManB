#include "function.h"

// This function's purpose is to print a Linked list
void printList(Linked& list) {
    cout << "List: " << endl;
    list.printList();
}

// This function removes alphabetical chars and symbols from a string
string cleanInput(string in) {
    string out = "";
    size_t negCount = 0;
    size_t i;
    // Iterate over each char over the length of string
    for (i = 0; i < in.size(); ++i) {
        // This line adds chars to str out if a neg sign or int.
        if ((in.at(i) == '-' && negCount == 0) || isdigit(in.at(i))) {
            out += in.at(i);
            // This ensures only one neg sign is added to the out string
            if (in.at(i) == '-') { negCount = 1; }
        }
    }
    // "Out" string is finished, verify string not empty, and not solely a neg sign.
    if ((out.size() == 1 && out.at(0) == '-') || out.empty()) {
        out = "ERROR";
    }
    // Function will return either a convertable numeric string or the word "ERROR"
    return out;
}

size_t boundTest(int min, int max, int in) {
    // This will ensure the now confirmed input integer is within the bounds
    while (in < min || in > max) {
        cout << "ERROR: Entry out of bounds." << endl;
        cout << "Please enter a valid selection, values " << min << " - " << max << "." << endl;
        in = getInput();
    }
    return in;
}

int getInput() {
    // This is a function that will have a verification loop for user inputs.
    int out;
    string userIn;
    string userNo;

    getline(cin, userIn);
    userNo = cleanInput(userIn);
    // If userNo is "ERROR", enter while loop until valid choice is input.
    if (userNo == "ERROR") {
        while (userNo == "ERROR") {
            cout << userNo << ": Invalid entry! Please enter a valid selection." << endl;
            getline(cin, userIn);
            userNo = cleanInput(userIn);
        }
    }
    try {
        out = stoi(userNo);
        return out;
    }
    catch (const invalid_argument&) {
        cout << "ERROR: Invalid entry!" << endl;
        return getInput();
    }
}

void buildList(Linked& list) {
    // This function will build a linked list of integers based on user input.
    cout << "How many integer will be in the list?" << endl;
    int numIntegers = getInput();
    cout << "Please enter the integers in the list." << endl;
    for (int i = 0; i < numIntegers; ++i) {
        int userIn = getInput();
        list.add_back(userIn);
        cout << endl;
    }
    cout << "List built successfully." << endl;
    list.printList();
    cout << endl;
}

void buildStack(vector <int>& stack) {
    // This function will build a stack of integers based on user input.
    cout << "How many integers will be in the stack?" << endl;
    int numIntegers = getInput();
    cout << "Please enter the integers in the stack." << endl;
    cout << "Note: The first integer will be at the bottom of the stack." << endl;
    for (int i = 0; i < numIntegers; ++i) {
        int userIn = getInput();
        stack.push_back(userIn);
        cout << endl;
    }
}