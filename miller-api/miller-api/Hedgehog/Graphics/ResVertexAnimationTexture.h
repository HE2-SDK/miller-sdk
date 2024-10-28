#pragma once

namespace hh::gfx {
    struct VertexAnimationTextureRange {
        float min;
        float max;
    };

    enum class VertextAnimationTextureType : unsigned int {

    };

    struct VertexAnimationTextureData {
        unsigned int version;
        const char* textureName;
        const char* normalTextureName;
        VertextAnimationTextureType type;
        VertexAnimationTextureRange positionRange;
        VertexAnimationTextureRange rotationRange;
        VertexAnimationTextureRange scaleRange;
        unsigned int fps;
        unsigned int frameCount;
    };

    class ResVertexAnimationTexture : fnd::ManagedResource {
    public:
        VertexAnimationTextureData* vatData;
        hh::fnd::Reference<gfnd::ResTexture>* texture;
        hh::fnd::Reference<gfnd::ResTexture>* normalsTexture;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Resolve(fnd::ResourceResolver& resolver) override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResVertexAnimationTexture);

        VertexAnimationTextureRange GetPositionRange() const;
        VertexAnimationTextureRange GetRotationRange() const;
        VertexAnimationTextureRange GetScaleRange() const;
        VertextAnimationTextureType GetType() const;
        gfnd::ResTexture* GetTexture(unsigned int idx) const;
        gfnd::ResTexture* GetNormalTexture(unsigned int idx) const;
        float GetFPS() const;
        float GetFrameCount() const;
        float GetDuration() const;
    };
}
