#ifndef LOVE_GRAPHICS_VULKAN_VULKAN_H
#define LOVE_GRAPHICS_VULKAN_VULKAN_H

#include "graphics/Graphics.h"
#include "vulkan/vulkan.h"

namespace love {
	namespace graphics {
		namespace vulkan {
			struct TextureFormat {
				VkFormat internalFormat = VK_FORMAT_UNDEFINED;

				VkComponentSwizzle swizzleR = VK_COMPONENT_SWIZZLE_IDENTITY;
				VkComponentSwizzle swizzleG = VK_COMPONENT_SWIZZLE_IDENTITY;
				VkComponentSwizzle swizzleB = VK_COMPONENT_SWIZZLE_IDENTITY;
				VkComponentSwizzle swizzleA = VK_COMPONENT_SWIZZLE_IDENTITY;
			};

			class Vulkan {
			public:
				static VkFormat getVulkanVertexFormat(DataFormat format);
				static TextureFormat getTextureFormat(PixelFormat);
				static std::string getVendorName(uint32_t vendorId);
				static std::string getVulkanApiVersion(uint32_t apiVersion);
			};
		}
	}
}

#endif