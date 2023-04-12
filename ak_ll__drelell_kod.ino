/*   akıllı gravür
 *   
 *   25/03/2022
 *   
 *   Selim Burak KUL
 */
#include <MPU6050_tockn.h>   //MPU6050 kütüphane tanımlama
#include <Wire.h>
#define but 5      // artış butonun bağlanacağı pin
#define but_2 6    // azalış butonunun bağlanacağı pin
#define led 15     // deneme aşamaları için led tanımlama
#define motor 11    // motorun bağlanacağı pin
#define led_1 7    // gösterge ledelri 
#define led_2 8    // gösterge ledelri
#define led_3 9    // gösterge ledelri
MPU6050 mpu6050(Wire);

long timer = 0;
int devir ;       // motor devir değişkeni
int ledler ;
float aci_x;     // "x" ekseni açı değişkeni
float aci_y;     // "y" ekseni açı değişkeni
float ivme_x;    // "x" ekseni ivme değişkeni
float ivme_y;    // "y" ekseni ivme değişkeni
float ivme_z;    // "z" ekseni ivme değişkeni
boolean son;  
boolean dik;         //dik durma değişkeni
boolean but_durum;   //buton lojik değer
boolean but_durum_2; //buton 2 lojik değer
boolean guvenlik;

void setup() {
  
  digitalWrite(led_1 , HIGH);
  digitalWrite(led_2 , LOW);
  digitalWrite(led_3 , HIGH);
  delay(10);
  Serial.begin(9600);  //serihaberleşme başlatma
  Wire.begin();
  mpu6050.begin();     //MPU6050 başlatma
  mpu6050.calcGyroOffsets(true);
  pinMode(led , OUTPUT);
  pinMode(led_1 , OUTPUT);
  pinMode(led_2 , OUTPUT);
  pinMode(led_3 , OUTPUT); 
  pinMode(but , INPUT_PULLUP); 
  pinMode(but_2 , INPUT_PULLUP); 
  digitalWrite(led_1 , LOW);
  digitalWrite(led_2 , LOW);
  digitalWrite(led_3 , LOW);
}

void loop() {
  mpu6050.update();
  but_durum = digitalRead(but); 
  but_durum_2 = digitalRead(but_2); 

    
 // }
 aci_x = abs(mpu6050.getAngleX());  //  "x" ekseninden okunan açı değerinin mutlakdeğerini alma
 aci_y = abs(mpu6050.getAngleY());  //  "y" ekseninden okunan açı değerinin mutlakdeğerini alma

  ivme_x = abs(mpu6050.getGyroX());  //  "x" ekseninden okunan ivme değerinin mutlakdeğerini alma
  ivme_y = abs(mpu6050.getGyroY());  //  "y" ekseninden okunan ivme değerinin mutlakdeğerini alma
  ivme_z = abs(mpu6050.getGyroZ());  //  "z" ekseninden okunan ivme değerinin mutlakdeğerini alma

  
  if(aci_x < 10 and aci_y < 10  )   //  cihazın kaldırılmış olmasının algılanması
  {
    digitalWrite( led , HIGH);     
    dik = 1;
  }
  
 else                              //  cihazın düz zeminde olduğunun algılanması :)
 {
  digitalWrite( led , LOW);
  dik = 0;
 }
 
 if(ivme_x >500 or ivme_y >500 or ivme_z >500 )  // güvenlik modu savrulma algılama
 {
  guvenlik=1;       // güvenlik aktifetme
 }
 
 if(guvenlik==1 and but_durum==0 or but_durum_2==0)     // güvenlik moduna geçtiğinde butona basıp güvenlik modundan çıkma
 {
  guvenlik=0;      // güvenlik pasif
 }
 
  while(but_durum == 0  && devir < 255  )               // butona basılırsa devir sayısının artırılması
  {
    devir++ ;                 // devir sayısını bir-bir artırma
    delay(15);          
    Serial.println(devir);            // hata ayıklamak için
    break;
  }
  
  while(but_durum_2 == 0 && devir >0  )               // butona_2 ye basılırsa devir sayısının azaltılması
  {
    devir-- ;                 // devir sayısını bir-bir azaltma
    delay(15);          
    Serial.println(devir);            // hata ayıklamak için
    break;
  }
  
  while(dik == 0 and guvenlik==0 ){     //dik durma ve savrulmama şartı sağlanmazsa motora güç verme
    analogWrite(motor , devir);
   // Serial.println("çalışıyorum");    // hata ayıklamak için
    break;
  }
  
  while(dik == 1 or guvenlik==1)       //dik durma veya savrulma şartı sağlanırsa motorun gücünü kesme
  {   
    Serial.println("durdum");         // hata ayıklamak için
    analogWrite(motor , 0);
    break;
  }
  
  //Serial.println(guvenlik); 
  ledler = map(devir, 0 , 255 , 0 ,3);
  if(ledler==0)
  {
    digitalWrite(led_1 , LOW);
    digitalWrite(led_2 , LOW);
    digitalWrite(led_3 , LOW);
  }
  if(ledler==1)
  {
    digitalWrite(led_1 , HIGH);
    digitalWrite(led_2 , LOW);
    digitalWrite(led_3 , LOW);
  }
  if(ledler==2)
  {
    digitalWrite(led_1 , HIGH);
    digitalWrite(led_2 , HIGH);
    digitalWrite(led_3 , LOW);
  }
  if(ledler==3)
  {
    digitalWrite(led_1 , HIGH);
    digitalWrite(led_2 , HIGH);
    digitalWrite(led_3 , HIGH);
  }
}
