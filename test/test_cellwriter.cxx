#include "WireCellBio/CellWriter.h"

#include <boost/filesystem.hpp>

#include <iostream>

using namespace WireCellBio;
using namespace WireCell;
using namespace std;
using namespace boost::filesystem;

int main() {
    auto outdir = temp_directory_path();
    outdir += "data";

    CellWriter cw("test_cellwriter","bogus",0,0,outdir.c_str());

    

}
