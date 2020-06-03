The scripts in this directory provide the minimum needed to generate Pythia MC events and smear them with eic-smear on the ifarm nodes using a Singularity container.  Signal MC samples can be generated separately and smeared using the same run_eicsmear.py described below.

## Open Singularity container 
See setup_jlab_singularity.txt in this directory for details

## Setup environment:
source /etc/profile

## Generate Pythia MC events for smearing (modify files in steer_pytia/ to adjust settings or number of events to generate).  
./generatePythia.csh

## Run eic-smear over LUND file input (modify Python script for your input/output filenames and paths).
python3.7 run_eicsmear.py

## The output ROOT TTrees can be analyzed via a TSelector using only ROOT (ie. outside the Singularity container on the ifarm (or on your laptop).  Example selectors can be found in the selector/ directory of this repository
 
