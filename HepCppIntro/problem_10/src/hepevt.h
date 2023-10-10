/*
** W. H. Bell
**
** A header file to provide access to the HEPEVT fortran
** common block.  This must match the version used in the 
** PYTHIA source code.
*/

#ifndef HEPEVT_H
#define HEPEVT_H

#define NMXHEP 4000

extern "C" {

/* 
 * A common block containing the list of particles generated.
 */
typedef struct {
  int nevhep;
  int nhep;
  int isthep[NMXHEP];
  int idhep[NMXHEP];
  int jmohep[NMXHEP][2];
  int jdahep[NMXHEP][2];
  double phep[NMXHEP][5];
  double vhep[NMXHEP][4];
} HEPEVT;

extern HEPEVT hepevt_;

}
#endif
