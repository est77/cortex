//////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2008-2009, Image Engine Design Inc. All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are
//  met:
//
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//
//     * Neither the name of Image Engine Design nor the names of any
//       other contributors to this software may be used to endorse or
//       promote products derived from this software without specific prior
//       written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
//  IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
//  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
//  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
//  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
//  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
//  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
//  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
//  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
//  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
//  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//////////////////////////////////////////////////////////////////////////

#ifndef IE_CORE_SCALEDDATACONVERSION_H
#define IE_CORE_SCALEDDATACONVERSION_H

#include "IECore/DataConversion.h"

#include "boost/static_assert.hpp"

namespace IECore
{

/// A DataConversion which converts one numeric type to another, maximising the use of the range of the target type.
/// For example, converting a char value of 127 (half way through the range of the char type) to a short would yield
/// a short value of 32767 (half way through the range of the short type). Care is taken when dealing with floating
/// point types, which are assumed to have no practical "range". So, in the example above, a char value of 127 when
/// converter to float, double, or half, would have a value of approximately 0.498 (127/255).
///
/// When conversion is attempted between a signed type and an unsigned type, appropriate clamping is performed.
///
/// This conversion is employed primarily in the ImageWriter-derived classes.
template<typename F, typename T, typename Enable = void>
struct ScaledDataConversion : public DataConversion< F, T >
{
	T operator()( F f ) const
	{
		BOOST_STATIC_ASSERT( sizeof(T) == 0 );
	}
};

} // namespace IECore

#include "ScaledDataConversion.inl"

#endif // IE_CORE_SCALEDDATACONVERSION_H
