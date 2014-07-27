// This file is part of Dicomkit.
//  
// DicomKit  is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// DicomKit is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with DicomKit.  If not, see <http://www.gnu.org/licenses/>.

#include "DicomWriter.h"

using namespace Dicomkit::Sdk;

DicomWriter::DicomWriter(void)
{
	Init();
}


DicomWriter::~DicomWriter(void)
{
	delete dataSet;
}

void DicomWriter::Init()
{
	dataSet = new DataSet();
}

void DicomWriter::AddDataElement(DataElement dataElement)
{

}

void DicomWriter::Save(string fileName)
{
	Save(this->dataSet,fileName);
}

void DicomWriter::Save(DataSet* dataSet, string fileName)
{
	ofstream dicomStream(fileName, ios::binary | ios::out);

	WriteHeader(dicomStream, dataSet);

	WriteDataElements(dicomStream, dataSet);

	dicomStream.close();
}

void DicomWriter::WriteHeader(ofstream& dicomStream, DataSet* dataSet)
{
	dicomStream.write(dataSet->GetPreamble(),128);
	dicomStream.write(dataSet->GetPrefix(), 4);
}

void DicomWriter::WriteDataElements(ofstream& dicomStream, DataSet* dataSet)
{
	//get bytes from data element and dump to file
}