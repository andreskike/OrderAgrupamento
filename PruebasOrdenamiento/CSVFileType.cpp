/*******************************************************************************
 * IBOPE - Midia TI - 2004
 * CSVFileType.cpp - 01/09/2004, 13/09/2004
 *
 * This class implements a read and write CSV.
*******************************************************************************/

#define _CRT_SECURE_NO_DEPRECATE
#include "CSVFileType.h"
#include <stdio.h>
#include <stdlib.h>
#include <share.h>
#include <string.h>
#include <windows.h>

namespace CSVFILE {

//------------------------------------------------------------------------------
CSVFileType::CSVFileType() {
  fileOpened = false;
  strcpy(_fileName,"\0");
}

//------------------------------------------------------------------------------
CSVFileType::~CSVFileType() {
  if( fileOpened ) {
     this->closeFile();
  }
  fileOpened = false;
  strcpy(_fileName,"\0");
}

//------------------------------------------------------------------------------
int CSVFileType::countTokens( char* line ) {
   char* tempS = new char[strlen(line)+1];
   char* token;
   strcpy(tempS,line);
   int countToken = 0;
   // Count the numbers of tokens
   token = strtok(tempS,CSVTOKEN);
   while(token != NULL) {
      countToken++;
      token = strtok(NULL,CSVTOKEN);
   }
   delete[] tempS;
   return countToken;
}

//------------------------------------------------------------------------------
// This function counts the number of tokens in a string terminated with a "\0"!
bool CSVFileType::checkLineNumTokens(char* line, int numTokens) {
   // Check if it's equals!
   if( numTokens == countTokens(line) ) {
      return true;
   } else {
      return false;
   }
}

//------------------------------------------------------------------------------
// This function get a item!
void CSVFileType::getTokenIndex(char* line, int indexToken, char* result) {
   char* tempS = new char[strlen(line)+1];
   char* token;
   strcpy(tempS,line);
   int countToken = -1;
   // Count the numbers of tokens
   token = strtok(tempS,CSVTOKEN);
   while(token != NULL) {
      countToken++;
      // If found the token than break!
      if(countToken == indexToken) {
         break;
      } else { // else take the other token!
         token = strtok(NULL,CSVTOKEN);
      }
   }
   strcpy(result,token);
   delete[] tempS;
}

//------------------------------------------------------------------------------
// Check is already opened or not than open the file in read write text mode!
bool CSVFileType::openFile(char* fileName) {
   if( !fileOpened ) {
      file = NULL;
      file = _fsopen(fileName,"rt",SH_DENYNO);
      if ( file != NULL ) {
        strcpy(_fileName,fileName);
        fileOpened = true;
        return true;
      } else {
        fileOpened = false;
        return false;
      }
   }
   return false;
}

//------------------------------------------------------------------------------
// Reads until the "\0"!
bool CSVFileType::readline(char* buffer, int bufferLenght) {
   char* tempCP;
   int lenghtC;
   if( fileOpened ) {
     tempCP = fgets(buffer,bufferLenght,file);
     lenghtC = strlen(buffer);
     // Verify if there is a \n and suply with a '\0'
     if( buffer[lenghtC-1] == '\n' ) {
        buffer[lenghtC-1] = '\0';
     }
     if( tempCP != NULL ) {
        return true;
     } else {
        return false;
     }
   }
   return false;
}


//------------------------------------------------------------------------------
// Check if the file is already opened
bool CSVFileType::closeFile() {
   if( fileOpened ) {
     fclose(file);
     fileOpened = false;
      return true;
   }
   return false;
}

//------------------------------------------------------------------------------
char *CSVFileType::getFileName() {
   return _fileName;
}

}

