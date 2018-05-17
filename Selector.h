//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Apr 26 19:07:19 2018 by ROOT version 5.34/30
// from TTree mtree/Hadron EMC + TOF tree
// found on file: /home/arkady/NIRS/RootFiles/new62/311857.root
//////////////////////////////////////////////////////////

#ifndef Selector_h
#define Selector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TLorentzVector.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class Selector : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   // Declaration of leaf types
   Int_t           run;
   Float_t         bbcz;
   Float_t         cent;
   Int_t           rh;
   Float_t         phir[47];   //[rh]
   Float_t         time[47];   //[rh]
   Float_t         qr0[47];   //[rh]
   Float_t         etar[47];   //[rh]
   Short_t         armr[47];   //[rh]
   Short_t         ring[47];   //[rh]
   Int_t           chid[47];   //[rh]
   Int_t           mh;
   Float_t         alpha[52];   //[mh]
   Short_t         dcarm[52];   //[mh]
   Float_t         p[52];   //[mh]
   Short_t         charge[52];   //[mh]
   Float_t         phi0[52];   //[mh]
   Float_t         the0[52];   //[mh]
   Float_t         phi[52];   //[mh]
   Float_t         ecore[52];   //[mh]
   Float_t         plemc[52];   //[mh]
   Float_t         ecent[52];   //[mh]
   Float_t         temc[52];   //[mh]
   Float_t         temcpi[52];   //[mh]
   Float_t         temcp[52];   //[mh]
   Float_t         temck[52];   //[mh]
   Short_t         sect[52];   //[mh]
   Float_t         isPiemc[52];   //[mh]
   Float_t         isPemc[52];   //[mh]
   Float_t         isKemc[52];   //[mh]
   Int_t           idtwr[52];   //[mh]
   Float_t         sigtof[52];   //[mh]
   Float_t         sigpc3[52];   //[mh]
   Float_t         sigemc[52];   //[mh]
   Float_t         res[52];   //[mh]
   Float_t         ttof[52];   //[mh]
   Int_t           slat[52];   //[mh]
   Float_t         pltof[52];   //[mh]
   Float_t         etof[52];   //[mh]
   Float_t         isPi[52];   //[mh]
   Float_t         isP[52];   //[mh]
   Float_t         isK[52];   //[mh]

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_bbcz;   //!
   TBranch        *b_cent;   //!
   TBranch        *b_rh;   //!
   TBranch        *b_phir;   //!
   TBranch        *b_time;   //!
   TBranch        *b_qr0;   //!
   TBranch        *b_etar;   //!
   TBranch        *b_armr;   //!
   TBranch        *b_ring;   //!
   TBranch        *b_chid;   //!
   TBranch        *b_mh;   //!
   TBranch        *b_alpha;   //!
   TBranch        *b_dcarm;   //!
   TBranch        *b_p;   //!
   TBranch        *b_charge;   //!
   TBranch        *b_phi0;   //!
   TBranch        *b_the0;   //!
   TBranch        *b_phi;   //!
   TBranch        *b_ecore;   //!
   TBranch        *b_plemc;   //!
   TBranch        *b_ecent;   //!
   TBranch        *b_temc;   //!
   TBranch        *b_temcpi;   //!
   TBranch        *b_temcp;   //!
   TBranch        *b_temck;   //!
   TBranch        *b_sect;   //!
   TBranch        *b_isPiemc;   //!
   TBranch        *b_isPemc;   //!
   TBranch        *b_isKemc;   //!
   TBranch        *b_idtwr;   //!
   TBranch        *b_sigtof;   //!
   TBranch        *b_sigpc3;   //!
   TBranch        *b_sigemc;   //!
   TBranch        *b_res;   //!
   TBranch        *b_ttof;   //!
   TBranch        *b_slat;   //!
   TBranch        *b_pltof;   //!
   TBranch        *b_etof;   //!
   TBranch        *b_isPi;   //!
   TBranch        *b_isP;   //!
   TBranch        *b_isK;   //!

   TH2F *hm2pE;
   TH2F *hm2pW;
   TH1F *minvE;
   TH1F *minvW;
   TH1F *hm2E;
   TH1F *hm2W;
   TFile *f;

   TLorentzVector par_1;  //Initialisation of var for Selector.C
   TLorentzVector par_2;
   TLorentzVector pair;

   Float_t m2, m2sigma;
   //Float_t sigtof;
   Float_t m_inv;

   bool is_Good[52];
   bool is_KaonP[52];
   bool is_KaonM[52];
   Float_t is_m2[52];

   Selector(TTree * /*tree*/ =0) : fChain(0), par_1(1,1,1,1), par_2(1,1,1,1), pair(1,1,1,1) { }
   virtual ~Selector() { }
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

   ClassDef(Selector,0);
