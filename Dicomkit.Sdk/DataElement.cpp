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
#include "DataElement.h"

#include <string>

using namespace std;
using namespace Dicomkit::Sdk;

DataElement::DataElement(void)
{
}

DataElement::DataElement(const DataElement& dataElement)
{
	this->dicomTag = DicomTag(dataElement.dicomTag.GroupId,dataElement.dicomTag.ElementId);
	this->valueLength = dataElement.valueLength;
	this->valueType  = dataElement.valueType;

	this->valueField = new unsigned char[this->valueLength];
	memcpy(this->valueField,dataElement.valueField,this->valueLength);
}

DataElement::~DataElement(void)
{
	//delete valueField;

	////delete list of data elements
	//for(list<DataElement*>::iterator it = dataElements.begin(); 
	//	it != dataElements.end(); 
	//	++it) delete *it;
}

bool DataElement::operator==(const DataElement& dataElement) const {
	return (this->dicomTag == dataElement.dicomTag);
}

void DataElement::SetDicomTag(DicomTag tag)
{
	this->dicomTag = tag;
}

void DataElement::SetData(short valueType, int valueLength, unsigned char* valueField)
{
	this->valueLength = valueLength;
	this->valueType = valueType;

	this->valueField =  new unsigned char[this->valueLength];
	memcpy(this->valueField,valueField,this->valueLength);
}

unsigned char* DataElement:: GetValueField()
{
	return this->valueField;
}

int  DataElement::GetValueLength()
{
	return this->valueLength;
}

short  DataElement::GetValueType()
{
	return this->valueType;
}

DicomTag  DataElement::GetDicomTag()
{
	return this->dicomTag;
}

void DataElement::AddDataElement(DataElement dataElement)
{
	this->dataElements.push_back(dataElement);
}

void DataElement::RemoveDataElement(DataElement dataElement)
{
	this->dataElements.remove(dataElement);
}

list<DataElement> DataElement::GetDataElements()
{
	return this->dataElements;
}