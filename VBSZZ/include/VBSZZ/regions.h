#ifndef REGIONS_H
#define REGIONS_H

namespace RG_3lCR{
    enum{
        _NONE = 0,
        _eeev = 3,
        _eemv = 4,
        _mmev = 2,
        _mmmv = 1,
    };
}

namespace RG_emuMC{
    enum{
        _NONE = 0,
        _EE = 1,
        _MM = 2,
        _EM = 3,
    };
}

namespace RG_CutFlow{
    enum{
        _NONE = 0,
        _Zmass_EE = 1,
        _Zmass_MM = 2,
        _Zmass_EM = 3,
        _2Jet_EE  = 4,
        _2Jet_MM  = 5,
        _2Jet_EM  = 6,
        _MET_EE   = 7,
        _MET_MM   = 8,
        _MET_EM   = 9,
        _2lSR_EE  =10,
        _2lSR_MM  =11,
        _2lCR_EE  =12,
        _2lCR_MM  =13,
        _2lCR_EM  =14,
    };
}

#endif
