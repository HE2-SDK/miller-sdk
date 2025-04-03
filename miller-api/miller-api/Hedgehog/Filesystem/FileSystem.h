#pragma once

namespace hh::fnd {

    class StreamReader : public fnd::ReferencedObject {
    public:
        struct ReadInfo {
            void* buffer;
            size_t start;
            size_t bytesToRead;
        };

        virtual ~StreamReader();
        virtual unsigned int Read(const ReadInfo& readInfo);
        virtual unsigned int Read(void* buffer, size_t start, size_t bytesToRead) = 0;
        virtual unsigned int Read(void* buffer, size_t bytesToRead);
        virtual bool IsValid() const = 0;
        virtual void Close() = 0;
        virtual unsigned int GetFileSize() const = 0;
        virtual unsigned int GetUnk1() const = 0;
    };

    class StreamReaderWin32 : public StreamReader {
        HANDLE fileHandle;
        unsigned int currentPosition;

        DEFAULT_CREATE_FUNC(StreamReaderWin32);

        virtual unsigned int Read(void* buffer, size_t start, size_t bytesToRead) override;
        virtual bool IsValid() const override;
        virtual void Close() override;
        virtual unsigned int GetFileSize() const override;
        virtual unsigned int GetUnk1() const override;
    };

    class StreamWriter : public fnd::ReferencedObject {
    public:
        virtual ~StreamWriter();
        virtual unsigned int Write(void* buffer, size_t size) = 0;
        virtual bool IsValid() const = 0;
        virtual void Close() = 0;
    };

    class StreamWriterWin32 : public StreamWriter {
    public:
        HANDLE fileHandle;

        DEFAULT_CREATE_FUNC(StreamWriterWin32);

        virtual unsigned int Write(void* buffer, size_t size) override;
        virtual bool IsValid() const override;
        virtual void Close() override;
    };

    // class FileSystemImpl : public fnd::ReferencedObject {
    // public:
    //     virtual ~FileSystemImpl() = default;

    // };

    class FileSet {
    public:
        struct Item {
            const char* path;
            unsigned int length;
        };

        csl::ut::InplaceMoveArray<Item, 32> items;

        DEFAULT_CREATE_FUNC(FileSet);
        ~FileSet();

        void AddItem(const csl::ut::String& path);
        void UpdateItem(Item& item, const char* path);
        void Clear();
    };

    class IFileSystem {
    public:
        virtual void* GetRuntimeTypeInfo() const;
        virtual ~IFileSystem() = default;
        virtual bool UnkFunc2(uint64_t unkParam) { return false; }
        virtual bool UnkFunc3(const Uri& uri);
        virtual bool UnkFunc4(const char* path) { return true; }
        virtual unsigned int UnkFunc5(const Uri& uri);
        virtual unsigned int UnkFunc6(const char* path);
        virtual bool UnkFunc7(const Uri& uri);
        virtual bool UnkFunc7a(const char* path) { return true; }
        virtual StreamReader* OpenFileForReading(const Uri& uri);
        virtual StreamReader* OpenFileForReadingByPath(const char* path) = 0;
        virtual StreamWriter* OpenFileForWriting(const Uri& uri, csl::fnd::IAllocator* allocator);
        virtual StreamWriter* OpenFileForWritingByPath(const char* path, csl::fnd::IAllocator* allocator) = 0;
        virtual bool ListDirectory(const Uri& uri, FileSet& results);
        virtual bool ListDirectoryByPath(const char* path, FileSet& results) = 0;
        virtual bool CreateDirectory(const Uri& uri);
        virtual bool CreateDirectoryByPath(const char* path) { return false; }
        virtual bool Delete(const Uri& uri);
        virtual bool DeleteByPath(const char* path) { return false; }
        virtual bool Rename(const Uri& uri, const Uri& newUri);
        virtual bool RenameByPath(const char* path, const char* newUri) { return false; }
        virtual bool IsFile(const Uri& uri);
        virtual bool IsFileByPath(const char* path) = 0;
        virtual bool IsDirectory(const Uri& uri);
        virtual bool IsDirectoryByPath(const char* path) = 0;
        virtual bool CreateDirectoryRecursively(const Uri& uri);
        virtual bool CreateDirectoryRecursivelyByPath(const char* path);
    };

    class FileSystemImpl : public fnd::ReferencedObject, public IFileSystem {
    public:
        virtual void* GetRuntimeTypeInfo() const override;

        DEFAULT_CREATE_FUNC(FileSystemImpl);
    };
    
    class FileSystemNative : public FileSystemImpl {
    public:
        csl::ut::MoveArray<void*> unk1;

        DEFAULT_CREATE_FUNC(FileSystemNative);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void UnkFunc28(const char* path, csl::ut::String& unkParam2) = 0;
        virtual void UnkFunc29(const char* path, csl::ut::String& unkParam2) = 0;
        virtual void UnkFunc30() {}
    };
    
    class FileSystemWin32 : public FileSystemNative {
    public:
        DEFAULT_CREATE_FUNC(FileSystemWin32);
        
        virtual StreamReader* OpenFileForReadingByPath(const char* path) override;
        virtual StreamWriter* OpenFileForWritingByPath(const char* path, csl::fnd::IAllocator* allocator) override;
        virtual bool ListDirectoryByPath(const char* path, FileSet& results) override;
        virtual bool CreateDirectoryByPath(const char* path) override;
        virtual bool DeleteByPath(const char* path) override;
        virtual bool RenameByPath(const char* path, const char* newUri) override;
        virtual bool IsFileByPath(const char* path) override;
        virtual bool IsDirectoryByPath(const char* path) override;
        virtual void UnkFunc28(const char* path, csl::ut::String& unkParam2) override;
        virtual void UnkFunc29(const char* path, csl::ut::String& unkParam2) override;
    };

