## Program 4 - Processing in Trie Tree Time

### Loic Konan

#### Description

- This program will read in a dictionary file and store it in a Trie Tree.

  - Suggestions will start after **_1 character_** is typed.
  - Only the top **_10 suggestions_** will be printed along with the total number of matching words.
  - Matching suggestions will ONLY be words that match the **substring** starting from **_position zero_**.
  - As typing, the time it takes to find suggestions will be displayed in **_seconds_** with some **_color effects_**.

- We are doing this with the knowledge that this is slow, and we plan on applying our "lookup" code <br>
  to other backend data structures with better performance.

### Files

|  #  | File                           | Description                              |
| :-: | ------------------------------ | ---------------------------------------- |
|  1  | [main.cpp](main.cpp)           | The main cpp file.                       |
|  2  | [Banner](Banner)               | Assignment Banner                    |
|  3  | [timer.hpp](timer.hpp)         | Timer helper class                       |
|  4  | [getch.hpp](getch.hpp)         | Get character, without printing it .     |
|  5  | [Dictionary](dictionary.txt)   | List of words, and some I'm not sure a really words|
|  6  | [termcolor.hpp](termcolor.hpp) | Class to color text                      |
|  7  |[Replit to P04](https://replit.com/@JonHogan/P04#trie.hpp)| Replit link to project|

### Instructions

- $ ./main.cpp
- $ ./dictionary.txt
- $  Z to terminate the program.
  
