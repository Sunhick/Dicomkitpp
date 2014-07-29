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

#ifndef DICOM_DUMP_H
#define DICOM_DUMP_H 

#include <string>
#include <list>

#include "..\Dicomkit.Sdk\DicomReader.h"

using namespace std;
using namespace Dicomkit::Sdk;

namespace Dicomkit {
	namespace Dump {

		class DicomDump
		{
		private:
			string fileName;
			DicomReader* dicomReader;

			string GetLog(short groupId, short elementId, char* valType);
			void DumpLog(list<DataElement*> dataElement, ostream& out);
		public:
			DicomDump(string fileName);
			~DicomDump(void);
			void Dump(ostream& out);
		};
	}
}

#endif