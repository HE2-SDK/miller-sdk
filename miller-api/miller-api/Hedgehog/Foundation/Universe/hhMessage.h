#pragma once

namespace hh::fnd
{
	enum class MessageID : uint32_t {
		TRIGGER_ENTER = 512,
		TRIGGER_LEAVE = 513,
		TRIGGER_STAY = 514,
		UPDATE_SET_EDITOR = 768,
		UPDATE_ACTIVE_OBJECT_IN_EDITOR = 769,
		START_ACTIVE_OBJECT_IN_EDITOR = 770,
		FINISH_ACTIVE_OBJECT_IN_EDITOR = 771,
		PARAM_CHANGED_IN_EDITOR = 772,
		GET_DEBUG_COMMENT_IN_EDITOR = 773,
		PUSH_CAMERA_CONTROLLER = 4097,
		POP_CAMERA_CONTROLLER = 4098,
		ADD_NOTIFY_PRE_DEAD_LISTENER = 8201,
		CAMERA_OFF = 8353,
		CAMERA_ON = 8354,
		CAMERA_ZOOM_END = 8366,
		DAMAGE = 8370,
		DEAD = 8374,
		CHANGE_GLOBAL_TIME_SCALE = 8387,
		CHANGE_LAYER_TIME_SCALE = 8388,
		END_FREE_CAMERA = 8499,
		REPLAY_COMMAND = 8598,
		IS_TAKE_RED_RING = 8676,
		NOTIFY_ACTION = 8748,
		UI_SET_GAME_COCKPIT_ENABLE_RENDER = 8757,
		UI_SET_GAME_COCKPIT_VISIBILITY = 8758,
		NOTIFY_END_FALL_CYBERSPACE = 8765,
		NOTIFY_LEVEL_STATUS = 8779,
		NOTIFY_RETRY = 8788,
		PASS_POINT_MARKER = 8823,
		REVERT_GLOBAL_TIME_SCALE = 8915,
		REVERT_LAYER_TIME_SCALE = 8916,
		SET_MENU_ENABLED = 8947,
		START_FREE_CAMERA = 9001,
		UI_CAMERA_INFO = 9117,
		UI_CHANGE_PLAYER_CHARACTER = 9120,
		UI_NOTIFY_CAMERA_CONTROL = 9186,
		UI_PAUSE_RESULT = 9198,
	};

	class Messenger;
	class MessageAsyncHandler;
	class Message
	{
	public:
		MessageID ID{};
		Handle<Messenger> Sender{};
		Handle<Messenger> Receiver{};
		char Handled{};
		bool Broadcasted{};
		uint32_t Mask{ (uint32_t)-1 };

		Message(MessageID in_id);

		virtual MessageAsyncHandler* CreateAsyncHandler(csl::fnd::IAllocator* allocator);
		virtual ~Message() = default;

		inline static void* operator new(size_t count) {
			return AllocateObjectGlobalMemory(count);
		}
		
		inline static void operator delete(void* ptr) noexcept {
			FreeObjectGlobalMemory(ptr);
		}
	};

	class MessageAsyncHandler : public ReferencedObject
	{
		Message& message;
		uint8_t unk1{};

	public:
		MessageAsyncHandler(csl::fnd::IAllocator* allocator, Message& message) : ReferencedObject{ allocator, true }, message{ message } {}

		inline Message& GetMessage() const {
			return message;
		}

		template<typename T>
		T& GetMessage() const {
			return static_cast<T&>(GetMessage());
		}
	};

	template <typename T>
	class MessageAsyncHandlerInplace : public MessageAsyncHandler
	{
		T messageInPlace;

	public:
		inline MessageAsyncHandlerInplace(csl::fnd::IAllocator* allocator, const T& message) : messageInPlace{ message }, MessageAsyncHandler { allocator, messageInPlace } {}
	};
}
