#pragma once

namespace hh::gfnd {
    class RenderManagerBase : public fnd::BaseObject, public game::GameUpdateListener, public csl::fnd::Singleton<RenderManagerBase> {
    public:
        struct SetupInfo {
            const char* shaderPackfilePath;
            float aspectRatio;
            uint8_t unk2a;
            uint64_t unk3;
            uint32_t resX;
            uint32_t resY;
            uint32_t renderResX;
            uint32_t renderResY;
            uint64_t unk6;
            uint64_t unk7;
            uint64_t unk8;
            uint64_t unk9;
            void* unk10;
        };

        RenderManagerBase(csl::fnd::IAllocator* allocator);

        virtual bool Setup(const SetupInfo& setupInfo) = 0;
        virtual uint64_t UnkFunc2() = 0;
        virtual uint64_t UnkFunc3() = 0;
        virtual void UnkFunc4() {}
        virtual uint64_t UnkFunc5() = 0;

		virtual void PostGameUpdateCallback(game::GameManager* gameManager, const fnd::SUpdateInfo& updateInfo) override;
    };
}