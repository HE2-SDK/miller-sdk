#pragma once

namespace hh::ui {
    class CastSizeBinder : public fnd::ReferencedObject, public TextObjectUpdaterListener {
    public:
        struct Settings {
            const char* sourceCastName;
            bool bindWidth;
            bool bindHeight;
        };

        hh::fnd::Handle<SurfRideCastHandle> hCast;
        TextObjectUpdater* textObjectUpdater;
        bool bindWidth;
        bool bindHeight;

        CREATE_FUNC(CastSizeBinder, const hh::fnd::Handle<SurfRideCastHandle>& cast, TextObjectUpdater* textObjectUpdater, bool bindWidth, bool bindHeight);
        static bool ParseSettings(SurfRide::Cast* cast, Settings& settings);

        void Update(TextObjectUpdater* textObjectUpdater);

        virtual void TOUL_UnkFunc2() override;
    };
}
