#pragma once

#define SCENECONTEXT_CLASS_DECLARATION(ClassName) public:\
		ClassName();\
		static unsigned int GetStaticNameHash();
		static const char* GetStaticName();

namespace hh::needle {
    class SupportFXAll;
    class SceneContextManager;
    class SceneContext : public NeedleRefcountObject {
    public:
        enum class Flag : unsigned int {
            UNK0,
            UNK1,
        };

        struct InitializeInfo {
            RenderingDevice* renderingDevice;
            csl::fnd::IAllocator* allocator;
            SupportFXAll* supportFX;
        };

        csl::ut::Bitset<Flag> flags;
        SceneContextManager* sceneContextManager;

        virtual void Initialize(const InitializeInfo& initializeInfo) = 0;
        virtual void UnkFunc1() = 0;
        virtual void UnkFunc2() {}
        virtual void UnkFunc3() {}
        virtual void UnkFunc4() {}
        virtual unsigned int GetNameHash() = 0;
        virtual const char* GetName() = 0;
    };
}
