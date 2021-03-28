/*************************************************************
**************************************************************
//                                                          //
//   Author  : Jonathan Hogan                               //
//   E-mail  : jon.hogan83@gmail.com                        //
//   Program : P04                                          //
//   Course  : Advanced Algorithms 3013                     //
//   Semester: Spring 2021                                  //
//                                                          //
**************************************************************
*************************************************************/

#include <iostream>
#include "getch.hpp"
#include "termcolor.hpp"
#include <string>
#include <vector>
#include <fstream>
#include "timer.hpp"
#include "trie.hpp"

int main()
{
    TrieTree search;
    vector<string> dictionary;      // Placeholder Dictionary to read in the words.txt data

    ifstream in;
    in.open("dictionary.txt");


    Timer T1000;                    // Timer object
    T1000.Start();                  // Timing how long it takes to read and load the data

    while (!in.eof())               // Reading in the dictionary words
    {
        string Temp;

        in >> Temp;

        dictionary.push_back(Temp);
    }

    T1000.End();

    cout << T1000.Seconds() << " seconds to read in the data." << endl;


    for (int i = 0; i < dictionary.size(); i++)
    {
        string Temp = dictionary[i];

        search.insert(Temp);
    }



    char k;                 // holder for character being typed
    std::string word = "";       // var to concatenate letters to
    std::vector<std::string> matches; // any matches found in vector of Dictionary Words

    std::string topResults[10];
    int searchResults;

    cout << endl << "Type keys and watch what happens. Type capital Z to quit." << endl;

    // While capital Z is not typed keep looping
    while ((k = getch()) != 'Z')
    {

        // Tests for a backspace and if pressed deletes 
        // last letter from "word".
        if ((int)k == 127)
        {
            if (word.size() > 0)
            {
                word = word.substr(0, word.size() - 1);
            }
        }

        else
        {
            // Make sure a letter was pressed and only letter
            if (!isalpha(k))
            {
                cout << "Letters only!" << endl;
                continue;
            }

            // We know its a letter, lets make sure its lowercase.
            // Any letter with ascii value < 97 is capital so we
            // lower it.

            /*
                Reversed the ASCII values from starter code since my txt file is all
                capital letters, += 32 becomes -= 32, flipped < to > etc.
            */
            if ((int)k >= 97)
            {
                k -= 32;
            }
            word += k; // append char to word
        }


        Timer suggestion;           // Timer for how long it takes to return word suggestions and total words found

        suggestion.Start();
        matches = search.find(word);
        suggestion.End();

        searchResults = matches.size();


        if ((int)k != 32)
        { // if k is not a space print it
            std::cout << "Keypressed: " << termcolor::on_yellow << termcolor::blue << k << " = " << (int)k
                      << termcolor::reset << std::endl;

            std::cout << "Current Substr: " << termcolor::red << word << termcolor::reset << std::endl;

            std::cout << searchResults << " words found in " << termcolor::green << suggestion.Seconds() << " seconds"
                      << termcolor::reset << std::endl;

            // This prints out the top ten results
            if (matches.size() >= 10)
            {
                for (int i = 0; i < 10; i++)
                {
                    topResults[i] = matches[i];
                    std::cout << topResults[i] << " ";
                }
            }else
            {
                for (int i = 0; i < matches.size(); i++)
                {
                    topResults[i] = matches[i];
                    std::cout << topResults[i] << " ";
                }
            }

            std::cout << std::endl << std::endl;
        }
    }

    return 0;
}