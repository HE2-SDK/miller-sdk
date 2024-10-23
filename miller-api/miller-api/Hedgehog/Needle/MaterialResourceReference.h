#pragma once

#define NEEDLE_RESOURCE_MATERIAL_REFERENCE 0x303046455254414Dui64 // '00FERTAM'

namespace hh::needle {
    class MaterialResourceReference : TResourceReference<MaterialResource, NEEDLE_RESOURCE_MATERIAL_REFERENCE> {
    public:
        static MaterialResourceReference* Create();
    };

}