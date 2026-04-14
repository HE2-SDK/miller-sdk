#pragma once

namespace Cyan::System::Math {
    csl::math::Matrix34 GetEulerRotationMatrix(const csl::math::Vector3& eulerAngles);
    void DisassemblyMatrix(const csl::math::Matrix34& matrix, csl::math::Vector3* translation, csl::math::Matrix34* rotationScale);
}
