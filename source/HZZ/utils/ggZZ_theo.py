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
from Jing.plots.jPlt import plot_atlas_axis, plot_atlas_logo

def hinit(f, hname, rebin):
    #return f.Get(hname).merge_bins([(21, 22), (23, 24), (25, 26), (27, 28), (29, 32), (33, 36), (37, 40), (41, 44), (45, 48), (49, 61)])
    return f.Get(hname).merge_bins(rebin)

def process(rebin):
    froot = 'ggZZ-rel75'
    h = dict()
    fin = root_open(f'{froot}.root', 'r')

    h['NORM'] = hinit(fin, 'llvv__GGH__mTZZ__PFLOW', rebin)
    h['NORM'].Scale(1./h['NORM'].integral(0, -1))
    h['NORM'].linecolor = 'k'
    h['NORM'].title = 'NOMINAL'
    n = h['NORM'].GetNbinsX()

    h['rNORM'] = h['NORM'].empty_clone()
    h['rNORM'].linecolor = 'k'
    for nb in range(n):
        if h['NORM'].GetBinContent(nb+1) > 0:
            h['rNORM'].SetBinContent(nb+1, 1)

    h['QCDUP'] = h['NORM'].empty_clone()
    h['QCDDN'] = h['NORM'].empty_clone()
    for nb in range(n):
        if h['NORM'].GetBinContent(nb+1) > 0:
            h['QCDUP'].SetBinContent(nb+1, 1)
            h['QCDDN'].SetBinContent(nb+1, 1)

    for w in ['QCD55', 'QCD51', 'QCD15', 'QCD21', 'QCD12', 'QCD22']:
        hname = 'llvv__GGH__mTZZ__' + w
        h[w] = hinit(fin, hname, rebin)
        h[w].Scale( 1 / h[w].integral(0, -1))
        h[f'r{w}'] = h[w].empty_clone()
        for nb in range(n):
            norm = h['NORM'].GetBinContent(nb+1)
            if norm > 0:
                h[f'r{w}'].SetBinContent(nb+1, h[w].GetBinContent(nb+1) / norm)
                h['QCDUP'].SetBinContent(nb+1, max(h[f'r{w}'].GetBinContent(nb+1), h['QCDUP'].GetBinContent(nb+1)))
                h['QCDDN'].SetBinContent(nb+1, min(h[f'r{w}'].GetBinContent(nb+1), h['QCDDN'].GetBinContent(nb+1)))

    _up, _dn = h['QCDUP'].GetBinContent(1), h['QCDDN'].GetBinContent(1)
    h['QCDUP'].SetBinContent(1, _dn)
    h['QCDDN'].SetBinContent(1, _up)
    h['QCDUP'].Smooth()
    h['QCDDN'].Smooth()
    for nb in range(n):
        h['QCDUP'].SetBinContent(nb+1, h['QCDUP'].GetBinContent(nb+1) * h['NORM'].GetBinContent(nb+1))
        h['QCDDN'].SetBinContent(nb+1, h['QCDDN'].GetBinContent(nb+1) * h['NORM'].GetBinContent(nb+1))
    h['QCDUP'].Scale( 1 / h['QCDUP'].integral(0, -1))
    h['QCDDN'].Scale( 1 / h['QCDDN'].integral(0, -1))
    for nb in range(n):
        if h['NORM'].GetBinContent(nb+1)>0:
            h['QCDUP'].SetBinContent(nb+1, h['QCDUP'].GetBinContent(nb+1) / h['NORM'].GetBinContent(nb+1))
            h['QCDDN'].SetBinContent(nb+1, h['QCDDN'].GetBinContent(nb+1) / h['NORM'].GetBinContent(nb+1))

    config = dict()
    config['QCD55'] = {'color' : '#1f77b4', 'title' : r'$\mu_{R}=0.5, \mu_{F}=0.5$'}
    config['QCD51'] = {'color' : '#ff7f0e', 'title' : r'$\mu_{R}=0.5, \mu_{F}=1$'}
    config['QCD15'] = {'color' : '#2ca02c', 'title' : r'$\mu_{R}=1, \mu_{F}=0.5$'}
    config['QCD21'] = {'color' : '#d62728', 'title' : r'$\mu_{R}=2, \mu_{F}=1$'}
    config['QCD12'] = {'color' : '#9467bd', 'title' : r'$\mu_{R}=1, \mu_{F}=2$'}
    config['QCD22'] = {'color' : '#8c564b', 'title' : r'$\mu_{R}=2, \mu_{F}=2$'}

    fig, (ax, axr) = plt.subplots(2, figsize=(5, 5), sharex=True, gridspec_kw={'height_ratios':[3,1]})
    for key in config:
        hname = 'llvv__GGH__mTZZ__' + key
        h[key].title = config[key]['title']
        h[key].linecolor = config[key]['color']
        rplt.hist(h[key], axes = ax, zorder = -1)

        h[f'r{key}'].linecolor = config[key]['color']
        rplt.hist(h[f'r{key}'], axes = axr, zorder = -1)

    rplt.hist(h['NORM'], axes = ax, zorder = -1)
    rplt.hist(h['rNORM'], axes = axr, zorder = -1)

    ax.legend(frameon=False)
    #axr.set_ylim([0.8, 1.2])
    plot_atlas_axis(ax, xlabel='', ylabel='Event Fractions', xlim = (200, 3000), ylim=(0, 0.6))
    plot_atlas_axis(axr, xlabel=r'$m_{T}^{ZZ}$[GeV]', ylabel='QCD/NOMINAL', ylim = (0.8, 1.2), yticker = (0.2, 0.05), xlim = (200, 3000))
    plot_atlas_logo(ax, loc=[0.05, 0.90], lumi=139, info=f'Scale uncertainty {froot}', gap=0.15)
    plt.tight_layout()
    plt.savefig(froot+'_mTZZ_QCD.pdf')

    #h['QCDUP'].linecolor = 'r'
    #h['QCDDN'].linecolor = 'b'
    #h['QCDUP'].linestyle = 'dashed'
    #h['QCDDN'].linestyle = 'dashed'
    #h['QCDUP'].linewidth = 2
    #h['QCDDN'].linewidth = 2
    #rplt.hist(h['QCDUP'], axes = axr, zorder = -1)
    #rplt.hist(h['QCDDN'], axes = axr, zorder = -1)
    #dashed = h['NORM'].empty_clone()
    #dashed.linestyle = 'dashed'
    #dashed.linewidth = 2
    #dashed.title = 'Smoothed Envelope'
    #for nb in range(n): dashed.SetBinContent(nb+1, -1)
    #rplt.hist(dashed, axes = ax, zorder = -1)
    #ax.legend(frameon=False)
    #plot_atlas_axis(ax, xlabel='', ylabel='Events', xlim = (200, 3000), ylim=(0, 0.9))
    #plot_atlas_axis(axr, xlabel=r'$m_{T}^{ZZ}$[GeV]', ylabel='QCD/NOMINAL', ylim = (0.8, 1.2), yticker = (0.2, 0.05), xlim = (200, 3000))
    #plot_atlas_logo(ax, loc=[0.05, 0.90], lumi=139, info=f'Scale uncertainty {froot}', gap=0.15)
    #plt.tight_layout()
    #plt.savefig(froot+'_mTZZ_QCD_all.pdf')




    pdfs = np.zeros(n)
    for i in range(101):
        hname = 'llvv__GGH__mTZZ__PDF{}'.format(i)
        h[hname] = hinit(fin, hname, rebin)
        h[hname].Scale( 1 / h[hname].integral(0, -1))
        for nb in range(n):
            pdfs[nb] += (h[hname].GetBinContent(nb+1) - h['NORM'].GetBinContent(nb+1)) ** 2
    pdfs = np.sqrt(pdfs/100)
    h['PDFUP'] = h['NORM'].empty_clone()
    h['PDFDN'] = h['NORM'].empty_clone()
    for nb in range(n):
        h['PDFUP'].SetBinContent(nb+1, h['NORM'].GetBinContent(nb+1) + pdfs[nb])
        h['PDFDN'].SetBinContent(nb+1, h['NORM'].GetBinContent(nb+1) - pdfs[nb])

    for nb in range(n):
        if h['NORM'].GetBinContent(nb+1)>0:
            h['PDFUP'].SetBinContent(nb+1, h['PDFUP'].GetBinContent(nb+1) / h['NORM'].GetBinContent(nb+1))
            h['PDFDN'].SetBinContent(nb+1, h['PDFDN'].GetBinContent(nb+1) / h['NORM'].GetBinContent(nb+1))
    h['PDFUP'].Smooth()
    h['PDFDN'].Smooth()
    for nb in range(n):
        h['PDFUP'].SetBinContent(nb+1, h['PDFUP'].GetBinContent(nb+1) * h['NORM'].GetBinContent(nb+1))
        h['PDFDN'].SetBinContent(nb+1, h['PDFDN'].GetBinContent(nb+1) * h['NORM'].GetBinContent(nb+1))

    h['PDFUP'].Scale( 1 / h['PDFUP'].integral(0, -1))
    h['PDFDN'].Scale( 1 / h['PDFDN'].integral(0, -1))

    fig, (ax, axr) = plt.subplots(2, figsize=(5, 5), sharex=True, gridspec_kw={'height_ratios':[3,1]})
    rplt.hist(h['PDFDN'], axes = ax, zorder = -1)
    rplt.hist(h['PDFUP'], axes = ax, zorder = -1)
    rplt.hist(h['NORM'], axes = ax, zorder = -1)

    dashed = h['NORM'].empty_clone()
    dashed.linestyle = 'dashed'
    dashed.linewidth = 2
    dashed.title = 'PDF variation'
    for nb in range(n): dashed.SetBinContent(nb+1, -1)
    rplt.hist(dashed, axes = ax, zorder = -1)

    for nb in range(n):
        if h['NORM'].GetBinContent(nb+1)>0:
            h['PDFUP'].SetBinContent(nb+1, h['PDFUP'].GetBinContent(nb+1) / h['NORM'].GetBinContent(nb+1))
            h['PDFDN'].SetBinContent(nb+1, h['PDFDN'].GetBinContent(nb+1) / h['NORM'].GetBinContent(nb+1))

    h['PDFUP'].linecolor = 'r'
    h['PDFDN'].linecolor = 'b'
    h['PDFUP'].linestyle = 'dashed'
    h['PDFDN'].linestyle = 'dashed'
    h['PDFUP'].linewidth = 2
    h['PDFDN'].linewidth = 2
    rplt.hist(h['rNORM'], axes = axr, zorder = -1)
    rplt.hist(h['PDFDN'], axes = axr, zorder = -1)
    rplt.hist(h['PDFUP'], axes = axr, zorder = -1)

    ax.legend(frameon=False)
    plot_atlas_axis(ax, xlabel='', ylabel='Event Fractions', xlim = (200, 3000), ylim = (0, 0.6))
    plot_atlas_axis(axr, xlabel=r'$m_{T}^{ZZ}$[GeV]', ylabel='PDF/NOMINAL', ylim = (0.8, 1.2), yticker = (0.2, 0.05), xlim = (200, 3000))
    plot_atlas_logo(ax, loc=[0.05, 0.90], lumi=139, info=f'PDF uncertainty {froot}', gap=0.15)
    plt.tight_layout()
    plt.savefig(froot+'_mTZZ_PDF.pdf')



    h[ 'NORM-input'] = hinit(fin, 'llvv__GGH__mTZZ__PFLOW', [(21, 22), (23, 24), (25, 26), (27, 28), (29, 32), (33, 36), (37, 40), (41, 44), (45, 48), (49, 61)])
    h['QCDUP-input'] = hinit(fin, 'llvv__GGH__mTZZ__QCD12', [(21, 22), (23, 24), (25, 26), (27, 28), (29, 32), (33, 36), (37, 40), (41, 44), (45, 48), (49, 61)])
    h['QCDDN-input'] = hinit(fin, 'llvv__GGH__mTZZ__QCD15', [(21, 22), (23, 24), (25, 26), (27, 28), (29, 32), (33, 36), (37, 40), (41, 44), (45, 48), (49, 61)])
    fout = root_open(f'{froot}-input.root', 'recreate')
    h[ 'NORM-input'].Scale(1./h[ 'NORM-input'].integral(0, -1))
    h['QCDUP-input'].Scale(1./h['QCDUP-input'].integral(0, -1))
    h['QCDDN-input'].Scale(1./h['QCDDN-input'].integral(0, -1))
    h['PDFUP-input'] = h['NORM-input'].empty_clone()
    h['PDFDN-input'] = h['NORM-input'].empty_clone()
    bout = [ 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30]
    bin  = [ 1, 1, 1, 1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19,20,21,22,22,22,22]
    for _bin, _bout in zip(bin, bout):
        h['PDFUP-input'].SetBinContent(_bout, h['NORM-input'].GetBinContent(_bout) * h['PDFUP'].GetBinContent(_bin))
        h['PDFDN-input'].SetBinContent(_bout, h['NORM-input'].GetBinContent(_bout) * h['PDFDN'].GetBinContent(_bin))

    fout.cd()
    h[ 'NORM-input'].Write('ggZZ_rel75_NORM')
    h['PDFUP-input'].Write('ggZZ_rel75_PDFUP_shape')
    h['PDFDN-input'].Write('ggZZ_rel75_PDFDN_shape')
    h['QCDUP-input'].Write('ggZZ_rel75_QCDUP_shape')
    h['QCDDN-input'].Write('ggZZ_rel75_QCDDN_shape')
    fout.Close()




if __name__ == '__main__':

    rebin = [(1, 6), (21, 22), (23, 24), (25, 26), (27, 28), (29, 32), (33, 36), (37, 61)]
    process(rebin)
