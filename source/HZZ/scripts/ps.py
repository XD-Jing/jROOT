#!/usr/bin/env python

import logging
import rootpy
import ROOT
logging.getLogger("rootpy").setLevel(logging.WARNING)
logging.getLogger("ROOT").setLevel(logging.WARNING)
logging.getLogger("matplotlib").setLevel(logging.WARNING)

import numpy as np

from rootpy.io import root_open
from rootpy.plotting import Hist
import rootpy.plotting.root2matplotlib as rplt

import matplotlib.pyplot as plt
#import matplotlib.gridspec as gridspec
from Jing.plots.jPlt import plot_atlas_axis

n = 30



def process(froot, xsec):
    h = dict()
    with root_open(froot+'.root', 'r') as f:
        def hinit(hname):
            return f.Get(hname).merge_bins([(21, 22), (23, 24), (25, 26), (27, 28), (29, 32), (33, 36), (37, 40), (41, 44), (45, 48), (49, 61)])

        h['DAOD'] = hinit('llvv__DAOD__NOMINAL')
        #sW_1 = 1. /  h['DAOD'].integral(0, -1) * xsec

        h['NORM'] = hinit('llvv___GGH__mTZZ__NOMINAL')
        #h['NORM'].Scale(sW_1)
        #h['NORM'].linecolor = 'k'
        #h['NORM'].title = 'NOMINAL'


        PSUP, PSDN = np.zeros(n), np.zeros(n)
        for w, color in zip(['CKKW15', 'CKKW30', 'QSF025', 'QSF4',  'CSSKIN'], ['r', 'g', 'b', 'y', 'm', 'c']):
            hname = 'llvv___GGH__mTZZ__' + w
            h[hname] = hinit(hname)
            #h[hname].Scale( h['NORM'].integral(0, -1) / h[hname].integral(0, -1))


        with root_open('shape_ps_ratio.root', 'recreate') as fout:
            for w in ['CKKW15', 'CKKW30', 'QSF025', 'QSF4',  'CSSKIN']:
                hname = 'llvv___GGH__mTZZ__' + w
                tmp = Hist.divide(h[hname], h['NORM'])
                #tmp.title = w
                tmp.Write(w)

        #for nb in range(n):
        #    norm = h['NORM'].GetBinContent(nb+1)
        #    PSUP[nb] += max(0, h['llvv___GGH__mTZZ__CKKW15'].GetBinContent(nb+1) - norm, h['llvv___GGH__mTZZ__CKKW30'].GetBinContent(nb+1) - norm) ** 2
        #    PSUP[nb] += max(0, h['llvv___GGH__mTZZ__QSF025'].GetBinContent(nb+1) - norm, h['llvv___GGH__mTZZ__QSF4'].GetBinContent(nb+1) - norm) ** 2
        #    PSUP[nb] += (h['llvv___GGH__mTZZ__CSSKIN'].GetBinContent(nb+1) - norm) ** 2

        #    PSDN[nb] += min(0, h['llvv___GGH__mTZZ__CKKW15'].GetBinContent(nb+1) - norm, h['llvv___GGH__mTZZ__CKKW30'].GetBinContent(nb+1) - norm) ** 2
        #    PSDN[nb] += min(0, h['llvv___GGH__mTZZ__QSF025'].GetBinContent(nb+1) - norm, h['llvv___GGH__mTZZ__QSF4'].GetBinContent(nb+1) - norm) ** 2
        #    PSDN[nb] += (h['llvv___GGH__mTZZ__CSSKIN'].GetBinContent(nb+1) - norm) ** 2

        #    PSUP[nb] = np.sqrt(PSUP[nb])
        #    PSDN[nb] = np.sqrt(PSDN[nb])


        #fig, (ax, axr) = plt.subplots(2, figsize=(5, 5), sharex=True, gridspec_kw={'height_ratios':[3,1]})
        #rplt.hist(h['NORM'], axes = ax, zorder = -1)
        #rplt.hist(hTHUP, axes = ax, zorder = -1)
        #rplt.hist(hTHDN, axes = ax, zorder = -1)
        #rplt.hist(rNORM, axes = axr, zorder = -1)
        #rplt.hist(rTHUP, axes = axr, zorder = -1)
        #rplt.hist(rTHDN, axes = axr, zorder = -1)


        #ax.legend()
        #plot_atlas_axis(ax, xlabel='', ylabel='Events', xlim = (0, 3000))
        #plot_atlas_axis(axr, xlabel=r'$m_{T}^{ZZ}$[GeV]', ylabel='THEO/NOMINAL', ylim = (0, 2), yticker = (0.5, 0.1), xlim = (0, 3000))
        #plt.tight_layout()
        #plt.savefig(froot+'_mTZZ_THEO.pdf')


if __name__ == '__main__':
    process('ggZZ', 0.0071055 * 139 * 1000)
    process('qqZZ', 0.49785 * 139 * 1000)
