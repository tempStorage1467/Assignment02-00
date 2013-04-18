/*
 * File: UnitTests.cpp
 * ----------------------
 * Name: Eric Beach
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * Assignment 2 - Pt. 1 - Word Ladder
 * This file implements a class that performs unit tests on methods
 *   used to find word ladders.
 *
 * This file lightly linted using
 * http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
 */

#include <string>
#include "UnitTests.h"

bool UnitTests::assertEquals(const Set<string>& expected,
                             const Set<string>& actual) {
    if (actual.size() != expected.size()) {
        cout << "Test Failed; Sets Unequal" << endl;
        return false;
    }
    for (string word : actual) {
        if (!expected.contains(word)) {
            cout << "Test Failed; Sets Unequal" << endl;
            return false;
        }
    }

    for (string word : expected) {
        if (!actual.contains(word)) {
            cout << "Test Failed; Sets Unequal" << endl;
            return false;
        }
    }
    return true;
}

bool UnitTests::assertEquals(const Vector<string>& expected,
                             const Vector<string>& actual) {
    if (expected.size() != actual.size()) {
        cout << "Test Failed; Vectors Unequal" << endl;
        return false;
    }
    for (int i = 0; i < expected.size(); i++) {
        if (expected.get(i) != actual.get(i)) {
            cout << "Test Failed; Vectors Unequal" << endl;
            return false;
        }
    }
    return true;
}

void UnitTests::testWordLadderFinder() {
    testGetWordLadder();
}

void UnitTests::testLexiconHelper() {
    testGetWordsByDiffChar();
}

void UnitTests::testGetWordsByDiffChar() {
    // TEST 1
    Lexicon lexicon1 = Lexicon();
    lexicon1.add("cat");
    lexicon1.add("cog");
    lexicon1.add("cot");
    lexicon1.add("dog");
    lexicon1.add("bat");
    lexicon1.add("cin");

    LexiconHelper helper1 = LexiconHelper(lexicon1);
    Set<string> words1 = helper1.getWordsDiffByChar("cat");
    Set<string> expected1;
    expected1.add("cot");
    expected1.add("bat");

    assertEquals(words1, expected1);

    // TEST 2
    Lexicon lexicon2 = Lexicon();
    lexicon2.add("chicken");
    lexicon2.add("ahicken");
    lexicon2.add("bhickan");
    lexicon2.add("chacken");
    lexicon2.add("chackin");
    lexicon2.add("chickes");
    lexicon2.add("chicken");
    lexicon2.add("chickea");
    lexicon2.add("chickez");
    lexicon2.add("chickez");
    lexicon2.add("chzcken");
    lexicon2.add("zhzcken");

    LexiconHelper helper2 = LexiconHelper(lexicon2);
    Set<string> words2 = helper2.getWordsDiffByChar("chicken");
    Set<string> expected2;
    expected2.add("ahicken");
    expected2.add("chacken");
    expected2.add("chickes");
    expected2.add("chickea");
    expected2.add("chickez");
    expected2.add("chzcken");

    assertEquals(words2, expected2);
}

void UnitTests::testGetWordLadder() {
    // TEST 1
    Lexicon lexicon1 = Lexicon();
    lexicon1.add("cat");
    lexicon1.add("cog");
    lexicon1.add("cot");
    lexicon1.add("dog");
    lexicon1.add("cin");

    WordLadderFinder finder1 = WordLadderFinder(lexicon1);
    finder1.setStartingWord("cat");
    finder1.setEndingWord("cog");

    Vector<string> ladder1 = finder1.getWordLadder();

    Vector<string> expectedLadder1;
    expectedLadder1.add("cat");
    expectedLadder1.add("cot");
    expectedLadder1.add("cog");
    assertEquals(expectedLadder1, ladder1);

    // TEST 2
    Lexicon lexicon2 = Lexicon("EnglishWords.dat");

    WordLadderFinder finder2 = WordLadderFinder(lexicon2);
    finder2.setStartingWord("code");
    finder2.setEndingWord("data");

    Vector<string> ladder2 = finder2.getWordLadder();

    Vector<string> expectedLadder2;
    expectedLadder2.add("code");
    expectedLadder2.add("cade");
    expectedLadder2.add("cate");
    expectedLadder2.add("date");
    expectedLadder2.add("data");
    assertEquals(expectedLadder2, ladder2);

    // TEST 3
    Lexicon lexicon3 = Lexicon("EnglishWords.dat");

    WordLadderFinder finder3 = WordLadderFinder(lexicon3);
    finder3.setStartingWord("cat");
    finder3.setEndingWord("bag");

    Vector<string> ladder3 = finder3.getWordLadder();

    Vector<string> expectedLadder3;
    expectedLadder3.add("cat");
    expectedLadder3.add("bat");
    expectedLadder3.add("bag");
    assertEquals(expectedLadder3, ladder3);

    // TEST 4
    Lexicon lexicon4 = Lexicon("EnglishWords.dat");

    WordLadderFinder finder4 = WordLadderFinder(lexicon4);
    finder4.setStartingWord("people");
    finder4.setEndingWord("person");

    Vector<string> ladder4 = finder4.getWordLadder();

    Vector<string> expectedLadder4;
    assertEquals(expectedLadder4, ladder4);

    // TEST 5
    Lexicon lexicon5 = Lexicon("EnglishWords.dat");

    WordLadderFinder finder5 = WordLadderFinder(lexicon5);
    finder5.setStartingWord("apple");
    finder5.setEndingWord("chair");

    Vector<string> ladder5 = finder5.getWordLadder();

    Vector<string> expectedLadder5;
    expectedLadder5.add("apple");
    expectedLadder5.add("ample");
    expectedLadder5.add("amole");
    expectedLadder5.add("anole");
    expectedLadder5.add("anile");
    expectedLadder5.add("anise");
    expectedLadder5.add("arise");
    expectedLadder5.add("prise");
    expectedLadder5.add("prase");
    expectedLadder5.add("phase");
    expectedLadder5.add("chase");
    expectedLadder5.add("chare");
    expectedLadder5.add("charr");
    expectedLadder5.add("chair");
    assertEquals(expectedLadder5, ladder5);

    // TEST 6
    Lexicon lexicon6 = Lexicon("EnglishWords.dat");

    WordLadderFinder finder6 = WordLadderFinder(lexicon6);
    finder6.setStartingWord("john");
    finder6.setEndingWord("mike");

    Vector<string> ladder6 = finder6.getWordLadder();

    Vector<string> expectedLadder6;
    expectedLadder6.add("john");
    expectedLadder6.add("join");
    expectedLadder6.add("coin");
    expectedLadder6.add("conn");
    expectedLadder6.add("cone");
    expectedLadder6.add("cine");
    expectedLadder6.add("mine");
    expectedLadder6.add("mike");
    assertEquals(expectedLadder6, ladder6);
}
