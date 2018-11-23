#include "MFU.h"

void MFU::run() {
    bool already_in_memory = false;

    for ( const int page : pages ) {
        ++step;

        //std::cout << step << "(" << page << ")[" << frames.length() << "] ------ ";

        //int pos = 0;
        auto frameptr = frames.begin();
        auto registryptr = registry.begin();

        while ( frameptr != frames.end() || registryptr != registry.end()) {
            //std::cout << (*frameptr) << "[" << (*registryptr) << "] ";
            if ( (*frameptr) == page && !already_in_memory ) {
                (*registryptr) += 1;
                already_in_memory = true;
                //break;
            }
            ++frameptr;
            ++registryptr;
            //++pos;
        }

        //std::cout << std::endl;

        if ( !already_in_memory ) {
            //std::cout << "Page Fault" << std::endl;
            if ( frames.length() == max_frames ) {
                // go through the register and find the one that was used the earliest
                int max = INT64_MIN;       // start at -1 (every frames starts at 0)
                int mfu = 0;        // the position of the most frequently used
                int pos = 0;        // position in the ll


                // step through the registry
                for ( const int &uses : registry ) {
                    //std::cout << uses << " ";
                    if ( uses > max ) {
                        max = uses;
                        mfu = pos;
                    }
                    ++pos;
                }

                //std::cout << "MFU " << mfu << std::endl;

                if ( mfu == max_frames - 1 ) {
                    frames.deleteAtBack();
                    registry.deleteAtBack();
                }
                else if ( mfu == 0 ) {
                    frames.deleteAtFront();
                    registry.deleteAtFront();
                }
                else {
                    frames.deleteBeforePosition(mfu + 1);
                    registry.deleteBeforePosition(mfu + 1);
                }
            }

            frames.insertAtBack(page);
            registry.insertAtBack( 0 );
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