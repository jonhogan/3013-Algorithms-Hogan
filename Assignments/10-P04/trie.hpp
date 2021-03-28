#pragma once
#include <iostream>
#include <string>
#include <vector>

// Defining the character size of 26 for the alphabet
#define CHAR_SIZE 26


/************************************************************************************
*************************************************************************************
**                                                                                 **
**    Struct Name: TrieNode                                                        **
**                                                                                 **
**    Description:                                                                 **
**        Node to hold a string from dictionary                                    **
**                                                                                 **
**    Public Methods:                                                              **
**        string word                                                              **
**        TrieNode* character                                                      **
**        bool isLeaf                                                              **
**                                                                                 **
**    Private Methods:                                                             **
**        - None                                                                   **
**                                                                                 **
**    Usage:                                                                       **
**        - Creates Trie Tree Node for a Prefix Tree                               **
**                                                                                 **
*************************************************************************************
************************************************************************************/

struct TrieNode
{
    bool isLeaf;
    string word;
    TrieNode* character[CHAR_SIZE];

    TrieNode()
    {
        isLeaf = true;
        word = "";

        for (int i = 0; i < CHAR_SIZE; i++)
        {
            this -> character[i] = NULL;
        }
    }

};


/************************************************************************************
*************************************************************************************
**                                                                                 **
**    Struct Name: TrieNode                                                        **
**                                                                                 **
**    Description:                                                                 **
**        Node to hold a string from dictionary                                    **
**                                                                                 **
**    Public Methods:                                                              **
**        string word                                                              **
**        TrieNode* character                                                      **
**        bool isLeaf                                                              **
**                                                                                 **
**    Private Methods:                                                             **
**        None                                                                     **
**                                                                                 **
**    Usage:                                                                       **
**        Creates TrieTree Node for the TrieTree                                   **
**                                                                                 **
*************************************************************************************
************************************************************************************/

class TrieTree
{
protected:
    TrieNode* m_root;
    std::vector<std::string> m_results;

    /********************************************************************************
    *                                                                               * 
    *   Protected :                                                                 *
    *       Find(TrieNode* &m_current, string t_data)                               *
    *                                                                               *
    *   Description:                                                                *
    *       Receives t_data data from the user and checks it against the dictionary *
    *       of words for matches.                                                   *
    *                                                                               *
    *   Params:                                                                     *
    *       TrieNode* &m_current                                                    *
    *       string t_data                                                           *
    *                                                                               *
    *   Returns:                                                                    *
    *       void                                                                    *
    *                                                                               *
    ********************************************************************************/

    void Find(TrieNode* &m_current, std::string t_data)
    {
        if (m_current -> isLeaf)
        {
            m_results.push_back(t_data);
        }

        for (int i = 0; i < 26; i++)
        {
            if (m_current -> character[i])
            {
                Find(m_current -> character[i], t_data + char(i + 65));
            }
        }
    }

public:

    /********************************************************************************
    *                                                                               *
    *    Constructor :                                                              *
    *        TrieTree                                                               *
    *                                                                               *
    *    Description:                                                               *
    *        Allocates a TrieNode for the TrieTree                                  *
    *                                                                               *
    ********************************************************************************/

    TrieTree()
    {
        m_root = new TrieNode;
    }


    /********************************************************************************
    *                                                                               *
    *   Public:                                                                     *
    *       insert(string t_data)                                                   *
    *                                                                               *
    *   Description:                                                                *
    *       Receives a string from the vector dictionary of words from main.        *
    *       Each word is attached to a newly allocated TrieNode and is then         *
    *       inserted into the TrieTree.                                             *
    *                                                                               *
    *   Params:                                                                     *
    *       string t_data                                                           *
    *                                                                               *
    *   Returns:                                                                    *
    *       void                                                                    *
    *                                                                               *
    ********************************************************************************/

    void insert(std::string t_word)
    {
        TrieNode* m_current = m_root;

        for (int i = 0; i < t_word.size(); i++)
        {
            if (m_current -> character[t_word[i] - 65] == NULL)
            {
                m_current -> character[t_word[i] - 65] = new TrieNode();
            }

            m_current = m_current -> character[t_word[i] - 65];
        }

        m_current -> isLeaf = true;
    }


    /********************************************************************************
    *                                                                               *
    *   Public : Find(string t_data)                                                *
    *                                                                               *
    *   Description:                                                                *
    *       Receives the t_data or getched data from the user and compares it to    *
    *       the dictionary data to find matches. Calls the private/protected        *
    *                                                                               *
    *       Find method.                                                            *
    *   Params:                                                                     *
    *       string t_data                                                           *
    *                                                                               *
    *   Returns:                                                                    *
    *       vector<string> m_results                                                *
    *                                                                               *
    ********************************************************************************/

    std::vector<std::string> find(string t_data)
    {
        TrieNode* m_current = m_root;

        if (m_results.size() != 0)
        {
            m_results.clear();
        }

        for (int i = 0; i < t_data.length(); i++)
        {
            m_current = m_current -> character[t_data[i] - 65];
        }

        Find(m_current, t_data);
        return m_results;
    }

};