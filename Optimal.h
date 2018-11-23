#ifndef PAGINGALGORITHMS_OPTIMAL_H
#define PAGINGALGORITHMS_OPTIMAL_H

#include "LinkedList.h"
#include "IPaging.h"

class Optimal : public IPaging {
public:
    Optimal( const LinkedList &s, const int &slen ) : IPaging( s, slen ) {
//        for ( int i = 0; i < slen; ++i ) {
//            registry.insertAtFront( INT32_MAX );
//        }
    };
    void run();
private:
    const std::string name = "Optimal";
    LinkedList registry;
};


#endif //PAGINGALGORITHMS_OPTIMAL_H
