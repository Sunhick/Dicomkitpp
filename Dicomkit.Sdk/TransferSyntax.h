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
#ifndef TRANSFER_SYNTAX_H
#define TRANSFER_SYNTAX_H

#include <string>
#include <exception>

#include "DicomTag.h"

using namespace std;

#define Implicit_VR_Little_Endian											"1.2.840.10008.1.2"
#define Explicit_VR_Little_Endian											"1.2.840.10008.1.2.1"
#define Deflated_Explicit_VR_Little_Endian									"1.2.840.10008.1.2.1.99"
#define Explicit_VR_Big_Endian												"1.2.840.10008.1.2.2"
#define MPEG2_Image_Compression												"1.2.840.10008.1.2.4.100"
#define JPEG_Baseline_Process_1												"1.2.840.10008.1.2.4.50"
#define JPEG_Extended_Process_2_4											"1.2.840.10008.1.2.4.51"
#define JPEG_Extended_Process_3_5											"1.2.840.10008.1.2.4.52"
#define JPEG_Spectral_Selection_NonHierarchical_Process_6_8					"1.2.840.10008.1.2.4.53"
#define JPEG_Spectral_Selection_NonHierarchical_Process_7_9					"1.2.840.10008.1.2.4.54"
#define JPEG_Full_Progression_NonHierarchical_Process_10_12					"1.2.840.10008.1.2.4.55"
#define JPEG_Full_Progression_NonHierarchical_Process_11_13					"1.2.840.10008.1.2.4.56"
#define JPEG_Lossless_NonHierarchical_Process_14							"1.2.840.10008.1.2.4.57"
#define JPEG_Lossless_NonHierarchical_Process_15							"1.2.840.10008.1.2.4.58"
#define JPEG_Extended_Hierarchical_Process_16_18							"1.2.840.10008.1.2.4.59"
#define JPEG_Extended_Hierarchical_Process_17_19							"1.2.840.10008.1.2.4.60"
#define JPEG_Spectral_Selection_Hierarchical_Process_20_22					"1.2.840.10008.1.2.4.61"
#define JPEG_Spectral_Selection_Hierarchical_Process_21_23					"1.2.840.10008.1.2.4.62"
#define JPEG_Full_Progression_Hierarchical_Process_24_26					"1.2.840.10008.1.2.4.63"
#define JPEG_Full_Progression_Hierarchical_Process_25_27					"1.2.840.10008.1.2.4.64"
#define JPEG_Lossless_Hierarchical_Process_28								"1.2.840.10008.1.2.4.65"
#define JPEG_Lossless_Hierarchical_Process_29								"1.2.840.10008.1.2.4.66"
#define JPEG_Lossless_NonHierarchical_First_Order_Prediction_Process_14 	"1.2.840.10008.1.2.4.70"
#define JPEG_LS_Lossless													"1.2.840.10008.1.2.4.80"
#define JPEG_LS_Near_Lossless												"1.2.840.10008.1.2.4.81"
#define JPEG_2000_Lossless													"1.2.840.10008.1.2.4.90"
#define JPEG_2000_Either													"1.2.840.10008.1.2.4.91"
#define JPEG_2000_Lossless_Multi_Component									"1.2.840.10008.1.2.4.92"
#define JPEG_2000_Either_Multi_Component									"1.2.840.10008.1.2.4.93"
#define RLE_Lossless														"1.2.840.10008.1.2.5"

namespace Dicomkit {
	namespace Sdk {
		class TransferSyntax {
		private:
			bool isImplicitVr;
			bool isLittleEndian;
			string transferSyntaxUid;
			static DicomTag transferTag;
		public:
			TransferSyntax(void);
			~TransferSyntax(void);

			static DicomTag GetTransferSyntaxTag();

			bool IsImplicitVr();
			bool IsLittleEndian();
			string GetTransferSyntaxUid();
			void SetTransferSyntaxUid(string uid);
		};

		class NotSupportedTransferSyntax : public exception {
		public:
			NotSupportedTransferSyntax(char* message) : exception(message) {}
			NotSupportedTransferSyntax() : exception() {}
			~NotSupportedTransferSyntax() {}
		};
	}
}
#endif