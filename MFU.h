#ifndef PAGINGALGORITHMS_MFU_H
#define PAGINGALGORITHMS_MFU_H

#include "IPaging.h"
#include <algorithm>

class MFU : public IPaging {
public:
    MFU( const LinkedList &s, const int &slen ) : IPaging( s, slen ) {  };
    void run();
private:
    const std::string name = "MFU";
    LinkedList registry;
};


#endif //PAGINGALGORITHMS_MFU_H
