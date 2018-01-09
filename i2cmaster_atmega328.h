// This code borrows from http://www.embedds.com/programming-avr-I2C-interface/

#include <avr/io.h>

void I2C_init(char bitrate);
char I2C_start();
char I2C_repeated_start();
char I2C_stop();
char I2C_write(char byte);
char I2C_read_ack();
char I2C_read_nack();
