# Project 1 README

Student 1: ZongYuan Wei(919597167)



## Project Status
Done

## Known Issues
N/A. The project can function properly

## Code References
* [looking for the explanation of the Edit distance algorithm(learnt the way of using matrix struture to calculate the distancce)](https://github.com/guilhermeagostinelli/levenshtein)
* [looking for the overall summary video to the Edit distance algorithm in Chinese(to get an insight of the algorithm after reading wikipedia)](https://b23.tv/CNN2Mc2)

## Generative AI Use
I asked ChatGPT for the structure of vector, and how to put element into the vector.

### Prompt 1
what is the structure of vector, and how to put element into the vector in c++?

### Response 1
In C++, a vector is a dynamic array-like data structure that can dynamically resize itself to accommodate the number of elements it holds. 
It is part of the Standard Template Library (STL) and is defined in the <vector> header. 
The structure of a vector includes information about its size, capacity, and a pointer to the dynamically allocated array that holds the elements.
push_back: Adds an element to the end of the vector.
code:
#include <vector>
#include <iostream>

int main() {
    std::vector<int> myVector;

    // Put elements into the vector using push_back
    myVector.push_back(1);
    myVector.push_back(2);
    myVector.push_back(3);

    // Print elements
    for (int element : myVector) {
        std::cout << element << " ";
    }

    return 0;
}
### Chagnes 1
I learnt the structure of vector and the use of push_back. Then, I include the push_back method in my code to push in elements.


