#ifndef PAGINGALGORITHMS_FIFO_H
#define PAGINGALGORITHMS_FIFO_H

#include "IPaging.h"

class FIFO : public IPaging {
public:
    FIFO( const LinkedList &s, const int &slen ) : IPaging( s, slen ) {  };
    void run();
private:
    const std::string name = "FIFO";

};


#endif //PAGINGALGORITHMS_FIFO_H
