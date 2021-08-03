/* Interfacing 14 Segment(Common Anode) display to Arduino Uno
 * 
 * Hardware Components:
 * Arduino Uno
 * 14 Segment display
 * 
 * Hardware Connections:
 * D0-D13 of Arduino Uno pins are connected to a,b,c,d,e,f,g,h,j,k,l,m,n of 14 Segment(Common Anode) display
 * D0-D5 = a,b,c,d,e,f
 * D6-D7 = g,h,j,k,l,m,n
 * 
 * Since it is common Anode 0 is used to activate the letter 
 *      a b c d e f p g h j k l m n 
 * H = [1 0 0 1 0 0 1 1 1 0 1 1 1 0] 
 * E = [0 1 1 0 0 0 1 1 1 0 1 1 1 0] 
 * L = [1 1 1 0 0 0 1 1 1 1 1 1 1 1] 
 * L = [1 1 1 0 0 0 1 1 1 1 1 1 1 1] 
 * O = [0 0 0 0 0 0 1 1 1 1 1 1 1 1] 
 * 
 * 
 * Author = Sahana B G
 * Date   = 30 Apr 2021
 */


// Pin initialization
const int FIRSTPIN = 0;
const int LASTPIN = 13;

// Defining an array to store led pattern 
int myArray[5][14] ={{1,0,0,1,0,0,1,1,1,0,1,1,1,0}, //'H'
                     {0,1,1,0,0,0,1,1,1,0,1,1,1,0}, //'E'
                     {1,1,1,0,0,0,1,1,1,1,1,1,1,1}, //'L'
                     {1,1,1,0,0,0,1,1,1,1,1,1,1,1}, //'L'
                     {0,0,0,0,0,0,1,1,1,1,1,1,1,1}}; //'O'
                 
void setup()
{
   // Intizalizing the output pins  
   for(int i = FIRSTPIN ; i<=LASTPIN; i++ )
    pinMode(i,OUTPUT);
}

void loop()
{
  int pin = FIRSTPIN ;
  
  for( int i = 0; i<5;i++) //  Iterating over row
  {
   for( int j = 0 ; j<14; j++) // Iterating over column
   {
    digitalWrite(pin,myArray[i][j]); // Set the digital pins to display given array
    pin++; 
    delay(10); // wait 10ms after displaying
   }
   pin = FIRSTPIN ; // Starts from first pin for next iteration
   delay(1000);     
  }
}
