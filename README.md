# FcMaker
Aquí voy a utilizar la libreria GTK+ para poder llevar a cabo la interfaz gráfica.

Para poder instalar la librería cross-platform se utiliza el comando :

sudo apt-get install libgtk-3-dev

-------------------------------------------------

Actualmente me encuentro en intento de entendimiento de la librería y sus distintas apis para poder generar el código. El archivo
Make aun no está corregido por lo tanto para poder compilar el ejecutable hace falta poner por terminal el siguiente comando:

gcc `pkg-config --cflags gtk+-3.0` -o main main.cpp `pkg-config --libs gtk+-3.0` -export-dynamic

Posteriormente su ejecución se logra mediante ./main
