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

#include "DicomReader.h"
#include "ValueRepresentation.h"
#include "InvalidDicomFileException.h"

using namespace Dicomkit::Sdk;

DicomReader::DicomReader(string fileName)
{
	this->fileName = fileName;

	if(!FileExists(fileName)) {
		char message[20];
		sprintf_s(message,sizeof(message), "File: %s not found!",fileName.c_str());
		throw exception(message);
	}

	this->reader = new ifstream(fileName, ios::in | ios::binary);

	if(!reader)	
		throw exception("Error occured in opening the file");
}

bool DicomReader::FileExists(const std::string& name)
{
	return true;
}

DicomReader::~DicomReader(void)
{
}

bool DicomReader::IsValidDicomFile()
{
	//read prefix: 4bytes 'DICM'
	char prefix[4];
	!reader->read(prefix,4);

	string dicm(prefix,4);

	return (strcmp(dicm.c_str(),"DICM") == 0);
}

DataSet DicomReader::ParseDicom()
{
	DataSet dataSet;

	//preamble
	char preamble[128];
	reader->read(preamble,128);
	dataSet.SetPreamble(preamble);

	//check next 4bytes for "DICM"
	if(!IsValidDicomFile()) 
		throw new InvalidDicomFileException("Not a valid DICOM file");

	dataSet.SetPrefix("DICM");

	//read Data elements in Dataset
	while(!reader->eof()) {
		DataElement* dataElement = ParseDataElement();
		dataSet.AddDataElement(dataElement);
	}


	return dataSet;
}

DataElement* DicomReader::ParseDataElement()
{
	//read group Id
	short groupId = ReadShort();

	//read element Id
	short elementId = ReadShort();

	//value type
	short valueType = ReadShort();//ReadString(2);

	bool isImplicitVr = false;
	if (valueType == OB || valueType == OW || valueType == SQ || valueType == UN) {
		reader->seekg(2, ios::cur);
		isImplicitVr = true;
	}

	DataElement* dataElement = new DataElement;
	dataElement->SetDicomTag(DicomTag(groupId, elementId));

	//value length
	int valLen = ReadInt(isImplicitVr ? 4 : 2);

	//For item sequences
	if (valueType == SQ) {
		int limit = valLen + reader->tellg();

		while (reader->tellg() < limit) {
			DataElement* de = ParseDataElement();
			dataElement->AddDataElement(de);
		}
		valLen = 0; //read no data for SQ
	}

	//value
	unsigned char* data = ReadBytes(valLen > 0 ? valLen : 0);

	dataElement->SetData(valueType, valLen, data);

	delete[] data;
	return dataElement;
}

