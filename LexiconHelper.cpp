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
#include "LexiconHelper.h"

LexiconHelper::LexiconHelper(const Lexicon& dict) {
    dictionary = dict;
}

Set<string> LexiconHelper::getWordsDiffByChar(const string& currentWord) {
    Set<string> words;
    // TODO: use prefix to narrow search
    string wordPermutation;
    for (int i = 0; i < currentWord.length(); i++) {
        for (int j = 'a'; j <= 'z'; j++) {
            wordPermutation = currentWord;
            wordPermutation[i] = j;
            if (dictionary.contains(wordPermutation)
                && wordPermutation != currentWord) {
                words.add(wordPermutation);
            }
        }
    }
    return words;
}
