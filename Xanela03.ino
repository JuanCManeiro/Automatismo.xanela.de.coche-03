# Automatismo.xanela.de.coche-03
Xanela con finais de curso

/*
Nesta practica o esencial e que o cambio pase por paro antes de comezar outro motor
o resto sera igual que na practica anterior, incluindo un inicio de traballo desde paro
Programa para simular a funcion dunha xanela de automovil 
de maneira simplificada. O motor acciona o motor se subida 
ao ser premido, Unha segunda pulsacion fai que se accione
o motor de baixada. o motor sube durante 7 sg despois pode baixar tamen 7sg 

Entrada: Pulsador (dixital)
Saídas:  Relé (2xdixital)

Autor:..... Comunidade
Data: Febreiro'23

Sempre despois de cada orde hay que poñer ; non telo da erro
*/

#define motorArriba 11 // no levan igual nin levan punto e coma
#define motorAbaixo 12
#define pulsador 7
#define fcArriba 8
#define fcAbaixo 9

//int motorArriba = 11; //quitamos esto con doble barra pero so queda inutilizado por se o necesitamos no futuro so temos que quitar as barras
//int motorAbaixo = 12;  

int estado = 1; //senón e bool pode tomar valores como 0, 1, 2, 3 // Con ESTADO 0 FALLABA PROBO CON 1
int contador = 0; // contador de sinais ao motor asi o motor empeza parado

/// adicion int pulsador = 0;

void setup() {
    pinMode(motorArriba, OUTPUT);// pinMode e digitalMode ven sendo o mesmo so diferentes modos de nomear "sinónimos"
    pinMode(motorAbaixo, OUTPUT);
    pinMode(pulsador, INPUT);
    pinMode(fcArriba, INPUT);
    pinMode(fcAbaixo, INPUT);

  Serial.begin(9600); //poñemos o monitor serie en funcionamento

  // int estado; //con "bool" no sitio de "int" funciona igual COMPROVAR MAIS ADIANTE
    
 // Serial.println(estado);  // si poñemos " o monitor di o que ten escrito se non ponnos o valor da variable dada
  
}

void loop() {
    // lectura do pulsador
  
  if(digitalRead(pulsador)) {
//      estado = !estado; // !significa o contrario da variable
    
      estado = (estado + 1) % 4 ; /***** Esto quere decir que se temos un 2 (2/4=0; R=2) 
          a nosa salida e un 2 (o resto) nunca podera ser >= que 4 , isto chamase modulo 4, o valor sempre sera entre 0 e 3 
            Estado = 0  motorArriba funcionando, 7sg?? ou ata accionar pulsador
             Estado = 1 motor parado, e como teño estado = 1 como definicion asi e como empeza cando encendo o coche, e supoñemos que esta a xanela levantada
              Estado = 2 motorAbaixo funcionando, 7sg ou ata accionar pulsador
               Estado = 3 motor parado ata que accione pulsador
          *****/

    contador = 100; //cada vez que pulse o contador resetea
   while(digitalRead(pulsador)) { //quitado momentaneamente
      delay(20);  //espera 20 ,milisegundos e comprova segue asi ata que solte o pulsador, no momento no que solte o pulsador cambia
   }
  }
  
  // poñemos os fc que veñen sendo 2 pulsadores 
  
  if(digitalRead(fcArriba)) { // fin de curso superior
    estado = 1; //Xanela parada arriba
    delay(20);
    
  }
  
  if(digitalRead(fcAbaixo)) { //fin de curso inferior
     estado = 3; // Xanela parada abaixo
    delay(20);
  }
  
  // fin da lectura do pulsador
 
    Serial.print("contador = ");// o estar entre " aparecera o escrito
    Serial.print(contador); // aqui poñera o dato
    Serial.print("   |   Estado = ");
    Serial.println(estado);  
    
  
  // Arrancamos motores
 /* if(contador == 0)  {
    
  }
  else {  //senon esta accionado lee 10 veces por sg
      digitalWrite(motorArriba, LOW); // aqui si introducindo aqui os dous motores en baixa o chegar o contador a 0 os motores deteñense,
      digitalWrite(motorAbaixo, LOW);
      Serial.print("  | xanela parada |  "); 
      delay(100);
      contador--; ESTA FORMULA NO ME VALEU para a parada de motores cando o "contador = 0"
      */
    
  if(contador > 0) { // aqui di que si cont>0 fai esta primeira parte sinon fai o que di o else, xq o motor non para o chegar a 0??
    if(estado == 0) {
      digitalWrite(motorArriba, HIGH);
      digitalWrite(motorAbaixo, LOW);
      delay(70); // usamos un numero pequeno para que de tempo a pulsacion asi lee cada 70 msg que por 100 impulsos seran os 7sg
      contador--;  //- 1; non me funcionou o -1 xq? XQ cando o contador chega a 0 non paran os motores?      
    }
    else if(estado == 2) {
      digitalWrite(motorArriba, LOW);
      digitalWrite(motorAbaixo, HIGH);
      delay(70); 
      contador--; //-- é igual a -1, SEGUNDO as miñas probas -1 != --
    
  }
  else  {      //senon esta accionado lee 10 veces por sg
      digitalWrite(motorArriba, LOW); // aqui si introducindo aqui os dous motores en baixa o chegar o contador a 0 os motores deteñense,
      digitalWrite(motorAbaixo, LOW);
      Serial.print("  | xanela parada |  "); 
      delay(100);
      contador--;
  }
  }
  }
//}

  //fin de accionamento de motores, por que?, cando pase o tempo non podemos volver a activar?

 // no es necesario delay(5); // con este delay final conseguimos que o contador vaia mais lento e asi danos tempo de ver o proceso e poder usar o pulsador



/* Agora o proceso esta rematado de aqui en diante son datos innecesarios para o programa da xanela
  so foron parte do traballo realizado e queda aqui para posibles consutas no futuro



/* quero que cando acabe o recorrido da xanela os motores permanezan parados a espera de pulso
  
  parece que con este sistema non sirve  
    if(contador == 0) {
      digitalWrite(motorArriba, LOW);
      digitalWrite(motorAbaixo, LOW);
}
    
// de momento continuame o problema de que o chegar a 0 non podo volver accionar     
     
/********     
     /* repetimos todo este proceso   
 /* Serial.println(estado);
  delay(20000); Borramos esto ( de momento)
  */
/*     
   }
  }
} // ESTA sobraba
/*
OLLO AQUI /*   if(estado == 0) {
  digitalWrite(motorArriba, HIGH);
  digitalWrite(motorAbaixo, LOW);
   while(digitalRead(pulsador)) { 
      delay(20); 
  }
}
}
  // ollo levar o control de parenteses e chaves abertas e cerralas todas
     
     
     
     
     
/*
 Estructura de funcións if, else
        if()

        {

        }

        else()

        {

        }
*/
