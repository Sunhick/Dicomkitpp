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

#ifndef INVALID_DICOMFILE_EXP_H
#define INVALID_DICOMFILE_EXP_H

#include <exception>

using namespace std;

namespace Dicomkit {
	namespace Sdk {
		class InvalidDicomFileException : public exception {
		public:
			InvalidDicomFileException(const char* message);
			~InvalidDicomFileException(void);
		};

	}
}
#endif