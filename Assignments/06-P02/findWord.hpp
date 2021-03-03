#include "getch.hpp"
#include "termcolor.hpp"
#include "timer.hpp"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
typedef vector<string> vs;

/**
 * Description:
 *      Originally wrote this to count size of input file so
 *      I could allocate enough memory for an array of strings
 *      but I went with a vector below. But I'm keeping it and
 *      using it anyway!
 * Params:
 *      string file_name - file to get the line count
 * 
 * Returns:
 *      int - line count
 */
// int CountLines(string file_name) {
//     ifstream inFile(file_name);
//     return count(istreambuf_iterator<char>(inFile), istreambuf_iterator<char>(), '\n');
// }

/**
 * Description:
 *      Loads a file of strings (words, names, whatever) reading them in
 *      with one word per line. So words must be delimited by newlines '\n'
 * Params:
 *      string file_name - file to get the line count
 * 
 * Returns:
 *      int - line count
 */
vector<string> LoadAnimals(string file_name) {
    ifstream fin;                            // file to get animal names
    int count = 224; // get size of input file
    vector<string> array(count);             // allocate vector of correct size

    fin.open("animals.txt"); // open file for reading

    // knowing the size of the file lets us treat
    // it like an array without using .push_back(value)
    for (int i = 0; i < count; i++) {
        fin >> array[i];           // read in animals
        for (auto &c : array[i]) { // c++ 11 style loop
            c = tolower(c);        // lowercase the animal name
        }
    }
    return array;
}

/**
 * Description:
 *      Finds partial matches in an array of strings and returns them. It
 *      doesn't matter where in the string the match is.
 * Params:
 *      vector<string>  array       - array to search
 *      string          substring   - substring to search for in each word
 * 
 * Returns:
 *      vector<string> - holding all the matches to substring
 */
vector<string> FindAnimals(vector<string> array, string substring) {
    vector<string> matches; // to hold any matches
    size_t found;           // size_t is an integer position of
                            // found item. -1 if its not found.

    for (int i = 0; i < array.size(); i++) { // loop through array
        found = array[i].find(substring);    // check for substr match
        if (found != string::npos) {         // if found >= 0 (its found then)
            matches.push_back(array[i]);     // add to matches
        }
    }

    return matches;
}

/***********************************************************************************
 
  __       __  __      __         ______    ______   _______   ________ 
 /  \     /  |/  \    /  |       /      \  /      \ /       \ /        |
 $$  \   /$$ |$$  \  /$$/       /$$$$$$  |/$$$$$$  |$$$$$$$  |$$$$$$$$/ 
 $$$  \ /$$$ | $$  \/$$/        $$ |  $$/ $$ |  $$ |$$ |  $$ |$$ |__    
 $$$$  /$$$$ |  $$  $$/         $$ |      $$ |  $$ |$$ |  $$ |$$    |   
 $$ $$ $$/$$ |   $$$$/          $$ |   __ $$ |  $$ |$$ |  $$ |$$$$$/    
 $$ |$$$/ $$ |    $$ |          $$ \__/  |$$ \__$$ |$$ |__$$ |$$ |_____ 
 $$ | $/  $$ |    $$ |          $$    $$/ $$    $$/ $$    $$/ $$       |
 $$/      $$/     $$/            $$$$$$/   $$$$$$/  $$$$$$$/  $$$$$$$$/ 
                                                                        
                                                                        
                                                                        
 
***********************************************************************************/
