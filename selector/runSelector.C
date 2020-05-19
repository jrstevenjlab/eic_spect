//
//  runSelector.C
//  
//
//  Created by Justin Stevens on 3/18/20.
//

void runSelector(TString input_dir = "/volatile/halld/home/jrsteven/eic/eic_spect/outTree/") { 
    
    TFile *file;
    TTree *tree;
    TString sample[2] = {"zc","pythia"};
    TString detectors[4] = {"nosm", "smjleic", "smbeast", "smephenix"};
    TString energies[4] = {"5_41", "5_100", "10_100", "18_275"};
    
    // process data from each detector in series
    for(int i=0; i<1; i++) { //3
	    for(int j=0; j<1; j++) { //4
		    for(int k=0; k<1; k++) { //2
                TString input_name = energies[j];
                
                cout<<"Processing detector: "<<detectors[i].Data()<<" at "<<input_name.Data()<<endl;
                file = TFile::Open(Form("%s/%s_sm%s_%s.root", input_dir.Data(),sample[k].Data(), detectors[i].Data(), input_name.Data()));
                if(!file) continue;
                
                gDirectory->cd("events");
                //gDirectory->ls();
                tree = (TTree*)gDirectory->Get("tree");
                tree->Process("selector_zc.C",sample[k]+"_"+detectors[i]+"_"+input_name);
            }
        }
    }
            
    return;
}
