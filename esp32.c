#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

// WiFi credentials
const char* ssid = "nome da rede wifi";
const char* password = "senha da rede wifi";

// Endereço da API - certifique-se de usar o IP do servidor
const char* apiUrl = "link do ngrok baseado na porta do servidor django/api/esp32/"; // Alterar para o IP correto do servidor

void setup() {
  // Inicializa a comunicação serial com taxa de 115200 bauds
  Serial.begin(9600);
  delay(1000);
  
  Serial.println("Iniciando a conexão ao WiFi...");
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("Conectado ao WiFi!");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Simula dados fictícios dos sensores
  int sensorEsquerdo = random(0, 2);  // Valor aleatório entre 0 e 1
  int sensorDireito = random(0, 2);   // Valor aleatório entre 0 e 1

  // Imprime os dados dos sensores no Serial Monitor
  Serial.print("Sensor Esquerdo: ");
  Serial.println(sensorEsquerdo);
  Serial.print("Sensor Direito: ");
  Serial.println(sensorDireito);

  // Envia os dados fictícios para a API
  enviarDadosAPI(sensorEsquerdo, sensorDireito);
  delay(10000); // Espera 10 segundos antes de enviar os dados novamente
}

// Função para enviar dados para a API
void enviarDadosAPI(int sensorEsquerdo, int sensorDireito) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    
    http.begin(apiUrl);
    http.addHeader("Content-Type", "application/json");
    
    // Ajuste os nomes dos campos conforme a API espera
    String jsonData = "{\"sensor_esquerdo\": " + String(sensorEsquerdo) + ", \"sensor_direito\": " + String(sensorDireito) + "}";
    Serial.print("Enviando dados JSON: ");
    Serial.println(jsonData);
    
    int httpResponseCode = http.POST(jsonData);
    
    if (httpResponseCode > 0) {
      Serial.print("Requisição POST bem-sucedida. Código de resposta: ");
      Serial.println(httpResponseCode);
      String payload = http.getString();
      Serial.println("Resposta do servidor: ");
      Serial.println(payload);
    } else {
      Serial.print("Erro na requisição POST. Código de resposta: ");
      Serial.println(httpResponseCode);
      Serial.print("Mensagem de erro: ");
      Serial.println(http.errorToString(httpResponseCode).c_str());
    }
    
    http.end();
  } else {
    Serial.println("Erro na conexão WiFi");
  }
}
