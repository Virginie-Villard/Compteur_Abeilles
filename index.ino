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
    while(digitalRead(bouton) == LOW);
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

