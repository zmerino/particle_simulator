#!/bin/bash
#
# W. H. Bell
# A bash script to download and build PYTHIA
#
version=6.4.20

base_dir=${PWD%/install-scripts}
tmp_dir=$base_dir"/tmp-PYTHIA"

source_file="pythia-"$version".f.gz"
fortran_file="pythia-"$version".f"

download_url="http://www.hepforge.org/archive/pythia6/"

if [[ ! -d $tmp_dir ]]; then
  mkdir $tmp_dir
  if [[ $? != 0 ]]; then
    exit 1
  fi
fi

cd $tmp_dir

if [[ ! -f $source_file ]]; then
  wget $download_url$source_file
  if [[ $? != 0 ]]; then
    echo "wget failed.  Please download $source_file from $download_url into $tmp_dir and re-run this script."
    exit 1
  fi
fi

if [[ -d $fortran_file ]]; then
  echo "The source has already been un-packed.  Please remove $tmp_dir/$source_dir and try again."
  exit 1
fi

echo "gunzip $source_file"
gunzip $source_file

echo "Building (It is one big FORTRAN file.)"

echo "gfortran -c -O $fortran_file"
gfortran -c -O $fortran_file

objectFile=${fortran_file%.f}".o"
echo "ar -cr libpythia.a $objectFile"
ar -cr libpythia.a $objectFile

echo "Installing"
mkdir -p $base_dir/lib
cp libpythia.a $base_dir/lib

mkdir -p $base_dir/include/pythia
cat > $base_dir/include/pythia/pythia.h <<EOF
#ifndef PYTHIA_H
#define PYTHIA_H

/* W. H. Bell
** Some C declarations to match this version of Pythia
** Only the functions and common block used are included here.
*/

extern "C" {
  typedef struct {
    int msel;
    int mselpd;
    int msub[500];
    int kfin[81][2];
    double ckin[200];
  } PYSUBS;
  extern PYSUBS pysubs_;

  void pyinit_(char *, char *, char *, double *, int, int, int);
  void pystat_(int *);
  void pyevnt_(void);
  void pylist_(int *);
  void pyhepc_(int *);
}

#endif
EOF

echo "Cleaning up"
rm -rf $tmp_dir
