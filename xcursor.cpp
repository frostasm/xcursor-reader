// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "xcursor.h"
#include "kaitai/exceptions.h"

xcursor_t::xcursor_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, xcursor_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;
    m_toc = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void xcursor_t::_read() {
    m_magic = m__io->read_bytes(4);
    if (!(magic() == std::string("\x58\x63\x75\x72", 4))) {
        throw kaitai::validation_not_equal_error<std::string>(std::string("\x58\x63\x75\x72", 4), magic(), _io(), std::string("/seq/0"));
    }
    m_header_len = m__io->read_u4le();
    m_version = m__io->read_u4le();
    m_ntoc = m__io->read_u4le();
    int l_toc = ntoc();
    m_toc = new std::vector<toc_entry_t*>();
    m_toc->reserve(l_toc);
    for (int i = 0; i < l_toc; i++) {
        m_toc->push_back(new toc_entry_t(m__io, this, m__root));
    }
}

xcursor_t::~xcursor_t() {
    _clean_up();
}

void xcursor_t::_clean_up() {
    if (m_toc) {
        for (std::vector<toc_entry_t*>::iterator it = m_toc->begin(); it != m_toc->end(); ++it) {
            delete *it;
        }
        delete m_toc; m_toc = 0;
    }
}

xcursor_t::chunk_comment_t::chunk_comment_t(kaitai::kstream* p__io, xcursor_t::chunk_t* p__parent, xcursor_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void xcursor_t::chunk_comment_t::_read() {
    m_length = m__io->read_u4le();
    m_string = kaitai::kstream::bytes_to_str(m__io->read_bytes(length()), std::string("UTF-8"));
}

xcursor_t::chunk_comment_t::~chunk_comment_t() {
    _clean_up();
}

void xcursor_t::chunk_comment_t::_clean_up() {
}

xcursor_t::chunk_image_t::chunk_image_t(kaitai::kstream* p__io, xcursor_t::chunk_t* p__parent, xcursor_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_pixels = 0;
    f_size = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void xcursor_t::chunk_image_t::_read() {
    m_width = m__io->read_u4le();
    m_height = m__io->read_u4le();
    m_yhot = m__io->read_u4le();
    m_xhot = m__io->read_u4le();
    m_delay = m__io->read_u4le();
    int l_pixels = ((width() * height()) * 4);
    m_pixels = new std::vector<uint8_t>();
    m_pixels->reserve(l_pixels);
    for (int i = 0; i < l_pixels; i++) {
        m_pixels->push_back(m__io->read_u1());
    }
}

xcursor_t::chunk_image_t::~chunk_image_t() {
    _clean_up();
}

void xcursor_t::chunk_image_t::_clean_up() {
    if (m_pixels) {
        delete m_pixels; m_pixels = 0;
    }
}

int32_t xcursor_t::chunk_image_t::size() {
    if (f_size)
        return m_size;
    m_size = ((width() * height()) * 4);
    f_size = true;
    return m_size;
}

xcursor_t::chunk_t::chunk_t(kaitai::kstream* p__io, xcursor_t::toc_entry_t* p__parent, xcursor_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void xcursor_t::chunk_t::_read() {
    m_header = m__io->read_u4le();
    m_type = static_cast<xcursor_t::chunk_type_t>(m__io->read_u4le());
    m_subtype = m__io->read_u4le();
    m_version = m__io->read_u4le();
    n_body = true;
    switch (type()) {
    case xcursor_t::CHUNK_TYPE_COMMENT: {
        n_body = false;
        m_body = new chunk_comment_t(m__io, this, m__root);
        break;
    }
    case xcursor_t::CHUNK_TYPE_IMAGE: {
        n_body = false;
        m_body = new chunk_image_t(m__io, this, m__root);
        break;
    }
    }
}

xcursor_t::chunk_t::~chunk_t() {
    _clean_up();
}

void xcursor_t::chunk_t::_clean_up() {
    if (!n_body) {
        if (m_body) {
            delete m_body; m_body = 0;
        }
    }
}

xcursor_t::toc_entry_t::toc_entry_t(kaitai::kstream* p__io, xcursor_t* p__parent, xcursor_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_chunk = 0;
    f_chunk = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void xcursor_t::toc_entry_t::_read() {
    m_type = static_cast<xcursor_t::chunk_type_t>(m__io->read_u4le());
    m_subtype = m__io->read_u4le();
    m_position = m__io->read_u4le();
}

xcursor_t::toc_entry_t::~toc_entry_t() {
    _clean_up();
}

void xcursor_t::toc_entry_t::_clean_up() {
    if (f_chunk) {
        if (m_chunk) {
            delete m_chunk; m_chunk = 0;
        }
    }
}

xcursor_t::chunk_t* xcursor_t::toc_entry_t::chunk() {
    if (f_chunk)
        return m_chunk;
    std::streampos _pos = m__io->pos();
    m__io->seek(position());
    m_chunk = new chunk_t(m__io, this, m__root);
    m__io->seek(_pos);
    f_chunk = true;
    return m_chunk;
}
