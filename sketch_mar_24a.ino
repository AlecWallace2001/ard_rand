//Initializing the debug process. Setup to view the randomness generated due to an issue when reading
//a0
#ifdef DEBUG_ESP_PORT
#define DEBUG_MSG(...) DEBUG_ESP_PORT.printf( __VA_ARGS__ )
#else
#define DEBUG_MSG(...)
#endif

String start (int a)
{
  //This function converts a number between 1 and 31 to a binary string and returns it
  //The binary int has to be converted character by character and accomodate zero padding.
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
 }

int updateRand(){
  //This function generates the random seed to avoid duplicate sets
  long seed;
  long temp0;
  long temp1;
  for (int i = 0; i <= 10; i++) { // analogRead(0) seems to respond better tha, A0. Using ESP8266
                                  // with a bare analog pin, only a single digit (4-6) is created.
                                  // randomizing the seed segments with the cubed read function
                                  // generates a wider range of characters
    temp0 = random(1,random(1,(analogRead(0)*analogRead(0)*analogRead(0))));
    delay(1); //IMPORTANT Running the random generation too quickly causes memory to be exceeded and
              //there is data poisoning. This delay slows the process down so this doesnt happen.
              //This was discovered when the code worked without issue when running debug, but errored on
              //raw runs.
    temp1 = random(temp0,random(1,(temp0*analogRead(0)*analogRead(0)*analogRead(0))));
    #ifdef DEBUG_ESP_PORT //This allows the debug to print a line of 
    //Serial.print("(");
    //Serial.print(i);
    //Serial.print(")");
    //Serial.print(temp0);
    //Serial.print(" ");
    //Serial.print(temp1);
    //Serial.print(", ");
    #endif
    seed = seed + (temp0*temp1);
  };
  #ifdef DEBUG_ESP_PORT
  //Serial.println(" end");
  #endif
  seed = seed*seed;
  randomSeed(seed);
  return 0;
}

// Initializing our variables
  String bin1 = start(random(1,30));
  String bin2 = start(random(1,30));
  String bin3 = start(random(1,30));
  String bin4 = start(random(1,30));
  String bin5 = start(random(1,30));
  String bin6 = start(random(1,30));
  String bin7 = start(random(1,30));
  String bin8 = start(random(1,30));
  String bin9 = start(random(1,30));
  String prsteps = "";

  int print_cycle = 0;
  int prev = 4;
  int steps = 0;
  int attempt[10] ={0,0,0,0,0,0,0,0,0,0}; //current state being attempted
  int next_attempt[10] ={2,2,2,2,2,2,2,2,2,2}; //array to compare against to generate an attempt based iteration
  int solution[5] ={1,1,1,1,1}; // maintain comparative uniformity by using an expected array
  int a_state = 0; //button state, 0,1, or 2
  int b_state = 0; //button state, 0,1, or 2
  int c_state = 0; //button state, 0,1, or 2
  int valid_sol = 0; //Flag indicating if a valid solution has been found
  int curr_state[5] ={0,0,0,0,0}; // Current state based on the latest step
  int buttonSeq[][5] = {
    {bin1[0]-'0',bin1[1]-'0',bin1[2]-'0',bin1[3]-'0',bin1[4]-'0'},
    {bin2[0]-'0',bin2[1]-'0',bin2[2]-'0',bin2[3]-'0',bin2[4]-'0'},
    {bin3[0]-'0',bin3[1]-'0',bin3[2]-'0',bin3[3]-'0',bin3[4]-'0'}
  }; // Button 1 set
  int rotary1Seq[][5] = {
    {bin4[0]-'0',bin4[1]-'0',bin4[2]-'0',bin4[3]-'0',bin4[4]-'0'},
    {bin5[0]-'0',bin5[1]-'0',bin5[2]-'0',bin5[3]-'0',bin5[4]-'0'},
    {bin6[0]-'0',bin6[1]-'0',bin6[2]-'0',bin6[3]-'0',bin6[4]-'0'}
  }; // Button 2 set
  int rotary2Seq[][5] = {
    {bin7[0]-'0',bin7[1]-'0',bin7[2]-'0',bin7[3]-'0',bin7[4]-'0'},
    {bin8[0]-'0',bin8[1]-'0',bin8[2]-'0',bin8[3]-'0',bin8[4]-'0'},
    {bin9[0]-'0',bin9[1]-'0',bin9[2]-'0',bin9[3]-'0',bin9[4]-'0'}
  }; // Button 3 set
  unsigned long myTime;// millis count to show how long to find the solution
  unsigned long stTime;// millis count before generating the solution 


