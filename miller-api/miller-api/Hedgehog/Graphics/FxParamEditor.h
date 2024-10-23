#pragma once

namespace hh::gfx {
    struct FxParamEditInfo {
        int index;
        float interpolationTime;
        const char* paramClassName;
        const char* path;
        void* value;
        uint64_t unk1;
        bool unk2;
        bool applyToParamManager;
    };

    class FxParamEditorListener {
        virtual void FPE_OnSetParam(const FxParamEditInfo& editInfo) {}
        virtual void FPE_OnSetParam2(const FxParamEditInfo& editInfo) {}
        virtual void FPE_UnkFunc3(const FxParamEditInfo& editInfo) {}
        virtual void FPE_OnInterpolate(const FxParamEditInfo& editInfo) {}
    };
}
