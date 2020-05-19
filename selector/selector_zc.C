#define selector_zc_cxx
// The class definition in selector_zc.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("selector_zc.C")
// root> T->Process("selector_zc.C","some options")
// root> T->Process("selector_zc.C+")
//

#include "selector_zc.h"
#include <TH2.h>
#include <TStyle.h>


void selector_zc::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

    TString option = GetOption();
    fOutputFile = new TFile(Form("../outHist/output_%s.root",option.Data()),"recreate");
    
    hPVsEtaEle = new TH2F("PVsEtaEle", "; #eta; p (GeV)", 120, -1, 5, 100, 0, 20);
    hPVsEtaPos = new TH2F("PVsEtaPos", "; #eta; p (GeV)", 120, -1, 5, 100, 0, 20);
    hPVsEtaPion = new TH2F("PVsEtaPion", "; #eta; p (GeV)", 120, -1, 5, 100, 0, 20);
    
    hDeltaPOverPVsEtaEle = new TH2F("DeltaPOverPVsEtaEle", "; #eta; #Delta p/p", 120, -1, 5, 100, -0.1, 0.1);
    hDeltaPOverPVsEtaPos = new TH2F("DeltaPOverPVsEtaPos", "; #eta; #Delta p/p", 120, -1, 5, 100, -0.1, 0.1);
    hDeltaPOverPVsEtaPion = new TH2F("DeltaPOverPVsEtaPion", "; #eta; #Delta p/p", 120, -1, 5, 100, -0.1, 0.1);
    
    hMapEle = new TH2F("MapEle", "; #theta (rad); momentum (GeV)", 720, 0, 2*TMath::Pi(), 40, 0, 80);
    hMapPos = new TH2F("MapPos", "; #theta (rad); momentum (GeV)", 720, 0, 2*TMath::Pi(), 40, 0, 80);
    hMapPion = new TH2F("MapPion", "; #theta (rad); momentum (GeV)", 720, 0, 2*TMath::Pi(), 40, 0, 80);
    
    hMassElePos = new TH1F("MassElePos", "; M_{ee} (GeV)", 350, 0.0, 3.5);
    hMassJpsiPion = new TH1F("MassJpsiPion", "; M_{J/#psi#pi} (GeV)", 450, 0.0, 4.5);
}

void selector_zc::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t selector_zc::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either selector_zc::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the data. When processing
   // keyed objects with PROOF, the object is already loaded and is available
   // via the fObject pointer.
   //
   // This function should contain the "body" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.

    GetEntry(entry);
    //cout<<evt_id<<" "<<evt_prt_count<<" "<<pdg[0]<<endl;
    
    TLorentzVector P4Pion, P4Ele, P4Pos, P4Jpsi, P4Zc;
    TLorentzVector P4PionThrown, P4EleThrown, P4PosThrown, P4JpsiThrown, P4ZcThrown;

    int ndetected_ele = 0;
    int ndetected_pos = 0;
    int ndetected_pion = 0;
    
    for(int i=0; i<evt_prt_count; i++) {
        //cout<<pdg[i]<<endl;
        TLorentzVector P4, P4Thrown;
        P4.SetXYZM(px[i],py[i],pz[i],m[i]);
        P4Thrown.SetXYZM(smear_orig_px[i],smear_orig_py[i],smear_orig_pz[i],m[i]);
        if(abs(pdg[i]) == 11) {
            if(charge[i] == -1) {
                ndetected_ele++;
                P4Ele = P4;
                P4EleThrown = P4Thrown;
            }
            if(charge[i] == +1) {
                ndetected_pos++;
                P4Pos = P4;
                P4PosThrown = P4Thrown;
            }
        }
        if(pdg[i] == 211) {
            ndetected_pion++;
            P4Pion = P4;
            P4PionThrown = P4Thrown;
        }
    }
    
    // require 3 detected
    if(ndetected_ele < 1 || ndetected_pos < 1 || ndetected_pion < 1)
        return kTRUE;
    
    // observed lab frame distributions
    hPVsEtaEle->Fill(P4Ele.Eta(),P4Ele.Vect().Mag());
    hPVsEtaPos->Fill(P4Pos.Eta(),P4Pos.Vect().Mag());
    hPVsEtaPion->Fill(P4Pion.Eta(),P4Pion.Vect().Mag());

    // observed thrown maps
    hPolarMapEle->Fill(P4Ele.Vect().Mag(),P4Ele.Theta());
    
    if(P4Ele.Theta() < 3.0) // skip beam electrons
        hMapEle->Fill(P4Ele.Theta(), P4Ele.Vect().Mag());
    hMapPos->Fill(P4Pos.Theta(), P4Pos.Vect().Mag());
    hMapPion->Fill(P4Pion.Theta(), P4Pion.Vect().Mag());
    
    // single particle resolutions
    double DeltaPOverP_Ele = (P4Ele.Vect().Mag() - P4EleThrown.Vect().Mag())/P4EleThrown.Vect().Mag();
    double DeltaPOverP_Pos = (P4Pos.Vect().Mag() - P4PosThrown.Vect().Mag())/P4PosThrown.Vect().Mag();
    double DeltaPOverP_Pion = (P4Pion.Vect().Mag() - P4PionThrown.Vect().Mag())/P4PionThrown.Vect().Mag();
    
    hDeltaPOverPVsEtaEle->Fill(P4EleThrown.Eta(),DeltaPOverP_Ele);
    hDeltaPOverPVsEtaPos->Fill(P4PosThrown.Eta(),DeltaPOverP_Pos);
    hDeltaPOverPVsEtaPion->Fill(P4PionThrown.Eta(),DeltaPOverP_Pion);
    
    P4Jpsi = P4Ele + P4Pos;
    P4Zc = P4Jpsi + P4Pion;
    
    hMassElePos->Fill(P4Jpsi.M());
    if(fabs(P4Jpsi.M() - 3.1) > 0.2) return kTRUE;
    hMassJpsiPion->Fill(P4Zc.M());
    
   return kTRUE;
}

void selector_zc::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void selector_zc::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

    hPVsEtaEle->Write(); hPVsEtaPos->Write(); hPVsEtaPion->Write();
    hDeltaPOverPVsEtaEle->Write();
    hDeltaPOverPVsEtaPos->Write();
    hDeltaPOverPVsEtaPion->Write();
    
    hMapEle->Write(); hMapPos->Write(); hMapPion->Write();
    
    hMassElePos->Write();
    hMassJpsiPion->Write();
    
    fOutputFile->Close();
}
