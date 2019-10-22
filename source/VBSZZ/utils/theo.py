#!/usr/bin/env python

from rootpy.io import root_open
import numpy as np

with root_open('hist_EWK.root', 'recreate') as fout:
    QCDUP, QCDDN = np.zeros(5), np.zeros(5)
    PDFUP, PDFDN = np.zeros(5), np.zeros(5)
    with root_open('EWK.root', 'r') as fin:
        NOMI = fin.Get('llvv__2lSR__BDT__NOMINAL').merge_bins([(1,4),(5,8),(9,12),(13,15),(16,20)])

        for nb in range(5):
            QCDUP[nb] = NOMI.GetBinContent(nb+1)
            QCDDN[nb] = NOMI.GetBinContent(nb+1)
        for i in [55, 15, 51, 12, 21, 22]:
            h = fin.Get('llvv__2lSR__BDT__QCD{}'.format(i)).merge_bins([(1,4),(5,8),(9,12),(13,15),(16,20)])

            for nb in range(5):
                QCDUP[nb] = max(QCDUP[nb], h.GetBinContent(nb+1))
                QCDDN[nb] = min(QCDDN[nb], h.GetBinContent(nb+1))

        for i in range(100):
            h = fin.Get('llvv__2lSR__BDT__PDF{}'.format(i)).merge_bins([(1,4),(5,8),(9,12),(13,15),(16,20)])

            for nb in range(5):
                PDFUP[nb] += (NOMI.GetBinContent(nb+1) - h.GetBinContent(nb+1)) ** 2
                PDFDN[nb] += (NOMI.GetBinContent(nb+1) - h.GetBinContent(nb+1)) ** 2

        fout.cd()
        h = [NOMI.empty_clone(), NOMI.empty_clone(),NOMI.empty_clone(),NOMI.empty_clone()]
        for nb in range(5):
            norm = NOMI.GetBinContent(nb+1)
            h[0].SetBinContent(nb+1, QCDUP[nb])
            h[1].SetBinContent(nb+1, QCDDN[nb])
            h[2].SetBinContent(nb+1, norm + np.sqrt(PDFUP[nb] / 100))
            h[3].SetBinContent(nb+1, norm - np.sqrt(PDFUP[nb] / 100))

        fout.cd()
        h[0].Write('qcd_up')
        h[1].Write('qcd_dn')
        h[2].Write('pdf_up')
        h[3].Write('pdf_dn')
