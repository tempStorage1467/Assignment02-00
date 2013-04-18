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
    WordLadderFinder();
    WordLadderFinder(const Lexicon& dict);
    void setStartingWord(const string& startingStr);
    void setEndingWord(const string& endingStr);
    Vector<string> getWordLadder();

 private:
    string endingWord;
    string startingWord;
    Lexicon dictionary;
};

#endif  // WORDLADDERFINDER_H_
