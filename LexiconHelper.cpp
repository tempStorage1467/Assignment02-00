//
//  LexiconHelper.cpp
//  Word Ladder
//
//  Created by Eric Beach on 4/18/13.
//
//

#include "LexiconHelper.h"

LexiconHelper::LexiconHelper(Lexicon dict) {
    dictionary = dict;
}

Set<string> LexiconHelper::getWordsDiffByChar(string currentWord) {
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