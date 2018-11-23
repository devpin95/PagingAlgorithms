#include "Optimal.h"

void Optimal::run() {
    bool already_in_memory = false;
    auto pageptr = pages.begin();

    for ( const int &page : pages )
    {
        ++step;

        for ( const int &frame : frames )
        {
            if ( page == frame ) {
                already_in_memory = true;
                break;
            }
        }

        if ( !already_in_memory )
        {
            if ( frames.length() == max_frames ) {
                auto frame = frames.begin();
                auto reg = registry.begin();

                while ( frame != frames.end() || reg != registry.end() )
                {
                    int runner = step + 1;
                    auto temp_page = pageptr;
                    ++temp_page;

                    while ( temp_page != pages.end() ) {
                        if ( *temp_page == *frame ) {
                            *reg = runner;
                            break;
                        }
                        ++runner;
                        ++temp_page;
                    }

                    ++frame;
                    ++reg;
                }

                int max = INT32_MIN;       // start at -1 (every frames starts at 0)
                int lnu = 0;        // the position of the most frequently used
                int pos = 0;        // position in the ll
                for ( int &next_use : registry ) {
                    if ( next_use > max ) {
                        max = next_use;
                        lnu = pos;
                    }
                    next_use = INT32_MAX;
                    ++pos;
                }

                if ( lnu == max_frames - 1 ) {
                    frames.deleteAtBack();
                    registry.deleteAtBack();
                }
                else if ( lnu == 0 ) {
                    frames.deleteAtFront();
                    registry.deleteAtFront();
                }
                else {
                    frames.deleteBeforePosition(lnu + 1);
                    registry.deleteBeforePosition(lnu + 1);
                }
            }

            ++num_page_faults;
            frames.insertAtBack( page );
            registry.insertAtBack( INT32_MAX );
        }

        already_in_memory = false;
        ++pageptr;

        if ( step % 2000 == 0 ) {
            std::cout << std::left << std::setw( 10 ) << std::setfill(' ') << num_page_faults / (double)step;
//            std::cout << "Page: " << step << " Faults: " << num_page_faults
//                      << " Fault Rate: " << num_page_faults / (double)step << std::endl;
        }
    }

    std::cout << std::left << std::setw( 25 ) << std::setfill(' ') << num_page_faults << std::endl;
}