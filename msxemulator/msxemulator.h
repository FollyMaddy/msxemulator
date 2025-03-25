// Configuration
#define HW_FLASH_STORAGE_MEGABYTES 02  // Define the pico's FLASH size in Megabytes (01MB - 16MB)
//#define USE_I2S  // Enable I2S DAC Output and SCC emulation
//#define USE_OPLL  // Enable OPLL emulation. Sets CLOCKMUL on 10 (overclock). Needs USE_I2S uncommented. Needs FM-PAC BIOS.
#define USE_FDC  // Enable SONY HBD-F1 emulation. needs DISKBIOS.

// Useful for pico1 with VGA blackouts when using PSG only, pico2 can do without it
//#define USE_OVERCLOCK  // Set CLOCKMUL on 10 (not needed for pico2)
//#define USE_OVERCLOCKVOLTAGE_1_20  // Enable 1.2 volt for better overclocking, if needed. Don't worry, but usage is for your own risk.
