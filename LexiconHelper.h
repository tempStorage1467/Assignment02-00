/*
 * File: LexiconHelper.h
 * ----------------------
 * Name: Eric Beach
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * Assignment 2 - Pt. 1 - Word Ladder
 * This file defines a class that helps with lexicon operations such as
 *   finding all words different by one character.
 *
 * This file lightly linted using
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */

#ifndef LEXICONHELPER_H_
#define LEXICONHELPER_H_

#include <iostream>
#include <string>
#include "set.h"
#include "lexicon.h"

class LexiconHelper {
 public:
    LexiconHelper(const Lexicon& dict);

    // get set of words that differ from the current word
    Set<string> getWordsDiffByChar(const string& currentWord);

    // get set of words that differ from the current word; improve efficiency
    Set<string> getWordsDiffByCharEffic(const string& currentWord);

 private:
    // dictionary of words to search through
    Lexicon dictionary;
};

#endif  // LEXICONHELPER_H_
