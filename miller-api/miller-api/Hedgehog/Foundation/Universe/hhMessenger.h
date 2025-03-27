#pragma once

namespace hh::fnd
{
	class Message;
	class MessageAsyncHandler;
	class MessageManager;
	class Messenger : public RefByHandleObject
	{
	public:
		typedef HandleManager<Messenger> HandleManager;

	protected:
		/*
		 * Sends a message to one particular receiver.
		 */
		MessageAsyncHandler* SendMessage(Handle<Messenger>& receiver, Message& message);
		bool SendMessageImm(Handle<Messenger>& receiver, Message& message);
		bool ForwardMessageImm(Handle<Messenger>& receiver, Message& message);

	public:
		MessageManager* messageManager;
		uint32_t messageMask;
		uint32_t unk3;

		Messenger(csl::fnd::IAllocator* pAllocator);
		virtual ~Messenger();

		virtual void* GetRuntimeTypeInfo() const;
		virtual bool ProcessMessage(Message& message);
		virtual bool fUnk3() { return false; }
		virtual bool ReceiveMessage(Message& message);
		virtual bool IsAcceptingMessages() { return true; }
		
		bool SendMessageImm(Message& message);
	};
}
