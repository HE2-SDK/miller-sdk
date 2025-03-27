#pragma once

namespace hh::fnd
{
	class HandleBase
	{
	protected:
		uint32_t handle{};

		void Set(const RefByHandleObject* pObj);
		RefByHandleObject* Get(HandleManagerBase* handleManager) const;
		
	public:
		HandleBase()
		{
			
		}
		
		HandleBase(const RefByHandleObject* pObj)
		{
			Set(pObj);
		}

		bool operator==(const HandleBase& other) const
		{
			return handle == other.handle;
		}

		bool operator!=(const HandleBase& other) const
		{
			return !operator==(other);
		}

		bool operator==(const RefByHandleObject* pObj) const
		{
			return pObj == nullptr ? handle == 0 : handle == pObj->handle;
		}

		bool operator!=(const RefByHandleObject* pObj) const
		{
			return !operator==(pObj);
		}

		HandleBase& operator=(const RefByHandleObject* pObj)
		{
			Set(pObj);
			return *this;
		}

		HandleBase& operator=(const HandleBase& hObj);
		// {
		// 	handle = hObj.handle;
		// 	return *this;
		// }
	};

	template<typename T, typename M = typename T::HandleManager>
	class Handle : public HandleBase
	{
	public:
		Handle()
		{
			
		}

		Handle(const T* pObj) : HandleBase(pObj)
		{
			
		}


		Handle<T, M>& operator=(T* pObj)
		{
			Set(pObj);
			return *this;
		}

		Handle<T, M>& operator=(const Handle<T, M>& hObj)
		{
			handle = hObj.handle;
			return *this;
		}

		T* operator*() const
		{
			return reinterpret_cast<T*>(HandleBase::Get(RESOLVE_STATIC_VARIABLE(M::instance)));
		}

		operator T*() const
		{
			return operator*();
		}

		T* operator->() const
		{
			return operator*();
		}
	};

	template<typename T, typename M = typename T::HandleManager>
	class CustomHandle : public HandleBase
	{
	public:
		CustomHandle()
		{

		}

		CustomHandle(const T* pObj) : HandleBase(pObj)
		{

		}


		CustomHandle<T, M>& operator=(T* pObj)
		{
			Set(pObj);
			return *this;
		}

		CustomHandle<T, M>& operator=(const CustomHandle<T, M>& hObj)
		{
			handle = hObj.handle;
			return *this;
		}

		T* operator*() const
		{
			return reinterpret_cast<T*>(HandleBase::Get(M::instance));
		}

		T* operator->() const
		{
			return operator*();
		}

		// template<typename U, typename = std::enable_if<std::is_base_of<U, T>>>
		// operator const hh::fnd::CustomHandle<U, M>&() const & {
		// 	return *(hh::fnd::CustomHandle<U, M>*)this;
		// }

		// template<typename U, typename = std::enable_if<std::is_base_of<T, U>>>
		// explicit operator hh::fnd::CustomHandle<U, M>() const && {
		// 	hh::fnd::CustomHandle<U, M> res{};
		// 	res.handle = handle;
		// 	return res;
		// }

		// template<typename U, typename = std::enable_if<std::is_base_of<T, U>>>
		// explicit operator hh::fnd::CustomHandle<U, M>&() const & {
		// 	return *(hh::fnd::CustomHandle<U, M>*)this;
		// }
	};
}
