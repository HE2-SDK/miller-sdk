#pragma once

namespace hh::needle {
    class SupportFXAll;
    class SceneContextManager : public NeedleRefcountObject {
    public:
        csl::ut::MoveArray<intrusive_ptr<SceneContext>> sceneContexts;
        CNameIDObject* nameId;
        bool initialized;
        SupportFXAll* supportFX;
        csl::ut::MoveArray<void*> unk3;

        SceneContextManager(const char* name, SupportFXAll* supportFX);
        virtual void Initialize() = 0;
        virtual uint64_t UnkFunc2() = 0;
        virtual void UnkFunc3();

        void Setup();
        void AddSceneContext(SceneContext* sceneContext);
    };

    class SceneContextManagerNeedle : public SceneContextManager {
    public:
        SceneContextManagerNeedle(const char* name, SupportFXAll* supportFX);

        virtual void Initialize() override;
        virtual uint64_t UnkFunc2() override {}
    };
}
