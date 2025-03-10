#pragma once

namespace hh::dv{
    class DvElementControllerVibration : public DvElementBase {
    public:
    struct Data {
        public:
            enum class Flags : unsigned int {
                IGNORE_END = 2
            };

            csl::ut::Bitset<Flags> flags;
            char groupName[64];
            char vibrationName[64];
        private:
            int unk0[3];
        };

        Data binaryData;
        void* unk0;
        void* unk1;
        void* unk2;

        virtual bool AddCallback(int currentFrame, csl::math::Transform transform) override;
        virtual void* RemoveCallback() override;
        virtual void SetData(void* data) override;

        DV_ELEMENT_DECLARATION_BASE(DvElementControllerVibration)
    };
}