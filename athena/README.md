# elSpectro Generator for X, Y, Psi(2S) generated events with decay to J/psi pi+ pi-
* https://github.com/dglazier/elSpectro
* Some description in a [recent talk by Derek](https://indico.bnl.gov/event/11669/contributions/50919/attachments/36099/59218/PSQatEICJuly21Glazier.pdf)

# ATHENA software 
* documented here https://ip6soft.readthedocs.io/en/latest/index.html
* best to use [container](https://ip6soft.readthedocs.io/en/latest/overview/containers.html) if you want to use libraries.
* singularity available on JLab and BNL clusters, but can install locally as well (I haven't tried)

# some preliminary data files can be found at
* https://dtn01.sdcc.bnl.gov:9000/minio/eictest/ATHENA/RECO/master/SPECTROSCOPY/
* however, these files are changing regulary, so not guaranteed to always be available...

# openS3.C 
* opens file from S3 line above. Only ROOT required, can run without ATHENA software anywhere
* need to set environment variables in `setup.sh` to have permission at S3

# exampleMass.C 
* requires ATHENA libraries, works with singularity container
* based on tutorial 
https://eic.phy.anl.gov/tutorials/eic_tutorial/part5/reconstruction_analysis
* plot mass of J/psi pi+ pi- from generated and reconstructed particles

# Exercises (sorry these are very late)
## Produce kinematic histograms of both J/psi decay leptons and charged pions
* momentum vs pseudorapidity eta
* momentum vs polar angle theta
* transverse momentum vs pseudorapdity eta
* azimuthal angle phi vs eta
## Produce mass resolution plots for J/psi
* fill histogram with reconstructed - generated mass for decay leptons
* fit histogram to obtain mass resolution for J/psi
* bonus points: study dependence of mass resolution on momentum or pseudorapidity of lepton tracks, 
