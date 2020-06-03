
INDIR=/work/halld2/home/jrsteven/eic/eic_spect/ifarm/steer_pythia/
OUTDIR=/volatile/halld/home/jrsteven/eic/eic_spect/outTree/
LOGDIR=$OUTDIR/log/

cd $OUTDIR
pythiaeRHIC < $INDIR/input.data.ep_lowQ2.5_41.txt   > $LOGDIR/out5_41.10M.log
pythiaeRHIC < $INDIR/input.data.ep_lowQ2.5_100.txt  > $LOGDIR/out5_100.10M.log
pythiaeRHIC < $INDIR/input.data.ep_lowQ2.10_100.txt > $LOGDIR/out10_100.10M.log
pythiaeRHIC < $INDIR/input.data.ep_lowQ2.18_275.txt > $LOGDIR/out18_275.10M.log

cd /work/halld2/home/jrsteven/eic/eic_spect/ifarm/
