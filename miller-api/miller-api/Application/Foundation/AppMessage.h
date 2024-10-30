#pragma once

namespace app::fnd
{
	template <typename T>
	class AppMessage : public hh::fnd::Message
	{
	public:
		AppMessage(hh::fnd::MessageID in_id) : Message(in_id)
		{
			
		}
		
		virtual hh::fnd::MessageAsyncHandler* CreateAsyncHandler(csl::fnd::IAllocator* allocator) override;
		virtual uint32_t UnkFunc1();
	};

	template <typename T>
	class AppMessageCustom : public hh::fnd::Message
	{
	public:
		AppMessageCustom(hh::fnd::MessageID in_id) : Message(in_id) {}
		
		virtual hh::fnd::MessageAsyncHandler* CreateAsyncHandler(csl::fnd::IAllocator* allocator) override {
			return new (allocator) hh::fnd::MessageAsyncHandlerInplace<T>{ allocator, *static_cast<T*>(this) };
		}
		virtual uint32_t UnkFunc1() { return 0; }
	};
}
