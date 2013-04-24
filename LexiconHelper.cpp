/*
 * File: LexiconHelper.cpp
 * ----------------------
 * Name: Eric Beach
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * Assignment 2 - Pt. 1 - Word Ladder
 * This file implements a class responsible for helping with lexicon
 *  operations such as finding words different by one character.
 *
 * This file lightly linted using
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */

#include <string>
#include "time.h"
#include "LexiconHelper.h"

/*
 * Constructor to receive a lexicon to work on.
 */
LexiconHelper::LexiconHelper(const Lexicon& dict) {
    this->dictionary = dict;
}

/*
 * Compute all the words
 */
Set<string> LexiconHelper::getWordsDiffByChar(const string& currentWord) {    
    Set<string> words;
    string wordPermutation;
    for (int i = 0; i < currentWord.length(); i++) {
        for (int j = 'a'; j <= 'z'; j++) {
            wordPermutation = currentWord;
            wordPermutation[i] = j;
            if (this->dictionary.contains(wordPermutation)
                && wordPermutation != currentWord) {
                words.add(wordPermutation);
            }
        }
    }
    return words;
}

/*
 * Compute all the words, using some efficiency improvements
 */
Set<string> LexiconHelper::getWordsDiffByCharEffic(const string& currentWord) {
    Set<string> words;
    string wordPermutation;
    for (int i = 0; i < currentWord.length(); i++) {
        if (!this->dictionary.containsPrefix(currentWord.substr(0, i))) {
            continue;
        }
        for (int j = 'a'; j <= 'z'; j++) {
            wordPermutation = currentWord;
            wordPermutation[i] = j;
            if (this->dictionary.contains(wordPermutation)
                && wordPermutation != currentWord) {
                words.add(wordPermutation);
            }
        }
    }
    return words;
}