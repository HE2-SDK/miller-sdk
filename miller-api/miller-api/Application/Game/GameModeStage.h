#pragma once

namespace app::game {
    class GameModeStage : public GameMode {
    public:
        class State {
        public:
            class BuildBase : public hh::ut::StateBase<GameModeStage> {
            };

            class RebuildLevel : public BuildBase {
                uint32_t unk3;
                uint64_t unk4;
                uint64_t unk5;
                bool unk6;
                uint32_t unk7;
                uint32_t unk8;
                uint16_t unk9;

                void InitializeCockpit(GameModeStage* gameMode);
            };
        };

		virtual void* GetRuntimeTypeInfo() override;
		virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual bool fUnk3() override;
        virtual bool UnkFunc5() override;
        virtual bool UnkFunc6() override;
        virtual bool UnkFunc7() override;
        virtual bool UnkFunc8() override;
        virtual bool UnkFunc9() override;
        virtual bool UnkFunc10() override;
        virtual bool UnkFunc12() override;
        virtual bool UnkFunc13() override;
    };
}
