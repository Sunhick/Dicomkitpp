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

#ifndef DICOM_READER_H
#define DICOM_READER_H

#include "DataSet.h"

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

namespace Dicomkit {
	namespace Sdk {

		class DicomReader 
		{
		private:
			string fileName;
			ifstream* reader;

			bool IsValidDicomFile();
			bool FileExists(const std::string& name);

			string GetLog(short groupId, short elementId, char* valType);
			unsigned char* ReadBytes(int count);
			string ReadString(int count);
			short ReadShort();
			int ReadInt(int count);

		public:
			DicomReader(string fileName);
			~DicomReader(void);

			void Dump();
			DataSet ParseDicom();
		};

	}
}

#endif