#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>


void httpPost(String bodyJson, String url){
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Wifi is unavailable");
    return;
  }
  // Make request each 5 seconds

  HTTPClient http;
  WiFiClient client;

  http.begin(client, url);
  Serial.println("Making POST request to " + url);

  /*
  {"value":"some_value","another_value":"another_value"}
  */
  http.addHeader("Content-Type", "application/json");
  
  int httpCode = http.POST(bodyJson);
  if (httpCode > 0)
  {
    if (httpCode == HTTP_CODE_OK)
    {
      Serial.println("Request is OK!");
    }
    else
    {
      Serial.println("Error: httpCode was " + httpCode);
    }
  }
  else
  {
    Serial.println("Request failed: " + httpCode);
  }

  http.end(); //Close connection
}

void httpGet(String url){
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Wifi is unavailable");
    return;
  }
  // Make request each 5 seconds

  HTTPClient  http;
  WiFiClient wifiClient;

  http.begin(wifiClient, url);

  // Make request
  Serial.println("Making GET request to " + url);
  int httpCode = http.GET();
  if (httpCode > 0)
  {
    if (httpCode == HTTP_CODE_OK)
    {

      String payload = http.getString(); //Get the request response payload
      Serial.println("Request is OK!");
      Serial.println(payload);
    }
    else
    {
      Serial.println("Error: httpCode was " + httpCode);
    }
  }
  else
  {
    Serial.println("Request failed: " + httpCode);
  }

  http.end(); //Close connection


}
