#define Selector_cxx
// The class definition in Selector.h has been generated automatically
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
// Root > T->Process("Selector.C")
// Root > T->Process("Selector.C","some options")
// Root > T->Process("Selector.C+")
//

#include "Selector.h"
#include <TH2.h>
#include <TH1.h>
#include <TStyle.h>
#include <TMath.h>
const Double_t c2 = TMath::C() * TMath::C();
#define phi_mass2 1039298.6916
#define sigma_m2 0.016
//#define sigma


void Selector::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).
   f = new TFile("testfile.root", "recreate");


   hm2pE = new TH2F ("hm2pE","m^{2}", 200,-0.2,1.5,200, -100,100); //m^{2} vs p histogram booking
   hm2pW = new TH2F ("hm2pW", "m^{2}", 200,-0.2,1.5,200, -100,100); //m^{2} vs p histogram booking
   minv = new TH1F ("minv","Invariant mass",100,-0.2,1200);


   TString option = GetOption();

}

void Selector::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t Selector::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either Selector::GetEntry() or TBranch::GetEntry()
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


    if (entry % 100000 == 0)
    {
         std::cout << entry << std::endl;
    }

   // if (entry > 1000)
   //  {
   //    Abort("BFVSDGFVD");
   //  }

   fChain->GetEntry(entry); 


   if(cent>0 && cent<=80)
   {
      for(Int_t itrk=0; itrk<mh; itrk++)
      {
         //if(pt>0.4&&pt<3.8){ // track selection
         //std::cout << "dcarm[itrk]: " << dcarm[itrk] << "    pltof[itrk]: " << pltof[itrk]<< "    etof[itrk]: " << etof[itrk]<< "    sigtof[itrk]: " << sigtof[itrk] << std::endl;
            if( (dcarm[itrk]==0) && (pltof[itrk]>0) && (etof[itrk]>0.002) && (sigtof[itrk]<3) )
            {        //Tof East selection
               //std::cout << "hm2pEOk" << std::endl;
               float tmp=(ttof[itrk]*c2)/pltof[itrk];
               m2=(p[itrk]*p[itrk]*((tmp*tmp)-1))/c2;
               m2sigma=(abs(m2-phi_mass2))/sigma_m2;
               hm2pE->Fill(m2sigma,p[itrk]);

               if( m2sigma > (phi_mass2-sigma_m2) && (m2sigma < (phi_mass2 + sigma_m2)) && (charge[itrk] > 0) )
               {
                  par_1.SetRho(p[itrk]);
                  par_1.SetTheta(the0[itrk]);
                  par_1.SetPhi(phi0[itrk]);
                  par_1.SetE(etof[itrk]);
                  for( Int_t jtrk=0; jtrk<mh; jtrk++)
                  {
                     if (m2sigma > (phi_mass2-sigma_m2) && (m2sigma<phi_mass2+sigma_m2) && (charge[itrk]<0))
                     {
                        par_2.SetRho(p[jtrk]);
                        par_2.SetTheta(the0[jtrk]);
                        par_2.SetE(etof[jtrk]);
                        par_2.SetPhi(phi0[jtrk]);
                     }
                     pair=par_1+par_2;
                     m_inv=pair.M();
                     minv->Fill(m_inv);
                   
                  }
               }
            }




            else
            {
               if((dcarm[itrk]==1) && (pltof[itrk]>0) && (etof[itrk]>60) && (etof[itrk]<600) && (sigtof[itrk]<3))
               {// Tof West selection
                  float tmp=(ttof[itrk]*c2)/pltof[itrk];
                  m2=(p[itrk]*p[itrk]*((tmp*tmp)-1))/c2;
                  m2sigma=(abs(m2-phi_mass2))/sigma_m2;
                  hm2pW->Fill(m2,p[itrk]);
                  if(m2sigma>phi_mass2-sigma_m2 && m2sigma<phi_mass2+sigma_m2 && charge[itrk]>0)
                  {
                     par_1.SetRho(p[itrk]);
                     par_1.SetTheta(the0[itrk]);
                     par_1.SetPhi(phi0[itrk]);
                     par_1.SetE(etof[itrk]);
                     for( Int_t jtrk=0; jtrk<mh;jtrk++)
                     {
                        if ( (m2sigma>(phi_mass2-sigma_m2)) && (m2sigma<(phi_mass2+sigma_m2)) && (charge[itrk]<0)) 
                        {
                           par_2.SetRho(p[jtrk]);
                           par_2.SetTheta(the0[jtrk]);
                           par_2.SetE(etof[jtrk]);
                           par_2.SetPhi(phi0[jtrk]);
                        }
                        pair=par_1+par_2;
                        m_inv=pair.M();
                        minv->Fill(m_inv);
                     }
                  }
               }
            }
      }
   }
   return kTRUE;
}

         



void Selector::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.
   hm2pE->Write();
   hm2pW->Write();
   minv->Write();
   
   //delete hm2pE;
   //delete hm2pW;
   //delete minv;

   f->Close();
}

void Selector::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
}
