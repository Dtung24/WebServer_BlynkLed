#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

String webPage =
{
  "<!DOCTYPE html>"
  "<html>"
  "<head>"
  "  <meta http-equiv='Content-Type' content='text/html; charset=utf-8'>"
  "  <title>ESP8266 Control</title>"
  "  <meta name='viewport' content='width=device-width, initial-scale=1'>"
  "  <style>"
  "    :root {"
  "      --color-on: #00e676; /* Green */"
  "      --color-off: #ff1744; /* Red */"
  "      --color-bg: #f4f7f6; /* Light Gray */"
  "      --color-card-bg: #ffffff;"
  "    }"
  "    body { font-family: sans-serif; background-color: var(--color-bg); margin: 0; }"
  "    .container { max-width: 400px; margin: 50px auto; padding: 20px; text-align: center; }"
  "    h1 { color: #333; margin-bottom: 30px; font-size: 1.5em; }"
  "    .device-grid { display: flex; flex-direction: column; gap: 15px; }"
  "    /* ------------------- Animation Keyframe ------------------- */"
  "    @keyframes fadeIn { from { opacity: 0; transform: translateY(-10px); } to { opacity: 1; transform: translateY(0); } }"
  "    /* ---------------------------------------------------------- */"
  "    .device-card {"
  "      display: flex;"
  "      justify-content: space-between;"
  "      align-items: center;"
  "      padding: 15px;"
  "      background-color: var(--color-card-bg);"
  "      border-radius: 12px;"
  "      box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);"
  "      animation: fadeIn 0.5s ease-out; /* Áp dụng animation */"
  "    }"
  "    .device-name { font-size: 1.1em; color: #555; font-weight: 600; }"
  "    .btn-group { display: flex; gap: 10px; }"
  "    .btn {"
  "      width: 85px; height: 38px; border: none; border-radius: 8px;"
  "      font-size: 16px; font-weight: 600; color: #fff; cursor: pointer;"
  "      text-decoration: none;"
  "      display: inline-flex; justify-content: center; align-items: center;"
  "      transition: all 0.2s ease-in-out; /* Transition cho hiệu ứng mượt mà */"
  "    }"
  "    .btn-on { background-color: var(--color-on); }"
  "    .btn-off { background-color: var(--color-off); }"
  "    .btn-on:hover { background-color: #00c853; }"
  "    .btn-off:hover { background-color: #d50000; }"
  "    .btn:active { transform: scale(0.95); box-shadow: 0 2px 4px rgba(0, 0, 0, 0.2); } /* Hiệu ứng nhấn */"
  "  </style>"
  "</head>"
  "<body>"
  "<div class='container'>"
  "  <h1>ĐIỀU KHIỂN THIẾT BỊ WIFI</h1>"
  "  <div class='device-grid'>"
  "    <div class='device-card'>"
  "      <span class='device-name'>Thiết bị 1 (D0)</span>"
  "      <div class='btn-group'>"
  "        <a href='/bat1' class='btn btn-on'>BẬT</a>"
  "        <a href='/tat1' class='btn btn-off'>TẮT</a>"
  "      </div>"
  "    </div>"
  "    <div class='device-card'>"
  "      <span class='device-name'>Thiết bị 2 (D1)</span>"
  "      <div class='btn-group'>"
  "        <a href='/bat2' class='btn btn-on'>BẬT</a>"
  "        <a href='/tat2' class='btn btn-off'>TẮT</a>"
  "      </div>"
  "    </div>"
  "    <div class='device-card'>"
  "      <span class='device-name'>Thiết bị 3 (D2)</span>"
  "      <div class='btn-group'>"
  "        <a href='/bat3' class='btn btn-on'>BẬT</a>"
  "        <a href='/tat3' class='btn btn-off'>TẮT</a>"
  "      </div>"
  "    </div>"
  "    <div class='device-card'>"
  "      <span class='device-name'>Thiết bị 4 (Chưa cấp Pin)</span>"
  "      <div class='btn-group'>"
  "        <a href='/bat4' class='btn btn-on'>BẬT</a>"
  "        <a href='/tat4' class='btn btn-off'>TẮT</a>"
  "      </div>"
  "    </div>"
  "  </div>"
  "</div>"
  "</body>"
  "</html>"
};

