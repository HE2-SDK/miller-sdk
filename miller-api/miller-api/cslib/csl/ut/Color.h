#pragma once
#include <ucsl/colors.h>

namespace csl::ut {
    UCSL_NEWTYPE_STRUCT(Color8, ucsl::colors::Color8ABGR, Color8ABGR);
    UCSL_NEWTYPE_STRUCT(Colorf, ucsl::colors::ColorfABGR, ColorfABGR);
}
