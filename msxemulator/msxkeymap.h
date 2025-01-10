// Keycodes for emulation

const uint16_t msxusbcode[] = {

    // SELECT STOP

         // 0x00    
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x40,0x02,  // A
        0x80,0x02,  // B
        0x01,0x03,  // C
        0x02,0x03,  // D
        0x04,0x03,  // E
        0x08,0x03,  // F
        0x10,0x03,  // G
        0x20,0x03,  // H
        0x40,0x03,  // I
        0x80,0x03,  // J
        0x01,0x04,  // K
        0x02,0x04,  // L
        // 0x10
        0x04,0x04,  // M
        0x08,0x04,  // N
        0x10,0x04,  // O
        0x20,0x04,  // P
        0x40,0x04,  // Q
        0x80,0x04,  // R
        0x01,0x05,  // S
        0x02,0x05,  // T
        0x04,0x05,  // U
        0x08,0x05,  // V
        0x10,0x05,  // W
        0x20,0x05,  // X
        0x40,0x05,  // Y
        0x80,0x05,  // Z
        0x02,0x00,  // 1
        0x04,0x00,  // 2
        // 0x20
        0x08,0x00,  // 3
        0x10,0x00,  // 4
        0x20,0x00,  // 5
        0x40,0x00,  // 6
        0x80,0x00,  // 7
        0x01,0x01,  // 8
        0x02,0x01,  // 9
        0x01,0x00,  // 0
        0x80,0x07,  // Enter
        0x04,0x07,  // Escape  
        0x20,0x07,  // Backspace
        0x80,0x07,  // Tab
        0x01,0x08,  // Space
        0x04,0x01,  // -
        0x08,0x01,  // ^ = +
        0x20,0x01,  // @
        // 0x30
        0x40,0x01,  // [ = (
        0x02,0x02,  // ] = )
        0x00,0x00,  //
        0x80,0x01,  // ;
        0x01,0x02,  // :
        0x00,0x00,  // Hankaku/Zenkaku
        0x04,0x02,  // ,
        0x08,0x02,  // .
        0x10,0x02,  // /
        0x08,0x06,  // CapsLock
        0x20,0x06,  // F1
        0x40,0x06,  // F2
        0x80,0x06,  // F3
        0x01,0x07,  // F4
        0x02,0x07,  // F5
        0x00,0x00,
        // 0x40
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x40,0x07,  // ScrollLock -> SELECT
        0x10,0x07,  // Pause -> STOP
        0x04,0x08,  // INS
        0x02,0x08,  // Home
        0x00,0x00,  // PageUP
        0x08,0x08,  // Del
        0x00,0x00,  // End
        0x00,0x00,  // PageDown
        0x80,0x08,  // Right
    // 0x50
        0x10,0x08,  // Left
        0x40,0x08,  // Down
        0x20,0x08,  // Up
        0x00,0x00,  // Numlock 
        0x00,0x00,  // Keypad /
        0x00,0x00,  // Keypad * 
        0x20,0x0a,  // Keypad -
        0x40,0x0a,  // Keypad + = , 
        0x80,0x07,  // Keypad Enter
        0x10,0x09,  // Keypad 1
        0x20,0x09,  // Keypad 2
        0x40,0x09,  // Keypad 3
        0x80,0x09,  // Keypad 4
        0x01,0x0a,  // Keypad 5
        0x02,0x0a,  // Keypad 6  
        0x04,0x0a,  // Keypad 7 
    // 0x60
        0x08,0x0a,  // Keypad 8
        0x10,0x0a,  // Keypad 9 
        0x08,0x09,  // Keypad 0 
        0x80,0x0a,  // Keypad .
        0x00,0x00, 
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
    // 0x70
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
    // 0x80
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x20,0x02,  // Ro
        0x10,0x06,  // Hira-Kata
        0x10,0x01,  // Yen = *
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
    // 0x90
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00, 
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
    // 0xa0
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
    // 0xb0
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
    // 0xc0
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
    // 0xd0
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
    // 0xe0
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
    // 0xf0
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
};

// Keycodes for MENU

const uint8_t usbhidcode[] = {
        // 0x00
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x41,0x00,  // A
        0x42,0x00,  // B
        0x43,0x00,  // C
        0x44,0x00,  // D
        0x45,0x00,  // E
        0x46,0x00,  // F
        0x47,0x00,  // G
        0x48,0x00,  // H
        0x49,0x00,  // I
        0x4a,0x00,  // J
        0x4b,0x00,  // K
        0x4c,0x00,  // L
        // 0x10
        0x4d,0x00,  // M
        0x4e,0x00,  // N
        0x4f,0x00,  // O
        0x50,0x00,  // P
        0x51,0x00,  // Q
        0x52,0x00,  // R
        0x53,0x00,  // S
        0x54,0x00,  // T
        0x55,0x00,  // U
        0x56,0x00,  // V
        0x57,0x00,  // W
        0x58,0x00,  // X
        0x59,0x00,  // Y
        0x5a,0x00,  // Z
        0x31,0x21,  // 1
        0x32,0x22,  // 2
        // 0x20
        0x33,0x23,  // 3
        0x34,0x24,  // 4
        0x35,0x25,  // 5
        0x36,0x26,  // 6
        0x37,0x27,  // 7
        0x38,0x28,  // 8
        0x39,0x29,  // 9
        0x30,0x00,  // 0
        0x0a,0x0a,  // Enter
        0x00,0x00,  // Escape
        0x08,0x08,  // Backspace
        0x00,0x00,  // Tab
        0x20,0x20,  // Space
        0x2d,0x3d,  // -
        0x7e,0x00,  // ^
        0x40,0x00,  // @
        // 0x30
        0x5b,0x00,  // [
        0x5d,0x00,  // ]
        0x00,0x00,  //
        0x3b,0x2b,  // ;
        0x3a,0x2a,  // :
        0x00,0x00,
        0x2c,0x3c,  // ,
        0x2e,0x3e,  // .
        0x2f,0x3f,  // /
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        // 0x40
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
        0x7f,0x7f,  // Del
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,
};