void DicomReader::Dump()
{
	//skip preamble : 128 bits at the begining
	reader->seekg(128, ios::beg);

	//check next 4bytes for "DICM"
	if(!IsValidDicomFile()) 
		throw new InvalidDicomFileException("Not a valid DICOM file");

	//read Data elements in Dataset
	while(!reader->eof()) {

		//read group Id
		short groupId = ReadShort();

		//read element Id
		short elementId = ReadShort();

		//value type
		short valueType = ReadShort();//ReadString(2);

		bool isImplicitVr = false;
		if(valueType == OB || valueType == OW || valueType == SQ || valueType == UN) {
			reader->seekg(2, ios::cur);
			isImplicitVr = true;
		}

		//value length
		int valLen = ReadInt(isImplicitVr ? 4 : 2);

		//value
		unsigned char* data = ReadBytes(valLen > 0 ? valLen : 0);

		string message;

		switch(valueType) {
		case UL:
			{
				unsigned long ulong = data[0] | data[1] << 8 | data[2] << 16 | data[3] << 24;
				message = GetLog(groupId,elementId, "UL");
				cout<<message<<ulong<<endl;
			}
			break;
		case OB:
			{
				message = GetLog(groupId,elementId, "OB");
				cout<<message<<endl;
			}
			break;
		case UI:
			{
				message = GetLog(groupId,elementId, "UI");
				string uid((char*)data, valLen);
				cout<<message<<uid.c_str()<<endl;
			}
			break;
		case SH:
			{
				message = GetLog(groupId,elementId, "SH");
				string uid((char*)data, valLen);
				cout<<message<<uid.c_str()<<endl;
			}
			break;
		case AE:
			{
				message = GetLog(groupId,elementId, "AE");
				string uid((char*)data, valLen);
				cout<<message<<uid.c_str()<<endl;
			}
			break;
		case CS:
			{
				message = GetLog(groupId,elementId, "CS");
				string uid((char*)data, valLen);
				cout<<message<<uid.c_str()<<endl;
			}
			break;
		case DA:
			{
				message = GetLog(groupId,elementId, "DA");
				string uid((char*)data, valLen);
				cout<<message<<uid.c_str()<<endl;
			}
			break;
		case TM:
			{
				message = GetLog(groupId,elementId, "TM");
				string uid((char*)data, valLen);
				cout<<message<<uid.c_str()<<endl;
			}
			break;
		case LO:
			{
				message = GetLog(groupId,elementId, "LO");
				string uid((char*)data, valLen);
				cout<<message<<uid.c_str()<<endl;
			}
			break;
		case PN:
			{
				message = GetLog(groupId,elementId, "PN");
				string uid((char*)data, valLen);
				cout<<message<<uid.c_str()<<endl;
			}
			break;
		case SQ:
			message = GetLog(groupId,elementId, "SQ");
			cout<<message<<endl;
			break;
		case AS:
			{
				message = GetLog(groupId,elementId, "AS");
				string uid((char*)data, valLen);
				cout<<message<<uid.c_str()<<endl;
			}
			break;
		case DS:
			{
				message = GetLog(groupId,elementId, "DS");
				string uid((char*)data, valLen);
				cout<<message<<uid.c_str()<<endl;
			}
			break;
		case IS:
			{
				message = GetLog(groupId,elementId, "IS");
				string uid((char*)data, valLen);
				cout<<message<<uid.c_str()<<endl;
			}
			break;
		case US:
			{
				short us = data[1] << 8 | data[0];
				message = GetLog(groupId,elementId, "US");
				cout<<message<<us<<endl;
			}
			break;
		case LT:
			{
				message = GetLog(groupId,elementId, "LT");
				string uid((char*)data, valLen);
				cout<<message<<uid.c_str()<<endl;
			}
			break;
		case ST:
			{
				message = GetLog(groupId,elementId, "ST");
				string uid((char*)data, valLen);
				cout<<message<<uid.c_str()<<endl;
			}
			break;
		case OW:
			message = GetLog(groupId,elementId, "OW");
			cout<<message<<endl;
			break;
		default :
			{
				message = GetLog(groupId,elementId, "AT");
				int at1 = data[1] << 8 | data[0];
				int at2 = data[3] << 8 | data[2];
				
				char buf[20];
				sprintf_s(buf, sizeof(buf),"(%04x,%04x)",at1,at2);
				cout<<message<<buf<<endl;
			}
		}

		delete[] data;
	}

	cout<<"End of file"<<endl;
}

string DicomReader::GetLog(short groupId, short elementId, char* valType)
{
	char message[40];
	sprintf_s(message,sizeof(message), "<%04x,%04x> \t %s \t",groupId, elementId, valType);
	return message;
}


int DicomReader::ReadInt(int count = 4)
{
	unsigned char* bytes = ReadBytes(count);

	unsigned int value;
	if(count == 4) {
		value = bytes[3] << 24 | bytes[2] << 16 | bytes[1] << 8 | bytes[0];
	}
	else {
		value = bytes[1] << 8 | bytes[0];
	}

	delete bytes;
	return value;
}

short DicomReader::ReadShort()
{
	unsigned char* bytes = ReadBytes(2);
	short value = bytes[1] << 8 | bytes[0];

	delete bytes;
	return value;
}

string DicomReader::ReadString(int count)
{
	unsigned char* bytes = ReadBytes(count);
	string value((char*)bytes,count);

	delete bytes;
	return value;
}

unsigned char* DicomReader::ReadBytes(int count)
{
	unsigned char* bytes = new unsigned char[count];
	reader->read((char*)bytes, count);

	return bytes;
}


