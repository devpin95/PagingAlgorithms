#include "FIFO.h"

void FIFO::run() {
    bool already_in_memory = false;
    for ( const int page : pages ) {
        ++step;
//        std::cout << step << "(" << page << ")" << std::endl;
//        frames.printVals();
//        std::cout << std::endl;

        // check if page is already here
        for ( const int frame : frames ) {
            if ( page == frame ) {
                already_in_memory = true;
                break;
            }
        }

        if ( !already_in_memory ) {
            if ( frames.length() == max_frames ) {
                frames.deleteAtFront();
            }
            frames.insertAtBack(page);
            ++num_page_faults;
        }

        already_in_memory = false;

        if ( step % 2000 == 0 ) {
            std::cout << std::left << std::setw( 10 ) << std::setfill(' ') << num_page_faults / (double)step;
            //std::cout << "Page: " << step << " Faults: " << num_page_faults << " Fault Rate: " << num_page_faults / (double)step << std::endl;
            //page_fault_rates_per_2000.insertAtBack( num_page_faults / step );
        }
    }
    std::cout << std::left << std::setw( 25 ) << std::setfill(' ') << num_page_faults << std::endl;
}