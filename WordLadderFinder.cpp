//
//  WordLadderFinder.cpp
//  Word Ladder
//
//  Created by Eric Beach on 4/17/13.
//
//

#include "WordLadderFinder.h"

WordLadderFinder::WordLadderFinder() {
    dictionary = Lexicon();
}

WordLadderFinder::WordLadderFinder(Lexicon dict) {
    dictionary = dict;
}

void WordLadderFinder::setEndingWord(string endingStr) {
    endingWord = endingStr;
}

void WordLadderFinder::setStartingWord(string startingStr) {
    startingWord = startingStr;
}

Vector<string> WordLadderFinder::getWordLadder() {
    // Step 1: Setup the dictionary
    LexiconHelper lexHelper = LexiconHelper(dictionary);

    // Step 2: Setup the queue of word ladders
    Queue<Vector <string> > ladders;
    Vector<string> firstLadder;
    firstLadder.add(startingWord);
    ladders.enqueue(firstLadder);
    
    // Step 3: Create set to store words previously used in ladder
    Set<string> usedWords;
    
    // Step 4: Breadth-first search for word ladder
    Vector <string> currentLadder;
    string lastWordInCurrentLadder;
    Set<string> wordsToExploreInLadder;
    Vector<string> newLadder;
    while (!ladders.isEmpty()) {
        currentLadder = ladders.dequeue();
        lastWordInCurrentLadder = currentLadder.get(currentLadder.size() - 1);
        if (lastWordInCurrentLadder == endingWord) {
            return currentLadder;
        }
        wordsToExploreInLadder =
          lexHelper.getWordsDiffByChar(lastWordInCurrentLadder);
        
        for (string word : wordsToExploreInLadder) {
            if (!usedWords.contains(word)) {
                newLadder = currentLadder;
                newLadder.add(word);
                ladders.enqueue(newLadder);
                usedWords.add(word);
            }
        }
    }

    // no ladder found; return a blank ladder
    currentLadder = Vector<string>();
    return currentLadder;
}