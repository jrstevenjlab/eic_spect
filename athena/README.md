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
