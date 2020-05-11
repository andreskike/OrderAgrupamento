/*******************************************************************************
 * IBOPE - Midia TI - 2004
 * Agrupamento.h - 21/09/2004
 *
 * This class manipulate a agrupamento CSV file.
*******************************************************************************/

#ifndef AgrupamentoH
#define AgrupamentoH

#include "defines.h"
#include "CSVFileType.h"
#include <vector>

using namespace std;

namespace CSVFILE {

typedef struct {
  int emissora;
  vector<int> redes;
} AgrupCad;


typedef struct {
	int redes;
	int emissora;
} AgrupCad2;

class AgrupamentoFile: public CSVFileType {
private:
   vector<AgrupCad> _agrupamento;
   vector< pair <int, int> > _agrupamento2;
   vector<int> listRedes;
   int agrupamento;
public:
   AgrupamentoFile();
   ~AgrupamentoFile();
   void clear();
   bool read(char* file);
   bool readFile2(char* file);
   bool write(char* file);
   bool compareByLength(const AgrupCad& a, const AgrupCad& b);
   AgrupCad* getRedeAgrupamento(int indexEmissora);
   int getRede(int index);
   int getAgrupamento();
   unsigned int getTotalListRede();

};

}

#endif
