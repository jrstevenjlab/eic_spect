
INDIR=/work/halld2/home/jrsteven/eic/eic_spect/ifarm/steer_pythia/
OUTDIR=/volatile/halld/home/jrsteven/eic/eic_spect/outPythiaText/
LOGDIR=$OUTDIR/log/
ENERGY=5_100
mkdir -p $LOGDIR

cd $OUTDIR
for file in {0..9}
do
  pythiaeRHIC < $INDIR/input.data.ep_lowQ2_${ENERGY}_$file.txt   > $LOGDIR/out$ENERGY.10M_$file.log &
done

cd /work/halld2/home/jrsteven/eic/eic_spect/ifarm/

