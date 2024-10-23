#pragma once

namespace hh::dbg {
    class MsgParamChangedInEditor : public fnd::Message {
    public:
        MsgParamChangedInEditor() : fnd::Message(fnd::MessageID::PARAM_CHANGED_IN_EDITOR) {}
    };

    class MsgUpdateActiveObjectInEditor : public fnd::Message {
    public:
        MsgUpdateActiveObjectInEditor() : fnd::Message(fnd::MessageID::UPDATE_ACTIVE_OBJECT_IN_EDITOR) {}
    };

    class MsgStartActiveObjectInEditor : public fnd::Message {
    public:
        MsgStartActiveObjectInEditor() : fnd::Message(fnd::MessageID::START_ACTIVE_OBJECT_IN_EDITOR) {}
    };

    class MsgFinishActiveObjectInEditor : public fnd::Message {
    public:
        MsgFinishActiveObjectInEditor() : fnd::Message(fnd::MessageID::FINISH_ACTIVE_OBJECT_IN_EDITOR) {}
    };

    class MsgUpdateSetEditor : public fnd::Message {
    public:
        MsgUpdateSetEditor() : fnd::Message(fnd::MessageID::UPDATE_SET_EDITOR) {}
    };

    class MsgGetDebugCommentInEditor : public fnd::Message {
    public:
        char comment[512]{ "" };
        MsgGetDebugCommentInEditor() : fnd::Message(fnd::MessageID::GET_DEBUG_COMMENT_IN_EDITOR) {}
    };
}