int cycle ()
{
  //This function generates a new set by selecting a new seed, creating new binary values,
  //then assigning the new values to the array
  updateRand(); //Update the seed to reduce the probability of duplicate solutions
  prsteps = "";
  bin1 = start(random(1,30));
  bin2 = start(random(1,30));
  bin3 = start(random(1,30));
  bin4 = start(random(1,30));
  bin5 = start(random(1,30));
  bin6 = start(random(1,30));
  bin7 = start(random(1,30));
  bin8 = start(random(1,30));
  bin9 = start(random(1,30));
  for (int i = 0; i <= 4; i++){
    buttonSeq[0][i]= bin1[i]-'0';
    buttonSeq[1][i]= bin2[i]-'0';
    buttonSeq[2][i]= bin3[i]-'0';
    rotary1Seq[0][i]= bin4[i]-'0';
    rotary1Seq[1][i]= bin5[i]-'0';
    rotary1Seq[2][i]= bin6[i]-'0';
    rotary2Seq[0][i]= bin7[i]-'0';
    rotary2Seq[1][i]= bin8[i]-'0';
    rotary2Seq[2][i]= bin9[i]-'0';
    curr_state[i] = 0;
  };
 return 0;
 };

int iterate_attempt() {
  //This process handles out 10 button combination. It iterates the array of 10 integers so we progress
  //through the possibilities from all 0 to all 2 putton presses. 
  int j_var = 0;
  do {
    if (attempt[j_var]==2) {
      attempt[j_var]=0;// Iterate the current step and continue the loop
    } else {
      attempt[j_var] = 1 + attempt[j_var];// iterate the current step and return
      return 0;
    }
    j_var++;
  }
  while (j_var <=9);
  return 0;
}

int state_cycle(char var_state) {
  //This cycles our state between the different program button presses.
  if(var_state=='a') {// Cycle the state if the first button was pressed using base 3
    if(a_state==2) {
      a_state = 0;
    } else {
      a_state = 1 + a_state;
    }
  } else if (var_state=='b') { // Cycle the state if the second button was pressed using base 3
    if(b_state==2) {
      b_state = 0;
    } else {
      b_state = 1 + b_state;
    }
  } else { // Cycle the state if the third button was pressed using base 3
    if(c_state==2) {
      c_state = 0;
    } else {
      c_state = 1 + c_state;
    }
  }
  return 0;
};

int reset_state() {
  //Sets the current state and button states back to zero
  curr_state[0] = 0;
  curr_state[1] = 0;
  curr_state[2] = 0;
  curr_state[3] = 0;
  curr_state[4] = 0;
  valid_sol = 0;
  a_state = 0;
  b_state = 0;
  c_state = 0;
  prsteps = " ";
  return 0;
};

int next_state(int* state, int loc) {
  //This handles the state of our lights, flipping between 1/0 based on what is in the button state
  //and the light state
  for (int i = 0; i <= 4; i++) {
    if (state[i] + curr_state[i] ==2) {
      curr_state[i] = 0;
    } else {
      curr_state[i] = state[i] + curr_state[i];
    }
  }
  return 0;
}

int validation(int step_num){
  //This just compares our currrent state with the anticipated solution. If all values in the current
  //light state match the solution state, then the valid solution flag is set.
  prsteps = prsteps + "current: "; // This logic creates the output for visual validation of the solution
  prsteps = prsteps + String(curr_state[0]); 
  prsteps = prsteps + String(curr_state[1]); 
  prsteps = prsteps + String(curr_state[2]); 
  prsteps = prsteps + String(curr_state[3]); 
  prsteps = prsteps + String(curr_state[4]); 
  prsteps = prsteps + ";"; 
  prsteps = prsteps + "solution: "; 
  prsteps = prsteps + String(solution[0]); 
  prsteps = prsteps + String(solution[1]); 
  prsteps = prsteps + String(solution[2]); 
  prsteps = prsteps + String(solution[3]); 
  prsteps = prsteps + String(solution[4]);
  prsteps = prsteps + " ,"; 
  if((solution[0] == curr_state[0])&&(solution[1] == curr_state[1])&&(solution[2] == curr_state[2])&&(solution[3] == curr_state[3])&&(solution[4] == curr_state[4])) {
    if (valid_sol == 0) {
          steps = step_num+1;
    };
    valid_sol = 1; //setting the global valid flag once a solution is found 
    return 1;
  } else {
    return 0;
  }
};

bool compare(){
  //better comparison to iterate if a solution is not found.
  bool next = true;
  for (int i = 0;  i < 10; i++) {
              if (attempt[i] != next_attempt[i]){
                next = false;
              };
            };
  return next;
};

