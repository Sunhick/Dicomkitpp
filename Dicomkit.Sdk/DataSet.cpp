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

#include <string>

#include "DataSet.h"

using namespace std;
using namespace Dicomkit::Sdk;

DataSet::DataSet(void)
{
}

DataSet::~DataSet(void)
{
	////delete list of data elements
	//for(list<DataElement*>::iterator it = dataElements.begin(); 
	//	it != dataElements.end(); 
	//	++it) delete *it;
}

void DataSet::SetPreamble(char* preamble)
{
	memcpy(this->preamble,preamble,128);
}

void DataSet::SetPrefix(char* prefix)
{
	memcpy(this->prefix, prefix,4);
}

void DataSet::AddDataElement(DataElement dataElement)
{
	this->dataElements.push_back(DataElement(dataElement));
}

list<DataElement> DataSet::GetDataElements()
{
	return this->dataElements;
}

char* DataSet::GetPreamble()
{
	return this->preamble;
}

char* DataSet::GetPrefix()
{
	return this->prefix;
}

bool DataSet::IsEmpty()
{
	return (this->dataElements.size() > 0);
}