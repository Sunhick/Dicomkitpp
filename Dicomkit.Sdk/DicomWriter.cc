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

#include "ValueRepresentation.h"

using namespace Dicomkit::Sdk;

DicomWriter::DicomWriter(void) {
	Init();
}

DicomWriter::~DicomWriter(void) {

}

void DicomWriter::Init() {
	dataSet = new DataSet();
	
	//patient mandatory tags
	this->mandatoryTags.push_back(DicomTag(0x0008,0x0005));
	this->mandatoryTags.push_back(DicomTag(0x0010,0x0010));
	this->mandatoryTags.push_back(DicomTag(0x0010,0x0020));

	//study mandatory tags
	this->mandatoryTags.push_back(DicomTag(0x0008,0x0005));
	this->mandatoryTags.push_back(DicomTag(0x0008,0x0020));
	this->mandatoryTags.push_back(DicomTag(0x0008,0x0030));	
	this->mandatoryTags.push_back(DicomTag(0x0008,0x0050));
	this->mandatoryTags.push_back(DicomTag(0x0020,0x000D));
	this->mandatoryTags.push_back(DicomTag(0x0020,0x0010));

	//series mandatory tags
	this->mandatoryTags.push_back(DicomTag(0x0008,0x0060));
	this->mandatoryTags.push_back(DicomTag(0x0020,0x000E));
	this->mandatoryTags.push_back(DicomTag(0x0020,0x0011));

	//instance mandatory tags
	this->mandatoryTags.push_back(DicomTag(0x0008,0x0018));
	this->mandatoryTags.push_back(DicomTag(0x0020,0x0013));
}

void DicomWriter::AddDataElement(DataElement dataElement) {
	this->dataSet->AddDataElement(dataElement);
}

void DicomWriter::Save(string fileName) {
	SortElements(this->dataSet);
	Save(this->dataSet,fileName);
}

void DicomWriter::Save(DataSet* dataSet, string fileName) {
	CheckDicomMandatoryTags(dataSet->GetDataElements());

	ofstream dicomStream(fileName, ios::binary | ios::out);

	WriteHeader(dicomStream, dataSet);

	dataSet->SortDataElements();
	WriteDataElements(dicomStream, dataSet->GetDataElements());

	dicomStream.close();
}

void DicomWriter::WriteHeader(ofstream& dicomStream, DataSet* dataSet) {
	dicomStream.write(dataSet->GetPreamble(),128);
	dicomStream.write(dataSet->GetPrefix(), 4);
}

void DicomWriter::WriteDataElements(ofstream& dicomStream, list<DataElement> elements) {
	// get bytes from data element and dump to file
	for(auto element : elements) {
		DicomTag tag = element.GetDicomTag();
		unsigned char* value = element.GetValueField();
		int length = element.GetValueLength();
		short type = element.GetValueType();

		if(type == SQ) {
			auto sqSet = element.GetDataElements();
			this->WriteDataElements(dicomStream, sqSet);
		}

		// FixMe: Write data in correct format

		// write tag
		dicomStream.write((const char*)&tag.GroupId,2);
		dicomStream.write((const char*)&tag.ElementId,2);

		// write VT
		dicomStream.write((const char*)&type,2);

		// write value length
		dicomStream.write((const char*)&length,4);

		// write value
		dicomStream.write((const char*)&value,length);
	}
}

void DicomWriter::SortElements(DataSet* dataSet) {
	// sort the elements based on dicom tags. suggested in dicom part 05 
	dataSet->SortDataElements();
}

void DicomWriter::PadNullBytes(int count) {
	// pad with null(0x00) bytes
}

bool DicomWriter::CheckDicomMandatoryTags(list<DataElement> elements)
{
	//check for dicom mandatory tags. Like Transfer syntax etc.
	bool found = false;
	for(auto tag : this->mandatoryTags) {
		for(auto element : elements)
			if(element.GetDicomTag() == tag) found = true;

		if(!found) throw MissingMandatoryTagException("Missing tag:" + tag.ToString());
	}

	return true;
}