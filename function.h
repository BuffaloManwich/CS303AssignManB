#pragma once

#include <vector>
#include <iomanip>
#include <iostream>
#include <string>
#include "menus.h"
#include "linked.h"

using namespace std;


void printList(Linked& list);

string cleanInput(string in);

size_t boundTest(int min, int max, int in);

int getInput();

void buildList(Linked& list);

void buildStack(vector <int>& stack);
