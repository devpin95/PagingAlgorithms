#include <iostream>
#include <fstream>
#include <iomanip>
#include "LinkedList.h"
#include "FIFO.h"
#include "LRU.h"
#include "MFU.h"
#include "Optimal.h"


int main() {
    const char separator = ' ';
    LinkedList sequence;

    int frame_size = 128;

    std::string infilename = "/home/devpin/CLionProjects/PagingAlgorithms/pg-reference.txt";
    std::ifstream infile;
    infile.open(infilename);

    if ( !infile ) {
        std::cout << "Could not open file " << infilename << std::endl;
        return 1;
    }
    else {
        int page;
        int count = 0;
        while ( !infile.eof() ) {
            infile >> page;
            sequence.insertAtBack( page );
            ++count;
        }

        sequence.deleteAtBack();

        std::string outfilename = "/home/devpin/CLionProjects/PagingAlgorithms/results.txt";
        std::ofstream outfile;
        outfile.open(outfilename);

        if ( !outfile ) {
            std::cout << "Could not open file " << outfilename << std::endl;
            return 1;
        }

        std::cout << "Starting Simulation" << std::endl;

        std::streambuf *coutbuf = std::cout.rdbuf();
        std::streambuf *ofbuf = outfile.rdbuf();
        std::cout.rdbuf( ofbuf );

        std::cout << "==================================================================================" << std::endl;
        std::cout << "Page Replacement Algorithm Simulation (frame size: " << frame_size << ")" << std::endl;
        std::cout << "==================================================================================" << std::endl;

        std::cout << std::left << std::setw( 15 ) << std::setfill(separator) << ' ';
        std::cout << std::left << std::setw( 50 ) << std::setfill(separator)
        << "|--------------- Page Fault Rates ---------------|" << std::endl;

        std::cout << std::left << std::setw( 15 ) << std::setfill(separator) << "Algorithm";
        std::cout << std::left << std::setw( 10 ) << std::setfill(separator) << "2000";
        std::cout << std::left << std::setw( 10 ) << std::setfill(separator) << "4000";
        std::cout << std::left << std::setw( 10 ) << std::setfill(separator) << "6000";
        std::cout << std::left << std::setw( 10 ) << std::setfill(separator) << "8000";
        std::cout << std::left << std::setw( 10 ) << std::setfill(separator) << "10000";
        std::cout << std::left << std::setw( 25 ) << std::setfill(separator) << "Total Page Faults" << std::endl;

        std::cout.rdbuf( coutbuf );
        std::cout << "Working on FIFO" << std::endl;
        std::cout.rdbuf( ofbuf );

        std::cout << std::left << std::setw( 15 ) << std::setfill(separator) << "FIFO";
        FIFO fifo( sequence, frame_size );
        fifo.run();

        std::cout.rdbuf( coutbuf );
        std::cout << "Working on LRU" << std::endl;
        std::cout.rdbuf( ofbuf );

        std::cout << std::left << std::setw( 15 ) << std::setfill(separator) << "LRU";
        LRU lru( sequence, frame_size );
        lru.run();

        std::cout.rdbuf( coutbuf );
        std::cout << "Working on MFU" << std::endl;
        std::cout.rdbuf( ofbuf );

        std::cout << std::left << std::setw( 15 ) << std::setfill(separator) << "MFU";
        MFU mfu( sequence, frame_size );
        mfu.run();

        std::cout.rdbuf( coutbuf );
        std::cout << "Working on Optimal" << std::endl;
        std::cout.rdbuf( ofbuf );

        std::cout << std::left << std::setw( 15 ) << std::setfill(separator) << "Optimal";
        Optimal optimal( sequence, frame_size );
        optimal.run();

        std::cout.rdbuf(coutbuf);

        std::cout << "Simulation Complete" << std::endl;

        outfile.close();
        infile.close();
    }

    return 0;
}