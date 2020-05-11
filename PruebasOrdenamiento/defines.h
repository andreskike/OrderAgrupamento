/*******************************************************************************
 * IBOPE - Midia TI - 2004
 * defines.h - 03/09/2004
 *
 * General definitions and constant defines!
*******************************************************************************/

#ifndef definesH
#define definesH

// FILES EXTENSIONS
#define FILEEXTMTYPROC     ".proc"
#define FILEEXTMTY         ".mty"
#define FILEEXTCMD         ".cmd"

#define PUBLICODOMICILIO   0
#define PUBLICOINDIVIDUAL  1
#define PUBLICOTELEVISOR   2

#define MAXDOM            2048
#define MAXTVS            8
#define MAXMTYSTATUS      8
#define MAXTVSTATUS       3
#define MAXPES	          16
#define MAXPESBITS	  0xFFFF

#define SBUFFERLEN        1024
#define KILOBYTES2        2048
#define BYTES256          256
#define KILOBYTES128      131072
#define KILOBYTESTESTE      512000

// Codigos de controle
//Codigo máximo da distribuidora ao qual tabulador vai alinhar
#define	MAXDISTRIBUIDORA  256

//Maximo de codigo de emissora permitido
#define	MAXEMISSORAS      2048

//Máximo de canais transmitidos pelo DIB
#define MAXCANAIS                       2048
//Codigo para sintonias que não possuem alinhamentos
#define SEM_ALINHAMENTO	238


//Codigos de emissoras
#define FORA_BASE                        242
#define MAX_FORA_BASE                    255
#define TOTAL_LIGADOS                    999

//#define VIDEO_GAME                       120
//#define VIDEO_GAME1                      121
//#define OUTRAS_UHF_DIB2                  236
//#define CANAL_NAO_IDENTIFICADO           237
//#define EMISSORA_DESCONHECIDA            238
//#define VIDEO_CASSETE                    239
#define DESLIGADO                        240
#define CANAL_DESLIGADO                  253
#define SEMLUZ                           241
#define CANAL_PROBLEMARELOGIO            242
#define CANAL_FALHAME                    0
#define CANAL_FALHAMGCD                  250
#define CANAL_PROBLEMASENSORI2C          251
#define CANAL_ERROCOMSERIAL              434
#define CANAL_FALHAAD                    249
#define CANAL_NI                         254
#define CANAL_FALHA250                   250
#define CANAL_FALHA251                   251
#define CANAL_FALHA252                   252

#define EMISSORA_NI                      237
#define EMISSORA_DESLIGADO               240
#define EMISSORA_FALHAMGCD               250
#define EMISSORA_FALHAME                 253
#define EMISSORA_FALHAAD                 254
#define EMISSORA_TSV               	 990
//#define PROBLEMA_NO_SENSOR_I2C_DETECTOR  251
//#define INVALIDO                         252
//#define FALHAME                          253
//#define FALHAAD                          254

#endif

