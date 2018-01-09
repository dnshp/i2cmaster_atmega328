# I2C master library for the ATmega328/328P

Basic functions to operate the ATmega328/328P in Master Transmitter or Master Receiver mode. These have been tested on the 328/328P, and should work (but have not been tested) for the 48A/48PA/88A/88PA/168A/168PA.

## Functions

**I2C_init**: initializes the I2C interface with the provided bitrate. Choose an appropriate SCL frequency (baud rate) for your peripheral, then calculate the bitrate according to the following: SCL frequency = (CPU clock frequency) / (16 + 2*bitrate). The prescaler has been hardcoded to 1, but this may be updated in the future.

**I2C_start**: transmits a start condition. Returns 1 if successful and 0 if not.

**I2C_repeated_start**: transmits a repeated start condition. Returns 1 if successful and 0 if not.

**I2C_stop**: transmits a stop condition and returns 1.

**I2C_write**: writes the argument (a single byte) to the I2C interface. Returns 1 if successful and 0 if not.

**I2C_read_ack**: reads a byte from the I2C interface and transmits an ACK bit. Returns the read value if successful and 0 if not.

**I2C_read_nack**: reads a byte from the I2C interface but does not transmit an ACK bit. Returns the read value if successful and 0 if not.

Credit to embedds.com for I2C code examples that inspired this project.

## Changelog

**v1.0** (1/9/2018): Initial commit.
