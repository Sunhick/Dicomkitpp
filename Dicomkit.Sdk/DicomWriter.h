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

#ifndef DICOM_WRITER_H
#define DICOM_WRITER_H

#include <string>
#include <fstream>
#include <iostream>
#include <exception>

#include "DataSet.h"

using namespace std;

namespace Dicomkit {
	namespace Sdk {
		class DicomWriter
		{
		private:
			DataSet* dataSet;
			void Init();

			void WriteHeader(ofstream& dicomStream, DataSet* dataSet);
			void WriteDataElements(ofstream& dicomStream, DataSet* dataSet);
			void SortElements();
			void PadNullBytes(int count);
			void CheckDicomMandatoryTags();
		public:
			DicomWriter(void);
			~DicomWriter(void);

			void AddDataElement(DataElement dataElement);
			void Save(string fileName);
			void Save(DataSet* dataSet, string fileName);
		};

		class MissingMandatoryTagException : public exception 
		{
		public:
			MissingMandatoryTagException(char* message) : exception(message) {}
			MissingMandatoryTagException() : exception() {}
			~MissingMandatoryTagException() {}
		};
	}
}
#endif