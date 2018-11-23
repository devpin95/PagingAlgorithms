#ifndef PAGINGALGORITHMS_LRU_H
#define PAGINGALGORITHMS_LRU_H

#include "IPaging.h"

class LRU : IPaging {
public:
    LRU( const LinkedList &s, const int &slen ) : IPaging( s, slen ) {  };
    void run();
private:
    const std::string name = "LRU";
    LinkedList registry;
};


#endif //PAGINGALGORITHMS_LRU_H
