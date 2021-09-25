#ifndef XCURSOR_H_
#define XCURSOR_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

/**
 * https://www.x.org/releases/X11R7.5/doc/man/man3/Xcursor.3.html
 */

class xcursor_t : public kaitai::kstruct {

public:
    class chunk_comment_t;
    class chunk_image_t;
    class chunk_t;
    class toc_entry_t;

    enum comment_subtype_t {
        COMMENT_SUBTYPE_COPYRIGHT = 1,
        COMMENT_SUBTYPE_LICENSE = 2,
        COMMENT_SUBTYPE_OTHER = 3
    };

    enum chunk_type_t {
        CHUNK_TYPE_COMMENT = 4294770689,
        CHUNK_TYPE_IMAGE = 4294770690
    };

    xcursor_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, xcursor_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~xcursor_t();

    class chunk_comment_t : public kaitai::kstruct {

    public:

        chunk_comment_t(kaitai::kstream* p__io, xcursor_t::chunk_t* p__parent = 0, xcursor_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~chunk_comment_t();

    private:
        uint32_t m_length;
        std::string m_string;
        xcursor_t* m__root;
        xcursor_t::chunk_t* m__parent;

    public:
        uint32_t length() const { return m_length; }
        std::string string() const { return m_string; }
        xcursor_t* _root() const { return m__root; }
        xcursor_t::chunk_t* _parent() const { return m__parent; }
    };

    class chunk_image_t : public kaitai::kstruct {

    public:

        chunk_image_t(kaitai::kstream* p__io, xcursor_t::chunk_t* p__parent = 0, xcursor_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~chunk_image_t();

    private:
        bool f_size;
        int32_t m_size;

    public:
        int32_t size();

    private:
        uint32_t m_width;
        uint32_t m_height;
        uint32_t m_yhot;
        uint32_t m_xhot;
        uint32_t m_delay;
        std::vector<uint8_t>* m_pixels;
        xcursor_t* m__root;
        xcursor_t::chunk_t* m__parent;

    public:
        uint32_t width() const { return m_width; }
        uint32_t height() const { return m_height; }
        uint32_t yhot() const { return m_yhot; }
        uint32_t xhot() const { return m_xhot; }
        uint32_t delay() const { return m_delay; }
        std::vector<uint8_t>* pixels() const { return m_pixels; }
        xcursor_t* _root() const { return m__root; }
        xcursor_t::chunk_t* _parent() const { return m__parent; }
    };

    class chunk_t : public kaitai::kstruct {

    public:

        chunk_t(kaitai::kstream* p__io, xcursor_t::toc_entry_t* p__parent = 0, xcursor_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~chunk_t();

    private:
        uint32_t m_header;
        chunk_type_t m_type;
        uint32_t m_subtype;
        uint32_t m_version;
        kaitai::kstruct* m_body;
        bool n_body;

    public:
        bool _is_null_body() { body(); return n_body; };

    private:
        xcursor_t* m__root;
        xcursor_t::toc_entry_t* m__parent;

    public:
        uint32_t header() const { return m_header; }
        chunk_type_t type() const { return m_type; }
        uint32_t subtype() const { return m_subtype; }
        uint32_t version() const { return m_version; }
        kaitai::kstruct* body() const { return m_body; }
        xcursor_t* _root() const { return m__root; }
        xcursor_t::toc_entry_t* _parent() const { return m__parent; }
    };

    class toc_entry_t : public kaitai::kstruct {

    public:

        toc_entry_t(kaitai::kstream* p__io, xcursor_t* p__parent = 0, xcursor_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~toc_entry_t();

    private:
        bool f_chunk;
        chunk_t* m_chunk;

    public:
        chunk_t* chunk();

    private:
        chunk_type_t m_type;
        uint32_t m_subtype;
        uint32_t m_position;
        xcursor_t* m__root;
        xcursor_t* m__parent;

    public:
        chunk_type_t type() const { return m_type; }
        uint32_t subtype() const { return m_subtype; }
        uint32_t position() const { return m_position; }
        xcursor_t* _root() const { return m__root; }
        xcursor_t* _parent() const { return m__parent; }
    };

private:
    std::string m_magic;
    uint32_t m_header_len;
    uint32_t m_version;
    uint32_t m_ntoc;
    std::vector<toc_entry_t*>* m_toc;
    xcursor_t* m__root;
    kaitai::kstruct* m__parent;

public:
    std::string magic() const { return m_magic; }
    uint32_t header_len() const { return m_header_len; }
    uint32_t version() const { return m_version; }
    uint32_t ntoc() const { return m_ntoc; }
    std::vector<toc_entry_t*>* toc() const { return m_toc; }
    xcursor_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // XCURSOR_H_