    class FileSystemNativeLocal : public FileSystemImpl {
    public:
        FileSystemNative* nativeFilesystem;

        CREATE_FUNC(FileSystemNativeLocal, FileSystemNative* nativeFilesystem);

        virtual StreamReader* OpenFileForReadingByPath(const char* path) override;
        virtual StreamWriter* OpenFileForWritingByPath(const char* path, csl::fnd::IAllocator* allocator) override;
        virtual bool ListDirectoryByPath(const char* path, FileSet& results) override;
        virtual bool CreateDirectoryByPath(const char* path) override;
        virtual bool DeleteByPath(const char* path) override;
        virtual bool RenameByPath(const char* path, const char* newUri) override;
        virtual bool IsFileByPath(const char* path) override;
        virtual bool IsDirectoryByPath(const char* path) override;
        virtual bool CreateDirectoryRecursivelyByPath(const char* path) override;
    };

    class FileSystemNativeHost : public FileSystemImpl {
    public:
        FileSystemNative* nativeFilesystem;

        CREATE_FUNC(FileSystemNativeHost, FileSystemNative* nativeFilesystem);

        virtual StreamReader* OpenFileForReadingByPath(const char* path) override;
        virtual StreamWriter* OpenFileForWritingByPath(const char* path, csl::fnd::IAllocator* allocator) override;
        virtual bool ListDirectoryByPath(const char* path, FileSet& results) override;
        virtual bool CreateDirectoryByPath(const char* path) override;
        virtual bool DeleteByPath(const char* path) override;
        virtual bool RenameByPath(const char* path, const char* newUri) override;
        virtual bool IsFileByPath(const char* path) override;
        virtual bool IsDirectoryByPath(const char* path) override;
        virtual bool CreateDirectoryRecursivelyByPath(const char* path) override;
    };

    class NVMeFileSystem : public FileSystemImpl {
    public:
        FileSystemNative* nativeFilesystem;
        csl::fnd::Mutex mutex;

        CREATE_FUNC(NVMeFileSystem, FileSystemNative* nativeFilesystem);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual StreamReader* OpenFileForReadingByPath(const char* path) override;
        virtual StreamWriter* OpenFileForWritingByPath(const char* path, csl::fnd::IAllocator* allocator) override;
        virtual bool ListDirectoryByPath(const char* path, FileSet& results) override { return false; }
        virtual bool IsFileByPath(const char* path) override;
        virtual bool IsDirectoryByPath(const char* path) override { return false; }
        virtual bool UnkFunc28() { return false; }
        virtual int UnkFunc29();
        virtual void UnkFunc30() {}
        virtual unsigned char UnkFunc31();
        virtual bool UnkFunc32() { return false; }
        virtual unsigned int UnkFunc33();
        virtual bool UnkFunc34() { return false; }
    };

    class NVMeFileSystemNull : public NVMeFileSystem {
    public:
        CREATE_FUNC(NVMeFileSystemNull, FileSystemNative* nativeFilesystem);
    };

    class FileSystem : public IFileSystem, public hh::fnd::BaseObject, public csl::fnd::Singleton<FileSystem> {
    public:
        struct FileSystemDefinition {
            csl::ut::VariableString protocol;
            fnd::Reference<FileSystemImpl> filesystem;
        };

        FileSystemDefinition nativeFilesystem;
        csl::ut::InplaceMoveArray<FileSystemDefinition, 4> filesystems;

        DEFAULT_CREATE_FUNC(FileSystem);

        virtual void* GetRuntimeTypeInfo() const override;
        virtual ~FileSystem() = default; // TODO: implement
        virtual bool UnkFunc2(uint64_t unkParam) override;
        virtual bool UnkFunc3(const Uri& uri) override;
        virtual bool UnkFunc4(const char* path) override;
        virtual unsigned int UnkFunc5(const Uri& uri) override;
        virtual unsigned int UnkFunc6(const char* path) override;
        virtual bool UnkFunc7(const Uri& uri) override;
        virtual bool UnkFunc7a(const char* path) override;
        virtual StreamReader* OpenFileForReading(const Uri& uri) override;
        virtual StreamReader* OpenFileForReadingByPath(const char* path) override;
        virtual StreamWriter* OpenFileForWriting(const Uri& uri, csl::fnd::IAllocator* allocator) override;
        virtual StreamWriter* OpenFileForWritingByPath(const char* path, csl::fnd::IAllocator* allocator) override;
        virtual bool ListDirectory(const Uri& uri, FileSet& results) override;
        virtual bool ListDirectoryByPath(const char* path, FileSet& results) override;
        virtual bool CreateDirectory(const Uri& uri) override;
        virtual bool CreateDirectoryByPath(const char* path) override;
        virtual bool Delete(const Uri& uri) override;
        virtual bool DeleteByPath(const char* path) override;
        virtual bool Rename(const Uri& uri, const Uri& newUri) override;
        virtual bool RenameByPath(const char* path, const char* newUri) override;
        virtual bool IsFile(const Uri& uri) override;
        virtual bool IsFileByPath(const char* path) override;
        virtual bool IsDirectory(const Uri& uri) override;
        virtual bool IsDirectoryByPath(const char* path) override;

        FileSystemImpl* GetFileSystem(const Uri& uri) const;
        FileSystemImpl* GetFileSystem(const char* protocol) const;
    };
}
