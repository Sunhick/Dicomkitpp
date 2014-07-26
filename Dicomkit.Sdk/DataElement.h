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

#ifndef DATA_ELEMENT_H
#define DATA_ELEMENT_H

#include "DicomTag.h"

namespace Dicomkit {
	namespace Sdk {
		class DataElement
		{
		private:
			DicomTag dicomTag;
			short valueType;
			int valueLength;
			unsigned char* valueField;
		public:
			DataElement(void);
			DataElement(const DataElement& dataElement);
			~DataElement(void);

			unsigned char* GetValueField();
			int GetValueLength();
			short GetValueType();
			DicomTag GetDicomTag();

			void SetDicomTag(DicomTag tag);
			void SetData(short valueType, int valueLength, unsigned char* valueField);
		};

	}
}
#endif