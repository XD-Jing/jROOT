#!/usr/bin/env python3

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
#from Jing.plots.jPlt import plot_atlas_axis, plot_atlas_logo

def hinit(f, hname, rebin):
    #return f.Get(hname).merge_bins([(21, 22), (23, 24), (25, 26), (27, 28), (29, 32), (33, 36), (37, 40), (41, 44), (45, 48), (49, 61)])
    return f.Get(hname).merge_bins(rebin)

def processQCD(froot, rebin):
    h = dict()
    with root_open(froot+'.root', 'r') as f:

        h['NORM'] = hinit(f, 'llvv__GGH__mTZZ__PFLOW', rebin)
        h['NORM'].Scale(1./h['NORM'].integral(0, -1))
        h['NORM'].linecolor = 'k'
        h['NORM'].title = 'NOMINAL'
        h['rNORM'] = h['NORM'].empty_clone()
        h['rNORM'].linecolor = 'k'

        n = h['NORM'].GetNbinsX()
        h['QCDUP'], h['QCDDN'] = h['NORM'].empty_clone(), h['NORM'].empty_clone()
        for nb in range(n):
            if h['NORM'].GetBinContent(nb+1) > 0:
                h['rNORM'].SetBinContent(nb+1, 1)
                h['QCDUP'].SetBinContent(nb+1, 1)
                h['QCDDN'].SetBinContent(nb+1, 1)

        legenddict = dict()
        legenddict['QCD55'] = r'$\mu_{R}=0.5, \mu_{F}=0.5$'
        legenddict['QCD51'] = r'$\mu_{R}=0.5, \mu_{F}=1$'
        legenddict['QCD15'] = r'$\mu_{R}=1, \mu_{F}=0.5$'
        legenddict['QCD21'] = r'$\mu_{R}=2, \mu_{F}=1$'
        legenddict['QCD12'] = r'$\mu_{R}=1, \mu_{F}=2$'
        legenddict['QCD22'] = r'$\mu_{R}=2, \mu_{F}=2$'

        #QCDUP, QCDDN = np.zeros(n), np.zeros(n)
        #for nb in range(n):
        #    QCDUP[nb] = h['NORM'].GetBinContent(nb+1)
        #    QCDDN[nb] = h['NORM'].GetBinContent(nb+1)
        fig, (ax, axr) = plt.subplots(2, figsize=(5, 5), sharex=True, gridspec_kw={'height_ratios':[3,1]})
        for w, color in zip(['QCD55', 'QCD51', 'QCD15', 'QCD21', 'QCD12', 'QCD22'], ['r', 'g', 'b', 'y', 'm', 'c']):
            hname = 'llvv__GGH__mTZZ__' + w
            h[hname] = hinit(f, hname, rebin)

            h[hname].title = legenddict[w]
            h[hname].linecolor = color
            h[hname].Scale( 1 / h[hname].integral(0, -1))
            rplt.hist(h[hname], axes = ax, zorder = -1)

            r = h[hname].empty_clone()
            for nb in range(n):
                norm = h['NORM'].GetBinContent(nb+1)
                if norm > 0:
                    r.SetBinContent(nb+1, h[hname].GetBinContent(nb+1) / norm)
                QCDUP[nb] = max(h[hname].GetBinContent(nb+1), QCDUP[nb])
                QCDDN[nb] = min(h[hname].GetBinContent(nb+1), QCDDN[nb])
            r.linecolor = color
            #r.Smooth()
            rplt.hist(r, axes = axr, zorder = -1)
        rplt.hist(h['NORM'], axes = ax, zorder = -1)
        rplt.hist(h['rNORM'], axes = axr, zorder = -1)
        ax.legend()
        axr.set_ylim([0.8, 1.2])
        #plot_atlas_axis(ax, xlabel='', ylabel='Events', xlim = (0, 3000), ylim=ylim[froot])
        #plot_atlas_axis(axr, xlabel=r'$m_{T}^{ZZ}$[GeV]', ylabel='QCD/NOMINAL', ylim = rQCD, yticker = tickQCD, xlim = (0, 3000))
        #plot_atlas_logo(ax, loc=[0.05, 0.90], lumi=139, info=f'Scale uncertainty {froot}', gap=0.15)
        plt.tight_layout()
        plt.savefig(froot+'_mTZZ_QCD.pdf')


        #h['QCDUP'] = h['NORM'].empty_clone()
        #h['QCDDN'] = h['NORM'].empty_clone()
        #h['rQCDUP'] = h['NORM'].empty_clone()
        #h['rQCDDN'] = h['NORM'].empty_clone()
        #h['QCDUP'].linecolor = 'r'
        #h['QCDDN'].linecolor = 'b'
        #h['rQCDUP'].linecolor = 'r'
        #h['rQCDDN'].linecolor = 'b'
        #h['QCDUP'].title = 'up'
        #h['QCDDN'].title = 'down'
        #for nb in range(n):
        #    h['QCDUP'].SetBinContent(nb+1, QCDUP[nb])
        #    h['QCDDN'].SetBinContent(nb+1, QCDDN[nb])
        #    norm = h['NORM'].GetBinContent(nb+1)
        #    if norm > 0:
        #        h['rQCDUP'].SetBinContent(nb+1, QCDUP[nb] / norm)
        #        h['rQCDDN'].SetBinContent(nb+1, QCDDN[nb] / norm)
        #fig, (ax, axr) = plt.subplots(2, figsize=(5, 5), sharex=True, gridspec_kw={'height_ratios':[3,1]})
        #rplt.hist(h['NORM'], axes = ax, zorder = -1)
        #rplt.hist(h['rNORM'], axes = axr, zorder = -1)
        #rplt.hist(h['QCDUP'], axes = ax, zorder = -1)
        #rplt.hist(h['QCDDN'], axes = ax, zorder = -1)
        #rplt.hist(h['rQCDUP'], axes = axr, zorder = -1)
        #rplt.hist(h['rQCDDN'], axes = axr, zorder = -1)
        #ax.legend()
        #plot_atlas_axis(ax, xlabel='', ylabel='Events', xlim = (0, 3000), ylim = ylim[froot])
        #plot_atlas_axis(axr, xlabel=r'$m_{T}^{ZZ}$[GeV]', ylabel='Scale/NOMINAL', ylim = rQCD, yticker = tickQCD, xlim = (0, 3000))
        #plot_atlas_logo(ax, loc=[0.05, 0.90], lumi=139, info=f'Scale uncertainty {froot}', gap=0.15)
        #plt.tight_layout()
        #plt.savefig(froot+'_mTZZ_QCD_merge.pdf')




        #fig, (ax, axr) = plt.subplots(2, figsize=(5, 5), sharex=True, gridspec_kw={'height_ratios':[3,1]})
        #for i in range(100):
        #    hname = 'llvv___GGH__mTZZ__PDF{}'.format(i)
        #    h[hname] = hinit(hname)
        #    h[hname].linecolor = 'r'
        #    h['r' + hname] = h['NORM'].empty_clone()
        #    h['r' + hname].linecolor = 'r'
        #    if i==0:
        #        h[hname].title = 'PDF'
        #    h[hname].Scale( h['NORM'].integral(0, -1) / h[hname].integral(0, -1))
        #    for nb in range(n):
        #        norm = h['NORM'].GetBinContent(nb+1)
        #        if norm > 0:
        #            h['r' + hname].SetBinContent(nb+1, h[hname].GetBinContent(nb+1) / norm)

        #    rplt.hist(h[hname], axes = ax, zorder = -1)
        #    rplt.hist(h['r' + hname], axes = axr, zorder = -1)

        #rplt.hist(h['NORM'], axes = ax, zorder = -1)
        #rplt.hist(h['rNORM'], axes = axr, zorder = -1)
        #ax.legend()
        #plot_atlas_axis(ax, xlabel='', ylabel='Events', xlim = (0, 3000), ylim = ylim[froot])
        #plot_atlas_axis(axr, xlabel=r'$m_{T}^{ZZ}$[GeV]', ylabel='PDF/NOMINAL', ylim = rPDF, yticker = tickPDF, xlim = (0, 3000))
        #plot_atlas_logo(ax, loc=[0.05, 0.90], lumi=139, info=f'PDF uncertainty {froot}', gap=0.15)
        #plt.tight_layout()
        #plt.savefig(froot+'_mTZZ_PDF.pdf')


        #PDF = np.zeros(n)
        #for i in range(100):
        #    for nb in range(n):
        #        norm = h['NORM'].GetBinContent(nb+1)
        #        hname = 'llvv___GGH__mTZZ__PDF{}'.format(i)
        #        pdfnb = h[hname].GetBinContent(nb+1)
        #        PDF[nb] += (norm - pdfnb) ** 2

        #h['PDF_UP'] = h['NORM'].empty_clone()
        #h['PDF_DN'] = h['NORM'].empty_clone()
        #h['rPDF_UP'] = h['NORM'].empty_clone()
        #h['rPDF_DN'] = h['NORM'].empty_clone()
        #h['PDF_UP'].title='up'
        #h['PDF_DN'].title='down'
        #h['PDF_UP'].linecolor='r'
        #h['PDF_DN'].linecolor='b'
        #h['rPDF_UP'].linecolor='r'
        #h['rPDF_DN'].linecolor='b'
        #for nb in range(n):
        #    norm = h['NORM'].GetBinContent(nb+1)
        #    PDF[nb] = np.sqrt(PDF[nb] / 100.0)
        #    pdfnb = PDF[nb]
        #    h['PDF_UP'].SetBinContent(nb+1, norm + pdfnb)
        #    h['PDF_DN'].SetBinContent(nb+1, norm - pdfnb)
        #    if norm>0:
        #        h['rPDF_UP'].SetBinContent(nb+1, 1 + pdfnb/norm)
        #        h['rPDF_DN'].SetBinContent(nb+1, 1 - pdfnb/norm)

        #fig, (ax, axr) = plt.subplots(2, figsize=(5, 5), sharex=True, gridspec_kw={'height_ratios':[3,1]})
        #rplt.hist(h['PDF_UP'], axes = ax, zorder = -1)
        #rplt.hist(h['PDF_DN'], axes = ax, zorder = -1)
        #rplt.hist(h['rPDF_UP'], axes = axr, zorder = -1)
        #rplt.hist(h['rPDF_DN'], axes = axr, zorder = -1)
        #rplt.hist(h['NORM'], axes = ax, zorder = -1)
        #rplt.hist(h['rNORM'], axes = axr, zorder = -1)
        #ax.legend()
        #plot_atlas_axis(ax, xlabel='', ylabel='Events', xlim = (0, 3000), ylim = ylim[froot])
        #plot_atlas_axis(axr, xlabel=r'$m_{T}^{ZZ}$[GeV]', ylabel='PDF/NOMINAL', ylim = rPDF, yticker = tickPDF, xlim = (0, 3000))
        #plot_atlas_logo(ax, loc=[0.05, 0.90], lumi=139, info=f'PDF uncertainty {froot}', gap=0.15)
        #plt.tight_layout()
        #plt.savefig(froot+'_mTZZ_PDF_merge.pdf')


        #PSUP, PSDN = np.zeros(n), np.zeros(n)
        #fig, (ax, axr) = plt.subplots(2, figsize=(5, 5), sharex=True, gridspec_kw={'height_ratios':[3,1]})
        #for w, color in zip(['CKKW15', 'CKKW30', 'QSF025', 'QSF4',  'CSSKIN'], ['r', 'g', 'b', 'y', 'm', 'c']):
        #    hname = 'llvv___GGH__mTZZ__' + w
        #    h[hname] = hinit(hname)
        #    tmp = f.get('llvv__DAOD__' + w)
        #    #h[hname].Scale(1./tmp.integral(0, -1))
        #    h[hname].title = w
        #    h[hname].linecolor = color
        #    h[hname].Scale( h['NORM'].integral(0, -1) / h[hname].integral(0, -1))
        #    rplt.hist(h[hname], axes = ax, zorder = -1)

        #    r = h[hname].empty_clone()
        #    for nb in range(n):
        #        norm = h['NORM'].GetBinContent(nb+1)
        #        if norm > 0:
        #            r.SetBinContent(nb+1, h[hname].GetBinContent(nb+1) / norm)
        #    r.linecolor = color
        #    rplt.hist(r, axes = axr, zorder = -1)

        #rplt.hist(h['NORM'], axes = ax, zorder = -1)
        #rplt.hist(h['rNORM'], axes = axr, zorder = -1)
        #ax.legend()
        #plot_atlas_axis(ax, xlabel='', ylabel='Events', xlim = (0, 3000), ylim = ylim[froot])
        #plot_atlas_axis(axr, xlabel=r'$m_{T}^{ZZ}$[GeV]', ylabel='PS/NOMINAL', ylim = rPS, yticker = tickPS, xlim = (0, 3000))
        #plot_atlas_logo(ax, loc=[0.05, 0.9], lumi=139, info=f'PS uncertainty {froot}', gap = 0.15)
        #plt.tight_layout()
        #plt.savefig(froot+'_mTZZ_PS.pdf')

        #h['PSUP'] = h['NORM'].empty_clone()
        #h['PSDN'] = h['NORM'].empty_clone()
        #h['rPSUP'] = h['NORM'].empty_clone()
        #h['rPSDN'] = h['NORM'].empty_clone()
        #h['PSUP'].linecolor = 'r'
        #h['PSDN'].linecolor = 'b'
        #h['rPSUP'].linecolor = 'r'
        #h['rPSDN'].linecolor = 'b'
        #h['PSUP'].title = 'up'
        #h['PSDN'].title = 'down'
        #for nb in range(n):
        #    norm = h['NORM'].GetBinContent(nb+1)
        #    PSUP[nb] += (max(norm, h['llvv___GGH__mTZZ__CKKW15'].GetBinContent(nb+1), h['llvv___GGH__mTZZ__CKKW30'].GetBinContent(nb+1)) - norm) ** 2
        #    PSUP[nb] += (max(norm, h['llvv___GGH__mTZZ__QSF025'].GetBinContent(nb+1), h['llvv___GGH__mTZZ__QSF4'].GetBinContent(nb+1)) - norm) ** 2
        #    PSUP[nb] += (max(norm, h['llvv___GGH__mTZZ__CSSKIN'].GetBinContent(nb+1)) - norm) ** 2
        #    PSDN[nb] += (min(norm, h['llvv___GGH__mTZZ__CKKW15'].GetBinContent(nb+1), h['llvv___GGH__mTZZ__CKKW30'].GetBinContent(nb+1)) - norm) ** 2
        #    PSDN[nb] += (min(norm, h['llvv___GGH__mTZZ__QSF025'].GetBinContent(nb+1), h['llvv___GGH__mTZZ__QSF4'].GetBinContent(nb+1)) - norm) ** 2
        #    PSDN[nb] += (min(norm, h['llvv___GGH__mTZZ__CSSKIN'].GetBinContent(nb+1)) - norm) ** 2

        #    PSUP[nb] = np.sqrt(PSUP[nb])
        #    PSDN[nb] = np.sqrt(PSDN[nb])
        #    h['PSUP'].SetBinContent(nb+1, norm + PSUP[nb])
        #    h['PSDN'].SetBinContent(nb+1, norm - PSDN[nb])
        #    if norm > 0:
        #        h['rPSUP'].SetBinContent(nb+1, 1 + PSUP[nb] / norm)
        #        h['rPSDN'].SetBinContent(nb+1, 1 - PSDN[nb] / norm)


        #fig, (ax, axr) = plt.subplots(2, figsize=(5, 5), sharex=True, gridspec_kw={'height_ratios':[3,1]})
        #rplt.hist(h['NORM'], axes = ax, zorder = -1)
        #rplt.hist(h['rNORM'], axes = axr, zorder = -1)
        #rplt.hist(h['PSUP'], axes = ax, zorder = -1)
        #rplt.hist(h['PSDN'], axes = ax, zorder = -1)
        #rplt.hist(h['rPSUP'], axes = axr, zorder = -1)
        #rplt.hist(h['rPSDN'], axes = axr, zorder = -1)
        #ax.legend()
        #plot_atlas_axis(ax, xlabel='', ylabel='Events', xlim = (0, 3000), ylim = ylim[froot])
        #plot_atlas_axis(axr, xlabel=r'$m_{T}^{ZZ}$[GeV]', ylabel='PS/NOMINAL', ylim = rPS, yticker = tickPS, xlim = (0, 3000))
        #plot_atlas_logo(ax, loc=[0.05, 0.9], lumi=139, info=f'PS uncertainty {froot}', gap = 0.15)
        #plt.tight_layout()
        #plt.savefig(froot+'_mTZZ_PS_merge.pdf')


        #THEOUP, THEODN = np.zeros(n), np.zeros(n)
        #h['THEOUP'] = h['NORM'].empty_clone()
        #h['THEODN'] = h['NORM'].empty_clone()
        #h['rTHEOUP'] = h['NORM'].empty_clone()
        #h['rTHEODN'] = h['NORM'].empty_clone()
        #h['THEOUP'].linecolor = 'r'
        #h['THEODN'].linecolor = 'b'
        #h['rTHEOUP'].linecolor = 'r'
        #h['rTHEODN'].linecolor = 'b'
        #h['THEOUP'].title = 'up'
        #h['THEODN'].title = 'down'
        #for nb in range(n):
        #    norm = h['NORM'].GetBinContent(nb+1)
        #    THEOUP[nb] = norm + np.sqrt( PDF[nb] ** 2 + (QCDUP[nb] - norm) ** 2 + PSUP[nb] ** 2)
        #    THEODN[nb] = norm - np.sqrt( PDF[nb] ** 2 + (QCDDN[nb] - norm) ** 2 + PSDN[nb] ** 2)
        #    h['THEOUP'].SetBinContent(nb+1, THEOUP[nb])
        #    h['THEODN'].SetBinContent(nb+1, THEODN[nb])
        #    if norm > 0:
        #        h['rTHEOUP'].SetBinContent(nb+1, THEOUP[nb] / norm)
        #        h['rTHEODN'].SetBinContent(nb+1, THEODN[nb] / norm)
        #fig, (ax, axr) = plt.subplots(2, figsize=(5, 5), sharex=True, gridspec_kw={'height_ratios':[3,1]})
        #rplt.hist(h['NORM'], axes = ax, zorder = -1)
        #rplt.hist(h['rNORM'], axes = axr, zorder = -1)
        #rplt.hist(h['THEOUP'], axes = ax, zorder = -1)
        #rplt.hist(h['THEODN'], axes = ax, zorder = -1)
        #rplt.hist(h['rTHEOUP'], axes = axr, zorder = -1)
        #rplt.hist(h['rTHEODN'], axes = axr, zorder = -1)
        #ax.legend()
        #plot_atlas_axis(ax, xlabel='', ylabel='Events', xlim = (0, 3000), ylim = ylim[froot])
        #plot_atlas_axis(axr, xlabel=r'$m_{T}^{ZZ}$[GeV]', ylabel='THEO/NOMINAL', ylim = rPS, yticker = tickPS, xlim = (0, 3000))
        #plot_atlas_logo(ax, loc=[0.05, 0.9], lumi=139, info=f'Theoretical uncertainty {froot}', gap = 0.15)
        #plt.tight_layout()
        #plt.savefig(froot+'_mTZZ_THEO_merge.pdf')


        #def phist(dic, key):
        #    print('{:10} {:.5f}'.format(key, dic[key].integral(0, -1)))

        #phist(h, 'NORM')
        #phist(h, 'QCDUP')
        #phist(h, 'QCDDN')
        #phist(h, 'PDF_UP')
        #phist(h, 'PDF_DN')
        #phist(h, 'PSUP')
        #phist(h, 'PSDN')

if __name__ == '__main__':

    #rebin = [(i*2+1, i*2+2) for i in range(10)] + [(21, 24), (25, 28), (29, 38), (39, 61)]
    #processQCD('ggZZ-rel75', rebin)
    rebin = [(1, 6), (7, 8), (9, 10), (11, 12), (13, 14), (15, 16), (17, 26), (27, 61)]
    #rebin = [(i*2+1, i*2+2) for i in range(10)] + [(21, 24), (25, 28), (29, 38), (39, 61)]
    #rebin = [(21, 22), (23, 24), (25, 26), (27, 28), (29, 32), (33, 36), (37, 40), (41, 44), (45, 48), (49, 61)]
    processQCD('qqZZ-rel75', rebin)
