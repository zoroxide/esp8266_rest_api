# esp8266_rest_api
<h4>a simple DIY esp8266 REST_AP contains three sections:</h4>
<hr>

1. "poster.ino" is the NodeMCU(esp8266) using the Arduino IDE code, its main mission is to HTTP Post the data it has in the form of JSON to the Backend, in this project, the server is the "server.py"
2. "Server.py" is the Backend server powered by Python the the Flask framework, its mission is to receive the data from the NodeMCU and wait for the HTTP request that comes from the client, in this case, the client is "client.html"
3. "client.html" is our client, its main mission is to HTTP request the server to receive the NodeMCU data and stream it in an HTML user-based page

<br>

![image](https://github.com/zoroxide/esp8266_rest_api/assets/72279810/de07b2eb-2b27-4dc1-825d-94039c90620e)