private:
   void dropArrays() {
      for (int i = 0; i < 52; i++) 
      {
         is_Good[i] = false;
         is_KaonP[i] = false;
         is_KaonM[52] = false;
         is_m2[i]=0;
      }
   }
};

#endif

#ifdef Selector_cxx
void Selector::Init(TTree *tree)
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

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("bbcz", &bbcz, &b_bbcz);
   fChain->SetBranchAddress("cent", &cent, &b_cent);
   fChain->SetBranchAddress("rh", &rh, &b_rh);
   fChain->SetBranchAddress("phir", phir, &b_phir);
   fChain->SetBranchAddress("time", time, &b_time);
   fChain->SetBranchAddress("qr0", qr0, &b_qr0);
   fChain->SetBranchAddress("etar", etar, &b_etar);
   fChain->SetBranchAddress("armr", armr, &b_armr);
   fChain->SetBranchAddress("ring", ring, &b_ring);
   fChain->SetBranchAddress("chid", chid, &b_chid);
   fChain->SetBranchAddress("mh", &mh, &b_mh);
   fChain->SetBranchAddress("alpha", alpha, &b_alpha);
   fChain->SetBranchAddress("dcarm", dcarm, &b_dcarm);
   fChain->SetBranchAddress("p", p, &b_p);
   fChain->SetBranchAddress("charge", charge, &b_charge);
   fChain->SetBranchAddress("phi0", phi0, &b_phi0);
   fChain->SetBranchAddress("the0", the0, &b_the0);
   fChain->SetBranchAddress("phi", phi, &b_phi);
   fChain->SetBranchAddress("ecore", ecore, &b_ecore);
   fChain->SetBranchAddress("plemc", plemc, &b_plemc);
   fChain->SetBranchAddress("ecent", ecent, &b_ecent);
   fChain->SetBranchAddress("temc", temc, &b_temc);
   fChain->SetBranchAddress("temcpi", temcpi, &b_temcpi);
   fChain->SetBranchAddress("temcp", temcp, &b_temcp);
   fChain->SetBranchAddress("temck", temck, &b_temck);
   fChain->SetBranchAddress("sect", sect, &b_sect);
   fChain->SetBranchAddress("isPiemc", isPiemc, &b_isPiemc);
   fChain->SetBranchAddress("isPemc", isPemc, &b_isPemc);
   fChain->SetBranchAddress("isKemc", isKemc, &b_isKemc);
   fChain->SetBranchAddress("idtwr", idtwr, &b_idtwr);
   fChain->SetBranchAddress("sigtof", sigtof, &b_sigtof);
   fChain->SetBranchAddress("sigpc3", sigpc3, &b_sigpc3);
   fChain->SetBranchAddress("sigemc", sigemc, &b_sigemc);
   fChain->SetBranchAddress("res", res, &b_res);
   fChain->SetBranchAddress("ttof", ttof, &b_ttof);
   fChain->SetBranchAddress("slat", slat, &b_slat);
   fChain->SetBranchAddress("pltof", pltof, &b_pltof);
   fChain->SetBranchAddress("etof", etof, &b_etof);
   fChain->SetBranchAddress("isPi", isPi, &b_isPi);
   fChain->SetBranchAddress("isP", isP, &b_isP);
   fChain->SetBranchAddress("isK", isK, &b_isK);

   std::cout << fChain->GetEntries() << " entries" << std::endl;

}

Bool_t Selector::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef Selector_cxx
