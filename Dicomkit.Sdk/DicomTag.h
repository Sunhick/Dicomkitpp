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

#ifndef DICOM_TAG
#define DICOM_TAG

namespace Dicomkit {
	namespace Sdk {
		struct DicomTag
		{
			DicomTag(){}

			DicomTag(unsigned short groupId, unsigned short elementId) {
				this->GroupId = groupId;
				this->ElementId = elementId;
			}

			unsigned short GroupId;
			unsigned short ElementId;

			bool operator==(DicomTag tag) {
				return (tag.GroupId == this->GroupId && tag.ElementId == this->ElementId);
			}
		};

	}
}
#endif