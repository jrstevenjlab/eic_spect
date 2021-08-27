
void openS3() {

  TFile *file = TFile::Open("s3https://dtn01.sdcc.bnl.gov:9000/eictest/ATHENA/RECO/master/SPECTROSCOPY/psi2s_10_100.0001.root");
  TTree *tree = (TTree*)file->Get("events");
 
  tree->Draw("mcparticles2.ps.y:mcparticles2.ps.x>>h2(100,-10,10,100,-10,10)","","colz");

}
