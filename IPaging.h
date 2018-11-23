#ifndef PAGINGALGORITHMS_IPAGING_H
#define PAGINGALGORITHMS_IPAGING_H

#include <iostream>
#include <string>
#include <iomanip>
#include "LinkedList.h"

class IPaging {

protected:
    LinkedList pages;                // the linked list holding the pages
    LinkedList frames;                  // linked list holding the used frames
    int max_frames = 0;
    int step = 0;                       // a counter of which page we are at
    int num_page_faults = 0;                 // the total number of page faults
    int sequence_len = 0;               // the length of the pages
    //LinkedList page_fault_rates_per_2000;     // an array of the page fault rates every 2000 pages

public:
    IPaging( const LinkedList &s, const int &nframes ) {
        max_frames = nframes;
        pages = s;
        sequence_len = pages.length();
    };

    virtual void run() = 0;
    void printAlgorithmRates( const std::string &name ) {};
};

#endif //PAGINGALGORITHMS_IPAGING_H
