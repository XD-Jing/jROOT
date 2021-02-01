#ifndef REGIONS_H
#define REGIONS_H

namespace RG_VBS{
    enum{
        _none = 0,
        _2lVR_eevv = 9,
        _2lVR_mmvv = 8,
        _2lSR_eevv = 7,
        _2lSR_mmvv = 6,
        _2lCR_emvv = 5,
        _3lCR_eemv = 4,
        _3lCR_eeev = 3,
        _3lCR_mmev = 2,
        _3lCR_mmmv = 1,
    };
}

namespace RG_3lCR{
    enum{
        _NONE = 0,
        _eemv = 4,
        _eeev = 3,
        _mmev = 2,
        _mmmv = 1,
    };
}

namespace RG_2lXR{
    enum{
        _NONE = 0,
        _eevv = 3,
        _mmvv = 2,
        _emvv = 1,
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
