#include <iostream>
#include <fstream>
#include "LinkedList.h"

int main() {
    LinkedList sequence;

    std::string infilename = "/home/devpin/CLionProjects/PagingAlgorithms/pg-reference.txt";
    std::fstream infile;
    infile.open(infilename);

    if ( !infile ) {
        std::cout << "Could not open file " << infilename << std::endl;
    }
    else {
        int page;
        while ( !infile.eof() ) {
            infile >> page;
            sequence.insertAtBack( page );
        }

        sequence.deleteAtBack();
        sequence.printVals();
        std::cout << "Sequence length " << sequence.length();

        infile.close();
    }

    return 0;
}