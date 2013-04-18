//
//  LexiconHelper.h
//  Word Ladder
//
//  Created by Eric Beach on 4/18/13.
//
//

#ifndef __Word_Ladder__LexiconHelper__
#define __Word_Ladder__LexiconHelper__

#include <iostream>
#include <string>
#include "set.h"
#include "lexicon.h"
#include "set.h"

class LexiconHelper {
public:
    LexiconHelper(Lexicon dict);
    Set<string> getWordsDiffByChar(string currentWord);
    
private:
    Lexicon dictionary;
};

#endif /* defined(__Word_Ladder__LexiconHelper__) */
