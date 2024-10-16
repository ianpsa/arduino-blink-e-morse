#define    LED  10
#define BUZZER  6

String codigo[] = {  ".-" , "-..." , "-.-." ,  "-.." ,    "." ,           //A,B,C,D,E
                   "..-." ,  "--." , "...." ,   ".." , ".---" ,           //F,G,H,I,J
                    "-.-" , ".-.." ,   "--" ,   ".-" ,  "---" ,           //K,L,M,N,O
                   ".--." , "--.-" ,  ".-." ,  "..." ,    "-" ,           //P,Q,R,S,T
                    "..-" , "...-" ,  ".--" , "-..-" , "-.--" , "--.."    //U,V,W,X,Y,Z                                                                   
                  };

String mensagem = "KIZZY";

void on_output(String pos);
void output_ponto();
void output_traco();
void codifica_string(String mens);

void setup() {
  pinMode(LED,OUTPUT);
  pinMode(BUZZER,OUTPUT);
  digitalWrite(LED,LOW);
  digitalWrite(BUZZER,LOW);

  codifica_string(mensagem);
}

void loop(){}

void on_output(String caractere){
  for(int i=0; i<caractere.length(); i++){
    if(caractere[i] == '.'){
      output_ponto();
    }
    else if(caractere[i] == '-'){
      output_traco();
    }   
  }
}

void output_ponto(){
  digitalWrite(LED,HIGH);
  digitalWrite(BUZZER,HIGH);
  delay(75);
  digitalWrite(LED,LOW);
  digitalWrite(BUZZER,LOW);
  delay(75);
}

void output_traco(){
  digitalWrite(LED,HIGH);
  digitalWrite(BUZZER,HIGH);
  delay(200);
  digitalWrite(LED,LOW);
  digitalWrite(BUZZER,LOW);
  delay(200);
}

void codifica_string(String mens){
  int posicao_codigo;
  for(int i=0; i<mens.length(); i++){
    posicao_codigo = ((int)mens[i])-65;
    on_output(codigo[posicao_codigo]);
    delay(500);
  }
}