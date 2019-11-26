#!/usr/bin/env python3

from rootpy.io import root_open
from rootpy.plotting import Hist
from uncertainties import ufloat

fdata = root_open('emuCR-Data.root', 'r')
fmc = root_open('emuCR-MC.root', 'r')

hee_ggH_data = fdata.Get('Data_ggF_ee_mTZZ')
hmm_ggH_data = fdata.Get('Data_ggF_mm_mTZZ')
hem_ggH_data = fdata.Get('Data_ggF_EM_mTZZ')
hee_ggH_mc = fmc.Get('NonRes_ggF_ee_mTZZ')
hmm_ggH_mc = fmc.Get('NonRes_ggF_mm_mTZZ')

hee_JET_data = fdata.Get('Data_JET_ee_mTZZ')
hmm_JET_data = fdata.Get('Data_JET_mm_mTZZ')
hem_JET_mc = fmc.Get('NonRes_JET_EM_mTZZ')
hee_JET_mc = fmc.Get('NonRes_JET_EE_mTZZ')
hmm_JET_mc = fmc.Get('NonRes_JET_MM_mTZZ')
hem_VBF_mc = fmc.Get('NonRes_VBF_EM_mTZZ')

femCR = root_open('emu-rel75-input.root', 'recreate')

rebin_ggH = [
        (  0,   5), (  6,  10), ( 11,  15), ( 16,  20), ( 21,  25), ( 26,  30),
        ( 31,  35), ( 36,  40), ( 41,  45), ( 46,  50), ( 51,  55), ( 56,  60),
        ( 61,  65), ( 66,  70), ( 71,  75), ( 76,  80), ( 81,  85), ( 86,  90),
        ( 91,  95), ( 96, 100), (101, 110), (111, 120), (121, 130), (131, 140),
        (141, 160), (161, 180), (181, 200), (201, 220), (221, 240), (241, 301),
        ]

hee_ggH_mc = hee_ggH_mc.merge_bins(rebin_ggH)
yee_ggH_data = ufloat(*hee_ggH_data.integral(0, -1, error = True))
yee_ggH_mc = ufloat(*hee_ggH_mc.integral(0, -1, error = True))
hee_ggH_NORM = hee_ggH_mc.Clone()
hee_ggH_STATUP = hee_ggH_mc.Clone()
hee_ggH_STATDN = hee_ggH_mc.Clone()
hee_ggH_NORM.Scale(yee_ggH_data.n / yee_ggH_mc.n)
hee_ggH_STATUP.Scale((yee_ggH_data.n + yee_ggH_data.s) / yee_ggH_mc.n)
hee_ggH_STATDN.Scale((yee_ggH_data.n - yee_ggH_data.s) / yee_ggH_mc.n)
hee_ggH_NORM.Write('emu_rel75_GGH_NORM_ee')
hee_ggH_STATUP.Write('emu_rel75_GGH_StatUP_ee')
hee_ggH_STATDN.Write('emu_rel75_GGH_StatDN_ee')

hmm_ggH_mc = hmm_ggH_mc.merge_bins(rebin_ggH)
ymm_ggH_data = ufloat(*hmm_ggH_data.integral(0, -1, error = True))
ymm_ggH_mc = ufloat(*hmm_ggH_mc.integral(0, -1, error = True))
hmm_ggH_NORM = hmm_ggH_mc.Clone()
hmm_ggH_STATUP = hmm_ggH_mc.Clone()
hmm_ggH_STATDN = hmm_ggH_mc.Clone()
hmm_ggH_NORM.Scale(ymm_ggH_data.n / ymm_ggH_mc.n)
hmm_ggH_STATUP.Scale((ymm_ggH_data.n + ymm_ggH_data.s) / ymm_ggH_mc.n)
hmm_ggH_STATDN.Scale((ymm_ggH_data.n - ymm_ggH_data.s) / ymm_ggH_mc.n)
hmm_ggH_NORM.Write('emu_rel75_GGH_NORM_mm')
hmm_ggH_STATUP.Write('emu_rel75_GGH_StatUP_mm')
hmm_ggH_STATDN.Write('emu_rel75_GGH_StatDN_mm')


yem_ggH_data = ufloat(*hem_ggH_data.integral(0, -1, error = True))
print('{:10.3f} {:10.3f} {:10.3f}'.format(yem_ggH_data/2, yee_ggH_data, ymm_ggH_data))

rebin_JET = [(0, 10), (11, 42), (43, 54), (55, 82), (83, 301)]
yem_JET_mc = ufloat(*hem_JET_mc.integral(0, -1, error = True))
yem_VBF_mc = ufloat(*hem_VBF_mc.integral(0, -1, error = True))
transfer_factor = yem_VBF_mc / yem_JET_mc
print(transfer_factor)

