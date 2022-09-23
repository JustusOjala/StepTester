#include <avr/io.h>
#include <util/delay.h>

#define DELAY 10

int main(){
	DDRA = 0xFF;
	DDRB = 0x3F;

	PORTA = 0;
	PORTB = 0;

	uint i;
	//Spin in one direction
	PORTB |= 0x08;
	//Go through all 8 microstep settings
	for(i = 0; i < 8; i++){
		PORTA = i;
		PORTB = (PORTB & 0x8F) + (i << 4);
		fail = 0;

		//Spin 1000 steps
		for(uint j = 0; j < 1000; j++){
			delay(DELAY);
			PORTB |= 0x04;
			delay(DELAY);
			PORTB &= 0xFB;
		}
	}

	//Spin in the other direction
	PORTB &= 0xF7;
	//Go through all 8 microstep settings
	for(i = 0; i < 8; i++){
		PORTA = i + 0x08;
		PORTB = (PORTB & 0x8F) + (i << 4);

		//Spin 1000 steps
		for(uint j = 0; j < 1000; j++){
			delay(DELAY);
			PORTB |= 0x04;
			delay(DELAY);
			PORTB &= 0xFB;
		}
	}
	
	return 0
}
