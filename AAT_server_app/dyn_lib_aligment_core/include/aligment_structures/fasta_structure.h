/**
* author: Rami Mtier
* date: 10.6.2016
*/
#ifdef AAT_ALIGMENT_STRUCTURE
#define AAT_ALIGMENT_STRUCTURE
#include "aligment_structure.h"

namespace AAT
{
    class FastaStructure: public AligmentAlgorithm
    {
    public:
        void FastaStructure();

    public:
        char* sequence;
        int size_of_sequence;
    };
}

#endif
