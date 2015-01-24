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

#ifndef DATA_ELEMENT_H
#define DATA_ELEMENT_H

#include <list>
#include "DicomTag.h"

using namespace std;

namespace Dicomkit {
	namespace Sdk {
		class DataElement
		{
		private:
			DicomTag dicomTag;
			unsigned short valueType;
			int valueLength;
			unsigned char* valueField;
			list<DataElement> dataElements;	//Sequence items(SQ)
		public:
			DataElement(void);
			DataElement(const DataElement& dataElement);
			~DataElement(void);

			bool operator==(const DataElement& dataElement) const;

			unsigned char* GetValueField();
			int GetValueLength();
			short GetValueType();
			DicomTag GetDicomTag();
			list<DataElement> GetDataElements();

			void SetDicomTag(DicomTag tag);
			void SetData(short valueType, int valueLength, unsigned char* valueField);
			
			void AddDataElement(DataElement dataElement);
			void RemoveDataElement(DataElement dataElement);
		};

	}
}
#endif