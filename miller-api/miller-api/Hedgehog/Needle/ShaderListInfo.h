#pragma once

namespace hh::needle {
    class ShaderListInfo : public NeedleRefcountObject {
    public:
        virtual VertexShader* GetVertexShader(const char* name) = 0; // tt
        virtual PixelShader* GetPixelShader(const char* name) = 0; // tt
    };
}
