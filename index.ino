const int fourche_optique = 11; // déclaration de la fourche_optique // mettre en majuscule les const !!!
const int led = 4;// ajout d'une led en PIN 3
const int buzzer = 7;
const int bouton = 6;
int count = 0;
const int photo_resistence;

int fourche_optique_state = 0; // etat dans lequel se trouve la fourche_optique

int frequences[7]={262, 294, 330, 349, 392, 440, 494};
int i = 0; // index dans le tableau des fréquences

bool jour = true;
int seuil = 200;
int t=200;

void setup() {

// pinMode(bouton, INPUT_PULLUP);// déclaration du bouton en entrée avec la résistance pullup
pinMode(fourche_optique, INPUT_PULLUP);
pinMode (led, OUTPUT);// déclaration de la la LED en sortie
pinMode (buzzer, OUTPUT);// déclaration du buzzer en sortie


Serial.begin(9600);// ouverture port de communication
}

void loop() {

  if(digitalRead(fourche_optique_state) == LOW && jour)
  {
    digitalWrite(led, HIGH);
    delay(t);
    digitalWrite(led, LOW);
    delay(t);
    tone(buzzer, frequences[i], t);
    count ++;
    Serial.print("\nAbeilles : ");
    Serial.print(count); // ou directement mettre count ++ ici
    while(digitalRead(fourche_optique_state)==LOW);
  }

  if(digitalRead(bouton) == LOW)
  {
    while(digitalRead(bouton) == LOW);// https://create.arduino.cc/projecthub/reverendfuzzy/simple-on-off-pushbutton-f637a7
// https://forum.arduino.cc/t/compteur-de-vitesse-avec-fourche-optique/476240

// .ino 
const int fourche = 11;
const int bouton = 6;
const int led =4;
const int buzzer = 2;
// PR photoresistance
const int PR = A0;
// https://www.programmingelectronics.com/an-easy-way-to-make-noise-with-arduino-using-tone/

int frequence[7] = {261, 293, 329, 349, 391, 440, 493};
int indexNote = 0;

int nbreI0 = 0;
int t = 200;
int seuil = 20;
bool jour = true;
int photoValue;

void setup() {
  pinMode(fourche, INPUT);
  pinMode(led,OUTPUT);           // define LED as an output
  pinMode (buzzer, OUTPUT);// déclaration de la la buzzer en sortie
  pinMode(PR, INPUT);
  pinMode(bouton, INPUT_PULLUP);         // define button as an input 
  // digitalWrite(led,LOW);         // turn output off just in case
  Serial.begin(9600);
}

void loop() {

  photoValue = analogRead(PR);
  Serial.println(photoValue);
  delay(t);

  if (digitalRead(fourche) == LOW && jour) {
  //if (digitalRead(fourche) == LOW) {
      while(digitalRead(fourche)== LOW); 
      digitalWrite(led, HIGH);     // and turn on the LED
      delay(t);
      digitalWrite(led, LOW);
      tone(buzzer, frequence[indexNote], t);
      Serial.print("\nAbeilles : ");
      nbreI0=nbreI0 + 1;
      //nbreI0=0;
      
      Serial.println(nbreI0);

  }
// on est en pull-up, donc on est directement sur du 5 V (lu 1), quand on appuie, on est au ground (lu 0)
  // on cherche est lire quand il passe au ground, quand il est LOW
  // PULLDOWN pas native au arduino, à tester et à faire à la main
   if (digitalRead(bouton) == LOW) {// et que la position du bouton est à LOW (inversé avec la résistance de PULLUP)
      while(digitalRead(bouton) == LOW); 
      delay(200);
      indexNote = (indexNote+1)%7;
      //Serial.print("\nFrequence : ");
      //Serial.print(indexNote);
    } 
    if (analogRead(PR)<seuil){
      jour = false;
      // Serial.print("nuit ");
      // Serial.println(jour);
      // delay(t);

    } else {
      jour = true;
      // Serial.print("jour ");
      // Serial.println(jour);
      // delay(t);
    }

}
    delay(200);
    i = (i + 1) % 7;
    Serial.print("\n fréquence : ");
    Serial.print(i); 
  }

  if(analogRead(photo_resistence) < seuil)
  {
    jour = false;
  }
  else
  {
    jour = true;
  }
}

