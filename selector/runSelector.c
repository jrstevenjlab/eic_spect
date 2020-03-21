//
//  runSelector.C
//  
//
//  Created by Justin Stevens on 3/18/20.
//

void runSelector() {
    
    TFile *file;
    TTree *tree;
    TString detectors[3] = {"jleic", "beast", "ephenix"};
    TString energies[4] = {"5_41", "5_100", "10_100", "18_275"};
    
    // process data from each detector in series
    for(int i=0; i<3; i++) {
        for(int j=0; j<4; j++) {
            TString input_name = energies[j];
            
            cout<<"Processing detector: "<<detectors[i].Data()<<" at "<<input_name.Data()<<endl;
            file = TFile::Open(Form("../outTree/zc_sm%s_%s.root", detectors[i].Data(), input_name.Data()));
            gDirectory->cd("events");
            //gDirectory->ls();
            tree = (TTree*)gDirectory->Get("tree");
            tree->Process("selector_zc.C",detectors[i]+"_"+input_name);
        }
    }
            
    return;
}
