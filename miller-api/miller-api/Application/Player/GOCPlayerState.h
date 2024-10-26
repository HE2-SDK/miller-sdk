#pragma once

namespace app::player {
    template<typename T>
    class GOCPlayerStateBase : public hh::ut::StateBase<T> {
        struct Unk1 {
            uint32_t a;
            uint32_t b;
            uint32_t c;
        };
    public:
        uint64_t unk2;
        uint64_t unk3;
        GOCPlayerHsm* hsm;
        csl::ut::MoveArray<void*> messageHandlers;
        csl::ut::InplaceMoveArray<Unk1, 4> unk5;
        uint64_t unk9;
        uint32_t unk10;
        int32_t unk11;

        virtual bool DoUnkFunc8() { return UnkFunc8(hsm); }
        virtual void DoUnkFunc9(uint32_t unkParam) { return UnkFunc9(hsm, unkParam); }
        virtual void DoUnkFunc10(uint32_t unkParam) { return UnkFunc10(hsm, unkParam); }
        virtual bool DoUnkFunc11(float unkParam) { return UnkFunc11(hsm, unkParam); }
        virtual bool DoUnkFunc15(uint32_t unkParam, float unkParam2) { return UnkFunc15(hsm, unkParam, unkParam2); }
        virtual bool DoStart(uint32_t unkParam, float unkParam2) { return Start(hsm, unkParam, unkParam2); }
        virtual bool DoProcessMessage(const hh::fnd::Message& message) { return ProcessMessage(hsm, message); }

        virtual bool UnkFunc8(void* hsm) { return Exit(hsm); }
        virtual void UnkFunc9(void* hsm, uint32_t unkParam2) { UnkFunc12(hsm, unkParam2); }
        virtual void UnkFunc10(void* hsm, uint32_t unkParam2) { UnkFunc13(hsm, unkParam2); }
        virtual bool ProcessMessage(void* hsm, const hh::fnd::Message& message);
        virtual bool UnkFunc11(void* hsm, float unkParam2) { return false; }
        virtual bool UnkFunc15(void* hsm, uint32_t unkParam2, float unkParam3);
        virtual bool Start(void* hsm, uint32_t unkParam2, float unkParam3) { return false; }

        virtual bool Exit(void* hsm) { return false; }
        virtual void UnkFunc12(void* hsm, uint32_t unkParam2) {}
        virtual void UnkFunc13(void* hsm, uint32_t unkParam2) {}
        virtual bool UnkFunc14(void* hsm, uint32_t unkParam2, float unkParam3) {
            if (unkParam2 == 0) {
                Update(hsm, unkParam3);
            }
            return false;
        }
        virtual bool Update(void* hsm, float unkParam2) { return false; }
    };
}
