import serial
import time

port_led = "COM8"
port_photo = "COM9"

connection_led = serial.Serial(port_led, baudrate=9600, timeout=1)
connection_photo = serial.Serial(port_photo, baudrate=9600, timeout=1)

while True:
    connection_photo.write(b'p')
    photo_val = connection_photo.read(1)

    if photo_val:
        photo_val = int.from_bytes(photo_val, "big") * 4
        print(f"Освещенность: {photo_val}")
        if photo_val > 500:
            connection_led.write(b'u')
            print("Светодиод включен.")
        else:
            connection_led.write(b'd')
            print("Светодиод выключен.")

    time.sleep(0.5)
