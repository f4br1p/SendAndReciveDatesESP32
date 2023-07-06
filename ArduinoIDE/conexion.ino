#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager
#include <WiFiClient.h>
#include <WebServer.h>
String url="http://192.168.11.88/pasantia/node.php";
const char separador=',';
const int dataLenght=4;
int data[dataLenght];
String str="";
/*int contconexion=0;
const char* ssid = "Maker Lab";
const char* password = "makerlab2022";*/
int Colectivo0=0;
int Colectivo1=0;
int Colectivo2=0;
int Colectivo3=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  IPAddress miIP = WiFi.localIP() ;   // Recopila la ip del esp
  Serial.print(miIP);                 // Imprime la ip del esp
  WiFi.mode(WIFI_STA); //modo establecido explícitamente, esp por defecto es STA + AP
  // ponga su código de configuración aquí, para que se ejecute una vez:
  // WiFi.mode(WiFi_STA); // Es una buena práctica asegurarse de que su código establezca el modo wifi como lo desea.

  //WiFiManager, Inicialización local. Una vez que compila no hay necesidad de modificarlo.
  WiFiManager wm;
  //restablecer la configuración: borra las credenciales para realizar pruebas
  //wm.resetSettings();
  // Se conecta automáticamente usando credenciales guardadas,
  // si falla la conexión, inicia un punto de acceso con el nombre especificado ("AutoConnectAP"),
  // si está vacío generará automáticamente SSID, si la contraseña está en blanco será AP anónimo (wm.autoConnect ())
  // luego entra en un bucle de bloqueo en espera de configuración y devolverá un resultado exitoso
    
   bool res;
   // res = wm.autoConnect(); // nombre de AP generado automáticamente a partir de chipid
   // res = wm.autoConnect("AutoConnectAP"); // anonymous ap
   res = wm.autoConnect("AutoConnectAP",""); // Contraseña protegida ap

   if(!res) {
        Serial.println("Failed to connect");
        // ESP.restart();
    } 
    else {
        //si llegas aquí te has conectado al wifi   
        Serial.println("Conectado...yeey :)");
    }
    ///////////////////////////////////////////////////////
   /* WiFi.begin(ssid, password);
  //Cuenta hasta 50 si no se puede conectar lo cancela
  while (WiFi.status() != WL_CONNECTED and contconexion <50) { 
    ++contconexion;
    delay(500);
    Serial.print(".");
  }
  if (contconexion <50) { 
      
      Serial.println("");
      Serial.println("WiFi conectado");
      Serial.println(WiFi.localIP());
      //server.begin(); // iniciamos el servidor
  }
  else { 
      Serial.println("");
      Serial.println("Error de conexion");
  }
    //........................................ 
  //---------------------------------------- 

  //---------------------------------------- If successfully connected to the wifi router, the IP Address that will be visited is displayed in the serial monitor
  Serial.println();
  Serial.print("Successfully connected to : ");
  Serial.println(ssid);
  Serial.println("-------------");
  //---------------------------------------- 
  delay(2000);*/
}

void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client;
    HTTPClient http; //Creamos el objeto del tipo HTTPClient
    http.begin(client, url); //Inicializamos el objeto con la URL+getData
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");//Cabecera del protocolo
       
    int httpCode=http.GET(); //Se envia por método GET y se guarda la respuesta 200=OK -1=ERROR
    String respuesta=http.getString();//Respuesta del Servidor

    Serial.println("RESPUESTA DEL SERVIDOR");
    Serial.println(httpCode);
    Serial.println(respuesta);
    Serial.println("--------------------------");
    if(respuesta.indexOf(',')){
      str = respuesta;
      Serial.println(str);
      const int dataLenght = 4;
      for(int i=0;i<dataLenght;i++){
        int index = str.indexOf(separador);//lee hasta el separador
        data[i]=str.substring(0,index).toInt();
        str = str.substring(index + 1);
      }
      Colectivo0=(data[0]);
      Colectivo1=(data[1]);
      Colectivo2=(data[2]);
      Colectivo3=(data[3]);
    }
      /*
    int ini=respuesta.indexOf(","); //busca la posicion del primer {
    int fin=respuesta.indexOf(",",ini);//busca la posicion de la coma, comenzando desde la posicion del ":"   //Se termina la comunicación
    Colectivo1=respuesta.substring(ini+1, fin).toInt();

    ini=respuesta.indexOf(",",fin); //busca la posicion del proximo ":" comenzando desde la coma
    fin=respuesta.indexOf(",",ini);//busca la posicion de la "}" comenzando desde el ":" del LED
    Colectivo2=respuesta.substring(ini+1, fin).toInt();

    ini=respuesta.indexOf(",",fin); //busca la posicion del proximo ":" comenzando desde la coma
    fin=respuesta.indexOf(",",ini);//busca la posicion de la "}" comenzando desde el ":" del LED
    Colectivo3=respuesta.substring(ini+1, fin).toInt();
    delay(500);*/
    //Se imprimen las respuesta
  
    Serial.println("VALORES GUARDADOS EN LAS VARIABLES");
    Serial.println(Colectivo1);
    Serial.println(Colectivo2);
    Serial.println(Colectivo3);
      http.end();
}
