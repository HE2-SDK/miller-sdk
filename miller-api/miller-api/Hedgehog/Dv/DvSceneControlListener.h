#pragma once

namespace hh::dv{
    class DvSceneControlListenerBase {
    };

    class DvSceneControlListener {
    public:
        virtual bool DSCL_UnkFunc1(void* unk0, void* unk1) { return false; }
        virtual bool DSCL_UnkFunc2(void* unk0, void* unk1) { return false; }
        virtual bool DSCL_UnkFunc3() { return false; }
        virtual void DSCL_UnkFunc4() {}
        virtual void DSCL_UnkFunc5() {}
        virtual void DSCL_UnkFunc6() {}
        virtual void OnCutsceneEnd() {}
        virtual void DSCL_UnkFunc8() {}
        virtual void DSCL_UnkFunc9() {}
        virtual void DSCL_UnkFunc10() {}
        virtual void DSCL_UnkFunc11() {}
        virtual void DSCL_UnkFunc12() {}
        virtual bool DSCL_UnkFunc13(void* unk0) { return false; }
        virtual bool DSCL_UnkFunc14() { return false; }
        virtual void DSCL_UnkFunc15() {}
        virtual void DSCL_UnkFunc16() {}
    };
}
