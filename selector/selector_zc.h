//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Mar 18 10:01:48 2020 by ROOT version 6.16/00
// from TTree tree/a tree with all the events
// found on file: zc_smjleic.root
//////////////////////////////////////////////////////////

#ifndef selector_zc_h
#define selector_zc_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

// Header file for the classes stored in the TTree if any.

class selector_zc : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   TFile          *fOutputFile;
    
// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   ULong64_t       evt_id;
   Double_t        evt_true_q2;
   Double_t        evt_true_x;
   Double_t        evt_true_y;
   Double_t        evt_true_w2;
   Double_t        evt_true_nu;
   Char_t          evt_has_dis_info;
   ULong64_t       evt_prt_count;
   Double_t        evt_weight;
   ULong64_t       id[100];   //[evt_prt_count]
   Long64_t        pdg[100];   //[evt_prt_count]
   Double_t        trk_id[100];   //[evt_prt_count]
   Double_t        charge[100];   //[evt_prt_count]
   Double_t        dir_x[100];   //[evt_prt_count]
   Double_t        dir_y[100];   //[evt_prt_count]
   Double_t        dir_z[100];   //[evt_prt_count]
   Double_t        p[100];   //[evt_prt_count]
   Double_t        px[100];   //[evt_prt_count]
   Double_t        py[100];   //[evt_prt_count]
   Double_t        pz[100];   //[evt_prt_count]
   Double_t        tot_e[100];   //[evt_prt_count]
   Double_t        m[100];   //[evt_prt_count]
   Double_t        time[100];   //[evt_prt_count]
   Bool_t          is_beam[100];   //[evt_prt_count]
   Bool_t          is_stable[100];   //[evt_prt_count]
   Bool_t          gen_code[100];   //[evt_prt_count]
   ULong64_t       mother_id[100];   //[evt_prt_count]
   ULong64_t       mother_second_id[100];   //[evt_prt_count]
   Double_t        has_pol_info[100];   //[evt_prt_count]
   Double_t        pol_x[100];   //[evt_prt_count]
   Double_t        pol_y[100];   //[evt_prt_count]
   Double_t        pol_z[100];   //[evt_prt_count]
   Bool_t          has_vtx_info[100];   //[evt_prt_count]
   ULong64_t       vtx_id[100];   //[evt_prt_count]
   Double_t        vtx_x[100];   //[evt_prt_count]
   Double_t        vtx_y[100];   //[evt_prt_count]
   Double_t        vtx_z[100];   //[evt_prt_count]
   Double_t        vtx_t[100];   //[evt_prt_count]
   Bool_t          has_smear_info[100];   //[evt_prt_count]
   Bool_t          smear_has_e[100];   //[evt_prt_count]
   Bool_t          smear_has_p[100];   //[evt_prt_count]
   Bool_t          smear_has_pid[100];   //[evt_prt_count]
   Bool_t          smear_has_vtx[100];   //[evt_prt_count]
   Bool_t          smear_has_any_eppid[100];   //[evt_prt_count]
   Double_t        smear_orig_tot_e[100];   //[evt_prt_count]
   Double_t        smear_orig_p[100];   //[evt_prt_count]
   Double_t        smear_orig_px[100];   //[evt_prt_count]
   Double_t        smear_orig_py[100];   //[evt_prt_count]
   Double_t        smear_orig_pz[100];   //[evt_prt_count]
   Double_t        smear_orig_vtx_x[100];   //[evt_prt_count]
   Double_t        smear_orig_vtx_y[100];   //[evt_prt_count]
   Double_t        smear_orig_vtx_z[100];   //[evt_prt_count]

   // List of branches
   TBranch        *b_evt_id;   //!
   TBranch        *b_evt_true_q2;   //!
   TBranch        *b_evt_true_x;   //!
   TBranch        *b_evt_true_y;   //!
   TBranch        *b_evt_true_w2;   //!
   TBranch        *b_evt_true_nu;   //!
   TBranch        *b_evt_has_dis_info;   //!
   TBranch        *b_evt_prt_count;   //!
   TBranch        *b_evt_weight;   //!
   TBranch        *b_id;   //!
   TBranch        *b_pdg;   //!
   TBranch        *b_trk_id;   //!
   TBranch        *b_charge;   //!
   TBranch        *b_dir_x;   //!
   TBranch        *b_dir_y;   //!
   TBranch        *b_dir_z;   //!
   TBranch        *b_p;   //!
   TBranch        *b_px;   //!
   TBranch        *b_py;   //!
   TBranch        *b_pz;   //!
   TBranch        *b_tot_e;   //!
   TBranch        *b_m;   //!
   TBranch        *b_time;   //!
   TBranch        *b_is_beam;   //!
   TBranch        *b_is_stable;   //!
   TBranch        *b_gen_code;   //!
   TBranch        *b_mother_id;   //!
   TBranch        *b_mother_second_id;   //!
   TBranch        *b_has_pol_info;   //!
   TBranch        *b_pol_x;   //!
   TBranch        *b_pol_y;   //!
   TBranch        *b_pol_z;   //!
   TBranch        *b_has_vtx_info;   //!
   TBranch        *b_vtx_id;   //!
   TBranch        *b_vtx_x;   //!
   TBranch        *b_vtx_y;   //!
   TBranch        *b_vtx_z;   //!
   TBranch        *b_vtx_t;   //!
   TBranch        *b_has_smear_info;   //!
   TBranch        *b_smear_has_e;   //!
   TBranch        *b_smear_has_p;   //!
   TBranch        *b_smear_has_pid;   //!
   TBranch        *b_smear_has_vtx;   //!
   TBranch        *b_smear_has_any_eppid;   //!
   TBranch        *b_smear_orig_tot_e;   //!
   TBranch        *b_smear_orig_p;   //!
   TBranch        *b_smear_orig_px;   //!
   TBranch        *b_smear_orig_py;   //!
   TBranch        *b_smear_orig_pz;   //!
   TBranch        *b_smear_orig_vtx_x;   //!
   TBranch        *b_smear_orig_vtx_y;   //!
   TBranch        *b_smear_orig_vtx_z;   //!

    // declare histograms
    TH2F *hPVsEtaEle, *hPVsEtaPos, *hPVsEtaPion;
    TH2F *hDeltaPOverPVsEtaEle, *hDeltaPOverPVsEtaPos, *hDeltaPOverPVsEtaPion;
    TH1F *hMassElePos, *hMassJpsiPion;
    TH2F *hMapEle, *hMapPos, *hMapPion;
    
   selector_zc(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~selector_zc() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(selector_zc,0);
};

