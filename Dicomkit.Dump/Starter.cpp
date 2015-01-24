// This file is part of Dicomkit++.
//  
// Dicomkit++  is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Dicomkit++ is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Dicomkit++.  If not, see <http://www.gnu.org/licenses/>.

#include <exception>

#include "DicomDump.h"
#include "../Dicomkit.Sdk/DicomWriter.h"

using namespace std;
using namespace Dicomkit::Dump;

int main(int argc, char** argv) 
{
	if(argc < 2)
	{
		cout<<"usage : "<<endl;
		cout<<"Dicomkit.Dump.exe [dicom file]"<<endl;
		return 0;
	}

	try
	{
		char* dcmFile = argv[1];
		DicomDump *dcmDump = new DicomDump(dcmFile);
		dcmDump->Dump(cout);

		DicomReader reader(dcmFile);
		DataSet ds = reader.ParseDicom();

		DicomWriter writer;
		writer.Save(&ds,"G:\\image.dcm");
	}
	catch(exception e)
	{
		cout<<e.what()<<endl;
	}

	cout<<"Press any key to continue..."<<endl;
	cin.get();
	return 0;
}