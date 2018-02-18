// This code borrows from http://www.embedds.com/programming-avr-I2C-interface/

#include <avr/io.h>

char I2C_check_status(char status_code) {
	if ((TWSR & 0xF8) != status_code) {
		return 0;
	}
  return 1;
}

void I2C_init(char bitrate) {
	TWSR = 0; // prescaler = 1
	TWBR = bitrate; // load into bitrate reg
}

char I2C_start() {
	TWCR = (1 << TWEN) | (1 << TWSTA) | (1 << TWINT); // transmit start condition
	while (!(TWCR & (1 << TWINT))); // wait for interrupt flag
  return I2C_check_status(0x08);
}

char I2C_repeated_start() {
	TWCR = (1 << TWEN) | (1 << TWSTA) | (1 << TWINT); // transmit start condition
	while (!(TWCR & (1 << TWINT))); // wait for interrupt flag
  return I2C_check_status(0x10);
}

char I2C_stop() {
	TWCR = (1 << TWEN) | (1 << TWSTO) | (1 << TWINT); // transmit stop condition
	while(TWCR & (1<<TWSTO));
  return 1;
}

char I2C_write(char byte) {
	TWDR = byte;
	TWCR = (1 << TWINT) | (1 << TWEN); // clear interrupt flag to transmit
	while (!(TWCR & (1 << TWINT)));
  return I2C_check_status(0x28);
}

char I2C_read_ack() {
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
	while (!(TWCR & (1 << TWINT)));
  if (I2C_check_status(0x58)) {
    return TWDR;
  }
  return 0;
}

char I2C_read_nack() {
	TWCR = (1 << TWINT) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
  if (I2C_check_status(0x58)) {
    return TWDR;
  }
  return 0;
}
