# Process event text files in LUND format through eic-smear
# Choose file_name to match names for Pythia (ep_lowQ2), Z_C(3900), or other user defined input

from pyjano.jana import Jana

#file_name = "ep_lowQ2" # Inclusive e+p events in Pythia LUND format
file_name = "zc_pythia" # Z_C(3900) in Pythia LUND format

detector_name = "handbook" # Handbook detector specificiations
energies = ["5_41","5_100","10_100","18_275"] # Eelectron_Eproton

# User-defined input and output directores
indir = "/volatile/halld/home/jrsteven/eic/eic_spect/outText/"
outdir = "/volatile/halld/home/jrsteven/eic/eic_spect/outTree/"

for energy in energies:

	Jana().plugin('lund_reader')\
      		.plugin('event_writer')\
      		.plugin('eic_smear', detector=detector_name)\
      		.plugin('jana', nevents=10000000, nthreads=4, output='%s/%s_%s_%s.root' % (outdir,file_name,detector_name,energy))\
      		.source('%s/%s_%s.txt' % (indir,file_name,energy))\
      		.run()
