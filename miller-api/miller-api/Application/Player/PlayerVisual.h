#pragma once

#define PLAYER_VISUAL_CLASS_DECLARATION_BASE(ClassName) private:\
		static const app::player::PlayerVisualClass playerVisualClass;\
		static app::player::PlayerVisual* Create(csl::fnd::IAllocator* allocator);\
		ClassName(csl::fnd::IAllocator* allocator);

#define PLAYER_VISUAL_CLASS_DECLARATION(ClassName) PLAYER_VISUAL_CLASS_DECLARATION_BASE(ClassName)\
	public:\
		static const app::player::PlayerVisualClass* GetClass();

#define PLAYER_VISUAL_CLASS_DECLARATION_INLINE_GET_CLASS(ClassName) PLAYER_VISUAL_CLASS_DECLARATION_BASE(ClassName)\
	public:\
		static inline const app::player::PlayerVisualClass* GetClass() {\
			return &RESOLVE_STATIC_VARIABLE(playerVisualClass);\
		}

namespace app::player {
    class PlayerVisual;

    struct PlayerVisualClass {
        unsigned int nameHash;
        PlayerVisual* (*instantiator)(csl::fnd::IAllocator* allocator);
    };

    class GOCPlayerVisual;
    class PlayerVisual : public hh::fnd::ReferencedObject {
        hh::game::GameObject* gameObject;
        GOCPlayerVisual* gocPlayerVisual;
        void* unkFromUnkParam1;
        uint64_t unk1;
        uint16_t unk2;
    public:
        PlayerVisual(csl::fnd::IAllocator* allocator, hh::game::GameObject* gameObject, void* unkParam1);

        virtual unsigned int GetNameHash() const = 0;
        virtual uint64_t UnkFunc2() = 0;
        virtual uint64_t UnkFunc3() {}
        virtual uint64_t UnkFunc4() {}
        virtual uint64_t UnkFunc5();
        virtual uint64_t UnkFunc6();
        virtual uint64_t UnkFunc7() = 0;
        virtual uint64_t UnkFunc8() = 0;
    };
}
