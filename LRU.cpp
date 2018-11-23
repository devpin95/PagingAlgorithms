#include "LRU.h"

//void LRU::run() {
//    bool already_in_memory = false;
//
//    for ( const int &page : pages ) {
//        ++step;
//
//        int pos = 0;
//        for ( const int &frame : frames ) {
//            if ( page == frame ) {
//                //frames.deleteBeforePosition( pos + 1 );
//                if ( pos == max_frames ) {
//                    frames.deleteAtBack();
//                }
//                else if ( pos == 0 ) {
//                    frames.deleteAtFront();
//                }
//                else {
//                    frames.deleteBeforePosition(pos + 1);
//                }
//
//                frames.insertAtFront( page );
//                already_in_memory = true;
//                break;
//            }
//            ++pos;
//        }
//
//        if ( !already_in_memory ) {
//            if ( frames.length() == max_frames ) {
//                frames.deleteAtBack();
//            }
//            frames.insertAtFront(page);
//            ++num_page_faults;
//        }
//
//
//        already_in_memory = false;
//
//        if ( step % 2000 == 0 ) {
//            std::cout << "Page: " << step << " Faults: " << num_page_faults
//                      << " Fault Rate: " << num_page_faults / (double)step << std::endl;
//        }
//    }
//
//    printAlgorithmRates( name );
//}

void LRU::run() {
    bool already_in_memory = false;

    for ( const int page : pages ) {
        ++step;

        auto frameptr = frames.begin();
        auto registryptr = registry.begin();

        while ( frameptr != frames.end() || registryptr != registry.end()) {
            if ( (*frameptr) == page ) {
                (*registryptr) = step;
                already_in_memory = true;
                break;
            }
            ++frameptr;
            ++registryptr;
        }

        if ( !already_in_memory ) {
            if ( frames.length() == max_frames ) {
                // go through the register and find the one that was used the earliest
                int min = pages.length() + 1;       // start at 1 more than the size (nothing will be higher)
                int lru = -1;                       // the position of the least recently used
                int pos = 0;                        // position in the ll

                // step through the registry
                for ( const int last_used : registry ) {
                    if ( last_used < min ) {
                        min = last_used;
                        lru = pos;
                    }
                    ++pos;
                }

                if ( lru == max_frames - 1 ) {
                    frames.deleteAtBack();
                    registry.deleteAtBack();
                }
                else if ( lru == 0 ) {
                    frames.deleteAtFront();
                    registry.deleteAtFront();
                }
                else {
                    frames.deleteBeforePosition(lru + 1);
                    registry.deleteBeforePosition(lru + 1);
                }
            }
            frames.insertAtBack(page);
            registry.insertAtBack( step );
            ++num_page_faults;
        }


        already_in_memory = false;

        if ( step % 2000 == 0 ) {
            std::cout << std::left << std::setw( 10 ) << std::setfill(' ') << num_page_faults / (double)step;
//            std::cout << "Page: " << step << " Faults: " << num_page_faults
//                      << " Fault Rate: " << num_page_faults / (double)step << std::endl;
        }
    }
    std::cout << std::left << std::setw( 25 ) << std::setfill(' ') << num_page_faults << std::endl;
}