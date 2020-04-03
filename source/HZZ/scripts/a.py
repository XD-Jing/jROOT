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

def process(froot, xsec, rQCD=[0.5, 1.5], rPDF=[0, 2], rPS=[0, 2], tickQCD=[0.5, 0.1], tickPDF=[0.5, 0.1], tickPS=[0.5, 0.1]):
    h = dict()
    with root_open(froot+'.root', 'r') as f:
        def hinit(hname):
            return f.Get(hname).merge_bins([(21, 22), (23, 24), (25, 26), (27, 28), (29, 32), (33, 36), (37, 40), (41, 44), (45, 48), (49, 61)])

        h['DAOD'] = hinit('llvv__DAOD__NOMINAL')
        sW_1 = 1. /  h['DAOD'].integral(0, -1) * xsec

        h['NORM'] = hinit('llvv___GGH__mTZZ__NOMINAL')
        h['NORM'].Scale(sW_1)
        h['NORM'].linecolor = 'k'
        h['NORM'].title = 'NOMINAL'

        legenddict = dict()
        legenddict['QCD55'] = r'$\mu_{R}=0.5, \mu_{F}=0.5$'
        legenddict['QCD51'] = r'$\mu_{R}=0.5, \mu_{F}=1$'
        legenddict['QCD15'] = r'$\mu_{R}=1, \mu_{F}=0.5$'
        legenddict['QCD21'] = r'$\mu_{R}=2, \mu_{F}=1$'
        legenddict['QCD12'] = r'$\mu_{R}=1, \mu_{F}=2$'
        legenddict['QCD22'] = r'$\mu_{R}=2, \mu_{F}=2$'
        QCD = np.zeros(n)
        fig, (ax, axr) = plt.subplots(2, figsize=(5, 5), sharex=True, gridspec_kw={'height_ratios':[3,1]})
        rplt.hist(h['NORM'], axes = ax, zorder = -1)
        for w, color in zip(['QCD55', 'QCD51', 'QCD15', 'QCD21', 'QCD12', 'QCD22'], ['r', 'g', 'b', 'y', 'm', 'c']):
            hname = 'llvv___GGH__mTZZ__' + w
            h[hname] = hinit(hname)

            #h[hname].Scale(sW_1)
            h[hname].title = legenddict[w]
            h[hname].linecolor = color
            h[hname].Scale( h['NORM'].integral(0, -1) / h[hname].integral(0, -1))
            rplt.hist(h[hname], axes = ax, zorder = -1)

            r = h[hname].empty_clone()
            for nb in range(n):
                norm = h['NORM'].GetBinContent(nb+1)
                if norm > 0:
                    r.SetBinContent(nb+1, h[hname].GetBinContent(nb+1) / norm)
                QCD[nb] = max(np.abs(h['NORM'].GetBinContent(nb) - h[hname].GetBinContent(nb)), QCD[nb])
            r.linecolor = color
            rplt.hist(r, axes = axr, zorder = -1)
        ax.legend()
        plot_atlas_axis(ax, xlabel='', ylabel='Events', xlim = (0, 3000))
        plot_atlas_axis(axr, xlabel=r'$m_{T}^{ZZ}$[GeV]', ylabel='QCD/NOMINAL', ylim = rQCD, yticker = tickQCD, xlim = (0, 3000))
        plt.tight_layout()
        plt.savefig(froot+'_mTZZ_QCD.pdf')
        plt.savefig(froot+'_mTZZ_QCD.png')
        h['QCD_UP'] = h['NORM'].empty_clone()
        h['QCD_DN'] = h['NORM'].empty_clone()
        for nb in range(n):
            h['QCD_UP'].SetBinContent(nb, h['NORM'].GetBinContent(nb) + QCD[nb])
            h['QCD_DN'].SetBinContent(nb, h['NORM'].GetBinContent(nb) - QCD[nb])

        PDF = np.zeros(n)
        fig, (ax, axr) = plt.subplots(2, figsize=(5, 5), sharex=True, gridspec_kw={'height_ratios':[3,1]})
        for i in range(100):
            hname = 'llvv___GGH__mTZZ__PDF{}'.format(i)
            h[hname] = hinit(hname)
            h[hname].linecolor = 'r'
            h[hname].Scale( h['NORM'].integral(0, -1) / h[hname].integral(0, -1))
            if i==0: h[hname].title = 'PDF'
            rplt.hist(h[hname], axes = ax, zorder = -1)

            r = h[hname].empty_clone()
            for nb in range(n):
                norm = h['NORM'].GetBinContent(nb+1)
                if norm > 0:
                    r.SetBinContent(nb+1, h[hname].GetBinContent(nb+1) / norm)
                PDF[nb] += (h['NORM'].GetBinContent(nb) - h[hname].GetBinContent(nb)) ** 2
            r.linecolor = 'r'
            rplt.hist(r, axes = axr, zorder = -1)
            if r.GetBinContent(26)>1.2:
                print(i, r.GetBinContent(26))

        rplt.hist(h['NORM'], axes = ax, zorder = -1)
        ax.legend()
        plot_atlas_axis(ax, xlabel='', ylabel='Events', xlim = (0, 3000))
        plot_atlas_axis(axr, xlabel=r'$m_{T}^{ZZ}$[GeV]', ylabel='PDF/NOMINAL', ylim = rPDF, yticker = tickPDF, xlim = (0, 3000))
        plt.tight_layout()
        plt.savefig(froot+'_mTZZ_PDF.pdf')
        plt.savefig(froot+'_mTZZ_PDF.png')
        h['PDF_UP'] = h['NORM'].empty_clone()
        h['PDF_DN'] = h['NORM'].empty_clone()
        for nb in range(n):
            h['PDF_UP'].SetBinContent(nb, h['NORM'].GetBinContent(nb) + np.sqrt(PDF[nb]))
            h['PDF_DN'].SetBinContent(nb, h['NORM'].GetBinContent(nb) - np.sqrt(PDF[nb]))


        PS = np.zeros(n)
        fig, (ax, axr) = plt.subplots(2, figsize=(5, 5), sharex=True, gridspec_kw={'height_ratios':[3,1]})
        rplt.hist(h['NORM'], axes = ax, zorder = -1)
        for w, color in zip(['CKKW15', 'CKKW30', 'QSF025', 'QSF4',  'CSSKIN'], ['r', 'g', 'b', 'y', 'm', 'c']):
            hname = 'llvv___GGH__mTZZ__' + w
            h[hname] = hinit(hname)
            tmp = f.get('llvv__DAOD__' + w)
            #h[hname].Scale(1./tmp.integral(0, -1))
            h[hname].title = w
            h[hname].linecolor = color
            h[hname].Scale( h['NORM'].integral(0, -1) / h[hname].integral(0, -1))
            rplt.hist(h[hname], axes = ax, zorder = -1)

            r = h[hname].empty_clone()
            for nb in range(n):
                norm = h['NORM'].GetBinContent(nb+1)
                if norm > 0:
                    r.SetBinContent(nb+1, h[hname].GetBinContent(nb+1) / norm)
                PS[nb] += (h['NORM'].GetBinContent(nb+1) - h[hname].GetBinContent(nb+1)) ** 2
            r.linecolor = color
            rplt.hist(r, axes = axr, zorder = -1)
        ax.legend()
        plot_atlas_axis(ax, xlabel='', ylabel='Events', xlim = (0, 3000))
        plot_atlas_axis(axr, xlabel=r'$m_{T}^{ZZ}$[GeV]', ylabel='PS/NOMINAL', ylim = rPS, yticker = tickPS, xlim = (0, 3000))
        plt.tight_layout()
        plt.savefig(froot+'_mTZZ_PS.pdf')
        plt.savefig(froot+'_mTZZ_PS.png')
        h['PS_UP'] = h['NORM'].empty_clone()
        h['PS_DN'] = h['NORM'].empty_clone()
        for nb in range(n):
            h['PS_UP'].SetBinContent(nb, h['NORM'].GetBinContent(nb) + np.sqrt(PS[nb]))
            h['PS_DN'].SetBinContent(nb, h['NORM'].GetBinContent(nb) - np.sqrt(PS[nb]))


        def phist(dic, key):
            print('{:10} {:.5f}'.format(key, dic[key].integral(0, -1)))

        phist(h, 'NORM')
        phist(h, 'QCD_UP')
        phist(h, 'QCD_DN')
        phist(h, 'PDF_UP')
        phist(h, 'PDF_DN')
        phist(h, 'PS_UP')
        phist(h, 'PS_DN')

if __name__ == '__main__':
    process('ggZZ', 0.0071055 * 139 * 1000, rQCD=[0.8, 1.2], rPDF=[0, 2], rPS=[0, 2], tickQCD=[0.2, 0.05], tickPDF=[0.5, 0.1], tickPS=[0.5, 0.1])
    #process('qqZZ', 0.49785 * 139 * 1000)
