#pragma once

namespace hh::fnd {
    class FileWin32 : public fnd::ReferencedObject {
        HANDLE fileHandle;
        uint32_t unk1;
    };

    // class FileSystemImpl : public fnd::ReferencedObject {
    // public:
    //     virtual ~FileSystemImpl() = default;

    // };

    class IFileSystem {
    public:
        virtual void* GetRuntimeTypeInfo() const;
        virtual ~IFileSystem() = default;
        virtual bool UnkFunc2(uint64_t unkParam) { return false; }
        virtual uint64_t UnkFunc3(uint64_t unkParam);
        virtual bool UnkFunc4(uint64_t unkParam) { return true; }
        virtual uint64_t UnkFunc5(uint64_t unkParam);
        virtual unsigned int UnkFunc6(const char* unkParam);
        virtual uint64_t UnkFunc7(uint64_t unkParam);
        virtual bool UnkFunc7a(uint64_t unkParam) { return true; }
        virtual uint64_t OpenFile(const Uri& uri);
        virtual uint64_t UnkFunc8(const char* unkParam) = 0;
        virtual uint64_t UnkFunc12(uint64_t unkParam1, uint64_t unkParam2);
        virtual uint64_t UnkFunc13(const char* unkParam1, uint64_t unkParam2) = 0;
        virtual uint64_t UnkFunc14(uint64_t unkParam1, uint64_t unkParam2);
        virtual uint64_t UnkFunc15(const char* unkParam1, uint64_t unkParam2) = 0;
        virtual uint64_t UnkFunc16(uint64_t unkParam);
        virtual bool UnkFunc17(uint64_t unkParam) { return false; }
        virtual uint64_t UnkFunc18(uint64_t unkParam);
        virtual bool UnkFunc19(const char* unkParam1) { return false; }
        virtual uint64_t UnkFunc20(uint64_t unkParam1, uint64_t unkParam2);
        virtual bool UnkFunc21(const char* unkParam1, const char* unkParam2) { return false; }
        virtual uint64_t UnkFunc22(uint64_t unkParam);
        virtual uint64_t UnkFunc23(const char* unkParam1) = 0;
        virtual uint64_t UnkFunc24(uint64_t unkParam);
        virtual uint64_t UnkFunc25(const char* unkParam1) = 0;
        virtual uint64_t UnkFunc26(uint64_t unkParam);
        virtual uint64_t UnkFunc27(uint64_t unkParam);
    };

    // class NVMeFileSystemNull : public IFileSystem {

    // }

    class FileSystem : public IFileSystem, public hh::fnd::BaseObject, public csl::fnd::Singleton<FileSystem> {
    public:
        FileSystem(csl::fnd::IAllocator* allocator);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual ~FileSystem() = default; // TODO: implement
        virtual bool UnkFunc2(uint64_t unkParam) override;
        virtual uint64_t UnkFunc3(uint64_t unkParam) override;
        virtual bool UnkFunc4(uint64_t unkParam) override;
        virtual uint64_t UnkFunc5(uint64_t unkParam) override;
        virtual unsigned int UnkFunc6(const char* unkParam) override;
        virtual uint64_t UnkFunc7(uint64_t unkParam) override;
        virtual bool UnkFunc7a(uint64_t unkParam) override;
        virtual uint64_t OpenFile(const Uri& uri) override;
        virtual uint64_t UnkFunc8(const char* unkParam) override;
        virtual uint64_t UnkFunc12(uint64_t unkParam1, uint64_t unkParam2) override;
        virtual uint64_t UnkFunc13(const char* unkParam1, uint64_t unkParam2) override;
        virtual uint64_t UnkFunc14(uint64_t unkParam1, uint64_t unkParam2) override;
        virtual uint64_t UnkFunc15(const char* unkParam1, uint64_t unkParam2) override;
        virtual uint64_t UnkFunc16(uint64_t unkParam) override;
        virtual bool UnkFunc17(uint64_t unkParam) override;
        virtual uint64_t UnkFunc18(uint64_t unkParam) override;
        virtual bool UnkFunc19(const char* unkParam1) override;
        virtual uint64_t UnkFunc20(uint64_t unkParam1, uint64_t unkParam2) override;
        virtual bool UnkFunc21(const char* unkParam1, const char* unkParam2) override;
        virtual uint64_t UnkFunc22(uint64_t unkParam) override;
        virtual uint64_t UnkFunc23(const char* unkParam1) override;
        virtual uint64_t UnkFunc24(uint64_t unkParam) override;
        virtual uint64_t UnkFunc25(const char* unkParam1) override;
    };
}
