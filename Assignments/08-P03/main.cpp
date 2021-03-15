/*************************************************************
*                                                            *
*   Author  : Jonathan Hogan                                 *
*   E-mail  : jon.hogan83@gmail.com                          *
*   Program : P02                                            *
*   Course  : Advanced Algorithms 3013                       *
*   Semester: Spring 2021                                    *
*                                                            *
*************************************************************/

#include "getch.hpp"
#include "termcolor.hpp"
#include "timer.hpp"
#include "findWord.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

typedef std::vector<std::string> vs;


int main()
 {
    char k;                // holder for character being typed
    string word = "";      // var to concatenate letters to
    vs wordList;           // Location to read words into 
    vs matches;            // Matches found in the dictionary
    LINKEDLIST dictionary;

    ifstream fin;           // File in
    ofstream fout;          // File out
    fin.open("dictionary.txt");

    Timer timer;   // create a timer
    timer.Start(); // start it

    while(!fin.eof())
    {
        // Add words to the vector wordList
        std::string tempWord;
        fin >> tempWord;

        wordList.push_back(tempWord);

    }

    
    timer.End(); // end the current timer

    // print out how long it took to load the dictionary file
    std::cout << "It took " << timer.Seconds() << " seconds to read in the data" << std::endl;
    std::cout << "It took " << timer.MilliSeconds() << " milliseconds to read in the data" << std::endl;

    std::cout << "Type keys and watch what happens. Type capital Z to quit." << std::endl;

    timer.Start();      // start it

    // Add words to the linked list
    for (int i = 0; i < wordList.size(); i++)
    {
        wordNode* temp = new wordNode;
        temp->word = wordList[i];
        dictionary.insert(temp);
    }

    timer.End(); // end the current timer

    // print out how long it took to load the linked list dictionary
    std::cout << "It took " << timer.Seconds() << " seconds to read in the data" << std::endl;
    std::cout << "It took " << timer.MilliSeconds() << " milliseconds to read in the data" << std::endl;

    // While capital Z is not typed keep looping
    while ((k = getch()) != 'Z')
    {
        
        // Tests for a backspace and if pressed deletes
        // last letter from "word".
        if ((int)k == 127 || k == 8)
        {
            if (word.size() > 0)
            {
                word = word.substr(0, word.size() - 1);
            }
        }else
        {
            // Make sure a letter was pressed and only letter
            if (!isalpha(k))
            {
                std::cout << "Letters only!" << std::endl;
                continue;
            }

            // We know its a letter, lets make sure its lowercase.
            // Any letter with ascii value < 97 is capital so we
            // lower it.
            if ((int)k < 97)
            {
                k += 32;
            }
            word += k; // append char to word
        }

        // Find any animals in the array that partially match
        // our substr word
        timer.Start(); // start it
        matches = dictionary.search(word);
        timer.End(); // end the current timer
        std::cout << timer.Seconds() << " seconds to read in and print" << std::endl;
        std::cout << timer.MilliSeconds() << " milli to read in and print" << std::endl;

        if (word == "")
        {
          // If "word" is empty, do not print the dictionary
        }else if ((int)k != 32) 
        { 
            // if k is not a space print it
            std::cout << "Keypressed: " << termcolor::on_yellow << termcolor::blue << k << " = " << (int)k << termcolor::reset << std::endl;
            std::cout << "Current Substr: " << termcolor::red << word << termcolor::reset << std::endl;
            std::cout << "Word found: ";
            std::cout << termcolor::green;
            // This prints out all found matches
            for (int i = 0; i < matches.size(); i++) {
                std::cout << matches[i] << " ";
            }
            std::cout << termcolor::reset << std::endl
                 << std::endl;
        }

    }

    return 0;
}