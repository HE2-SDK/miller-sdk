#pragma once

namespace hh::fnd {
    class MessageQueue {
    public:
        class Entry : public ReferencedObject {
        public:
            enum class Flags {
                PENDING,
                IN_FLIGHT,
                HANDLED_FAILURE,
                HANDLED_SUCCESS,
            };
            fnd::Message* message;
            Flags flags;
        };
		struct Buffer {
			csl::fnd::IAllocator* allocator;
			Entry** results;
			uint32_t messageCount;
			uint32_t bufferSize;

            Buffer();
		};

		csl::fnd::IAllocator* allocator;
		Buffer messageBuffers[2];
		int currentBuffer;
    
        MessageQueue();
        void Reserve(csl::fnd::IAllocator* allocator, size_t size);
        MessageAsyncHandler* EnqueueMessage(const Message& message);
        void Dispatch(bool (*func)(const Message& message, void* userData), void* userData);
    };
}
