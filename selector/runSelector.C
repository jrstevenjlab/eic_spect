//
//  runSelector.C
//  
//
//  Created by Justin Stevens on 3/18/20.
//

void runSelector(TString input_dir = "/volatile/halld/home/jrsteven/eic/eic_spect/outTree/") { 
    
    TFile *file;
    TTree *tree;
    TString sample[2] = {"zc_pythia","ep_lowQ2"};
    TString detectors[4] = {"handbook", "smjleic", "smbeast", "smephenix"};
    TString energies[4] = {"5_41", "5_100", "10_100", "18_275"};

    // process data from each detector in series
    for(int i=0; i<1; i++) { //detectors: 4 
        for(int j=0; j<4; j++) { //energies: 4 
	    for(int k=0; k<2; k++) { //samples: 2
                TString input_name = energies[j];
                
                cout<<"Processing sample "<<sample[k]<<" with "<<detectors[i].Data()<<" detector at "<<input_name.Data()<<endl;
		TString filename = Form("%s/%s_%s_%s.root", input_dir.Data(),sample[k].Data(), detectors[i].Data(), input_name.Data());
                file = TFile::Open(filename);
                if(!file) {
			cout<<"can't find file: "<<filename<<endl;
			continue;
		}
                
                gDirectory->cd("events");
                tree = (TTree*)gDirectory->Get("tree");
                tree->Process("selector_zc.C",sample[k]+"_"+detectors[i]+"_"+input_name);
            }
        }
    }
            
    return;
}
