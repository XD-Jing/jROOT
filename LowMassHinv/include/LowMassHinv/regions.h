#ifndef REGIONS_H
#define REGIONS_H

namespace RG_emuMC{
    enum{
        _NONE = 0,
        _EE = 1,
        _MM = 2,
        _EM = 3,
    };
}

namespace RG_emuCR{
    enum{
        _NONE = 0,
        _ONSHELL_EE = 1,
        _ONSHELL_MM = 2,
        _ONSHELL_EM = 3,
        _GGF_EE = 4,
        _GGF_MM = 5,
        _GGF_EM = 6,
        _JET_EE = 7,
        _JET_MM = 8,
        _JET_EM = 9,
        _VBF_EE = 10,
        _VBF_MM = 11,
        _VBF_EM = 12,
    };
}

namespace RG_HinvComb{
    enum{
        _NONE = 0,
        _SR     = 1,
        _3CR    = 2,
        _4CR    = 3,
        _emuCR  = 4,
        _ZjetCR = 5,
    };
}
#endif
