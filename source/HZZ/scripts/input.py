#!/usr/bin/env python

from rootpy.io import root_open
from rootpy.plotting import Hist


def normalize(hist):
    hist.Scale(1./hist.integral(0, -1))

with root_open('ggZZ_input.root', 'recreate') as fout:
    h = dict()
    with root_open('ggZZ.root', 'r') as fin:
        def hinit(hname):
            return fin.Get(hname).merge_bins([(21, 22), (23, 24), (25, 26), (27, 28), (29, 32), (33, 36), (37, 40), (41, 44), (45, 48), (49, 61)])

        h['NOMINAL_llvv'] = hinit('llvv___GGH__mTZZ__NOMINAL')
        h['NOMINAL_eevv'] = hinit('llvv__ee___GGH__mTZZ__NOMINAL')
        h['NOMINAL_mmvv'] = hinit('llvv__mm___GGH__mTZZ__NOMINAL')
        normalize(h['NOMINAL_llvv'])
        normalize(h['NOMINAL_eevv'])
        normalize(h['NOMINAL_mmvv'])

        h['QCD_SHAPE_llvv'] = hinit('llvv___GGH__mTZZ__QCD15')
        h['QCD_SHAPE_eevv'] = hinit('llvv__ee___GGH__mTZZ__QCD15')
        h['QCD_SHAPE_mmvv'] = hinit('llvv__mm___GGH__mTZZ__QCD15')
        normalize(h['QCD_SHAPE_llvv'])
        normalize(h['QCD_SHAPE_eevv'])
        normalize(h['QCD_SHAPE_mmvv'])


        h['PDF_SHAPE_llvv'] = hinit('llvv___GGH__mTZZ__PDF15')
        h['PDF_SHAPE_eevv'] = hinit('llvv__ee___GGH__mTZZ__PDF15')
        h['PDF_SHAPE_mmvv'] = hinit('llvv__mm___GGH__mTZZ__PDF15')
        normalize(h['PDF_SHAPE_llvv'])
        normalize(h['PDF_SHAPE_eevv'])
        normalize(h['PDF_SHAPE_mmvv'])


        h['PS_SHAPE_llvv'] = hinit('llvv___GGH__mTZZ__QSF025')
        h['PS_SHAPE_eevv'] = hinit('llvv__ee___GGH__mTZZ__QSF025')
        h['PS_SHAPE_mmvv'] = hinit('llvv__mm___GGH__mTZZ__QSF025')
        normalize(h['PS_SHAPE_llvv'])
        normalize(h['PS_SHAPE_eevv'])
        normalize(h['PS_SHAPE_mmvv'])


        fout.cd()
        for key in h:
            h[key].Write(key)



with root_open('qqZZ_input.root', 'recreate') as fout:
    h = dict()
    with root_open('qqZZ.root', 'r') as fin:
        def hinit(hname):
            return fin.Get(hname).merge_bins([(21, 22), (23, 24), (25, 26), (27, 28), (29, 32), (33, 36), (37, 40), (41, 44), (45, 48), (49, 61)])

        h['NOMINAL_llvv'] = hinit('llvv___GGH__mTZZ__NOMINAL')
        h['NOMINAL_eevv'] = hinit('llvv__ee___GGH__mTZZ__NOMINAL')
        h['NOMINAL_mmvv'] = hinit('llvv__mm___GGH__mTZZ__NOMINAL')
        normalize(h['NOMINAL_llvv'])
        normalize(h['NOMINAL_eevv'])
        normalize(h['NOMINAL_mmvv'])

        h['QCD_SHAPE_llvv'] = hinit('llvv___GGH__mTZZ__QCD55')
        h['QCD_SHAPE_eevv'] = hinit('llvv__ee___GGH__mTZZ__QCD55')
        h['QCD_SHAPE_mmvv'] = hinit('llvv__mm___GGH__mTZZ__QCD55')
        normalize(h['QCD_SHAPE_llvv'])
        normalize(h['QCD_SHAPE_eevv'])
        normalize(h['QCD_SHAPE_mmvv'])


        h['PDF_SHAPE_llvv'] = hinit('llvv___GGH__mTZZ__PDF15')
        h['PDF_SHAPE_eevv'] = hinit('llvv__ee___GGH__mTZZ__PDF15')
        h['PDF_SHAPE_mmvv'] = hinit('llvv__mm___GGH__mTZZ__PDF15')
        normalize(h['PDF_SHAPE_llvv'])
        normalize(h['PDF_SHAPE_eevv'])
        normalize(h['PDF_SHAPE_mmvv'])


        h['PS_SHAPE_llvv'] = hinit('llvv___GGH__mTZZ__QSF4')
        h['PS_SHAPE_eevv'] = hinit('llvv__ee___GGH__mTZZ__QSF4')
        h['PS_SHAPE_mmvv'] = hinit('llvv__mm___GGH__mTZZ__QSF4')
        normalize(h['PS_SHAPE_llvv'])
        normalize(h['PS_SHAPE_eevv'])
        normalize(h['PS_SHAPE_mmvv'])


        fout.cd()
        for key in h:
            h[key].Write(key)
