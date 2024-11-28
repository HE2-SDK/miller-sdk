#pragma once
#include <ucsl/rfl/rflclass.h>

namespace hh::fnd {
    UCSL_NEWTYPE_SIMPLE(RflCustomAttribute, ucsl::rfl::miller::RflCustomAttribute);
    UCSL_NEWTYPE_SIMPLE(RflCustomAttributes, ucsl::rfl::miller::RflCustomAttributes);
    UCSL_NEWTYPE_SIMPLE(RflClassEnumMember, ucsl::rfl::miller::RflClassEnumMember);
    UCSL_NEWTYPE_SIMPLE(RflClassEnum, ucsl::rfl::miller::RflClassEnum);
    UCSL_NEWTYPE_SIMPLE(RflClassMember, ucsl::rfl::miller::RflClassMember);
    UCSL_NEWTYPE_SIMPLE(RflClass, ucsl::rfl::miller::RflClass);
}
