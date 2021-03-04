#include "getch.hpp"
#include "termcolor.hpp"
#include "timer.hpp"
#include <fstream>
#include <iostream>
#include <vector>

typedef std::vector<std::string> vs;


/***********************************************************************************
************************************************************************************ 
**  __       __  __      __         ______    ______   _______   ________         **
** /  \     /  |/  \    /  |       /      \  /      \ /       \ /        |        **
** $$  \   /$$ |$$  \  /$$/       /$$$$$$  |/$$$$$$  |$$$$$$$  |$$$$$$$$/         **
** $$$  \ /$$$ | $$  \/$$/        $$ |  $$/ $$ |  $$ |$$ |  $$ |$$ |__            **
** $$$$  /$$$$ |  $$  $$/         $$ |      $$ |  $$ |$$ |  $$ |$$    |           **
** $$ $$ $$/$$ |   $$$$/          $$ |   __ $$ |  $$ |$$ |  $$ |$$$$$/            **
** $$ |$$$/ $$ |    $$ |          $$ \__/  |$$ \__$$ |$$ |__$$ |$$ |_____         **
** $$ | $/  $$ |    $$ |          $$    $$/ $$    $$/ $$    $$/ $$       |        **
** $$/      $$/     $$/            $$$$$$/   $$$$$$/  $$$$$$$/  $$$$$$$$/         **
**                                                                                **
************************************************************************************
***********************************************************************************/

/**********************************************************************
***********************************************************************
*                                                                     *
* wordNode                                                            *
*                                                                     *
* Description:                                                        *
*        Node structure for a linked list                             *
*                                                                     *
* Private Methods:                                                    *
*        None                                                         *
*                                                                     *
* Public Methods:                                                     *
*        wordNode                                                     *
*                                                                     *
***********************************************************************
**********************************************************************/

struct wordNode
{
    wordNode* Next;
    string word;

    wordNode()
    {
        Next = NULL;
        word = "";
    }

};


/**********************************************************************
***********************************************************************
*                                                                     *
* LINKEDLIST                                                          *
*                                                                     *
* Description:                                                        *
*        Node structure for a linked list                             *
*                                                                     *
* Private Methods:                                                    *
*        None                                                         *
*                                                                     *
* Public Methods:                                                     *
*        LINKEDLIST                                                   *
*        getSize                                                      *
*        insert                                                       *
*        print                                                        *
*                                                                     *
***********************************************************************
**********************************************************************/


class LINKEDLIST
{
    protected:
        wordNode* head;
        wordNode* tail;
        int size;


    public:

        LINKEDLIST()
        {
            head = NULL;
            tail = NULL;
            size = 0;
        }

    int getSize()
    {
        return size;
    }

    void insert(wordNode* word)
    {
        if (!head)
        {
            head = tail = word;
        }

        else
        {
            tail->Next = word;
            tail = word;
        }

        size++;
    }

    void print()
    {
        
        wordNode* current = head;
        
        // Start at head and then goto next node.
        while (current)
        {
            std::cout << current->word;   // save word in node
            std::cout << std::endl;
            current = current->Next;      // move to next node
        }
        
    }

    vs find(std::string userInput)
    {
       std::cout << "Searching for match" << std::endl;

       vs results;


       wordNode* current = head;
        
       while (current)
       {
            std::string found = "";


            found = current->word;

            int len = userInput.length();

            if (found.substr(0, len) == userInput)
            {
                results.push_back(found);
            }

            current = current->Next;
       }

        return results;
    }
};


