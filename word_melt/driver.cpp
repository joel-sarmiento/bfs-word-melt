/*
 * file: driver-proj2.cpp
 * author: Joel Sarmiento
 *
 * This file is the driver that solves a word melt using BFS
 */

#include <iostream>
#include <set>
#include <map>
#include <vector>
#include "maze.h"
#include "arrayqueue-student.h"
#include "arrayqueue-prof.h"
#include "location.h"

using namespace std;

/*
 * main
 *
 * main streams in a given word melt and uses DFS to solve
 *
 * Parameters:
 *     argc: the number of arguments entered on the command line
 *     argv: array of char pointers that represent command line arguments
 *           passed to the program
 *
 * Return value: exit status
 */
int main(int argc, const char *argv[])
{
    // Data Abstraction
    Maze wordMelt;
    ArrayQueue<Location> queue;
    map<Location, Location> previous;

    // Input word melt and initialize the predecessor of the start to itself
    cin >> wordMelt;
    queue.add(wordMelt.getStartLocation());
    previous[wordMelt.getStartLocation()] = wordMelt.getStartLocation();

    // BFS
    while (queue.getLength() != 0 && !wordMelt.isEndLocation(queue.getFront()))
    {
        Location current = queue.getFront();
        queue.remove();

        for (current.iterationBegin(); !current.iterationDone(); current.iterationAdvance())
        {
            Location neighbor = current.iterationCurrent();

            if (wordMelt.isValidLocation(neighbor) && previous.find(neighbor) == previous.end())
            {
                queue.add(neighbor);
                previous[neighbor] = current;
            }
        }
    }

    // Output
    if (queue.getLength() != 0)
    {
        cout << "Solution found" << endl;
        map<Location, Location>::iterator it;
        Location current;

        // Set 'current' to the last word of word melt
        for (it = previous.begin(); it != previous.end(); ++it)
        {
            if (wordMelt.isEndLocation(it->first))
            {
                current = it->first;
            }
        }

        // Backtrack from end to start of word melt
        vector<Location> output;
        while (!(previous.find(current)->second == current))
        {
            output.push_back(current);
            current = previous.find(current)->second;
        }
        output.push_back(current);

        // Reverse output
        for (auto it = output.rbegin(); it != output.rend(); ++it)
        {
            cout << *it << endl;
        }
    }
    else
    {
        cout << "No solution" << endl;
    }

    return 0;
}
