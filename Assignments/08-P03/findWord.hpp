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
    std::string word;
    std::string def;

    wordNode()
    {
        word = "";
        def = "";
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
        wordNode* m_dictionary;
        int m_currentSize;
        float m_ratio;

    public:

        /**********************************************************************
        *                                                                     *
        * WordTree                                                            *
        *                                                                     *
        * Description:                                                        *
        *        Default Constructor                                          *
        *        Array based binary tree                                      *
        *                                                                     *
        * Method Variables:                                                   *
        *        m_currentSize                                                *
        *        m_dictionary                                                 *
        *        m_ratio                                                      *
        *                                                                     *
        * Use:                                                                *
        *   Create an array based binary tree                                 *
        *                                                                     *
        **********************************************************************/

        WordTree()
        {
          m_currentSize = 10;
          m_dictionary = new wordNode[m_currentSize];
          m_ratio = 1;
        }


        /**********************************************************************
        * GrowTree                                                            *
        *                                                                     *
        * Description:                                                        *
        *         If the binary tree is full, grow it                         *
        *                                                                     *
        * Params:                                                             *
        *         NULL                                                        *
        *                                                                     *
        * Returns:                                                            *
        *         NULL                                                        *
        **********************************************************************/

        void GrowTree()
        {
            int growSize = m_currentSize * 2;  // Double the size of the stack
            wordNode* B = new wordNode[growSize];      // New memory

            for (int i = 0; i < m_currentSize; i++) // Copy data to new stack
            {
                B[i] = m_dictionary[i];
            }

            m_currentSize = growSize;          // Set current size to the new size
            delete[] m_dictionary;                      // Delete old array
            m_dictionary = B;                           // Reset the pointer
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
        }
    */
};