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

#include "DataParser.h"

using namespace Dicomkit::Sdk;

vector<float> DataParser::ParseFL(unsigned char* data, int length)
{
	vector<float> fl;
	for (int i = 0; i < length / sizeof(float); i++) {
		float f;
		memcpy(&f, data + (i * sizeof(float)), sizeof(float));
		fl.push_back(f);
	}
	return  fl;
}

vector<long> DataParser::ParseSL(unsigned char* data, int length)
{
	vector<long> sl;
	for (int i = 0; i < length / sizeof(long); i++) {
		int j = i * 4;
		long us = data[j] | data[j + 1] << 8 | data[j + 2] << 16 | data[j + 3] << 24;
		sl.push_back(us);
	}
	return sl;
}

vector<short> DataParser::ParseSS(unsigned char* data, int length)
{
	vector<short> ss;
	for (int i = 0; i < length / sizeof(short); i++) {
		short s = data[(i * 2) + 1] << 8 | data[i * 2];
		ss.push_back(s);
	}
	return ss;
}

vector<unsigned long> DataParser::ParseUL(unsigned char* data, int length)
{
	vector<unsigned long> ul;
	for (int i = 0; i < length / sizeof(unsigned long); i++) 	{
		int j = i * sizeof(unsigned long);
		unsigned long l = data[j] | data[j + 1] << 8 | data[j + 2] << 16 | data[j + 3] << 24;
		ul.push_back(l);
	}
	return ul;
}

vector<unsigned char> DataParser::ParseOB(unsigned char* data, int length)
{
	vector<unsigned char> ob;
	for (int i = 0; i < length / sizeof(char); i++)	{
		unsigned char c;
		memcpy(&c,data + (i * sizeof(unsigned char)),sizeof(unsigned char));
		ob.push_back(c);
	}
	return ob;
}

vector<unsigned short> DataParser::ParseUS(unsigned char* data, int length)
{
	vector<unsigned short> us;
	for (int i = 0; i < length / sizeof(unsigned short); i++) {
		int j = i * sizeof(unsigned short);
		unsigned short s = data[j + 1] << 8 | data[j];
		us.push_back(s);
	}
	return us;
}

string DataParser::ParseUI(unsigned char* data, int length)
{
	return ParseString(data,length);
}

string DataParser::ParseSH(unsigned char* data, int length)
{
	return ParseString(data,length);
}

string DataParser::ParseAE(unsigned char* data, int length)
{
	return ParseString(data, length);
}

string DataParser::ParseCS(unsigned char* data, int length)
{
	return ParseString(data, length);
}

string DataParser::ParseDA(unsigned char* data, int length)
{
	return ParseString(data, length);
}

string DataParser::ParseTM(unsigned char* data, int length)
{
	return ParseString(data, length);
}

string DataParser::ParseLO(unsigned char* data, int length)
{
	return ParseString(data, length);
}

string DataParser::ParsePN(unsigned char* data, int length)
{
	return ParseString(data, length);
}

string DataParser::ParseAS(unsigned char* data, int length)
{
	return ParseString(data, length);
}

string DataParser::ParseIS(unsigned char* data, int length)
{
	return ParseString(data, length);
}

string DataParser::ParseLT(unsigned char* data, int length)
{
	return ParseString(data, length);
}

string DataParser::ParseST(unsigned char* data, int length)
{
	return ParseString(data, length);
}

DicomTag DataParser::ParseAT(unsigned char* data, int length)
{
	int at1 = data[1] << 8 | data[0];
	int at2 = data[3] << 8 | data[2];

	return DicomTag(at1, at2);
}

string DataParser::ParseDS(unsigned char* data, int length)
{
	return ParseString(data, length);
}

string DataParser::ParseString(unsigned char* data, int length)
{
	return string((char*)data, length);
}