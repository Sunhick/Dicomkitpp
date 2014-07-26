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

#include <exception>
#include "InvalidDicomFileException.h"

using namespace std;
using namespace Dicomkit::Sdk;


InvalidDicomFileException::InvalidDicomFileException(const char* message)
	:exception(message)
{
}


InvalidDicomFileException::~InvalidDicomFileException(void)
{
}
