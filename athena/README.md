# elSpectro Generator for X, Y, Psi(2S) generated events with decay to J/psi pi+ pi-
* https://github.com/dglazier/elSpectro
* Some description in a [recent talk by Derek](https://indico.bnl.gov/event/11669/contributions/50919/attachments/36099/59218/PSQatEICJuly21Glazier.pdf)

# ATHENA software 
* documented here https://ip6soft.readthedocs.io/en/latest/index.html
* best to use [container](https://ip6soft.readthedocs.io/en/latest/overview/containers.html) if you want to use libraries.
* singularity available on JLab and BNL clusters, but can install locally as well (I haven't tried)

# Some preliminary data files can be found at
* Version 0: eictest/ATHENA/RECO/master/SPECTROSCOPY/
* Version 1 (Nov 4): eictest/ATHENA/RECO/canyonlands-v1.2/EXCLUSIVE/SPECTROSCOPY_ABCONV
* however, these files are changing regulary, so not guaranteed to always be available...

# openS3.C 
* opens file from S3 line above. Only ROOT required, can run without ATHENA software anywhere
* need to set environment variables in `setup.sh` to have permission at S3

# exampleMass.C 
* requires ATHENA libraries, works with singularity container
* based on tutorial 
https://eic.phy.anl.gov/tutorials/eic_tutorial/part5/reconstruction_analysis
* plot mass of J/psi pi+ pi- from generated and reconstructed particles

# Exercises (1st round): produce histograms for both psi(2s) and X(3872) files using all available files
## Study kinematic histograms of both J/psi decay leptons and charged pions (generated and reconstructed):
* momentum vs pseudorapidity eta
* momentum vs polar angle theta
* transverse momentum vs pseudorapdity eta
* azimuthal angle phi vs eta
## Study effieciencies by taking ratio of reconstructed/generated for individual final state particles
* efficiency vs momentum, transverse momentum, pseudorapidity, phi
* plot efficiencies on lineary y-axis with range efficiency = 0.0 - 1.1
  * check the errors on the efficiency are computed correctly using the sum of weights squared (TH1::Sumw2())
## Study mass resolution for J/psi
* fill histogram with difference: reconstructed mass - generated mass for decay J/psi -> e+e-
  * fit histogram to obtain mass resolution for J/psi
* bonus points: study dependence of mass resolution on momentum or pseudorapidity of lepton or pion tracks
  * fill 2D histogram with difference: reconstructed mass - generated mass vs momentum or pseudorapidity
  * plot mass resolution (sigma) vs momentum or pseudorapidity:
    * fit slices of 2D histograms and plot mass resolution (sigma) vs momentum or pseudorapidity
    * compute standard deviation directly from histogram slices vs momentum or pseudorapidity

# Exercises (2nd round): produce histograms for both psi(2s) and X(3872) files using all available files
## Study efficiencies and mass resolution with additional requirements
* add a cut on transverse momentum > 0.1 GeV and |eta| < 3 for all tracks
* plot the efficiency and mass resolution for events surviving these cuts
  * plot efficiencies on lineary y-axis with range efficiency = 0.0 - 1.1
