/**
 * Copyright (c) 2006-2020 LOVE Development Team
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 **/

#pragma once

#include "graphics/Buffer.h"
#include "Metal.h"

namespace love
{
namespace graphics
{
namespace metal
{

class Buffer final : public love::graphics::Buffer
{
public:

	Buffer(id<MTLDevice> device, size_t size, const void *data, BufferType type, vertex::Usage usage, uint32 mapflags);
	virtual ~Buffer();

	void *map() override;
	void unmap() override;
	void setMappedRangeModified(size_t offset, size_t size) override;
	void fill(size_t offset, size_t size, const void *data) override;
	ptrdiff_t getHandle() const override { return (ptrdiff_t) buffer; }

	void copyTo(size_t offset, size_t size, love::graphics::Buffer *other, size_t otheroffset) override;

private:

	id<MTLBuffer> buffer;
	char *memoryMap;

	NSRange mappedRange;

}; // Buffer

} // metal
} // graphics
} // love