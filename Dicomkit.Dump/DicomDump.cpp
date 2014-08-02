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

#include <vector>

#include "DicomDump.h"
#include "..\Dicomkit.Sdk\DataSet.h"
#include "..\Dicomkit.Sdk\DataParser.h"
#include "..\Dicomkit.Sdk\ValueRepresentation.h"

using namespace std;
using namespace Dicomkit::Dump;

DicomDump::DicomDump(string fileName)
{
	this->fileName = fileName;
	this->dicomReader = new DicomReader(fileName);
}


DicomDump::~DicomDump(void)
{
}

void DicomDump::Dump(ostream& out)
{
	out<<"Dumping dicom contents..."<<endl;
	//this->dicomReader->Dump();

	DataSet dataSet = this->dicomReader->ParseDicom();
	list<DataElement*> dataElements = dataSet.GetDataElements();

	DumpLog(dataElements, out);
}

void DicomDump::DumpLog(list<DataElement*> dataElements, ostream& out)
{
	for (list<DataElement*>::iterator dataElement1 = dataElements.begin();
		dataElement1 != dataElements.end();
		++dataElement1) {
			string message;

			DataElement* dataElement = *dataElement1;

			unsigned short valueType = dataElement->GetValueType();
			unsigned short groupId = dataElement->GetDicomTag().GroupId;
			unsigned short elementId = dataElement->GetDicomTag().ElementId;
			int valLen = dataElement->GetValueLength();

			//skip Item sequence.
			if (groupId == 0xfffe && elementId == 0xe000) continue;

			switch (valueType) {
			case FL:
				{
					out << GetLog(groupId, elementId, "FL");
					vector<float> fl = DataParser::ParseFL(dataElement->GetValueField(), dataElement->GetValueLength());

					for (int i = 0; i < fl.size(); i++) 
						out << fl[i] << " ";
				}
				break;
			case SL:
				{
					out << GetLog(groupId, elementId, "SL");
					vector<long> us = DataParser::ParseSL(dataElement->GetValueField(), dataElement->GetValueLength());

					for (int i = 0; i < us.size(); i++)
						out << us[i] << " ";
				}
				break;
			case SS:
				{
					out << GetLog(groupId, elementId, "SS");
					vector<short> ss = DataParser::ParseSS(dataElement->GetValueField(), dataElement->GetValueLength());

					for(vector<short>::iterator it = ss.begin(); it != ss.end(); ++it)
						out << *it << " ";
				}
				break;
			case UL:
				{
					out << GetLog(groupId, elementId, "UL");
					vector<unsigned long> ul = DataParser::ParseUL(dataElement->GetValueField(), dataElement->GetValueLength());

					for(vector<unsigned long>::iterator it = ul.begin(); it != ul.end(); ++it)
						out << *it << " ";
				}
				break;
			case OB:
				{
					out << GetLog(groupId, elementId, "OB");
					vector<unsigned char> ob = DataParser::ParseOB(dataElement->GetValueField(), dataElement->GetValueLength());

					for (int i = 0; i < ob.size(); i++)
						out << (unsigned short)ob[i] << " ";
				}
				break;
			case UI:
				{
					out << GetLog(groupId, elementId, "UI") 
						<< DataParser::ParseUI(dataElement->GetValueField(), valLen).c_str();
				}
				break;
			case SH:
				{
					out << GetLog(groupId, elementId, "SH") 
						<< DataParser::ParseSH(dataElement->GetValueField(), valLen).c_str() ;
				}
				break;
			case AE:
				{
					out << GetLog(groupId, elementId, "AE")
						<< DataParser::ParseAE(dataElement->GetValueField(), valLen).c_str();
				}
				break;
			case CS:
				{
					out << GetLog(groupId, elementId, "CS")
						<< DataParser::ParseCS(dataElement->GetValueField(), valLen).c_str();
				}
				break;
			case DA:
				{
					out << GetLog(groupId, elementId, "DA")
						<< DataParser::ParseDA(dataElement->GetValueField(), valLen).c_str();
				}
				break;
			case TM:
				{
					out << GetLog(groupId, elementId, "TM")
						<< DataParser::ParseTM(dataElement->GetValueField(), valLen).c_str();
				}
				break;
			case LO:
				{
					out << GetLog(groupId, elementId, "LO")
						<<DataParser::ParseLO(dataElement->GetValueField(), valLen).c_str();
				}
				break;
			case PN:
				{
					out << GetLog(groupId, elementId, "PN")
						<< DataParser::ParsePN(dataElement->GetValueField(), valLen).c_str();
				}
				break;
			case SQ:
				{
					out << GetLog(groupId, elementId, "SQ");
					out << "[-----------SEQ START-----------" << endl;
					DumpLog(dataElement->GetDataElements(), out);
					out << "-----------SEQ END-------------]";
				}
				break;
			case AS:
				{
					out << GetLog(groupId, elementId, "AS") 
						<<DataParser::ParseAS(dataElement->GetValueField(), valLen).c_str();
				}
				break;
			case DS:
				{
					out << GetLog(groupId, elementId, "DS")
						<< DataParser::ParseDS(dataElement->GetValueField(), valLen).c_str();
				}
				break;
			case IS:
				{
					out << GetLog(groupId, elementId, "IS")
						<< DataParser::ParseIS(dataElement->GetValueField(), valLen).c_str();
				}
				break;
			case US:
				{
					out << GetLog(groupId, elementId, "US");
					vector<unsigned short> us = DataParser::ParseUS(dataElement->GetValueField(), dataElement->GetValueLength());

					for (vector<unsigned short>::iterator it = us.begin(); it != us.end(); ++it)
						out << *it << " ";
				}
				break;
			case LT:
				{
					out << GetLog(groupId, elementId, "LT")
						<< DataParser::ParseLT(dataElement->GetValueField(), valLen).c_str();
				}
				break;
			case ST:
				{
					out << GetLog(groupId, elementId, "ST")
						<< DataParser::ParseST(dataElement->GetValueField(), valLen).c_str();
				}
				break;
			case OW:
				{
					out << GetLog(groupId, elementId, "OW");	//mostly pixel data.

					// uncommented below code for printing out hex re-presentation of pixel data
					/*unsigned char* data = dataElement->GetValueField();
					for (int i = 0; i  < dataElement->GetValueLength(); i++) {
					out << hex << (unsigned short)*(data+i) << " ";
					}*/
				}
				break;
			case AT:
				{
					out << GetLog(groupId, elementId, "AT");
					DicomTag tag = DataParser::ParseAT(dataElement->GetValueField(), dataElement->GetValueLength());

					char buf[20];
					sprintf_s(buf, sizeof(buf), "(%04x,%04x)", tag.GroupId, tag.ElementId);
					out << message << buf;
				}
			default:
				out << GetLog(groupId, elementId, "--");
				break;
			}

			out << endl;
	}
}

string DicomDump::GetLog(short groupId, short elementId, char* valType)
{
	char message[40];
	sprintf_s(message,sizeof(message), "<%04x,%04x> \t %s \t",groupId, elementId, valType);
	return message;
}