#endif

#ifdef selector_zc_cxx
void selector_zc::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("evt_id", &evt_id, &b_evt_id);
   fChain->SetBranchAddress("evt_true_q2", &evt_true_q2, &b_evt_true_q2);
   fChain->SetBranchAddress("evt_true_x", &evt_true_x, &b_evt_true_x);
   fChain->SetBranchAddress("evt_true_y", &evt_true_y, &b_evt_true_y);
   fChain->SetBranchAddress("evt_true_w2", &evt_true_w2, &b_evt_true_w2);
   fChain->SetBranchAddress("evt_true_nu", &evt_true_nu, &b_evt_true_nu);
   fChain->SetBranchAddress("evt_has_dis_info", &evt_has_dis_info, &b_evt_has_dis_info);
   fChain->SetBranchAddress("evt_prt_count", &evt_prt_count, &b_evt_prt_count);
   fChain->SetBranchAddress("evt_weight", &evt_weight, &b_evt_weight);
   fChain->SetBranchAddress("id", id, &b_id);
   fChain->SetBranchAddress("pdg", pdg, &b_pdg);
   fChain->SetBranchAddress("trk_id", trk_id, &b_trk_id);
   fChain->SetBranchAddress("charge", charge, &b_charge);
   fChain->SetBranchAddress("dir_x", dir_x, &b_dir_x);
   fChain->SetBranchAddress("dir_y", dir_y, &b_dir_y);
   fChain->SetBranchAddress("dir_z", dir_z, &b_dir_z);
   fChain->SetBranchAddress("p", p, &b_p);
   fChain->SetBranchAddress("px", px, &b_px);
   fChain->SetBranchAddress("py", py, &b_py);
   fChain->SetBranchAddress("pz", pz, &b_pz);
   fChain->SetBranchAddress("tot_e", tot_e, &b_tot_e);
   fChain->SetBranchAddress("m", m, &b_m);
   fChain->SetBranchAddress("time", time, &b_time);
   fChain->SetBranchAddress("is_beam", is_beam, &b_is_beam);
   fChain->SetBranchAddress("is_stable", is_stable, &b_is_stable);
   fChain->SetBranchAddress("gen_code", gen_code, &b_gen_code);
   fChain->SetBranchAddress("mother_id", mother_id, &b_mother_id);
   fChain->SetBranchAddress("mother_second_id", mother_second_id, &b_mother_second_id);
   fChain->SetBranchAddress("has_pol_info", has_pol_info, &b_has_pol_info);
   fChain->SetBranchAddress("pol_x", pol_x, &b_pol_x);
   fChain->SetBranchAddress("pol_y", pol_y, &b_pol_y);
   fChain->SetBranchAddress("pol_z", pol_z, &b_pol_z);
   fChain->SetBranchAddress("has_vtx_info", has_vtx_info, &b_has_vtx_info);
   fChain->SetBranchAddress("vtx_id", vtx_id, &b_vtx_id);
   fChain->SetBranchAddress("vtx_x", vtx_x, &b_vtx_x);
   fChain->SetBranchAddress("vtx_y", vtx_y, &b_vtx_y);
   fChain->SetBranchAddress("vtx_z", vtx_z, &b_vtx_z);
   fChain->SetBranchAddress("vtx_t", vtx_t, &b_vtx_t);
   fChain->SetBranchAddress("has_smear_info", has_smear_info, &b_has_smear_info);
   fChain->SetBranchAddress("smear_has_e", smear_has_e, &b_smear_has_e);
   fChain->SetBranchAddress("smear_has_p", smear_has_p, &b_smear_has_p);
   fChain->SetBranchAddress("smear_has_pid", smear_has_pid, &b_smear_has_pid);
   fChain->SetBranchAddress("smear_has_vtx", smear_has_vtx, &b_smear_has_vtx);
   fChain->SetBranchAddress("smear_has_any_eppid", smear_has_any_eppid, &b_smear_has_any_eppid);
   fChain->SetBranchAddress("smear_orig_tot_e", smear_orig_tot_e, &b_smear_orig_tot_e);
   fChain->SetBranchAddress("smear_orig_p", smear_orig_p, &b_smear_orig_p);
   fChain->SetBranchAddress("smear_orig_px", smear_orig_px, &b_smear_orig_px);
   fChain->SetBranchAddress("smear_orig_py", smear_orig_py, &b_smear_orig_py);
   fChain->SetBranchAddress("smear_orig_pz", smear_orig_pz, &b_smear_orig_pz);
   fChain->SetBranchAddress("smear_orig_vtx_x", smear_orig_vtx_x, &b_smear_orig_vtx_x);
   fChain->SetBranchAddress("smear_orig_vtx_y", smear_orig_vtx_y, &b_smear_orig_vtx_y);
   fChain->SetBranchAddress("smear_orig_vtx_z", smear_orig_vtx_z, &b_smear_orig_vtx_z);
}

Bool_t selector_zc::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef selector_zc_cxx
