//
//  WordLadderFinder.h
//  Word Ladder
//
//  Created by Eric Beach on 4/17/13.
//
//

#ifndef __Word_Ladder__WordLadderFinder__
#define __Word_Ladder__WordLadderFinder__

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
    WordLadderFinder(Lexicon dict);
    void setStartingWord(string startingStr);
    void setEndingWord(string endingStr);
    Vector<string> getWordLadder();

 private:
    string endingWord;
    string startingWord;
    Lexicon dictionary;
};

#endif /* defined(__Word_Ladder__WordLadderFinder__) */
