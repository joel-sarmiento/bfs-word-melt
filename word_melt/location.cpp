/*
 * file: location.cpp
 * author: Joel Sarmiento
 *
 * This file implements the methods of Location
 */

#include "location.h"
#include <cassert>


/*
 * Location
 *
 * This constructor initializes the data members
 *
 * Parameters: none
 *
 * Return value: none
 */
Location::Location() {
    word = "";
    iterationMode = CHANGE_LETTER;
    indexToChange = 0;
    nextLetter = 'a';
}


/*
 * iterationBegin
 *
 * This constructor initializes the data members
 *
 * Parameters: none
 *
 * Return value: none
 */
void Location::iterationBegin() {
    iterationMode = CHANGE_LETTER;
    indexToChange = 0;
    nextLetter = 'a';
    if (word[indexToChange] == nextLetter) {
        nextLetter++;
    }
}


/*
 * iterationCurrent
 *
 * This function modifies a word 'x' in three ways:
 *  1. changing a letter in x
 *  2. inserting a new letter in x
 *  3. deleting a letter from x
 * depending on what iteration mode it is in
 *
 * Parameters: none
 *
 * Return value: neighbor of a word
 */
Location Location::iterationCurrent() const {
    Location neighbor = *this;
    
    assert(iterationMode != DONE);
    
    if (iterationMode == CHANGE_LETTER) {
        neighbor.word[indexToChange] = nextLetter;
    }
    if (iterationMode == INSERT_LETTER) {
        neighbor.word.insert(indexToChange, 1, nextLetter);
    }
    if (iterationMode == DELETE_LETTER) {
        neighbor.word.erase(indexToChange, 1);
    }
    
    return neighbor;
    
}

/*
 * iterationAdvance
 *
 * This function advances the iterationMode of a word
 *
 * Parameters: none
 *
 * Return value: none
 */
void Location::iterationAdvance() {
    Location neighbor = *this;
    
    if (iterationMode == CHANGE_LETTER) {
        
        //handles case of changing 'z' back to 'a'
        if (nextLetter < 'z') {
            nextLetter++;
        } else {
            nextLetter = 'a';
            indexToChange++;
        }
        
        //handles case of letter at index being same as nextLetter
        if (neighbor.word[indexToChange] == nextLetter) {
            if (neighbor.word[indexToChange] == 'z') {
                indexToChange++;
            } else {
                nextLetter++;
            }
        }
        
        //prepare for next mode after passing through all letters
        if (indexToChange >= word.length()) {
            iterationMode = INSERT_LETTER;
            indexToChange = 0;
            nextLetter = 'a';
        }
        
    }
    else if (iterationMode == INSERT_LETTER) {
        
        //handles case of changing 'z' back to 'a'
        if (nextLetter < 'z') {
            nextLetter++;
        } else {
            nextLetter = 'a';
            indexToChange++;
        }
        
        //prepare for next mode after passing through all letters
        if (indexToChange > word.length()) {
            iterationMode = DELETE_LETTER;
            indexToChange = 0;
            nextLetter = 'a';
        }
        
    }
    else if (iterationMode == DELETE_LETTER) {
        
        indexToChange++;
        
        //done if passed through all letters
        if (indexToChange >= word.length()) {
            iterationMode = DONE;
        }
        
    }
    
}


/*
 * iterationDone
 *
 * This function returns whether the iteration is done or not
 *
 * Parameters: none
 *
 * Return value: true if iteration is done, false if it is not done
 */
bool Location::iterationDone() const {
    return (iterationMode == DONE);
}


/*
 * operator==
 *
 * This compares to see if two words are the same
 *
 * Parameters:
 *     loc: a word that will be compared with another word
 *
 * Return value: true if words are the same, false if they are not
 */
bool Location::operator==(const Location &loc) const {
    return (word == loc.word);
}


/*
 * operator<<
 *
 * This provides a means of streaming a word out
 *
 * Parameters: 
 *     os: a means of streaming out a word
 *     loc: a word to be output
 *
 * Return value: a reference to the given stream for chaining purposes
 */
ostream &operator<<(ostream &os, const Location &loc) {
    os << loc.word;
    
    return os;
}


/*
 * operator>>
 *
 * This provides a means of streaming a word in
 *
 * Parameters:
 *     is: a means of streaming in a word
 *     loc: a word to be input
 *
 * Return value: a reference to the given stream for chaining purposes
 */
istream &operator>>(istream &is, Location &loc) {
    is >> loc.word;
    
    return is;
}


/*
 * opertor<
 *
 * This compares two words to keep them in order
 *
 * Parameters:
 *     loc: a word to be compared to another word
 *
 * Return value: return true if the word precedes another word, false if not
 */
bool Location::operator<(const Location &loc) const {
    return (word < loc.word);
}


