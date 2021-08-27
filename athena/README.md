# ATHENA software 
* documented here https://ip6soft.readthedocs.io/en/latest/index.html
* best to use signularity container to obtain necessary libraries to analyze ROOT trees

# some preliminary data files can be found at
* https://dtn01.sdcc.bnl.gov:9000/minio/eictest/ATHENA/RECO/master/SPECTROSCOPY/
* however, these files are changing regulary, so not guaranteed to always be available...

# openS3.C 
* opens file from S3 line above (only ROOT required), can run without ATHENA software anywhere
* need to set environment variables in `setup.sh` to have permission at S3

# exampleMass.C 
* based on tutorial 
https://eic.phy.anl.gov/tutorials/eic_tutorial/part5/reconstruction_analysis
* plot mass of J/psi pi+ pi- from generated and reconstructed particles