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

#include "DataSet.h"

#include <string>

using namespace std;
using namespace Dicomkit::Sdk;

DataSet::DataSet(void) {
}

DataSet::~DataSet(void) {
	this->dataElements.clear();
}

void DataSet::SetPreamble(char* preamble) {
	memcpy(this->preamble,preamble,128);
}

void DataSet::SetPrefix(char* prefix) {
	memcpy(this->prefix, prefix,4);
}

void DataSet::AddDataElement(DataElement dataElement) {
	this->dataElements.push_back(DataElement(dataElement));
}

list<DataElement> DataSet::GetDataElements() {
	return this->dataElements;
}

char* DataSet::GetPreamble() {
	return this->preamble;
}

char* DataSet::GetPrefix() {
	return this->prefix;
}

bool DataSet::IsEmpty() {
	return (this->dataElements.size() > 0);
}

void DataSet::SortDataElements() {
	this->dataElements.sort( [](const DataElement& first, const DataElement& second) 
								{
									auto firstTag = first.GetDicomTag();
									auto secondTag = second.GetDicomTag();

									// primary sort key: Group Id.
									// secondary sort key: Element Id
									return (firstTag.GroupId == secondTag.GroupId) ?
										firstTag.ElementId < secondTag.ElementId 
										: firstTag.GroupId < secondTag.GroupId;
								});
}