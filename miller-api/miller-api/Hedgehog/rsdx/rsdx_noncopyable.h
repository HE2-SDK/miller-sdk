#pragma once

namespace hh::rsdx {
    class rsdx_noncopyable {
	protected:
		rsdx_noncopyable() = default;

		~rsdx_noncopyable() = default;
		
		rsdx_noncopyable(const rsdx_noncopyable&) = delete;
		rsdx_noncopyable& operator =(const rsdx_noncopyable&) = delete;
    };
}
