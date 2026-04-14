#pragma once

namespace hh::needle {
    class Model;
    class ModelInstance;
}

namespace Cyan {
    class Manager;
}

namespace Cyan::Graphics {
    class MeshInstance {
    public:
        virtual bool UnkFunc1() const = 0;
        virtual unsigned int UnkFunc2() const = 0;
        virtual void* UnkFunc3() const = 0;
        virtual void UnkFunc4() = 0;
        virtual void UnkFunc5() = 0;
        virtual ~MeshInstance();
        virtual void UnkFunc7() = 0;
        virtual void UnkFunc8() = 0;

        template<typename T> static MeshInstance* Create(Manager* manager, System::IAllocator* allocator, T* model);
        template<> MeshInstance* Create(Manager* manager, System::IAllocator* allocator, hh::needle::Model* model);
    };

    class MeshInstanceImpl : public MeshInstance {
    public:
        hh::needle::intrusive_ptr<hh::needle::ModelInstance> modelInstance;
        hh::needle::intrusive_ptr<hh::needle::Model> model;
        void* renderHandler;

        virtual bool UnkFunc1() const override;
        virtual unsigned int UnkFunc2() const override;
        virtual void* UnkFunc3() const override;
        virtual void UnkFunc4() override;
        virtual void UnkFunc5() override;
        virtual ~MeshInstanceImpl();
        virtual void UnkFunc7() override;
        virtual void UnkFunc8() override;
    };

    template<typename Model, typename ModelInstance>
    class ExternalMeshInstance : public MeshInstance {
    public:
        class RenderHandler {
        public:
            virtual ModelInstance* CreateModelInstance(Model* model) = 0;
            virtual void SetVisible(ModelInstance* modelInstance, bool visible) = 0;
            virtual void UnkFunc3(void* unkParam1, unsigned int unkParam2) = 0;
            virtual bool UnkFunc4(void* unkParam1) = 0;
            virtual void UnkFunc5() = 0;
            virtual void UnkFunc6(ModelInstance* modelInstance, void* unkParam1, void* unkParam2) = 0;
        };

        hh::needle::intrusive_ptr<ModelInstance> modelInstance;
        hh::needle::intrusive_ptr<Model> model;
        RenderHandler* renderHandler;

        virtual bool UnkFunc1() const override;
        virtual unsigned int UnkFunc2() const override;
        virtual void* UnkFunc3() const override;
        virtual void UnkFunc4() override;
        virtual void UnkFunc5() override;
        virtual ~ExternalMeshInstance();
        virtual void UnkFunc7() override;
        virtual void UnkFunc8() override;
    };
}
