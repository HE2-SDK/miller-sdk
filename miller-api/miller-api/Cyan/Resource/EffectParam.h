#pragma once
#include <ucsl/resources/cemt/v120000.h>

namespace Cyan::Resource {
    UCSL_NEWTYPE_STRUCT_SIMPLE(ElementParam, ucsl::resources::cemt::v120000::ElementParam);
    UCSL_NEWTYPE_STRUCT_SIMPLE(EmitterParam, ucsl::resources::cemt::v120000::EmitterParam);
    UCSL_NEWTYPE_STRUCT_SIMPLE(EffectParam, ucsl::resources::cemt::v120000::EffectParam);
    UCSL_NEWTYPE_STRUCT_SIMPLE(FieldParam, ucsl::resources::cemt::v120000::FieldParam);
}
