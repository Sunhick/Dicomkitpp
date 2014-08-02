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
	this->dataSet->AddDataElement(dataElement);
}

void DicomWriter::Save(string fileName)
{
	SortElements();
	Save(this->dataSet,fileName);
}

void DicomWriter::Save(DataSet* dataSet, string fileName)
{
	CheckDicomMandatoryTags();

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

void DicomWriter::SortElements()
{
	//sort the elements based on dicom tags. suggested in dicom part 05 
}

void DicomWriter::PadNullBytes(int count)
{
	//pad with null(0x00) bytes
}

void DicomWriter::CheckDicomMandatoryTags()
{
	//check for dicom mandatory tags. Like Transfer syntax etc.
	throw MissingMandatoryTagException("Implement this method");
}