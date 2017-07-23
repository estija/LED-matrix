int st_clk[5]={10,8,6,4,2};
int sh_clk[5]={11,9,7,5,3};
int data_pin=12,k=0;

int data[6][8][5]={
    0,0,0,0,0,
    0,0,0,0,0,
    1,1,1,1,1,
    0,0,1,0,0,
    0,0,1,0,0,    //H
    0,0,1,0,0,
    1,1,1,1,1,
    0,0,0,0,0,

    0,0,0,0,0,  
    0,0,0,0,0,
    1,1,1,1,1,
    1,0,1,0,1,    //E
    1,0,1,0,1,
    1,0,1,0,1,
    1,0,0,0,1,
    0,0,0,0,0,

    0,0,0,0,0,
    0,0,0,0,0,
    1,1,1,1,1,
    1,0,0,0,0,
    1,0,0,0,0,    //L
    1,0,0,0,0,
    1,0,0,0,0,
    0,0,0,0,0,

    0,0,0,0,0,
    0,0,0,0,0,
    1,1,1,1,1,
    1,0,0,0,0,
    1,0,0,0,0,    //L
    1,0,0,0,0,
    1,0,0,0,0,
    0,0,0,0,0,

    0,0,0,0,0,
    0,0,0,0,0,
    0,1,1,1,0,
    1,0,0,0,1,
    1,0,0,0,1,    //O
    1,0,0,0,1,
    0,1,1,1,0,
    0,0,0,0,0,

    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,1,
    1,0,1,1,1,    //!
    0,0,0,0,1,
    0,0,0,0,0,
    0,0,0,0,0
    };

void setup(){
    for(int i=0;i<5;i++){
      pinMode(st_clk[i], OUTPUT);
      pinMode(sh_clk[i], OUTPUT);
  }
  pinMode(data_pin, OUTPUT);
}

void write_reg(int st_pin, int sh_pin, int dataPin, int j){
  digitalWrite(st_pin,LOW);
    for(int i=0;i<8;i++){
        digitalWrite(dataPin,data[k%6][7-i][j]);
      digitalWrite(sh_pin,LOW);
        digitalWrite(sh_pin,HIGH);
    }
    digitalWrite(st_pin,HIGH);
}

void loop(){
  for(int a=0;a<5;a++){
  write_reg(st_clk[a],sh_clk[a],data_pin,a);
    delay(10);
  }
  delay(2000);
  k++;
  }
