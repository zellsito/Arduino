#include "http.h"
#include <ArduinoJson.h>

String number = "1169940853";
String url = "http://wp-api-rest.herokuapp.com";

void enviarMensaje(String text){
  String bodyJson;
  DynamicJsonDocument data(1024);

  data["password"] = 123456;
  data["number"] = "549"+number;
  data["text"] = text;

  serializeJson(data, bodyJson);
  
  //String bodyJson = "{\"password\":\"123456\",\"number\":\"549"+number+"\",\"text\":\""+text+"\"}";
  httpPost(bodyJson, url);
}
