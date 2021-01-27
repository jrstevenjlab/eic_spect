
OLDENERGY=5_41
NEWENERGY=10_100
OLDENERGYC='41, 5'
NEWENERGYC='100, 10'

for file in {0..9}
do
  cp input.data.ep_lowQ2_${OLDENERGY}_${file}.txt input.data.ep_lowQ2_${NEWENERGY}_${file}.txt
  sed -i "s/$OLDENERGY/$NEWENERGY/g" input.data.ep_lowQ2_${NEWENERGY}_${file}.txt
  sed -i "s/$OLDENERGYC/$NEWENERGYC/g" input.data.ep_lowQ2_${NEWENERGY}_${file}.txt
done

cd /work/halld2/home/jrsteven/eic/eic_spect/ifarm/

