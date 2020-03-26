//////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2016, Esteban Tovagliari. All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are
//  met:
//
//	 * Redistributions of source code must retain the above copyright
//	   notice, this list of conditions and the following disclaimer.
//
//	 * Redistributions in binary form must reproduce the above copyright
//	   notice, this list of conditions and the following disclaimer in the
//	   documentation and/or other materials provided with the distribution.
//
//	 * Neither the name of Image Engine Design nor the names of any
//	   other contributors to this software may be used to endorse or
//	   promote products derived from this software without specific prior
//	   written permission.
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

#ifndef IECOREAPPLESEED_PROGRESS_TILE_CALLBACK_H
#define IECOREAPPLESEED_PROGRESS_TILE_CALLBACK_H

#include "IECoreAppleseed/Export.h"

#include "boost/thread/mutex.hpp"

#include "foundation/memory/autoreleaseptr.h"
#include "renderer/api/rendering.h"

namespace IECoreAppleseed
{

/// An appleseed tile callback that logs the render progress
/// using appleseed logging system.
class IECOREAPPLESEED_API ProgressTileCallback : public renderer::TileCallbackBase
{

	public :

		ProgressTileCallback();

		void release() override;

		void on_tile_end( const renderer::Frame *frame, const size_t tileX, const size_t tileY ) override;

	protected :

		void log_progress( const renderer::Frame *frame, const size_t tileX, const size_t tileY );

		boost::mutex m_mutex;
		size_t m_renderedPixels;
};

class IECOREAPPLESEED_API ProgressTileCallbackFactory : public renderer::ITileCallbackFactory
{

	public :

		ProgressTileCallbackFactory();

		void release() override;

		renderer::ITileCallback* create() override;

	private :

		foundation::auto_release_ptr<renderer::ITileCallback> m_callback;
};

} // namespace IECoreAppleseed

#endif // IECOREAPPLESEED_PROGRESS_TILE_CALLBACK_H
