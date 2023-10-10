#!/bin/bash
#
# W. H. Bell
# A bash script to download and build ROOT
#
version=5.22.00

base_dir=${PWD%/install-scripts}
tmp_dir=$base_dir"/tmp-ROOT"

source_file="root_v"$version".source.tar.gz"
source_dir="root"

download_url="ftp://root.cern.ch/root/"

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

echo "./configure --prefix=$base_dir --etcdir=$base_dir/etc/root"
./configure --prefix=$base_dir --etcdir=$base_dir"/etc/root"

echo "Building"
make

echo "Installing"
make install

echo "Cleaning up"
rm -rf $tmp_dir

echo ""
echo "ROOT has been successfully built"
echo "The environmental variable ROOTSYS should be set to $base_dir"
