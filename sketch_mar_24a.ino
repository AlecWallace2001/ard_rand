void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  
}

String start (int a)
{
  String binary  ("");
    int mask = 1;
    for(int i = 0; i < 5; i++)
    {
    if((mask&a) >= 1)
        binary = "1"+binary;
    else
        binary = "0"+binary;
     mask<<=1;
 }
 return binary;     //optional if not using ideone
 };


  String bin1 = start((rand() %30)+1);
  String bin2 = start((rand() %30)+1);
  String bin3 = start((rand() %30)+1);
  String bin4 = start((rand() %30)+1);
  String bin5 = start((rand() %30)+1);
  String bin6 = start((rand() %30)+1);
  String bin7 = start((rand() %30)+1);
  String bin8 = start((rand() %30)+1);
  String bin9 = start((rand() %30)+1);
  
  int rotary0Seq[][5] = {
    {bin1[0]-'0',bin1[1]-'0',bin1[2]-'0',bin1[3]-'0',bin1[4]-'0'},
    {bin2[0]-'0',bin2[1]-'0',bin2[2]-'0',bin2[3]-'0',bin2[4]-'0'},
    {bin3[0]-'0',bin3[1]-'0',bin3[2]-'0',bin3[3]-'0',bin3[4]-'0'}
  };
  int rotary1Seq[][5] = {
    {bin4[0]-'0',bin4[1]-'0',bin4[2]-'0',bin4[3]-'0',bin4[4]-'0'},
    {bin5[0]-'0',bin5[1]-'0',bin5[2]-'0',bin5[3]-'0',bin5[4]-'0'},
    {bin6[0]-'0',bin6[1]-'0',bin6[2]-'0',bin6[3]-'0',bin6[4]-'0'}
  };
  int rotary2Seq[][5] = {
    {bin7[0]-'0',bin7[1]-'0',bin7[2]-'0',bin7[3]-'0',bin7[4]-'0'},
    {bin8[0]-'0',bin8[1]-'0',bin8[2]-'0',bin8[3]-'0',bin8[4]-'0'},
    {bin9[0]-'0',bin9[1]-'0',bin9[2]-'0',bin9[3]-'0',bin9[4]-'0'}
  };


int cycle ()
{
  bin1 = start((rand() %30)+1);
  bin2 = start((rand() %30)+1);
  bin3 = start((rand() %30)+1);
  bin4 = start((rand() %30)+1);
  bin5 = start((rand() %30)+1);
  bin6 = start((rand() %30)+1);
  bin7 = start((rand() %30)+1);
  bin8 = start((rand() %30)+1);
  bin9 = start((rand() %30)+1);
  
  rotary0Seq[0][0]= bin1[0]-'0';
  rotary0Seq[0][1]= bin1[1]-'0';
  rotary0Seq[0][2]= bin1[2]-'0';
  rotary0Seq[0][3]= bin1[3]-'0';
  rotary0Seq[0][4]= bin1[4]-'0';
  rotary0Seq[1][0]= bin2[0]-'0';
  rotary0Seq[1][1]= bin2[1]-'0';
  rotary0Seq[1][2]= bin2[2]-'0';
  rotary0Seq[1][3]= bin2[3]-'0';
  rotary0Seq[1][4]= bin2[4]-'0';
  rotary0Seq[2][0]= bin3[0]-'0';
  rotary0Seq[2][1]= bin3[1]-'0';
  rotary0Seq[2][2]= bin3[2]-'0';
  rotary0Seq[2][3]= bin3[3]-'0';
  rotary0Seq[2][4]= bin3[4]-'0';

  rotary1Seq[0][0]= bin4[0]-'0';
  rotary1Seq[0][1]= bin4[1]-'0';
  rotary1Seq[0][2]= bin4[2]-'0';
  rotary1Seq[0][3]= bin4[3]-'0';
  rotary1Seq[0][4]= bin4[4]-'0';
  rotary1Seq[1][0]= bin5[0]-'0';
  rotary1Seq[1][1]= bin5[1]-'0';
  rotary1Seq[1][2]= bin5[2]-'0';
  rotary1Seq[1][3]= bin5[3]-'0';
  rotary1Seq[1][4]= bin5[4]-'0';
  rotary1Seq[2][0]= bin6[0]-'0';
  rotary1Seq[2][1]= bin6[1]-'0';
  rotary1Seq[2][2]= bin6[2]-'0';
  rotary1Seq[2][3]= bin6[3]-'0';
  rotary1Seq[2][4]= bin6[4]-'0';
  
  rotary2Seq[0][0]= bin7[0]-'0';
  rotary2Seq[0][1]= bin7[1]-'0';
  rotary2Seq[0][2]= bin7[2]-'0';
  rotary2Seq[0][3]= bin7[3]-'0';
  rotary2Seq[0][4]= bin7[4]-'0';
  rotary2Seq[1][0]= bin8[0]-'0';
  rotary2Seq[1][1]= bin8[1]-'0';
  rotary2Seq[1][2]= bin8[2]-'0';
  rotary2Seq[1][3]= bin8[3]-'0';
  rotary2Seq[1][4]= bin8[4]-'0';
  rotary2Seq[2][0]= bin9[0]-'0';
  rotary2Seq[2][1]= bin9[1]-'0';
  rotary2Seq[2][2]= bin9[2]-'0';
  rotary2Seq[2][3]= bin9[3]-'0';
  rotary2Seq[2][4]= bin9[4]-'0';
 return 0;
 };




void loop() {
  // put your main code here, to run repeatedly:
int var = 0;

Serial.println("Start");
Serial.println(rotary0Seq[0][0]);
do
{
  cycle();
  var++;
}
while (var < 200);

String command = start((rand() %30)+1);
Serial.println(rotary0Seq[0][0]);
delay(500);
}
