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
const Double_t c = TMath::C() / 10000000;
const Double_t c2 = c*c;
const Float_t K_mass2 = 0.49366716*0.49366716;
const Float_t sigma_m2E = 120;
const Float_t sigma_m2W = 90;
const Float_t sigma_m2 = 0.000016;
//#define sigma


void Selector::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).
   f = new TFile("testfile.root", "recreate");

   hm2pE = new TH2F ("hm2pE","m^{2}", 20000,-0.2,100, 200,-0.2,100); //m^{2} vs p histogram booking
   hm2pW = new TH2F ("hm2pW", "m^{2}", 200,-0.2,1.5,200, -0.2,10); //m^{2} vs p histogram booking
   minvE = new TH1F ("minvE","Invariant mass East",500,0,2);
   //minvE2 = new TH1F ("minvE","Invariant mass East",500,0,2);
   //minvE3 = new TH1F ("minvE","Invariant mass East",500,0,2);
   minvW = new TH1F ("minvW","Invariant mass West",500,0,2);
   //minvW2 = new TH1F ("minvE","Invariant mass East",500,0,2);
   //minvW3 = new TH1F ("minvE","Invariant mass East",500,0,2);
   hm2E = new TH1F ("hm2E", "m^{2}", 15000, -0.2,1.5);
   hm2W = new TH1F ("hm2W", "m^{2}", 15000, -0.2,1.5);
   hetof = new TH1F ("hetof", "Energy", 1000, 0, 1000);
   hpltof = new TH1F ("pltof", "Distance", 1000, 0,1000);
   hphitof = new TH1F ("phitof", "Phi0", 1000, -5, 5);
   hthetof = new TH1F ("thetof", "Theta", 1000, -5, 5);

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

   dropArrays();
   fChain->GetEntry(entry); 

   if(mh>52)
   {
      return kTRUE;
   }

   if(cent>0 && cent<60)
   {

      for(int itrk=0; itrk<mh; itrk++)
      {
            if( (dcarm[itrk]==0) && (pltof[itrk]>0) && (etof[itrk]>0.002) && (p[itrk]*sin(the0[itrk])/c <1.5) && (p[itrk]*sin(the0[itrk])/c > 0.3) && (sigtof[itrk]<3) )
            {        //Tof East selection
               is_Good[itrk]=true;
               float tmp=(ttof[itrk])/pltof[itrk]*c;
               m2 = (p[itrk]*p[itrk]*((tmp*tmp)-1));

               //m2sigma=(fabs(m2-K_mass2))/sigma_m2E;
               hm2E->Fill(m2);
               hm2pE->Fill(m2,p[itrk]);
               if( m2 > (K_mass2-sigma_m2) && (m2 < (K_mass2 + sigma_m2)) && (charge[itrk] > 0) )
               {
                  is_KaonPE[itrk]=true;
                  hthetof->Fill(the0[itrk]);
                  hphitof->Fill(phi0[itrk]);
                  hpltof->Fill(pltof[itrk]);
                  hetof->Fill(etof[itrk]);
               }
               if (m2 > (K_mass2-sigma_m2) && (m2<K_mass2+sigma_m2) && (charge[itrk]<0))
               {
                  is_KaonME[itrk]=true;
                  hthetof->Fill(the0[itrk]);
                  hphitof->Fill(phi0[itrk]);
                  hpltof->Fill(pltof[itrk]);
                  hetof->Fill(etof[itrk]);
               }
            }s

            else
            {
               if((dcarm[itrk]==1) && (pltof[itrk]>0) && (etof[itrk]>60) && (p[itrk]*sin(the0[itrk])/c <1.5) && (p[itrk]*sin(the0[itrk])/c > 0.3) && (etof[itrk]<600) && (sigtof[itrk]<3))
               {// Tof West selection
                  float tmp=(ttof[itrk]*c)/pltof[itrk];
                  m2=(p[itrk]*p[itrk]*((tmp*tmp)-1));
                  m2sigma=(fabs(m2-K_mass2))/sigma_m2W;
                  hm2pW->Fill(m2,p[itrk]);
                  hm2W->Fill(m2);
                  is_Good[itrk]=true;
                  if(m2>K_mass2-sigma_m2W && m2<K_mass2+sigma_m2W && charge[itrk]>0)
                  {
                     is_KaonPW[itrk]=true;
                     hthetof->Fill(the0[itrk]);
                     hphitof->Fill(phi0[itrk]);
                     hpltof->Fill(pltof[itrk]);
                     hetof->Fill(etof[itrk]);
                  }
                  if ( (m2>(K_mass2-sigma_m2W)) && (m2<(K_mass2+sigma_m2W)) && (charge[itrk]<0))
                  {
                     is_KaonMW[itrk]=true;
                     hthetof->Fill(the0[itrk]);
                     hphitof->Fill(phi0[itrk]);
                     hpltof->Fill(pltof[itrk]);
                     hetof->Fill(etof[itrk]);
                  }
               }
            }
      }

      for(int itrk=0; itrk<mh; itrk++)
      {
         if ( is_KaonPE[itrk]=true && dcarm[itrk]==0 )
         {

            par_1.SetRho(p[itrk]);
            par_1.SetTheta(the0[itrk]);
            par_1.SetPhi(phi0[itrk]);
            par_1.SetE(sqrt((p[itrk]*p[itrk])+(K_mass2)));
            for(int jtrk=0; jtrk<mh; jtrk++){
               if ( is_KaonME[jtrk]=true && dcarm[jtrk]==0 )
               {
                  par_2.SetRho(p[jtrk]);
                  par_2.SetTheta(the0[jtrk]);
                  par_2.SetE(sqrt((p[jtrk]*p[jtrk])+(K_mass2)));
                  par_2.SetPhi(phi0[jtrk]);
                  pair=par_1+par_2;
                  m_inv=pair.M();
                  minvE->Fill(m_inv);
               }
            }  
         }
      }

      for(int itrk=0; itrk<mh; itrk++)
      {
         if (is_KaonPW[itrk]=true && dcarm[itrk]==1)
         {
            par_1.SetRho(p[itrk]);
            par_1.SetTheta(the0[itrk]);
            par_1.SetPhi(phi0[itrk]);
            par_1.SetE(sqrt((p[itrk]*p[itrk])+(K_mass2)));
            for(int jtrk=0; jtrk<mh; jtrk++){
               if (is_KaonMW[jtrk]=true && dcarm[jtrk]==1)
               {
                  par_2.SetRho(p[jtrk]);
                  par_2.SetTheta(the0[jtrk]);
                  par_2.SetE(sqrt((p[jtrk]*p[jtrk])+(K_mass2)));
                  par_2.SetPhi(phi0[jtrk]);
                  pair=par_1+par_2;
                  m_inv=pair.M();
                  minvW->Fill(m_inv);
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
   minvE->Write();
   //minvE2->Write();
   //minvE3->Write();
   minvW->Write();
   //minvW2->Write();
   hm2E->Write();
   hm2W->Write();
   //minvW3->Write();
   hthetof->Write();
   hphitof->Write();
   hpltof->Write();
   hetof->Write();

   f->Close();
}

void Selector::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
}
