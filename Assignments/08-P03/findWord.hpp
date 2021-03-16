#pragma once
#include <fstream>
#include <iostream>
#include <string>


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
*        wordNode structure to hold a word, and definition            *
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
    std::string definition;
    wordNode* left;
    wordNode* right;

    wordNode()
    {
        word = "";
        definition = "";
        left = right = NULL;
    }

    wordNode(std::string w, std::string d)
    {
        word = w;
        definition = d;
        left = right = NULL;
    }

};


/**********************************************************************
***********************************************************************
*                                                                     *
* WordTree                                                            *
*                                                                     *
* Description:                                                        *
*        Binary tree using a linked list                              *
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
    private:
        wordNode* m_root;
        int m_size;
        void Print(wordNode*);

        void Insert(wordNode* &m_root, std::string w, std::string d)
        {
            bool didInsert = false;
            
            if(!m_root)
            {
                m_root = new wordNode(w, d);
            }else
            {
                if (m_root -> word[0] == w[0])
                {
                    for (int i = 0; i < m_root -> word.size();i++)
                    {
                        if (m_root -> word[i] > w[i])
                        {
                            Insert(m_root -> left, w, d);
                            didInsert = true;

                        }else if (m_root -> word[i] < w[i])
                        {
                            Insert(m_root -> right, w, d);
                            didInsert = true;
                        }
                    }
                    if (!didInsert)
                    {
                        Insert(m_root -> right, w, d);
                    }
                    
                }else if (m_root -> word[0] > w[0])
                {
                    Insert(m_root -> left, w, d);
                }else
                {
                    Insert(m_root -> right, w, d);
                }
            }
        }
        bool Find(wordNode*,int);
        int Height(wordNode*);
        int NumChildren(wordNode*);
        
    public:
        WordTree()
        {
            m_size = 0;
            m_root = NULL;
        }

        /*WordTree(std::string *w, std::string *d)
        {

        }*/

        void Insert(std::string w, std::string d)
        {
            if(!m_root)
            {
                wordNode* temp = new wordNode(w, d);
                m_root = temp;
            }else
            {
                Insert(m_root, w, d);
            }
        }
        void Print();
        bool Find(int);
        void Delete();
        int Height();
        
        /**************************************************************
        *                                                             *
        * WordTree                                                    *
        *                                                             *
        * Description:                                                *
        *        Default Constructor                                  *
        *        Array based binary tree                              *
        *                                                             *
        * Method Variables:                                           *
        *        m_currentSize                                        *
        *        m_dictionary                                         *
        *        m_ratio                                              *
        *                                                             *
        * Use:                                                        *
        *   Create an array based binary tree                         *
        *                                                             *
        **************************************************************/

        WordTree()
        {
          m_currentSize = 10;
          m_dictionary = new wordNode[m_currentSize];
          m_ratio = 1;
        }


        /**************************************************************
        * GrowTree                                                    *
        *                                                             *
        * Description:                                                *
        *         If the binary tree is full, grow it                 *
        *                                                             *
        * Params:                                                     *
        *         NULL                                                *
        *                                                             *
        * Returns:                                                    *
        *         NULL                                                *
        **************************************************************/

        void GrowTree()
        {
            int growSize = m_currentSize * 2;  // Double the size of the stack
            wordNode* B = new wordNode[growSize];      // New memory

            for (int i = 0; i < m_currentSize; i++) // Copy data to new stack
            {
                B[i] = m_dictionary[i];
            }

            m_currentSize = growSize;          // Set current size to the new size
            delete[] m_dictionary;             // Delete old array
            m_dictionary = B;                           // Reset the pointer
            delete[] B;
        }

        /**************************************************************
        *                                                             *
        * print                                                       *
        *                                                             *
        * Description:                                                *
        *        Prints the WordTree                                  *
        *                                                             *
        * Method Variables:                                           *
        *        None                                                 *
        *                                                             *
        * Return:                                                     *
        *   NULL                                                      *
        *                                                             *
        **************************************************************/
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
        /**************************************************************
        *                                                             *
        * getSize                                                     *
        *                                                             *
        * Description:                                                *
        *        Gets the size of the linked list                     *
        *                                                             *
        * Method Variables:                                           *
        *        None                                                 *
        *                                                             *
        * Return:                                                     *
        *   size                                                      *
        *                                                             *
        **************************************************************/
/*
        int getSize()
        {
            return size;
        }
*/
        /**************************************************************
        *                                                             *
        * insert                                                      *
        *                                                             *
        * Description:                                                *
        *        Adds a word to the linked list                       *
        *                                                             *
        * Method Variables:                                           *
        *        None                                                 *
        *                                                             *
        * Return:                                                     *
        *   NULL                                                      *
        *                                                             *
        **************************************************************/
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
        /**************************************************************
        *                                                             *
        * search                                                      *
        *                                                             *
        * Description:                                                *
        *        searches through the liked list to find a matching   * 
        *        word                                                 *
        *                                                             *
        * Method Variables:                                           *
        *        vector <string> (vs) results                         *
        *                                                             *
        * Return:                                                     *
        *   vector <string> (vs) results                              *
        *                                                             *
        **************************************************************/
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