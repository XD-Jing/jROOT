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

def process():
    h = dict()
    fin = root_open(f'qqZZ-rel75.root', 'r')

    rebin_GGH = [(1, 6), (7, 8), (9, 10), (11, 12), (13, 14), (15, 16), (17, 20), (21, 26), (27, 61)]

    h['GGH-NORM'] = hinit(fin, 'llvv__GGH__mTZZ__PFLOW', rebin_GGH)
    h['GGH-NORM'].Scale(1./h['GGH-NORM'].integral(0, -1))
    h['GGH-NORM'].linecolor = 'k'
    h['GGH-NORM'].title = 'NOMINAL'
    n = h['GGH-NORM'].GetNbinsX()

    h['GGH-rNORM'] = h['GGH-NORM'].empty_clone()
    h['GGH-rNORM'].linecolor = 'k'
    for nb in range(n):
        if h['GGH-NORM'].GetBinContent(nb+1) > 0:
            h['GGH-rNORM'].SetBinContent(nb+1, 1)

    h['GGH-QCDUP'] = h['GGH-NORM'].empty_clone()
    h['GGH-QCDDN'] = h['GGH-NORM'].empty_clone()
    for nb in range(n):
        if h['GGH-NORM'].GetBinContent(nb+1) > 0:
            h['GGH-QCDUP'].SetBinContent(nb+1, 1)
            h['GGH-QCDDN'].SetBinContent(nb+1, 1)

    for w in ['QCD55', 'QCD51', 'QCD15', 'QCD21', 'QCD12', 'QCD22']:
        hname = f'llvv__GGH__mTZZ__{w}'
        h[f'GGH-{w}'] = hinit(fin, hname, rebin_GGH)
        h[f'GGH-{w}'].Scale( 1 / h[f'GGH-{w}'].integral(0, -1))
        h[f'GGH-r{w}'] = h[f'GGH-{w}'].empty_clone()
        for nb in range(n):
            norm = h['GGH-NORM'].GetBinContent(nb+1)
            if norm > 0:
                h[f'GGH-r{w}'].SetBinContent(nb+1, h[f'GGH-{w}'].GetBinContent(nb+1) / norm)
                h['GGH-QCDUP'].SetBinContent(nb+1, max(h[f'GGH-r{w}'].GetBinContent(nb+1), h['GGH-QCDUP'].GetBinContent(nb+1)))
                h['GGH-QCDDN'].SetBinContent(nb+1, min(h[f'GGH-r{w}'].GetBinContent(nb+1), h['GGH-QCDDN'].GetBinContent(nb+1)))

    _up, _dn = h['GGH-QCDUP'].GetBinContent(1), h['GGH-QCDDN'].GetBinContent(1)
    h['GGH-QCDUP'].SetBinContent(1, _dn)
    h['GGH-QCDDN'].SetBinContent(1, _up)
    h['GGH-QCDUP'].Smooth()
    h['GGH-QCDDN'].Smooth()
    for nb in range(n):
        h['GGH-QCDUP'].SetBinContent(nb+1, h['GGH-QCDUP'].GetBinContent(nb+1) * h['GGH-NORM'].GetBinContent(nb+1))
        h['GGH-QCDDN'].SetBinContent(nb+1, h['GGH-QCDDN'].GetBinContent(nb+1) * h['GGH-NORM'].GetBinContent(nb+1))
    h['GGH-QCDUP'].Scale( 1 / h['GGH-QCDUP'].integral(0, -1))
    h['GGH-QCDDN'].Scale( 1 / h['GGH-QCDDN'].integral(0, -1))
    for nb in range(n):
        if h['GGH-NORM'].GetBinContent(nb+1)>0:
            h['GGH-QCDUP'].SetBinContent(nb+1, h['GGH-QCDUP'].GetBinContent(nb+1) / h['GGH-NORM'].GetBinContent(nb+1))
            h['GGH-QCDDN'].SetBinContent(nb+1, h['GGH-QCDDN'].GetBinContent(nb+1) / h['GGH-NORM'].GetBinContent(nb+1))

    config = dict()
    config['QCD55'] = {'color' : '#1f77b4', 'title' : r'$\mu_{R}=0.5, \mu_{F}=0.5$'}
    config['QCD51'] = {'color' : '#ff7f0e', 'title' : r'$\mu_{R}=0.5, \mu_{F}=1$'}
    config['QCD15'] = {'color' : '#2ca02c', 'title' : r'$\mu_{R}=1, \mu_{F}=0.5$'}
    config['QCD21'] = {'color' : '#d62728', 'title' : r'$\mu_{R}=2, \mu_{F}=1$'}
    config['QCD12'] = {'color' : '#9467bd', 'title' : r'$\mu_{R}=1, \mu_{F}=2$'}
    config['QCD22'] = {'color' : '#8c564b', 'title' : r'$\mu_{R}=2, \mu_{F}=2$'}

    fig, (ax, axr) = plt.subplots(2, figsize=(5, 5), sharex=True, gridspec_kw={'height_ratios':[3,1]})
    for key in config:
        hname = f'llvv__GGH__mTZZ__{key}'
        h[f'GGH-{key}'].title = config[key]['title']
        h[f'GGH-{key}'].linecolor = config[key]['color']
        rplt.hist(h[f'GGH-{key}'], axes = ax, zorder = -1)

        h[f'GGH-r{key}'].linecolor = config[key]['color']
        rplt.hist(h[f'GGH-r{key}'], axes = axr, zorder = -1)

    rplt.hist(h['GGH-NORM'], axes = ax, zorder = -1)
    rplt.hist(h['GGH-rNORM'], axes = axr, zorder = -1)

    ax.legend(frameon=False)
    plot_atlas_axis(ax, xlabel='', ylabel='Event Fractions', xlim = (200, 3000), ylim=(0, 0.8))
    plot_atlas_axis(axr, xlabel=r'$m_{T}^{ZZ}$[GeV]', ylabel='QCD/NOMINAL', ylim = (0.8, 1.2), yticker = (0.2, 0.05), xlim = (200, 3000))
    plot_atlas_logo(ax, loc=[0.05, 0.90], lumi=139, info=f'Scale uncertainty qqZZ-rel75', gap=0.15)
    plt.tight_layout()
    plt.savefig('qqZZ-rel75_GGH_mTZZ_QCD.pdf')

    h['GGH-QCDUP'].linecolor = 'r'
    h['GGH-QCDDN'].linecolor = 'b'
    h['GGH-QCDUP'].linestyle = 'dashed'
    h['GGH-QCDDN'].linestyle = 'dashed'
    h['GGH-QCDUP'].linewidth = 2
    h['GGH-QCDDN'].linewidth = 2
    rplt.hist(h['GGH-QCDUP'], axes = axr, zorder = -1)
    rplt.hist(h['GGH-QCDDN'], axes = axr, zorder = -1)
    dashed = h['GGH-NORM'].empty_clone()
    dashed.linestyle = 'dashed'
    dashed.linewidth = 2
    dashed.title = 'Smoothed Envelope'
    for nb in range(n): dashed.SetBinContent(nb+1, -1)
    rplt.hist(dashed, axes = ax, zorder = -1)
    ax.legend(frameon=False)
    plot_atlas_axis(ax, xlabel='', ylabel='Event Fractions', xlim = (200, 3000), ylim=(0, 0.8))
    plot_atlas_axis(axr, xlabel=r'$m_{T}^{ZZ}$[GeV]', ylabel='QCD/NOMINAL', ylim = (0.8, 1.2), yticker = (0.2, 0.05), xlim = (200, 3000))
    plot_atlas_logo(ax, loc=[0.05, 0.90], lumi=139, info=f'Scale uncertainty qqZZ-rel75', gap=0.15)
    plt.tight_layout()
    plt.savefig('qqZZ-rel75_GGH_mTZZ_QCD_all.pdf')


    pdfs = np.zeros(n)
    for i in range(101):
        hname = f'llvv__GGH__mTZZ__PDF{i}'
        h[f'GGH-{hname}'] = hinit(fin, hname, rebin_GGH)
        h[f'GGH-{hname}'].Scale( 1 / h[f'GGH-{hname}'].integral(0, -1))
        for nb in range(n):
            pdfs[nb] += (h[f'GGH-{hname}'].GetBinContent(nb+1) - h['GGH-NORM'].GetBinContent(nb+1)) ** 2
    pdfs = np.sqrt(pdfs/100)
    h['GGH-PDFUP'] = h['GGH-NORM'].empty_clone()
    h['GGH-PDFDN'] = h['GGH-NORM'].empty_clone()
    for nb in range(n):
        h['GGH-PDFUP'].SetBinContent(nb+1, h['GGH-NORM'].GetBinContent(nb+1) + pdfs[nb])
        h['GGH-PDFDN'].SetBinContent(nb+1, h['GGH-NORM'].GetBinContent(nb+1) - pdfs[nb])
    h['GGH-PDFUP'].Scale( 1 / h['GGH-PDFUP'].integral(0, -1))
    h['GGH-PDFDN'].Scale( 1 / h['GGH-PDFDN'].integral(0, -1))

    fig, (ax, axr) = plt.subplots(2, figsize=(5, 5), sharex=True, gridspec_kw={'height_ratios':[3,1]})
    rplt.hist(h['GGH-PDFDN'], axes = ax, zorder = -1)
    rplt.hist(h['GGH-PDFUP'], axes = ax, zorder = -1)
    rplt.hist(h['GGH-NORM'], axes = ax, zorder = -1)

    dashed = h['GGH-NORM'].empty_clone()
    dashed.linestyle = 'dashed'
    dashed.linewidth = 2
    dashed.title = 'PDF variation'
    for nb in range(n): dashed.SetBinContent(nb+1, -1)
    rplt.hist(dashed, axes = ax, zorder = -1)

    for nb in range(n):
        if h['GGH-NORM'].GetBinContent(nb+1)>0:
            h['GGH-PDFUP'].SetBinContent(nb+1, h['GGH-PDFUP'].GetBinContent(nb+1) / h['GGH-NORM'].GetBinContent(nb+1))
            h['GGH-PDFDN'].SetBinContent(nb+1, h['GGH-PDFDN'].GetBinContent(nb+1) / h['GGH-NORM'].GetBinContent(nb+1))

    h['GGH-PDFUP'].linecolor = 'r'
    h['GGH-PDFDN'].linecolor = 'b'
    h['GGH-PDFUP'].linestyle = 'dashed'
    h['GGH-PDFDN'].linestyle = 'dashed'
    h['GGH-PDFUP'].linewidth = 2
    h['GGH-PDFDN'].linewidth = 2
    rplt.hist(h['GGH-rNORM'], axes = axr, zorder = -1)
    rplt.hist(h['GGH-PDFDN'], axes = axr, zorder = -1)
    rplt.hist(h['GGH-PDFUP'], axes = axr, zorder = -1)

    ax.legend(frameon=False)
    plot_atlas_axis(ax, xlabel='', ylabel='Event Fractions', xlim = (200, 3000), ylim=(0, 0.8))
    plot_atlas_axis(axr, xlabel=r'$m_{T}^{ZZ}$[GeV]', ylabel='PDF/NOMINAL', ylim = (0.8, 1.2), yticker = (0.2, 0.05), xlim = (200, 3000))
    plot_atlas_logo(ax, loc=[0.05, 0.90], lumi=139, info=f'PDF uncertainty qqZZ-rel75', gap=0.15)
    plt.tight_layout()
    plt.savefig('qqZZ-rel75_GGH_mTZZ_PDF.pdf')



    rebin_VBF = [(0, 42), (43, 54), (55, 82), (83, 171)]

    h['VBF-NORM'] = hinit(fin, 'llvv__VBF__mTZZ__PFLOW', rebin_VBF)
    h['VBF-NORM'].Scale(1./h['VBF-NORM'].integral(0, -1))
    h['VBF-NORM'].linecolor = 'k'
    h['VBF-NORM'].title = 'NOMINAL'
    n = h['VBF-NORM'].GetNbinsX()

    h['VBF-rNORM'] = h['VBF-NORM'].empty_clone()
    h['VBF-rNORM'].linecolor = 'k'
    for nb in range(n):
        if h['VBF-NORM'].GetBinContent(nb+1) > 0:
            h['VBF-rNORM'].SetBinContent(nb+1, 1)

    h['VBF-QCDUP'] = h['VBF-NORM'].empty_clone()
    h['VBF-QCDDN'] = h['VBF-NORM'].empty_clone()
    for nb in range(n):
        if h['VBF-NORM'].GetBinContent(nb+1) > 0:
            h['VBF-QCDUP'].SetBinContent(nb+1, 1)
            h['VBF-QCDDN'].SetBinContent(nb+1, 1)

    for w in ['QCD55', 'QCD51', 'QCD15', 'QCD21', 'QCD12', 'QCD22']:
        hname = f'llvv__VBF__mTZZ__{w}'
        h[f'VBF-{w}'] = hinit(fin, hname, rebin_VBF)
        h[f'VBF-{w}'].Scale( 1 / h[f'VBF-{w}'].integral(0, -1))
        h[f'VBF-r{w}'] = h[f'VBF-{w}'].empty_clone()
        for nb in range(n):
            norm = h['VBF-NORM'].GetBinContent(nb+1)
            if norm > 0:
                h[f'VBF-r{w}'].SetBinContent(nb+1, h[f'VBF-{w}'].GetBinContent(nb+1) / norm)
                h['VBF-QCDUP'].SetBinContent(nb+1, max(h[f'VBF-r{w}'].GetBinContent(nb+1), h['VBF-QCDUP'].GetBinContent(nb+1)))
                h['VBF-QCDDN'].SetBinContent(nb+1, min(h[f'VBF-r{w}'].GetBinContent(nb+1), h['VBF-QCDDN'].GetBinContent(nb+1)))

    _up, _dn = h['VBF-QCDUP'].GetBinContent(1), h['VBF-QCDDN'].GetBinContent(1)
    h['VBF-QCDUP'].SetBinContent(1, _dn)
    h['VBF-QCDDN'].SetBinContent(1, _up)
    #h['VBF-QCDUP'].Smooth()
    #h['VBF-QCDDN'].Smooth()
    for nb in range(n):
        h['VBF-QCDUP'].SetBinContent(nb+1, h['VBF-QCDUP'].GetBinContent(nb+1) * h['VBF-NORM'].GetBinContent(nb+1))
        h['VBF-QCDDN'].SetBinContent(nb+1, h['VBF-QCDDN'].GetBinContent(nb+1) * h['VBF-NORM'].GetBinContent(nb+1))
    h['VBF-QCDUP'].Scale( 1 / h['VBF-QCDUP'].integral(0, -1))
    h['VBF-QCDDN'].Scale( 1 / h['VBF-QCDDN'].integral(0, -1))
    for nb in range(n):
        if h['VBF-NORM'].GetBinContent(nb+1)>0:
            h['VBF-QCDUP'].SetBinContent(nb+1, h['VBF-QCDUP'].GetBinContent(nb+1) / h['VBF-NORM'].GetBinContent(nb+1))
            h['VBF-QCDDN'].SetBinContent(nb+1, h['VBF-QCDDN'].GetBinContent(nb+1) / h['VBF-NORM'].GetBinContent(nb+1))

    config = dict()
    config['QCD55'] = {'color' : '#1f77b4', 'title' : r'$\mu_{R}=0.5, \mu_{F}=0.5$'}
    config['QCD51'] = {'color' : '#ff7f0e', 'title' : r'$\mu_{R}=0.5, \mu_{F}=1$'}
    config['QCD15'] = {'color' : '#2ca02c', 'title' : r'$\mu_{R}=1, \mu_{F}=0.5$'}
    config['QCD21'] = {'color' : '#d62728', 'title' : r'$\mu_{R}=2, \mu_{F}=1$'}
    config['QCD12'] = {'color' : '#9467bd', 'title' : r'$\mu_{R}=1, \mu_{F}=2$'}
    config['QCD22'] = {'color' : '#8c564b', 'title' : r'$\mu_{R}=2, \mu_{F}=2$'}

    fig, (ax, axr) = plt.subplots(2, figsize=(5, 5), sharex=True, gridspec_kw={'height_ratios':[3,1]})
    for key in config:
        hname = f'llvv__VBF__mTZZ__{key}'
        h[f'VBF-{key}'].title = config[key]['title']
        h[f'VBF-{key}'].linecolor = config[key]['color']
        rplt.hist(h[f'VBF-{key}'], axes = ax, zorder = -1)

        h[f'VBF-r{key}'].linecolor = config[key]['color']
        rplt.hist(h[f'VBF-r{key}'], axes = axr, zorder = -1)

    rplt.hist(h['VBF-NORM'], axes = ax, zorder = -1)
    rplt.hist(h['VBF-rNORM'], axes = axr, zorder = -1)

    ax.legend(frameon=False)
    plot_atlas_axis(ax, xlabel='', ylabel='Event Fractions', xlim = (100, 1700), ylim = (0, 0.8))
    plot_atlas_axis(axr, xlabel=r'$m_{T}^{ZZ}$[GeV]', ylabel='QCD/NOMINAL', ylim = (0.9, 1.1), yticker = (0.1, 0.02), xlim = (100, 1700))
    plot_atlas_logo(ax, loc=[0.05, 0.90], lumi=139, info=f'Scale uncertainty qqZZ-rel75', gap=0.15)
    plt.tight_layout()
    plt.savefig('qqZZ-rel75_VBF_mTZZ_QCD.pdf')

    h['VBF-QCDUP'].linecolor = 'r'
    h['VBF-QCDDN'].linecolor = 'b'
    h['VBF-QCDUP'].linestyle = 'dashed'
    h['VBF-QCDDN'].linestyle = 'dashed'
    h['VBF-QCDUP'].linewidth = 2
    h['VBF-QCDDN'].linewidth = 2
    rplt.hist(h['VBF-QCDUP'], axes = axr, zorder = -1)
    rplt.hist(h['VBF-QCDDN'], axes = axr, zorder = -1)
    dashed = h['VBF-NORM'].empty_clone()
    dashed.linestyle = 'dashed'
    dashed.linewidth = 2
    dashed.title = 'Smoothed Envelope'
    for nb in range(n): dashed.SetBinContent(nb+1, -1)
    rplt.hist(dashed, axes = ax, zorder = -1)
    ax.legend(frameon=False)
    plot_atlas_axis(ax, xlabel='', ylabel='Event Fractions', xlim = (100, 1700), ylim = (0, 0.8))
    plot_atlas_axis(axr, xlabel=r'$m_{T}^{ZZ}$[GeV]', ylabel='QCD/NOMINAL', ylim = (0.9, 1.1), yticker = (0.1, 0.02), xlim = (100, 1700))
    plot_atlas_logo(ax, loc=[0.05, 0.90], lumi=139, info=f'Scale uncertainty qqZZ-rel75', gap=0.15)
    plt.tight_layout()
    plt.savefig('qqZZ-rel75_VBF_mTZZ_QCD_all.pdf')




    pdfs = np.zeros(n)
    for i in range(101):
        hname = f'llvv__VBF__mTZZ__PDF{i}'
        h[f'VBF-{hname}'] = hinit(fin, hname, rebin_VBF)
        h[f'VBF-{hname}'].Scale( 1 / h[f'VBF-{hname}'].integral(0, -1))
        for nb in range(n):
            pdfs[nb] += (h[f'VBF-{hname}'].GetBinContent(nb+1) - h['VBF-NORM'].GetBinContent(nb+1)) ** 2
    pdfs = np.sqrt(pdfs/100)
    h['VBF-PDFUP'] = h['VBF-NORM'].empty_clone()
    h['VBF-PDFDN'] = h['VBF-NORM'].empty_clone()
    for nb in range(n):
        h['VBF-PDFUP'].SetBinContent(nb+1, h['VBF-NORM'].GetBinContent(nb+1) + pdfs[nb])
        h['VBF-PDFDN'].SetBinContent(nb+1, h['VBF-NORM'].GetBinContent(nb+1) - pdfs[nb])
    h['VBF-PDFUP'].Scale( 1 / h['VBF-PDFUP'].integral(0, -1))
    h['VBF-PDFDN'].Scale( 1 / h['VBF-PDFDN'].integral(0, -1))

    fig, (ax, axr) = plt.subplots(2, figsize=(5, 5), sharex=True, gridspec_kw={'height_ratios':[3,1]})
    rplt.hist(h['VBF-PDFDN'], axes = ax, zorder = -1)
    rplt.hist(h['VBF-PDFUP'], axes = ax, zorder = -1)
    rplt.hist(h['VBF-NORM'], axes = ax, zorder = -1)

    dashed = h['VBF-NORM'].empty_clone()
    dashed.linestyle = 'dashed'
    dashed.linewidth = 2
    dashed.title = 'PDF variation'
    for nb in range(n): dashed.SetBinContent(nb+1, -1)
    rplt.hist(dashed, axes = ax, zorder = -1)

    for nb in range(n):
        if h['VBF-NORM'].GetBinContent(nb+1)>0:
            h['VBF-PDFUP'].SetBinContent(nb+1, h['VBF-PDFUP'].GetBinContent(nb+1) / h['VBF-NORM'].GetBinContent(nb+1))
            h['VBF-PDFDN'].SetBinContent(nb+1, h['VBF-PDFDN'].GetBinContent(nb+1) / h['VBF-NORM'].GetBinContent(nb+1))

    h['VBF-PDFUP'].linecolor = 'r'
    h['VBF-PDFDN'].linecolor = 'b'
    h['VBF-PDFUP'].linestyle = 'dashed'
    h['VBF-PDFDN'].linestyle = 'dashed'
    h['VBF-PDFUP'].linewidth = 2
    h['VBF-PDFDN'].linewidth = 2
    rplt.hist(h['VBF-rNORM'], axes = axr, zorder = -1)
    rplt.hist(h['VBF-PDFDN'], axes = axr, zorder = -1)
    rplt.hist(h['VBF-PDFUP'], axes = axr, zorder = -1)

    ax.legend(frameon=False)
    plot_atlas_axis(ax, xlabel='', ylabel='Event Fractions', xlim = (100, 1700), ylim = (0, 0.8))
    plot_atlas_axis(axr, xlabel=r'$m_{T}^{ZZ}$[GeV]', ylabel='PDF/NOMINAL', ylim = (0.9, 1.1), yticker = (0.1, 0.02), xlim = (100, 1700))
    plot_atlas_logo(ax, loc=[0.05, 0.90], lumi=139, info=f'PDF uncertainty qqZZ-rel75', gap=0.15)
    plt.tight_layout()
    plt.savefig('qqZZ-rel75_VBF_mTZZ_PDF.pdf')



    fout = root_open(f'qqZZ-rel75-input.root', 'recreate')

    h['GGH- NORM-input'] = hinit(fin, 'llvv__GGH__mTZZ__PFLOW', [(21, 22), (23, 24), (25, 26), (27, 28), (29, 32), (33, 36), (37, 40), (41, 44), (45, 48), (49, 61)])
    h['GGH- NORM-input'].Scale(1./h['GGH- NORM-input'].integral(0, -1))
    h['GGH-PDFUP-input'] = h['GGH- NORM-input'].empty_clone()
    h['GGH-PDFDN-input'] = h['GGH- NORM-input'].empty_clone()
    h['GGH-QCDUP-input'] = h['GGH- NORM-input'].empty_clone()
    h['GGH-QCDDN-input'] = h['GGH- NORM-input'].empty_clone()
    bout = [ 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30]
    bin  = [ 1, 1, 1, 1, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9]
    for _bin, _bout in zip(bin, bout):
        h['GGH-PDFUP-input'].SetBinContent(_bout, h['GGH- NORM-input'].GetBinContent(_bout) * h['GGH-PDFUP'].GetBinContent(_bin))
        h['GGH-PDFDN-input'].SetBinContent(_bout, h['GGH- NORM-input'].GetBinContent(_bout) * h['GGH-PDFDN'].GetBinContent(_bin))
        h['GGH-QCDUP-input'].SetBinContent(_bout, h['GGH- NORM-input'].GetBinContent(_bout) * h['GGH-QCDUP'].GetBinContent(_bin))
        h['GGH-QCDDN-input'].SetBinContent(_bout, h['GGH- NORM-input'].GetBinContent(_bout) * h['GGH-QCDDN'].GetBinContent(_bin))


    h['VBF- NORM-input'] = hinit(fin, 'llvv__VBF__mTZZ__PFLOW', [(0, 10), (11, 42), (43, 54), (55, 82), (83, 171)])
    h['VBF-QCDUP-input'] = hinit(fin, 'llvv__VBF__mTZZ__QCD12', [(0, 10), (11, 42), (43, 54), (55, 82), (83, 171)])
    h['VBF-QCDDN-input'] = hinit(fin, 'llvv__VBF__mTZZ__QCD15', [(0, 10), (11, 42), (43, 54), (55, 82), (83, 171)])
    h['VBF- NORM-input'].Scale(1./h['VBF- NORM-input'].integral(0, -1))
    h['VBF-QCDUP-input'].Scale(1./h['VBF-QCDUP-input'].integral(0, -1))
    h['VBF-QCDDN-input'].Scale(1./h['VBF-QCDDN-input'].integral(0, -1))
    h['VBF-PDFUP-input'] = h['VBF- NORM-input'].empty_clone()
    h['VBF-PDFDN-input'] = h['VBF- NORM-input'].empty_clone()
    bout = [ 1, 2, 3, 4, 5]
    bin  = [ 1, 1, 2, 3, 4]
    for _bin, _bout in zip(bin, bout):
        h['VBF-PDFUP-input'].SetBinContent(_bout, h['VBF- NORM-input'].GetBinContent(_bout) * h['VBF-PDFUP'].GetBinContent(_bin))
        h['VBF-PDFDN-input'].SetBinContent(_bout, h['VBF- NORM-input'].GetBinContent(_bout) * h['VBF-PDFDN'].GetBinContent(_bin))

    fout.cd()
    h['GGH- NORM-input'].Write('qqZZ_rel75_GGH_NORM')
    h['GGH-PDFUP-input'].Write('qqZZ_rel75_GGH_PDFUP_shape')
    h['GGH-PDFDN-input'].Write('qqZZ_rel75_GGH_PDFDN_shape')
    h['GGH-QCDUP-input'].Write('qqZZ_rel75_GGH_QCDUP_shape')
    h['GGH-QCDDN-input'].Write('qqZZ_rel75_GGH_QCDDN_shape')

    h['VBF- NORM-input'].Write('qqZZ_rel75_VBF_NORM')
    h['VBF-PDFUP-input'].Write('qqZZ_rel75_VBF_PDFUP_shape')
    h['VBF-PDFDN-input'].Write('qqZZ_rel75_VBF_PDFDN_shape')
    h['VBF-QCDUP-input'].Write('qqZZ_rel75_VBF_QCDUP_shape')
    h['VBF-QCDDN-input'].Write('qqZZ_rel75_VBF_QCDDN_shape')

    fout.Close()




if __name__ == '__main__':
    process()
