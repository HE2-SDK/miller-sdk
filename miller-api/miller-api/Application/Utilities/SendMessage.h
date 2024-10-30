#pragma once

namespace app::ut {
    bool SendMessageImmToCameraFrame(hh::game::GameObject& gameObject, int unusedCameraFrameId, hh::fnd::Message& message);
    bool SendMessageImmToCameraFrame(hh::fnd::Messenger& messenger, hh::game::GameManager* gameManager, int unusedCameraFrameId, hh::fnd::Message& message);
    bool SendMessageImmToCameraService(hh::game::GameObject& gameObject, hh::fnd::Message& message);
    void SendMessageImmToLayers(hh::fnd::Messenger& messenger, hh::game::GameManager* gameManager, unsigned int layerMask, hh::fnd::Message& message);
    bool SendMessageImmToSetObject(hh::game::GameObject& gameObject, hh::game::ObjectId objectId, hh::fnd::Message& message);
    bool SendMessageImmToSetObject(hh::fnd::Messenger& messenger, hh::game::GameManager* gameManager, hh::game::ObjectId objectId, hh::fnd::Message& message);
    bool SendMessageImmToPlayerObject(hh::game::GameObject& gameObject, char playerId, hh::fnd::Message& message);
    bool SendMessageImmToPlayerObject(hh::fnd::Messenger& messenger, hh::game::GameManager* gameManager, char playerId, hh::fnd::Message& message);
    bool SendMessageImmToUIObjects(hh::game::GameObject& gameObject, hh::fnd::Message& message);
    bool SendMessageImmToUIObjects(hh::fnd::Messenger& messenger, hh::game::GameManager* gameManager, hh::fnd::Message& message);

    hh::fnd::MessageAsyncHandler* SendMessageToCameraFrame(hh::game::GameObject& gameObject, int unusedCameraFrameId, hh::fnd::Message& message);
    // hh::fnd::MessageAsyncHandler* SendMessageToCameraFrame(hh::fnd::Messenger& messenger, hh::game::GameManager* gameManager, hh::fnd::Message& message);
    hh::fnd::MessageAsyncHandler* SendMessageToCameraService(hh::game::GameObject& gameObject, hh::fnd::Message& message);
    hh::fnd::MessageAsyncHandler* SendMessageToLayers(hh::fnd::Messenger& messenger, hh::game::GameManager* gameManager, unsigned int layerMask, hh::fnd::Message& message);
    bool SendMessageToSetObject(hh::game::GameObject& gameObject, hh::game::ObjectId objectId, hh::fnd::Message& message);
    // hh::fnd::MessageAsyncHandler* SendMessageToSetObject(hh::fnd::Messenger& messenger, hh::game::GameManager* gameManager, hh::game::ObjectId objectId, hh::fnd::Message& message);
    hh::fnd::MessageAsyncHandler* SendMessageToPlayerObject(hh::game::GameObject& gameObject, char playerId, hh::fnd::Message& message);
    hh::fnd::MessageAsyncHandler* SendMessageToPlayerObject(hh::fnd::Messenger& messenger, hh::game::GameManager* gameManager, char playerId, hh::fnd::Message& message);
    void SendMessageToUIObjects(hh::game::GameObject& gameObject, hh::fnd::Message& message);
    void SendMessageToUIObjects(hh::fnd::Messenger& messenger, hh::game::GameManager* gameManager, hh::fnd::Message& message);
}
