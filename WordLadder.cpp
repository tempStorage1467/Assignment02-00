/*
 * File: WordLadder.cpp
 * ----------------------
 * Name: Eric Beach
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * Assignment 2 - Pt. 1 - Word Ladder
 * This file is main file for the Word Ladder problem. It contains the logic
 *   that runs the program.
 *
 * This file lightly linted using
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */

#include <string>
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "queue.h"
#include "vector.h"
#include "WordLadderFinder.h"
#include "UnitTests.h"

using namespace std;

void printLadder(const Vector<string>& ladder) {
    if (ladder.size() == 0) {
        cout << "No word ladder could be found." << endl;
    } else {
        string toPrint = "";
        toPrint += "Ladder found: ";
        for (int i = 0; i < ladder.size(); i++) {
            toPrint += ladder.get(i) + " --> ";
        }
        toPrint = toPrint.substr(0, toPrint.size() - 4);
        cout << toPrint << endl;
    }
}

string getWord(const string& prompt) {
    string input = getLine(prompt);
    input = toLowerCase(input);
    return input;
}

int runWordLadder() {
    // Setup: Get starting and ending words
    string startingWord = getWord("Enter starting word (or nothing to quit): ");
    if (startingWord.size() < 1) {
        return 0;
    }

    string endingWord = getWord("Enter ending word: ");
    if (startingWord.size() != endingWord.size()) {
        cout << "No word ladder could be found. Enter words of the " <<
                "same length" << endl;
        return 1;
    }

    Lexicon englishWords = Lexicon("EnglishWords.dat");
    WordLadderFinder finder = WordLadderFinder(englishWords);
    finder.setStartingWord(startingWord);
    finder.setEndingWord(endingWord);
    Vector<string> ladder = finder.getWordLadder();
    printLadder(ladder);
    return 1;
}

int main() {
    // Run Unit Tests
    UnitTests tests = UnitTests();
    tests.testLexiconHelper();
    tests.testWordLadderFinder();

    // Run Word Ladder
    while (runWordLadder()) {
        cout << endl;
    }
    return 0;
}
