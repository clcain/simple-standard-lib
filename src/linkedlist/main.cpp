#include <iostream>
#include "linkedlist.h"

int main()
{
    LinkedList<char> list;
    list.append('A');
    list.append('B');
    list.append('C');
    std::cout << list.toString("\n") << std::endl;
    return EXIT_SUCCESS;
}
