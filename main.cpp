// Project 2
// main.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

#include "Texttool.h"

using namespace std;
int i = 0;	// for test step numbering.

#define SMALL_FILE_WORDS 36
#define SMALL_FILE_DUPS 6
#define LARGE_FILE_WORDS 1345
#define LARGE_FILE_DUPS 45

int main() {
	try {
		{
			cout << "CPSC131 PROJECT 2" << endl << endl;
			cout << "TESTING: BASIC LIST OPERATIONS" << endl << endl;

			// constructor test
			cout << "\t" << ++i << ". Testing: constructor and function totalWords()... ";
			TextTool test;
			assert(test.totalWords() == 0);
			cout << "--> PASSED." << endl;
			cout << "\t" << ++i << ". Testing: list insertion and function printAll()... ";
			test.addEntryBack("This");
			assert(test.totalWords() == 1);
			test.addEntryBack("is");
			assert(test.totalWords() == 2);
			assert(test.listToString() == "This is ");
			cout << "--> PASSED." << endl;
			cout << "\t" << ++i << ". Testing: list erase... ";
			test.makeEmpty();
			assert(test.totalWords() == 0);
			cout << "--> PASSED." << endl << endl;
		}

		{   // test full code with a small text file
			cout << "TESTING: USING SMALL TEXT FILE:" << endl << endl;
			cout << "\t" << ++i << ". Testing: verify number of words loaded... ";
			TextTool test;
			test.loadListFromTextfile("small_file.txt");	// load linked list with words from a text file
			assert(test.totalWords() == SMALL_FILE_WORDS);	// verify number of words loaded
			cout << "--> PASSED." << endl << endl;
			cout << "\t" << "Print the list:" << endl << endl;
			cout << test.listToString() << endl << endl;	// convert linked list to a string and then output
			cout << "\t" << ++i << ". Testing: find number of duplicated words... ";
			assert(test.totalDuplicates() == SMALL_FILE_DUPS);	// determine number of duplicates in the linked list
			cout << "--> PASSED." << endl;
			test.printDuplicates();	// output the duplicates found
			cout << "\t" << ++i << ". Testing: removal of duplicated words... ";
			test.removeDuplicates();	// remove all duplicated words from the linked list
			assert(test.totalDuplicates() == 0);
			cout << "--> PASSED." << endl << endl;
			cout << "\t" << "Print the file after removal of duplicated words:" << endl << endl;
			cout << test.listToString() << endl << endl; // display the final linked list contents
			cout << "FINISHED TESTING USING SMALL TEXT FILE." << endl << endl;
		}

		{   // test full code with a large text file
			cout << "TESTING: USING LARGE TEXT FILE:" << endl << endl;
			cout << "\t" << ++i << ". Testing: verify number of words loaded... ";
			TextTool test;
			test.loadListFromTextfile("large_file.txt");	// load linked list with words from a text file
			assert(test.totalWords() == LARGE_FILE_WORDS);	// verify number of words loaded
			cout << "--> PASSED." << endl << endl;
			cout << "\t" << "Print the list:" << endl << endl;
			cout << test.listToString() << endl << endl;	// convert linked list to a string and then output
			cout << "\t" << ++i << ". Testing: find number of duplicated words... ";
			assert(test.totalDuplicates() == LARGE_FILE_DUPS);	// determine number of duplicates in the linked list
			cout << "--> PASSED." << endl;
			test.printDuplicates();	// output the duplicates found
			cout << "\t" << ++i << ". Testing: removal of duplicated words... ";
			test.removeDuplicates();	// remove all duplicated words from the linked list
			assert(test.totalDuplicates() == 0);
			cout << "--> PASSED." << endl << endl;
			cout << "\t" << "Print the file after removal of duplicated words:" << endl << endl;
			cout << test.listToString() << endl << endl; // display the final linked list contents
			cout << "FINISHED TESTING USING LARGE TEXT FILE." << endl << endl;
		}
	}
	catch (exception &e) {
		cout << e.what() << endl;
	}

	// system("pause");
}

