The scripts in this directory provide the minimum needed to generate XYZ events with the elSpectro generator and smear them with eic-smear on the ifarm nodes using a Singularity container.

## Install elSpectro on ifarm (modify to set path to build location)
source build_jlab_elspectro.csh

## Run example (see elSpectro README)
cd $ELSPECTRO/examples/  
../bin/elspectro 'EIC_JPAC_nZc_Hists.C("low",5,41,1E33,25)'  

## Open Singularity container 
module load singularity  
singularity shell --cleanenv /cvmfs/eic.opensciencegrid.org/singularity/escalate:latest  

## Setup environment:
source /etc/profile

## Run eic-smear over LUND file input (modify Python script for your input/output filenames and paths).
python3.7 run_eicsmear_HEPMC3.py

## The output ROOT TTrees can be analyzed via a TSelector using only ROOT (ie. outside the Singularity container on the ifarm (or on your laptop).  Example selectors can be found in the selector/ directory of this repository
 
