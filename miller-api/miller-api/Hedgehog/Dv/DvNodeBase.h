#pragma once

namespace hh::dv{
    class DvSceneNodeTree;

    class DvNodeBase : public hh::fnd::ReferencedObject{
    public:
        struct Description {};

        enum class NodeType : uint32_t{
            PATH = 1,
            PATH_MOTION,
            CAMERA,
            CAMERA_MOTION,
            CHARACTER,
            CHARACTER_MOTION,
            CHARACTER_BEHAVIOR,
            MODEL,
            MODEL_MOTION = 10,
            MODEL_NODE,
            ELEMENT
        };

        uint32_t flags; //prolly a bitset
        NodeType nodeType;
        char guid[16];
        char padding[16];
        csl::ut::String nodeName;
        csl::fnd::IAllocator* idkallocator;
        csl::math::Transform transform;
        csl::math::Matrix44 matrix;
        DvResource* dvResource;
        DvNodeBase* parent;
        csl::ut::MoveArray<DvNodeBase*> childrenElements0;
        csl::ut::MoveArray<DvNodeBase*> childrenPath;
        csl::ut::MoveArray<DvNodeBase*> childrenCamera;
        csl::ut::MoveArray<DvNodeBase*> childrenMotion;
        csl::ut::MoveArray<DvNodeBase*> childrenElements1;
        csl::ut::MoveArray<DvNodeBase*> childrenElements2;
        DvSceneNodeTree* dvsceneNodeTree;

        virtual void Setup(Description& description);
        virtual void Start();
        virtual void Update(int currentFrame) {};
        virtual void PreStepUpdate(int currentFrame) {}; // another update?
        virtual void PostStepUpdate(int currentFrame) {};
        virtual bool IsUnkFlag0();
        virtual bool UnkFunc3() { return true; }
        virtual void UnkFunc4() {};
        virtual int GetUpdateTiming();
        virtual void UnkFunc6(void* unk0, void* unk1) {};
        virtual void UnkFunc7() {};
        virtual void UnkFunc8() {};
        virtual void UnkFunc9() {};
        virtual void UnkFunc10() {};
        virtual void UnkFunc11() {};
        virtual void UnkFunc12() {};

        char* GetGUID();
        void SetTransform(csl::math::Transform* transform);

        DvNodeBase(csl::fnd::IAllocator* allocator);
    };
}
