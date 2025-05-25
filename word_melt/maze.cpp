/*
 * file: maze.cpp
 * author: Joel Sarmiento
 *
 * This file contains the implementations of the Maze class methods
 */

#include "maze.h"


/*
 * Maze
 *
 * The constructor is empty validLocations is no longer an array
 *
 * Parameters: none
 *
 * Return value: none
 */
Maze::Maze() {}


/*
 * getStartLocation
 *
 * This function returns the start location of the maze
 *
 * Parameters: none
 *
 * Return value: start location of maze
 */
Location Maze::getStartLocation() const {
    return startLocation;
}


/*
 * isValidLocation
 *
 * This function checks to see if a location is a valid location of
 * a maze
 *
 * Parameters:
 *     loc: a location that is checked to see if it is valid
 *
 * Return value: true if location is valid, false if otherwise
 */
bool Maze::isValidLocation(const Location &loc) const {
    return (validLocations.find(loc) != validLocations.end());
}


/*
 * isEndLocation
 *
 * This functions checks to see if a given location is the end location
 *
 * Parameters:
 *     loc: a location that is checked to see if it is the end location
 *
 * Return value: true if the location is the end location, false if otherwise
 */
bool Maze::isEndLocation(const Location &loc) const {
    return (endLocation == loc);
}


/*
 * operator>>
 *
 * This streams in a maze
 *
 * Parameters:
 *     is: a means of streaming in a maze
 *     m: a given maze to be solved
 *
 * Return value: a reference to the stream for chaining purposes
 */
istream &operator>>(istream &is, Maze &m) {
    int validLocationCount;
    is >> validLocationCount;
    m.validLocations.clear();
    
    Location loc;
    for (int i = 0; i < validLocationCount; i++) {
        is >> loc;
        m.validLocations.insert(loc);
    }
    
    is >> m.startLocation >> m.endLocation;
    
    return is;
}

