# Process event text files in HEPMC format through eic-smear
# Choose file_name to match names for Z_C(3900) or other user defined input from elspectro

from pyjano.jana import Jana

file_name = "jpac_Zc3900_low" # Z_C(3900) in HepMC3 format

detector_name = "handbook" # Handbook detector specificiations
energies = ["5_41","5_100","10_100","18_275"] # Eelectron_Eproton

# User-defined input and output directores
indir = "/volatile/halld/home/jrsteven/eic/eic_spect/outHepMC3Text/"
outdir = "/volatile/halld/home/jrsteven/eic/eic_spect/outHepMC3Tree/"

for energy in energies:

	Jana().plugin('hepmc_reader', hepmc_version=3)\
      		.plugin('event_writer')\
      		.plugin('eic_smear', detector=detector_name)\
      		.plugin('jana', nevents=10000000, nthreads=4, output='%s/%s_%s_%s.root' % (outdir,file_name,detector_name,energy))\
      		.source('%s/%s_%s.txt' % (indir,file_name,energy))\
      		.run()
