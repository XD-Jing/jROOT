#!/usr/bin/env python3

from rootpy.io import root_open


class Systematic(object):
    def __init__(self, name, upname=None, dnname=None):
        self.name = name
        self.upname = upname
        self.dnname = dnname
        self.up = 0
        self.down = 0
        self.upentries = 0
        self.downentries = 0


def process(filename):
    sList = [
            Systematic(name='EG_RESOLUTION_ALL',upname='EG_RESOLUTION_ALL__1down',dnname='EG_RESOLUTION_ALL__1up'),
            Systematic(name='EG_SCALE_AF2',upname='EG_SCALE_AF2__1down',dnname='EG_SCALE_AF2__1up'),
            Systematic(name='EG_SCALE_ALL',upname='EG_SCALE_ALL__1down',dnname='EG_SCALE_ALL__1up'),
            Systematic(name='JET_BJES_Response',upname='JET_BJES_Response__1down',dnname='JET_BJES_Response__1up'),
            Systematic(name='JET_EffectiveNP_1',upname='JET_EffectiveNP_1__1down',dnname='JET_EffectiveNP_1__1up'),
            Systematic(name='JET_EffectiveNP_2',upname='JET_EffectiveNP_2__1down',dnname='JET_EffectiveNP_2__1up'),
            Systematic(name='JET_EffectiveNP_3',upname='JET_EffectiveNP_3__1down',dnname='JET_EffectiveNP_3__1up'),
            Systematic(name='JET_EffectiveNP_4',upname='JET_EffectiveNP_4__1down',dnname='JET_EffectiveNP_4__1up'),
            Systematic(name='JET_EffectiveNP_5',upname='JET_EffectiveNP_5__1down',dnname='JET_EffectiveNP_5__1up'),
            Systematic(name='JET_EffectiveNP_6',upname='JET_EffectiveNP_6__1down',dnname='JET_EffectiveNP_6__1up'),
            Systematic(name='JET_EffectiveNP_7',upname='JET_EffectiveNP_7__1down',dnname='JET_EffectiveNP_7__1up'),
            Systematic(name='JET_EffectiveNP_8restTerm',upname='JET_EffectiveNP_8restTerm__1down',dnname='JET_EffectiveNP_8restTerm__1up'),
            Systematic(name='JET_EtaIntercalibration_Modelling',upname='JET_EtaIntercalibration_Modelling__1down',dnname='JET_EtaIntercalibration_Modelling__1up'),
            Systematic(name='JET_EtaIntercalibration_NonClosure_highE',upname='JET_EtaIntercalibration_NonClosure_highE__1down',dnname='JET_EtaIntercalibration_NonClosure_highE__1up'),
            Systematic(name='JET_EtaIntercalibration_NonClosure_negEta',upname='JET_EtaIntercalibration_NonClosure_negEta__1down',dnname='JET_EtaIntercalibration_NonClosure_negEta__1up'),
            Systematic(name='JET_EtaIntercalibration_NonClosure_posEta',upname='JET_EtaIntercalibration_NonClosure_posEta__1down',dnname='JET_EtaIntercalibration_NonClosure_posEta__1up'),
            Systematic(name='JET_EtaIntercalibration_TotalStat',upname='JET_EtaIntercalibration_TotalStat__1down',dnname='JET_EtaIntercalibration_TotalStat__1up'),
            Systematic(name='JET_Flavor_Composition',upname='JET_Flavor_Composition__1down',dnname='JET_Flavor_Composition__1up'),
            Systematic(name='JET_Flavor_Response',upname='JET_Flavor_Response__1down',dnname='JET_Flavor_Response__1up'),
            Systematic(name='JET_JER_DataVsMC_MC16',upname='JET_JER_DataVsMC_MC16__1down',dnname='JET_JER_DataVsMC_MC16__1up'),
            Systematic(name='JET_JER_EffectiveNP_1',upname='JET_JER_EffectiveNP_1__1down',dnname='JET_JER_EffectiveNP_1__1up'),
            Systematic(name='JET_JER_EffectiveNP_2',upname='JET_JER_EffectiveNP_2__1down',dnname='JET_JER_EffectiveNP_2__1up'),
            Systematic(name='JET_JER_EffectiveNP_3',upname='JET_JER_EffectiveNP_3__1down',dnname='JET_JER_EffectiveNP_3__1up'),
            Systematic(name='JET_JER_EffectiveNP_4',upname='JET_JER_EffectiveNP_4__1down',dnname='JET_JER_EffectiveNP_4__1up'),
            Systematic(name='JET_JER_EffectiveNP_5',upname='JET_JER_EffectiveNP_5__1down',dnname='JET_JER_EffectiveNP_5__1up'),
            Systematic(name='JET_JER_EffectiveNP_6',upname='JET_JER_EffectiveNP_6__1down',dnname='JET_JER_EffectiveNP_6__1up'),
            Systematic(name='JET_JER_EffectiveNP_7restTerm',upname='JET_JER_EffectiveNP_7restTerm__1down',dnname='JET_JER_EffectiveNP_7restTerm__1up'),
            Systematic(name='JET_Pileup_OffsetMu',upname='JET_Pileup_OffsetMu__1down',dnname='JET_Pileup_OffsetMu__1up'),
            Systematic(name='JET_Pileup_OffsetNPV',upname='JET_Pileup_OffsetNPV__1down',dnname='JET_Pileup_OffsetNPV__1up'),
            Systematic(name='JET_Pileup_PtTerm',upname='JET_Pileup_PtTerm__1down',dnname='JET_Pileup_PtTerm__1up'),
            Systematic(name='JET_Pileup_RhoTopology',upname='JET_Pileup_RhoTopology__1down',dnname='JET_Pileup_RhoTopology__1up'),
            Systematic(name='JET_PunchThrough_MC16',upname='JET_PunchThrough_MC16__1down',dnname='JET_PunchThrough_MC16__1up'),
            Systematic(name='JET_SingleParticle_HighPt',upname='JET_SingleParticle_HighPt__1down',dnname='JET_SingleParticle_HighPt__1up'),
            Systematic(name='MET_SoftTrk_ResoPara',upname='MET_SoftTrk_ResoPara'),
            Systematic(name='MET_SoftTrk_ResoPerp',upname='MET_SoftTrk_ResoPerp'),
            Systematic(name='MET_SoftTrk_Scale',upname='MET_SoftTrk_ScaleDown',dnname='MET_SoftTrk_ScaleUp'),
            Systematic(name='MUON_ID',upname='MUON_ID__1down',dnname='MUON_ID__1up'),
            Systematic(name='MUON_MS',upname='MUON_MS__1down',dnname='MUON_MS__1up'),
            Systematic(name='MUON_SAGITTA_RESBIAS',upname='MUON_SAGITTA_RESBIAS__1down',dnname='MUON_SAGITTA_RESBIAS__1up'),
            Systematic(name='MUON_SAGITTA_RHO',upname='MUON_SAGITTA_RHO__1down',dnname='MUON_SAGITTA_RHO__1up'),
            Systematic(name='MUON_SCALE',upname='MUON_SCALE__1down',dnname='MUON_SCALE__1up'),
            Systematic(name='EL_EFF_ID_CorrUncertaintyNP0',dnname='EL_EFF_ID_CorrUncertaintyNP0__1down',upname='EL_EFF_ID_CorrUncertaintyNP0__1up'),
            Systematic(name='EL_EFF_ID_CorrUncertaintyNP10',dnname='EL_EFF_ID_CorrUncertaintyNP10__1down',upname='EL_EFF_ID_CorrUncertaintyNP10__1up'),
            Systematic(name='EL_EFF_ID_CorrUncertaintyNP11',dnname='EL_EFF_ID_CorrUncertaintyNP11__1down',upname='EL_EFF_ID_CorrUncertaintyNP11__1up'),
            Systematic(name='EL_EFF_ID_CorrUncertaintyNP12',dnname='EL_EFF_ID_CorrUncertaintyNP12__1down',upname='EL_EFF_ID_CorrUncertaintyNP12__1up'),
            Systematic(name='EL_EFF_ID_CorrUncertaintyNP13',dnname='EL_EFF_ID_CorrUncertaintyNP13__1down',upname='EL_EFF_ID_CorrUncertaintyNP13__1up'),
            Systematic(name='EL_EFF_ID_CorrUncertaintyNP14',dnname='EL_EFF_ID_CorrUncertaintyNP14__1down',upname='EL_EFF_ID_CorrUncertaintyNP14__1up'),
            Systematic(name='EL_EFF_ID_CorrUncertaintyNP15',dnname='EL_EFF_ID_CorrUncertaintyNP15__1down',upname='EL_EFF_ID_CorrUncertaintyNP15__1up'),
            Systematic(name='EL_EFF_ID_CorrUncertaintyNP1',dnname='EL_EFF_ID_CorrUncertaintyNP1__1down',upname='EL_EFF_ID_CorrUncertaintyNP1__1up'),
            Systematic(name='EL_EFF_ID_CorrUncertaintyNP2',dnname='EL_EFF_ID_CorrUncertaintyNP2__1down',upname='EL_EFF_ID_CorrUncertaintyNP2__1up'),
            Systematic(name='EL_EFF_ID_CorrUncertaintyNP3',dnname='EL_EFF_ID_CorrUncertaintyNP3__1down',upname='EL_EFF_ID_CorrUncertaintyNP3__1up'),
            Systematic(name='EL_EFF_ID_CorrUncertaintyNP4',dnname='EL_EFF_ID_CorrUncertaintyNP4__1down',upname='EL_EFF_ID_CorrUncertaintyNP4__1up'),
            Systematic(name='EL_EFF_ID_CorrUncertaintyNP5',dnname='EL_EFF_ID_CorrUncertaintyNP5__1down',upname='EL_EFF_ID_CorrUncertaintyNP5__1up'),
            Systematic(name='EL_EFF_ID_CorrUncertaintyNP6',dnname='EL_EFF_ID_CorrUncertaintyNP6__1down',upname='EL_EFF_ID_CorrUncertaintyNP6__1up'),
            Systematic(name='EL_EFF_ID_CorrUncertaintyNP7',dnname='EL_EFF_ID_CorrUncertaintyNP7__1down',upname='EL_EFF_ID_CorrUncertaintyNP7__1up'),
            Systematic(name='EL_EFF_ID_CorrUncertaintyNP8',dnname='EL_EFF_ID_CorrUncertaintyNP8__1down',upname='EL_EFF_ID_CorrUncertaintyNP8__1up'),
            Systematic(name='EL_EFF_ID_CorrUncertaintyNP9',dnname='EL_EFF_ID_CorrUncertaintyNP9__1down',upname='EL_EFF_ID_CorrUncertaintyNP9__1up'),
            Systematic(name='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP0',dnname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP0__1down',upname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP0__1up'),
            Systematic(name='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP10',dnname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP10__1down',upname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP10__1up'),
            Systematic(name='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP11',dnname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP11__1down',upname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP11__1up'),
            Systematic(name='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP12',dnname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP12__1down',upname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP12__1up'),
            Systematic(name='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP13',dnname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP13__1down',upname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP13__1up'),
            Systematic(name='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP14',dnname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP14__1down',upname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP14__1up'),
            Systematic(name='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP15',dnname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP15__1down',upname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP15__1up'),
            Systematic(name='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP16',dnname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP16__1down',upname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP16__1up'),
            Systematic(name='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP17',dnname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP17__1down',upname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP17__1up'),
            Systematic(name='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP1',dnname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP1__1down',upname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP1__1up'),
            Systematic(name='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP2',dnname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP2__1down',upname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP2__1up'),
            Systematic(name='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP3',dnname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP3__1down',upname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP3__1up'),
            Systematic(name='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP4',dnname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP4__1down',upname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP4__1up'),
            Systematic(name='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP5',dnname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP5__1down',upname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP5__1up'),
            Systematic(name='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP6',dnname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP6__1down',upname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP6__1up'),
            Systematic(name='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP7',dnname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP7__1down',upname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP7__1up'),
            Systematic(name='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP8',dnname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP8__1down',upname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP8__1up'),
            Systematic(name='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP9',dnname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP9__1down',upname='EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP9__1up'),
            Systematic(name='EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR',dnname='EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR__1down',upname='EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR__1up'),
            Systematic(name='EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR',dnname='EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR__1down',upname='EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR__1up'),
            Systematic(name='EL_EFF_TriggerEff_TOTAL_1NPCOR_PLUS_UNCOR',dnname='EL_EFF_TriggerEff_TOTAL_1NPCOR_PLUS_UNCOR__1down',upname='EL_EFF_TriggerEff_TOTAL_1NPCOR_PLUS_UNCOR__1up'),
            Systematic(name='EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR',dnname='EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down',upname='EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up'),
            Systematic(name='FT_EFF_B_systematics',dnname='FT_EFF_B_systematics__1down',upname='FT_EFF_B_systematics__1up'),
            Systematic(name='FT_EFF_C_systematics',dnname='FT_EFF_C_systematics__1down',upname='FT_EFF_C_systematics__1up'),
            Systematic(name='FT_EFF_Light_systematics',dnname='FT_EFF_Light_systematics__1down',upname='FT_EFF_Light_systematics__1up'),
            Systematic(name='FT_EFF_extrapolation',dnname='FT_EFF_extrapolation__1down',upname='FT_EFF_extrapolation__1up'),
            Systematic(name='FT_EFF_extrapolation_from_charm',dnname='FT_EFF_extrapolation_from_charm__1down',upname='FT_EFF_extrapolation_from_charm__1up'),
            Systematic(name='JET_JvtEfficiency',dnname='JET_JvtEfficiency__1down',upname='JET_JvtEfficiency__1up'),
            Systematic(name='MUON_EFF_ISO_STAT',dnname='MUON_EFF_ISO_STAT__1down',upname='MUON_EFF_ISO_STAT__1up'),
            Systematic(name='MUON_EFF_ISO_SYS',dnname='MUON_EFF_ISO_SYS__1down',upname='MUON_EFF_ISO_SYS__1up'),
            Systematic(name='MUON_EFF_RECO_STAT_LOWPT',dnname='MUON_EFF_RECO_STAT_LOWPT__1down',upname='MUON_EFF_RECO_STAT_LOWPT__1up'),
            Systematic(name='MUON_EFF_RECO_STAT',dnname='MUON_EFF_RECO_STAT__1down',upname='MUON_EFF_RECO_STAT__1up'),
            Systematic(name='MUON_EFF_RECO_SYS_LOWPT',dnname='MUON_EFF_RECO_SYS_LOWPT__1down',upname='MUON_EFF_RECO_SYS_LOWPT__1up'),
            Systematic(name='MUON_EFF_RECO_SYS',dnname='MUON_EFF_RECO_SYS__1down',upname='MUON_EFF_RECO_SYS__1up'),
            Systematic(name='MUON_EFF_TTVA_STAT',dnname='MUON_EFF_TTVA_STAT__1down',upname='MUON_EFF_TTVA_STAT__1up'),
            Systematic(name='MUON_EFF_TTVA_SYS',dnname='MUON_EFF_TTVA_SYS__1down',upname='MUON_EFF_TTVA_SYS__1up'),
            Systematic(name='MUON_EFF_TrigStatUncertainty',dnname='MUON_EFF_TrigStatUncertainty__1down',upname='MUON_EFF_TrigStatUncertainty__1up'),
            Systematic(name='MUON_EFF_TrigSystUncertainty',dnname='MUON_EFF_TrigSystUncertainty__1down',upname='MUON_EFF_TrigSystUncertainty__1up'),
            Systematic(name='PRW_DATASF',dnname='PRW_DATASF__1down',upname='PRW_DATASF__1up'),
            ]

    with root_open(filename, 'read') as f:
        h = dict()
        h['PFLOW'] = f.Get('llvv__GGH__BDT__PFLOW')
        yield_pflow = h['PFLOW'].integral()
        print('{:50s}  {:7.0f} {:9.5F}'.format(f'{filename}   PFLOW', h['PFLOW'].GetEntries(), yield_pflow))
        for s in sList:
            if s.upname:
                h[s.upname] = f.Get(f'llvv__GGH__BDT__{s.upname}')
                s.up = (h[s.upname].integral() - yield_pflow) / yield_pflow * 100
                s.upentries = h[s.upname].GetEntries()
            if s.dnname:
                h[s.dnname] = f.Get(f'llvv__GGH__BDT__{s.dnname}')
                s.down = (h[s.dnname].integral() - yield_pflow) / yield_pflow * 100
                s.downentries = h[s.dnname].GetEntries()

            print('{:50s}  {:7.0f} {:9.5f}  {:7.0f} {:9.5f}'.format(s.name, s.upentries, s.up, s.downentries, s.down))


if __name__ == '__main__':
    #process('qqZZ-rel75-LM.root')
    process('aggZZ-rel75-LM.root')
