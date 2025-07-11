# Управляемая машинка с esp32

## Цель проекта
Создать Wi-Fi-управляемую машинку с камерой на базе микроконтроллера ESP32-CAM, способную:
- передавать видео в реальном времени через веб-интерфейс
- управляться удалённо с помощью кнопок (вперёд/назад/влево/вправо)

### Детали для 3D-печати
Готовые детали машины для 3D-печати [3D printer machine details](https://github.com/Kirilligu/Internet-of-Things/tree/main/PROJECT/3D%20printer%20machine%20details).
### Комплектующие
- Arduino Uno — https://clck.ru/3MMuch
- Драйвер моторов L298N — https://clck.ru/3MMufo
- ESP32 CAM — https://clck.ru/3MMuhq
- Моторы постоянного тока с редуктором и колёсам (2 шт) — https://clck.ru/3MMujJ
- Сервомотор SG90 — https://clck.ru/3MMuqN
- Соеденительные провода папа-папа, мама-мама, папа-мама 10-30 см — https://clck.ru/3MMutK
- Аккумулятор 18650 — https://clck.ru/3MMuvA
- Переключатель — https://clck.ru/3MMuxE

### Крепежные материалы 
- Болты 3 х 30 мм — 4 шт;
- Гайки 3 мм — 4 шт;
- Болты 4 х 6 мм — 10 шт;
- Болты 4 х 10 мм — 2 шт;
- Гайки 4 мм — 10 шт;
- Болты 5 х 25 мм — 4 шт;
- Гайки 5 мм — 6 шт;
- Саморезы — 2 х 7 мм — 8 шт;
- Подшипники — 5 х 16 х 5 мм — 4 шт.

### Схема подключения 
![circuit_image](https://github.com/user-attachments/assets/9762e217-04d1-4e3b-a1ae-de5b6fcbc37e)
<div align="center">
  <img src="https://github.com/user-attachments/assets/b89510ce-1c5d-42d8-baca-873d24c12bb7" width="300" style="display: inline-block; margin: 10px;">
  <img src="https://github.com/user-attachments/assets/61e9d958-426e-4d18-b36b-81e035d61759" width="300" style="display: inline-block; margin: 10px;">
  <img src="https://github.com/user-attachments/assets/9da33ab6-9e39-47ad-8a04-3204cf79c0df" width="300" style="display: inline-block; margin: 10px;">
</div>

### Схема подключения с фарами и задними стоп сигналами (+ Arduino UNO)
![circuit_image (1)](https://github.com/user-attachments/assets/9495fef7-f646-4586-aa94-9977dd09a772)
<img src="https://github.com/user-attachments/assets/a05c4e09-df53-4951-871b-30dd9479ca83" width="300">
<img src="https://github.com/user-attachments/assets/51f3840b-4a47-49f9-ba17-175c9df41d46" width="300">

## Сборка
<div style="text-align:center; white-space:nowrap; overflow-x:auto;">
  <img src="https://github.com/user-attachments/assets/ef786e53-52a5-4dc4-839c-20efae7600ea" width="300" style="display:inline-block; margin:5px;">
  <img src="https://github.com/user-attachments/assets/c677534f-5a10-450c-a064-2068cc90e920" width="300" style="display:inline-block; margin:5px;">
  <img src="https://github.com/user-attachments/assets/252a005d-cf1b-4da2-9adb-f30bec0504b3" width="300" style="display:inline-block; margin:5px;">
  <img src="https://github.com/user-attachments/assets/0ce170c0-7a1c-4320-a405-ff12504381af" width="300" style="display:inline-block; margin:5px;">
  <img src="https://github.com/user-attachments/assets/7c9e0ed1-6d75-4dde-86a0-88c335f7f4ea" width="300" style="display:inline-block; margin:5px;">
  <img src="https://github.com/user-attachments/assets/54334318-78cb-469f-becd-4d58a9d72802" width="300" style="display:inline-block; margin:5px;">
  <img src="https://github.com/user-attachments/assets/d78b9f1b-a8c6-4ebf-ae74-bd6212327387" width="300" style="display:inline-block; margin:5px;">
  <img src="https://github.com/user-attachments/assets/29d420fc-99d8-483e-af6d-cc5282f626cd" width="300" style="display:inline-block; margin:5px;">
  <img src="https://github.com/user-attachments/assets/ca8eb34c-cb15-4767-9bfd-d3552be64aec" width="300" style="display:inline-block; margin:5px;">
</div>

## Прошивка плат
Если вы сделали передние и задние фары, то код для Arduino UNO находится в папке [codes for the firmware](https://github.com/Kirilligu/Internet-of-Things/blob/main/PROJECT/codes%20for%20the%20firmware/headlights.ino).

Прошивка для ESP32 CAM находится в папке [ESP32 CAM](https://github.com/Kirilligu/Internet-of-Things/tree/main/PROJECT/codes%20for%20the%20firmware/ESP32%20CAM).

## Демонстрация работы
https://cloud.mail.ru/public/GWPq/hxhJLXFgj
