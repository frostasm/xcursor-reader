meta:
  id: xcursor
  file-extension: xcursor
  endian: le
doc: |
  Xcursor defines a new format for cursors on disk. Each file holds one or more cursor images. 
  Each cursor image is tagged with a nominal size so that the best size can be selected automatically. 
  https://www.x.org/releases/X11R7.5/doc/man/man3/Xcursor.3.html
seq:
  - id: magic
    contents: [0x58, 0x63, 0x75, 0x72]
  - id: header_len
    type: u4
  - id: version
    type: u4
  - id: ntoc
    type: u4
  - id: toc
    type: toc_entry
    repeat: expr
    repeat-expr: ntoc
    
enums:
  comment_subtype:
    1: copyright
    2: license
    3: other

  chunk_type:
    0xfffd0001: comment
    0xfffd0002: image

types:
  chunk_comment:
    seq:
      - id: length
        type: u4
      - id: string
        type: str
        size: length
        encoding: UTF-8
  
  chunk_image:
    seq:
      - id: width
        type: u4
      - id: height
        type: u4
      - id: yhot
        type: u4
      - id: xhot
        type: u4
      - id: delay
        type: u4
      - id: pixels
        type: u1
        repeat: expr
        repeat-expr: width * height * 4
    instances:
      size:
        value: width * height * 4

  chunk:
    seq:
      - id: header
        type: u4
      - id: type
        type: u4
        enum: chunk_type
      - id: subtype
        type: u4
      - id: version
        type: u4
      - id: body
        # type: chunk_image
        type: 
          switch-on: type
          cases:
            'chunk_type::comment': chunk_comment
            'chunk_type::image': chunk_image


  toc_entry:
    seq:
      - id: type
        type: u4
        enum: chunk_type
      - id: subtype
        type: u4
      - id: position
        type: u4
    instances:
      chunk:
        pos: position
        type: chunk
