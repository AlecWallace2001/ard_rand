String start (int a)
{
  //This function converts a number between 1 and 31 to a binary string and returns it
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
  for (int i = 0; i <= 10; i++) {
    seed = seed + (analogRead(0)*analogRead(0));
  };
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
  int attempt[10] ={0,0,0,0,0,0,0,0,0,0};
  int next_attempt[10] ={2,2,2,2,2,2,2,2,2,2};
  int solution[5] ={1,1,1,1,1};
  int entry[5] ={0,0,0,0,0};
  int a_state = 0;
  int b_state = 0;
  int c_state = 0;
  int usa = 0;
  int usb = 0;
  int usc = 0;
  int valid_sol = 0;
  int curr_state[5] ={0,0,0,0,0};
  int buttonSeq[][5] = {
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
  //This function generates a new set by selecting a new seed, creating new binary values,
  //then assigning the new values to the array
  updateRand();
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
      attempt[j_var]=0;
    } else {
      attempt[j_var] = 1 + attempt[j_var];
      return 0;
    }
    j_var++;
  }
  while (j_var <=9);
  return 0;
}

int state_cycle(char var_state) {
  //This cycles our state between the different program button presses.
  if(var_state=='a') {
    if(a_state==2) {
      a_state = 0;
    } else {
      a_state = 1 + a_state;
    }
  } else if (var_state=='b') {
    if(b_state==2) {
      b_state = 0;
    } else {
      b_state = 1 + b_state;
    }
  } else {
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
  a_state = 0;
  b_state = 0;
  c_state = 0;
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
  prsteps = prsteps + "current: "; 
  prsteps = prsteps + curr_state[0]; 
  prsteps = prsteps + curr_state[1]; 
  prsteps = prsteps + curr_state[2]; 
  prsteps = prsteps + curr_state[3]; 
  prsteps = prsteps + curr_state[4]; 
  prsteps = prsteps + ";"; 
  prsteps = prsteps + "solution: "; 
  prsteps = prsteps + solution[0]; 
  prsteps = prsteps + solution[1]; 
  prsteps = prsteps + solution[2]; 
  prsteps = prsteps + solution[3]; 
  prsteps = prsteps + solution[4];
  prsteps = prsteps + " ,"; 
  if((solution[0] == curr_state[0])&&(solution[1] == curr_state[1])&&(solution[2] == curr_state[2])&&(solution[3] == curr_state[3])&&(solution[4] == curr_state[4])) {
    if (valid_sol == 0) {
          steps = step_num+1;
    };
    valid_sol = 1;
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
  for (int i = 0; i <= steps; i++) {
    if (attempt[i] == prev) {
      return 0;
    } else {
      prev = attempt[i];
    }
  }
    return 1;
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
        if ((valid_sol==1)&&(steps>=4)&&(steps<=7)&&(no_dupe()==1)) {
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
  pinMode(13, OUTPUT);
  Serial.println("Start");
  cycle();
  gen_val_state();
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
}
