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

#ifndef DATA_SET_H
#define DATA_SET_H

#include <list>

#include "DataElement.h"

using namespace std;

namespace Dicomkit {
	namespace Sdk {
		class DataSet
		{
		private:
			char preamble[128];					//128 bit preamble
			char prefix[4];						//4 bit dicom prefix "DICM"
			list<DataElement*> dataElements;		//Data elements			
		public:
			DataSet(void);
			~DataSet(void);

			list<DataElement*> GetDataElements();

			void SetPreamble(char* preamble);
			void SetPrefix(char* prefix);
			char* GetPreamble();
			char* GetPrefix();

			bool IsEmpty();
			void AddDataElement(DataElement dataElement);
			void AddDataElement(DataElement* dataElement);
			void RemoveDataElement(DataElement* dataElement);
		};

	}
}
#endif