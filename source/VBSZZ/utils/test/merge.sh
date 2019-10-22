cp data.root ../data.root
cp Data_dd.root ../Data_dd.root
cp NonRes.root ../NonRes.root
cp ZJet.root ../ZJet.root
cp NonRes_dd.root ../NonRes_dd.root
hadd -f ../EWK.root EWK*root
hadd -f ../qqZZ.root qqZZ*root
hadd -f ../ggZZ.root ggZZ*root
hadd -f ../WZ.root WZ*root
hadd -f ../Other.root Other*root
hadd -f ../ZZ4l.root ZZ4l*root
