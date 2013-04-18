/*
 * File: WordLadderFinder.cpp
 * ----------------------
 * Name: Eric Beach
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * Assignment 2 - Pt. 1 - Word Ladder
 * This file implements a class responsible for finding a word ladder
 *   between two words.
 *
 * This file lightly linted using
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */

#include <string>
#include "WordLadderFinder.h"

WordLadderFinder::WordLadderFinder() {
    dictionary = Lexicon();
}

WordLadderFinder::WordLadderFinder(const Lexicon& dict) {
    dictionary = dict;
}

void WordLadderFinder::setEndingWord(const string& endingStr) {
    endingWord = endingStr;
}

void WordLadderFinder::setStartingWord(const string& startingStr) {
    startingWord = startingStr;
}

Vector<string> WordLadderFinder::getWordLadder() {
    // Step 1: Setup the dictionary
    LexiconHelper lexHelper = LexiconHelper(dictionary);

    // Step 2: Setup the queue of word ladders
    Queue<Vector <string> > ladders;
    Vector<string> firstLadder;
    firstLadder.add(startingWord);
    ladders.enqueue(firstLadder);

    // Step 3: Create set to store words previously used in ladder
    Set<string> usedWords;

    // Step 4: Breadth-first search for word ladder
    Vector <string> currentLadder;
    string lastWordInCurrentLadder;
    Set<string> wordsToExploreInLadder;
    Vector<string> newLadder;
    while (!ladders.isEmpty()) {
        currentLadder = ladders.dequeue();
        lastWordInCurrentLadder = currentLadder.get(currentLadder.size() - 1);
        if (lastWordInCurrentLadder == endingWord) {
            return currentLadder;
        }
        wordsToExploreInLadder =
          lexHelper.getWordsDiffByChar(lastWordInCurrentLadder);

        for (string word : wordsToExploreInLadder) {
            if (!usedWords.contains(word)) {
                newLadder = currentLadder;
                newLadder.add(word);
                ladders.enqueue(newLadder);
                usedWords.add(word);
            }
        }
    }

    // no ladder found; return a blank ladder
    currentLadder = Vector<string>();
    return currentLadder;
}
