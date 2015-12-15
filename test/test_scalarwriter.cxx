#include "WireCellBio/ScalarFieldWriter.h"
#include "WireCellUtil/Testing.h"
#include "WireCellUtil/Units.h"

#include <boost/filesystem.hpp>

#include <iostream>

using namespace WireCellBio;
using namespace WireCell;
using namespace std;
using namespace boost::filesystem;

int main(int argc, char *argv[]) {
    path outdir(argv[0]);
    outdir += "_data/data";

    if (exists(outdir)) {
	cerr << "Expected output directory already exists: " << outdir << endl;
	return 1;
    }

    cerr << "Test output going to: " << outdir << endl;

    ScalarFieldWriter sfw("test_scalarwriter","bogus",0,0,outdir.c_str());

    for (int eventnum=0; eventnum<10; ++eventnum) {
	double o = eventnum*10*units::cm;
	Vector origin(o,o,o);
	Vector dir(1.0,1.0,1.0);
	ScalarField* field = new ScalarField;
	for (double s = 0; s < 1.0*units::meter; s += 1.0*units::cm) {
	    Vector point = origin + s*dir;
	    double scalar = s/units::cm;
	    field->push_back(ScalarPoint(scalar, point));
	}
	ScalarFieldWriter::input_pointer in(field);
	Assert(sfw(in));

	auto zerodir = outdir / "0";
	Assert(exists(zerodir.c_str()));

	if (argc > 1 && argv[1] == string("purge")) {
	    cerr << "Purging: " << outdir << endl;
	    remove_all(outdir);
	}
    }
    return 0;
}
