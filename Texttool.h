// Project 2
// Texttool.h

#pragma once

#include <string>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <list>

using namespace std;

class TextTool {
public:
	// default constructor
	TextTool() {
		// TO BE COMPLETED
		wordlist = new list<string>;
	
	}

	// destructor
	~TextTool() {
		// TO BE COMPLETED
		delete wordlist;
	
	}

	// Load information from a text file with the given filename.
	void loadListFromTextfile(string filename) {
		ifstream ifs;
		ifs.open(filename);

		if (ifs.is_open()) {
			string aword;
			while (ifs >> aword) {
				addEntryBack(aword);
			}
			ifs.close();
		}
		else
			throw invalid_argument("Could not open file " + filename);
	}

	// return the number of words in the linked list
	int totalWords() {
		return wordlist->size(); // TO BE COMPLETED
		
	}

	// add entry at the back of the linked list
	void addEntryBack(const string& aword) {
		// TO BE COMPLETED
		wordlist->push_back(aword);
		
	}

	// print all words stored in the linked list, separated by a space
	const string listToString() {
		// TO BE COMPLETED
		TextTool::isEmpty();
		typedef list<string>::iterator it;
		string display;
		for (it p = wordlist->begin(); p != wordlist->end(); ++p) {
			display += *p;
			display += " ";
		}
		return display;
	}

	// print duplicated words in the linked list
	void printDuplicates() {
		// TO BE COMPLETED
		for (int i = 0; i < 1500; i++) {
			cout << dupW[i] << " ";
		}
		
	}

	// remove duplicated words in the linked
	void removeDuplicates() {
		// TO BE COMPLETED
		wordlist->unique();
		
	}

	// determine the total number of duplicated words in the list
	int totalDuplicates() {
		// TO BE COMPLETED
		typedef list<string>::iterator it;
		int dup = 0;	//# of duplicates
		int i = 0;
		int x = 0;
		for (it p = wordlist->begin(); p != wordlist->end(); ++p) { //Gather wordlist data into words[i]
			words[i] = *p;
			i++;
		}
		i = 1;
		for (it p = wordlist->begin(); p != wordlist->end(); ++p) {
			if (words[i] == *p) {
				dup++;
					dupW[x] = *p;
					x++;
			}
			
			++i;
		}
	
		return dup;
		
	}

	// check if the list is empty
	bool isEmpty() {
		// TO BE COMPLETED
		if (wordlist->size() == 0) throw length_error("Nothing in the list");
	}

	// Empty the list
	void makeEmpty() {
		// TO BE COMPLETED
		wordlist->clear();
	}

private:
	string dupW[45];
	string words[1500];
	list<string> *wordlist;
};
