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

#ifndef DATA_PARSER_H
#define DATA_PARSER_H

#include <vector>

#include "DicomTag.h"

using namespace std;

namespace Dicomkit {
	namespace Sdk {
		class DataParser
		{
		public:
			static vector<float> ParseFL(unsigned char* data, int length);			//floating point single VR
			static vector<long> ParseSL(unsigned char* data, int length);			//signed long VR
			static vector<short> ParseSS(unsigned char* data, int length);			//signed short VR
			static vector<unsigned long> ParseUL(unsigned char* data, int length);	//unsigned long VR
			static vector<unsigned char> ParseOB(unsigned char* data, int length);	//other byte VR
			static vector<unsigned short> ParseUS(unsigned char* data, int length);	//unsigned short VR

			static string ParseUI(unsigned char* data, int length);					//unique identifier VR
			static string ParseSH(unsigned char* data, int length);					//shrot string VR
			static string ParseAE(unsigned char* data, int length);					//Application entity VR
			static string ParseCS(unsigned char* data, int length);					//Code string VR
			static string ParseLO(unsigned char* data, int length);					//long string VR
			static string ParsePN(unsigned char* data, int length);					//Person name VR
			static string ParseDS(unsigned char* data, int length);					//Decimal string VR
			static string ParseLT(unsigned char* data, int length);					//long text VR
			static string ParseST(unsigned char* data, int length);					//short text VR
			static string ParseAS(unsigned char* data, int length);					//Age string VR
			static string ParseDA(unsigned char* data, int length);					//Date VR
			static string ParseTM(unsigned char* data, int lenth);					//Time VR
			static string ParseIS(unsigned char* data, int lenth);					//Integer string VR
			static string ParseString(unsigned char* data, int length);				//string parser

			static DicomTag ParseAT(unsigned char* data, int lenth);				//Attribute tag VR
		};
	}
}

#endif