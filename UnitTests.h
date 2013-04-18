//
//  UnitTests.h
//  Word Ladder
//
//  Created by Eric Beach on 4/18/13.
//
//

#ifndef __Word_Ladder__UnitTests__
#define __Word_Ladder__UnitTests__

#include <iostream>
#include <string>
#include "set.h"
#include "vector.h"
#include "WordLadderFinder.h"
#include "LexiconHelper.h"
#include "lexicon.h"

class UnitTests {
 public:
    void testWordLadderFinder();
    void testLexiconHelper();
 private:
    bool assertEquals(Set<string> set1, Set<string> set2);
    bool assertEquals(Vector<string> vec1, Vector<string> vec2);
    void testGetWordsByDiffChar();
    void testGetWordLadder();
};

#endif /* defined(__Word_Ladder__UnitTests__) */
