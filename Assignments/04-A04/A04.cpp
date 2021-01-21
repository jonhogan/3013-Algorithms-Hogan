/*****************************************************************************
*                    
*  Author:           Jonathan Hogan
*  Email:            jon.hogan83@gmail.com
*  Label:            Commenting Code
*  Title:            (short title from assignment, if any)
*  Course:           3013-Algorithms
*  Semester:         Spring 2021
* 
*  Description:
*        Test program to work on commenting code
* 
*  Usage:
*        how to use the program if necessary
* 
*  Files:  No addition files needed for this program
*****************************************************************************/

#include <iostream>

using namespace std;

int A[100];

/*****************************************************************************
 * Struct Node
 * 
 * Description:
 *      Created a Node structure to be used in other classes
 * 
 * Public Methods:
 *      Node
 *      
 * 
 * Private Methods:
 *      
 * 
 * Usage: 
 * 
 *      Used to create a node for a linked list
 *      
 *****************************************************************************/

struct Node {
    int x;
    Node *next;
    Node() {
        x = -1;
        next = NULL;
    }
    Node(int n) {
        x = n;
        next = NULL;
    }
};

/*****************************************************************************
 * Class Lists
 * 
 * Description:
 *      Creates a linked list data type
 * 
 * Public Methods:
 *      List
 *      Push
 *      Insert
 *      PrintTail
 *      Print
 *      Pop
 * 
 * Private Methods:
 *      
 * 
 * Usage: 
 * 
 *      Used to create a node for a linked list
 *      
 *****************************************************************************/

class List {
private:
    Node *Head;
    Node *Tail;
    int Size;

public:

    /*****************************************************************************
    * Public List
    * 
    * Description:
    *      Default constructor for a List data type
    * 
    * Params:
    *      NULL
    * 
    * Returns:
    *      NULL
    *****************************************************************************/
    List() {                               
        Head = Tail = NULL;             // Set Head and Tail to NULL
        Size = 0;                       // Default Size set to 0
    }

    /*****************************************************************************
    * Public Push
    * 
    * Description:
    *      This method allows you to add new Nodes to your linked list
    * 
    * Params:
    *      int val
    * 
    * Returns:
    *      NULL
    *****************************************************************************/

    void Push(int val) {
        
        Node *Temp = new Node(val);     // allocate new memory and init node

        if (!Head && !Tail) {           // If both Head and Tail point to NULL
            Head = Tail = Temp;
        } else {
            Tail->next = Temp;          // Else Head points to data
            Tail = Temp;
        }
        Size++;                         // Increment Size of the list
    }

    /*****************************************************************************
    * Public Insert
    * 
    * Description:
    *      This method allows you to add new Nodes to your linked list in an
    *      ordered mannor
    * 
    * Params:
    *      int val
    * 
    * Returns:
    *      NULL
    *****************************************************************************/

    void Insert(int val) {
        
        Node *Temp = new Node(val);       // allocate new memory and init node

        Temp->next = Head;                // figure out where it goes in the list
        Head = Temp;
        if (!Tail) {
            Tail = Head;
        }
        Size++;
    }

    /*****************************************************************************
    * Public PrintTail
    * 
    * Description:
    *      This method allows you to Print the last item in your linked list
    * 
    * Params:
    *      NULL
    * 
    * Returns:
    *      NULL
    *****************************************************************************/

    void PrintTail() {
        cout << Tail->x << endl;
    }

    /*****************************************************************************
    * Public Print
    * 
    * Description:
    *      This method allows you to Print your linked list
    * 
    * Params:
    *      NULL
    * 
    * Returns:
    *      string list
    *****************************************************************************/

    string Print() {
        Node *Temp = Head;
        string list;

        while (Temp != NULL) {
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list;
    }

    // not implemented
    int Pop() {
        Size--;
        return 0; //
    }

    List operator+(const List &Rhs) {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node *Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }

    // Implementation of [] operator.  This function returns an
    // int value as if the list were an array.
    int operator[](int index) {
        Node *Temp = Head;

        if (index >= Size) {
            cout << "Index out of bounds, exiting";
            exit(0);
        } else {

            for (int i = 0; i < index; i++) {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }

    friend ostream &operator<<(ostream &os, List L) {
        os << L.Print();
        return os;
    }
};

int main(int argc, char **argv) {
    List L1;
    List L2;

    for (int i = 0; i < 25; i++) {
        L1.Push(i);
    }

    for (int i = 50; i < 100; i++) {
        L2.Push(i);
    }

    //cout << L1 << endl;
    L1.PrintTail();
    L2.PrintTail();

    List L3 = L1 + L2;
    cout << L3 << endl;

    cout << L3[5] << endl;
    return 0;
}