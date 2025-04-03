#pragma once

#define DV_PAGE_CONDITION_DECLARATION_BASE(ClassName)public:\
		ClassName(csl::fnd::IAllocator* allocator);\
		static DvPageConditionBase* Create(DvPageTransition* transition, csl::fnd::IAllocator* allocator);

namespace hh::dv{
    class DvSceneControl;
    class DvPage;
    class DvPageTransition;

    class DvPageConditionBase : public fnd::ReferencedObject{
    public:
        DvPageTransition* transition;
        int idx;
        int unk3;
        DvPageConditionBase* unkCondition;

        virtual void Setup(void* setupInfo) {};
        virtual void UnkFunc1() {};
        virtual void UnkFunc2() {};
        virtual void UnkFunc3() {};
        virtual void UnkFunc4() {};
        virtual bool UnkFunc5() { return false; };

        game::GameManager* GetGameManager();
        
        DvPageConditionBase(csl::fnd::IAllocator* allocator);
    };

    class DvPageTransition : public fnd::ReferencedObject{
    public:
        struct Data{
            int destinationPageID;
            int conditionCount;
            int64_t conditionSize;
        };

        DvPage* page;
        Data binaryData;
        DvPageConditionBase* condition;

        DvPageTransition(csl::fnd::IAllocator* allocator);
    };

    class DvPage : public fnd::ReferencedObject{
    public:
        struct Data{
            int64_t unk0;
            int start;
            int end;
            int transitionCount;
            int transitionSize;
            int skipFrame;
            int pageIndex;
            int dataSize;
            int unks[3];
            char pageName[32];
        };

        DvSceneControl* dvSceneControl;
        Data binaryData;
        csl::ut::MoveArray<DvPageTransition*> transitions;
        int framesTakenToLoad;
        int unk2;

        virtual int GetStart();

        DvPage(csl::fnd::IAllocator* allocator);
    };
}
