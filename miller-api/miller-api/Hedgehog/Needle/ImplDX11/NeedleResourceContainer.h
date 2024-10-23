#pragma once

// ASCII magic numbers to select parts of the datastructure
// Generic interface for the container
#define NEEDLE_RESOURCE_CONTAINER 0x544E43535231314Eui64 // 'TNCSR11N'

// Location of a boolean
#define NEEDLE_RESOURCE_SSTR 0x525453534445454Eui64 // 'RTSSDEEN'

namespace hh::needle::ImplDX11 {
    struct SQueryTypeOwn {}; // Querying Impl::resourceId return `implementation`
    struct SQueryTypeSelf {}; // Querying Impl::resourceId returns `this`
    struct SDupTypeSupport {}; // SetDuplicate supported
    struct SDupTypeNotSupport {}; // SetDuplicate not supported

    // Current assumption: QueryType chooses the handling of the QueryResource default branch, DupSupport handles something about the SetDuplicate function
    template<typename Type, typename Impl, size_t MyResourceId, typename SQueryType, typename SDupType>
    class NeedleResourceContainer : public Type {
        Impl implementation;
        NeedleSStr needleSStr;

    public:
        static constexpr size_t resourceId = MyResourceId;

        NeedleResourceContainer();
        
        virtual void* QueryResource(size_t id) override;
        //     switch (id) {
        //         case resourceId: return this;
        //         case Type::resourceId: return this;
        //         case NEEDLE_RESOURCE_SSTR: return &needsStr;
        //         default: return implementation.QueryResource(id);
        //     }
        // }
        
        virtual const void* QueryResource(size_t id) const override;
        //     switch (id) {
        //         case resourceId: return this;
        //         case Type::resourceId: return this;
        //         case NEEDLE_RESOURCE_SSTR: return &needsStr;
        //         default: return implementation.QueryResource(id);
        //     }
        // }
    };
}
