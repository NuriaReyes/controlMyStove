#include <SPI.h>       //Importamos la librería SPI
#include <Ethernet.h>  //Importamos la librería Ethernet

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };     //Ponemos una dirección MAC para la Ethernet Shield
IPAddress ip(192, 168, 1, 177);                             //Asingamos una IP a la Ethernet Shield
EthernetServer server(80);                               //Creamos un servidor web en el puerto 80 (puerto HTTP por defecto)

int led = 32;             //Definimos el pin que usaremos para encender el led
String estado = "OFF";   //Variable de tipo string que almacena el estado del Led (inicialmente "OFF")




void setup()
{
  Serial.begin(9600);       // Inicializamos la comunicación serie
  Ethernet.begin(mac, ip);  // Inicializamos la comunicación Ethernet y el servidor
  server.begin();           // Inicializamos el servidor web

  // Mostramos la direccion y el puerto donde esta funcionando el servidor web
  Serial.print("servidor iniciado: ");
  Serial.println(Ethernet.localIP());

  // Definimos el pin del led como salida y lo ponemos en LOW (apagado)
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
}


void loop()
{
  EthernetClient client = server.available();          //Creamos un cliente Web
    if (client) {                                      //Cuando detecte un cliente a través de una petición HTTP
    Serial.println("new client");                      //Avisamos por comunicacion serie
    boolean currentLineIsBlank = true;                 //Una petición HTTP acaba con una línea en blanco, ponemos la variable en TRUE
    String cadena="";                                  //Definimos una variable de tipo string vacía para almacenar el mensaje
    while (client.connected()) {                       //Si el cliente esta conectado...
      if (client.available()) {                        //Y hay datos para recibir...
        char c = client.read();                        //Leemos la petición HTTP carácter por carácter
        Serial.write(c);                               //Visualizamos la petición HTTP por el Monitor Serie
        cadena.concat(c);                              //Unimos todos los caracteres de la petición HTTP "c", en la variable de tipo String "Cadena"



         //Ya que hemos convertido la petición HTTP a una cadena de caracteres, ahora podremos buscar partes del texto.
         int posicion=cadena.indexOf("LED=");          //Nos fijamos en el texto "LED="
           if(cadena.substring(posicion)=="LED=ON")     //Si en esa posición tenemos "LED=ON"
          {
            digitalWrite(led,HIGH);                    //Encendemos el LED
            estado="ON";                               //Asignamos el valor "ON" a la variable "estado"
          }
          if(cadena.substring(posicion)=="LED=OFF")    //Si en esa posición tenemos "LED=OFF"
          {
            digitalWrite(led,LOW);                     //Apagamos el LED
            estado="OFF";                              //Asignamos el valor "OFF" a la variable "estado"
          }

        //Cuando reciba una línea en blanco, quiere decir que la petición HTTP ha acabado y el servidor Web está listo para enviar una respuesta
        if (c == '\n' && currentLineIsBlank) {

            // Enviamos al cliente una respuesta HTTP (cabecera)
            client.println("HTTP/1.1 200 OK");
            client.println("Content-Type: text/html");
            client.println("Connection: close");

            // Enviamos al cliente una respuesta en formato HTML
            client.println("<html>");
            client.println("");
            client.println("<head>");
            client.println("<meta charset='UTF-8'>");
            client.println("<meta name='viewport' content='width=device-width, initial-scale=1.0'>");
            client.println("<title>control-my-stove</title>");
            client.println("</head>");
            client.println("");
            client.println("<body>");

            client.println("<center><h1>Control remoto a estufa</h1></center>");
            client.println("<center><legend>Control de encendido</legend></center>");
            client.println("<center>");
            client.println("<input onClick=location.href='./?LED=ON' type='radio' name='on_off' id='on' value='on' checked=''>");
            client.println("Prender estufa");
            client.println("<input onClick=location.href='./?LED=OFF' type='radio' name='on_off' id='off' value='off' >");
            client.println("Apagar estufa");
            client.println("</center>");
            client.println("<br>");
            client.println("<center><legend>Timer de encendido</legend></center>");
            client.println("<center>");
            client.println("<input onClick=location.href='./?LED=ON' type='radio' name='timer' id='on' value='on' checked=''>");
            client.println("10 min");
            client.println("<input onClick=location.href='./?LED=OFF' type='radio' name='timer' id='off' value='off' >");
            client.println("15 min");
            client.println("</center>");
            client.println("<input onClick=location.href='./?LED=ON' type='radio' name='timer' id='on' value='on' checked=''>");
            client.println("20 min");
            client.println("<input onClick=location.href='./?LED=ON' type='radio' name='timer' id='off' value='off' >");
            client.println("25 min");
            client.println("</center>");
            client.println("<center><legend>Regular flama</legend></center>");
            client.println("<center>");
            client.println("<select>");
            client.println("  <option onClick=location.href='./?LED=ON' value='20'>20</option>");
            client.println("  <option onClick=location.href='./?LED=OFF' value='40'>40</option>");
            client.println("  <option onClick=location.href='./?LED=ON' value='40'>60</option>");
            client.println("  <option onClick=location.href='./?LED=OFF' value='40'>80</option>");
            client.println("  <option onClick=location.href='./?LED=ON' value='40'>100</option>");
            client.println("</select>");
            client.println("</center>");
            client.println("<h3>Detector de fugas de gas</h3>");
            client.println("");
            client.println("<h3>Detector de temperatura</h3>");
            client.println("");
            client.println("<button onClick=location.href='./?LED=OFF'>Reset</button>");
            client.println("<br>");

            client.println("<center><img src='C:/richa/downloads/logo.png'></center>");
            client.println("<br><br>");
            //Creamos los botones. Para enviar parametros a través de HTML se utilizara el metodo URL encode. Los parametros se envian a traves del simbolo '?'
            client.println("<div style='text-align:center;'>");
            client.println("<button onClick=location.href='./?LED=ON' style='width:200px; height:75px; background-color:#aaf442; color:snow; padding:10px; border:1px solid #3F7CFF;'>ON</button>");
            client.println("<button onClick=location.href='./?LED=OFF' style='width:200px; height:75px; background-color:#d82408; color:snow; padding:10px; border:1px solid #3F7CFF;'>OFF</button>");
            client.println("<br><br>");
            client.println("<b>Estado del LED = ");
            client.print(estado);
            client.println("</b><br />");
            client.println("</b></body>");
            client.println("</html>");
            break;
        }
        if (c == '\n') {
          currentLineIsBlank = true;
        }
        else if (c != '\r') {
          currentLineIsBlank = false;
        }
      }
    }
    //Damos tiempo al navegador para recibir los datos
    delay(1);
    client.stop();// Cierra la conexion
  }
}
