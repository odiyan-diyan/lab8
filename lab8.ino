//Oluwatosin Diyan
// 03/31/22
// CPE 301 
// Lab 8

#define RDA 0x80
#define TBE 0x20  

volatile unsigned char *myUCSR0A = (unsigned char *)0x00C0;
volatile unsigned char *myUCSR0B = (unsigned char *)0x00C1;
volatile unsigned char *myUCSR0C = (unsigned char *)0x00C2;
volatile unsigned int  *myUBRR0  = (unsigned int *) 0x00C4;
volatile unsigned char *myUDR0   = (unsigned char *)0x00C6;
volatile unsigned char* my_ADMUX = (unsigned char*) 0x7C;
volatile unsigned char* my_ADCSRB = (unsigned char*) 0x7B;
volatile unsigned char* my_ADCSRA = (unsigned char*) 0x7A;
volatile unsigned int* my_ADC_DATA = (unsigned int*) 0x78;

void setup() 
{
  // setup the UART
  U0init(9600);
  // setup the ADC
  adc_init();
}
void loop() 
{
  // get the reading from the ADC
  unsigned int adc_reading = adc_read(0);
  // print it to the serial port
  print_int(adc_reading);
}
void adc_init(int bit){
ADMUX = (0 << REFS1) | (1 << REFS0);
If (bit == 7){
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
	}
	else if(factor == 8){
	ADCSRA = (1 << ADEN) | (0 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
	}
	else if(factor == 16){
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (0 << ADPS1) | (0 << ADPS0);
	}
else if(factor == 32){
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (0 << ADPS1) | (1 << ADPS0);
	}
	else if(factor == 64){
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
	}
else if(factor == 128){
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
	}
	}
{


int setup(unsigned char *myUCSR0A){
	if(int A = 7){

	return ((1 << A | *myUCSR0A);
	}
	else if(A = 5){
	return (myUCSR0A & (0 << A – 1);
	ADCSRA = 0;
	}
else if(A = 5){
	return (myUCSR0A & (0 << A – 1);
	ADMUX= 0;
	}
	else if(A = 5){
	return (myUCSR0A & (0 << A – 1);
	ADEN = 0; // slow reading
	}
int setup(unsigned char *myUCSR0B){
	if(int B = 3){

	return ((0 << A | *myUCSR0B);
	}
	else if(0 << B << 2){
	return (myUCSR0B & (0 << B – 1);
	ADCSRB = 0;
	}
else if(A = 5){
	return (myUCSR0A & (0 << B – 1);
	ADMUX= 0;
	}
int cbits(unsigned char *my_ADMUX
	if(int MUX = 7){

	return ((0 << MUX | *my_ADMUX);
	}
	else if(MUX = 6){

	return ((1 << MUX | *my_ADMUX);
	}
else if(MUX = 5){

	return ((0 << MUX | *my_ADMUX);
	}
else if(MUX = 4){

	return ((0 << MUX | *my_ADMUX);
	}


else if(A = 5){
	return (myUCSR0A & (0 << B – 1);
	ADMUX= 0;
	}
}
unsigned int adc_read(unsigned char adc_channel_num)
{
  int bit, place;
int x = (3 >> bit >> 6);
int y = (0 >> place >> 1);
if(bit = 4, place = 0){

printf(“%d\n”, cbits(bit, place));

}else if{bit = 5, place = 0{

printf(“%d\n”, cbits(bit, place));

}else if{bit = 6, place = 1

printf(“%d\n”, cbits(bit, place));

}
else{
	return (bits & (1 << (place – 1)));
}
}
int channel(int ch);
ch = 4;


}
void print_int(unsigned int out_num)
{
  // clear a flag (for printing 0's in the middle of numbers)
  unsigned char print_flag = 0;
  // if its greater than 1000
  if(out_num >= 1000)
  {
    // get the 1000's digit, add to '0' 
    U0putchar(out_num / 1000 + '0');
    // set the print flag
    print_flag = 1;
    // mod the out num by 1000
    out_num = out_num % 1000;
  }
  // if its greater than 100 or we've already printed the 1000's
  if(out_num >= 100 || print_flag)
  {
    // get the 100's digit, add to '0'
    U0putchar(out_num / 100 + '0');
    // set the print flag
    print_flag = 1;
    // mod the output num by 100
    out_num = out_num % 100;
  } 
  // if its greater than 10, or we've already printed the 10's
  if(out_num >= 10 || print_flag)
  {
    U0putchar(out_num / 10 + '0');
    print_flag = 1;
    out_num = out_num % 10;
  } 
  // always print the last digit (in case it's 0)
  U0putchar(out_num + '0');
  // print a newline
  U0putchar('\n');
}
void U0init(int U0baud)
{
 unsigned long FCPU = 16000000;
 unsigned int tbaud;
 tbaud = (FCPU / 16 / U0baud - 1);
 // Same as (FCPU / (16 * U0baud)) - 1;
 *myUCSR0A = 0x20;
 *myUCSR0B = 0x18;
 *myUCSR0C = 0x06;
 *myUBRR0  = tbaud;
}
unsigned char U0kbhit()
{
  return *myUCSR0A & RDA;
}
unsigned char U0getchar()
{
  return *myUDR0;
}
void U0putchar(unsigned char U0pdata)
{
  while((*myUCSR0A & TBE)==0);
  *myUDR0 = U0pdata;
}
