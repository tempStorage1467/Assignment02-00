/*
 * File: UnitTests.h
 * ----------------------
 * Name: Eric Beach
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * Assignment 2 - Pt. 1 - Word Ladder
 * This file defines a class that performs unit tests.
 *
 * This file lightly linted using
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */

#ifndef UNITTESTS_H_
#define UNITTESTS_H_

#include <iostream>
#include <string>
#include "set.h"
#include "vector.h"
#include "WordLadderFinder.h"
#include "LexiconHelper.h"
#include "lexicon.h"

class UnitTests {
 public:
    // test the word ladder finder class
    void testWordLadderFinder();

    // test the lexicon helper class
    void testLexiconHelper();
 private:
    // determine whether two sets are equal
    bool assertEquals(const Set<string>& set1, const Set<string>& set2);

    // determine whether two vectors are equal
    bool assertEquals(const Vector<string>& vec1, const Vector<string>& vec2);

    // test the getWordsByDiffChar() method
    void testGetWordsByDiffChar();

    // test the getWordLadder() method
    void testGetWordLadder();
};

#endif  // UNITTESTS_H_
