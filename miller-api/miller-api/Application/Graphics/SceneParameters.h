#pragma once

namespace app::gfx {
    class SceneParameters : public hh::fnd::ReferencedObject, public hh::gfx::FxParamEditorListener {
    public:
        class Listener {
        public:
            virtual void SPL_UnkFunc1() {}
            virtual void SPL_UnkFunc2() {}
            virtual void SPL_UnkFunc3() {}
        };

        hh::needle::NeedleFxSceneData* sceneData;
        csl::ut::MoveArray<Listener*> listeners;
        csl::ut::MoveArray<void*> unk2;
        uint64_t unk3;
        csl::ut::VariableString unk4;
        uint8_t unk5;
        uint32_t sceneParamIndexOffset;
        SceneParameters(csl::fnd::IAllocator* allocator);
        virtual void FPE_OnSetParam(const hh::gfx::FxParamEditInfo& editInfo) override;
        virtual void FPE_OnSetParam2(const hh::gfx::FxParamEditInfo& editInfo) override;
        virtual void FPE_OnInterpolate(const hh::gfx::FxParamEditInfo& editInfo) override;
        hh::needle::NeedleFxSceneData* GetSceneData();
    };
}