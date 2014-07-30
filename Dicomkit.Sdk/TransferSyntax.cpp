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
#include "TransferSyntax.h"

using namespace Dicomkit::Sdk;

TransferSyntax::TransferSyntax(void)
{
}


TransferSyntax::~TransferSyntax(void)
{
}

bool TransferSyntax::IsImplicitVr()
{
	return this->isImplicitVr;
}

bool TransferSyntax::IsLittleEndian()
{
	return this->isLittleEndian;
}

DicomTag TransferSyntax::GetTransferSyntaxTag()
{
	return this->transferTag;
}

string TransferSyntax::GetTransferSyntaxUid()
{
	return this->transferSyntaxUid;
}

void TransferSyntax::SetTransferSyntaxUid(string uid)
{
	const char* transferUid = uid.c_str();
	transferSyntaxUid = transferUid;

	if(strcmp(transferUid, Implicit_VR_Little_Endian) == 0) {
		isImplicitVr = isLittleEndian = true;
	} else if(strcmp(transferUid, Explicit_VR_Little_Endian) == 0) {
		isImplicitVr = false;
		isLittleEndian = true;
	} else if(strcmp(transferUid,Explicit_VR_Big_Endian) == 0) {
		isLittleEndian = isImplicitVr = false;
	} else if(strcmp(transferUid, Deflated_Explicit_VR_Little_Endian) == 0) {
		char buf[30];
		sprintf_s(buf,"%s is not supported Dicom transfer syntax!",Deflated_Explicit_VR_Little_Endian);
		throw NotSupportedTransferSyntax(buf);
	}
}