#ifndef VBSZZ_REGIONS_H
#define VBSZZ_REGIONS_H


namespace RG{
    enum{
        _NONE = 0,
        _2lFV = 1, // 2 lepton FV
        _3MMM = 2,
        _3MME = 3,
        _3EEE = 4,
        _3EEM = 5,
        _emCR = 6,
        _2JET = 7,
        _2lVR = 8,
        _2lSR = 9
    };
}

namespace YEAR{
    enum{
        NONE = -1,
        MC16A = 0,
        MC16D = 1,
        MC16E = 2
    };
}

#endif