// --- GIỮ NGUYÊN PHẦN CÒN LẠI CỦA CODE C++ ---

MDNSResponder mdns;
ESP8266WebServer server(80);

// Hàm xử lý Web Server (Giữ nguyên)
void TrangChu()
{
  server.send(200, "text/html", webPage);
}

// Chức năng Bật/Tắt LED 1 (D0 - GPIO16)
void bat1()
{
  digitalWrite(16, HIGH); // D0 là GPIO16
  Serial.println("Bật LED 1 (D0)");
  server.send(200, "text/html", webPage);
}
void tat1()
{
  digitalWrite(16, LOW); // D0 là GPIO16
  Serial.println("Tắt LED 1 (D0)");
  server.send(200, "text/html", webPage);
}

// Chức năng Bật/Tắt LED 2 (D1 - GPIO5)
void bat2()
{
  digitalWrite(5, HIGH); // D1 là GPIO5
  Serial.println("Bật LED 2 (D1)");
  server.send(200, "text/html", webPage);
}
void tat2()
{
  digitalWrite(5, LOW); // D1 là GPIO5
  Serial.println("Tắt LED 2 (D1)");
  server.send(200, "text/html", webPage);
}

// Chức năng Bật/Tắt LED 3 (D2 - GPIO4) - Đã thêm vào setup
void bat3()
{
  digitalWrite(4, HIGH); // D2 là GPIO4
  Serial.println("Bat LED 3 (D2)");
  server.send(200, "text/html", webPage);
}
void tat3()
{
  digitalWrite(4, LOW); // D2 là GPIO4
  Serial.println("Tat LED 3 (D2)");
  server.send(200, "text/html", webPage);
}

// Chức năng Bật/Tắt LED 4 (Chưa cấu hình pin)
void bat4()
{
  // Pin cho Thiết bị 4 cần được khai báo và cấu hình trong setup
  Serial.println("Bat LED 4 (Chưa có Pin)");
  server.send(200, "text/html", webPage);
}
void tat4()
{
  Serial.println("Tat LED 4 (Chưa có Pin)");
  server.send(200, "text/html", webPage);
}


// --- Setup ---
void setup()
{
  // Cấu hình chân D0 (GPIO16), D1 (GPIO5), D2 (GPIO4) là OUTPUT
  pinMode(16, OUTPUT); // D0
  pinMode(5, OUTPUT);  // D1
  pinMode(4, OUTPUT);  // D2 (đã sửa từ 04 thành 4)
  
  // Set trạng thái ban đầu
  digitalWrite(16, LOW);
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
  
  Serial.begin(9600);
  Serial.println();
  Serial.print("Connecting to ");
  // Thay thế bằng SSID và Mật khẩu WiFi của bạn
  WiFi.begin("hang_phong", "16102012"); 
  
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected"); 
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
  // Khởi tạo mDNS
  if (mdns.begin("esp8266", WiFi.localIP()))
    Serial.println("MDNS responder started");
  
  // Cấu hình các đường dẫn (routes)
  server.on("/", TrangChu);
  server.on("/bat1", bat1); // D0
  server.on("/tat1", tat1); // D0
  server.on("/bat2", bat2); // D1
  server.on("/tat2", tat2); // D1
  server.on("/bat3", bat3); // D2
  server.on("/tat3", tat3); // D2
  server.on("/bat4", bat4); 
  server.on("/tat4", tat4);
  
  server.begin();
  Serial.println("HTTP server started");
}

// --- Loop ---
void loop()
{
  server.handleClient();
}
