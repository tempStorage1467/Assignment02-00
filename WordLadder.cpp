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

#include <iostream>
#include "console.h"
#include "simpio.h"
#include "queue.h"
#include "vector.h"
#include "WordLadderFinder.h"
#include "UnitTests.h"

using namespace std;


string getWord(string prompt) {
    string input = getLine(prompt);
    // TODO: convert to lower case
}

int main() {
    // Run Unit Tests
    UnitTests tests = UnitTests();
    tests.testLexiconHelper();
    tests.testWordLadderFinder();
    
    // Setup: Get starting and ending words
    string startingWord = getWord("Enter starting word (or nothing to quit): ");
    string endingWord = getWord("Enter ending word: ");
    if (startingWord == "") {
        return 0;
    } else if (startingWord.size() != endingWord.size()) {
        cout << "No word ladder could be found";
    }
    
    Lexicon englishWords = Lexicon("EnglishWords.dat");
    WordLadderFinder finder = WordLadderFinder(englishWords);
    finder.setStartingWord(startingWord);
    finder.setEndingWord(endingWord);
    finder.getWordLadder();
    
    return 0;
}
