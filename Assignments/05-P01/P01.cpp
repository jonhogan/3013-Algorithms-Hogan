/**********************************************************************
*
*  Author:   Jonathan Hogan
*  Email:    jon.hogan83@gmail.com
*  Label:    P01
*  Title:    Program 01 - Array Based Stack
*  Course:   3013
*  Semester: Spring 2020
*
*  Description:
*        Overview of a class implementing an array based stack
*
*
**********************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

/**********************************************************************
* ArrayStack
*
* Description:
*        Array Based Stack
*
* Private Methods:
*        See Class below
*
* Public Methods:
*        See Main program
*
**********************************************************************/

class ArrayStack
{
private:
    int* A;           // Pointer to an array of ints
    int currentSize;  // Current size of Array
    int top;          // Top of stack
    int maxSize;      // Maximum size
    float ratio;      // Stack Size ratio
    int resizeCount;  // Resize counter


public:

    /**************************************************************
    * ArrayStack
    *
    * Description:
    *         Default constuctor of the Array Stack
    *
    * Params:
    *         NULL
    *
    * Returns:
    *         NULL
    **************************************************************/
    ArrayStack()
    {
        currentSize = 10;
        A = new int[currentSize];
        top = -1;
        maxSize = 0;
        ratio = 1;
        resizeCount = 0;
    }

    /**************************************************************
    * ArrayStack
    *
    * Description:
    *         Constuctor of the Array Stack using uder defined
    *         parameters
    *
    * Params:
    *         int currentSize
    *
    * Returns:
    *         NULL
    **************************************************************/
    ArrayStack(int s)
    {
        currentSize = s;
        A = new int[currentSize];
        top = -1;
        maxSize = 0;
        ratio = 1;
        resizeCount = 0;
    }

    /**************************************************************
    * Public FullStack
    *
    * Description:
    *         Determines if the stack is full
    *
    * Params:
    *         NULL
    *
    * Returns:
    *         [bool]: True for full, false if not
    **************************************************************/
    bool FullStack()
    {
        return (top == (currentSize - 1));
    }

    /**************************************************************
    * Public bool Empty
    *
    * Description:
    *         Check if stack is empty
    *
    * Params:
    *         NULL
    *
    * Returns:
    *         [bool] true = empty
    **************************************************************/
    bool Empty()
    {
        return (top <= -1);
    }

    /**************************************************************
   * Public int GetSize
   *
   * Description:
   *         Returns Current Size of the stack
   *
   * Params:
   *         NULL
   *
   * Returns:
   *         currentSize
   **************************************************************/
    int GetSize()
    {
        return currentSize;
    }

    /**************************************************************
   * Public int GetMaxSize
   *
   * Description:
   *         Returns Max Size of the stack
   *
   * Params:
   *         NULL
   *
   * Returns:
   *         maxSize
   **************************************************************/
    int GetMaxSize()
    {
        return maxSize;
    }

    /**************************************************************
    * Public int GetResize
    *
    * Description:
    *         Returns Resize Count of the stack
    *
    * Params:
    *         NULL
    *
    * Returns:
    *         resizeCount
    **************************************************************/
    int GetResize()
    {
        return resizeCount;
    }

    /**************************************************************
    * Public int GetResize
    *
    * Description:
    *         Returns ratio how full the stack is
    *
    * Params:
    *         NULL
    *
    * Returns:
    *         ratio
    **************************************************************/
    float GetRatio(int top, int size)
    {
        float t = top;
        float s = size;
        ratio = t / s;
        return ratio;
    }

    /**************************************************************
    * Public GrowStack
    *
    * Description:
    *         If the Stack is full, increas the size
    *
    * Params:
    *         NULL
    *
    * Returns:
    *         NULL
    **************************************************************/
    void GrowStack()
    {
        cout << "Increasing the size of the Stack" << endl;
        int growSize = currentSize * 2;  // Double the size of the stack
        int* B = new int[growSize];      // New memory

        for (int i = 0; i < currentSize; i++) // Copy data to new stack
        {
            B[i] = A[i];
        }

        currentSize = growSize;          // Set current size to the new size
        delete[] A;                      // Delete old array
        A = B;                           // Reset the pointer
        resizeCount++;
    }

    /**************************************************************
    * Public ShrinkStack
    *
    * Description:
    *         If the Stack is mostly empty, decrease the size
    *
    * Params:
    *         NULL
    *
    * Returns:
    *         NULL
    **************************************************************/
    void ShrinkStack()
    {
        cout << "Decreasing the size of the Stack" << endl;
        int shrinkSize = currentSize / 2;  // Halve the size of the stack

        if (shrinkSize >= 10)
        {
            int* B = new int[shrinkSize];      // New memory

            for (int i = 0; i < shrinkSize; i++) // Copy data to new stack
            {
                B[i] = A[i];
            }

            currentSize = shrinkSize;          // Set current size to the new size
            delete[] A;                        // Delete old array
            A = B;                             // Reset the pointer
            resizeCount++;
        }
    }


    /**************************************************************
    * Public Push
    *
    * Description:
    *         Add integers to the stack
    *
    * Params:
    *         [int]: Data to add
    *
    * Returns:
    *         Null
    **************************************************************/
    void Push(int x)
    {
        if (FullStack())             // Increase stack size if full
        {
            GrowStack();
        }

        if (currentSize > maxSize)
        {
            maxSize = currentSize;
        }

        A[++top] = x;
    }

    /**************************************************************
    * Public int: Pop
    *
    * Description:
    *         Returns top value and removes it from stack
    *
    * Params:
    *        currentRatio
    *
    * Returns:
    *         [int] top value if any
    **************************************************************/
    int Pop()
    {
        float currentRatio = GetRatio(top, currentSize);

        if (!Empty())
        {
            if (currentSize > 10 && currentRatio < .15)
            {
                ShrinkStack();
            }
            return A[top--];
        }

        cout << "Stack is Empty" << endl;
        return -99;
    }

    /**************************************************************
    * Public void: Print
    *
    * Descriptions:
    *         Prints out the stack
    * Params:
    *         NULL
    * Returns:
    *         NULL
    **************************************************************/
    void Print()
    {
        int counter = 0;
        for (int i = 0; i < top; i++)
        {
            cout << A[i] << " ";
            counter++;
        }
        cout << A[counter] << endl;
    }

};


int main() {
    ArrayStack Stack;                       // Declairing an instance of ArrayStack
    ifstream fin;
    ofstream fout;
    int temp;

    // Test files

    //fin.open("nums.dat");
    //fin.open("nums_test.dat");
    fin.open("nums_test2.dat");



    // outfile destination
    fout.open("Stack_results_Hogan.txt");


    while (!fin.eof())
    {
        fin >> temp;

        if (temp % 2 == 0)                  // Push if Even
        {
            Stack.Push(temp);
        }
        else                                // Pop if Odd
        {
            Stack.Pop();
        }

    }

    fout << "----------------------------------------------------------------------\n"
        << "Program 1 - Resizing the Stack\n"
        << "CMPS 3013\n" << endl
        << "Jonasthan Hogan\n\n"
        << "======================================================================\n";

    fout << setw(4) << "" << "Max Stack Size: " << Stack.GetMaxSize() << endl
        << setw(4) << "" << "End Stack Size: " << Stack.GetSize() << endl
        << setw(4) << "" << "Stack Resized: " << Stack.GetResize() << " times\n\n"
        << "======================================================================" << endl;

    fin.close();                            // close the files
    fout.close();

    return 0;
}