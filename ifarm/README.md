
# Open Singularity container (see setup_jlab_singularity.txt)
# Setup environment:
source /etc/profile

# Run eic-smear over LUND file input (modify Python script for your input/output filenames and paths)
python3.7 run_eicsmear.py

# The output ROOT TTrees can be analyzed via a TSelector using only ROOT (ie. outside the Singularity container on the ifarm (or on your laptop).  Example selectors can be found in the selector/ directory of this repository
 
