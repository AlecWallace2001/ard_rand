String start (int a)
{
  //This function converts a number between 1 and 31 to a binary string and returns it
  Serial.println(a);
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
  Serial.println(seed);
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

  int steps = 0;
  int attempt[10] ={0,0,0,0,0,0,0,0,0,0};
  int next_attempt[10] ={2,2,2,2,2,2,2,2,2,2};
  int solution[5] ={1,1,1,1,1};
  int entry[5] ={0,0,0,0,0};
  int a_state = 0;
  int b_state = 0;
  int c_state = 0;
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
  int solutionP1[][5] = {
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
  };
  int solutionP2[][5] = {
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
  };


int cycle ()
{
  //This function generates a new set by selecting a new seed, creating new binary values,
  //then assigning the new values to the array
  updateRand();
  bin1 = start(random(1,30));
  bin2 = start(random(1,30));
  bin3 = start(random(1,30));
  bin4 = start(random(1,30));
  bin5 = start(random(1,30));
  bin6 = start(random(1,30));
  bin7 = start(random(1,30));
  bin8 = start(random(1,30));
  bin9 = start(random(1,30));
  buttonSeq[0][0]= bin1[0]-'0';
  buttonSeq[0][1]= bin1[1]-'0';
  buttonSeq[0][2]= bin1[2]-'0';
  buttonSeq[0][3]= bin1[3]-'0';
  buttonSeq[0][4]= bin1[4]-'0';
  buttonSeq[1][0]= bin2[0]-'0';
  buttonSeq[1][1]= bin2[1]-'0';
  buttonSeq[1][2]= bin2[2]-'0';
  buttonSeq[1][3]= bin2[3]-'0';
  buttonSeq[1][4]= bin2[4]-'0';
  buttonSeq[2][0]= bin3[0]-'0';
  buttonSeq[2][1]= bin3[1]-'0';
  buttonSeq[2][2]= bin3[2]-'0';
  buttonSeq[2][3]= bin3[3]-'0';
  buttonSeq[2][4]= bin3[4]-'0';
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
  curr_state[0] = 0;
  curr_state[1] = 0;
  curr_state[2] = 0;
  curr_state[3] = 0;
  curr_state[4] = 0;
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
};

int reset_state() {
  curr_state[0] = 0;
  curr_state[1] = 0;
  curr_state[2] = 0;
  curr_state[3] = 0;
  curr_state[4] = 0;
  a_state = 0;
  b_state = 0;
  c_state = 0;
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
}

int validation(int step_num){
  //This just compares our currrent state with the anticipated solution. If all values in the current
  //light state match the solution state, then the valid solution flag is set.
    Serial.print("current: "); 
    Serial.print(curr_state[0]); 
    Serial.print(curr_state[1]); 
    Serial.print(curr_state[2]); 
    Serial.print(curr_state[3]); 
    Serial.println(curr_state[4]); 
    Serial.print("solution: "); 
    Serial.print(solution[0]); 
    Serial.print(solution[1]); 
    Serial.print(solution[2]); 
    Serial.print(solution[3]); 
    Serial.println(solution[4]); 
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
        Serial.println("");
        if (valid_sol==1){
          return 0;
        }
        iterate_attempt();
    }
    while (attempt != next_attempt);
    cycle();
  }
  while (valid_sol == 0);
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
int var = 0;

Serial.println(validation(steps));
Serial.println("Seg1");
Serial.print(buttonSeq[0][0]);
Serial.print(buttonSeq[0][1]);
Serial.print(buttonSeq[0][2]);
Serial.print(buttonSeq[0][3]);
Serial.println(buttonSeq[0][4]);
Serial.print(buttonSeq[1][0]);
Serial.print(buttonSeq[1][1]);
Serial.print(buttonSeq[1][2]);
Serial.print(buttonSeq[1][3]);
Serial.println(buttonSeq[1][4]);
Serial.print(buttonSeq[2][0]);
Serial.print(buttonSeq[2][1]);
Serial.print(buttonSeq[2][2]);
Serial.print(buttonSeq[2][3]);
Serial.println(buttonSeq[2][4]);
Serial.println("Seg2");
Serial.print(rotary1Seq[0][0]);
Serial.print(rotary1Seq[0][1]);
Serial.print(rotary1Seq[0][2]);
Serial.print(rotary1Seq[0][3]);
Serial.println(rotary1Seq[0][4]);
Serial.print(rotary1Seq[1][0]);
Serial.print(rotary1Seq[1][1]);
Serial.print(rotary1Seq[1][2]);
Serial.print(rotary1Seq[1][3]);
Serial.println(rotary1Seq[1][4]);
Serial.print(rotary1Seq[2][0]);
Serial.print(rotary1Seq[2][1]);
Serial.print(rotary1Seq[2][2]);
Serial.print(rotary1Seq[2][3]);
Serial.println(rotary1Seq[2][4]);
Serial.println("Seg3");
Serial.print(rotary2Seq[0][0]);
Serial.print(rotary2Seq[0][1]);
Serial.print(rotary2Seq[0][2]);
Serial.print(rotary2Seq[0][3]);
Serial.println(rotary2Seq[0][4]);
Serial.print(rotary2Seq[1][0]);
Serial.print(rotary2Seq[1][1]);
Serial.print(rotary2Seq[1][2]);
Serial.print(rotary2Seq[1][3]);
Serial.println(rotary2Seq[1][4]);
Serial.print(rotary2Seq[2][0]);
Serial.print(rotary2Seq[2][1]);
Serial.print(rotary2Seq[2][2]);
Serial.print(rotary2Seq[2][3]);
Serial.println(rotary2Seq[2][4]);
Serial.println("solution list");
Serial.print(attempt[0]);
Serial.print(attempt[1]);
Serial.print(attempt[2]);
Serial.print(attempt[3]);
Serial.print(attempt[4]);
Serial.print(attempt[5]);
Serial.print(attempt[6]);
Serial.print(attempt[7]);
Serial.print(attempt[8]);
Serial.print(attempt[9]);
Serial.print(" ");
Serial.println(steps);


String command = start((rand() %30)+1);
Serial.println(buttonSeq[0][0]);
delay(500);
}
