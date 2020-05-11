/*******************************************************************************
 * IBOPE - Midia TI - 2004
 * Agrupamento.cpp - 08/10/2004
 *
 * This class manipulate a agrupamento CSV file.
*******************************************************************************/
#define _CRT_SECURE_NO_DEPRECATE
#include "Agrupamento.h"
#include "string.h"
#include "stdlib.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <sstream>

namespace CSVFILE {

//------------------------------------------------------------------------------
AgrupamentoFile::AgrupamentoFile() {
   clear();
}

//------------------------------------------------------------------------------
AgrupamentoFile::~AgrupamentoFile() {
   clear();
}

//------------------------------------------------------------------------------
// Clear the struct _agrupamento[...][...]!
void AgrupamentoFile::clear() {
   for( unsigned int i = 0; i < _agrupamento.size(); i++ ) {
      _agrupamento[i].emissora = 0;
      _agrupamento[i].redes.clear();
   }
   _agrupamento.clear();
   agrupamento = 0;
   listRedes.clear();
}

//------------------------------------------------------------------------------
bool AgrupamentoFile::read(char* file) {
   // Set temporary variable
   char strDados[SBUFFERLEN];
   char tempS[SBUFFERLEN];
   strcpy(strDados,"\0");
   strcpy(tempS,"\0");
   vector<int>::iterator itI;
   vector<AgrupCad>::iterator itAgrp;
   AgrupCad tempAgrup;

   int rede, emissora;
   // Open the file!
   if( !this->openFile(file) ) {
     return false;
   }
   clear();
   // The first line is the header than it's discarted!
   if(this->readline(strDados,SBUFFERLEN)) {
      strcpy(tempS,"\0");
      // While we have data in the file, do!
      while(this->readline(strDados,SBUFFERLEN)) {
         this->getTokenIndex(strDados,0,tempS);
         agrupamento = atoi(tempS);
         this->getTokenIndex(strDados,1,tempS);
	 emissora = atoi(tempS);
         this->getTokenIndex(strDados,2,tempS);
	 rede = atoi(tempS);

        // Try to find an "emissora" in "agrupamento" list to prevent "emissora" duplication!
         for (itAgrp = _agrupamento.begin(); itAgrp != _agrupamento.end(); itAgrp++)
           if (itAgrp->emissora == emissora) break;

         // Se encontrou uma emissora cadastrada apenas tente colocar a rede para aquela emissora
         if (itAgrp != _agrupamento.end()) {
            itI = find( itAgrp->redes.begin(), itAgrp->redes.end(), rede);
            if ( itI == itAgrp->redes.end() ) {
               itAgrp->redes.push_back(rede);
            }
         } else { // Senão crie um novo cadastro de emissora e adicione na lista.
            tempAgrup.emissora = emissora;
            tempAgrup.redes.push_back(rede);

            _agrupamento.push_back(tempAgrup);
            tempAgrup.redes.clear();
         }
         // Store all diferents values of "rede" for future use in tabulador!
         itI = find( listRedes.begin(), listRedes.end(), rede);

         if (itI == listRedes.end()) {
            listRedes.push_back(rede);
         }
      }
      // !@#$ WARNING MAY BE(MUST BE) THIS IS WILL BE REMOVED!! GABI PARA TOTAL LIGADOS!!!
      // Adiciona na lista no final o TOTAL LIGADOS!

	  //Ordenamiento de el agrupamiento por redes
	 /* std::sort(_agrupamento.begin(), _agrupamento.end(),
		  [](const AgrupCad& a, const AgrupCad& b)
	  {
		  return a.redes < b.redes;
	  }
	  );*/
      listRedes.push_back(TOTAL_LIGADOS);
   } else {
      return false;
   }
   return this->closeFile();
}


//------------------------------------------------------------------------------
bool AgrupamentoFile::readFile2(char* file) {
	// Set temporary variable
	char strDados[SBUFFERLEN];
	char tempS[SBUFFERLEN];
	strcpy(strDados, "\0");
	strcpy(tempS, "\0");
	vector<int>::iterator itI;
	vector<AgrupCad>::iterator itAgrp;
	AgrupCad2 tempAgrup;

	int rede, emissora;
	// Open the file!
	if (!this->openFile(file)) {
		return false;
	}
	clear();
	// The first line is the header than it's discarted!
	if (this->readline(strDados, SBUFFERLEN)) {
		strcpy(tempS, "\0");
		// While we have data in the file, do!
		while (this->readline(strDados, SBUFFERLEN)) {
			this->getTokenIndex(strDados, 0, tempS);
			agrupamento = atoi(tempS);
			this->getTokenIndex(strDados, 1, tempS);
			emissora = atoi(tempS);
			this->getTokenIndex(strDados, 2, tempS);
			rede = atoi(tempS);

			tempAgrup.redes = rede;
			tempAgrup.emissora = emissora;
			
			
			_agrupamento2.push_back(make_pair(rede, emissora));
			// Store all diferents values of "rede" for future use in tabulador!
			itI = find(listRedes.begin(), listRedes.end(), rede);

			if (itI == listRedes.end()) {
				listRedes.push_back(rede);
			}
		
		}

		//Ordenamiento de el agrupamiento por redes almacenado en un vector
		std::sort(_agrupamento2.begin(),_agrupamento2.end());
		std::sort(listRedes.begin(), listRedes.end());

		// !@#$ WARNING MAY BE(MUST BE) THIS IS WILL BE REMOVED!! GABI PARA TOTAL LIGADOS!!!
		// Adiciona na lista no final o TOTAL LIGADOS!

		listRedes.push_back(TOTAL_LIGADOS);

		
	}
	else {
		return false;
	}
	return this->closeFile();
}

bool AgrupamentoFile::compareByLength(const AgrupCad& a, const AgrupCad& b)
{
	return a.redes.size() < b.redes.size();
}


//------------------------------------------------------------------------------
bool AgrupamentoFile::write(char* file) {
   // TODO: Write a Agrupamento file!
   return false;
}

//------------------------------------------------------------------------------
int AgrupamentoFile::getAgrupamento() {
   return agrupamento;
}

//------------------------------------------------------------------------------
AgrupCad* AgrupamentoFile::getRedeAgrupamento(int indexEmissora) {
   vector<AgrupCad>::iterator itAgrp;
   bool encontrou = false;
   for (itAgrp = _agrupamento.begin(); itAgrp != _agrupamento.end(); itAgrp++)
     if (itAgrp->emissora == indexEmissora) {
        encontrou = true;
        break;
     }
   if (encontrou) {
      return &(*itAgrp);
   }
   return NULL;
}

//------------------------------------------------------------------------------
int AgrupamentoFile::getRede(int index) {
   return listRedes[index];
}

//------------------------------------------------------------------------------
unsigned int AgrupamentoFile::getTotalListRede() {
   return listRedes.size();
}

}
