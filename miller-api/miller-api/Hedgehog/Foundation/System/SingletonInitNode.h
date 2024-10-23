#pragma once

namespace hh::fnd {
	struct SingletonInitNode
	{
        typedef void* SingletonInit();
        typedef void SingletonDestroy(void* singleton);
	
		inline static SingletonInitNode** ms_ppCurNode;
		SingletonInit* init;
		SingletonDestroy* destroy;
		SingletonInitNode* prevNode;
		void** instance;

		SingletonInitNode() = default;
		
		SingletonInitNode(SingletonInit* init_, SingletonDestroy* destroy_, void** inst) : init(init_), destroy(destroy_), prevNode(*ms_ppCurNode), instance(inst)
		{
			*ms_ppCurNode = this;
		}
	};
}