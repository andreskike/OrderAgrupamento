/*******************************************************************************
 * IBOPE - Midia TI - 2004
 * CSVFileType.h - 01/09/2004
 *
 * This class implements a read and write CSV.
*******************************************************************************/

#ifndef CSVFileTypeH
#define CSVFileTypeH

#include <stdio.h>
#include "defines.h"

#define CSVTOKEN ";"

namespace CSVFILE {

class CSVFileType {
protected:
   FILE* file;
   bool fileOpened;
   bool checkLineNumTokens(char* line, int numTokens);
   void getTokenIndex(char* line, int indexToken, char* result);
   int  countTokens(char* line);
   bool openFile(char* fileName);
   bool readline(char* buffer, int bufferLenght);
   bool closeFile();
   char _fileName[SBUFFERLEN];
   virtual bool read(char* file) = 0;
   virtual bool write(char* file) = 0;
public:
   CSVFileType();
   ~CSVFileType();
   char* getFileName();
};

}

#endif