int printsteps() {
  //Updated print out for the solution proof
String value1;
String value2 = prsteps;
// For loop which will separate the String in parts
// and assign them the the variables we declare
for (int i = 12; i < value2.length(); i++) {
  if (value2.substring(i, i+1) == ",") {
    Serial.println(value2.substring(0, i));
    value2 = value2.substring(i+1);
    i = 12;
  }
}
return 0;
}

int no_dupe() {
  prev = 4;
  steps;
  attempt;
  int st0 = 0;
  int st1 = 0;
  int st2 = 0;
  for (int i = 0; i < steps; i++) { //This cycles through the steps in the solution to compare the 
                                    //current step with the previous to detect duplicates
    if (attempt[i] == prev) {
      return 0;
    } else {
      prev = attempt[i];
    }
  }
  for (int i = 0; i < steps; i++) { //This cycles through the attempts to verify that the solution 
                                    //has used each button atleast once.
  #ifdef DEBUG_ESP_PORT
    Serial.print(i);
    Serial.print(" ");
    Serial.println(attempt[i]);
  #endif
    if (attempt[i] == 0) {
      st0++;
    } else if (attempt[i] == 1) {
      st1++;
    } else if (attempt[i] == 2) {
      st2++;
    }
  }
  if ((st0>=1)&&(st1>=1)&&(st2>=1)) {
    return 1;
  }
    return 0;
}

int gen_val_state() {
  //This is the main function. 
  do {
    //This will continue running until a valid solution is found. Then the 
    //function ends and the global variables contain a set of arrays that can solve the puzzle
    do{
      //This cycles through the 59k combinations to find out if this combination of arrays contains a valid solution.
      //at the point that a valid solution is found, the function exits. If no solution is found with the current
      //array set, a fresh array set is generated and tested.
        reset_state();
        for (int i = 0; i <= 9; i++) {
          //This cycles through the attempt array to test to see if it contains a valid combination
          //using the current arrays
          if (attempt[i]==0) {
            next_state(buttonSeq[a_state],i);
            state_cycle('a');
          } else if (attempt[i]==1) {
            next_state(rotary1Seq[b_state],i);
            state_cycle('b');
          } else {
            next_state(rotary2Seq[c_state],i);
            state_cycle('c');
          }
          validation(i);
        }
        if ((valid_sol==1)&&(steps>=5)&&(steps<=7)&&(no_dupe()==1)) {
          printsteps();
          return 1;
        } else if ((valid_sol==1) && (steps>7) && (no_dupe()==0)) {
          //The solution was found in an invalid path. Skip further tests and generate a new combination
          for (int i = 0;  i < 10; i++) {
              attempt[i] = next_attempt[i];
            };
        };
        valid_sol = 0;
        iterate_attempt();
    }
    while (compare());
    if ((valid_sol==0)||(no_dupe()==0)) {
      valid_sol=0;
      cycle();
    };
  }
  while (valid_sol == 0);
  return 0;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Serial1.begin(115200);
  DEBUG_MSG("bootup...\n");
  pinMode(13, OUTPUT);
  Serial.println("Start");
  stTime = millis();
  cycle();
  gen_val_state();
  myTime = millis()-stTime;
  Serial.print("generation in mills: ");
  Serial.println(myTime);
}

void loop() {
  // put your main code here, to run repeatedly:


if (print_cycle==0) {
  Serial.println(validation(steps));
  Serial.println("Seg1");
  for (int j = 0; j <= 2; j++){
    for (int i = 0; i <= 3; i++){
      Serial.print(buttonSeq[j][i]);
    }
    Serial.println(buttonSeq[j][4]);
  };
  Serial.println("Seg2");
  for (int j = 0; j <= 2; j++){
    for (int i = 0; i <= 3; i++){
      Serial.print(rotary1Seq[j][i]);
    }
    Serial.println(rotary1Seq[j][4]);
  };
  Serial.println("Seg3");
  for (int j = 0; j <= 2; j++){
    for (int i = 0; i <= 3; i++){
      Serial.print(rotary2Seq[j][i]);
    }
    Serial.println(rotary2Seq[j][4]);
  };
  Serial.println("solution list");
  for (int i = 0; i <= 9; i++){
    Serial.print(attempt[i]);
  };
  Serial.print(" ");
  Serial.println(steps);
};
print_cycle++;
delay(500);

  #ifdef DEBUG_ESP_PORT
  reset_state();
  Serial.println("Start");
  stTime = millis();
  cycle();
  gen_val_state();
  myTime = millis()-stTime;
  Serial.print("generation in mills: ");
  Serial.println(myTime);
  #endif
}