hee_JET_mc = hee_JET_mc.merge_bins(rebin_JET)
yee_JET_data = ufloat(*hee_JET_data.integral(0, -1, error = True))
yee_JET_mc = ufloat(*hee_JET_mc.integral(0, -1, error = True))
hee_VBF_NORM = Hist(170, 0, 1700)
hee_VBF_NORM = hee_VBF_NORM.merge_bins([(0, 10), (11, 42), (43, 54), (55, 82), (83, 171)])
for nb in range(hee_VBF_NORM.GetNbinsX()):
    hee_VBF_NORM.SetBinContent(nb+1, hee_JET_mc.GetBinContent(nb+1))
    hee_VBF_NORM.SetBinError  (nb+1, hee_JET_mc.GetBinError  (nb+1))
hee_VBF_STATUP = hee_VBF_NORM.Clone()
hee_VBF_STATDN = hee_VBF_NORM.Clone()
hee_VBF_TFUP = hee_VBF_NORM.Clone()
hee_VBF_TFDN = hee_VBF_NORM.Clone()
hee_VBF_NORM.Scale(yee_JET_data.n / yee_JET_mc.n * transfer_factor.n)
hee_VBF_STATUP.Scale((yee_JET_data.n + yee_JET_data.s) / yee_JET_mc.n * transfer_factor.n)
hee_VBF_STATDN.Scale((yee_JET_data.n - yee_JET_data.s) / yee_JET_mc.n * transfer_factor.n)
hee_VBF_TFUP.Scale(yee_JET_data.n / yee_JET_mc.n * (transfer_factor.n + transfer_factor.s))
hee_VBF_TFDN.Scale(yee_JET_data.n / yee_JET_mc.n * (transfer_factor.n - transfer_factor.s))
hee_VBF_NORM.Write('emu_rel75_VBF_NORM_ee')
hee_VBF_STATUP.Write('emu_rel75_VBF_StatUP_ee')
hee_VBF_STATDN.Write('emu_rel75_VBF_StatDN_ee')
hee_VBF_TFUP.Write('emu_rel75_VBF_TransferFactorUP_ee')
hee_VBF_TFDN.Write('emu_rel75_VBF_TransferFactorDN_ee')

hmm_JET_mc = hmm_JET_mc.merge_bins(rebin_JET)
ymm_JET_data = ufloat(*hmm_JET_data.integral(0, -1, error = True))
ymm_JET_mc = ufloat(*hmm_JET_mc.integral(0, -1, error = True))
hmm_VBF_NORM = Hist(170, 0, 1700)
hmm_VBF_NORM = hmm_VBF_NORM.merge_bins([(0, 10), (11, 42), (43, 54), (55, 82), (83, 171)])
for nb in range(hmm_VBF_NORM.GetNbinsX()):
    hmm_VBF_NORM.SetBinContent(nb+1, hmm_JET_mc.GetBinContent(nb+1))
    hmm_VBF_NORM.SetBinError  (nb+1, hmm_JET_mc.GetBinError  (nb+1))
hmm_VBF_STATUP = hmm_VBF_NORM.Clone()
hmm_VBF_STATDN = hmm_VBF_NORM.Clone()
hmm_VBF_TFUP = hmm_VBF_NORM.Clone()
hmm_VBF_TFDN = hmm_VBF_NORM.Clone()
hmm_VBF_NORM.Scale(ymm_JET_data.n / ymm_JET_mc.n * transfer_factor.n)
hmm_VBF_STATUP.Scale((ymm_JET_data.n + ymm_JET_data.s) / ymm_JET_mc.n * transfer_factor.n)
hmm_VBF_STATDN.Scale((ymm_JET_data.n - ymm_JET_data.s) / ymm_JET_mc.n * transfer_factor.n)
hmm_VBF_TFUP.Scale(ymm_JET_data.n / ymm_JET_mc.n * (transfer_factor.n + transfer_factor.s))
hmm_VBF_TFDN.Scale(ymm_JET_data.n / ymm_JET_mc.n * (transfer_factor.n - transfer_factor.s))
hmm_VBF_NORM.Write('emu_rel75_VBF_NORM_mm')
hmm_VBF_STATUP.Write('emu_rel75_VBF_StatUP_mm')
hmm_VBF_STATDN.Write('emu_rel75_VBF_StatDN_mm')
hmm_VBF_TFUP.Write('emu_rel75_VBF_TransferFactorUP_mm')
hmm_VBF_TFDN.Write('emu_rel75_VBF_TransferFactorDN_mm')

femCR.Close()
