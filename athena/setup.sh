# Load singularity containter
module load singularity
singularity run /cvmfs/singularity.opensciencegrid.org/eicweb/jug_xl:4.0-acadia-stable

# Once inside container setup environment
eic-shell
export S3_ACCESS_KEY=eicS3read
export S3_SECRET_KEY=eicS3read
