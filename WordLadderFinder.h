/*
 * File: WordLadder.h
 * ----------------------
 * Name: Eric Beach
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * Assignment 2 - Pt. 1 - Word Ladder
 * This file defines a class responsible for finding word ladders between
 *   two words.
 *
 * This file lightly linted using
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */

#ifndef WORDLADDERFINDER_H_
#define WORDLADDERFINDER_H_

#include <iostream>
#include <string>
#include "lexicon.h"
#include "queue.h"
#include "vector.h"
#include "set.h"
#include "LexiconHelper.h"

class WordLadderFinder {
 public:
    // defaut constructor
    WordLadderFinder();

    // constructor to receive a lexicon
    WordLadderFinder(const Lexicon& dict);

    // set the starting word of the word ladder
    void setStartingWord(const string& startingStr);

    // set the ending word of the word ladder
    void setEndingWord(const string& endingStr);

    // get a word ladder
    Vector<string> getWordLadder();

 private:
    string endingWord;
    string startingWord;
    Lexicon dictionary;
};

#endif  // WORDLADDERFINDER_H_
