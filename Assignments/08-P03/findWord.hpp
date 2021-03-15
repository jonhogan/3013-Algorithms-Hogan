#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>


typedef std::vector<std::string> vs;


/****************************************************************************
***************************************************************************** 
**  __       __  __      __         ______    ______   _______   ________  **
** /  \     /  |/  \    /  |       /      \  /      \ /       \ /        | **
** $$  \   /$$ |$$  \  /$$/       /$$$$$$  |/$$$$$$  |$$$$$$$  |$$$$$$$$/  **
** $$$  \ /$$$ | $$  \/$$/        $$ |  $$/ $$ |  $$ |$$ |  $$ |$$ |__     **
** $$$$  /$$$$ |  $$  $$/         $$ |      $$ |  $$ |$$ |  $$ |$$    |    **
** $$ $$ $$/$$ |   $$$$/          $$ |   __ $$ |  $$ |$$ |  $$ |$$$$$/     **
** $$ |$$$/ $$ |    $$ |          $$ \__/  |$$ \__$$ |$$ |__$$ |$$ |_____  **
** $$ | $/  $$ |    $$ |          $$    $$/ $$    $$/ $$    $$/ $$       | **
** $$/      $$/     $$/            $$$$$$/   $$$$$$/  $$$$$$$/  $$$$$$$$/  **
**                                                                         **
*****************************************************************************
****************************************************************************/

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
    wordNode* lChild;
    wordNode* rChild;
    std::string word;
    std::string def;

    wordNode(std::string w, std::string d)
    {
        lChild = NULL;
        rChild = NULL;
        word = w;
        def = d;
    }

};


/**********************************************************************
***********************************************************************
*                                                                     *
* WordTree                                                            *
*                                                                     *
* Description:                                                        *
*        Node structure for a linked list                             *
*                                                                     *
* Private Methods:                                                    *
*        None                                                         *
*                                                                     *
* Public Methods:                                                     *
*        WordTree                                                     *
*        getSize                                                      *
*        insert                                                       *
*        print                                                        *
*                                                                     *
***********************************************************************
**********************************************************************/


class WordTree
{
    protected:
        wordNode* m_rChild;
        wordNode* m_lChild;
        //int size;


    public:

    /**********************************************************************
    *                                                                     *
    * WordTree                                                            *
    *                                                                     *
    * Description:                                                        *
    *        Default Constructor                                          *
    *        Node structure for a linked list, created using our struct   *
    *                                                                     *
    * Method Variables:                                                   *
    *        lChild                                                       *
    *        m_rChild                                                     *
    *        size                                                         *
    *                                                                     *
    * Use:                                                                *
    *   Create a linked list within our class                             *
    *                                                                     *
    **********************************************************************/

        WordTree()
        {
            m_lChild = NULL;
            m_rChild = NULL;
            //size = 0;
        }

        /*******************************************************************
        *                                                                  *
        * print                                                            *
        *                                                                  *
        * Description:                                                     *
        *        Prints the BST                                            *
        *                                                                  *
        * Method Variables:                                                *
        *        None                                                      *
        *                                                                  *
        * Return:                                                          *
        *   NULL                                                           *
        *                                                                  *
        *******************************************************************/
/*
        void print()
        {
        
            wordNode* current = m_lChild;
        
            while (current)
            {
                std::cout << current->word;   
                std::cout << std::endl;
                current = current->Next;      
            }
        
        }
*/
        /*******************************************************************
        *                                                                  *
        * getSize                                                          *
        *                                                                  *
        * Description:                                                     *
        *        Gets the size of the linked list                          *
        *                                                                  *
        * Method Variables:                                                *
        *        None                                                      *
        *                                                                  *
        * Return:                                                          *
        *   size                                                           *
        *                                                                  *
        *******************************************************************/
/*
        int getSize()
        {
            return size;
        }
*/
        /*******************************************************************
        *                                                                  *
        * insert                                                           *
        *                                                                  *
        * Description:                                                     *
        *        Adds a word to the linked list                            *
        *                                                                  *
        * Method Variables:                                                *
        *        None                                                      *
        *                                                                  *
        * Return:                                                          *
        *   NULL                                                           *
        *                                                                  *
        *******************************************************************/
/*
        void insert(wordNode* word)
        {
            if (!m_lChild)
            {
                m_lChild = m_rChild = word;
            }else
            {
                m_rChild->Next = word;
                m_rChild = word;
            }

            size++;
        }
*/
        /*******************************************************************
        *                                                                  *
        * search                                                           *
        *                                                                  *
        * Description:                                                     *
        *        searches through the liked list to find a matching word   *
        *                                                                  *
        * Method Variables:                                                *
        *        vector <string> (vs) results                              *
        *                                                                  *
        * Return:                                                          *
        *   vector <string> (vs) results                                   *
        *                                                                  *
        *******************************************************************/
/*
        vs search(std::string userInput)
        {
            std::cout << "Searching for match" << std::endl;

           vs results;


           wordNode* current = m_lChild;
        
            while (current)
                {
                    std::string found = "";

                   found = current->word;

                    int length = userInput.length();

                    if (found.substr(0, length) == userInput)
                    {
                        results.push_back(found);
                    }

                    current = current->Next;
                }

            return results;
        }*/
};