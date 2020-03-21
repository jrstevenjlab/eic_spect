//
//  runSelector.c
//  
//
//  Created by Justin Stevens on 3/18/20.
//

void runSelector(TString input_name = "10_100") {
    
    TFile *file;
    TTree *tree;
    TString detectors[3] = {"jleic", "beast", "ephenix"};
    
    // process data from each detector in series
    for(int i=0; i<3; i++) {
        cout<<"Processing detector: "<<detectors[i].Data()<<endl;
        file = TFile::Open(Form("outTree/zc_sm%s_%s.root", detectors[i].Data(), input_name.Data()));
        gDirectory->cd("events");
        //gDirectory->ls();
        tree = (TTree*)gDirectory->Get("tree");
        tree->Process("selector_zc.C",detectors[i]+"_"+input_name);
    }
            
    return;
}
