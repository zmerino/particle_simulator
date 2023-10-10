#!/bin/bash
#
# W. H. Bell
# A bash script to download and build HepMC
#
version=2.04.01

base_dir=${PWD%/install-scripts}
tmp_dir=$base_dir"/tmp-HepMC"

source_file="HepMC-"$version".tar.gz"
source_dir="HepMC-"$version

download_url="http://lcgapp.cern.ch/project/simu/HepMC/download/"

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

if [[ -d $source_dir ]]; then
  echo "The source has already been un-packed.  Please remove $tmp_dir/$source_dir and try again."
  exit 1
fi

echo "tar xfz $source_file"
tar xfz $source_file

cd $source_dir

echo "./configure --with-momentum=MEV --with-length=MM --prefix=$base_dir"
./configure --with-momentum=MEV --with-length=MM --prefix=$base_dir

echo "Building"
make

echo "Installing"
make install

echo "Cleaning up"
rm -rf $tmp_dir
