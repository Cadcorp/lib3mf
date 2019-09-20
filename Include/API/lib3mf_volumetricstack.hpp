/*++

Copyright (C) 2019 3MF Consortium (Original Author)

All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

Abstract: This is the class declaration of CVolumetricStack

*/


#ifndef __LIB3MF_VOLUMETRICSTACK
#define __LIB3MF_VOLUMETRICSTACK

#include "lib3mf_interfaces.hpp"

// Parent classes
#include "lib3mf_resource.hpp"
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4250)
#endif

// Include custom headers here.
#include "Model/Classes/NMR_ModelVolumetricStack.h"

namespace Lib3MF {
namespace Impl {


/*************************************************************************************************************************
 Class declaration of CVolumetricStack 
**************************************************************************************************************************/

class CVolumetricStack : public virtual IVolumetricStack, public virtual CResource {
private:


protected:
	NMR::PModelVolumetricStack m_pVolumetricStack;
	NMR::PModel m_pModel;

public:

	CVolumetricStack(NMR::PModelVolumetricStack pVolumetricStack, NMR::PModel pModel);

	Lib3MF_uint32 GetDestinationChannelCount();

	void GetDestinationChannel(const Lib3MF_uint32 nIndex, std::string & sName, Lib3MF_double & dBackground);

	Lib3MF_uint32 AddDestinationChannel(const std::string & sName, const Lib3MF_double dBackground);

	void UpdateDestinationChannel(const Lib3MF_uint32 nIndex, const Lib3MF_double dBackground);

	void UpdateDestinationChannelByName(const std::string & sName, const Lib3MF_double dBackground);

	void RemoveDestinationChannel(const Lib3MF_uint32 nIndex);

	void RemoveDestinationChannelByName(const std::string & sName);

	Lib3MF_uint32 GetLayerCount();

	IVolumetricLayer * GetLayer(const Lib3MF_uint32 nIndex);

	IVolumetricLayer * AddLayer(const Lib3MF::sTransform Transform, const Lib3MF::eBlendMethod eBlendMethod);

	void ReindexLayer(IVolumetricLayer* pLayer, const Lib3MF_uint32 nIndex);

	void RemoveLayer(IVolumetricLayer* pLayer);

	void RemoveLayerByIndex(const Lib3MF_uint32 nIndex);

	void Clear();

	void ClearUnusedDestinationChannels();

};

} // namespace Impl
} // namespace Lib3MF

#ifdef _MSC_VER
#pragma warning(pop)
#endif
#endif // __LIB3MF_VOLUMETRICSTACK