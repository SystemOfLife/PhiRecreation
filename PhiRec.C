#include "TH1.h"
#include "TFile.h"
#include "TH2.h"
#include <time>
#include <iostream>

void PhiRec(){
	TFile *f1 =new TFile("/home/arkady/NIRS/RootFiles/new62/311857.root");
	mtree->MakeSelector("Selector");
	mtree->Process("Selector.C");

	
